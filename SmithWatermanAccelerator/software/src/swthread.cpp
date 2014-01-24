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
//      Albert Ng   Jan 15 2014     Added job count
//      Albert Ng   Jan 21 2014     Free ref seq storage at end of SWThread
//      Albert Ng   Jan 22 2014     Changed matrix memory allocation to a managed allocation

#include <list>
#include <set>
#include <assert.h>
#include <time.h>
#include "swthread.h"
#include "def.h"
#include "threadqueue.h"
#include "refseqmanager.h"
#include "queryseqmanager.h"
#include "utils.h"
#include "scoring.h"

#define SWTIMING

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
  args_.stats = &stats_;
  args_.v_matrix = &v_matrix_;
  args_.e_matrix = &e_matrix_;
  args_.f_matrix = &f_matrix_;
  args_.dir_matrix = &dir_matrix_;
  args_.matrix_rows = &matrix_rows_;
  args_.matrix_cols = &matrix_cols_;
  args_.matrices_mutex = &matrices_mutex_;

  v_matrix_ = new int*[1];
  e_matrix_ = new int*[1];
  f_matrix_ = new int*[1];
  dir_matrix_ = new AlnOp*[1];
  v_matrix_[0] = new int[1];
  e_matrix_[0] = new int[1];
  f_matrix_[0] = new int[1];
  dir_matrix_[0] = new AlnOp[1];
  matrix_rows_ = 1;
  matrix_cols_ = 1;
  pthread_mutex_init(&matrices_mutex_, NULL);
  
  ResetStats();
}

void SWThread::Run() {
  pthread_create(&thread_, NULL, &SWThread::Align, (void*) (&args_));
}

void SWThread::Join() {
  pthread_join(thread_, NULL);
}

SWThread::SWThreadStats SWThread::GetStats() {
  return stats_;
}

void SWThread::ResetStats() {
  stats_.job_count = 0;
  stats_.cell_count = 0;
  stats_.ref_seq_time = 0;
  stats_.alloc_time = 0;
  stats_.init_time = 0;
  stats_.compute_time = 0;
  stats_.backtrace_time = 0;
}

void SWThread::ResetMatrices() {
  pthread_mutex_lock(&matrices_mutex_);
  SWThread::ResizeMatrices(&v_matrix_, &e_matrix_, &f_matrix_, &dir_matrix_, matrix_rows_, matrix_cols_, 1, 1);
  matrix_rows_ = 1;
  matrix_cols_ = 1;
  pthread_mutex_unlock(&matrices_mutex_);
}

