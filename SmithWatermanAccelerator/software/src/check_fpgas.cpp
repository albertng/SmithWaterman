//  File Name        : check_fpgas.cpp
//  Description      : Prints out the FPGA temperatures
//                     Does not load new bitfiles, but requires exclusive access
//
//  Revision History :
//      Albert Ng   Feb 13 2014     Initial Revision

#include <iostream>
#include <picodrv.h>
#include <pico_errors.h>

#define NUM_FPGAS 6

int main(void) {
  PicoDrv* pico_drivers[NUM_FPGAS];
  PICO_CONFIG config[NUM_FPGAS];
  
  for (int i = 0; i < NUM_FPGAS; i++) {
    config[i].model = 0x505;
    config[i].shareAccess = false;
    int err = FindPico(&(config[i]), &(pico_drivers[i]));
    if (err < 0) {
      std::cerr << "FindPico error: " << PicoErrors_FullError << "\n";
      return 1;
    }
  }
  
  float temps[NUM_FPGAS];
  float voltages[NUM_FPGAS];
  float current[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    int err = pico_drivers[i]->GetSysMon(&(temps[i]), &(voltages[i]), &(current[i]));
    if (err < 0) {
      std::cerr << "GetSysMon error: " << PicoErrors_FullError << "\n";
      return 1;
    }
    std::cout << "FPGA " << i << "\tTemp: " << temps[i] << "\tVoltage: " << voltages[i] << "\tCurrent: " << current[i] << std::endl;
  }
}
