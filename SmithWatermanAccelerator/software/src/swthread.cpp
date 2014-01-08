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
//      Albert Ng   Oct 31 2013     Now reports all alignments above threshold
//      Albert Ng   Nov 19 2013     Added chromosomes

#include <list>
#include <set>
#include <assert.h>
#include "swthread.h"
#include "def.h"
#include "threadqueue.h"
#include "refseqmanager.h"
#include "queryseqmanager.h"
#include "utils.h"
#include "scoring.h"


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
void* SWThread::Align(void* args) {
  // Get alignment arguments 
  ThreadQueue<HighScoreRegion>* hsr_queue = ((SWThreadArgs*)args)->hsr_queue;
  ThreadQueue<AlignmentResult>* result_queue = ((SWThreadArgs*)args)->result_queue;
  RefSeqManager* ref_seq_manager = ((SWThreadArgs*)args)->ref_seq_manager;
  QuerySeqManager* query_seq_manager = ((SWThreadArgs*)args)->query_seq_manager;

  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  int gap_open;
  int gap_extend;

  while(true) {
    // Grab available high scoring region
    HighScoreRegion hsr = hsr_queue->Pop();
    //std::cout<<"HSR Popped:\tQuery ID: "<<hsr.query_id<<" Ref ID: "<<hsr.ref_id<<" Offset: "<<hsr.offset<<" Length: "<<hsr.len<<" Overlap Offset: "<<hsr.overlap_offset<<" Threshold: "<<hsr.threshold<<" Params: "<<hsr.params.ToString()<<std::endl;
    int ref_len = hsr.len;
    int query_len;
    //std::cout<<"Getting RefSeq "<<hsr.ref_id<<" " <<hsr.offset<<" " <<ref_len<<std::endl;
    char* ref_seq = ref_seq_manager->GetRefSeq(hsr.ref_id, hsr.chr_id, hsr.offset, ref_len);
    char* query_seq = query_seq_manager->GetQuerySeq(hsr.query_id, &query_len);
    
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
    int** v_matrix = new int*[ref_len + 1];       // Score matrix
    int** e_matrix = new int*[ref_len + 1];       // Insertion score matrix
    int** f_matrix = new int*[ref_len + 1];       // Deletion score matrix
    AlnOp** dir_matrix = new AlnOp*[ref_len + 1]; // Alignment ops for score matrix
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

    // Compute dynamic programming matrices
    std::set<Cell, CellComp> highscore_cells;
    for (int i = 1; i < ref_len + 1; i++) {
      for (int j = 1; j < query_len + 1; j++) {
        NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
        NtInt query_nt = NtChar2Int(query_seq[j-1]);
      
        // Compute possible choices
        int match;
        if (ref_nt == N_NT || query_nt == N_NT) {
          match = -2147483648; // Force N's to align with gaps
        } else {
          match = v_matrix[i-1][j-1] + sub_mat[query_nt][ref_nt];
        }
        int ins_open   = v_matrix[i-1][j] + gap_open;
        int ins_extend = e_matrix[i-1][j] + gap_extend;
        int del_open   = v_matrix[i][j-1] + gap_open;
        int del_extend = f_matrix[i][j-1] + gap_extend;

        // Pick choice with highest score
        // Record decision in dir_matrix
        e_matrix[i][j] = (ins_open > ins_extend) ? ins_open : ins_extend;
        f_matrix[i][j] = (del_open > del_extend) ? del_open : del_extend;
        
        int max1 = e_matrix[i][j];
        AlnOp dir1 = INSERT_OP;
        if (match > max1) {
          max1 = match;
          dir1 = MATCH_OP;
        }
        int max2 = 0;
        AlnOp dir2 = ZERO_OP;
        if (f_matrix[i][j] > 0) {
          max2 = f_matrix[i][j];
          dir2 = DELETE_OP;
        }
        if (max1 > max2) {
          v_matrix[i][j] = max1;
          dir_matrix[i][j] = dir1;
        } else {
          v_matrix[i][j] = max2;
          dir_matrix[i][j] = dir2;
        }
        
        // Record high-scoring cells
        if (v_matrix[i][j] >= hsr.threshold) {
          Cell hsc;
          hsc.ref_index = i;
          hsc.query_index = j;
          hsc.score = v_matrix[i][j];
          highscore_cells.insert(hsc);
        }
        
      }
    }

    // Backtrace to obtain alignments
    std::set<AlignmentResult, AlignmentResultComp> hsr_alignments;
    for (std::set<Cell, CellComp>::iterator it = highscore_cells.begin(); it != highscore_cells.end(); ++it) {
      int query_index = (*it).query_index;
      int ref_index = (*it).ref_index;
      int score = (*it).score;
      
      // Build the alignment
      Alignment aln(hsr.offset + ref_index, query_index);
      while (dir_matrix[ref_index][query_index] != ZERO_OP) {
        // Keep alignments ending with the right-most max score cell
        if (v_matrix[ref_index][query_index] > score) {
          score = v_matrix[ref_index][query_index];
          aln.TrimEnd(0);
        }
    
        // Remove visited cells from the high score cell list
        if (!(query_index == (*it).query_index && ref_index == (*it).ref_index)) {
          Cell hsc;
          hsc.query_index = query_index;
          hsc.ref_index = ref_index;
          hsc.score = score;
          highscore_cells.erase(hsc);
        }

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
         default:         assert(false);
        }
      }
      AlignmentResult aln_res;
      aln_res.hsr = hsr;
      aln_res.alignment = aln;
      aln_res.score = score;

      std::set<AlignmentResult, AlignmentResultComp>::iterator aln_it = hsr_alignments.find(aln_res);
      if (aln_it != hsr_alignments.end()) {
        // Filter out duplicate alignments, pick the highest scoring, longest duplicated alignment
        if (((*aln_it).score < aln_res.score) || 
            ((*aln_it).score == aln_res.score && (*aln_it).alignment.GetLength() < aln_res.alignment.GetLength())) {
          hsr_alignments.erase(aln_it);
          hsr_alignments.insert(aln_res);
        }
      } else if (aln_res.alignment.get_ref_offset() < hsr.overlap_offset) {
        // Ignore alignments starting in the overlap region to prevent reporting duplicated
        //   alignments across job borders
        hsr_alignments.insert(aln_res);
      }
    }
    
    // Store alignment results list onto results queue
    for (std::set<AlignmentResult, AlignmentResultComp>::iterator it = hsr_alignments.begin(); it != hsr_alignments.end(); ++it) {
      //std::cout<<"Storing alignment result "<<std::endl;
      result_queue->Push(*it);
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

