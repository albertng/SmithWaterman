// MultiStream.h
//

#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>

// number of FPGAs 
#define NUM_CARDS 2
// number of bits that the division can handle in firmware
#define NUM_DIV_BITS 4 
// number of bytes to write to input stream 
// will be rounded up to nearest multiple of buffer size
#define NUM_BYTES 4096
// initial value for the divisor. If multiple FPGA's are used,
// divisor will increment by 1 for each FPGA in the chain
#define DIV 2 

// function used to print hex value to stdout
void print128(FILE *f, void *buf, int count);

// functions used by threads
void stream_output(PicoDrv* pico, int stream_handle, int divisor, bool divisible);
void stream_input(PicoDrv* pico, int stream_handle);
void* start_stream(void* arg);

// thread parameters data structure
struct StreamInfo;
