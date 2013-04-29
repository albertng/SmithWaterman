/*===================================================================================
 File: StreamLoopback.cpp.

 This module is a simple command line utility designed to illustrate the operation 
 of a Pico stream interface. The streams provide a buffered interface to a module
 fabricated in the FPGA.

 This program interfaces with the firmware kernel StreamLoopback32.v in the sister directory.

=====================================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>

int main(int argc, char* argv[])
{
    int         err, i, j, stream;
    uint32_t    buf[1024], u32, addr;
    char        ibuf[1024];
    PicoDrv     *pico;
    const char* bitFileName;
    
    // specify the .bit file name on the command line
    if (argc < 2) {
        fprintf(stderr, "Please specify the .bit file on the command line.\n"
                        "For example: pbc ../firmware/M501_LX240_StreamLoopback32.bit\n");
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
    printf("Opening streams to test counter\n");
    stream = pico->CreateStream(1);
    if (stream < 0) {
        fprintf(stderr, "couldn't open streams! (return code: %i)\n", stream);
        exit(1);
    }
    
    // fill the buffer with data we'll recognize when it comes back.
    for (i=0; i < sizeof(buf)/sizeof(buf[0]); ++i)
        buf[i] = 0x42000000 | i;
    
    printf("%i bytes of room in stream to firmware.\n", i=pico->GetBytesAvailable(stream, false /* writing */));
    // write 256 words if there's room. (and there should be if all is well.)
    if (i < 0){
        fprintf(stderr, "GetBytesAvailable error: %s\n", PicoErrors_FullError(i, ibuf, sizeof(ibuf)));
        exit(1);
    }else if (i > 256*4)
        i = 256*4;
    i &= ~0xf; // process only whole words.
    if (i > 0) {
        err = pico->WriteStream(stream, buf, i);
        printf("Wrote %i B\n", err);
        if (err != i) {
            fprintf(stderr, "write error. returned %i, but should have been %i\n", err, i);
            exit(1);
        }
    }
    
    // clear our buffer to prepare for the read.
    memset(buf, 0, sizeof(buf));
    
    printf("%i B available to read from firmware.\n", i=pico->GetBytesAvailable(stream, true /* reading */));
    // read up to 32 words back from the firmware.
    // (due to the way the buffering in the firmware works, we might not see all 128 words at once right now.)
    if (i < 0){
        fprintf(stderr, "GetBytesAvailable error: %s\n", PicoErrors_FullError(i, ibuf, sizeof(ibuf)));
        exit(1);
    }else if (i > 32*4)
        i = 32*4;
    i &= ~0xf; // process only whole words.
    if (i > 0) {
        printf("Reading %i B\n", i);
        err = pico->ReadStream(stream, buf, i);
        if (err != i) {
            fprintf(stderr, "write error. returned %i, but should have been %i\n", err, i);
            exit(1);
        }
        printf("Data received back from firmware:\n");
        for (int j=0; j<i/4; j++)
            printf("[0x%4x] 0x%8x\n", j, buf[j]);
    }

    // streams are automatically closed when the PicoDrv object is destroyed, or on program termination, but
    //   we can also close a stream manually.
    pico->CloseStream(stream);
    
    // verify the received data by checking only the last entry of buf
    if( buf[(i/4)-1] != 0x400001f0){
        printf("Error: unexpected value for last received 32 bits of buf\n");
        exit(1);
    }else{
        printf("All tests successful!\n");
    }

    return 0;
}

