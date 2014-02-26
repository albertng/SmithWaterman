//  File Name        : dispatchworkerthread.cpp
//  Description      : FPGA Engine Alignment Dispatch Worker Thread definitions
//
//  Revision History :
//      Albert Ng   Feb 11 2014     Initial Revision

#include <pthread.h>
#include <assert.h>
#include "dispatchworkerthread.h"
#include "def.h"
#include "threadqueue.h"
#include "utils.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

DispatchWorkerThread::DispatchWorkerThread() {
}

DispatchWorkerThread::DispatchWorkerThread(PicoDrv* pico_driver, int stream, 
                                           ThreadQueue<DispatchJob>* dispatch_job_queue) {
  Init(pico_driver, stream, dispatch_job_queue);
}

void DispatchWorkerThread::Init(PicoDrv* pico_driver, int stream, 
                                ThreadQueue<DispatchJob>* dispatch_job_queue) {
  args_.pico_driver = pico_driver;
  args_.stream = stream;
  args_.dispatch_job_queue = dispatch_job_queue;
}

void DispatchWorkerThread::Run() {
  pthread_create(&thread_, NULL, &DispatchWorkerThread::Dispatch, (void*) (&args_));
}

void DispatchWorkerThread::Join() {
  pthread_join(thread_, NULL);
}

void* DispatchWorkerThread::Dispatch(void* args) {
  // Get thread arguments
  PicoDrv* pico_driver = ((DispatchWorkerThreadArgs*)args)->pico_driver;
  int stream = ((DispatchWorkerThreadArgs*)args)->stream;
  ThreadQueue<DispatchJob>* dispatch_job_queue = ((DispatchWorkerThreadArgs*)args)->dispatch_job_queue;
  
  uint32_t* dispatch_buf = new uint32_t[DISPATCH_BUF_LEN];
  int cur_buf_size = 0;
  while(true) {
    DispatchJob job = dispatch_job_queue->Pop();
    
    // Compute buffer space needed for this job
    int job_buf_size = 4 * (1 + job.query_len / QUERY_BLOCK_LEN);
    if (job.query_len % QUERY_BLOCK_LEN != 0) {
      job_buf_size += 4;
    }
    
    // Dispatch and empty the buffer before adding this job
    //   if it will overflow
    if (cur_buf_size + job_buf_size > DISPATCH_BUF_LEN) {
      assert(cur_buf_size > 0);
      WriteBufferToStream(pico_driver, stream, (char*) dispatch_buf, cur_buf_size * 4);
      //pico_driver->WriteStream(stream, dispatch_buf, cur_buf_size * 4);
      cur_buf_size = 0;
    }
    
    // Add job to the buffer
    dispatch_buf[cur_buf_size + 0] = (uint32_t) job.num_ref_blocks;
    dispatch_buf[cur_buf_size + 1] = (uint32_t) job.first_ref_block;
    dispatch_buf[cur_buf_size + 2] = (uint32_t) ((job.query_id << 16) + job.query_len);
    dispatch_buf[cur_buf_size + 3] = (uint32_t) job.threshold;
    for (int i = 0; i < job.query_len; i++) {
      NtInt nt = NtChar2Int(job.query_seq[i]);
      if (job.query_seq[i] == 'N' || job.query_seq[i] == 'n') {
        nt = rand() % 4;
      }
      if (i % 16 == 0) {
        dispatch_buf[cur_buf_size + 4+i/16] = nt;
      } else {
        dispatch_buf[cur_buf_size + 4+i/16] += (nt << (2 * (i % 16)));
      }
    }
    cur_buf_size += job_buf_size;
    
    // Dispatch and empty the buffer if the job queue is now empty
    if (dispatch_job_queue->Empty()) {
      assert(cur_buf_size > 0);
      WriteBufferToStream(pico_driver, stream, (char*) dispatch_buf, cur_buf_size * 4);
      //pico_driver->WriteStream(stream, dispatch_buf, cur_buf_size * 4);
      cur_buf_size = 0;
    }
  }
}

void DispatchWorkerThread::WriteBufferToStream(PicoDrv* pico_driver, int stream, char* buffer, long long int num_bytes) {
  long long int cur_index = 0;
  
  /*while (num_bytes > 0) {
    int num_bytes_to_stream = pico_driver->GetBytesAvailable(stream, false);
    num_bytes_to_stream = num_bytes_to_stream > num_bytes ? num_bytes : num_bytes_to_stream;
    pico_driver->WriteStream(stream, &(buffer[cur_index]), num_bytes_to_stream);
    cur_index += num_bytes_to_stream;
    num_bytes -= num_bytes_to_stream;
  }*/
  pico_driver->WriteStream(stream, &(buffer[cur_index]), num_bytes);
}

