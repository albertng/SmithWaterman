//  File Name        : enginedispatch_resultsreader_swthread_test.cpp
//  Description      : Engine alignment job dispatch, result reader, and
//                     Smith-Waterman aligner thread test
//
//  Revision History :
//      Albert Ng   Oct 17 2013     Initial Revision

#include "swthread.h"
#include "resultsreaderthread.h"
#include "enginedispatchthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "def.h"
#include "picodrv_stub.h"
#include <iostream>
#include <cstring>

#define NUM_THREADS 1
#define NUM_QUERIES 5

int main(void) {
  PicoDrv* pico_drivers;
  int** streams;
  EngineDispatchThread edthread;
  ResultsReaderThread rrthread;
  SWThread swthreads[NUM_THREADS];
  QuerySeqManager query_seq_manager;
  RefSeqManager ref_seq_manager;
  ThreadQueue<AlignmentJob> alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues;
  ThreadQueue<HighScoreRegion> hsr_queue;
  ThreadQueue<AlignmentResult> result_queue;
  char* query_seq[NUM_QUERIES];
  int query_ids[NUM_QUERIES];
  int query_lens[NUM_QUERIES];
  SwAffineGapParams params;

  // Set up queries
  std::cout << "Setting up queries..." << std::endl;
  query_seq[0] = (char*) "GACCGAGACT";
  query_seq[1] = (char*) "AGCTAGTCNN";
  query_seq[2] = (char*) "TAACCTAGCTAGCT";
  query_seq[3] = (char*) "CCATGTATCG";
  query_seq[4] = (char*) "TATNCATGG";
  for (int i = 0; i < NUM_QUERIES; i++) {
    query_lens[i] = strlen(query_seq[i]);
    query_ids[i] = query_seq_manager.AddQuery(query_seq[i], query_lens[i]);
  }

  // Set up scoring parameters
  std::cout << "Setting up scoring parameters..." << std::endl;
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
  std::cout << "Setting up Pico drivers..." << std::endl;
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  }

  // Set up streams
  std::cout << "Setting up streams..." << std::endl;
  streams = new int*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    streams[i] = new int[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      streams[i][j] = j;
    }
  }

  // Set up alignment job queue
  std::cout << "Setting up alignment job queue..." << std::endl;
  for (int i = 0; i < NUM_QUERIES; i++) {
    AlignmentJob job;
    job.query_id = query_ids[i];
    job.query_len = query_lens[i];
    job.ref_id = 0;
    job.ref_offset = 0;
    job.ref_len = ref_seq_manager.GetRefLength(0);
    job.threshold = 10;
    alignment_job_queue.Push(job);
    std::cout<<"Job "<<i<<":\tQuery ID:"<<job.query_id<<"\tQuery Len:"<<job.query_len<<"\tRef ID: "<<job.ref_id<<"\tRef Offset: "<<job.ref_offset<<"\tRef Len: "<<job.ref_len<<"\tThreshold: "<<job.threshold<<std::endl;
  }
  
  // Set up engine job queues
  std::cout << "Setting up engine job queues..." << std::endl;
  engine_job_queues = new ThreadQueue<EngineJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    engine_job_queues[i] = new ThreadQueue<EngineJob>[NUM_ENGINES_PER_FPGA];
  }
  
  // Set up Engine Dispatch thread
  edthread.Init(pico_drivers, streams, &alignment_job_queue, engine_job_queues,
                &query_seq_manager, &ref_seq_manager);

  // Set up Results Reader thread
  rrthread.Init(pico_drivers, streams, &hsr_queue, &query_seq_manager,
                engine_job_queues);

  // Set up Smith-Waterman worker threads
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Init(params, &hsr_queue, &result_queue, &ref_seq_manager, &query_seq_manager);
  }
  
  // Start threads
  std::cout << "Starting threads" << std::endl;
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Run();
  }
  rrthread.Run();
  edthread.Run();
  

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
  
  // Print out alignment results
  while (result_queue.Size() != 0) {
    AlignmentResult res = result_queue.Pop();
    std::cout << "Query: " << res.hsr.query_id << "\tScore: " << res.score << std::endl;
    res.alignment->Print(std::cout);
    std::cout << std::endl;
    delete res.alignment;
  }

  std::cout<<"All Done!"<<std::endl;
  //while(true);
  return 0;
}

  
  
  
  
  
  
  
  
  
  
  
  
  
