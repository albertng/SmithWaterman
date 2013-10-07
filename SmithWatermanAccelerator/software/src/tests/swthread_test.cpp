//  File Name        : swthread_test.cpp
//  Description      : Smith-Waterman aligner thread test
//
//  Revision History :
//      Albert Ng   Oct 07 2013     Initial Revision 

#include "swthread.h"
#include "threadqueue.h"
#include "refseqmanager_stub.h"
#include "sharedstructs.h"
#include "utils.h"
#include <iostream>
#include <string>

#define NUM_THREADS 2
#define NUM_QUERIES 5
#define THRESHOLD 0

int main(void) {
  RefSeqManager ref_seq_manager;
  ThreadQueue<HighScoreRegion> hsr_queue;
  ThreadQueue<AlignmentResult> result_queue;
  SWThread swthreads[NUM_THREADS];
  SwAffineGapParams params;
  std::string* query_seq[NUM_QUERIES];
  
  // Set up scoring parameters
  uint32_t[4][4] sub_mat;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        sub_mat[i][j] = 2;
      } else {
        sub_mat[i][j] = -2;
    }
  }
  params.sub_mat = sub_mat;
  params.gap_open = -2;
  params.gap_extend = -1;
  
  // Set up Smith-Waterman worker threads
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i] = SWThread(params, &hsr_queue, &result_queue, &ref_seq_manager);
  }
  
  // Populate job queue with a bunch of jobs
  for (int i = 0; i < 10000; i++) {
    HighScoreRegion hsr;  
    hsr.query_id = (uint32_t) i;
    hsr.query_seq = query_seq[i % NUM_QUERIES];
    hsr.query_len = query_seq[i % NUM_QUERIES]->length();
    hsr.ref_id = 0;
    hsr.ref_offset = (i % 5) * 10;
    hsr.ref_len = 10;
    hsr.threshold = THRESHOLD;
  }

  // Start the workers
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Run();
  }

  // Wait until all jobs are done
  while (result_queue.Size() != 10000);

  while (result_queue.Size() != 0) {
    AlignmentResult res = result_queue.Pop();
    std::cout << "Query: " << res.hsr.query_id << '\t' << "Ref Offset: " << res.hsr.ref_offset << '\t' << "Score: " << res.score << std::endl;
    res.alignment->Print(std::cout);
    std::cout << std::endl;
  }
  
  return 0;
}
