//  File Name        : smithwatermanserver.cpp
//  Description      : Server Process main thread
//
//  Revision History :
//      Albert Ng   Oct 28 2013     Initial Revision
//      Albert Ng   Nov 01 2013     Report ref name with each alignment
//      Albert Ng   Nov 13 2013     Uses REFPATH env var, takes in ref seq names
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 27 2014     Added ProcessJob()
//      Albert Ng   Feb 03 2014     Added fpga file loading

#include <iostream>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include <fstream>
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

void GetFilesWithExtension(std::string dir, std::vector<std::string>* files, std::vector<std::string>* ref_names, std::string extension) {
  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir.c_str())) == NULL) {
    std::cerr << "Invalid directory: " << dir << std::endl;
    return;
  }
  
  while ((dirp = readdir(dp)) != NULL) {
    std::string filename(dirp->d_name);
    std::string::size_type idx = filename.rfind('.');
    std::string ext;
    if (idx != std::string::npos) {
      ext = filename.substr(idx+1);
    }
    if (ext == extension) {
      files->push_back(filename);
      ref_names->push_back(filename.substr(0, idx));
    }
  }
  closedir(dp);
}

void GetFastaFiles(std::string dir, std::vector<std::string>* files, std::vector<std::string>* ref_names) {
  GetFilesWithExtension(dir, files, ref_names, "fa");
}

std::vector<int> ProcessJob(ServerComm::JobRequest jobreq, ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue, 
               QuerySeqManager* query_seq_manager, RefSeqManager* ref_seq_manager, unsigned int* errors) {
  std::vector<AlignmentJob> jobs;
  std::vector<int> query_ids;
  
  if (jobreq.params_job == true) {                  // Request for change of parameters
    AlignmentJob params_job;
    params_job.query_id = PARAMS_JOB;
    params_job.params = jobreq.params;
    jobs.push_back(params_job);
    alignment_job_queue->Push(jobs);
  } else if (jobreq.ref_name == ALL_REF) {          // Request for alignment to entire database
    int num_refs = ref_seq_manager->GetNumRefs();
    for (int ref_id = 0; ref_id < num_refs; ref_id++) {
      jobs.clear();
      std::vector<int> chr_ids = ref_seq_manager->GetChrIDs(ref_id);
      for (int i = 0; i < chr_ids.size(); i++) {
        int query_id = query_seq_manager->AddQuery(jobreq.query_name, jobreq.query_seq);
        query_ids.push_back(query_id);
        
        AlignmentJob job;
        job.query_id = query_id;
        job.ref_id = ref_id;
        job.chr_id = chr_ids[i];
        job.ref_offset = 0;
        job.ref_len = ref_seq_manager->GetRefLength(ref_id, chr_ids[i]);
        job.threshold = jobreq.threshold;
        job.params = jobreq.params;
        jobs.push_back(job);
      }
      
      alignment_job_queue->Push(jobs);
      std::cout << "Processed " << jobs.size() << " jobs" << std::endl;
    }
  } else {                                          // Request for alignment to single species
    int ref_id = ref_seq_manager->GetRefID(jobreq.ref_name);
    int chr_id = ref_seq_manager->GetChrID(ref_id, jobreq.chr_name);
    std::vector<int> chr_ids;
    if (jobreq.chr_name == ALL_CHROM) {
      chr_ids = ref_seq_manager->GetChrIDs(ref_id);
    } else {
      chr_ids.push_back(chr_id);
    }
    
    // Some syntax checks
    for (int i = 0; i < jobreq.query_seq.length(); i++) {                      // Check for invalid nucleotides
      if (jobreq.query_seq[i] != 'n' && jobreq.query_seq[i] != 'N' &&
          jobreq.query_seq[i] != 'a' && jobreq.query_seq[i] != 'A' &&
          jobreq.query_seq[i] != 'g' && jobreq.query_seq[i] != 'G' &&
          jobreq.query_seq[i] != 'c' && jobreq.query_seq[i] != 'C' &&
          jobreq.query_seq[i] != 't' && jobreq.query_seq[i] != 'T') {
        *errors |= SYNTAX_ERROR_QUERYSEQ;
        break;
      }
    }
    if (ref_id == -1) {                                                        // Check for invalid ref seq
      *errors |= SYNTAX_ERROR_REFNAME;
    } else if (chr_id == -1 && jobreq.chr_name != ALL_CHROM) {                 // Check for invalid chromosome
      *errors |= SYNTAX_ERROR_CHRNAME;
    }
    if (ref_id != -1 && chr_id != -1 && jobreq.chr_name != ALL_CHROM &&        // Check for start past end
        jobreq.ref_start >= jobreq.ref_end - 1) {                         
      *errors |= SYNTAX_ERROR_REFSTARTEND;
    }
    if (ref_id != -1 && chr_id != -1 && jobreq.chr_name != ALL_CHROM &&        // Check for invalid start coordinates
        jobreq.ref_start >= ref_seq_manager->GetRefLength(ref_id, chr_id)) {
      *errors |= SYNTAX_ERROR_REFSTART;
    }
    if (ref_id != -1 && chr_id != -1 && jobreq.chr_name != ALL_CHROM &&        // Check for invalid end coordinates
        jobreq.ref_end - 1 > ref_seq_manager->GetRefLength(ref_id, chr_id)) {
      *errors |= SYNTAX_ERROR_REFEND;
    }
    
    // Set up alignment information
    if (*errors == 0) {
      for (int i = 0; i < chr_ids.size(); i++) {
        int query_id = query_seq_manager->AddQuery(jobreq.query_name, jobreq.query_seq);
        query_ids.push_back(query_id);
        
        AlignmentJob job;
        job.query_id = query_id;
        job.ref_id = ref_id;
        job.chr_id = chr_ids[i];
        if (jobreq.chr_name == ALL_CHROM) {
          job.ref_offset = 0;
          job.ref_len = ref_seq_manager->GetRefLength(ref_id, chr_ids[i]);
        } else {
          job.ref_offset = jobreq.ref_start - 1;
          job.ref_len = jobreq.ref_end - jobreq.ref_start;
        }
        job.threshold = jobreq.threshold;
        job.params = jobreq.params;
        jobs.push_back(job);
      }
    }
    
    alignment_job_queue->Push(jobs);
    std::cout << "Processed " << jobs.size() << " jobs" << std::endl;
  }
  
  return query_ids;
}

