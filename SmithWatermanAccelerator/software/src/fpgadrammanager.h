//  File Name        : fpgadrammanager.h
//  Description      : FPGA DRAM manager definitions
//
//  Revision History :
//      Albert Ng   Feb 20 2014     Initial Revision

#ifndef FPGADRAMMANAGER_H_
#define FPGADRAMMANAGER_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
#include <set>
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif
#include "def.h"

#define DRAM_SIZE_BYTES 8*1024*1024*1024

class FpgaDramManager {
  public:
    FpgaDramManager();
    FpgaDramManager(PicoDrv** pico_drivers, std::string fpgaref_dir);
    void Init(PicoDrv** pico_drivers, std::string fpgaref_dir);
    
    // Add a ref seq to be managed
    //   Note: Does not load DRAM, only adds bookkeeping info
    void AddRef(int ref_id, long long int ref_bank_size, std::string ref_name);
    
    // Gets the starting ref block address of the given ref seq
    //   If the ref seq is unallocated, returns -1.
    long long int GetRefStartAddr(int ref_id);
    
    // Allocate and store the ref seq in FPGA DRAM using the
    //   allocation and replacement policies.
    void AllocateRef(int ref_id);
    
    // Get a set of ref seqs that are currently stored in FPGA DRAM
    std::set<int> GetAllocatedRefIds();
    
  private:
    struct MemChunk {
      int ref_id;               // Ref seq ID stored in this chunk
                                //   -1 if unallocated
      long long int start_addr; // Ref block address
      long long int len;        // Number of ref blocks in this chunk
    };
    
    // Find and allocate the best fit chunk for a ref seq
    //   Return the starting address of the chunk if found
    //   Returns -1 if no chunk found that fits the ref seq
    long long int AllocateBestFitChunk(int ref_id);
    
    // Frees LRU ref seq and coalesces the freed chunk with neighboring free chunks.
    //   Tries to allocate the given ref seq in the newly freed/coalesced chunk.
    //   Returns the newly allocated start address if successful, -1 otherwise.
    long long int ReallocateLRUChunk(int ref_id);
  
    // Update the LRU data structures with an access for a ref seq
    void UpdateAccess(std::list<MemChunk>::iterator ref_chunk_it);

    // Load a given address of the FPGA DRAMs with the ref seq
    //   Note: Assumes the FPGA2bit files exist in the ref directory
    void LoadRef(int ref_id, long long int addr);

    // Directory with ref seq FPGA 2bit and meta files
    std::string fpgaref_dir_;

    
    // List of memory chunks
    std::list<MemChunk> chunks_;
    
    // Allocated memory chunk (iterator) lookup from ref ID
    std::map<int, std::list<MemChunk>::iterator> ref_chunks_;
    
    // Ref seq bank size lookup from ref ID
    //   Bookkeeping info for all ref seqs added
    std::map<int, long long int> ref_bank_sizes_;
    
    PicoDrv** pico_drivers_;
    
    std::map<int, std::string> ref_names_;

    /** LRU policy data structures **/
    // Iterators for allocated ref seq memory chunks in usage order (MRU in front, LRU in back)
    std::list<std::list<MemChunk>::iterator> ref_chunk_lru_list_;
    
    // Ref seq ID to LRU list iterator map
    std::map<int, std::list<std::list<MemChunk>::iterator>::iterator> ref_chunk_lru_map_;

};




#endif // FPGADRAMMANAGER_H_
