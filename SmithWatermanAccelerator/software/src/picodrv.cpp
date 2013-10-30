//  File Name        : picodrv.cpp
//  Description      : Simulated Pico FPGA driver
//
//  Revision History :
//      Albert Ng   Oct 29 2013     Initial Revision

#include "picodrv.h"
#include "utils.h"
#include <assert.h>
#include <cstring>

PicoDrv::PicoDrv() {
  dram_ = new char[DRAM_SIZE];
  
  args_.query_job_queue = &query_job_queue_;
  args_.high_score_block_queues = &high_score_block_queues_;
  args_.dram = dram_;
  args_.params = &params_;
  
  pthread_create(&thread_, NULL, &PicoDrv::RunEngines, (void*) (&args_));
}

PicoDrv::~PicoDrv() {
  delete[] dram_;
}

int PicoDrv::WriteDeviceAbsolute(int addr, const void* buf, int size) {
  assert(size == SW_PARAMS_BUF_LENGTH * sizeof(int));
  
  int sub_mat[4][4];
  int* buf_i = (int*) buf;
  sub_mat[A_NT][A_NT] = buf_i[0];
  sub_mat[A_NT][C_NT] = buf_i[1];
  sub_mat[A_NT][G_NT] = buf_i[2];
  sub_mat[A_NT][T_NT] = buf_i[3];
  sub_mat[C_NT][C_NT] = buf_i[4];
  sub_mat[C_NT][G_NT] = buf_i[5];
  sub_mat[C_NT][T_NT] = buf_i[6];
  sub_mat[G_NT][G_NT] = buf_i[7];
  sub_mat[G_NT][T_NT] = buf_i[8];
  sub_mat[T_NT][T_NT] = buf_i[9];
  int gap_open = buf_i[10];
  int gap_extend = buf_i[11];
  
  // Fill other half of matrix
  sub_mat[C_NT][A_NT] = sub_mat[A_NT][C_NT];
  sub_mat[G_NT][A_NT] = sub_mat[A_NT][G_NT];
  sub_mat[G_NT][C_NT] = sub_mat[C_NT][G_NT];
  sub_mat[T_NT][A_NT] = sub_mat[A_NT][T_NT];
  sub_mat[T_NT][C_NT] = sub_mat[C_NT][T_NT];
  sub_mat[T_NT][G_NT] = sub_mat[G_NT][T_NT];
  
  SwAffineGapParams params(sub_mat, gap_open, gap_extend);
  params_ = params;
}

int PicoDrv::CreateStream(int streamNum) {
  assert(streamNum <= NUM_ENGINES_PER_FPGA && streamNum > 0);
  
  return streamNum - 1;
}

int PicoDrv::ReadStream(int streamHandle, void* buf, int size) {
  assert(streamHandle < NUM_ENGINES_PER_FPGA);
  assert(size % 16 == 0);

  for (int i = 0; i < size/16; i++) {
    HighScoreBlock hsb = high_score_block_queues_[streamHandle].Pop();
    ((int*) buf)[i*4] = hsb.high_score_block;
    ((int*) buf)[i*4 + 1] = hsb.query_id;
  }
}

int PicoDrv::WriteStream(int streamHandle, const void* buf, int size) {
  assert(size > 16);
  assert(size % 16 == 0);
  
  // Grab query metadata
  uint32_t* buf_i = (uint32_t*) buf;
  uint32_t num_ref_blocks = buf_i[0];
  uint32_t first_ref_block = buf_i[1];
  uint32_t query_id = buf_i[2] >> 16;
  uint32_t query_len = buf_i[2] & 0xFFFF;
  uint32_t threshold = buf_i[3];
  
  /*for (int i = 0; i < size/4; i++) {
    std::cout<<buf_i[i] << " ";
  }
  std::cout << std::endl;*/
  
  // Check query length is correct
  int num_query_blocks = query_len / QUERY_BLOCK_LEN;
  if (query_len % QUERY_BLOCK_LEN != 0) {
    num_query_blocks++;
  }
  assert(size == (num_query_blocks + 1)*16);
  
  // Grab query sequence and convert to NtInt array
  char* query_seq = new char[query_len];
  for (int i = 0; i < query_len; i++) {
    query_seq[i] = NtInt2Char((buf_i[4 + i/16] >> ((i % 16)*2)) & 0x3);
  }
  
  // Store query job onto queue
  QueryJob job;
  job.num_ref_blocks = num_ref_blocks;
  job.first_ref_block = first_ref_block;
  job.query_id = query_id;
  job.query_len = query_len;
  job.threshold = threshold;
  job.query_seq = query_seq;
  job.stream_num = streamHandle;
  query_job_queue_.Push(job);
  
  /*std::cout << "Num ref blocks: " << num_ref_blocks
            << " First ref block: " << first_ref_block
            << " Query ID: " << query_id
            << " Query Length: " << query_len
            << " Threshold: " << threshold
            << " Query Seq: ";
  for (int i = 0; i < query_len; i++) {
    std::cout << query_seq[i];
  }
  std::cout << std::endl;*/
}

