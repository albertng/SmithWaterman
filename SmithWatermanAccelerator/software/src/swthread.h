//  File Name        : sw.h
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
#include "refseqmanager.h"
#include "utils.h"

// Enumeration of possible alignment operations
enum AlnOp {INSERT_OP, DELETE_OP, MATCH_OP, ZERO_OP};

class SWThread {
  public:
    // Empty constructor (shouldn't use)
    SWThread();

    // Full constructor 
    SWThread(SwAffineGapParams params, ThreadQueue<HighScoreRegion>* hsr_queue,
             ThreadQueue<AlignmentResult>* result_queue, RefSeqManager* ref_seq_manager);

    // Set affine gap scoring metric parameters
    void set_params(SwAffineGapParams params);

    // Run the thread
    void Run();  

    // Join the thread
    // Can't be used for now, since the thread infinite loops and never terminates
    void Join(); 

  private:
    // Continuously perform alignments
    void* Align(void* args);

    // Actual pthread instance
    pthread_t thread_;

    // Affine gap metric scoring parameters
    SwAffineGapParams params_;

    // Pointer to shared job queue of high scoring regions to be aligned
    ThreadQueue<HighScoreRegion>* hsr_queue_;

    // Pointer to shared result queue in which alignment results are to be stored
    ThreadQueue<AlignmentResult>* result_queue_;

    // Pointer to shared reference sequence memory manager
    RefSeqManager* ref_seq_manager_;
}

#endif // SWTHREAD_H_
