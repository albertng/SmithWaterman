//  File Name        : enginedispatchthread.cpp
//  Description      : FPGA Engine Alignment Dispatch Thread definitions
//                     Full description in enginedispatchthread.h
//
//  Revision History :
//      Albert Ng   Oct 15 2013     Initial Revision 
//      Albert Ng   Oct 16 2013     Debugged initial version
//      Albert Ng   Oct 22 2013     Added SwAffineGapParams to AlignmentJob and EngineJob
//                                  Set scoring params between query groups

#include "enginedispatchthread.h"
#include "picodrv.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "def.h"
#include "utils.h"
#include "scoring.h"
#include <pthread.h>
#include <stdlib.h>

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
  
  while (true) {
    AlignmentJob aln_job = alignment_job_queue->Pop();
    //std::cout<<"Engine Dispatch Thread job: "<<aln_job.query_id<< " "<<aln_job.ref_id<<" "<<aln_job.ref_offset<<" "<<aln_job.ref_len<<" "<<aln_job.threshold<<" "<<aln_job.params.ToString()<<std::endl;
    int query_id = aln_job.query_id;
    int query_len;
    
    if (query_id == PARAMS_JOB) {     // Set scoring params between query groups
      params = aln_job.params;
      int params_buf_len;
      int* params_buf = params.ToBuf(&params_buf_len);
      for (int i = 0; i < NUM_FPGAS; i++) {
        pico_drivers[i]->WriteDeviceAbsolute(0, (uint32_t*) params_buf, params_buf_len);
      }
    } else {
      char* query_seq = query_seq_manager->GetQuerySeq(query_id, &query_len);
      int ref_id = aln_job.ref_id;
      long long int ref_offset = aln_job.ref_offset;
      long long int ref_len = aln_job.ref_len;
      int threshold = aln_job.threshold;

      if (query_len > MAX_QUERY_LEN) {
        std::cerr << "Error: Query length " << query_len << " exceeds max query length of " << MAX_QUERY_LEN 
                  << std::endl;
      } else {
        // Compute first block index and total number of blocks spanned by reference sequence
        int ref_addr = ref_seq_manager->GetRefAddr(ref_id);
        int first_ref_block = ref_addr + (ref_offset / REF_BLOCK_LEN);
        int last_ref_block = ref_addr + ((ref_offset + ref_len - 1) / REF_BLOCK_LEN);
        int total_num_ref_blocks = last_ref_block - first_ref_block + 1;

        // Compute minimum job size allowable
        // Jobs must be at least 2*REF_BLOCK_LEN or 2*query_len long, whichever is larger
        int min_job_len = query_len > REF_BLOCK_LEN ? 2*query_len : 2*REF_BLOCK_LEN;
        int min_job_num_blocks = 1 + min_job_len / REF_BLOCK_LEN;
        if (min_job_len % REF_BLOCK_LEN == 0) {
          min_job_num_blocks--;
        }

        // Compute number of blocks to overlap by for each job
        int num_overlap_blocks = 1 + (2*query_len / REF_BLOCK_LEN);
        if ((2*query_len) % REF_BLOCK_LEN == 0) {
          num_overlap_blocks--;
        }
        
        // Compute number of engine jobs to allocate for the alignment and the number of ref seq
        //   blocks each job spans
        int num_jobs;
        if ((total_num_ref_blocks / (NUM_FPGAS * NUM_ENGINES_PER_FPGA)) < min_job_num_blocks) {
          num_jobs = total_num_ref_blocks / min_job_num_blocks;
          num_jobs = (num_jobs == 0) ? 1 : num_jobs;
        } else {
          num_jobs = NUM_FPGAS * NUM_ENGINES_PER_FPGA;
        }
        query_seq_manager->SetQueryNumJobs(query_id, num_jobs);
        //std::cout<<"Num FPGAS: "<<NUM_FPGAS<<" Num Engines per FPGA: "<< NUM_ENGINES_PER_FPGA<< " Min Job Num Blocks: " << min_job_num_blocks<<" Total Num Ref Blocks " << total_num_ref_blocks<< " Num jobs: "<<num_jobs<<std::endl;
        // Compute the nucleotide length and number of ref seq blocks each job spans
        int job_num_blocks[num_jobs];
        long long int job_length[num_jobs];
        for (int i = 0; i < num_jobs; i++) {
          job_num_blocks[i] = total_num_ref_blocks / num_jobs;  // Evenly distribute over all jobs
          if (i < total_num_ref_blocks % num_jobs) {  
            job_num_blocks[i]++;
          }
          if (i != num_jobs-1) {                                // Add overlap for all jobs except last one
            job_num_blocks[i] += num_overlap_blocks;
          }
          job_num_blocks[i] = job_num_blocks[i] < min_job_num_blocks ? min_job_num_blocks : job_num_blocks[i];
          
          job_length[i] = job_num_blocks[i] * REF_BLOCK_LEN;
          if (i == 0) {               // Trim left end
            job_length[i] -= (ref_offset % REF_BLOCK_LEN);
          } 
          if (i == num_jobs - 1) {    // Trim right end
            if ((ref_offset + ref_len) % REF_BLOCK_LEN != 0) {
              job_length[i] -= (REF_BLOCK_LEN - ((ref_offset + ref_len) % REF_BLOCK_LEN));
            }
            if (total_num_ref_blocks < min_job_num_blocks) {
              job_length[i] -= ((min_job_num_blocks - total_num_ref_blocks) * REF_BLOCK_LEN);
            }
          }
        }
        
        // Compute the nucleotide offset and ref seq block offset of each job
        long long int job_offset[num_jobs];
        int job_block_offset[num_jobs];
        int cur_block = first_ref_block;
        for (int i = 0; i < num_jobs; i++) {
          job_block_offset[i] = cur_block;
          
          if (i == 0) {
            job_offset[i] = ref_offset;
          } else {
            job_offset[i] = ((long long int) cur_block) * REF_BLOCK_LEN;
          }
          
          cur_block += (job_num_blocks[i] - num_overlap_blocks);
        }
        
        // Compute the nucleotide offset of the overlap regions of each job
        long long int job_overlap_offset[num_jobs];
        for (int i = 0; i < num_jobs-1; i++) {
          job_overlap_offset[i] = job_offset[i+1];
        }
        job_overlap_offset[num_jobs-1] = job_offset[num_jobs-1] + job_length[num_jobs-1];

        // Dispatch and record the jobs
        int cur_fpga = 0;
        int cur_engine = 0;
        //std::cout<<"Dispatching "<<num_jobs<<" jobs"<<std::endl;
        for (int i = 0; i < num_jobs; i++) {
          //std::cout<<"Cur FPGA: "<<cur_fpga<<" Cur engine: "<<cur_engine<<std::endl;
          DispatchJob(pico_drivers[cur_fpga], streams[cur_fpga][cur_engine],
                      query_id, query_seq, query_len,
                      job_num_blocks[i], job_block_offset[i],
                      threshold);
          RecordEngineJob(&(engine_job_queues[cur_fpga][cur_engine]),
                          query_id, query_len,
                          ref_id, job_length[i], job_offset[i],
                          job_overlap_offset[i],
                          threshold, params);

          cur_fpga++;
          if (cur_fpga == NUM_FPGAS) {
            cur_fpga = 0;
            cur_engine++;
            if (cur_engine == NUM_ENGINES_PER_FPGA) {
              cur_engine = 0;
            }
          }
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

  int num_query_blocks = 0;
  for (int i = 0; i < query_len; i++) {
    NtInt nt = NtChar2Int(query_seq[i]);
    if (query_seq[i] == 'N') {
      nt = rand() % 4;
    }
    if (i % 16 == 0) {
      out_buf[4+i/16] = nt;
      num_query_blocks++;
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

void EngineDispatchThread::RecordEngineJob(ThreadQueue<EngineJob>* engine_job_queue,
                                           int query_id, int query_len,
                                           int ref_id, int ref_len, int ref_offset,
                                           int overlap_offset,
                                           int threshold, SwAffineGapParams params) {
  EngineJob job;
  job.query_id = query_id;
  job.query_len = query_len;
  job.ref_id = ref_id;
  job.ref_offset = ref_offset;
  job.ref_len = ref_len;
  job.overlap_offset = overlap_offset;
  job.threshold = threshold;
  job.params = params;

  //std::cout<<"Recorded Job:\tQuery ID:"<<job.query_id<<" Query Len: "<<job.query_len<<" Ref ID: "<<job.ref_id<<" Ref Offset: "<<job.ref_offset<<" Ref Len: "<<job.ref_len<<" Overlap Offset: "<<job.overlap_offset<<" Threshold: "<<job.threshold<<std::endl;

  engine_job_queue->Push(job);
}
