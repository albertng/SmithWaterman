//  File Name        : enginedispatchthread_test.cpp
//  Description      : Engine alignment job dispatch thread test
//
//  Revision History :
//      Albert Ng   Oct 16 2013     Initial Revision

#include "enginedispatchthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "queryseqmanager.h"
#include "def.h"
#include "picodrv_stub.h"
#include <iostream>
#include <cstring>

#define NUM_QUERIES 5

int main (void) {
  PicoDrv* pico_drivers;
  EngineDispatchThread edthread;
  int** streams;
  ThreadQueue<AlignmentJob> alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues;
  RefSeqManager ref_seq_manager;
  QuerySeqManager query_seq_manager;
  char* query_seq[NUM_QUERIES];
  int query_ids[NUM_QUERIES];
  int query_lens[NUM_QUERIES];

  // Set up queries
  std::cout << "Setting up queries..." << std::endl;
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
    job.ref_offset = i*63;
    job.ref_len = 1000;
    job.threshold = i;
    alignment_job_queue.Push(job);
  }

  // Set up engine job queues;
  std::cout << "Setting up engine job queues..." << std::endl;
  engine_job_queues = new ThreadQueue<EngineJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    engine_job_queues[i] = new ThreadQueue<EngineJob>[NUM_ENGINES_PER_FPGA];
  };

  // Set up and run thread
  std::cout << "Running engine dispatch thread..." << std::endl;
  edthread.Init(pico_drivers, streams, &alignment_job_queue, engine_job_queues,
                &query_seq_manager, &ref_seq_manager);
  edthread.Run();

  // Wait for results and print them
  std::cout << "Printing engine jobs:" << std::endl;
  while (!alignment_job_queue.Empty());
  sleep(1);
  bool done = false;
  while (done == false) {
    done = true;
    for (int i = 0; i < NUM_ENGINES_PER_FPGA; i++) {
      for (int j = 0; j < NUM_FPGAS; j++) {
        if (!engine_job_queues[j][i].Empty()) {
          EngineJob job = engine_job_queues[j][i].Pop();
          std::cout << "Query ID: " << job.query_id
                    << "\tRef ID: " << job.ref_id
                    << "\tLength: " << job.ref_len
                    << "\tOffset: " << job.ref_offset
                    << "\tOverlap Offset: " << job.overlap_offset
                    << "\tThreshold: " << job.threshold
                    << std::endl;
          if (!engine_job_queues[j][i].Empty()) {
            done = false;
          }
        }
      }
    }
  }

  std::cout << "All Done." << std::endl;
  return 0;
}
