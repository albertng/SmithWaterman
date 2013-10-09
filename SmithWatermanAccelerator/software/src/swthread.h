//  File Name        : swthread.h
//  Description      : Smith-Waterman aligner thread definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//      Albert Ng   Oct 05 2013     AlnOp names suffixed with _OP
//      Albert Ng   Oct 07 2013     Added SWThread::Join()

#ifndef SWTHREAD_H_
#define SWTHREAD_H_

#include <pthread.h>
#include "sharedstructs.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "utils.h"

// Enumeration of possible alignment operations
enum AlnOp {INSERT_OP, DELETE_OP, MATCH_OP, ZERO_OP};

// Software Smith-Waterman aligner worker thread
class SWThread {
  public:
    // Empty constructor
    SWThread();

    // Complete constructor 
    SWThread(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
             ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager);

    // Initialization function (called by constructor)
    void Init(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
             ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager);

    // Set affine gap scoring metric parameters
    void SetParams(SwAffineGapParams params);

    // Run the thread
    void Run();  

    // Join the thread
    // Can't be used for now, since the thread infinite loops and never terminates
    void Join(); 

  private:
    // Smith-Waterman aligner thread arguments struct
    struct SWThreadArgs {
      // Pointer to affine gap metric scoring parameters
      SwAffineGapParams* params;          
  
      // Pointer to mutex for scoring parameters
      pthread_mutex_t* params_mutex;
    
      // Pointer to shared job queue of high scoring regions to be aligned
      ThreadQueue<HighScoreRegion>* hsr_queue;
    
      // Pointer to shared result queue in which alignment results are to be stored
      ThreadQueue<AlignmentResult>* result_queue;
    
      // Pointer to shared reference sequence memory manager
      RefSeqManager* ref_seq_manager;
    };

    // Function for thread to run.
    // Continuously perform alignments, grabbing alignment jobs from the hsr_queue
    //   and storing results in the result_queue
    static void* Align(void* args);

    // Actual pthread instance
    pthread_t thread_;
    
    // Thread arguments
    SWThreadArgs args_;

    // Smith-Waterman affine gap scoring params
    SwAffineGapParams params_;

    // Mutex for scoring params
    pthread_mutex_t params_mutex_;
};

#endif // SWTHREAD_H_
