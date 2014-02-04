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
//      Albert Ng   Jan 14 2014     Added ref seq banking
//      Albert Ng   Jan 29 2014     Combined multiple engine jobs into larger PCIe streams

#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <list>
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
                                           ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue,
                                           ThreadQueue<EngineJob>** engine_job_queues,
                                           QuerySeqManager* query_seq_manager,
                                           RefSeqManager* ref_seq_manager) {
  Init(pico_drivers, streams, alignment_job_queue, engine_job_queues,
       query_seq_manager, ref_seq_manager);
}

void EngineDispatchThread::Init(PicoDrv** pico_drivers, int** streams,
                                ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue,
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
  ThreadQueue<std::vector<AlignmentJob> >* alignment_job_queue = ((EngineDispatchThreadArgs*)args)->alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues = ((EngineDispatchThreadArgs*)args)->engine_job_queues;
  QuerySeqManager* query_seq_manager = ((EngineDispatchThreadArgs*)args)->query_seq_manager;
  RefSeqManager* ref_seq_manager = ((EngineDispatchThreadArgs*)args)->ref_seq_manager;

  // Current scoring parameters;
  SwAffineGapParams params;
  
  struct timespec start, finish;
  double elapsed;
          
  int max_buf_len_per_job = 4 * (1 + MAX_QUERY_LEN / QUERY_BLOCK_LEN);
  if (MAX_QUERY_LEN % QUERY_BLOCK_LEN != 0) {
    max_buf_len_per_job += 4;
  }
  uint32_t* dispatch_buf = new uint32_t[EngineDispatchThread::kMaxJobsDispatch * max_buf_len_per_job];
          
  while (true) {
    std::vector<AlignmentJob> aln_jobs = alignment_job_queue->Pop();
    std::list<DispatchJob> dispatch_jobs[NUM_FPGAS][NUM_ENGINES_PER_FPGA];
    
    //std::cout << aln_jobs.size() << " EngineDispatchThread alignment jobs" << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < aln_jobs.size(); i++) {
      AlignmentJob aln_job = aln_jobs[i];
      /*std::cout << "Engine Dispatch Thread job: " << aln_job.query_id 
                << " " << aln_job.ref_id
                << " " << aln_job.chr_id
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
        for (int j = 0; j < NUM_FPGAS; j++) {
          pico_drivers[j]->WriteDeviceAbsolute(0, (uint32_t*) params_buf, params_buf_len);
        }
        delete[] params_buf;
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
        std::vector<EngineJob> engine_jobs;
        for (std::vector<RefSeqManager::RefSeqBank>::iterator it = locs.begin(); it != locs.end(); ++it) {
          RefSeqManager::RefSeqBank loc = *it;          
            
          // Compute length of ref seq bank
          long long int ref_len = (loc.end_coord - loc.start_coord) + loc.overlap_len;

          // Compute minimum job size allowable
          int min_job_len = 2*query_len > 50*REF_BLOCK_LEN ? 2*query_len : 50*REF_BLOCK_LEN;

          // Compute number of engine jobs to allocate for the alignment
          int num_jobs = ref_len / min_job_len;
          num_jobs = num_jobs == 0 ? 1 : num_jobs;
          num_jobs = num_jobs > NUM_ENGINES_PER_FPGA ? NUM_ENGINES_PER_FPGA : num_jobs;

          long long int cur_offset = loc.start_coord;
          for (int j = 0; j < num_jobs; j++) {
            EngineJob engine_job;
            engine_job.fpga_id        = loc.fpga;
            engine_job.engine_id      = j;
            engine_job.query_id       = query_id;
            engine_job.ref_id         = ref_id;
            engine_job.chr_id         = chr_id;
            engine_job.threshold      = threshold;
            engine_job.params         = params;
            engine_job.ref_offset     = cur_offset;

            // Compute job length
            engine_job.ref_len = (j < ref_len % num_jobs) ?                      // Distribute jobs evenly
                                 (ref_len / num_jobs + 1) : (ref_len / num_jobs);
            cur_offset += engine_job.ref_len;
            if (j != num_jobs - 1) {                                             // Add overlap for all jobs except last one
              engine_job.ref_len += (2 * query_len);
            }

            // Compute offset of the overlap region
            engine_job.overlap_offset = engine_job.ref_offset + engine_job.ref_len;
            if (j != num_jobs - 1) {
              engine_job.overlap_offset -= (2 * query_len);
            }
            engine_job.overlap_offset = (engine_job.overlap_offset > loc.end_coord) ?   // Make sure overlap offset doesn't go beyond
                                        loc.end_coord : engine_job.overlap_offset;      //   the end of the ref seq bank
            assert(engine_job.ref_offset + engine_job.ref_len <= loc.end_coord + loc.overlap_len);
            
            // Compute job FPGA address
            long long int start_block_coord = (loc.start_coord / REF_BLOCK_LEN) * REF_BLOCK_LEN;
            engine_job.fpga_addr = ((engine_job.ref_offset - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
            
            // Compute job FPGA length
            long long int first_ref_block = ((engine_job.ref_offset - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
            long long int last_ref_block = ((engine_job.ref_offset + engine_job.ref_len - 1 - start_block_coord) / REF_BLOCK_LEN) + loc.addr;
            engine_job.fpga_len = last_ref_block - first_ref_block + 1;
            
            engine_jobs.push_back(engine_job);
          }
        }

        // Dispatch jobs to FPGA engines and record the jobs for the results reader thread
        //std::cout << "Total num jobs: " << engine_jobs.size() << std::endl;
        query_seq_manager->SetQueryNumJobs(query_id, engine_jobs.size());
        for (std::vector<EngineJob>::iterator it = engine_jobs.begin(); it != engine_jobs.end(); ++it) {
          EngineJob job = *it;
          
          DispatchJob dispatch_job;
          dispatch_job.query_id = query_id;
          dispatch_job.query_seq = query_seq;
          dispatch_job.query_len = query_len;
          dispatch_job.threshold = threshold;
          dispatch_job.num_ref_blocks = job.fpga_len;
          dispatch_job.first_ref_block = job.fpga_addr;
          dispatch_job.engine_job = job;
          
          //std::cout << "FPGA " << job.fpga_id << " Engine " << job.engine_id << " query_id " << query_id << " fpga_len " << job.fpga_len << " fpga_addr " << job.fpga_addr << std::endl;
          dispatch_jobs[job.fpga_id][job.engine_id].push_back(dispatch_job);
        }
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    std::cout << "Job loop took " << elapsed << " seconds" << std::endl;

    for (int i = 0; i < NUM_FPGAS; i++) {
      for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
        int job_cnt = 0;
        int block_cnt = 0;
        for (std::list<EngineDispatchThread::DispatchJob>::iterator it = dispatch_jobs[i][j].begin(); it != dispatch_jobs[i][j].end(); it++) {
          block_cnt += (*it).num_ref_blocks;
          job_cnt++;
        }
        //std::cout << "FPGA " << i << " Engine " << j << " " << job_cnt << " " << block_cnt << std::endl;
      }
    }
    
    bool done = false;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (done == false) {
      done = true;
      for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
        for (int i = 0; i < NUM_FPGAS; i++) {
          if (dispatch_jobs[i][j].empty() == false) {
            done = false;
            DispatchJobs(pico_drivers[i], streams[i][j], &(engine_job_queues[i][j]), &(dispatch_jobs[i][j]), dispatch_buf);
          }
        }
      }
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    std::cout << "Dispatch loop took " << elapsed << " seconds" << std::endl;
  }
}

void EngineDispatchThread::DispatchJobs(PicoDrv* pico_driver, int stream, ThreadQueue<EngineJob>* engine_job_queue,
                                        std::list<EngineDispatchThread::DispatchJob>* jobs, uint32_t* out_buf) {                        
  int query_len   = jobs->front().query_len;
  int threshold   = jobs->front().threshold;

  // Compute number of 32-bit buffer slots to allocate per job to dispatch
  int buf_len_per_job = 4 * (1 + query_len / QUERY_BLOCK_LEN);
  if (query_len % QUERY_BLOCK_LEN != 0) {
    buf_len_per_job += 4;
  }

  // Compute maximum number of jobs that can be sent without stalling
  int bytes_available = pico_driver->GetBytesAvailable(stream, false);
  int max_num_jobs = bytes_available / (buf_len_per_job * 4);
  
  // Fill dispatch buffer
  int cur_index = 0;
  int cur_job = 0;
  for (std::list<EngineDispatchThread::DispatchJob>::iterator it = jobs->begin(); 
       it != jobs->end() && cur_job < max_num_jobs; it++, cur_job++) {
    EngineDispatchThread::DispatchJob job = *it;
    assert(job.query_len == query_len);
    assert(job.threshold == threshold);
  
    out_buf[cur_index + 0] = (uint32_t) job.num_ref_blocks;
    out_buf[cur_index + 1] = (uint32_t) job.first_ref_block;
    out_buf[cur_index + 2] = (uint32_t) ((job.query_id << 16) + query_len);
    out_buf[cur_index + 3] = (uint32_t) threshold;
    
    for (int j = 0; j < query_len; j++) {
      NtInt nt = NtChar2Int(job.query_seq[j]);
      if (job.query_seq[j] == 'N' || job.query_seq[j] == 'n') {
        nt = rand() % 4;
      }
      if (j % 16 == 0) {
        out_buf[cur_index + 4+j/16] = nt;
      } else {
        out_buf[cur_index + 4+j/16] += (nt << (2 * (j % 16)));
      }
    }
    
    cur_index += buf_len_per_job;
  }
  int num_jobs = cur_job;
  
  // Write dispatch buffer to FPGA
  pico_driver->WriteStream(stream, out_buf, (num_jobs * buf_len_per_job) * 4);
  
  // Store engine jobs onto engine job queue
  cur_job = 0;
  for (std::list<EngineDispatchThread::DispatchJob>::iterator it = jobs->begin(); 
       it != jobs->end() && cur_job < max_num_jobs; it++, cur_job++) {
    EngineDispatchThread::DispatchJob job = *it;
    engine_job_queue->Push(job.engine_job);
  }
  
  // Remove dispatched jobs from the queue
  for (int i = 0; i < max_num_jobs && jobs->empty() == false; i++) {
    jobs->pop_front();
  }
}
/*
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
  
  //std::cout << "Engine job for stream " << stream
  //          <<"\tNum Ref Blocks: " << out_buf[0]
  //          << "\tRef Block Offset: " << out_buf[1]
  //          << "\tQuery ID: " << (out_buf[2] >> 16)
  //          << "\tQuery Len: " << (out_buf[2] & 0xFFFF)
  //          << "\tThreshold: " << out_buf[3]
  //          << "\tQuery Seq: ";
  //for (int i = 0; i < ((num_query_blocks+1)*16 / 4) - 4; i++) {
  //  std::cout << out_buf[i + 4] << ' ';
  //}
  //std::cout << std::endl;
  
  pico_driver->WriteStream(stream, out_buf, (num_query_blocks+1)*16);
}*/

