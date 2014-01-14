//  File Name        : refseqmanager.h
//  Description      : Reference sequence manager definitions
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Removed GetSeqName()
//      Albert Ng   Nov 01 2013     Added GetRefName()
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2013     Added ref seq banking

#ifndef REFSEQMANAGER_H_
#define REFSEQMANAGER_H_

#include "def.h"
#include <map>
#include <string>
#include <vector>
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
    char* GetRefSeq(int ref_id, int chr_id, long long int ref_offset, long long int ref_len);

    // Get the index of the starting block of the reference sequence in the FPGA
    // DRAM.
    long long int GetRefAddr(int ref_id, int chr_id);

    // Get the nucleotide length of the reference sequence.
    long long int GetRefLength(int ref_id, int chr_id);
    
    // Get the ref ID number from a reference sequence name.
    // Return -1 if invalid ref name.
    int GetRefID(std::string ref_name);

    // Get the chr ID number from a chromosome name for a given ref seq.
    int GetChrID(int ref_id, std::string chr_name);
    
    // Get all chromosome ID numbers for a given ref seq.
    std::vector<int> GetChrIDs(int ref_id);

    // Get the ref seq name from the ref ID
    std::string GetRefName(int ref_id);

    // Get the chromosome name from the chr ID for a given ref seq.
    std::string GetChrName(int ref_id, int chr_id);

    // Add a new reference sequence to be managed.
    //void AddRef(std::string filename, std::string ref_name);
    void AddRef(std::vector<std::string> ref_files, std::string ref_name);


    // NEW THINGS
    // Struct holding the FPGA DRAM location of a reference sequence bank region
    struct RefSeqBank {
      int fpga;                     // FPGA the region is located in
      long long int start_coord;    // Start coordinate of the region
      long long int end_coord;      // Last coordinate of the region + 1
      long long int overlap_len;    // Length of the overlap region after the end coord
      long long int addr;           // Starting DRAM block address
    };


    // Get a list of FPGA DRAM locations of a ref seq region
    std::vector<RefSeqBank> GetRefSeqBanks(int ref_id, int chr_id, long long int start_coord,
                                           long long int end_coord);

  private:
    // Helper functions
    // Convert the ref seq to 2bit format and stream to the FPGA DRAM
    // Replaces each N with a random nucleotide
    void StreamRefSeq(int fpga, char* ref_seq, long long int ref_addr, long long int ref_length);

    // Ref ID lookup from ref seq name.
    std::map<std::string, int> ref_id_;

    // Vector of chr_name:chr_id maps, one for each ref seq
    std::vector<std::map<std::string, int> > chr_id_;
    
    // Ref seq name lookup from ref ID.
    std::vector<std::string> ref_name_;
    
    // Chromosome name lookup from ref ID and chr ID.
    std::vector<std::vector<std::string> > chr_name_;

    // Char sequence array lookup from ref ID.
    std::vector<std::vector<char*> > ref_seq_;

    // Ref seq starting block in FPGA DRAM lookup from ref ID and chr ID.
    //std::vector<std::vector<long long int> > ref_addr_;

    // Ref seq length lookup from ref ID and chr ID.
    std::vector<std::vector<long long int> > ref_length_;

    // Starting block address of the next ref seq to be added.
    int cur_block_;

    // Array of pointers to FPGA drivers
    PicoDrv** pico_drivers_;




    // NEW STUFF
    // Vectors of ref seq bank FPGA DRAM location info indexed by ref ID and chr ID
    std::vector<std::vector<std::vector<RefSeqBank> > > ref_seq_bank_info_;

    // Starting block address of the next ref seq to be added for each FPGA
    long long int cur_block_[NUM_FPGAS];

    // Amount of overlap between banks of a ref seq
    const int kOverlapLength = MAX_QUERY_LEN;
};

#endif // REFSEQMANAGER_H_
