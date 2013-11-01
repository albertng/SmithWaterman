//  File Name        : picodrv.h
//  Description      : Simulated Pico FPGA driver definitions
//
//  Revision History :
//      Albert Ng   Oct 29 2013     Initial Revision

#ifndef PICODRV_H_
#define PICODRV_H_

#include <pthread.h>
#include <stdint.h>
#include "threadqueue.h"
#include "def.h"
#include "scoring.h"

#define PICO_DDR3_0 0

class PicoDrv {
  public:
    PicoDrv();
    ~PicoDrv();
    
    // Pico API
    int WriteDeviceAbsolute(int addr, const void* buf, int size);
    int CreateStream(int streamNum);
    int ReadStream(int streamHandle, void* buf, int size);
    int WriteStream(int streamHandle, const void* buf, int size);
    int GetBytesAvailable(int streamHandle, bool isRead=true);
    int WriteRam(uint64_t addr, const void* buf, int size, int memID=PICO_DDR3_0);
    
    // Not part of API (used by my versions of non-class pico functions)
    void Init(int num_streams);
  
  private:
    // Useful class structs
    struct QueryJob {
      int num_ref_blocks;
      int first_ref_block;
      int query_id;
      int query_len;
      int threshold;
      char* query_seq;
      int stream_num;
    };
    
    struct HighScoreBlock {
      int high_score_block;
      int query_id;
    };
    
    struct PicoDrvThreadArgs {
      ThreadQueue<QueryJob>* query_job_queue;
      ThreadQueue<HighScoreBlock> (*high_score_block_queues)[NUM_ENGINES_PER_FPGA];
      char* dram;
      SwAffineGapParams* params;
    };
    
    // Function for engine thread to run.
    // Continuously retrieves engine jobs from query job queue, performs
    //   the alignment for the job, and enqueues high scoring block results
    //   onto the appropriate high score block queue.
    static void* RunEngines(void* args);
    
    // Smith-Waterman Engine thread
    pthread_t thread_;
    
    // Thread arguments
    PicoDrvThreadArgs args_;
    
    ThreadQueue<QueryJob> query_job_queue_;
    
    ThreadQueue<HighScoreBlock> high_score_block_queues_[NUM_ENGINES_PER_FPGA]; 
    
    char* dram_;
    
    SwAffineGapParams params_;
    
    static const int DRAM_SIZE = 1048576;
};

int RunBitFile(const char *bitFilePath, PicoDrv **drvpp);

char* PicoErrors_FullError(int err, char* ibuf, size_t size);

#endif //PICODRV_H_
