//  File Name        : picodrv_stub.cpp
//  Description      : Pico FPGA drive stub definitions for testing
//
//  Revision History :
//      Albert Ng   Oct 10 2013     Initial Revision (dummy implementation)
//      Albert Ng   Oct 21 2013     Added WriteRam() and dram_
//      Albert Ng   Oct 29 2013     Added RunBitFile() and PicoDrv::CreateStream()

#include "picodrv_stub.h"
#include "def.h"
#include <stdint.h>
#include <pthread.h>
#include <string.h>

#include <iostream>

PicoDrv::PicoDrv() {
}

void PicoDrv::Init(int num_streams) {
  num_streams_ = num_streams;
  read_buf_ = new uint32_t* [num_streams];
  cur_index_ = new int [num_streams];
  for (int i = 0; i < num_streams; i++) {
    read_buf_[i] = new uint32_t [READ_BUF_LENGTH];

    read_buf_[i][0] = 0;
    read_buf_[i][1] = 1;
    read_buf_[i][2] = 0xFFFFFFFF;
    read_buf_[i][3] = 1;
    read_buf_[i][4] = 0xFFFFFFFF;
    read_buf_[i][5] = 0;
    read_buf_[i][6] = 0xFFFFFFFF;
    read_buf_[i][7] = 0;
    read_buf_[i][8] = 1;
    read_buf_[i][9] = 0xFFFFFFFF;
    read_buf_[i][10] = 0;
    read_buf_[i][11] = 1;
    read_buf_[i][12] = 0xFFFFFFFF;

    cur_index_[i] = 0;
  }

  jobs_outstanding_ = new int[num_streams];
  for (int i = 0; i < num_streams; i++) {
    jobs_outstanding_[i] = 0;
  }

  mutex_ = new pthread_mutex_t[num_streams];
  for (int i = 0; i < num_streams; i++) {
    pthread_mutex_init(&(mutex_[i]), NULL);
  }

  dram_ = new char[1048576];
}

PicoDrv::~PicoDrv() {
  for (int i = 0; i < num_streams_; i++) {
    delete[] read_buf_[i];
  }
  delete[] read_buf_;
  delete[] cur_index_;
  delete[] jobs_outstanding_;
}

int PicoDrv::GetBytesAvailable(int stream, bool read) {
  pthread_mutex_lock(&(mutex_[stream]));
  //std::cout<<"Locked Mutex "<<&(mutex_[stream])<<std::endl;
  int num_bytes_available = (jobs_outstanding_[stream] > 0) ? (READ_BUF_LENGTH - cur_index_[stream]) * 16 : 0;
  //std::cout<<"Unlocking Mutex "<<&(mutex_[stream])<<std::endl;
  pthread_mutex_unlock(&mutex_[stream]);
  return num_bytes_available > 16 ? 16 : num_bytes_available;
}

int PicoDrv::CreateStream(int stream) {
  if (stream > NUM_ENGINES_PER_FPGA) {
    return -1;
  }
  
  return stream-1;
}

void PicoDrv::ReadStream(int stream, uint32_t* buf, int num_bytes) {
  pthread_mutex_lock(&(mutex_[stream]));
  //std::cout<<"Readstream Mutex locked"<<&(mutex_[stream])<<std::endl;
  int num_bytes_to_read = cur_index_[stream] + (num_bytes / 16) > READ_BUF_LENGTH ?
                            (READ_BUF_LENGTH - cur_index_[stream])*16 : num_bytes;
  for (int i = 0; i < num_bytes_to_read/16; i++) {
    buf[i] = read_buf_[stream][cur_index_[stream]];
    if (buf[i] == 0xFFFFFFFF) {
      jobs_outstanding_[stream]--;
    }
    cur_index_[stream]++;
  }
  //std::cout<<"ReadStream Unlocking Mutex "<<&(mutex_[stream])<<std::endl;
  pthread_mutex_unlock(&(mutex_[stream]));
}

void PicoDrv::WriteStream(int stream, uint32_t* buf, int num_bytes) {
  if (num_bytes < 16) {
    std::cout << "Writing to stream with less than a full packet!" << std::endl;
    return;
  }
  
  /*std::cout << "Engine job for stream " << stream
            <<"\tNum Ref Blocks: " << buf[0]
            << "\tRef Block Offset: " << buf[1]
            << "\tQuery ID: " << (buf[2] >> 16)
            << "\tQuery Len: " << (buf[2] & 0xFFFF)
            << "\tThreshold: " << buf[3]
            << "\tQuery Seq: ";
  for (int i = 0; i < (num_bytes / 4) - 4; i++) {
    std::cout << buf[i + 4] << ' ';
  }
  std::cout << std::endl;*/
  
  pthread_mutex_lock(&(mutex_[stream]));
  //std::cout<<"Writestream Mutex locked"<<&(mutex_[stream])<<std::endl;
  jobs_outstanding_[stream]++;
  //std::cout<<"WriteStream Unlocking Mutex "<<&(mutex_[stream])<<std::endl;
  pthread_mutex_unlock(&(mutex_[stream]));
}

int PicoDrv::WriteRam(int ref_addr, char* ref_buf, int ref_buf_length, int ddr) {
  std::cout << "Writing to FPGA DRAM at block " << ref_addr << ": ";
  for (int i = 0; i < ref_buf_length; i++) {
    std::cout << (((uint32_t) ref_buf[i]) & 0xFF) << " ";
  }
  std::cout << '\n' << std::endl;
}

void PicoDrv::WriteDeviceAbsolute(int addr, uint32_t* buf, int buf_len) {
  /*std::cout << "Writing to absolute address " << addr << ":\n";
  for (int i = 0; i < buf_len/4; i++) {
    std::cout << buf[i] << " ";
  }
  std::cout << std::endl;*/
}

char* PicoErrors_FullError(int err, char* ibuf, size_t size) {
  std::string error_str = "Dummy Error!";
  ibuf[error_str.size()] = 0;
  memcpy(ibuf, error_str.c_str(), error_str.size());
  return ibuf;
}

int RunBitFile(const char* bitfile_name, PicoDrv* pico) {
  pico->Init(NUM_ENGINES_PER_FPGA);
}






