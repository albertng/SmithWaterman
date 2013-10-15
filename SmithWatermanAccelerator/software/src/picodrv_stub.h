//  File Name        : picodrv_stub.h
//  Description      : Pico FPGA driver stub definitions for testing
//
//  Revision History :
//      Albert Ng   Oct 10 2013     Initial Revision (dummy implementation)
//

#ifndef PICODRVSTUB_H_
#define PICODRVSTUB_H_

#include <stdint.h>
#include <pthread.h>

class PicoDrv {
  public:
    PicoDrv();
    PicoDrv(int num_streams);
    ~PicoDrv();

    void Init(int num_streams);

    int GetBytesAvailable(int stream, bool read);

    void ReadStream(int stream, uint32_t* buf, int num_bytes);

  private:
    int num_streams_;
    uint32_t** read_buf_;
    int* cur_index_;
    static const int READ_BUF_LENGTH = 25;

    pthread_mutex_t* mutex_;
};

#endif // PICODRVSTUB_H_
