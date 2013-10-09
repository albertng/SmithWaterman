//  File Name        : resultsreaderthread.cpp
//  Description      : FPGA Engine Results Reader Thread
//
//  Revision History :
//      Albert Ng   Oct 08 2013     Initial Revision 

#include <picodrv.h>
#include "resultsreaderthread.h"
#include "threadqueue.h"
#include "sharedstructs.h"
#include <pthread.h>

ResultsReaderThread::ResultsReaderThread() {
}

ResultsReaderThread::ResultsReaderThread(PicoDrv** pico_drivers, int num_drivers, int** streams,
                                         int* num_streams, ThreadQueue<HighScoreRegion>* hsr_queue) {
  Init(pico_drivers, num_drivers, streams, num_streams, hsr_queue);
}

void ResultsReaderThread::Init(PicoDrv** pico_drivers, int num_drivers, int** streams,
                               int* num_streams, ThreadQueue<HighScoreRegion>* hsr_queue) {
  args.pico_drivers = pico_drivers;
  args.num_drivers = num_drivers;
  args.streams = streams;
  args.num_streams = num_streams;
  args.hsr_queue = hsr_queue;
}

void ResultsReaderThread::Run() {
  pthread_create(&thread_, NULL, &ResultsReaderThread::ReadResults, (void*) (&args_));
}

void ResultsReaderThread::Join() {
  pthread_join(thread_, NULL);
}

void* ResultsReaderThread::ReadResults(void* args) {
  // Get result reader arguments
  PicoDrv** pico_drivers = ((ResultsReaderThreadArgs*)args)->pico_drivers;
  int num_drivers = ((ResultsReaderThreadArgs*)args)->num_drivers;
  int** streams = ((ResultsReaderThreadArgs*)args)->streams;
  int* num_streams = ((ResultsReaderThreadArgs*)args)->num_streams;
  uint32_t* read_buf = ((ResultsReaderThreadArgs*)args)->read_buf;
  ThreadQueue<HighScoreRegion>* hsr_queue = ((ResultsReaderThreadArgs*)args)->hsr_queue;

  // Set up memory buffers
  uint32_t*** read_buf = new uint32_t**[num_drivers];
  for (int i = 0; i < num_drivers; i++) {
    read_buf[i] = new uint32_t*[num_streams[i]];
    for (int j = 0; j < num_streams[i]; j++) {
      read_buf[i][j] = new uint32_t[READ_BUF_SIZE];
      for (int k = 0; k < READ_BUF_SIZE; k++) {
        read_buf[i][j][k] = 0;
      }
    }
  }

  while(true) {
    for (int i = 0; i < num_drivers; i++) {
      for (int j = 0; j < num_streams[i]; j++) {
        int num_bytes_available = pico_drivers[i]->GetBytesAvailable(streams[i][j], true);
        if (num_bytes_available >= 16) {
          // Read full 128-bit packets (check might not be necessary)
          int num_bytes_to_read = num_bytes_available > 4096 ? 4096 : (num_bytes_available/16)*16;
          pico_drivers[i]->ReadStream(streams[i][j], read_buf[i][j], num_bytes_to_read);

          for (int k = 0; k < num_bytes_to_read / 16; k++) {
          //TODO:
          //  HighScoreRegion state machine
          //  Grab query sequence info (query length in particular)
          //  Coalesce consecutive ref seq blocks
          //  Report high scoring ref seq blocks, and prepend blocks up to query length
            
