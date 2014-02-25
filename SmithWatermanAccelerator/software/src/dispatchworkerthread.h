//  File Name        : dispatchworkerthread.h
//  Description      : FPGA Engine Alignment Dispatch Worker Thread definitions
//
//  Revision History :
//      Albert Ng   Feb 11 2014     Initial Revision
//      Albert Ng   Feb 23 2014     Added WriteBufferToStream()

#ifndef DISPATCHWORKERTHREAD_H_
#define DISPATCHWORKERTHREAD_H_

#include <pthread.h>
#include "def.h"
#include "threadqueue.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

class DispatchWorkerThread {
  public:
    // Empty constructor
    DispatchWorkerThread();
    
    // Complete constructor
    DispatchWorkerThread(PicoDrv* pico_driver, int stream, 
                         ThreadQueue<DispatchJob>* dispatch_job_queue);
                         
    // Initialization function (called by constructor)
    void Init(PicoDrv* pico_driver, int stream, 
              ThreadQueue<DispatchJob>* dispatch_job_queue);  

    // Run the thread
    void Run();

    // Join the thread
    //   Can't be used for now, since the thread infinite loops and never terminates
    void Join();
  
  private:
    // FPGA engine dispatch thread arguments struct
    struct DispatchWorkerThreadArgs {
      // Pointer to FPGA driver
      PicoDrv* pico_driver;
      
      // Engine stream handle
      int stream;
      
      // Pointer to shared queue of jobs to be dispatched to this engine
      ThreadQueue<DispatchJob>* dispatch_job_queue;
    };
    
    // Function for thread to run.
    //   Continuously retrieves alignment jobs from alignment job queue, splits the alignment
    //   jobs into engine sub-jobs, sends the engine sub-jobs to the FPGA engines, and
    //   records the scheduled engine jobs onto the engine job queues.
    static void* Dispatch(void* args);
    
    // Writes the given buffer to the stream
    static void WriteBufferToStream(PicoDrv* pico_driver, int stream, char* buffer, long long int num_bytes);
    
    // Actual pthread instance
    pthread_t thread_;

    // Thread arguments
    DispatchWorkerThreadArgs args_;
    
    // Buffer length (in 4B quantities)
    static const int DISPATCH_BUF_LEN = 4*1024*1024; // 16 MB 
};

#endif // DISPATCHWORKERTHREAD_H_
