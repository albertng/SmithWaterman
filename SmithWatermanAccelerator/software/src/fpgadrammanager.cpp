//  File Name        : fpgadrammanager.cpp
//  Description      : FPGA DRAM manager definitions
//
//  Revision History :
//      Albert Ng   Feb 20 2014     Initial Revision

#include <iostream>
#include <assert.h>
#include <stdexcept>
#include <vector>
#include <string>
#include <map> 
#include <set>
#include <fstream>
#include "fpgadrammanager.h"
#include "def.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

FpgaDramManager::FpgaDramManager() {
}

FpgaDramManager::FpgaDramManager(PicoDrv** pico_drivers, std::string fpgaref_dir) {
  Init(pico_drivers, fpgaref_dir);
}

void FpgaDramManager::Init(PicoDrv** pico_drivers, std::string fpgaref_dir) {
  pico_drivers_ = pico_drivers;
  fpgaref_dir_ = fpgaref_dir;

  MemChunk chunk;
  chunk.ref_id = -1;
  chunk.start_addr = 0;
  chunk.len = (long long int) DRAM_SIZE_BYTES * NT_PER_BYTE / REF_BLOCK_LEN;
  chunks_.push_back(chunk);
}

void FpgaDramManager::AddRef(int ref_id, long long int ref_bank_size, std::string ref_name) {
  std::cout << "Adding " << ref_name << ", bank size " << ref_bank_size << " to FpgaDramManager" << std::endl;
  ref_bank_sizes_[ref_id] = ref_bank_size;
  ref_names_[ref_id] = ref_name;
}

std::set<int> FpgaDramManager::GetAllocatedRefIds() {
  std::set<int> ref_ids;
  for (std::map<int, std::list<MemChunk>::iterator>::iterator it = ref_chunks_.begin(); it != ref_chunks_.end(); it++) {
    ref_ids.insert(it->first);
  }
  return ref_ids;
}

long long int FpgaDramManager::GetRefStartAddr(int ref_id) {
  if (ref_chunks_.find(ref_id) != ref_chunks_.end()) {
    return ref_chunks_[ref_id]->start_addr;
  } else {
    return -1;
  }
}

void FpgaDramManager::AllocateRef(int ref_id) {
  assert(ref_bank_sizes_.find(ref_id) != ref_bank_sizes_.end());

  // Case 1: Ref seq allocated in DRAM already
  //         Just update ref_id as most recently used
  if (ref_chunks_.find(ref_id) != ref_chunks_.end()) {
    UpdateAccess(ref_chunks_[ref_id]);
    return;
  }
  
  // Case 2: Large enough free chunk available
  //         Find best fit free chunk and allocate from it
  //         Load ref seq from disk to the newly allocated address
  //         Update ref_id as most recently used
  long long int best_fit_start_addr = AllocateBestFitChunk(ref_id);
  if (best_fit_start_addr != -1) {
    std::cout << "Best fit allocation" << std::endl;
    LoadRef(ref_id, best_fit_start_addr);
    UpdateAccess(ref_chunks_[ref_id]);
    return;
  }

  // Case 3: Large enough free chunk unavailable
  //         Keep freeing LRU ref seqs until a large enough chunk available and allocate it
  //         Load ref seq from disk to newly allocated address
  //         Update ref_id as most recently used
  long long int freed_start_addr = -1;
  while (freed_start_addr == -1) {
    freed_start_addr = ReallocateLRUChunk(ref_id);
  }
  std::cout << "LRU allocation" << std::endl;
  LoadRef(ref_id, freed_start_addr);
  UpdateAccess(ref_chunks_[ref_id]);
  return;
}


long long int FpgaDramManager::AllocateBestFitChunk(int ref_id) {
  std::list<MemChunk>::iterator best_chunk_it = chunks_.end();
  
  // Try to find best fit chunk
  for (std::list<MemChunk>::iterator it = chunks_.begin(); it != chunks_.end(); it++) {
    if (it->ref_id == -1 && it->len >= ref_bank_sizes_[ref_id] && 
       (best_chunk_it == chunks_.end() || it->len < best_chunk_it->len)) {
       best_chunk_it = it;
    }
  }
  
  if (best_chunk_it != chunks_.end()) {                       // Best fit chunk found
    assert(best_chunk_it->ref_id == -1);
    long long int new_start_addr = best_chunk_it->start_addr;
    if (best_chunk_it->len == ref_bank_sizes_[ref_id]) {      //   Chunk completely allocated 
      best_chunk_it->ref_id = ref_id;
    } else {                                                  //   Chunk split
      MemChunk new_chunk;
      new_chunk.ref_id = ref_id;
      new_chunk.start_addr = new_start_addr;
      new_chunk.len = ref_bank_sizes_[ref_id];
      chunks_.insert(best_chunk_it, new_chunk);
      
      best_chunk_it->len -= ref_bank_sizes_[ref_id];
      best_chunk_it->start_addr += ref_bank_sizes_[ref_id];
      best_chunk_it--;
    }
    ref_chunks_[ref_id] = best_chunk_it;
    return new_start_addr;
  } else {                                                    // No chunk found that fits                      
    return -1;
  }
}

