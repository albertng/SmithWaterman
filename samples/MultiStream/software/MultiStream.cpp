/*===================================================================================
 File: MultiStream.cpp.

 This program is designed to illustrate how to use the Pico stream interfaces. 
 It shows how to interface with the module implemented in the FPGA firmware and how 
 to communicate to multiple streams in parallel using the pthreads library.

 This program interfaces with the firmware kernel MultiStream.v in the sister directory.

=====================================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>
#include <pthread.h>
#include <MultiStream.h>

// buffer size used by PicoDrv to read and write from stream
#define BUF_SIZE 1024
// mask used for division
#define DIV_MASK (~(~0 << NUM_DIV_BITS))

// global variables shared between threads
unsigned long int total_read;
unsigned long int total_write;
bool              done_writing;
pthread_mutex_t   mutex;

// struct containing thread parameters
typedef struct StreamInfo{
    PicoDrv* pico;
    int stream_handle; 
    int divisor;       // divisor for the pico card, used to check values on output stream
    bool divisible;    // true if it is divisible stream (stream #2)
    bool is_input;     // true if an input stream 
} StreamInfo;

// print <count> 128-bit numbers from buf
void print128(FILE *f, void *buf, int count) {
    uint32_t *u32p = (uint32_t*) buf;
    for (int i=0; i < count; ++i)
        fprintf(f, "0x%x_%x_%x_%x\n", u32p[4*i+3], u32p[4*i+2], u32p[4*i+1], u32p[4*i]);
}

// function called by the output thread which reads numbers from the output stream until
// input stream is done writing
void stream_output(PicoDrv* pico, int stream_handle, int divisor, bool divisible) {
    uint32_t    buf[BUF_SIZE];
    int i,err,read_size;
    if (!divisible) printf("Reading non-divisible values\n");
    // while total_read less than total_write or input thread is not done writing
    while ((total_read < total_write) || !done_writing)  {
        read_size = pico->GetBytesAvailable(stream_handle, true);
        // only read as much room as we have in buf
        if (read_size > sizeof(buf)) {
            read_size = sizeof(buf);
        }
        err = pico->ReadStream(stream_handle, buf, read_size);
        if (err != read_size) {
            fprintf(stderr, "read error. returned %i, but should have been %d\n", err, read_size);
            exit(1);
        }
        // make sure all of the integers in buf were on the correct stream
        for (i = 0; i < read_size/4; i+=4) {    
            if (((buf[i] & DIV_MASK) % divisor == 0) != divisible) {
                printf("unexpected value %d found\n",buf[i]);
                exit(1);
            }
        }
        // update total_read to reflect the read that has been completed
        pthread_mutex_lock(&mutex);
        total_read += err;
        pthread_mutex_unlock(&mutex);
        // print out final "prime" values off non divisible stream
        if (!divisible && NUM_BYTES < (1<<23)) {
            print128(stdout, buf, read_size/16);
        }
    }
}

// thread that handles writing sequence of numbers to input stream
void stream_input(PicoDrv* pico, int stream_handle) {
    uint32_t    buf[BUF_SIZE];
    int i, j, n, err;
    int next_num;
    // write values to input stream  
    for (i=0; i < (NUM_BYTES+sizeof(buf)-1)/(sizeof(buf)); i++) {
        // fill the buffer with sequential numbers we'll recognize when it comes back.
        for (j=0; j < BUF_SIZE; j++) {
            next_num = (j+(i*BUF_SIZE))/4;
            buf[j]= (j%4 == 0) ? next_num : 0;
        }
        err = pico->WriteStream(stream_handle, buf, sizeof(buf));
        if (err != sizeof(buf)) {
            fprintf(stderr, "write error. returned %i, but should have been %i\n", err, BUF_SIZE);
            exit(1);
        }
        total_write += err;
    }
    // set done_writing flag to let other threads know that no more data will be written
    printf("Wrote %lu B\n", total_write);
    done_writing = true;
}

// start a new thread
void* start_stream(void* arg) {
    StreamInfo* info = (StreamInfo*) arg;
    if (info->is_input) {
        // if first card in the chain, start a thread to stream initial values
        printf("input stream thread started with stream handle %d\n",info->stream_handle);
        stream_input(info->pico, info->stream_handle);
    } else {
        printf("output stream thread started with stream handle %d\n",info->stream_handle);
        stream_output(info->pico, info->stream_handle, info->divisor, info->divisible);
    }
    return 0;
}

// load bit files, start streams and threads
int main(int argc, char* argv[]) {
    uint32_t buf[BUF_SIZE];
    char ibuf[BUF_SIZE];
    int err, i, j, card;
    int handle1, handle2;
    PicoDrv *last_pico, *cur_pico;
    const char* bitFileName;

    int num_cards = NUM_CARDS;
    int divisor = DIV;
    cur_pico = NULL;

    // initialize globals
    total_read = 0;
    total_write = 0;
    done_writing = false;
    pthread_mutex_init(&mutex, NULL);

    // keep track of thread parameters
    StreamInfo info[num_cards];
    StreamInfo input_info;
    StreamInfo output_info;

    pthread_t threads[num_cards+2];

    // specify the .bit file name on the command line
    if (argc < 2) {
        fprintf(stderr, "Please specify the .bit file on the command line.\n"
                        "For example: pbc ../firmware/M501_LX240_MultiStream.bit\n");
        exit(1);
    }

    bitFileName = argv[1];

    for (card = 0; card < num_cards; card++) {
        // last_pico points to previous FPGA so we can tie input streams if needed
        last_pico = cur_pico;
        // put the divisor on the buffer so we can write it to the pico card 
        buf[0] = divisor;
        // The RunBitFile function will locate a Pico card that can run the given bit file, and is not already
        //   opened in exclusive-access mode by another program. It requests exclusive access to the Pico card
        //   so no other programs will try to reuse the card and interfere with us.
        printf("Loading FPGA %d with '%s' ...\n", card+1, bitFileName);
        printf("Divisor is %d.\n", divisor);
        err = RunBitFile(bitFileName, &cur_pico);

        if (err < 0) {
            // We use the PicoErrors_FullError function to decipher error codes from RunBitFile.
            // This is more informative than just printing the numeric code, since it can report the name of
            //   file that wasn't found, for example.
            fprintf(stderr, "RunBitFile error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
            exit(1);
        }

        // Write to the divisor register in firmware
        if((err = cur_pico->WriteDeviceAbsolute(0, buf, 16)) < 0) {
            fprintf(stderr, "Error Writing: %d\n", err);
            exit(1);
        }

        // Open stream 1, used for input and output
        handle1 = cur_pico->CreateStream(1);
        if (handle1 < 0) {
            fprintf(stderr, "couldn't open stream 1! (return code: %i)\n", handle1);
            exit(1);
        }

        // Open stream 2, used for output only
        handle2 = cur_pico->CreateStream(2);
        if (handle2 < 0) {
            fprintf(stderr, "couldn't open stream 2! (return code: %i)\n", handle2);
            exit(1);
        }

        // if there is more than one fpga, tie the output stream of last_pico with the input stream of cur_pico
        if (last_pico != NULL) {
            err = last_pico->TieStreams(1,cur_pico,1);
            if (err < 0) {
                fprintf(stderr, "couldn't tie streams! (return code: %i)\n", err);
                exit(1);
            }
        }

        // if first FPGA, initialize input stream parameters
        if (card == 0) {
            input_info.pico = cur_pico;
            input_info.stream_handle = handle1;
            input_info.divisor = divisor;
            input_info.divisible = false;
            input_info.is_input = true;
        }

        // if last FPGA in chain, initialize output stream parameters (non-divisible stream)
        if (card == num_cards-1) {
            output_info.pico = cur_pico;
            output_info.stream_handle = handle1;
            output_info.divisor = divisor;
            output_info.divisible = false;
            output_info.is_input = false;
        }

        // initialize stream parameters for output stream 2, the "divisible" stream
        info[card].pico = cur_pico;
        info[card].stream_handle = handle2;
        info[card].divisor = divisor;
        info[card].divisible = true;
        info[card].is_input = false;

        // next fpga's divisor is just incremented by 1
        divisor += 1;
    }

    // Start all the input and output threads
    for (card = 0; card < num_cards; card++) {
        pthread_create(&threads[card], NULL, start_stream, (void*) &info[card]);
    }
    pthread_create(&threads[num_cards], NULL, start_stream, (void*) &input_info);
    pthread_create(&threads[num_cards+1], NULL, start_stream, (void*) &output_info);

    // Join all threads and terminate
    for (i = 0; i < num_cards+2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All tests successful!\n");
    return 0;
}

