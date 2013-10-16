//  File Name        : resultsreader_swthread_test.cpp
//  Description      : Results reader and Smith-Waterman aligner thread test
//
//  Revision History :
//      Albert Ng   Oct 14 2013     Initial Revision
//      Albert Ng   Oct 15 2013     Added overlap_offset

#include "swthread.h"
#include "resultsreaderthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "def.h"
#include "utils.h"
#include "picodrv_stub.h"
#include <iostream>
#include <cstring>

#define NUM_THREADS 1
#define NUM_QUERIES 5

int main(void) {
  PicoDrv* pico_drivers;
  int** streams;
  int* num_streams;
  ResultsReaderThread rrthread;
  SWThread swthreads[NUM_THREADS];
  QuerySeqManager query_seq_manager;
  RefSeqManager ref_seq_manager;
  ThreadQueue<HighScoreRegion> hsr_queue;
  ThreadQueue<EngineJob>** engine_job_queues;
  ThreadQueue<AlignmentResult> result_queue;
  char* query_seq[NUM_QUERIES];
  int query_ids[NUM_QUERIES];
  int query_lens[NUM_QUERIES];
  SwAffineGapParams params;

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

  // Set up scoring parameters
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        params.sub_mat[i][j] = 2;
      } else {
        params.sub_mat[i][j] = -2;
      }
    }
  }
  params.gap_open = -2;
  params.gap_extend = -1;

  // Set up pico drivers
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  }

  // Set up streams
  streams = new int*[NUM_FPGAS];
  num_streams = new int[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    num_streams[i] = NUM_ENGINES_PER_FPGA;
    streams[i] = new int[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      streams[i][j] = j;
    }
  }

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
        job.threshold = 10;
        engine_job_queues[i][j].Push(job);
      }
    }
  }

  // Set up Results Reader thread
  rrthread.Init(pico_drivers, streams, &hsr_queue, &query_seq_manager,
                engine_job_queues);

  // Set up Smith-Waterman worker threads
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Init(params, &hsr_queue, &result_queue, &ref_seq_manager, &query_seq_manager);
  }

  std::cout << "Starting threads" << std::endl;
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Run();
  }
  rrthread.Run();

  // Wait until all jobs are done
  bool done = false;
  while (done == false) {
    done = true;
    for (int i = 0; i < NUM_QUERIES; i++) {
      if (!query_seq_manager.QueryDone(query_ids[i])) {
        done = false;
      }
    }
  }

  std::cout<<"Printing alignment results\n"<<std::endl;

  // Print out alignment results
  while (result_queue.Size() != 0) {
    AlignmentResult res = result_queue.Pop();
    std::cout << "Query: " << res.hsr.query_id << "\tScore: " << res.score << std::endl;
    res.alignment->Print(std::cout);
    std::cout << std::endl;
  }

  std::cout<<"All Done!"<<std::endl;
  return 0;
}

  
