/*===================================================================================
 File: StreamLoopback.cpp.

 This module is a simple command line utility designed to illustrate the operation 
 of a Pico stream interface. The streams provide a buffered interface to a module
 fabricated in the FPGA.

 This program interfaces with the firmware kernel StreamLoopback128.v in the sister directory.

=====================================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>
#include <pthread.h>
#include <ctime>
#include <iostream>

struct thread_args {
    PicoDrv* pico;
    int      stream;
};

void* stream_write_thread(void* args) {
    uint32_t buf[1024];
    PicoDrv *pico = ((thread_args*)args)->pico;
    int stream = ((thread_args*)args)->stream;

    for(int i = 0; i < 1024; i++) {
        buf[i] = i;
    }

    clock_t begin = clock();
    // Stream 4 GB to FPGA
    for(int i = 0; i < (1 << 20); i++) {
        pico->WriteStream(stream, buf, 4096);
    }
    clock_t end = clock();
    double timeSec = (end - begin) / ((double) CLOCKS_PER_SEC);
    std::cout << "Stream write took " << timeSec << " seconds" << std::endl;
}

void* stream_read_thread(void* args) {
    uint32_t buf[1024];
    PicoDrv *pico = ((thread_args*)args)->pico;
    int stream = ((thread_args*)args)->stream;
 
    clock_t begin = clock();
    // Stream 4 GB from FPGA
    for(int i = 0; i < (1 << 20); i++) {
        pico->ReadStream(stream, buf, 4096);
    }
    clock_t end = clock();
    double timeSec = (end - begin) / ((double) CLOCKS_PER_SEC);
    std::cout << "Stream read took " << timeSec << " seconds" << std::endl;
}   

int main(int argc, char* argv[])
{
    int         err, stream;
    uint32_t    buf[1024];
    char        ibuf[1024];
    PicoDrv     *pico;
    const char* bitFileName;
    pthread_t read_thread, write_thread;
    int iret1, iret2;
    thread_args read_thread_args, write_thread_args;

    // specify the .bit file name on the command line
    if (argc < 2) {
        fprintf(stderr, "Please specify the .bit file on the command line.\n"
                        "For example: pbc ../firmware/M501_LX240_StreamLoopback128.bit\n");
        exit(1);
    }
    bitFileName = argv[1];
    
    // The RunBitFile function will locate a Pico card that can run the given bit file, and is not already
    //   opened in exclusive-access mode by another program. It requests exclusive access to the Pico card
    //   so no other programs will try to reuse the card and interfere with us.
    printf("Loading FPGA with '%s' ...\n", bitFileName);
    err = RunBitFile(bitFileName, &pico);
    if (err < 0) {
        // We use the PicoErrors_FullError function to decipher error codes from RunBitFile.
        // This is more informative than just printing the numeric code, since it can report the name of a
        //   file that wasn't found, for example.
        fprintf(stderr, "RunBitFile error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }
    
    // data goes out to the firmware on stream #1 and also comes back on stream #1
    printf("Opening streams to test stream bandwidth\n");
    stream = pico->CreateStream(1);
    if (stream < 0) {
        fprintf(stderr, "couldn't open stream 1! (return code: %i)\n", stream);
        exit(1);
    }
   
    read_thread_args.pico = pico;
    read_thread_args.stream = stream;
    write_thread_args.pico = pico;
    write_thread_args.stream = stream;
    iret1 = pthread_create(&read_thread, NULL, &stream_read_thread, (void*) &read_thread_args);
    iret2 = pthread_create(&write_thread, NULL, &stream_write_thread, (void*) &write_thread_args);

    pthread_join(read_thread, NULL);
    pthread_join(write_thread, NULL);

    // streams are automatically closed when the PicoDrv object is destroyed, or on program termination, but
    //   we can also close a stream manually.
    pico->CloseStream(stream);
   
    return 0;
}

