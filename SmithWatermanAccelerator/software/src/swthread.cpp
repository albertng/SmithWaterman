//  File Name        : sw.cpp
//  Description      : Smith-Waterman aligner thread
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision
//      Albert Ng   Oct 04 2013     Completed initial implementation
//      Albert Ng   Oct 07 2013     Added SWThread::Join()

#include "swthread.h"
#include "sharedstructs.h"
#include "threadqueue.h"
#include "refseqmanager.h"
#include "utils.h"

SWThread::SWThread() {
  SwAffineGapParams dummy;
  SWThread(dummy, NULL, NULL);
}

SWThread::SWThread(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
                   ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager) {
  params_ = params;
  hsr_queue_ = hsr_queue;
  result_queue_ = result_queue;
  ref_seq_manager_ = ref_seq_manager;
}

void SWThread::set_params(SwAffineGapParams params) {
  params_ = params;
}

void SWThread::Run() {
  pthread_create(&thread_, NULL, &Align, NULL);
}

void SWThread::Join() {
  pthread_join(thread_, NULL);
}

void* SWThread::Align(void* args) {
  int** v_matrix;   // Score matrix
  int** e_matrix;   // Insertion score matrix
  int** f_matrix;   // Deletion score matrix
  AlnOp** dir_matrix; // Alignment ops for score matrix
  char* ref_seq;
  char* query_seq;
  HighScoreRegion hsr;
  NtInt ref_nt, query_nt;
  int ins_open, ins_extend, del_open, del_extend, match;
  int max_score, max_row, max_col, row, col;
  Alignment* aln;
  int max1, max2;
  AlnOp dir1, dir2;

  while(true) {
    // Grab available high scoring region
    hsr = hsr_queue_.Pop();
    ref_seq = ref_seq_manager_->GetRefSeq(hsr.ref_id, hsr.ref_offset, hsr.ref_len);
    query_seq = hsr.query_seq;    

    // Initialize new score matrices
    v_matrix = new int*[hsr.query_len + 1];
    e_matrix = new int*[hsr.query_len + 1];
    f_matrix = new int*[hsr.query_len + 1];
    dir_matrix = new int*[hsr.query_len + 1];
    for (int i = 0; i < hsr.query_len + 1; i++) {
      v_matrix[i] = new int[hsr.ref_len + 1];
      e_matrix[i] = new int[hsr.ref_len + 1];
      f_matrix[i] = new int[hsr.ref_len + 1];
      dir_matrix[i] = new int[hsr.ref_len + 1];
      for (int j = 0; j < hsr.ref_len + 1; j++) {
        v_matrix[i][j] = 0;
        e_matrix[i][j] = 0;
        f_matrix[i][j] = 0;
        dir_matrix[i][j] = ZERO_OP;
    }
    max_score = 0;
    max_row = 0;
    max_col = 0;

    // Compute dynamic programming matrices
    for (int i = 1; i < hsr.query_len + 1; i++) {
      for (int j = 1; j < hsr.ref_len + 1; j++) {
        ref_nt = NtChar2Int(ref_seq[j-1]);
        query_nt = NtChar2Int(query_seq[i-1]);
        
        // Compute possible choices
        if (ref_nt == N_NT || query_nt == N_NT) {
          match = -2147483648; // Force N's to align with gaps
        else {
          match = v_matrix[i-1][j-1] + params_.sub_mat[query_nt][ref_nt];
        }
        ins_open   = v_matrix[i-1][j] + params_.gap_open;
        ins_extend = e_matrix[i-1][j] + params_.gap_extend;
        del_open   = v_matrix[i][j-1] + params_.gap_open;
        del_extend = f_matrix[i][j-1] + params_.gap_extend;

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
        else {
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

    // Backtrace to obtain alignment
    if (max_score > hsr.threshold) {
      aln = new Alignment;
      row = max_row;
      col = max_col;
      while (dir_matrix[row][col] != ZERO_OP) {
        switch(dir_matrix[row][col]) {
          case MATCH_OP:  aln->Prepend(ref_seq[col-1], query_seq[row-1]);
                          row--;
                          col--;
                          break;
          case INSERT_OP: aln->Prepend(ref_seq[col-1], '-');
                          col--;
                          break;
          case DELETE_OP: aln->Prepend('-', query_seq[row-1]);
                          row--;
                          break;
          default:        aln->Prepend('X', 'X');   // Shouldn't get here
                          row--;
                          col--;
                          break;
        }
      }

      AlignmentResult* aln_res = new AlignmentResult;
      aln_res->hsr = hsr;
      aln_res->alignment = aln;
      aln_res->score = max_score;
      
      result_queue_->Push(aln_res);
    }

    // Memory cleanup
    for (int i = 0; i < hsr.query_len + 1; i++) {
      delete[] v_matrix[i];
      delete[] e_matrix[i];
      delete[] f_matrix[i];
      delete[] dir_matrix[i];
    }
    delete[] v_matrix;
    delete[] e_matrix;
    delete[] f_matrix;
    delete[] dir_matrix;
  }   
}
