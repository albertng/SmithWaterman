//  File Name        : enginedispatchthread.cpp
//  Description      : FPGA Engine Alignment Dispatch Thread definitions
//                     Full description in enginedispatchthread.h
//
//  Revision History :
//      Albert Ng   Oct 15 2013     Initial Revision 
//      Albert Ng   Oct 16 2013     Debugged initial version
//      Albert Ng   Oct 22 2013     Added SwAffineGapParams to AlignmentJob and EngineJob
//                                  Set scoring params between query groups
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2013     Added ref seq banking

#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "def.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "utils.h"
#include "scoring.h"
#include "enginedispatchthread.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

EngineDispatchThread::EngineDispatchThread() {
}

EngineDispatchThread::EngineDispatchThread(PicoDrv** pico_drivers, int** streams,
                                           ThreadQueue<AlignmentJob>* alignment_job_queue,
                                           ThreadQueue<EngineJob>** engine_job_queues,
                                           QuerySeqManager* query_seq_manager,
                                           RefSeqManager* ref_seq_manager) {
  Init(pico_drivers, streams, alignment_job_queue, engine_job_queues,
       query_seq_manager, ref_seq_manager);
}

void EngineDispatchThread::Init(PicoDrv** pico_drivers, int** streams,
                                ThreadQueue<AlignmentJob>* alignment_job_queue,
                                ThreadQueue<EngineJob>** engine_job_queues,
                                QuerySeqManager* query_seq_manager,
                                RefSeqManager* ref_seq_manager) {
  args_.pico_drivers = pico_drivers;
  args_.streams = streams;
  args_.alignment_job_queue = alignment_job_queue;
  args_.engine_job_queues = engine_job_queues;
  args_.query_seq_manager = query_seq_manager;
  args_.ref_seq_manager = ref_seq_manager;
}

void EngineDispatchThread::Run() {
  pthread_create(&thread_, NULL, &EngineDispatchThread::Dispatch, (void*) (&args_));
}

void EngineDispatchThread::Join() {
  pthread_join(thread_, NULL);
}

