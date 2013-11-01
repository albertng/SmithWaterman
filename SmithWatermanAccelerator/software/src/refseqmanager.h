//  File Name        : refseqmanager.h
//  Description      : Reference sequence manager definitions
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Removed GetSeqName()

#ifndef REFSEQMANAGER_H_
#define REFSEQMANAGER_H_

#include "def.h"
#include <map>
#include <string>
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

class RefSeqManager {
  public:
    // Empty constructor
    RefSeqManager();

    // Calls Init()
    RefSeqManager(PicoDrv** pico_drivers);

    // Actual initialization function
    void Init(PicoDrv** pico_drivers);

    // Get the char array of the reference sequence starting from a given offset.
    // Makes sure the requested offset and length adhere to reference sequence
    // bounds.
    char* GetRefSeq(int ref_id, long long int ref_offset, long long int ref_len);

    // Get the index of the starting block of the reference sequence in the FPGA
    // DRAM.
    long long int GetRefAddr(int ref_id);

    // Get the nucleotide length of the reference sequence.
    long long int GetRefLength(int ref_id);
    
    // Get the ref ID number from a reference sequence name.
    int GetRefID(std::string ref_name);

    // Add a new reference sequence to be managed.
    void AddRef(std::string filename);

  private:
    // Helper functions
    // Convert the ref seq to 2bit format and stream to the FPGA DRAM
    // Replaces each N with a random nucleotide
    void StreamRefSeq(char* ref_seq, long long int ref_addr, long long int ref_length);

    // Map between ref seq name and ID number.
    std::map<std::string, int> ref_id_;

    // Map between ref seq ID and seq name.
    std::map<int, std::string> ref_name_;

    // Map between ref seq ID and char sequence array.
    std::map<int, char*> ref_seq_;

    // Map between ref seq ID and ref seq starting block in FPGA DRAM.
    std::map<int, long long int> ref_addr_;

    // Map between ref seq ID and ref seq length.
    std::map<int, long long int> ref_length_;

    // ID of the next ref seq to be added.
    int cur_ref_id_;

    // Starting block address of the next ref seq to be added.
    int cur_block_;

    // Array of pointers to FPGA drivers
    PicoDrv** pico_drivers_;
};

#endif // REFSEQMANAGER_H_
