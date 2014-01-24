//  File Name        : refseqmanager.h
//  Description      : Reference sequence manager definitions
//
//                     Reference sequences are stored on disk and are read on-demand
//                     when needed. To improve file reading performance, a number of
//                     reference sequence files are open at a time, up to FOPEN_MAX.
//                     This "cache" of open files is maintained by a LRU schedule.
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Removed GetSeqName()
//      Albert Ng   Nov 01 2013     Added GetRefName()
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2013     Added ref seq banking
//      Albert Ng   Jan 22 2014     Added ref seq file descriptor LRU management

#ifndef REFSEQMANAGER_H_
#define REFSEQMANAGER_H_

#include "def.h"
#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <list>
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

class RefSeqManager {
  public:
    // Struct holding the FPGA DRAM location of a reference sequence bank region
    struct RefSeqBank {
      int fpga;                     // FPGA the region is located in
      long long int start_coord;    // Start coordinate of the region
      long long int end_coord;      // Last coordinate of the region + 1
      long long int overlap_len;    // Length of the overlap region after the end coord
      long long int addr;           // Starting DRAM block address
    };
  
    // Empty constructor
    RefSeqManager();

    // Calls Init()
    RefSeqManager(PicoDrv** pico_drivers);

    // Actual initialization function
    void Init(PicoDrv** pico_drivers);

    // Reads from disk the char array of the ref seq with a given offset and length.
    char* GetRefSeq(int ref_id, int chr_id, long long int ref_offset, long long int ref_len);

    // Get the nucleotide length of the reference sequence.
    long long int GetRefLength(int ref_id, int chr_id);
    
    // Get the ref ID number from a reference sequence name.
    //   Return -1 if invalid ref name.
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
    void AddRef(std::string ref_file, std::string ref_name);

    // Get a list of FPGA DRAM locations of a ref seq region
    std::vector<RefSeqBank> GetRefSeqBanks(int ref_id, int chr_id, long long int start_coord,
                                           long long int end_coord);
                                           
    // Get total reference sequence length
    long long int GetTotalRefLength();
    
    // Get each FPGA storage size in number of bytes
    void GetFPGAStorage(long long int* num_nt);

  private:
    // Convert the ref seq to 2bit format and stream to the FPGA DRAM
    //   Replaces each N with a random nucleotide
    void StreamRefSeq(int fpga, char* ref_seq, long long int ref_addr, long long int ref_length);

    // Grab the file descriptor for the given ref seq.
    //   Opens the ref seq file if currently unopened.
    //   Closes the LRU ref seq file if max number of files are open.
    std::ifstream* GetRefSeqFD(int ref_id); 

    // Doubly-linked list of ref seq file descriptors
    std::list<std::ifstream*> ref_fd_list_;
    
    // Map of ref ID to file descriptor node in doubly-linked list
    std::map<int, std::list<std::ifstream*>::iterator> ref_fd_map_;

    // Vector of ref seq file mutexes, one for each ref seq
    std::vector<pthread_mutex_t> ref_fd_mutex_;

    // Mutex for the ref seq file descriptor list and map
    pthread_mutex_t ref_fd_listmap_mutex_;

    // Ref ID lookup from ref seq name.
    std::map<std::string, int> ref_id_;

    // Ref seq filename lookup from ref ID
    std::vector<std::string> ref_file_;
    
    // Ref seq name lookup from ref ID.
    std::vector<std::string> ref_name_;
    
    // Chromosome name lookup from ref ID and chr ID.
    std::vector<std::vector<std::string> > chr_name_;
    
    // Vector of chr_name:chr_id maps, one for each ref seq
    std::vector<std::map<std::string, int> > chr_id_;
    
    // Chromosome file position in each ref seq file
    std::vector<std::vector<long long int> > chr_filepos_;

    // Chr seq length lookup from ref ID and chr ID.
    std::vector<std::vector<long long int> > chr_length_;

    // Array of pointers to FPGA drivers
    PicoDrv** pico_drivers_;

    // Vectors of ref seq bank FPGA DRAM location info indexed by ref ID and chr ID
    std::vector<std::vector<std::vector<RefSeqBank> > > ref_seq_bank_info_;

    // Starting block address of the next ref seq to be added for each FPGA
    long long int cur_block_[NUM_FPGAS];

    // Sequence length count
    long long total_ref_length_;

    // Amount of overlap between banks of a ref seq
    static const int kOverlapLength = MAX_QUERY_LEN;
    
    // Max number of files that can be open at a time
    static const int kMaxNumFiles = FOPEN_MAX;
};

#endif // REFSEQMANAGER_H_
