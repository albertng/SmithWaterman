//  File Name        : swthread_test.cpp
//  Description      : Smith-Waterman aligner thread test
//
//  Revision History :
//      Albert Ng   Oct 07 2013     Initial Revision
//      Albert Ng   Oct 11 2013     Incorporated query_seq_manager 

#include "swthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "def.h"
#include "utils.h"
#include <iostream>
#include <cstring>
#include <time.h>

#define NUM_THREADS 12
#define NUM_QUERIES 5
#define NUM_JOBS 800000
#define THRESHOLD 0
#define NUM_ENGINES 5

int main(void) {
  RefSeqManager ref_seq_manager;
  QuerySeqManager query_seq_manager;
  ThreadQueue<HighScoreRegion> hsr_queue;
  ThreadQueue<AlignmentResult> result_queue;
  SWThread swthreads[NUM_THREADS];
  SwAffineGapParams params;
  char* query_seq[NUM_QUERIES];
  int query_ids[NUM_JOBS];
  
  // Set up queries
  query_seq[0] = (char*) "AGCTAGTCNN";
  query_seq[1] = (char*) "GACCGAGACT";
  query_seq[2] = (char*) "TAACCTAGCTAGCT";
  query_seq[3] = (char*) "CCATGTATCG";
  query_seq[4] = (char*) "TATNCATGG";

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
 
  std::cout<<"Setting up SW Threads"<<std::endl;
 
  // Set up Smith-Waterman worker threads
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Init(params, &hsr_queue, &result_queue, &ref_seq_manager, &query_seq_manager);
  }

  std::cout<<"Populating job queue"<<std::endl;
  
  // Populate job queue with a bunch of jobs
  for (int i = 0; i < NUM_JOBS; i++) {
    query_ids[i] = query_seq_manager.AddQuery(query_seq[i % NUM_QUERIES], 
                                              strlen(query_seq[i % NUM_QUERIES]),
                                              NUM_ENGINES);
    HighScoreRegion hsr;  
    hsr.query_id = query_ids[i];
    hsr.ref_id = 0;
    hsr.ref_offset = 0;
    hsr.ref_len = ref_seq_manager.ref_length();
    hsr.threshold = THRESHOLD;
    hsr_queue.Push(hsr);
    query_seq_manager.IncHighScoreRegionCount(query_ids[i]);
  }

  std::cout<<"Starting workers"<<std::endl;

  // Start the workers
  struct timespec start, finish;
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Run();
  }
  
  // Signal FPGA end of alignment for all queries
  for (int i = 0; i < NUM_JOBS; i++) {
    for (int j = 0; j < NUM_ENGINES; j++) {
      query_seq_manager.DecHighScoreRegionCount(query_ids[i]);
    }
  }

  // Wait until all jobs are done
  bool done = false;
  while (done == false) {
    done = true;
    for (int i = 0; i < NUM_JOBS; i++) {
      if (!query_seq_manager.QueryDone(query_ids[i])) {
        done = false;
      }
    }
  }
  
  clock_gettime(CLOCK_MONOTONIC, &finish);
  double elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << "Computation took " << elapsed << " seconds" << std::endl;
  /*std::cout<<"Printing alignment results"<<std::endl;  

  // Print out alignment results
  while (result_queue.Size() != 0) {
    AlignmentResult res = result_queue.Pop();
    std::cout << "Query: " << res.hsr.query_id << '\t' << "Ref Offset: " << res.hsr.ref_offset << '\t' << "Score: " << res.score << std::endl;
    res.alignment->Print(std::cout);
    std::cout << std::endl;
  }*/

  // Memory cleanup
  /*for (int i = 0; i < NUM_THREADS; i++) {
    delete swthreads[i];
  }*/
  
  return 0;
}
