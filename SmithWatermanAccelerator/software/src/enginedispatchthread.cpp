//  File Name        : enginedispatchthread.cpp
//  Description      : FPGA Engine Alignment Dispatch Thread definitions
//                     Full description in enginedispatchthread.h
//
//  Revision History :
//      Albert Ng   Oct 15 2013     Initial Revision 

#include "enginedispatchthread.h"
#include "picodrv_stub.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager_stub.h"
#include "def.h"
#include "utils.h"
#include <pthread.h>

EngineDispatchThread::EngineDispatchThread() {
}

EngineDispatchThread::EngineDispatchThread(PicoDrv* pico_drivers, int** streams,
                                           ThreadQueue<AlignmentJob>* alignment_job_queue,
                                           ThreadQueue<EngineJob>** engine_job_queues,
                                           QuerySeqManager* query_seq_manager,
                                           RefSeqManager* ref_seq_manager) {
  Init(pico_drivers, num_drivers, streams, num_streams, alignment_job_queue, engine_job_queues,
       query_seq_manager, ref_seq_manager);
}

void EngineDispatchThread::Init(PicoDrv* pico_drivers, int** streams,
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
  PicoDrv* pico_drivers = ((EngineDispatchThreadArgs*)args)->pico-drivers;
  int** streams = ((EngineDispatchThreadArgs*)args)->streams;
  ThreadQueue<AlignmentJob>* alignment_job_queue = ((EngineDispatchThreadArgs*)args)->alignment_job_queue;
  ThreadQueue<EngineJob>** engine_job_queues = ((EngineDispatchThreadArgs*)args)->engine_job_queues;
  QuerySeqManager* query_seq_manager = ((EngineDispatchThreadArgs*)args)->query_seq_manager;
  RefSeqManager* ref_seq_manager = ((EngineDispatchThreadArgs*)args)->ref_seq_manager;

  while (true) {
    AlignmentJob aln_job = alignment_job_queue.Pop();
    int query_id = aln_job.query_id;
    int query_len;
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
      int first_ref_block = ref_addr + (ref_offset / 128);
      int last_ref_block = ref_addr + ((ref_offset + ref_len - 1) / 128);
      int total_num_ref_blocks = last_ref_block - first_ref_block + 1;

      // Compute minimum job size allowable
      // Jobs must be at least 2*REF_BLOCK_SIZE or 2*query_len long, whichever is larger
      int min_job_len = query_len > REF_BLOCK_SIZE ? 2*query_len : 2*REF_BLOCK_SIZE;
      int min_job_num_blocks = 1 + min_job_len / REF_BLOCK_SIZE;
      if (min_job_len % REF_BLOCK_SIZE == 0) {
        min_job_num_blocks--;
      }

      // Compute number of blocks to overlap by for each job
      int num_overlap_blocks = 1 + (2*query_len / REF_BLOCK_SIZE);
      if ((2*query_len) % REF_BLOCK_SIZE == 0) {
        num_overlap_blocks--;
      }
      
      // Compute number of engine jobs to allocate for the alignment, and the number
      //   of reference sequence blocks each job covers (except for the last job)
      int num_jobs;
      int num_blocks_per_job;
      if ((total_num_ref_blocks / (NUM_FPGAS * NUM_ENGINES_PER_FPGA)) < min_job_num_blocks) {
        num_jobs = total_num_ref_blocks / min_job_num_blocks;
        num_blocks_per_job = min_job_num_blocks + num_overlap_blocks;
      } else {
        num_jobs = NUM_FPGAS * NUM_ENGINES_PER_FPGA;
        num_blocks_per_job = (total_num_ref_blocks / (NUM_FPGAS * NUM_ENGINES_PER_FPGA)) + 
                         num_overlap_blocks;
      }
      
      // Compute number of ref seq blocks each job covers
      int job_num_blocks[num_jobs];
      for (int i = 0; i < num_jobs; i++) {
        job_num_blocks = total_num_ref_blocks / num_jobs;
        if (i < total_num_ref_blocks % num_jobs) {
          job_num_blocks++;
        }
        if (i != num_jobs - 1) {
          job_num_blocks += num_overlap_blocks;
        }
      }

      // Dispatch and record the jobs
      int cur_fpga = 0;
      int cur_engine = 0;
      int cur_ref_block = first_ref_block;
      for (int i = 0; i < num_jobs; i++) {
        DispatchJob(&(pico_drivers[cur_fpga]), streams[cur_fpga][cur_engine],
                    query_id, query_seq, query_len,
                    job_num_blocks[i], cur_ref_block,
                    threshold);
        RecordEngineJob(&(engine_job_queues[cur_fpga][cur_engine]),
                        query_id, query_len,
                        ref_id, ref_offset, ref_len + num_overlap_blocks*REF_BLOCK_SIZE,
                        ref_offset + ref_len,
                        threshold);

        cur_fpga++;
        if (cur_fpga == NUM_FPGAS) {
          cur_fpga = 0;
          cur_engine++;
          if (cur_engine == NUM_ENGINES_PER_FPGA) {
            cur_engine = 0;
          }
        }
        cur_ref_block += (job_num_blocks[i] - num_overlap_blocks);
      }
    }
  }
}

static void EngineDispatchThread::DispatchJob(PicoDrv* pico_driver, int stream,
                                              int query_id, char* query_seq, int query_len,
                                              int num_ref_blocks, int first_ref_block,
                                              int threshold) {
  uint32_t out_buf[4096];

  out_buf[0] = (uint32_t) num_ref_blocks;
  out_buf[1] = (uint32_t) first_ref_block;
  out_buf[2] = (uint32_t) ((query_id << 16) + (query_len));
  out_buf[3] = (uint32_t) threshold;

  int num_query_blocks;
  for (int i = 0; i < query_len; i++) {
    if (i % 16 == 0) {
      out_buf[4+i/16] = NtChar2Int(query_seq[i]);
      num_query_blocks++;
    } else {
      out_buf[4+i/16] += (NtChar2Int(query_seq[i]) << (2 * (i % 16)));
    }
  }
  
  pico_driver->WriteStream(stream, out_buf, (num_query_blocks+1)*16);
}

static void EngineDispatchThread::RecordEngineJob(ThreadQueue<EngineJob>* engine_job_queue,
                                                  int query_id, int query_len,
                                                  int ref_id, int ref_offset, int ref_len,
                                                  int overlap_offset,
                                                  int threshold) {
  EngineJob job;
  job.query_id = query_id;
  job.query_len = query_len;
  job.ref_id = ref_id;
  job.ref_offset = ref_offset;
  job.ref_len = ref_len;
  job.overlap_offset = overlap_offset;
  job.threshold = threshold;

  engine_job_queue->Push(job);
}
