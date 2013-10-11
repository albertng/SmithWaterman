//  File Name        : resultsreaderthread.cpp
//  Description      : FPGA Engine Results Reader Thread
//                     Full description in resultsreaderthread.h
//
//  Revision History :
//      Albert Ng   Oct 08 2013     Initial Revision 
//      Albert Ng   Oct 10 2013     Finished initial implementation, untested

#include <picodrv.h>
#include "resultsreaderthread.h"
#include "threadqueue.h"
#include "def.h"
#include <pthread.h>
#include <stdint.h>

ResultsReaderThread::ResultsReaderThread() {
}

ResultsReaderThread::ResultsReaderThread(PicoDrv** pico_drivers, int num_drivers, int** streams,
                                         int* num_streams, ThreadQueue<HighScoreRegion>* hsr_queue,
                                         QuerySeqManager* query_seq_manager,
                                         ThreadQueue<AlignmentJob>** alignment_job_queue) {
  Init(pico_drivers, num_drivers, streams, num_streams, hsr_queue, query_seq_manager,
       alignment_job_queue);
}

void ResultsReaderThread::Init(PicoDrv** pico_drivers, int num_drivers, int** streams,
                               int* num_streams, ThreadQueue<HighScoreRegion>* hsr_queue,
                               QuerySeqManager* query_seq_manager,
                               ThreadQueue<AlignmentJob>>** alignment_job_queue) {
  args_.pico_drivers = pico_drivers;
  args_.num_drivers = num_drivers;
  args_.streams = streams;
  args_.num_streams = num_streams;
  args_.hsr_queue = hsr_queue;
  args_.query_seq_manager = query_seq_manager;
  args_.alignment_job_queue = alignment_job_queue;
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
  ThreadQueue<HighScoreRegion>* hsr_queue = ((ResultsReaderThreadArgs*)args)->hsr_queue;
  QuerySeqManager* query_seq_manager = ((ResultsReaderThreadArgs*)args)->query_seq_manager;
  ThreadQueue<AlignmentJob>** alignment_job_queue = ((ResultsReaderThreadArgs*)args)->alignment_job_queue;

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

  // Initialize FSM states and values
  HSRParserState states[num_drivers][num_streams];
  for (int i = 0; i < num_drivers; i++) {
    for (int j = 0; j < num_streams; j++) {
      states[i][j] = INIT;
    }
  }
  HighScoreRegion hsrs[num_drivers][num_streams];
  AlignmentJob jobs[num_drivers][num_streams];

  while(true) {
    for (int i = 0; i < num_drivers; i++) {
      for (int j = 0; j < num_streams[i]; j++) {
        int num_bytes_available = pico_drivers[i]->GetBytesAvailable(streams[i][j], true);
        if (num_bytes_available >= 16) {
          // Read full 128-bit packets (check might not be necessary)
          int num_bytes_to_read = num_bytes_available > 4096 ? 4096 : (num_bytes_available/16)*16;
          pico_drivers[i]->ReadStream(streams[i][j], read_buf[i][j], num_bytes_to_read);

          for (int k = 0; k < num_bytes_to_read / 16; k++) {
            uint32_t high_score_block = read_buf[i][j][k*4];
            uint32_t query_id = read_buf[i][j][k*4 + 1];

            // High scoring ref seq block parser FSM
            switch(states[i][j]) {
              case INIT:
                jobs[i][j] = alignment_job_queue[i][j].Pop();
                if (high_score_block == END_OF_ALIGNMENT) {
                  StoreTerminatingHSR(jobs[i][j]);
                  states[i][j] = INIT;
                } else {
                  hsrs[i][j] = NewHSR(jobs[i][j], high_score_block * REF_BLOCK_LEN, REF_BLOCK_LEN);
                  states[i][j] = IN_HSR;
                }
                break;

              case IN_HSR:
                if (high_score_block == END_OF_ALIGNMENT) {
                  StoreHSR(hsrs[i][j]);
                  StoreTerminatingHSR(jobs[i][j]);
                  states[i][j] = INIT;
                } else if (IsAdjacentBlock(high_score_block, hsrs[i][j])) {
                  hsrs[i][j] = ExtendHSR(hsrs[i][j]);
                  states[i][j] = IN_HSR;
                } else {
                  StoreHSR(hsrs[i][j]);
                  hsrs[i][j] = NewHSR(jobs[i][j], high_score_block * REF_BLOCK_LEN, REF_BLOCK_LEN);
                  states[i][j] = IN_HSR;
                }
                break;

              default: // Shouldn't get here
                break;
            }
          }
        }
      }
    }
  }
}

// Stores a terminating packet onto the high score region queue 
// Also decrements the high scoring region count (managed by query_seq_manager) for the query
void ResultsReaderThread::StoreTerminatingHSR(AlignmentJob job, ThreadQueue<HighScoreRegion>* hsr_queue) {
  HighScoreRegion hsr;
  hsr.query_id = job.query_id;
  hsr.ref_id = job.ref_id;
  hsr.ref_len = 0;
  hsr.ref_offset = END_OF_ALIGNMENT;
  hsr.threshold = job.threshold;
  StoreHSR(hsr, hsr_queue);
  
  query_seq_manager->DecHighScoreRegionCount(job.query_id);
}

// Stores the high scoring region onto the high score region queue to pass to Smith-Waterman
//   threads for alignment
void ResultsReaderThread::StoreHSR(HighScoreRegion hsr, ThreadQueue<HighScoreRegion>* hsr_queue) {
  hsr_queue->Push(hsr);
}

// Begins a new high scoring region with an extra 2 query lengths extension at the front
HighScoreRegion ResultsReaderThread::NewHSR(AlignmentJob job, uint32_t hsr_offset, uint32_t hsr_len) {
  HighScoreRegion hsr;
  hsr.query_id = job.query_id;
  hsr.ref_id = job.ref_id;
  hsr.ref_len = hsr_len + 2*job.query_len;
  hsr.ref_offset = (job.ref_offset + hsr_offset < 2*job.query_len) ? 0 : job.ref_offset + hsr_offset - 2*job.query_len;
  hsr.threshold = job.threshold;
  return hsr;
}

// Coalesces an high scoring region with the next block
HighScoreRegion ResultsReaderThread::ExtendHSR(HighScoreRegion hsr) {
  hsr.ref_len += REF_BLOCK_LEN;
  return hsr;
}

// Checks if a high scoring block index is adjacent to the given high scoring region, indicating
//   that they should be coalesced.
bool ResultsReaderThread::IsAdjacentBlock(uint32_t high_score_block, HighScoreRegion hsr) {
  if (hsr.ref_offset + hsr.ref_len == high_score_block * REF_BLOCK_LEN) {
    return true;
  }
  return false;
}
