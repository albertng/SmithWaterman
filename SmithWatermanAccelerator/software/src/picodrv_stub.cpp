//  File Name        : picodrv_stub.cpp
//  Description      : Pico FPGA drive stub definitions for testing
//
//  Revision History :
//      Albert Ng   Oct 10 2013     Initial Revision (dummy implementation)
//

#include "picodrv_stub.h"
#include <stdint.h>
#include <pthread.h>

#include <iostream>

PicoDrv::PicoDrv() {
}

PicoDrv::PicoDrv(int num_streams) {
  Init(num_streams);
}

void PicoDrv::Init(int num_streams) {
  num_streams_ = num_streams;
  read_buf_ = new uint32_t* [num_streams];
  cur_index_ = new int [num_streams];
  for (int i = 0; i < num_streams; i++) {
    read_buf_[i] = new uint32_t [READ_BUF_LENGTH];

    read_buf_[i][0] = 0;
    read_buf_[i][1] = 2;
    read_buf_[i][2] = 3;
    read_buf_[i][3] = 5;
    read_buf_[i][4] = 0xFFFFFFFF;
    read_buf_[i][5] = 0;
    read_buf_[i][6] = 1;
    read_buf_[i][7] = 3;
    read_buf_[i][8] = 7;
    read_buf_[i][9] = 0xFFFFFFFF;
    read_buf_[i][10] = 3;
    read_buf_[i][11] = 5;
    read_buf_[i][12] = 7;
    read_buf_[i][13] = 9;
    read_buf_[i][14] = 0xFFFFFFFF;
    read_buf_[i][15] = 1;
    read_buf_[i][16] = 2;
    read_buf_[i][17] = 3;
    read_buf_[i][18] = 4;
    read_buf_[i][19] = 0xFFFFFFFF;
    read_buf_[i][20] = 0;
    read_buf_[i][21] = 2;
    read_buf_[i][22] = 3;
    read_buf_[i][23] = 4;
    read_buf_[i][24] = 0xFFFFFFFF;

    cur_index_[i] = 0;
  }

  mutex_ = new pthread_mutex_t[num_streams];
  for (int i = 0; i < num_streams; i++) {
    std::cout<<"Init Mutex "<<i<<" "<<&(mutex_[i])<<std::endl;
    pthread_mutex_init(&(mutex_[i]), NULL);
  }
}

PicoDrv::~PicoDrv() {
  for (int i = 0; i < num_streams_; i++) {
    delete[] read_buf_[i];
  }
  delete[] read_buf_;
  delete[] cur_index_;
}

int PicoDrv::GetBytesAvailable(int stream, bool read) {
//  std::cout<<"In getbytesavailable stream: "<<stream<<std::endl;
//  std::cout<<"Checking mutex "<<&(mutex_[stream])<<std::endl;
  pthread_mutex_lock(&(mutex_[stream]));
//  std::cout<<"After mutex lock"<<std::endl;
  int num_bytes_available = (READ_BUF_LENGTH - cur_index_[stream]) * 16;
  pthread_mutex_unlock(&(mutex_[stream]));
//  std::cout<<"Unlocked mutex "<<&(mutex_[stream])<<std::endl;
  return num_bytes_available > 16 ? 16 : num_bytes_available;
}

void PicoDrv::ReadStream(int stream, uint32_t* buf, int num_bytes) {
//  std::cout<<"In readstream stream:"<<stream<<std::endl;
//  std::cout<<"Checking mutex "<<&(mutex_[stream])<<std::endl;
  pthread_mutex_lock(&(mutex_[stream]));
//  std::cout<<"After mutex lock"<<std::endl;
  int num_bytes_to_read = cur_index_[stream] + (num_bytes / 16) > READ_BUF_LENGTH ?
                            (READ_BUF_LENGTH - cur_index_[stream])*16 : num_bytes;
  for (int i = 0; i < num_bytes_to_read/16; i++) {
    buf[i] = read_buf_[stream][cur_index_[stream]];
    cur_index_[stream]++;
  }
  pthread_mutex_unlock(&(mutex_[stream]));
//  std::cout<<"Unlocked mutex "<<&(mutex_[stream])<<std::endl;
}

