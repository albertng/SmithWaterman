//  File Name        : smithwatermanserver.cpp
//  Description      : Server Process main thread
//
//  Revision History :
//      Albert Ng   Oct 28 2013     Initial Revision
//      Albert Ng   Nov 01 2013     Report ref name with each alignment
//      Albert Ng   Nov 13 2013     Uses REFPATH env var, takes in ref seq names
//      Albert Ng   Nov 19 2013     Added chromosomes

#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include "def.h"
#include "servercomm.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "scoring.h"
#include "enginedispatchthread.h"
#include "resultsreaderthread.h"
#include "swthread.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

#define SWSERVERTIMING

int GetFastaFiles(std::string dir, std::vector<std::string>* files) {
  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir.c_str())) == NULL) {
    std::cerr << "Invalid ref seq directory: " << dir << std::endl;
    return errno;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    std::string filename = dir + "/" + dirp->d_name;
    std::string::size_type idx = filename.rfind('.');
    std::string extension;
    if (idx != std::string::npos) {
      extension = filename.substr(idx+1);
    }
    if (extension == "fa" || extension == "FA") {
      files->push_back(filename);
    }
  }
  closedir(dp);
  return 0;
}

int main(int argc, char *argv[]) {
  // Shared structures
  PicoDrv** pico_drivers;
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
  SWThread swthreads[NUM_SW_THREADS];

  // Check program args
  if (argc < 3) {
    std::cerr << "Usage: ./smithwatermanserver <BIT FILE> <REF SEQ 1> [<REF SEQ 2> ...]" << std::endl;;
    return 1;
  }
  
  // Set up pico FPGA drivers
  const char* bitfile_name = argv[1];
  pico_drivers = new PicoDrv*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    std::cout << "Loading FPGA " << i << " with bitfile: " << bitfile_name << std::endl;
    int err = RunBitFile(bitfile_name, &(pico_drivers[i]));
    if (err < 0) {
      std::cerr << "RunBitFile error: " << PicoErrors_FullError << "\n";
      return 1;
    }
  }
  
  // Set up streams to engines
  streams = new int*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    streams[i] = new int[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      streams[i][j] = pico_drivers[i]->CreateStream(j+1);
      if (streams[i][j] < 0) {
        std::cerr << "Couldn't open stream " << j+1 << " on FPGA " << i << "! (return code: " << streams[i][j] << ")" << std::endl;
        return 1;
      }
    }
  }
  
  // Set up ref seq manager
  ref_seq_manager.Init(pico_drivers);
  char* ref_parentdir = getenv("REFPATH");
  if (ref_parentdir == NULL) {
    std::cerr << "$REFPATH environment variable not set!" << std::endl;
    return 1;
  }
  for (int i = 2; i < argc; i++) {
    std::string ref_dir(ref_parentdir);
    ref_dir += "/";
    ref_dir += argv[i];
    std::vector<std::string> ref_files;
    if (GetFastaFiles(ref_dir, &ref_files) != 0) {
      return 1;
    }
    
    std::cout << "Loading reference " << argv[i] << "..." << std::endl;
    ref_seq_manager.AddRef(ref_files, std::string(argv[i]));
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
  for (int i = 0; i < NUM_SW_THREADS; i++) {
    swthreads[i].Init(&hsr_queue, &result_queue, 
                      &ref_seq_manager, &query_seq_manager);
    swthreads[i].Run();
  }
  
  // Set up socket communication
  std::cout << "Server running..." << std::endl;
  ServerComm server_comm(30000);
  
  // Continuously accept and run alignments
  long long int num_hits;
  struct timespec start, finish;
  double elapsed;
  while (true) {
    // Parse the query group and initiate alignment
    unsigned int errors;
    std::vector<int> query_ids = server_comm.GetQueryGroup(&alignment_job_queue,
                                                           &query_seq_manager,
                                                           &ref_seq_manager,
                                                           &errors);
    for (int i = 0; i < NUM_SW_THREADS; i++) {
      swthreads[i].ResetStats();
    }
    num_hits = 0;
    
#ifdef SWSERVERTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif
    
    // Wait for alignment of query group to finish
    //   Send alignment results back to client when we get them
    bool group_done = false;
    while (group_done == false || result_queue.Size() != 0) {
      while (result_queue.Size() != 0) {
        AlignmentResult aln_res = result_queue.Pop();
        std::string query_name = query_seq_manager.GetQueryName(aln_res.hsr.query_id);
        std::string ref_name = ref_seq_manager.GetRefName(aln_res.hsr.ref_id);
        std::string chr_name = ref_seq_manager.GetChrName(aln_res.hsr.ref_id, aln_res.hsr.chr_id);
        server_comm.SendAlignment(aln_res, query_name, ref_name, chr_name);
        
        num_hits++;
      }
      
      group_done = true;
      for (std::vector<int>::iterator it = query_ids.begin(); it != query_ids.end(); ++it) {
        if (!query_seq_manager.QueryDone(*it)) {
          group_done = false;
        }
      }
    }
    server_comm.EndQueryGroup(errors);
    
    // Reclaim finished query memory
    for (std::vector<int>::iterator it = query_ids.begin(); it != query_ids.end(); ++it) {
      query_seq_manager.RemoveQuery(*it);
    }

#ifdef SWSERVERTIMING
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    std::cout << num_hits <<  " hits found in " << elapsed << " seconds" << std::endl;

    double total_init_time = 0;
    double total_compute_time = 0;
    double total_backtrace_time = 0;
    for (int i = 0; i < NUM_SW_THREADS; i++) {
      SWThread::SWThreadStats stats = swthreads[i].GetStats();
      total_init_time += stats.init_time;
      total_compute_time += stats.compute_time;
      total_backtrace_time += stats.backtrace_time;
    }
    double total_time = total_init_time + total_compute_time + total_backtrace_time;
    std::cout << total_init_time / total_time << "% init, " 
              << total_compute_time / total_time << "% compute, "
              << total_backtrace_time / total_time << "%backtrace"
              << std::endl;
#endif
  }
}


