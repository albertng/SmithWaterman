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
//      Albert Ng   Feb 11 2014     No longer keeps full scoring matrices in memory

#include <list>
#include <set>
#include <unordered_set>
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
  /*args_.h_matrix = &h_matrix_;
  args_.m_matrix = &m_matrix_;
  args_.i_matrix = &i_matrix_;
  args_.d_matrix = &d_matrix_;*/
  args_.dir_h_matrix = &dir_h_matrix_;
  args_.dir_m_matrix = &dir_m_matrix_;
  args_.dir_i_matrix = &dir_i_matrix_;
  args_.dir_d_matrix = &dir_d_matrix_;
  args_.matrix_rows = &matrix_rows_;
  args_.matrix_cols = &matrix_cols_;
  args_.matrices_mutex = &matrices_mutex_;

  /*h_matrix_ = new int*[1];
  m_matrix_ = new int*[1];
  i_matrix_ = new int*[1];
  d_matrix_ = new int*[1];*/
  dir_h_matrix_ = new AlnOp*[1];
  dir_m_matrix_ = new AlnOp*[1];
  dir_i_matrix_ = new AlnOp*[1];
  dir_d_matrix_ = new AlnOp*[1];
  /*h_matrix_[0] = new int[1];
  m_matrix_[0] = new int[1];
  i_matrix_[0] = new int[1];
  d_matrix_[0] = new int[1];*/
  dir_h_matrix_[0] = new AlnOp[1];
  dir_m_matrix_[0] = new AlnOp[1];
  dir_i_matrix_[0] = new AlnOp[1];
  dir_d_matrix_[0] = new AlnOp[1];
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
  SWThread::ResizeMatrices(&dir_h_matrix_, &dir_m_matrix_, &dir_i_matrix_, &dir_d_matrix_, matrix_rows_, matrix_cols_, 1, 1);
  matrix_rows_ = 1;
  matrix_cols_ = 1;
  pthread_mutex_unlock(&matrices_mutex_);
}

