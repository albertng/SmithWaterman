/*
* File Name : DDR3_Moving_Average.cpp
*
* Description :  This sample application is a moving average, otherwise known as a smoothing
*                filter.  This software generates random data to stream to the DDR3 system.  The
*                software sends a command to the firmware to begin filtering the data in the DDR
*                and writing it to another address in the DDR.  The software then reads the data
*                from the new address in DRAM and verifies the 4-sample moving average against the
*                expected values.
*
*                Note: the firmware imposes a 4kB size limit on the data to be filtered.
*
* Creation Date : Tue 21 Feb 2012 02:32:19 PM PST
*
* Author : Corey Olson
*
* Last Modified : Tue 20 Nov 2012 02:48:05 PM CST
*
* Copyright 2011 Pico Computing, Inc.
*/

#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>

// set this define to true to print out the input data and the filtered data
#define PRINT_DATA false

// size of the data written to the DDR (in Bytes) 
// Note: this must be a multiple of 32
#define WRITE_DATA_SIZE 4096

// prints the data that either will be filtered or has been filtered to the screen
// note: since we only filter the LS 32 bits of the data (out of 128 bits on the M-501 and 256 bits
//       on the M-503), we only print those bits here
void printFilterData(uint32_t* data, int numBytes, int cardType){

    // if M-501, print every 4th 32-bit element, else print every 8th 32-bit element
    for(int i=0; i<(numBytes/4); i += (cardType==0x501) ? 4 : 8){
        printf("%02i: %08X\n", i, data[i]);
    }
}