int PicoDrv::GetBytesAvailable(int streamHandle, bool isRead) {
  assert(streamHandle < NUM_ENGINES_PER_FPGA);
  
  if (isRead) {
    return high_score_block_queues_[streamHandle].Size() * 16;
  } else {
    return 512;
  }
}

int PicoDrv::WriteRam(uint64_t addr, const void* buf, int size, int memID) {
  assert((addr + size) < DRAM_SIZE);
  assert(memID == PICO_DDR3_0);
  
  for (int i = 0; i < size*4; i++) {
    dram_[addr*4 + i] = NtInt2Char((((char*) buf)[i/4] >> ((i%4)*2)) & 0x3);
  }
  return size;
}

int RunBitFile(const char *bitFilePath, PicoDrv **drvpp) {
  PicoDrv* pico = new PicoDrv;
  *drvpp = pico;
}

char* PicoErrors_FullError(int err, char* ibuf, size_t size) {
  std::string error_str = "Dummy Error!";
  ibuf[error_str.size()] = 0;
  memcpy(ibuf, error_str.c_str(), error_str.size());
  return ibuf;
}

void* PicoDrv::RunEngines(void* args) {
  // Get thread arguments
  ThreadQueue<QueryJob>* query_job_queue = ((PicoDrvThreadArgs*)args)->query_job_queue;
  ThreadQueue<HighScoreBlock> (*high_score_block_queues)[NUM_ENGINES_PER_FPGA] = ((PicoDrvThreadArgs*)args)->high_score_block_queues;
  char* dram = ((PicoDrvThreadArgs*)args)->dram;
  SwAffineGapParams* params = ((PicoDrvThreadArgs*)args)->params;
  
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  int gap_open;
  int gap_extend;
  
  while (true) {
    QueryJob job = query_job_queue->Pop();
    
    int ref_len = job.num_ref_blocks * REF_BLOCK_LEN;
    int query_len = job.query_len;
    char* ref_seq = &(dram[job.first_ref_block * REF_BLOCK_LEN]);
    char* query_seq = job.query_seq;
    int** v_matrix = new int*[ref_len + 1];
    int** e_matrix = new int*[ref_len + 1];
    int** f_matrix = new int*[ref_len + 1];
    for (int i = 0; i < ref_len + 1; i++) {
      v_matrix[i] = new int[query_len + 1];
      e_matrix[i] = new int[query_len + 1];
      f_matrix[i] = new int[query_len + 1];
      for (int j = 0; j < query_len + 1; j++) {
        v_matrix[i][j] = 0;
        e_matrix[i][j] = 0;
        f_matrix[i][j] = 0;
      }
    }
    
    params->GetSubMat(sub_mat);
    gap_open = params->GetGapOpen();
    gap_extend = params->GetGapExtend();
    
    // Compute dynamic programming matrices
    bool high_score_block;
    for (int i = 1; i < ref_len + 1; i++) {
      for (int j = 1; j < query_len + 1; j++) {
        if ((i - 1) % REF_BLOCK_LEN == 0 && j == 1) {
          high_score_block = false;
        }
      
        NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
        NtInt query_nt = NtChar2Int(query_seq[j-1]); 
        assert(ref_nt < 4);
        assert(query_nt < 4);
        
        // Compute possible choices
        int match = v_matrix[i-1][j-1] + sub_mat[query_nt][ref_nt];
        int ins_open   = v_matrix[i-1][j] + gap_open;
        int ins_extend = e_matrix[i-1][j] + gap_extend;
        int del_open   = v_matrix[i][j-1] + gap_open;
        int del_extend = f_matrix[i][j-1] + gap_extend;
        
        // Pick choice with highest score
        e_matrix[i][j] = (ins_open > ins_extend) ? ins_open : ins_extend;
        f_matrix[i][j] = (del_open > del_extend) ? del_open : del_extend;
        int max1;
        if (match > e_matrix[i][j]) {
          max1 = match;
        } else {
          max1 = e_matrix[i][j];
        }
        int max2;
        if (f_matrix[i][j] > 0) {
          max2 = f_matrix[i][j];
        } else {
          max2 = 0;
        }
        if (max1 > max2) {
          v_matrix[i][j] = max1;
        } else {
          v_matrix[i][j] = max2;
        }
  
        // Store HSB onto queue if score is above threshold
        if (v_matrix[i][j] >= job.threshold && high_score_block == false) {
          HighScoreBlock hsb;
          hsb.high_score_block = (i - 1) / REF_BLOCK_LEN;
          hsb.query_id = job.query_id;
          (*high_score_block_queues)[job.stream_num].Push(hsb);
          high_score_block = true;
          
          //std::cout<<"High score block: "<<hsb.high_score_block<<" Query ID: "<<hsb.query_id<<std::endl;
        }
      }
    }
    
    // Store End-of-engine-alignment token onto HSB queue
    HighScoreBlock hsb;
    hsb.high_score_block = END_OF_ENGINE_ALIGNMENT;
    hsb.query_id = job.query_id;
    (*high_score_block_queues)[job.stream_num].Push(hsb);
    //std::cout<<"End of Alignment Query ID: "<<hsb.query_id<<std::endl;
  }
}
          
          
          
