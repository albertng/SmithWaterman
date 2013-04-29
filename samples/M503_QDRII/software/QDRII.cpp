/*===================================================================================
 File: QDRII.cpp.
 Description: tests the functionality of the QDRII system using the Xilinx traffic generators
=====================================================================================*/

#include <stdio.h>
#include <time.h>
#include <picodrv.h>
#include <pico_errors.h>

#include "QDRII.h"

///////////
// Reset //
///////////
void ResetQDRII(PicoDrv *pico){
    int         err;
    uint32_t    cmd[4];
    char        ibuf[1024];

    cmd[0]=cmd[1]=cmd[3]=0;

    // write the reset to 1
    cmd[2] = 1;
    err = pico->WriteDeviceAbsolute(QDRII_CTRL_ADDR, cmd, 16);
    if (err < 0){
        fprintf(stderr, "WriteDeviceAbsolute error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }

    // release the reset
    cmd[2] = 0;
    err = pico->WriteDeviceAbsolute(QDRII_CTRL_ADDR, cmd, 16);
    if (err < 0){
        fprintf(stderr, "WriteDeviceAbsolute error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }
}

//////////////////////////
// Wait for Calibration //
//////////////////////////
void WaitQDRIICalibration(PicoDrv *pico){
    int         err;
    uint32_t    cmd[4];
    char        ibuf[1024];
    int         loopCount;

    // PicoData[QDRII_CTRL_ADDR]
    // 0        c0_cal_done
    // 16       c1_cal_done
    // 32       c2_cal_done
    // 64       qdrii_sys_rst_q
    // 127:96   QDRII_SIG
    for(loopCount = 0; (loopCount<RESET_LOOP_MAX); loopCount++){
        err = pico->ReadDeviceAbsolute(QDRII_CTRL_ADDR, cmd, 16);
        if (err < 0){
            fprintf(stderr, "ReadDeviceAbsolute error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
            exit(1);
        }else if(cmd[0]==0x00010001 && cmd[1]==0x1){
            break;
        }
    }
}

//////////
// Main //
//////////
int main(int argc, char* argv[])
{
    PicoDrv     *pico;
    int         err;
    time_t      startTime;
    time_t      endTime;

    uint32_t    cmd[4];
    char        ibuf[1024];
    const char* bitFileName;
    
    // specify the .bit file name on the command line
    if (argc < 2) {
        fprintf(stderr, "Please specify the .bit file on the command line.\n"
                        "For example: pbc ../firmware/M501_LX240_StreamLoopback128.bit\n");
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
    
    ////////////////////////////
    // reset the QDRII system //
    ////////////////////////////
    printf("\nResetting the QDRII system...\n");
    ResetQDRII(pico);

    /////////////////////////////////////////////////////
    // wait for the QDRII system to finish calibration //
    /////////////////////////////////////////////////////
    printf("Waiting for QDRII system to finish calibration...\n");
    WaitQDRIICalibration(pico);

    ///////////////////////////////////////////
    // read some data from the QDRII systems //
    ///////////////////////////////////////////
    printf("\nTesting QDRII for %i seconds...\n", TEST_MEM_S);
    time(&startTime);
    time(&endTime);
    
    // print a header
    printf("Elapsed time");
    for(int i=0; i<NUM_QDRII; i++){
        printf(" :        QDRII %i Data       ", i);
    }
    printf("\n");

    // read from the QDRII for TEST_MEM_S seconds
    while (difftime(endTime, startTime) < TEST_MEM_S){
        
        printf("    %lf", difftime(endTime, startTime));
        
        // read from each QDRII system each iteration
        for(int i=0; i<NUM_QDRII; i++){
            err = pico->ReadDeviceAbsolute(QDRII_DATA_ADDR+i*QDRII_DATA_INCR, cmd, 16);
            if (err < 0){
                fprintf(stderr, "ReadDeviceAbsolute error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
                exit(1);
            }else{
                printf(" : %08X_%08X_%08X", cmd[2], cmd[1], cmd[0]);
            }
        }
        printf("\n");

        // sleep for 400 ms
        Sleep(400);

        // update the elapsed time
        time(&endTime);
    }

    ///////////////////////////
    // check the error flags //
    ///////////////////////////
    printf("Checking QDRII error flags...\n");
    err = pico->ReadDeviceAbsolute(QDRII_ERR_ADDR, cmd, 16);
    if (err < 0){
        fprintf(stderr, "ReadDeviceAbsolute error: %s\n", PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
        exit(1);
    }
    for(int i=0; i<NUM_QDRII; i++){
        if(cmd[i]!=0){
            fprintf(stderr, "Error found when testing QDRII %i\n", i);
            exit(1);
        }
    }
    
    printf("All tests successful!\n");
    return 0;
}