// 1) creates random data to be filtered
// 2) streams that data to the DDR system
// 3) sends command to the FPGA to begin filter
// 4) streams filtered data from the DDR system
int main(int argc, char* argv[])
{
    PicoDrv     *pico;
    int         err;
    int         stream;

    uint32_t    cmd[4];
    char        ibuf[1024];
    const char* bitFileName;
    PICO_CONFIG icfg;

    uint32_t    *inputData;
    uint32_t    *expectedAverage;
    uint32_t    *actualAverage;
    
    // seed the random number generator
    srand(time(NULL));

    // specify the .bit file name on the command line
    if (argc < 2) {
        fprintf(stderr, "Please specify the .bit file on the command line.\n"
                        "For example: pbc ../firmware/M501_LX240_DDR3.bit\n");
        exit(1);
    }else{   
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
    }
    
    // create the stream 1
    stream = pico->CreateStream(1);
    if (stream < 0) {
        fprintf(stderr, "Unable to open stream 1: %s\n", PicoErrors_FullError(stream, ibuf, sizeof(ibuf)));
        exit(1);
    }
    
    // get the card type and slot number information
    pico->GetPicoConfig(&icfg);

    // allocate memory to initialize and verify the memory system
    inputData       = new uint32_t[WRITE_DATA_SIZE/4];
    expectedAverage = new uint32_t[WRITE_DATA_SIZE/4];
    actualAverage   = new uint32_t[4096/4];

    //////////////////////////////////////////
    // generate random input data           //
    // compute the expected filtered data   //
    //////////////////////////////////////////
    // only the LS word of each 128-bit entry of DRAM is included in the data to be filtered
    uint64_t sum = 0;
    for(int i=0; i<WRITE_DATA_SIZE/16; i++){

        // random input data
        inputData[4*i+3] = inputData[4*i+2] = inputData[4*i+1] = 0;
        inputData[4*i] = rand();
        
        // M-501
        if (icfg.model == 0x501){
            expectedAverage[4*i+3] = expectedAverage[4*i+2] = expectedAverage[4*i+1] = 0;
            if (i > 3){
                sum -= inputData[4*(i-4)];
            }
            sum += inputData[4*i];
            expectedAverage[4*i] = sum / 4;
        }
        // M-503
        else{
            if (i%2 == 0){
                expectedAverage[4*i+3] = expectedAverage[4*i+2] = expectedAverage[4*i+1] = 0;
                if (i > 7){
                    sum -= inputData[4*(i-8)];
                }
                sum += inputData[4*i];
                expectedAverage[4*i] = sum / 4;
            }else{
                expectedAverage[4*i+3] = expectedAverage[4*i+2] = 
                    expectedAverage[4*i+1] = expectedAverage[4*i] = 0;
            }
        }
    }

    // print the data to be filtered
    if (PRINT_DATA){
        printf("Data to be filtered:\n");
        printFilterData(inputData, 4096, icfg.model);
    }

    ///////////////////////////////
    // write the data to the DDR //
    ///////////////////////////////
    // write to DDR address 0
    printf("Writing %iB of data to the DDR\n", WRITE_DATA_SIZE);
    err = pico->WriteRam(0, inputData, WRITE_DATA_SIZE, PICO_DDR3_0);
    if (err < 0){
        fprintf(stderr, "WriteRam error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }else if (err != WRITE_DATA_SIZE){
        fprintf(stderr, "WriteRam wrote %i bytes instead of the desired %i bytes\n", err, WRITE_DATA_SIZE);
        exit(1);
    }
    sleep(1);

    /////////////////////////////////////////
    // send the command to filter the data //
    /////////////////////////////////////////
    // filter 4096 B from address 0 to address 4096
    printf("Sending command to begin moving average computation\n");
    cmd[3] = 0;
    cmd[2] = 4096;
    cmd[1] = 4096;
    cmd[0] = 0;
    err = pico->WriteStream(stream, cmd, 16);
    if (err < 0){
        fprintf(stderr, "WriteStream error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }else if (err != 16) {
        fprintf(stderr, "write error. returned %i, but should have been %i\n", err, 16);
        exit(1);
    }
    sleep(1);

    /////////////////////////////////////
    // read the filtered data from DDR //
    /////////////////////////////////////
    // read from DDR address 4096
    printf("Reading 4096B of averaged data from the DDR\n");
    err = pico->ReadRam(4096, actualAverage, 4096, PICO_DDR3_0);
    if (err < 0){
        fprintf(stderr, "ReadRam error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }else if (err != 4096){
        fprintf(stderr, "ReadRam read %i bytes instead of the desired 4096 bytes\n", err);
        exit(1);
    }

    // print the data after filtering
    if (PRINT_DATA){
        printf("Data after filtering:\n");
        printFilterData(actualAverage, 4096, icfg.model);
    }
    
    /////////////////////////////////////////////
    // compare the actual data to the expected //
    /////////////////////////////////////////////
    printf("Comparing the computed moving average data to the expected moving average\n");
    for(int i=0; i<4096/16; i++){
        if (actualAverage[4*i+3] != expectedAverage[4*i+3] ||
            actualAverage[4*i+2] != expectedAverage[4*i+2] ||
            actualAverage[4*i+1] != expectedAverage[4*i+1] ||
            actualAverage[4*i] != expectedAverage[4*i]){
            printf("data[%i]: actual (0x%08X_%08X_%08X_%08X) != expected (0x%08X_%08X_%08X_%08X)\n",
                            i, 
                            actualAverage[4*i+3], 
                            actualAverage[4*i+2], 
                            actualAverage[4*i+1], 
                            actualAverage[4*i], 
                            expectedAverage[4*i+3], 
                            expectedAverage[4*i+2],
                            expectedAverage[4*i+1], 
                            expectedAverage[4*i]);
            printf("Input data = %08X_%08X_%08X_%08X\n",
                            inputData[4*i+3], 
                            inputData[4*i+2],
                            inputData[4*i+1], 
                            inputData[4*i]);
            exit(1);
        }
    }
   
    //////////////////////////////
    // free up allocated memory //
    //////////////////////////////
    delete [] inputData;
    delete [] expectedAverage;
    delete [] actualAverage;

    printf("All tests successful!\n");
    return 0;
}
