#ifndef DDR3_AXI_H
#define DDR3_AXI_H 1

#include <stdio.h>
#include <picodrv.h>
#include <pico_errors.h>

///////////////
// CONSTANTS //
///////////////

/////////////////
// DEFINITIONS //
/////////////////

// QDRII
#define NUM_QDRII       3           // number of QDRII chips on the M503

// test specific
#define TEST_MEM_S      10          // number of seconds to stress the QDRII system
#define QDRII_CTRL_ADDR 0x12350000  // PicoBus address for controlling the QDRII system
#define QDRII_ERR_ADDR  0x12350020  // PicoBus address for accessing error flags
#define QDRII_DATA_ADDR 0x12350040  // PicoBus address for accessing read data
#define QDRII_DATA_INCR 0x20        // increment amount for reading different read data
#define QDRI_SIG        0x55AA55AA  // QDRII PicoData signature

#define RESET_LOOP_MAX  10000       // max number of times we read the PicoBus to check if QDRII is
                                    //  calibrated before timing out

/////////////
// METHODS //
/////////////

void    ResetQDRII              (PicoDrv *pico);
void    WaitQDRIICalibration    (PicoDrv *pico);

#endif
