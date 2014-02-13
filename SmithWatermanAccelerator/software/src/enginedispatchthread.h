//  File Name        : enginedispatchthread.h
//  Description      : FPGA Engine Alignment Dispatch Thread definitions
//
//  Revision History :
//      Albert Ng   Oct 15 2013     Initial Revision 
//      Albert Ng   Oct 22 2013     Added SwAffineGapParams to AlignmentJob and EngineJob
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2013     Added ref seq banking
//      Albert Ng   Jan 29 2014     Combined multiple engine jobs into larger PCIe streams

#ifndef ENGINEDISPATCHTHREAD_H_
#define ENGINEDISPATCHTHREAD_H_

#include <pthread.h>
#include <vector>
#include "def.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "scoring.h"
#include "dispatchworkerthread.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

class EngineDispatchThread{
  public:
    // Empty constructor
    EngineDispatchThread();

    // Complete constructor
    EngineDispatchThread(PicoDrv** pico_drivers, int** streams, 
                         ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue,
                         ThreadQueue<EngineJob>** engine_job_queues,
                         QuerySeqManager* query_seq_manager,
                         RefSeqManager* ref_seq_manager);

    // Initialization function (called by constructor)
    void Init(PicoDrv** pico_drivers, int** streams,
              ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue,
              ThreadQueue<EngineJob>** engine_job_queues,
              QuerySeqManager* query_seq_manager,
              RefSeqManager* ref_seq_manager);

    // Run the thread
    void Run();

    // Join the thread
    //   Can't be used for now, since the thread infinite loops and never terminates
    void Join();

  private:
    // FPGA engine dispatch thread arguments struct
    struct EngineDispatchThreadArgs {
      // Array of pointers to FPGA driver class objects
      PicoDrv** pico_drivers;
      
      // Engine stream handles, indexed by [FPGA][Stream]
      int** streams;
      
      // Pointer to shared queue of alignment jobs to be done
      ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue;

      // Pointers to shared queues of alignment jobs dispatched to FPGA engines
      ThreadQueue<EngineJob>** engine_job_queues;

      // Pointer to shared query sequence manager
      QuerySeqManager* query_seq_manager;

      // Pointer to shared reference sequence manager
      RefSeqManager* ref_seq_manager;
      
      ThreadQueue<DispatchJob>** dispatch_job_queues;
    };

    // Function for thread to run.
    //   Continuously retrieves alignment jobs from alignment job queue, splits the alignment
    //   jobs into engine sub-jobs, sends the engine sub-jobs to the FPGA engines, and
    //   records the scheduled engine jobs onto the engine job queues.
    static void* Dispatch(void* args);

    // Dispatch a group of alignment jobs to an engine
    /*static void DispatchJob(PicoDrv* pico_driver, int stream, int query_id, char* query_seq, 
                            int query_len, int num_ref_blocks, int first_ref_block, int threshold);*/
    /*static void DispatchJobs(PicoDrv* pico_driver, int stream, ThreadQueue<EngineJob>* engine_job_queue,
                             std::list<DispatchJob>* jobs, uint32_t* out_buf);*/


    // Actual pthread instance
    pthread_t thread_;

    // Thread arguments
    EngineDispatchThreadArgs args_;
    
    // Worker threads
    DispatchWorkerThread** dispatch_worker_threads_;
    ThreadQueue<DispatchJob>** dispatch_job_queues_;
    
    //static const int kMaxJobsDispatch = 64;
};

#endif // ENGINEDISPATCHTHREAD_H_
