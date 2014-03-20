//  File Name        : resultsreaderthread.cpp
//  Description      : FPGA Engine Results Reader Thread
//                     Full description in resultsreaderthread.h
//
//  Revision History :
//      Albert Ng   Oct 08 2013     Initial Revision 
//      Albert Ng   Oct 10 2013     Finished initial implementation, untested
//      Albert Ng   Oct 14 2013     Tested with swthread
//      Albert Ng   Oct 15 2013     Replaced num_drivers and num_streams with
//                                    NUM_FPGAS and NUM_ENGINES_PER_FPGA
//      Albert Ng   Oct 17 2013     Added NOT_IN_HSR state
//      Albert Ng   Oct 18 2013     Fixed engine job queue empty bug
//      Albert Ng   Oct 22 2013     Added SwAffineGapParams to HighScoreRegion
//      Albert Ng   Nov 19 2013     Added chromosomes

#include <pthread.h>
#include <stdint.h>
#include <assert.h>
#include "def.h"
#include "resultsreaderthread.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "threadqueue.h"
#include "scoring.h"
#include "time.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

ResultsReaderThread::ResultsReaderThread() {
}

ResultsReaderThread::ResultsReaderThread(PicoDrv** pico_drivers, int** streams,
                                         ThreadQueue<HighScoreRegion>* hsr_queue,
                                         QuerySeqManager* query_seq_manager,
                                         RefSeqManager* ref_seq_manager,
                                         ThreadQueue<EngineJob>** engine_job_queues) {
  Init(pico_drivers, streams, hsr_queue, query_seq_manager, ref_seq_manager,
       engine_job_queues);
}