void SWThread::ResizeMatrices(int*** v_matrix, int*** e_matrix, int*** f_matrix, AlnOp*** dir_matrix, int old_rows, int old_cols, int new_rows, int new_cols) {
  for (int i = 0; i < old_rows; i++) {
    delete[] (*v_matrix)[i];
    delete[] (*e_matrix)[i];
    delete[] (*f_matrix)[i];
    delete[] (*dir_matrix)[i];
  }
  delete[] (*v_matrix);
  delete[] (*e_matrix);
  delete[] (*f_matrix);
  delete[] (*dir_matrix);

  (*v_matrix) = new int*[new_rows];
  (*e_matrix) = new int*[new_rows];
  (*f_matrix) = new int*[new_rows];
  (*dir_matrix) = new AlnOp*[new_rows];
  for (int i = 0; i < new_rows; i++) {
    (*v_matrix)[i] = new int[new_cols];
    (*e_matrix)[i] = new int[new_cols];
    (*f_matrix)[i] = new int[new_cols];
    (*dir_matrix)[i] = new AlnOp[new_cols];
  }
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
  SWThreadStats* stats = ((SWThreadArgs*)args)->stats;
  int*** v_matrix = ((SWThreadArgs*)args)->v_matrix;
  int*** e_matrix = ((SWThreadArgs*)args)->e_matrix;
  int*** f_matrix = ((SWThreadArgs*)args)->f_matrix;
  AlnOp*** dir_matrix = ((SWThreadArgs*)args)->dir_matrix;
  int* matrix_rows = ((SWThreadArgs*)args)->matrix_rows;
  int* matrix_cols = ((SWThreadArgs*)args)->matrix_cols;
  pthread_mutex_t* matrices_mutex = ((SWThreadArgs*)args)->matrices_mutex;
  
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  int gap_open;
  int gap_extend;
  
  struct timespec start, finish;
  double elapsed;
  
  while(true) {
    // Grab available high scoring region
    HighScoreRegion hsr = hsr_queue->Pop();
    stats->job_count++;   
    
    int ref_len = hsr.len;
    int query_len;
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif
    char* ref_seq = ref_seq_manager->GetRefSeq(hsr.ref_id, hsr.chr_id, hsr.offset, ref_len);
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    stats->ref_seq_time += elapsed;
#endif 
    char* query_seq = query_seq_manager->GetQuerySeq(hsr.query_id, &query_len);
    
    // Get the scoring parameters
    hsr.params.GetSubMat(sub_mat);
    gap_open = hsr.params.GetGapOpen();
    gap_extend = hsr.params.GetGapExtend();
    
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif
    // Reallocate matrix memory if more memory needed
    pthread_mutex_lock(matrices_mutex);   // Using matrices, shared resource
    if ((ref_len + 1 > *matrix_rows) || (query_len + 1 > *matrix_cols)) {
      SWThread::ResizeMatrices(v_matrix, e_matrix, f_matrix, dir_matrix, *matrix_rows, *matrix_cols, ref_len + 1, query_len + 1);
      *matrix_rows = ref_len + 1;
      *matrix_cols = query_len + 1;
    }
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    stats->alloc_time += elapsed;
#endif 

#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif
    // Initialize scoring matrices
    for (int i = 0; i < ref_len + 1; i++) {
      (*v_matrix)[i][0] = 0;
      (*e_matrix)[i][0] = 0;
      (*f_matrix)[i][0] = 0;
      (*dir_matrix)[i][0] = ZERO_OP;
    }
    for (int j = 0; j < query_len + 1; j++) {
      (*v_matrix)[0][j] = 0;
      (*e_matrix)[0][j] = 0;
      (*f_matrix)[0][j] = 0;
      (*dir_matrix)[0][j] = ZERO_OP;
    }
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    stats->init_time += elapsed;
#endif 

#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif  
    // Compute dynamic programming matrices
    std::set<Cell, CellComp> highscore_cells;
    stats->cell_count += (ref_len * query_len);
    for (int i = 1; i < ref_len + 1; i++) {
      for (int j = 1; j < query_len + 1; j++) {
        NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
        NtInt query_nt = NtChar2Int(query_seq[j-1]);
      
        int match;
        if (ref_nt == N_NT || query_nt == N_NT) {
          match = -2147483648; // Force N's to align with gaps
        } else {
          match = (*v_matrix)[i-1][j-1] + sub_mat[query_nt][ref_nt];
        }
        int ins_open   = (*v_matrix)[i-1][j] + gap_open;
        int ins_extend = (*e_matrix)[i-1][j] + gap_extend;
        int del_open   = (*v_matrix)[i][j-1] + gap_open;
        int del_extend = (*f_matrix)[i][j-1] + gap_extend;

        (*e_matrix)[i][j] = (ins_open > ins_extend) ? ins_open : ins_extend;
        (*f_matrix)[i][j] = (del_open > del_extend) ? del_open : del_extend;
        
        int max1 = (*e_matrix)[i][j];
        AlnOp dir1 = INSERT_OP;
        if (match > max1) {
          max1 = match;
          dir1 = MATCH_OP;
        }
        int max2 = 0;
        AlnOp dir2 = ZERO_OP;
        if ((*f_matrix)[i][j] > 0) {
          max2 = (*f_matrix)[i][j];
          dir2 = DELETE_OP;
        }
        if (max1 > max2) {
          (*v_matrix)[i][j] = max1;
          (*dir_matrix)[i][j] = dir1;
        } else {
          (*v_matrix)[i][j] = max2;
          (*dir_matrix)[i][j] = dir2;
        }
        
        // Record high-scoring cells
        if ((*v_matrix)[i][j] >= hsr.threshold) {
          Cell hsc;
          hsc.ref_index = i;
          hsc.query_index = j;
          hsc.score = (*v_matrix)[i][j];
          highscore_cells.insert(hsc);
        }
      }
    }
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    stats->compute_time += elapsed;
#endif 

#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif  
    // Backtrace to obtain alignments
    std::set<AlignmentResult, AlignmentResultComp> hsr_alignments;
    for (std::set<Cell, CellComp>::iterator it = highscore_cells.begin(); it != highscore_cells.end(); ++it) {
      int query_index = (*it).query_index;
      int ref_index = (*it).ref_index;
      int score = (*it).score;
      
      // Build the alignment
      Alignment aln(hsr.offset + ref_index, query_index);
      while ((*dir_matrix)[ref_index][query_index] != ZERO_OP) {
        // Keep alignments ending with the right-most max score cell
        if ((*v_matrix)[ref_index][query_index] > score) {
          score = (*v_matrix)[ref_index][query_index];
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

        switch((*dir_matrix)[ref_index][query_index]) {
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
          default:        assert(false);
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

    pthread_mutex_unlock(matrices_mutex); // Done with matrices, shared resource
#ifdef SWTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    stats->backtrace_time += elapsed;
#endif 
    
    // Store alignment results list onto results queue
    for (std::set<AlignmentResult, AlignmentResultComp>::iterator it = hsr_alignments.begin(); it != hsr_alignments.end(); ++it) {
      result_queue->Push(*it);
    }

    // Memory cleanup
    delete[] ref_seq;
 
    // Decrement outstanding high scoring region count 
    query_seq_manager->DecHighScoreRegionCount(hsr.query_id);
  } 
}