int main(int argc, char *argv[]) {
  // Shared structures
  PicoDrv** pico_drivers;
  int** streams;
  QuerySeqManager query_seq_manager;
  RefSeqManager ref_seq_manager;
  ThreadQueue<std::vector<AlignmentJob> > alignment_job_queue;
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
      ref_seq_manager.AddRef(parentdir_str, file_names[i], ref_names[i]);
    }
  }
  else {
    for (int i = 2; i < argc; i++) {
      std::string ref_file = std::string(argv[i]) + ".fa";
      ref_seq_manager.AddRef(parentdir_str, ref_file, std::string(argv[i]));
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
  std::cout << "Disk loading completed in " << ref_seq_manager.GetDiskRefSeqLoadTime() << " seconds." << std::endl;
  std::cout << "FPGA DRAM loading completed in " << ref_seq_manager.GetFPGARefSeqLoadTime() << " seconds." << std::endl;
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
    ref_seq_manager.ResetStats();
    num_hits = 0;
    
    // Parse the query group and initiate alignments
    unsigned int errors = 0;
    std::vector<int> query_ids;
    /*std::vector<int> query_ids = server_comm.GetQueryGroup(&alignment_job_queue,
                                                           &query_seq_manager,
                                                           &ref_seq_manager,
                                                           &errors);*/
    std::vector<ServerComm::JobRequest> jobs = server_comm.GetQueryGroup(&errors);
    //std::cout << jobs.size() << " job requests received!" << std::endl;
    for (std::vector<ServerComm::JobRequest>::iterator it = jobs.begin(); it != jobs.end(); it++) {
      std::vector<int> new_query_ids = ProcessJob(*it, &alignment_job_queue, &query_seq_manager, &ref_seq_manager, &errors);
      for (int i = 0; i < new_query_ids.size(); i++) {
        query_ids.push_back(new_query_ids[i]);
      }
    } 
    
#ifdef SWSERVERTIMING
    clock_gettime(CLOCK_MONOTONIC, &start);
#endif
    // Wait for alignment of query group to finish
    //   Send alignment results back to client when we get them
    std::unordered_set<AlignmentResult, AlignmentResultHash> res_set;
    bool group_done = false;
    int num_boundary_duplicates = 0;
    while (group_done == false || result_queue.Size() != 0) {
      while (result_queue.Size() != 0) {
        AlignmentResult aln_res = result_queue.Pop();
        
        // Keep a set of unique alignments
        std::unordered_set<AlignmentResult, AlignmentResultHash>::iterator aln_it = res_set.find(aln_res);
        if (aln_it == res_set.end()) {
          res_set.insert(aln_res);
        } else if (((*aln_it).score < aln_res.score) || 
                   ((*aln_it).score == aln_res.score && (*aln_it).alignment.GetLength() < aln_res.alignment.GetLength())) {
          res_set.erase(aln_it);
          res_set.insert(aln_res);
          num_boundary_duplicates++;
        } else {
          num_boundary_duplicates++;
        }
      }
      
      group_done = true;
      for (std::vector<int>::iterator it = query_ids.begin(); it != query_ids.end(); ++it) {
        if (!query_seq_manager.QueryDone(*it)) {
          group_done = false;
        }
      }
    }
    
    // Send the unique set of alignment results
    for (std::unordered_set<AlignmentResult, AlignmentResultHash>::iterator it = res_set.begin();
         it != res_set.end(); it++) {
      AlignmentResult aln_res = *it;
      std::string query_name = query_seq_manager.GetQueryName(aln_res.hsr.query_id);
      std::string ref_name = ref_seq_manager.GetRefName(aln_res.hsr.ref_id);
      std::string chr_name = ref_seq_manager.GetChrName(aln_res.hsr.ref_id, aln_res.hsr.chr_id);
      server_comm.SendAlignment(aln_res, query_name, ref_name, chr_name);
      num_hits++;
    }
    
    // End the query group
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
    std::cout << num_boundary_duplicates << " duplicated hits found and removed" << std::endl;

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
              << std::endl;
              
    int ref_seq_access_count = ref_seq_manager.GetRefSeqAccessCount();
    double file_read_time = ref_seq_manager.GetFileReadTime();
    double seq_copy_time = ref_seq_manager.GetSeqCopyTime();
    long long int ref_length_read = ref_seq_manager.GetRefLengthRead();
    std::cout << "Ref seq accesses: " << ref_seq_access_count << "\n"
              << "Ref seq file read time: " << file_read_time << "\n"
              << "Ref seq copy time: " << seq_copy_time << "\n"
              << "Ref length read: " << ref_length_read << std::endl;
#endif
    std::cout << std::endl;
  }
}