void ResultsReaderThread::Init(PicoDrv** pico_drivers, int** streams,
                               ThreadQueue<HighScoreRegion>* hsr_queue,
                               QuerySeqManager* query_seq_manager,
                               RefSeqManager* ref_seq_manager,
                               ThreadQueue<EngineJob>** engine_job_queues) {
  args_.pico_drivers = pico_drivers;
  args_.streams = streams;
  args_.hsr_queue = hsr_queue;
  args_.query_seq_manager = query_seq_manager;
  args_.ref_seq_manager = ref_seq_manager;
  args_.engine_job_queues = engine_job_queues;
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
  int** streams = ((ResultsReaderThreadArgs*)args)->streams;
  ThreadQueue<HighScoreRegion>* hsr_queue = ((ResultsReaderThreadArgs*)args)->hsr_queue;
  QuerySeqManager* query_seq_manager = ((ResultsReaderThreadArgs*)args)->query_seq_manager;
  RefSeqManager* ref_seq_manager = ((ResultsReaderThreadArgs*)args)->ref_seq_manager;
  ThreadQueue<EngineJob>** engine_job_queues = ((ResultsReaderThreadArgs*)args)->engine_job_queues;

  // Set up memory buffers
  uint32_t*** read_mem_buf = new uint32_t**[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    read_mem_buf[i] = new uint32_t*[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      read_mem_buf[i][j] = new uint32_t[4096];
      for (int k = 0; k < 4096; k++) {
        read_mem_buf[i][j][k] = 0;
      }
    }
  }

  // Initialize FSM states and values
  HSRParserState* states[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    states[i] = new HSRParserState[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      states[i][j] = INIT;
    }
  }
  CoalescedHighScoreBlock* chsbs[NUM_FPGAS];
  EngineJob* jobs[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    chsbs[i] = new CoalescedHighScoreBlock[NUM_ENGINES_PER_FPGA];
    jobs[i] = new EngineJob[NUM_ENGINES_PER_FPGA];
  }

  int num_HSRs = 0;

  while(true) {
    for (int i = 0; i < NUM_FPGAS; i++) {
      for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
        int num_bytes_available = pico_drivers[i]->GetBytesAvailable(streams[i][j], true);
        //std::cout<<num_bytes_available<<" ";
        if (num_bytes_available >= 16) {
          
          // Read full 128-bit packets (check might not be necessary)
          int num_bytes_to_read = num_bytes_available > 4096 ? 4096 : (num_bytes_available/16)*16;
          pico_drivers[i]->ReadStream(streams[i][j], read_mem_buf[i][j], num_bytes_to_read);

          for (int k = 0; k < num_bytes_to_read / 16; k++) {
            //std::cout<<"Read stream:\t"<<i<<" "<<j<<"\tHSB:"<< read_mem_buf[i][j][k] << "\tQuery ID:" << read_mem_buf[i][j][k+1] << std::endl;
            uint32_t high_score_block = read_mem_buf[i][j][k*4];
            uint32_t query_id = read_mem_buf[i][j][k*4 + 1];
            
            // High scoring ref seq block parser FSM
            switch(states[i][j]) {
              case INIT:
                  jobs[i][j] = engine_job_queues[i][j].Pop();
                  
                  //std::cout<<"Engine Job:\tQuery ID:"<<jobs[i][j].query_id<<" Ref ID: "<<jobs[i][j].ref_id<<" Chr ID: " <<jobs[i][j].chr_id<<" Ref Offset: "<<jobs[i][j].ref_offset<<" Ref Len: "<<jobs[i][j].ref_len<<" Overlap Offset: "<<jobs[i][j].overlap_offset<<" Threshold: "<<jobs[i][j].threshold<<std::endl;
                  if (high_score_block == END_OF_ENGINE_ALIGNMENT) {
                    query_seq_manager->DecHighScoreRegionCount(jobs[i][j].query_id);
                    states[i][j] = INIT;
                  } else if (IsValidBlock(jobs[i][j], high_score_block)) {
                    chsbs[i][j] = StartCHSB(high_score_block);
                    states[i][j] = IN_HSR;
                  } else {
                    std::cerr << "Invalid high scoring block received! " << jobs[i][j].ref_offset <<" " <<jobs[i][j].ref_len<<" " <<high_score_block << std::endl;
                    assert(false);
                  }
                break;

              case IN_HSR:
                if (high_score_block == END_OF_ENGINE_ALIGNMENT) {
                  StoreHSR(chsbs[i][j], jobs[i][j], hsr_queue, query_seq_manager, ref_seq_manager);
                  num_HSRs++;
                  if (num_HSRs % 10000 == 0) {
                    std::cout << "HSRS: " << num_HSRs << std::endl;
                  }
                  query_seq_manager->DecHighScoreRegionCount(jobs[i][j].query_id);
                  //std::cout<<"Query " <<jobs[i][j].query_id<<" Decrement HSR count"<<std::endl;
                  states[i][j] = INIT;
                } else if (IsValidBlock(jobs[i][j], high_score_block) && IsAdjacentBlock(high_score_block, chsbs[i][j])) {
                  chsbs[i][j] = ExtendCHSB(chsbs[i][j]);
                  states[i][j] = IN_HSR;
                } else if (IsValidBlock(jobs[i][j], high_score_block)) {
                  StoreHSR(chsbs[i][j], jobs[i][j], hsr_queue, query_seq_manager, ref_seq_manager);
                  num_HSRs++;
                  if (num_HSRs % 10000 == 0) {
                    std::cout << "HSRS: " << num_HSRs << std::endl;
                  }
                  chsbs[i][j] = StartCHSB(high_score_block);
                  states[i][j] = IN_HSR;
                } else {
                  StoreHSR(chsbs[i][j], jobs[i][j], hsr_queue, query_seq_manager, ref_seq_manager);
                  num_HSRs++;
                  if (num_HSRs % 10000 == 0) {
                    std::cout << "HSRS: " << num_HSRs << std::endl;
                  }
                  states[i][j] = INIT;
                }
                break;
              
              case NOT_IN_HSR:
                if (high_score_block == END_OF_ENGINE_ALIGNMENT) {
                  query_seq_manager->DecHighScoreRegionCount(jobs[i][j].query_id);
                  states[i][j] = INIT;
                } else if (IsValidBlock(jobs[i][j], high_score_block)) {
                  chsbs[i][j] = StartCHSB(high_score_block);
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

// Stores the high scoring region onto the high score region queue to pass to Smith-Waterman
//   threads for alignment. Modifies the HSR length and offset to include up to 2 query
//   length extension at the front (bounded by the job boundaries).
void ResultsReaderThread::StoreHSR(CoalescedHighScoreBlock chsb, EngineJob job, ThreadQueue<HighScoreRegion>* hsr_queue, 
                                   QuerySeqManager* query_seq_manager, RefSeqManager* ref_seq_manager) {
  std::vector<int> chr_ids;
  std::vector<long long int> chr_offsets;
  std::vector<long long int> chr_start_coords;
  std::vector<long long int> chr_end_coords;

  int query_len;
  query_seq_manager->GetQuerySeq(job.query_id, &query_len);

  long long int offset = (job.ref_offset/REF_BLOCK_LEN)*REF_BLOCK_LEN + chsb.block_offset * REF_BLOCK_LEN - 2*query_len;
  long long int len = chsb.num_blocks * REF_BLOCK_LEN + 2*query_len;
  
  // Left boundary check
  if (offset < job.ref_offset) {
    len -= (job.ref_offset - offset);
    offset = job.ref_offset;
  }

  // Right boundary check
  if ((offset + len) > (job.ref_offset + job.ref_len)) {
    len -= ((offset + len) - (job.ref_offset + job.ref_len));
  } 

  if (job.chr_id == -1) {
    ref_seq_manager->GetChrRegions(job.ref_id, offset, offset + len, &chr_ids, &chr_offsets, &chr_start_coords, &chr_end_coords);
    
    for (int i = 0; i < chr_ids.size(); i++) {
      HighScoreRegion hsr;
      hsr.query_id       = job.query_id;
      hsr.ref_id         = job.ref_id;
      hsr.chr_id         = chr_ids[i];
      hsr.threshold      = job.threshold;
      hsr.params         = job.params;
      hsr.offset         = chr_start_coords[i];
      hsr.len            = chr_end_coords[i] - chr_start_coords[i];
      hsr.overlap_offset = job.overlap_offset - chr_offsets[i];
      hsr.pos_strand     = job.pos_strand;
      
      //std::cout << "HSR: " << hsr.chr_id << " " << hsr.offset << " " << hsr.len << std::endl;
      
      hsr_queue->Push(hsr);
      query_seq_manager->IncHighScoreRegionCount(hsr.query_id);
    }
  } else {
    HighScoreRegion hsr;
    hsr.query_id       = job.query_id;
    hsr.ref_id         = job.ref_id;
    hsr.chr_id         = job.chr_id;
    hsr.threshold      = job.threshold;
    hsr.params         = job.params;
    hsr.offset         = offset;
    hsr.len            = len;
    hsr.overlap_offset = job.overlap_offset;      
    hsr.pos_strand     = job.pos_strand; 
    
    hsr_queue->Push(hsr);
    query_seq_manager->IncHighScoreRegionCount(hsr.query_id);
  }    
}

// Begins a new coalesced high scoring block
ResultsReaderThread::CoalescedHighScoreBlock ResultsReaderThread::StartCHSB(uint32_t block_offset) {
  CoalescedHighScoreBlock chsb;
  chsb.block_offset = block_offset;
  chsb.num_blocks = 1;
  return chsb;
}

// Coalesces a high scoring block with the next block
ResultsReaderThread::CoalescedHighScoreBlock ResultsReaderThread::ExtendCHSB(CoalescedHighScoreBlock chsb) {
  chsb.num_blocks++;
  return chsb;
}

// Checks if a high scoring block index is adjacent to the given block, indicating
//   that they should be coalesced.
bool ResultsReaderThread::IsAdjacentBlock(uint32_t high_score_block, CoalescedHighScoreBlock chsb) {
  if (chsb.block_offset + chsb.num_blocks == high_score_block) {
    return true;
  }
  return false;
}

// Checks if a high score block index is within the job's boundaries.
// This is necessary for the edge case where the number of blocks spanned by the ref seq is less than 
// the minimum job size allowable on an engine. For example, if the ref seq length is 128 bp, the ref 
// seq offset is 0, and the min job size is 2 blocks (256 bp), then the second block should not be 
// considered for the alignment.
bool ResultsReaderThread::IsValidBlock(EngineJob job, int high_score_block) {
  return (job.ref_offset + job.ref_len) >= (job.ref_offset / REF_BLOCK_LEN + high_score_block) * REF_BLOCK_LEN;
}



