//  File Name        : swthread.cpp
//  Description      : Smith-Waterman aligner thread
//                     Full description in swthread.h
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision
//      Albert Ng   Oct 04 2013     Completed initial implementation
//      Albert Ng   Oct 07 2013     Added SWThread::Join()
//      Albert Ng   Oct 09 2013     Added query seq manager
//      Albert Ng   Oct 10 2013     Removed END_OF_ALIGNMENT token check
//      Albert Ng   Oct 15 2013     Ignore alignments starting in overlap region
//      Albert Ng   Oct 18 2013     Removed duplicate alignments
//      Albert Ng   Oct 22 2013     Changed SwAffineGapParams to a class
//                                  Removed params and params_mutex member variables
//      Albert Ng   Oct 28 2013     Changed AlignmentResult to store Alignment, not Alignment*

#include "swthread.h"
#include "def.h"
#include "threadqueue.h"
#include "refseqmanager.h"
#include "queryseqmanager.h"
#include "utils.h"
#include "scoring.h"
#include <list>

SWThread::SWThread() {
}

SWThread::SWThread(ThreadQueue<HighScoreRegion>* hsr_queue,
                   ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
                   QuerySeqManager* query_seq_manager) {
  Init(hsr_queue, result_queue, ref_seq_manager, query_seq_manager);
}

void SWThread::Init(ThreadQueue<HighScoreRegion>* hsr_queue,
          ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
          QuerySeqManager* query_seq_manager) {
  args_.hsr_queue = hsr_queue;
  args_.result_queue = result_queue;
  args_.ref_seq_manager = ref_seq_manager;
  args_.query_seq_manager = query_seq_manager;
}

void SWThread::Run() {
  pthread_create(&thread_, NULL, &SWThread::Align, (void*) (&args_));
}

void SWThread::Join() {
  pthread_join(thread_, NULL);
}

