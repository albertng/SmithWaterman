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

#include "swthread.h"
#include "def.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "utils.h"

SWThread::SWThread() {
}

SWThread::SWThread(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
                   ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
                   QuerySeqManager* query_seq_manager) {
  Init(params, hsr_queue, result_queue, ref_seq_manager, query_seq_manager);
}

void SWThread::Init(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
          ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
          QuerySeqManager* query_seq_manager) {
  args_.params = &params_;
  args_.params_mutex = &params_mutex_;
  args_.hsr_queue = hsr_queue;
  args_.result_queue = result_queue;
  args_.ref_seq_manager = ref_seq_manager;
  args_.query_seq_manager = query_seq_manager;

  params_ = params;
  pthread_mutex_init(&params_mutex_, NULL);
}

// Locks the params mutex before setting the params
//   so the params don't change in the middle of an
//   alignment.
void SWThread::SetParams(SwAffineGapParams params) {
  pthread_mutex_lock(&params_mutex_);
  params_ = params;
  pthread_mutex_unlock(&params_mutex_);
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
  int max_score, max_row, max_col, row, col;
  Alignment* aln;
  int max1, max2;
  AlnOp dir1, dir2;

  // Get alignment arguments 
  SwAffineGapParams* params = ((SWThreadArgs*)args)->params;
  pthread_mutex_t* params_mutex = ((SWThreadArgs*)args)->params_mutex;
  ThreadQueue<HighScoreRegion>* hsr_queue = ((SWThreadArgs*)args)->hsr_queue;
  ThreadQueue<AlignmentResult>* result_queue = ((SWThreadArgs*)args)->result_queue;
  RefSeqManager* ref_seq_manager = ((SWThreadArgs*)args)->ref_seq_manager;
  QuerySeqManager* query_seq_manager = ((SWThreadArgs*)args)->query_seq_manager;

  while(true) {
    // Grab available high scoring region
    hsr = hsr_queue->Pop();
    ref_len = hsr.len;
    ref_seq = ref_seq_manager->GetRefSeq(hsr.ref_id, hsr.offset, ref_len);
    query_seq = query_seq_manager->GetQuerySeq(hsr.query_id, &query_len);

    // Initialize new score matrices
    v_matrix = new int*[query_len + 1];
    e_matrix = new int*[query_len + 1];
    f_matrix = new int*[query_len + 1];
    dir_matrix = new AlnOp*[query_len + 1];
    for (int i = 0; i < query_len + 1; i++) {
      v_matrix[i] = new int[ref_len + 1];
      e_matrix[i] = new int[ref_len + 1];
      f_matrix[i] = new int[ref_len + 1];
      dir_matrix[i] = new AlnOp[ref_len + 1];
      for (int j = 0; j < ref_len + 1; j++) {
        v_matrix[i][j] = 0;
        e_matrix[i][j] = 0;
        f_matrix[i][j] = 0;
        dir_matrix[i][j] = ZERO_OP;
      }
    }
    max_score = 0;
    max_row = 0;
    max_col = 0;

    // Compute dynamic programming matrices
    pthread_mutex_lock(params_mutex);
    for (int i = 1; i < query_len + 1; i++) {
      for (int j = 1; j < ref_len + 1; j++) {
        ref_nt = NtChar2Int(ref_seq[j-1]);
        query_nt = NtChar2Int(query_seq[i-1]);
      
        // Compute possible choices
        if (ref_nt == N_NT || query_nt == N_NT) {
          match = -2147483648; // Force N's to align with gaps
        } else {
          match = v_matrix[i-1][j-1] + params->sub_mat[query_nt][ref_nt];
        }
        ins_open   = v_matrix[i][j-1] + params->gap_open;
        ins_extend = e_matrix[i][j-1] + params->gap_extend;
        del_open   = v_matrix[i-1][j] + params->gap_open;
        del_extend = f_matrix[i-1][j] + params->gap_extend;

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
          max_row = i;
          max_col = j;
        }
      }
    }
    pthread_mutex_unlock(params_mutex);

    // Backtrace to obtain alignment
    if (max_score > hsr.threshold) {
      // TODO: POTENTIAL MEMORY LEAK IF NOT CAREFUL
      // MAKE SURE ALIGNMENT IS FREED AFTER BEING USED (I.E. SENT BACK TO CLIENT)
      aln = new Alignment(hsr.offset + max_col, max_row);
      row = max_row;
      col = max_col;
      while (dir_matrix[row][col] != ZERO_OP) {
        switch(dir_matrix[row][col]) {
          case MATCH_OP:  aln->Prepend(ref_seq[col-1], query_seq[row-1]);
                          row--;
                          col--;
                          break;
          case INSERT_OP: aln->Prepend(ref_seq[col-1], GAP);
                          col--;
                         break;
          case DELETE_OP: aln->Prepend(GAP, query_seq[row-1]);
                          row--;
                          break;
         default:        aln->Prepend('X', 'X');   // Shouldn't get here
                          row--;
                          col--;
                          break;
        }
      }

      AlignmentResult aln_res;
      aln_res.hsr = hsr;
      aln_res.alignment = aln;
      aln_res.score = max_score;
    
      result_queue->Push(aln_res);
    }

    // Memory cleanup
    for (int i = 0; i < query_len + 1; i++) {
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
  } 
}