void* EngineDispatchThread::Dispatch(void* args) {
  // Get thread arguments
  PicoDrv** pico_drivers = ((EngineDispatchThreadArgs*)args)->pico_drivers;
  int** streams = ((EngineDispatchThreadArgs*)args)->streams;
  ThreadQueue<AlignmentJob>* alignment_job_queue = ((EngineDispatchThreadArgs*)args)->alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues = ((EngineDispatchThreadArgs*)args)->engine_job_queues;
  QuerySeqManager* query_seq_manager = ((EngineDispatchThreadArgs*)args)->query_seq_manager;
  RefSeqManager* ref_seq_manager = ((EngineDispatchThreadArgs*)args)->ref_seq_manager;

  // Current scoring parameters;
  SwAffineGapParams params;
  
  int num_jobs = 0;
  struct timespec start, finish;
  double elapsed;
  
  while (true) {
    AlignmentJob aln_job = alignment_job_queue->Pop();
    /*std::cout << "Engine Dispatch Thread job: " << aln_job.query_id 
              << " " << aln_job.ref_id
              << " " << aln_job.ref_offset 
              << " " << aln_job.ref_len 
              << " " << aln_job.threshold
              << " " << aln_job.params.ToString()
              << std::endl;*/
    int query_id = aln_job.query_id;
    
    if (query_id == PARAMS_JOB) {     // Set scoring params between query groups
      params = aln_job.params;
      int params_buf_len;
      int* params_buf = params.ToBuf(&params_buf_len);
      for (int i = 0; i < NUM_FPGAS; i++) {
        pico_drivers[i]->WriteDeviceAbsolute(0, (uint32_t*) params_buf, params_buf_len);
      }
    } else {
      int query_len;
      char* query_seq = query_seq_manager->GetQuerySeq(query_id, &query_len);
      int ref_id = aln_job.ref_id;
      int chr_id = aln_job.chr_id;
      long long int ref_offset = aln_job.ref_offset;
      long long int ref_len = aln_job.ref_len;
      int threshold = aln_job.threshold;

      // Get ref seq banks that contain the requested region for this alignment
      std::vector<RefSeqManager::RefSeqBank> locs = ref_seq_manager->GetRefSeqBanks(ref_id, chr_id, ref_offset, ref_offset + ref_len);

      // Partition the banks into engine jobs
      std::list<EngineJob> jobs;
      for (std::vector<RefSeqManager::RefSeqBank>::iterator it = locs.begin(); it != locs.end(); ++it) {
        RefSeqManager::RefSeqBank loc = *it;          
          
        // Compute length of ref seq bank
        long long int ref_len = (loc.end_coord - loc.start_coord) + loc.overlap_len;

        // Compute minimum job size allowable
        int min_job_len = query_len > REF_BLOCK_LEN ? 2*query_len : 2*REF_BLOCK_LEN;

        // Compute number of engine jobs to allocate for the alignment
        int num_jobs = ref_len / min_job_len;
        num_jobs = num_jobs == 0 ? 1 : num_jobs;
        num_jobs = num_jobs > NUM_ENGINES_PER_FPGA ? NUM_ENGINES_PER_FPGA : num_jobs;

        long long int cur_offset = loc.start_coord;
        for (int i = 0; i < num_jobs; i++) {
          EngineJob job;
          job.fpga_id        = loc.fpga;
          job.engine_id      = i;
          job.query_id       = query_id;
          job.ref_id         = ref_id;
          job.chr_id         = chr_id;
          job.threshold      = threshold;
          job.params         = params;
          job.ref_offset     = cur_offset;

          // Compute job length
          job.ref_len = (i < ref_len % num_jobs) ?                      // Distribute jobs evenly
                        (ref_len / num_jobs + 1) : (ref_len / num_jobs);
          cur_offset += job.ref_len;
          if (i != num_jobs - 1) {                                      // Add overlap for all jobs except last one
            job.ref_len += 2 * query_len;
          }

          // Compute offset of the overlap region
          job.overlap_offset = job.ref_offset + job.ref_len;
          if (i != num_jobs - 1) {
            job.overlap_offset -= 2 * query_len;
          }
          job.overlap_offset = (job.overlap_offset > loc.end_coord) ?   // Make sure overlap offset doesn't go beyond
                               loc.end_coord : job.overlap_offset;      //   the end of the ref seq bank
          assert(job.ref_offset + job.ref_len <= loc.end_coord + loc.overlap_len);
          
          // Compute job FPGA address
          long long int start_block_coord = (loc.start_coord / REF_BLOCK_LEN) * REF_BLOCK_LEN;
          job.fpga_addr = ((job.ref_offset - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
          
          // Compute job FPGA length
          long long int first_ref_block = ((job.ref_offset - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
          long long int last_ref_block = ((job.ref_offset + job.ref_len - 1 - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
          job.fpga_len = last_ref_block - first_ref_block + 1;
          
          jobs.push_back(job);
        }
      }

      // Dispatch jobs to FPGA engines and record the jobs for the results reader thread
      //std::cout << "Total num jobs: " << jobs.size() << std::endl;
      query_seq_manager->SetQueryNumJobs(query_id, jobs.size());
      for (std::list<EngineJob>::iterator it = jobs.begin(); it != jobs.end(); ++it) {
        EngineJob job = *it;
        //std::cout << "Dispatching job for FPGA " << job.fpga_id << " Engine " << job.engine_id << std::endl;
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        DispatchJob(pico_drivers[job.fpga_id], 
                    streams[job.fpga_id][job.engine_id], 
                    query_id,
                    query_seq,
                    query_len,
                    job.fpga_len,
                    job.fpga_addr,
                    threshold);                    
        engine_job_queues[job.fpga_id][job.engine_id].Push(job);
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed += (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    
        num_jobs++;
        if (num_jobs % 100000 == 0) {
          std::cout << "Jobs: " << num_jobs << std::endl;
          std::cout << "DispatchJob elapsed time: " << elapsed << std::endl;
        }
      }
    }
  }
}

void EngineDispatchThread::DispatchJob(PicoDrv* pico_driver, int stream,
                                       int query_id, char* query_seq, int query_len,
                                       int num_ref_blocks, int first_ref_block,
                                       int threshold) {
  uint32_t out_buf[4096];

  out_buf[0] = (uint32_t) num_ref_blocks;
  out_buf[1] = (uint32_t) first_ref_block;
  out_buf[2] = (uint32_t) ((query_id << 16) + (query_len));
  out_buf[3] = (uint32_t) threshold;

  int num_query_blocks = query_len / QUERY_BLOCK_LEN;
  if (query_len % QUERY_BLOCK_LEN != 0) {
    num_query_blocks++;
  }
  for (int i = 0; i < query_len; i++) {
    NtInt nt = NtChar2Int(query_seq[i]);
    if (query_seq[i] == 'N' || query_seq[i] == 'n') {
      nt = rand() % 4;
    }
    if (i % 16 == 0) {
      out_buf[4+i/16] = nt;
    } else {
      out_buf[4+i/16] += (nt << (2 * (i % 16)));
    }
  }
  
  /*std::cout << "Engine job for stream " << stream
            <<"\tNum Ref Blocks: " << out_buf[0]
            << "\tRef Block Offset: " << out_buf[1]
            << "\tQuery ID: " << (out_buf[2] >> 16)
            << "\tQuery Len: " << (out_buf[2] & 0xFFFF)
            << "\tThreshold: " << out_buf[3]
            << "\tQuery Seq: ";
  for (int i = 0; i < ((num_query_blocks+1)*16 / 4) - 4; i++) {
    std::cout << out_buf[i + 4] << ' ';
  }
  std::cout << std::endl;*/
  
  pico_driver->WriteStream(stream, out_buf, (num_query_blocks+1)*16);
}

