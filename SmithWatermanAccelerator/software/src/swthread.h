//  File Name        : swthread.h
//  Description      : Smith-Waterman aligner thread definitions
//
//                     The SWThread class is the worker thread class that performs
//                     software Smith-Waterman alignment construction on high scoring
//                     regions discovered by the FPGA accelerator engines. They
//                     obtain high scoring regions from a HighScoreRegion shared
//                     queue prepared by the ResultsReaderThread, and store
//                     completed alignments in an AlignmentResult shared queue
//                     for the main thread.
//
//                     The class receives the query id, reference id, high scoring
//                     region length and offset from the HighScoreRegion shared
//                     queue. With this info, it obtains the query sequence and
//                     reference sequence from a shared QuerySeqManager and 
//                     RefSeqManager, respectively.
//
//                     Upon completion of an alignment, it decrements the high
//                     scoring region count (managed by the query sequence manager)
//                     of that query.
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//      Albert Ng   Oct 05 2013     AlnOp names suffixed with _OP
//      Albert Ng   Oct 07 2013     Added SWThread::Join()
//      Albert Ng   Oct 09 2013     Added query seq manager
//      Albert Ng   Oct 22 2013     Removed params and params_mutex member variables
//      Albert Ng   Jan 15 2013     Added SWThreadStats
//      Albert Ng   Jan 22 2014     Changed matrix memory allocation to a managed allocation

#ifndef SWTHREAD_H_
#define SWTHREAD_H_

#include <pthread.h>
#include "def.h"
#include "threadqueue.h"
#include "utils.h"
#include "refseqmanager.h"
#include "queryseqmanager.h"

// Software Smith-Waterman aligner worker thread
class SWThread {
  public:
    // Empty constructor
    SWThread();

    // Complete constructor 
    SWThread(ThreadQueue<HighScoreRegion>* hsr_queue,
             ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
             QuerySeqManager* query_seq_manager);

    // Initialization function (called by constructor)
    void Init(ThreadQueue<HighScoreRegion>* hsr_queue,
             ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager,
             QuerySeqManager* query_seq_manager);

    // Run the thread
    void Run();  

    // Join the thread
    //   Can't be used for now, since the thread infinite loops and never terminates
    void Join();

    // Performance statistics
    struct SWThreadStats {
      long long int job_count;
      long long int cell_count;
      double ref_seq_time;
      double alloc_time;
      double init_time;
      double compute_time;
      double backtrace_time;
    };
    SWThreadStats GetStats();
    void ResetStats();

    // Reset the memory allocation for the matrices
    void ResetMatrices();

  private:
    // Enumeration of possible alignment operations
    enum AlnOp {INSERT_OP, DELETE_OP, MATCH_OP, ZERO_OP};

    // Smith-Waterman aligner thread arguments struct
    struct SWThreadArgs {    
      // Pointer to shared job queue of high scoring regions to be aligned
      ThreadQueue<HighScoreRegion>* hsr_queue;
    
      // Pointer to shared result queue in which alignment results are to be stored
      ThreadQueue<AlignmentResult>* result_queue;

      // Pointer to shared reference sequence manager
      RefSeqManager* ref_seq_manager;

      // Pointer to shared query sequence manager
      QuerySeqManager* query_seq_manager;
      
      // Pointer to statistics structure
      SWThreadStats* stats;
      
      // Pointers to scoring matrices
      int*** v_matrix;
      int*** e_matrix;
      int*** f_matrix;
      AlnOp*** dir_matrix;
      int* matrix_rows;
      int* matrix_cols;
      pthread_mutex_t* matrices_mutex;
    };

    // Data structure representing an individual DP matrix cell
    struct Cell {
      int ref_index;
      int query_index;
      
      bool operator==(const Cell& rhs) {
        return ref_index == rhs.ref_index && query_index == rhs.query_index;
      }
    };
    
    // Individual DP matrix comparison (descending order by ref index)
    struct CellComp {
      bool operator() (const Cell& lhs, const Cell& rhs) const {
        if (lhs.ref_index > rhs.ref_index) {
          return true;
        }
        else if (lhs.ref_index == rhs.ref_index) {
          return lhs.query_index > rhs.query_index;
        } else {
          return false;
        }
      }
    };

    // Function for thread to run.
    // Continuously perform alignments, grabbing alignment jobs from the hsr_queue
    //   and storing results in the result_queue
    static void* Align(void* args);

    // Helper function to resize the matrices to the given dimensions
    static void ResizeMatrices(int*** v_matrix, int*** e_matrix, int*** f_matrix, AlnOp*** dir_matrix, int old_rows, int old_cols, int new_rows, int new_cols);

    // Actual pthread instance
    pthread_t thread_;
    
    // Thread arguments
    SWThreadArgs args_;
    
    // Statistics
    SWThreadStats stats_;
    
    // Scoring matrices 
    int** v_matrix_;     // Score matrix
    int** e_matrix_;     // Insertion score matrix
    int** f_matrix_;     // Deletion score matrix
    AlnOp** dir_matrix_; // Alignment ops for score matrix
    int matrix_rows_;    // Current number of rows in matrices
    int matrix_cols_;    // Current number of cols in matrices
    pthread_mutex_t matrices_mutex_;
};

#endif // SWTHREAD_H_
