//  File Name        : picodrv_stub.h
//  Description      : Pico FPGA driver stub definitions for testing
//
//  Revision History :
//      Albert Ng   Oct 10 2013     Initial Revision (dummy implementation)
//      Albert Ng   Oct 21 2013     Added WriteRam();
//      Albert Ng   Oct 29 2013     Added RunBitFile() and PicoDrv::CreateStream()

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
    
    int CreateStream(int stream);
    
    void ReadStream(int stream, uint32_t* buf, int num_bytes);

    void WriteStream(int stream, uint32_t* buf, int num_bytes);

    int WriteRam(int ref_addr, char* ref_buf, int ref_buf_length, int ddr3=PICO_DDR3_0);
    
    void WriteDeviceAbsolute(int addr, uint32_t* buf, int buf_len);
    
  private:
    int num_streams_;
    uint32_t** read_buf_;
    int* cur_index_;
    static const int READ_BUF_LENGTH = 13;
    int* jobs_outstanding_;
    pthread_mutex_t* mutex_;

    char* dram_;
    
    static const int PICO_DDR3_0 = 0;
};

char* PicoErrors_FullError(int err, char* ibuf, size_t size);

int RunBitFile(const char* bitfile_name, PicoDrv* pico);

#endif // PICODRVSTUB_H_
