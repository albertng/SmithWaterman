//  File Name        : picodrv_stub.cpp
//  Description      : Pico FPGA drive stub definitions for testing
//
//  Revision History :
//      Albert Ng   Oct 10 2013     Initial Revision (dummy implementation)
//

#include "picodrv_stub.h"
#include <stdint.h>

PicoDrv::PicoDrv() {
}

PicoDrv::PicoDrv(int num_streams) {
  Init(num_streams);
}

void PicoDrv::Init(int num_streams) {
  num_streams_ = num_streams;
  read_buf_ = new uint32_t*[num_streams];
  cur_index_ = new int[num_streams];
  for (int i = 0; i < num_streams; i++) {
    read_buf_[i] = new uint32_t[READ_BUF_LENGTH];
    for (int j = 0; j < READ_BUF_LENGTH; j++) {
      read_buf_[i][j] = 0;
    }

    read_buf_[i][0] = 0;
    read_buf_[i][4] = 2;
    read_buf_[i][8] = 3;
    read_buf_[i][12] = 5;
    read_buf_[i][16] = 0xFFFFFFFF;

    cur_index_[i] = 0;
  }
}

PicoDrv::~PicoDrv() {
  for (int i = 0; i < num_streams_; i++) {
    delete[] read_buf_[i];
  }
  delete[] read_buf_;
  delete[] cur_index[];
}

int PicoDrv::GetBytesAvailable(int stream, bool read) {
  int num_bytes_available = (READ_BUF_LENGTH - cur_index) * 4;
  return num_bytes_available > 16 ? 16 : num_bytes_available;
}

void ReadStream(int stream, uint32_t* buf, int num_bytes) {
  int num_bytes_to_read = cur_index_[stream] + (num_bytes / 4) > READ_BUF_LENGTH ?
                            (READ_BUF_LENGTH - cur_index_[stream])*4 : num_bytes;
  for (int i = 0; i < num_bytes_to_read/4; i++) {
    buf[i] = read_buf_[stream][cur_index_[stream]];
    cur_index_[stream]++;
  }
}
