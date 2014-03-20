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
//      Albert Ng   Feb 19 2014     Added pos/neg strand

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
#include "dispatchworkerthread.h"
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
  // Set up dispatch worker threads
  dispatch_worker_threads_ = new DispatchWorkerThread*[NUM_FPGAS];
  dispatch_job_queues_ = new ThreadQueue<DispatchJob>*[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    dispatch_worker_threads_[i] = new DispatchWorkerThread[NUM_ENGINES_PER_FPGA];
    dispatch_job_queues_[i] = new ThreadQueue<DispatchJob>[NUM_ENGINES_PER_FPGA];
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      dispatch_worker_threads_[i][j].Init(pico_drivers[i], streams[i][j], &(dispatch_job_queues_[i][j]));
    }
  }
                                
  // Set up thread arguments
  args_.pico_drivers = pico_drivers;
  args_.streams = streams;
  args_.alignment_job_queue = alignment_job_queue;
  args_.engine_job_queues = engine_job_queues;
  args_.query_seq_manager = query_seq_manager;
  args_.ref_seq_manager = ref_seq_manager;
  args_.dispatch_job_queues = dispatch_job_queues_;
}

void EngineDispatchThread::Run() {
  // Run the worker threads
  for (int i = 0; i < NUM_FPGAS; i++) {
    for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
      dispatch_worker_threads_[i][j].Run();
    }
  }

  // Run the thread
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
  ThreadQueue<DispatchJob>** dispatch_job_queues = ((EngineDispatchThreadArgs*)args)->dispatch_job_queues;

  // Current scoring parameters;
  SwAffineGapParams params;
  
  struct timespec start, finish;
  double elapsed;
          
  while (true) {
    std::vector<AlignmentJob> aln_jobs = alignment_job_queue->Pop();

    long long int total_num_jobs = 0;
    long long int total_num_jobs_per_engine[NUM_FPGAS][NUM_ENGINES_PER_FPGA];
    for (int i = 0; i < NUM_FPGAS; i++) {
      for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
        total_num_jobs_per_engine[i][j] = 0;
      }
    }
    long long int total_length_per_engine[NUM_FPGAS][NUM_ENGINES_PER_FPGA];
    for (int i = 0; i < NUM_FPGAS; i++) {
      for (int j = 0; j < NUM_ENGINES_PER_FPGA; j++) {
        total_length_per_engine[i][j] = 0;
      }
    }
    
    //std::cout << aln_jobs.size() << " EngineDispatchThread alignment jobs" << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < aln_jobs.size(); i++) {
 
      AlignmentJob aln_job = aln_jobs[i];
      std::cout << "Engine Dispatch Thread job: " << aln_job.query_id 
                << " " << aln_job.ref_id
                << " " << aln_job.chr_id
                << " " << aln_job.ref_offset 
                << " " << aln_job.ref_len 
                << " " << aln_job.threshold
                << " " << aln_job.params.ToString()
                << std::endl;
              
      int query_id = aln_job.query_id;
      
      assert(query_id >= 0);
      /*if (query_id == PARAMS_JOB) {     // Set scoring params between query groups
        params = aln_job.params;
        int params_buf_len;
        int* params_buf = params.ToBuf(&params_buf_len);
        for (int j = 0; j < NUM_FPGAS; j++) {
          pico_drivers[j]->WriteDeviceAbsolute(0, (uint32_t*) params_buf, params_buf_len);
        }
        std::cout << "Wrote params " << params.ToString() << std::endl;
        delete[] params_buf;
      } else {*/
        int query_len;
        char* query_seq = query_seq_manager->GetQuerySeq(query_id, &query_len);
        int ref_id = aln_job.ref_id;
        int chr_id = aln_job.chr_id;
        long long int ref_offset = aln_job.ref_offset;
        long long int ref_len = aln_job.ref_len;
        SwAffineGapParams params = aln_job.params;
        int threshold = aln_job.threshold;
        bool pos_strand = aln_job.pos_strand;

        // Get ref seq banks that contain the requested region for this alignment
        std::vector<RefSeqManager::RefSeqBank> locs = ref_seq_manager->GetRefSeqBanks(ref_id, chr_id, ref_offset, ref_offset + ref_len);

        // Partition the banks into engine jobs
        std::vector<EngineJob> engine_jobs;
        for (std::vector<RefSeqManager::RefSeqBank>::iterator it = locs.begin(); it != locs.end(); ++it) {
          /*std::cout << "FPGA: " << it->fpga
                    << "\tStart coord: " << it->start_coord
                    << "\tEnd coord: " << it->end_coord
                    << "\tOverlap len: " << it->overlap_len
                    << "\tAddr : " << it->addr << std::endl;*/
        
          RefSeqManager::RefSeqBank loc = *it;          
            
          // Compute length of ref seq bank
          long long int refseqbank_len = (loc.end_coord - loc.start_coord) + loc.overlap_len;

          // Compute minimum job size allowable
          int min_job_len = 2*query_len >  50*REF_BLOCK_LEN ? 2*query_len : 50*REF_BLOCK_LEN;

          // Compute number of engine jobs to allocate for the alignment
          int num_jobs = refseqbank_len / min_job_len;
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
            engine_job.pos_strand     = pos_strand;

            // Compute job length
            engine_job.ref_len = (j < refseqbank_len % num_jobs) ?                      // Distribute jobs evenly
                                 (refseqbank_len / num_jobs + 1) : (refseqbank_len / num_jobs);
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
        for (int j = 0; j < engine_jobs.size(); j++) {
          EngineJob job = engine_jobs[j];
          
          DispatchJob dispatch_job;
          dispatch_job.query_id = query_id;
          dispatch_job.query_seq = query_seq;
          dispatch_job.query_len = query_len;
          dispatch_job.threshold = threshold;
          dispatch_job.num_ref_blocks = job.fpga_len;
          dispatch_job.first_ref_block = job.fpga_addr;
          dispatch_job.engine_job = job;
          
          //std::cout << "FPGA " << job.fpga_id << " Engine " << job.engine_id << " query_id " << query_id << " fpga_len " << job.fpga_len << " fpga_addr " << job.fpga_addr << std::endl;
          engine_job_queues[job.fpga_id][job.engine_id].Push(job);
          dispatch_job_queues[job.fpga_id][job.engine_id].Push(dispatch_job);
        }
      //}
    }
    
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    //std::cout << "Job loop took " << elapsed << " seconds" << std::endl;
  }
}


