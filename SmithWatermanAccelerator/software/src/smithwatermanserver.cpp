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

int GetFastaFiles(std::string dir, std::vector<std::string>* files, std::vector<std::string>* ref_names) {
  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir.c_str())) == NULL) {
    std::cerr << "Invalid ref seq directory: " << dir << std::endl;
    return errno;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    std::string filename(dirp->d_name);
    std::string::size_type idx = filename.rfind('.');
    std::string extension;
    if (idx != std::string::npos) {
      extension = filename.substr(idx+1);
    }
    if (extension == "fa" || extension == "FA") {
      files->push_back(dir + "/" + filename);
      ref_names->push_back(filename.substr(0, idx));
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

  // Timing values
  struct timespec start, finish;
  double elapsed;

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
#ifdef SWSERVERTIMING
  clock_gettime(CLOCK_MONOTONIC, &start);
#endif
  ref_seq_manager.Init(pico_drivers);
  char* ref_parentdir = getenv("REFPATH");
  if (ref_parentdir == NULL) {
    std::cerr << "$REFPATH environment variable not set!" << std::endl;
    return 1;
  }
  std::string parentdir_str(ref_parentdir);
  std::string arg2(argv[2]);
  if (arg2 == ALL_REF) {
    std::vector<std::string> file_names;
    std::vector<std::string> ref_names;
    GetFastaFiles(parentdir_str, &file_names, &ref_names);
    for (int i = 0; i < file_names.size(); i++) {
      std::cout << "Loading reference " << ref_names[i] << "..." << std::endl;
      ref_seq_manager.AddRef(file_names[i], ref_names[i]);
    }
  }
  else {
    for (int i = 2; i < argc; i++) {
      std::string ref_file = parentdir_str;
      ref_file += "/";
      ref_file += argv[i];
      ref_file += ".fa";
      
      std::cout << "Loading reference " << argv[i] << "..." << std::endl;
      ref_seq_manager.AddRef(ref_file, std::string(argv[i]));
    }
  }
  std::cout << "Loaded " << ref_seq_manager.GetTotalRefLength() << " nucleotides total." << std::endl;
  long long int fpga_storage[NUM_FPGAS];
  ref_seq_manager.GetFPGAStorage(fpga_storage);
  for (int i = 0; i < NUM_FPGAS; i++) {
    std::cout << "FPGA " << i << ": " << fpga_storage[i] << "B" << std::endl;
  }
#ifdef SWSERVERTIMING
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << "Ref seq loading completed in " << elapsed << " seconds." << std::endl;
#endif
  
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
  while (true) {
    for (int i = 0; i < NUM_SW_THREADS; i++) {
      swthreads[i].ResetStats();
      swthreads[i].ResetMatrices();
    }
    num_hits = 0;
    
    // Parse the query group and initiate alignment
    unsigned int errors;
    std::vector<int> query_ids = server_comm.GetQueryGroup(&alignment_job_queue,
                                                           &query_seq_manager,
                                                           &ref_seq_manager,
                                                           &errors);
    
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

    double total_ref_seq_time = 0;
    double total_alloc_time = 0;
    double total_init_time = 0;
    double total_compute_time = 0;
    double total_backtrace_time = 0;
    long long int total_job_count = 0;
    long long int total_cell_count = 0;
    for (int i = 0; i < NUM_SW_THREADS; i++) {
      SWThread::SWThreadStats stats = swthreads[i].GetStats();
      total_ref_seq_time += stats.ref_seq_time;
      total_alloc_time += stats.alloc_time;
      total_init_time += stats.init_time;
      total_compute_time += stats.compute_time;
      total_backtrace_time += stats.backtrace_time;
      total_job_count += stats.job_count;
      total_cell_count += stats.cell_count;
    }
    std::cout << total_job_count << " high scoring regions found by FPGAs" << std::endl;
    std::cout << total_cell_count << " cells computed by software threads" << std::endl;
    double total_time = total_ref_seq_time + total_alloc_time + total_init_time + total_compute_time + total_backtrace_time;
    std::cout << total_ref_seq_time << "s ref seq, "
              << total_alloc_time << "s alloc, "
              << total_init_time << "s init, " 
              << total_compute_time << "s compute, "
              << total_backtrace_time << "s backtrace"
              << std::endl;
    std::cout << (total_ref_seq_time / total_time)*100 << "% ref seq, "
              << (total_alloc_time / total_time)*100 << "% alloc, "
              << (total_init_time / total_time)*100 << "% init, " 
              << (total_compute_time / total_time)*100 << "% compute, "
              << (total_backtrace_time / total_time)*100 << "% backtrace"
              << std::endl << std::endl;
#endif
  }
}


