//  File Name        : smithwatermanserver.cpp
//  Description      : Server Process main thread
//
//  Revision History :
//      Albert Ng   Oct 28 2013     Initial Revision
//

#include "servercomm.h"
#include "picodrv_stub.h"
#include "threadqueue.h"
#include "def.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "scoring.h"
#include "enginedispatchthread.h"
#include "resultsreaderthread.h"
#include "swthread.h"
#include <iostream>

#define NUM_THREADS 1

int main(int argc, char *argv[]) {
  // Shared structures
  PicoDrv* pico_drivers;
  int** streams;
  QuerySeqManager query_seq_manager;
  RefSeqManager ref_seq_manager;
  ThreadQueue<AlignmentJob> alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues;
  ThreadQueue<HighScoreRegion> hsr_queue;
  ThreadQueue<AlignmentResult> result_queue;
  
  // Threads
  EngineDispatchThread edthread;
  ResultsReaderThread rrthread;
  SWThread swthreads[NUM_THREADS];

  // Check program args
  if (argc < 2) {
    std::cerr << "Usage: ./serverqueryparser_test <REF SEQ FASTA FILE1> [<REF SEQ FASTA FILE2> ...]\n";
    return 1;
  }
  
  // Set up pico drivers and streams
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  }
  streams = new int*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    streams[i] = new int[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      streams[i][j] = j;
    }
  }
  
  // Set up ref seq manager
  ref_seq_manager.Init(pico_drivers);
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ref_seq_manager.AddRef(filename);
  }
  
  // Set up engine job queues
  engine_job_queues = new ThreadQueue<EngineJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    engine_job_queues[i] = new ThreadQueue<EngineJob>[NUM_ENGINES_PER_FPGA];
  }
  
  // Set up and start threads
  edthread.Init(pico_drivers, streams, &alignment_job_queue, engine_job_queues,
                &query_seq_manager, &ref_seq_manager);
  edthread.Run();
  rrthread.Init(pico_drivers, streams, &hsr_queue, &query_seq_manager,
                engine_job_queues);
  rrthread.Run();
  for (int i = 0; i < NUM_THREADS; i++) {
    swthreads[i].Init(&hsr_queue, &result_queue, 
                      &ref_seq_manager, &query_seq_manager);
    swthreads[i].Run();
  }
  
  // Set up socket communication
  ServerComm server_comm(30000);
  
  // Continuously accept and run alignments
  while (true) {
    // Parse and align the query group
    std::list<int> query_ids = server_comm.ParseQueryGroup(&alignment_job_queue,
                                                           &query_seq_manager,
                                                           &ref_seq_manager);

    // Wait for alignment of query group to finish
    bool group_done = false;
    while (group_done == false) {
      group_done = true;
      for (std::list<int>::iterator it = query_ids.begin(); it != query_ids.end(); ++it) {
        if (!query_seq_manager.QueryDone(*it)) {
          group_done = false;
        }
      }
    }
    
    // Send alignment results
    while (result_queue.Size() != 0){
      AlignmentResult aln_res = result_queue.Pop();
      std::string query_name = query_seq_manager.GetQueryName(aln_res.hsr.query_id);
      server_comm.SendAlignment(aln_res, query_name);
    }
    server_comm.SendEndOfQueryGroup();
    
    // Reclaim finished query memory
    for (std::list<int>::iterator it = query_ids.begin(); it != query_ids.end(); ++it) {
      query_seq_manager.RemoveQuery(*it);
    }
  }
}


