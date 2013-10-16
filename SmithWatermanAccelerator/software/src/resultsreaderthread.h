//  File Name        : resultsreaderthread.h
//  Description      : FPGA Engine Results Reader Thread definitions
//
//                     The ResultsReaderThread receives high scoring ref seq block indices
//                     (and end of alignment tokens) from the FPGA accelerator engines,
//                     coalesces adjacent high scoring ref seq blocks into high scoring
//                     regions, extends the high scoring region by two query lengths, and
//                     stores the high scoring regions onto a shared HighScoreRegion queue
//                     for the SWThread worker threads to perform the software alignment.
//
//                     The thread round robin reads from FPGA engine streams and parses
//                     the high scoring blocks (and end of alignment tokens) in FSMs. The
//                     FSMs coalesce adjacent blocks and stores high scoring regions onto
//                     the shared HighScoreRegion queue.
//
//                     When a high scoring region is enqueued, the thread increments the
//                     high scoring region count (managed by the query seq manager) for
//                     the query. When it receives an end of alignment token, it decrements
//                     the high scoring region count. This is because the high scoring
//                     region count is initialized with the number of engines the query is
//                     scheduled across, or equivalently, the number of end of alignment
//                     tokens expected to be received. Therefore, the only time the high
//                     scoring region count of a query hits zero is when the alignment is
//                     is completely finished.
//
//  Revision History :
//      Albert Ng   Oct 08 2013     Initial Revision 
//      Albert Ng   Oct 10 2013     Finished initial implementation
//      Albert Ng   Oct 15 2013     Removed num_drivers and num_streams

#ifndef RESULTSREADERTHREAD_H_
#define RESULTSREADERTHREAD_H_

#include "picodrv_stub.h"
#include "threadqueue.h"
#include "def.h"
#include "queryseqmanager.h"
#include <pthread.h>
#include <stdint.h>

// Thread that handles reading and processing the results from the
//   FPGA engines
class ResultsReaderThread {
  public:
    // Empty constructor
    ResultsReaderThread();

    // Complete constructor
    ResultsReaderThread(PicoDrv* pico_drivers, int** streams,
                        ThreadQueue<HighScoreRegion>* hsr_queue, 
                        QuerySeqManager* query_seq_manager,
                        ThreadQueue<AlignmentJob>** engine_job_queues);

    // Initialization function (called by constructor)
    void Init(PicoDrv* pico_drivers, int** streams, 
              ThreadQueue<HighScoreRegion>* hsr_queue, QuerySeqManager* query_seq_manager,
              ThreadQueue<AlignmentJob>** engine_job_queues);

    // Run the thread
    void Run();

    // Join the thread
    // Can't be used for now, since the thread infinite loops and never terminates
    void Join();

  private:
    // High Score Region parser FSM states
    enum HSRParserState {INIT, IN_HSR};

    // FPGA engine results reader thread arguments struct
    struct ResultsReaderThreadArgs {
      // Pointers to FPGA driver class objects
      PicoDrv* pico_drivers;

      // Engine stream handles, indexed by [FPGA][Stream]
      int** streams;

      // Pointer to shared job queue of high scoring regions to be aligned
      ThreadQueue<HighScoreRegion>* hsr_queue;

      // Pointer to shared query sequence manager
      QuerySeqManager* query_seq_manager;

      // Pointers to queues of alignment jobs scheduled to the FPGA engines
      // Indexed by [FPGA][Stream]
      ThreadQueue<AlignmentJob>** engine_job_queues;
    };

    // Data structure holding a coalesced group of adjacent high scoring blocks
    struct CoalescedHighScoreBlock {
      int block_offset; // Block index offset
      int num_blocks;   // Number of blocks in this coalesced group
    };

    // Function for thread to run.
    // Continuously read results from engines, process them into HighScoreRegions,
    //   and store them into the hsr_queue
    static void* ReadResults(void* args);

    // Actual pthread instance
    pthread_t thread_;
    
    // Thread arguments
    ResultsReaderThreadArgs args_;

    // Memory buffer size
    static const int READ_BUF_SIZE = 4096;

    // High Score Block value indicating the end of an alignment for the engine
    static const uint32_t END_OF_ALIGNMENT = 0xFFFFFFFF;

    // HELPER FUNCTIONS
    // Store the high-score-region onto the high-score-region queue
    static void StoreHSR(CoalescedHighScoreBlock chsb, AlignmentJob job, ThreadQueue<HighScoreRegion>* hsr_queue, QuerySeqManager* query_seq_manager);

    // Begin a new high-score-block for the alignment job
    static CoalescedHighScoreBlock StartCHSB(uint32_t block_offset);

    // Extend the coalesced high-score-block by a block
    static CoalescedHighScoreBlock ExtendCHSB(CoalescedHighScoreBlock chsb);

    // Check if a high-score-block is adjacent to the coalesced high-score-block
    static bool IsAdjacentBlock(uint32_t high_score_block, CoalescedHighScoreBlock);
};

#endif // RESULTSREADERTHREAD_H_
