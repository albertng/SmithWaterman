//  File Name        : resultsreaderthread_test.cpp
//  Description      : Results Reader thread test
//
//  Revision History :
//      Albert Ng   Oct 11 2013     Initial Revision

#include "resultsreaderthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "def.h"
#include "picodrv_stub.h"
#include <iostream>
#include <cstring>

#define NUM_FPGAS 2
#define NUM_STREAMS 2
#define NUM_QUERIES 5

int main(void) {
  PicoDrv* pico_drivers;
  //PicoDrv pico_drivers[NUM_FPGAS];
  ResultsReaderThread rrthread;
  int** streams;
  //int streams[NUM_FPGAS][NUM_STREAMS];
  int* num_streams;
  //int num_streams[NUM_FPGAS];  
  ThreadQueue<HighScoreRegion> hsr_queue;
  QuerySeqManager query_seq_manager;
  ThreadQueue<AlignmentJob>** alignment_job_queue;
  //ThreadQueue<AlignmentJob> alignment_job_queue[NUM_FPGAS][NUM_STREAMS];
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
    query_seq_manager.SetQueryNumEngines(query_ids[i], NUM_FPGAS * NUM_STREAMS);
  }

  std::cout << "Setting up Pico drivers." << std::endl;

  // Set up pico drivers
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_STREAMS);
  }

  std::cout << "Setting up streams." << std::endl;

  // Set up streams
  streams = new int*[NUM_FPGAS];
  num_streams = new int[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    num_streams[i] = NUM_STREAMS;
    streams[i] = new int[NUM_STREAMS];
    for (int j = 0; j < NUM_STREAMS; j++) {
      streams[i][j] = j;
    }
  }

  std::cout << "Setting up alignment job queue." << std::endl;

  // Set up alignment job queue
  alignment_job_queue = new ThreadQueue<AlignmentJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    alignment_job_queue[i] = new ThreadQueue<AlignmentJob>[NUM_STREAMS];
    for (int j = 0; j < NUM_STREAMS; j++) {
      for (int k = 0; k < NUM_QUERIES; k++) {
        AlignmentJob job;
        job.query_id = query_ids[k];
        job.query_len = query_lens[k];
        job.ref_id = 0;
        job.ref_offset = k;
        job.ref_len = 256 - 2*k;
        job.threshold = i*NUM_STREAMS + j;
        alignment_job_queue[i][j].Push(job);
      }
    }
  }

  std::cout << "Running threads." << std::endl;

  rrthread.Init(pico_drivers, NUM_FPGAS, streams, num_streams, &hsr_queue, &query_seq_manager,
                alignment_job_queue);

  rrthread.Run();

  std::cout << "Grabbing results." << std::endl;
  sleep(1);
//  for (int i = 0; i < 18 * NUM_FPGAS * NUM_STREAMS; i++) {
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
