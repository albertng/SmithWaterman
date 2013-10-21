//  File Name        : refseqmanager_test.cpp
//  Description      : Reference sequence manager test
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//

#include "picodrv_stub.h"
#include "refseqmanager.h"
#include <iostream>
#include <vector>
#include "def.h"

int main(int argc, char *argv[]) {
  RefSeqManager ref_seq_manager;
  PicoDrv* pico_drivers;
  if (argc < 2) {
    fprintf(stderr, "Usage: ./refseqmanager_test <REF SEQ FASTA FILE1> [<REF SEQ FASTA FILE2> ...]");
    exit(1);
  }

  // Set up pico drivers
  std::cout << "Setting up Pico drivers..." << std::endl;
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  }

  // Set up ref seq manager
  ref_seq_manager.Init(pico_drivers);

  // Add reference sequences
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ref_seq_manager.AddRef(filename);
  }
}
