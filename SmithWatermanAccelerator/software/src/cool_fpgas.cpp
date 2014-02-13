//  File Name        : cool_fpgas.cpp
//  Description      : Loads FPGAs with a small bitfile to cool the FPGAs
//
//  Revision History :
//      Albert Ng   Feb 13 2014     Initial Revision

#include <iostream>
#include <picodrv.h>
#include <pico_errors.h>

#define NUM_FPGAS 6

int main(void) {
  PicoDrv* pico_drivers[NUM_FPGAS];
  
  // Set up pico FPGA drivers
  const char* bitfile_name = "cool_fpga.bit";
  for (int i = 0; i < NUM_FPGAS; i++) {
    std::cout << "Loading FPGA " << i << " with bitfile: " << bitfile_name << std::endl;
    int err = RunBitFile(bitfile_name, &(pico_drivers[i]));
    if (err < 0) {
      std::cerr << "RunBitFile error: " << PicoErrors_FullError << "\n";
      return 1;
    }
  }
}