// Checks for terminating packets, indicated by ref_len = 0 for the high
//   scoring location, which signal the completion of an alignment
//   by an FPGA engine. In the case of a terminating packet, decrement
//   the high score region count for that query, which was initialize
//   at the number of FPGA engine alignments allocated to the query.
// Grabs the mutex for the params before proceeding with each
//   alignment to make sure the params are coherent for the
//   entire alignment.
void* SWThread::Align(void* args) {
  int** v_matrix;   // Score matrix
  int** e_matrix;   // Insertion score matrix
  int** f_matrix;   // Deletion score matrix
  AlnOp** dir_matrix; // Alignment ops for score matrix
  char* ref_seq;
  char* query_seq;
  int ref_len, query_len;
  HighScoreRegion hsr;
  NtInt ref_nt, query_nt;
  int ins_open, ins_extend, del_open, del_extend, match;
  int max_score, query_index, ref_index;
  std::list<int> max_query_index, max_ref_index;
  std::list<int>::iterator it_query_index, it_ref_index;
  Alignment* aln;
  int max1, max2;
  AlnOp dir1, dir2;
  std::list<AlignmentResult> hsr_alignments;
  int** sub_mat;
  int gap_open;
  int gap_extend;

  // Get alignment arguments 
  ThreadQueue<HighScoreRegion>* hsr_queue = ((SWThreadArgs*)args)->hsr_queue;
  ThreadQueue<AlignmentResult>* result_queue = ((SWThreadArgs*)args)->result_queue;
  RefSeqManager* ref_seq_manager = ((SWThreadArgs*)args)->ref_seq_manager;
  QuerySeqManager* query_seq_manager = ((SWThreadArgs*)args)->query_seq_manager;

  sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }

  while(true) {
    // Grab available high scoring region
    hsr = hsr_queue->Pop();
    //std::cout<<"HSR Popped:\tQuery ID: "<<hsr.query_id<<" Ref ID: "<<hsr.ref_id<<" Offset: "<<hsr.offset<<" Length: "<<hsr.len<<" Overlap Offset: "<<hsr.overlap_offset<<" Threshold: "<<hsr.threshold<<" Params: "<<hsr.params.ToString()<<std::endl;
    ref_len = hsr.len;
    //std::cout<<"Getting RefSeq "<<hsr.ref_id<<" " <<hsr.offset<<" " <<ref_len<<std::endl;
    ref_seq = ref_seq_manager->GetRefSeq(hsr.ref_id, hsr.offset, ref_len);
    query_seq = query_seq_manager->GetQuerySeq(hsr.query_id, &query_len);
    
    /*std::cout<<"Ref len: "<<ref_len<<" Ref seq: ";
    for (int i = 0; i < ref_len; i++) {
      std::cout<<ref_seq[i];
    }
    
    std::cout<<"\nQuery len: "<<query_len<<" Query seq: ";
    for (int i = 0; i < query_len; i++) {
      std::cout<<query_seq[i];
    }
    std::cout<<std::endl;*/
    
    // Get the scoring parameters
    hsr.params.GetSubMat(sub_mat);
    gap_open = hsr.params.GetGapOpen();
    gap_extend = hsr.params.GetGapExtend();
    
    /*std::cout<<"Sub mat: ";
    for (int i =0 ; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        std::cout<<sub_mat[i][j]<<" ";
      }
    }
    std::cout<<std::endl;*/
    
    // Initialize new score matrices
    v_matrix = new int*[ref_len + 1];
    e_matrix = new int*[ref_len + 1];
    f_matrix = new int*[ref_len + 1];
    dir_matrix = new AlnOp*[ref_len + 1];
    for (int i = 0; i < ref_len + 1; i++) {
      v_matrix[i] = new int[query_len + 1];
      e_matrix[i] = new int[query_len + 1];
      f_matrix[i] = new int[query_len + 1];
      dir_matrix[i] = new AlnOp[query_len + 1];
      for (int j = 0; j < query_len + 1; j++) {
        v_matrix[i][j] = 0;
        e_matrix[i][j] = 0;
        f_matrix[i][j] = 0;
        dir_matrix[i][j] = ZERO_OP;
      }
    }
    max_score = 0;
    max_query_index.clear();
    max_ref_index.clear();

    // Compute dynamic programming matrices
    for (int i = 1; i < ref_len + 1; i++) {
      for (int j = 1; j < query_len + 1; j++) {
        ref_nt = NtChar2Int(ref_seq[i-1]);
        query_nt = NtChar2Int(query_seq[j-1]);
      
        // Compute possible choices
        if (ref_nt == N_NT || query_nt == N_NT) {
          match = -2147483648; // Force N's to align with gaps
        } else {
          match = v_matrix[i-1][j-1] + sub_mat[query_nt][ref_nt];
        }
        ins_open   = v_matrix[i-1][j] + gap_open;
        ins_extend = e_matrix[i-1][j] + gap_extend;
        del_open   = v_matrix[i][j-1] + gap_open;
        del_extend = f_matrix[i][j-1] + gap_extend;

        // Pick choice with highest score
        // Record decision in dir_matrix
        e_matrix[i][j] = (ins_open > ins_extend) ? ins_open : ins_extend;
        f_matrix[i][j] = (del_open > del_extend) ? del_open : del_extend;
        if (match > e_matrix[i][j]) {
          max1 = match;
          dir1 = MATCH_OP;
        } else {
          max1 = e_matrix[i][j];
          dir1 = INSERT_OP;
        }
        if (f_matrix[i][j] > 0) {
          max2 = f_matrix[i][j];
          dir2 = DELETE_OP;
        } else {
          max2 = 0;
          dir2 = ZERO_OP;
        }
        if (max1 > max2) {
          v_matrix[i][j] = max1;
          dir_matrix[i][j] = dir1;
        } else {
          v_matrix[i][j] = max2;
          dir_matrix[i][j] = dir2;
        }
        
        // Record max score
        if (v_matrix[i][j] > max_score) {
          max_score = v_matrix[i][j];
          max_query_index.clear();
          max_query_index.push_back(j);
          max_ref_index.clear();
          max_ref_index.push_back(i);
        } else if (v_matrix[i][j] == max_score) {
          max_query_index.push_back(j);
          max_ref_index.push_back(i);
        }
        
      }
    }

    // Backtrace to obtain alignments
    hsr_alignments.clear();
    //std::cout<<"Max score: "<<max_score<<std::endl;
    if (max_score > hsr.threshold) {
      for (it_query_index = max_query_index.begin(), it_ref_index = max_ref_index.begin(); 
           it_query_index != max_query_index.end() && it_ref_index != max_ref_index.end(); 
           ++it_query_index, ++it_ref_index) {
        query_index = *it_query_index;
        ref_index = *it_ref_index;
        Alignment aln(hsr.offset + ref_index, query_index);
        while (dir_matrix[ref_index][query_index] != ZERO_OP) {
          switch(dir_matrix[ref_index][query_index]) {
            case MATCH_OP:  aln.Prepend(ref_seq[ref_index-1], query_seq[query_index-1]);
                            query_index--;
                            ref_index--;
                            break;
            case INSERT_OP: aln.Prepend(ref_seq[ref_index-1], GAP);
                            ref_index--;
                           break;
            case DELETE_OP: aln.Prepend(GAP, query_seq[query_index-1]);
                            query_index--;
                            break;
           default:         aln.Prepend('X', 'X');   // Shouldn't get here
                            query_index--;
                            ref_index--;
                            break;
          }
        }
        
        AlignmentResult aln_res;
        aln_res.hsr = hsr;
        aln_res.alignment = aln;
        aln_res.score = max_score;
        
        // Filter out duplicate alignments, pick the longest duplicated alignment
        bool duplicate = false;
        for (std::list<AlignmentResult>::iterator it = hsr_alignments.begin(); it != hsr_alignments.end(); ++it) {
          if ((*it).alignment.get_ref_offset() == aln_res.alignment.get_ref_offset()) {
            duplicate = true;
            if ((*it).alignment.GetLength() < aln_res.alignment.GetLength()) {
              hsr_alignments.insert(it, aln_res);
              it = hsr_alignments.erase(it);
              --it;
            }
          }
        }
        
        // Ignore alignments starting in the overlap region to prevent reporting duplicated
        //   alignments across job borders
        if (aln_res.alignment.get_ref_offset() < hsr.overlap_offset && duplicate == false) {
          hsr_alignments.push_back(aln_res);
        }
      }
      
      // Store alignment results list onto results queue
      for (std::list<AlignmentResult>::iterator it = hsr_alignments.begin(); it != hsr_alignments.end(); ++it) {
        //std::cout<<"Storing alignment result "<<std::endl;
        result_queue->Push(*it);
      }
    }
    //std::cout<<"Aligned HSR:\tQuery ID: "<<hsr.query_id<<" Ref ID: "<<hsr.ref_id<<" Offset: "<<hsr.offset<<" Length: "<<hsr.len<<" Overlap Offset: "<<hsr.overlap_offset<<" Threshold: "<<hsr.threshold<<std::endl;

    // Memory cleanup
    for (int i = 0; i < ref_len + 1; i++) {
      delete[] v_matrix[i];
      delete[] e_matrix[i];
      delete[] f_matrix[i];
      delete[] dir_matrix[i];
    }
    delete[] v_matrix;
    delete[] e_matrix;
    delete[] f_matrix;
    delete[] dir_matrix;
 
    // Decrement outstanding high scoring region count 
    query_seq_manager->DecHighScoreRegionCount(hsr.query_id);
    //std::cout<<"Query "<<hsr.query_id<<" Decrement HSR Count after done with HSR"<<std::endl;
  } 
}