void SWThread::ResizeMatrices(AlnOp*** dir_h_matrix, AlnOp*** dir_m_matrix, AlnOp*** dir_i_matrix, AlnOp*** dir_d_matrix, int old_rows, int old_cols, int new_rows, int new_cols) {
  for (int i = 0; i < old_rows; i++) {
    delete[] (*dir_h_matrix)[i];
    delete[] (*dir_m_matrix)[i];
    delete[] (*dir_i_matrix)[i];
    delete[] (*dir_d_matrix)[i];
  }
  delete[] (*dir_h_matrix);
  delete[] (*dir_m_matrix);
  delete[] (*dir_i_matrix);
  delete[] (*dir_d_matrix);

  (*dir_h_matrix) = new AlnOp*[new_rows];
  (*dir_m_matrix) = new AlnOp*[new_rows];
  (*dir_i_matrix) = new AlnOp*[new_rows];
  (*dir_d_matrix) = new AlnOp*[new_rows];
  for (int i = 0; i < new_rows; i++) {
    (*dir_h_matrix)[i] = new AlnOp[new_cols];
    (*dir_m_matrix)[i] = new AlnOp[new_cols];
    (*dir_i_matrix)[i] = new AlnOp[new_cols];
    (*dir_d_matrix)[i] = new AlnOp[new_cols];
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
  AlnOp*** dir_h_matrix = ((SWThreadArgs*)args)->dir_h_matrix;
  AlnOp*** dir_m_matrix = ((SWThreadArgs*)args)->dir_m_matrix;
  AlnOp*** dir_i_matrix = ((SWThreadArgs*)args)->dir_i_matrix;
  AlnOp*** dir_d_matrix = ((SWThreadArgs*)args)->dir_d_matrix;
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
      SWThread::ResizeMatrices(dir_h_matrix, dir_m_matrix, dir_i_matrix, dir_d_matrix, *matrix_rows, *matrix_cols, ref_len + 1, query_len + 1);
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
    // Initialize direction matrices
    for (int i = 0; i < ref_len + 1; i++) {
      (*dir_h_matrix)[i][0] = ZERO_OP;
      (*dir_m_matrix)[i][0] = ZERO_OP;
      (*dir_i_matrix)[i][0] = ZERO_OP;
      (*dir_d_matrix)[i][0] = ZERO_OP;
    }
    for (int j = 0; j < query_len + 1; j++) {
      (*dir_h_matrix)[0][j] = ZERO_OP;
      (*dir_m_matrix)[0][j] = ZERO_OP;
      (*dir_i_matrix)[0][j] = ZERO_OP;
      (*dir_d_matrix)[0][j] = ZERO_OP;
    }
    
    // Initialize scoring matrix row buffers
    int* h_matrix_wr = new int[query_len + 1];
    int* m_matrix_wr = new int[query_len + 1];
    int* i_matrix_wr = new int[query_len + 1];
    int* d_matrix_wr = new int[query_len + 1];
    int* h_matrix_rd = new int[query_len + 1];
    int* m_matrix_rd = new int[query_len + 1];
    int* i_matrix_rd = new int[query_len + 1];
    int* d_matrix_rd = new int[query_len + 1];
    for (int i = 0; i < query_len + 1; i++) {
      h_matrix_rd[i] = 0;
      m_matrix_rd[i] = 0;
      i_matrix_rd[i] = 0;
      d_matrix_rd[i] = 0;
      h_matrix_wr[i] = 0;
      m_matrix_wr[i] = 0;
      i_matrix_wr[i] = 0;
      d_matrix_wr[i] = 0;
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
      int* m_matrix_tmp = m_matrix_wr;
      int* h_matrix_tmp = h_matrix_wr;
      int* i_matrix_tmp = i_matrix_wr;
      int* d_matrix_tmp = d_matrix_wr;
      m_matrix_wr = m_matrix_rd;
      h_matrix_wr = h_matrix_rd;
      i_matrix_wr = i_matrix_rd;
      d_matrix_wr = d_matrix_rd;
      m_matrix_rd = m_matrix_tmp;
      h_matrix_rd = h_matrix_tmp;
      i_matrix_rd = i_matrix_tmp;
      d_matrix_rd = d_matrix_tmp;
      for (int j = 1; j < query_len + 1; j++) {
        NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
        NtInt query_nt = NtChar2Int(query_seq[j-1]);
      
        int match = (ref_nt == N_NT || query_nt == N_NT) ? -2147483648 : sub_mat[query_nt][ref_nt];
        if (m_matrix_rd[j-1] > i_matrix_rd[j-1] && m_matrix_rd[j-1] > d_matrix_rd[j-1]) {
          m_matrix_wr[j] = m_matrix_rd[j-1] + match;
          (*dir_m_matrix)[i][j] = MATCH_OP;
        } else if (i_matrix_rd[j-1] > d_matrix_rd[j-1]) {
          m_matrix_wr[j] = i_matrix_rd[j-1] + match;
          (*dir_m_matrix)[i][j] = INSERT_OP;
        } else {
          m_matrix_wr[j] = d_matrix_rd[j-1] + match;
          (*dir_m_matrix)[i][j] = DELETE_OP;
        }
        if (m_matrix_wr[j] < 0) {
          m_matrix_wr[j] = 0;
          (*dir_m_matrix)[i][j] = ZERO_OP;
        }

        int ins_open   = m_matrix_rd[j] + gap_open;
        int ins_extend = i_matrix_rd[j] + gap_extend;
        int del_open   = m_matrix_wr[j-1] + gap_open;
        int del_extend = d_matrix_wr[j-1] + gap_extend;

        i_matrix_wr[j] = (ins_open > ins_extend) ? ins_open : ins_extend;
        (*dir_i_matrix)[i][j] = (ins_open > ins_extend) ? MATCH_OP : INSERT_OP;
        d_matrix_wr[j] = (del_open > del_extend) ? del_open : del_extend;
        (*dir_d_matrix)[i][j] = (del_open > del_extend) ? MATCH_OP : DELETE_OP;
        
        int max1 = m_matrix_wr[j] > i_matrix_wr[j] ? m_matrix_wr[j] : i_matrix_wr[j];
        AlnOp dir1 = m_matrix_wr[j] > i_matrix_wr[j] ? (*dir_m_matrix)[i][j] : (*dir_i_matrix)[i][j];
        int max2 = d_matrix_wr[j] > 0 ? d_matrix_wr[j] : 0;
        AlnOp dir2 = d_matrix_wr[j] > 0 ? (*dir_d_matrix)[i][j] : ZERO_OP;
        h_matrix_wr[j] = max1 > max2 ? max1 : max2;
        (*dir_h_matrix)[i][j] = max1 > max2 ? dir1 : dir2;

        // Record high-scoring cells
        if (h_matrix_wr[j] >= hsr.threshold) {
          //std::cout<< "Threshold: " << hsr.threshold << std::endl;
          Cell hsc;
          hsc.ref_index = i;
          hsc.query_index = j;
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
      
      // Build the alignment
      Alignment aln(hsr.offset + ref_index, query_index, hsr.pos_strand);
      AlnOp cur_op = (*dir_h_matrix)[ref_index][query_index];
      AlnOp*** dir_matrix;
      switch(cur_op) {
        case MATCH_OP:  dir_matrix = dir_m_matrix;
                        break;
        case INSERT_OP: dir_matrix = dir_i_matrix;
                        break;
        case DELETE_OP: dir_matrix = dir_d_matrix;
                        break;
      }
      while((*dir_h_matrix)[ref_index][query_index] != ZERO_OP) {
        // Remove visited cells from the high score cell list
        if (!(query_index == (*it).query_index && ref_index == (*it).ref_index)) {
          Cell hsc;
          hsc.query_index = query_index;
          hsc.ref_index = ref_index;
          highscore_cells.erase(hsc);
        }

        switch(cur_op) {
          case MATCH_OP:  aln.Prepend(ref_seq[ref_index-1], query_seq[query_index-1]);
                          cur_op = (*dir_m_matrix)[ref_index][query_index];
                          switch(cur_op) {
                            case MATCH_OP:  dir_matrix = dir_m_matrix;
                                            break;
                            case INSERT_OP: dir_matrix = dir_i_matrix;
                                            break;
                            case DELETE_OP: dir_matrix = dir_d_matrix;
                                            break;
                            default: assert(false);
                          }
                          query_index--;  
                          ref_index--;
                          break;
          case INSERT_OP: aln.Prepend(ref_seq[ref_index-1], GAP);
                          cur_op = (*dir_i_matrix)[ref_index][query_index];
                          switch(cur_op) {
                            case MATCH_OP:  dir_matrix = dir_m_matrix;
                                            break;
                            case INSERT_OP: dir_matrix = dir_i_matrix;
                                            break;
                            default: assert(false);
                          }
                          ref_index--;
                          break;
          case DELETE_OP: aln.Prepend(GAP, query_seq[query_index-1]);
                          cur_op = (*dir_d_matrix)[ref_index][query_index];
                          switch(cur_op) {
                            case MATCH_OP:  dir_matrix = dir_m_matrix;
                                            break;
                            case DELETE_OP: dir_matrix = dir_d_matrix;
                                            break;
                            default: assert(false);
                          }
                          query_index--;
                          break;
          default:        assert(false);
        }
      }
      aln.TrimEnd(hsr.params);
      int aln_score = aln.ComputeScore(hsr.params);
      
      AlignmentResult aln_res;
      aln_res.hsr = hsr;
      aln_res.alignment = aln;
      aln_res.score = aln_score;
      
      // Indicate whether or not the alignment falls on a boundary for duplicate
      //   checking in the main thread before reporting. 
      /*if ((aln.get_ref_offset() == hsr.job_offset) || 
          (aln.get_ref_offset() + aln.GetRefLength() >= hsr.overlap_offset)) {
        aln_res.boundary = true;
      } else {
        aln_res.boundary = false;
      }*/

      std::set<AlignmentResult, AlignmentResultComp>::iterator aln_it = hsr_alignments.find(aln_res);
      if (aln_it != hsr_alignments.end()) {
        // Filter out same start-index duplicate alignments, pick the highest scoring, longest duplicated alignment
        int aln_it_score = (*aln_it).alignment.ComputeScore(hsr.params);
        if ((aln_it_score < aln_score) || 
            (aln_it_score == aln_score && (*aln_it).alignment.GetLength() < aln_res.alignment.GetLength())) {
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
    delete[] h_matrix_wr;
    delete[] m_matrix_wr;
    delete[] i_matrix_wr;
    delete[] d_matrix_wr;
    delete[] h_matrix_rd;
    delete[] m_matrix_rd;
    delete[] i_matrix_rd;
    delete[] d_matrix_rd;
 
    // Decrement outstanding high scoring region count 
    query_seq_manager->DecHighScoreRegionCount(hsr.query_id);
  } 
}

