//  File Name        : resultsreaderthread_test.cpp
//  Description      : Results Reader thread test
//
//  Revision History :
//      Albert Ng   Oct 11 2013     Initial Revision
//      Albert Ng   Oct 15 2013     Added overlap_offset
//      Albert Ng   Oct 16 2013     Finished initial revision, untested

#include "resultsreaderthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "def.h"
#include "picodrv_stub.h"
#include <iostream>
#include <cstring>

#define NUM_QUERIES 5

int main(void) {
  PicoDrv* pico_drivers;
  ResultsReaderThread rrthread;
  int** streams;
  ThreadQueue<HighScoreRegion> hsr_queue;
  QuerySeqManager query_seq_manager;
  ThreadQueue<EngineJob>** engine_job_queues;
  char* query_seq[NUM_QUERIES];
  int query_ids[NUM_QUERIES];
  int query_lens[NUM_QUERIES];

  std::cout << "Setting up queries." << std::endl;

  // Set up queries
  query_seq[0] = (char*) "AGCTAGTCNN";
  query_seq[1] = (char*) "GACCGAGACT";
  query_seq[2] = (char*) "TAACCTAGCTAGCT";
  query_seq[3] = (char*) "CCATGTATCG";
  query_seq[4] = (char*) "TATNCATGG";
  for (int i = 0; i < NUM_QUERIES; i++) {
    query_lens[i] = strlen(query_seq[i]);
    query_ids[i] = query_seq_manager.AddQuery(query_seq[i], query_lens[i]);
    query_seq_manager.SetQueryNumEngines(query_ids[i], NUM_FPGAS * NUM_ENGINES_PER_FPGA);
  }

  std::cout << "Setting up Pico drivers." << std::endl;

  // Set up pico drivers
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  }

  std::cout << "Setting up streams." << std::endl;

  // Set up streams
  streams = new int*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    streams[i] = new int[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      streams[i][j] = j;
    }
  }

  std::cout << "Setting up engine job queues." << std::endl;

  // Set up engine job queues
  engine_job_queues = new ThreadQueue<AlignmentJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    engine_job_queues[i] = new ThreadQueue<AlignmentJob>[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      for (int k = 0; k < NUM_QUERIES; k++) {
        EngineJob job;
        job.query_id = query_ids[k];
        job.query_len = query_lens[k];
        job.ref_id = 0;
        job.ref_offset = k;
        job.ref_len = 256 - 2*k;
        job.overlap_offset = job.ref_offset + job.ref_len;
        job.threshold = i*NUM_ENGINES_PER_FPGA + j;
        engine_job_queues[i][j].Push(job);
      }
    }
  }

  std::cout << "Running threads." << std::endl;

  rrthread.Init(pico_drivers, streams, &hsr_queue, &query_seq_manager, engine_job_queues);

  rrthread.Run();

  std::cout << "Grabbing results." << std::endl;
  sleep(1);
//  for (int i = 0; i < 18 * NUM_FPGAS * NUM_ENGINES_PER_FPGA; i++) {
  while(true){
    HighScoreRegion hsr = hsr_queue.Pop();
    std::cout << "Query ID: " << hsr.query_id 
              << "\tRef ID: " << hsr.ref_id 
              << "\tLength: " << hsr.len 
              << "\tOffset: " << hsr.offset
              << "\tThreshold: " << hsr.threshold 
              << std::endl;
  }
  std::cout << "All Done." << std::endl;
  return 0;
}
