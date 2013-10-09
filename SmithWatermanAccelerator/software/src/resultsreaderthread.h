//  File Name        : resultsreaderthread.h
//  Description      : FPGA Engine Results Reader Thread definitions
//
//  Revision History :
//      Albert Ng   Oct 08 2013     Initial Revision 

#ifndef RESULTSREADERTHREAD_H_
#define RESULTSREADERTHREAD_H_

#include <picodrv.h>
#include "threadqueue.h"
#include "sharedstructs.h"
#include <pthread.h>

// Thread that handles reading and processing the results from the
//   FPGA engines
class ResultsReaderThread {
  public:
    // Empty constructor
    ResultsReaderThread();

    // Complete constructor
    ResultsReaderThread(PicoDrv** pico_drivers, int num_drivers, int** streams, int* num_streams,
                        ThreadQueue<HighScoreRegion>* hsr_queue);

    // Initialization function (called by constructor)
    void Init(PicoDrv** pico_drivers, int num_drivers, int** streams, int* num_streams,
              ThreadQueue<HighScoreRegion>* hsr_queue);

    // Run the thread
    void Run();

    // Join the thread
    // Can't be used for now, since the thread infinite loops and never terminates
    void Join();

  private:
    // FPGA engine results reader thread arguments struct
    struct ResultsReaderThreadArgs {
      // Pointers to FPGA driver class objects
      PicoDrv**                     pico_drivers;

      // Number of FPGA drivers
      int                           num_drivers;
  
      // Engine stream handles, indexed by [FPGA][Stream]
      int**                         streams;

      // Number of streams in each FPGA
      int*                          num_streams;

      // Pointer to shared job queue of high scoring regions to be aligned
      ThreadQueue<HighScoreRegion>* hsr_queue;
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
};

#endif // RESULTSREADERTHREAD_H_