long long int FpgaDramManager::ReallocateLRUChunk(int ref_id) {
  assert(ref_chunk_lru_list_.empty() == false);
  
  // Remove the LRU chunk from the LRU data structures
  std::list<MemChunk>::iterator lru_ref_chunk_it = ref_chunk_lru_list_.back();
  assert(lru_ref_chunk_it->ref_id != -1);
  ref_chunk_lru_list_.pop_back();
  ref_chunk_lru_map_.erase(ref_chunk_lru_map_.find(lru_ref_chunk_it->ref_id));
  
  // Free the LRU chunk
  std::cout << "Deallocating ref id " << lru_ref_chunk_it->ref_id << std::endl;
  ref_chunks_.erase(ref_chunks_.find(lru_ref_chunk_it->ref_id));
  lru_ref_chunk_it->ref_id = -1;
  
  // Coalesce with the previous adjacent free chunk
  std::list<MemChunk>::iterator prev_chunk_it = lru_ref_chunk_it;
  prev_chunk_it--;
  if (prev_chunk_it != chunks_.begin() && prev_chunk_it->ref_id == -1) {
    lru_ref_chunk_it->start_addr = prev_chunk_it->start_addr;
    lru_ref_chunk_it->len += prev_chunk_it->len;
    chunks_.erase(prev_chunk_it);
  }
  
  // Coalesce with the next adjacent free chunk
  std::list<MemChunk>::iterator next_chunk_it = lru_ref_chunk_it;
  next_chunk_it++;
  if (next_chunk_it != chunks_.end() && next_chunk_it->ref_id == -1) {
    lru_ref_chunk_it->len += next_chunk_it->len;
    chunks_.erase(next_chunk_it);
  }
  
  // Allocate the ref seq to the newly freed chunk if possible
  if (lru_ref_chunk_it->len >= ref_bank_sizes_[ref_id]) {         // Newly freed chunk fits
    long long int new_start_addr = lru_ref_chunk_it->start_addr;
    if (lru_ref_chunk_it->len == ref_bank_sizes_[ref_id]) {      //   Chunk completely allocated 
      lru_ref_chunk_it->ref_id = ref_id;
    } else {                                                     //   Chunk split
      MemChunk new_chunk;
      new_chunk.ref_id = ref_id;
      new_chunk.start_addr = new_start_addr;
      new_chunk.len = ref_bank_sizes_[ref_id];
      chunks_.insert(lru_ref_chunk_it, new_chunk);
      
      lru_ref_chunk_it->len -= ref_bank_sizes_[ref_id];
      lru_ref_chunk_it->start_addr += ref_bank_sizes_[ref_id];
      lru_ref_chunk_it--;
    }
    ref_chunks_[ref_id] = lru_ref_chunk_it;
    return new_start_addr;
  } else {                                                       // Newly freed chunk does not fit
    return -1;
  }
}

void FpgaDramManager::UpdateAccess(std::list<MemChunk>::iterator ref_chunk_it) {
  int ref_id = ref_chunk_it->ref_id;
  
  //assert(ref_chunk_lru_map_.find(ref_id) != ref_chunk_lru_map_.end());

  if (ref_chunk_lru_map_.count(ref_id) != 0) {                // Already previously accessed
    ref_chunk_lru_list_.push_front(*(ref_chunk_lru_map_[ref_id]));
    ref_chunk_lru_list_.erase(ref_chunk_lru_map_[ref_id]);
    ref_chunk_lru_map_[ref_id] = ref_chunk_lru_list_.begin();
  } else {                                                    // Newly accessed
    ref_chunk_lru_list_.push_front(ref_chunk_it);
    ref_chunk_lru_map_[ref_id] = ref_chunk_lru_list_.begin();
  }
}

// Note: addr is the ref block address, not byte address
void FpgaDramManager::LoadRef(int ref_id, long long int addr) {
  std::cout << "Loading " << ref_names_[ref_id] << " at address " << addr << std::endl;

  for (int i = 0; i < NUM_FPGAS; i++) {
    // Open FPGA 2bit file
    std::ifstream fpga2bitfile(fpgaref_dir_ + "/" + ref_names_[ref_id] + "." + std::to_string(i) + ".fpga2bit");
    assert(fpga2bitfile.is_open() == true);
    fpga2bitfile.seekg(0, fpga2bitfile.end);
    long size = fpga2bitfile.tellg();
    fpga2bitfile.seekg(0);
    assert(size % (REF_BLOCK_LEN / NT_PER_BYTE) == 0);
    
    // Read 2bit file into buffer
    char* buffer = new char[size];
    fpga2bitfile.read(buffer, size);
    fpga2bitfile.close();
    
    // Write the ref seq to the FPGA DRAM
    char ibuf[1024];
    int err = pico_drivers_[i]->WriteRam(addr * (REF_BLOCK_LEN / 4), (void*) buffer, size);
    std::cout << "Writing to FPGA " << i << " address " << addr << " " << size << " bytes" << std::endl;
    if (err < 0) {
      fprintf(stderr, "Failed to write ref seq to FPGA %d, error: %s\n", i,
              PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
    }
    
    delete[] buffer;
  }
}

