//  File Name        : refseqmanager.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 19 2013     Completed StreamRefSeq()
//      Albert Ng   Oct 29 2013     Uses fasta.h to parse FASTA files
//      Albert Ng   Nov 01 2013     Added GetRefName()
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2014     Added ref seq banking
//      Albert Ng   Jan 21 2014     Changed to ref seq file seeking
//      Albert Ng   Jan 22 2014     Added ref seq file descriptor LRU management
//                                  Added GetFPGAStorage()
//      Albert Ng   Feb 03 2014     Added fpga file loading
//      Albert Ng   Feb 04 2014     Added GetNumRefs()
//      Albert Ng   Feb 18 2014     Added GetChrRegions()

#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "refseqmanager.h"
#include "utils.h"
#include "fasta.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif
#include "fpgadrammanager.h"

static const int CHR_NAME_FIELD = 0;

RefSeqManager::RefSeqManager() {
}

RefSeqManager::RefSeqManager(PicoDrv** pico_drivers, std::string ref_dir) {
  Init(pico_drivers, ref_dir);
}

void RefSeqManager::Init(PicoDrv** pico_drivers, std::string ref_dir) {
  srand(time(NULL));
  
  for (int i = 0; i < NUM_FPGAS; i++) {
    cur_block_[i] = 0;
  }
  pico_drivers_ = pico_drivers;
  ref_dir_ = ref_dir;
  
  total_ref_length_ = 0;
  disk_refseqload_time_ = 0;
  fpga_refseqload_time_ = 0;
  ref_seq_access_count_ = 0;
  file_read_time_ = 0;
  seq_copy_time_ = 0;
  ref_length_read_ = 0;
  
  pthread_mutex_init(&ref_fd_listmap_mutex_, NULL);
  
  fpga_dram_manager_.Init(pico_drivers, ref_dir);
}

// Maintains a LRU "cache" of ref seq file descriptors.
//   The cache is implemented using a doubly linked list of
//   recent use history, and a map between ref seq ID and the 
//   linked list node pointer (iterator). When accessing a 
//   ref seq file, there are three cases:
// Case 1: File already open
//   Look up the linked list node of the ref seq from the map.
//   Move node to the head of the list.
//   Update linked list node pointer in map.
// Case 2: File not open, maximum open files not reached
//   Open the file and add to front of the list.
//   Update linked list node pointer in map.
// Case 3: File not open, maximum open files reached
//   Close and remove LRU file from linked list and map.
//   Open the file and add to front of the list.
//   Update linked list node pointer in map.
std::ifstream* RefSeqManager::GetRefSeqFD(int ref_id) {
  pthread_mutex_lock(&ref_fd_listmap_mutex_);

  if (ref_fd_map_.count(ref_id) != 0) {               // Case 1
    ref_fd_list_.push_front(*(ref_fd_map_[ref_id]));
    ref_fd_list_.erase(ref_fd_map_[ref_id]);
    ref_fd_map_[ref_id] = ref_fd_list_.begin();
  } else if (ref_fd_list_.size() < kMaxNumFiles) {    // Case 2
    std::ifstream* file = new std::ifstream;
    while(file->is_open() == false) {
      file->open(ref_file_[ref_id].c_str());
    }
    ref_fd_list_.push_front(file);
    ref_fd_map_[ref_id] = ref_fd_list_.begin();
  } else {                                            // Case 3
    // Find the LRU file
    std::list<std::ifstream*>::iterator lru_file_it = --ref_fd_list_.end();
    int lru_ref_id;
    for (std::map<int, std::list<std::ifstream*>::iterator>::iterator it = ref_fd_map_.begin();
         it != ref_fd_map_.end(); ++it) {
      if (lru_file_it == it->second) {
        lru_ref_id = it->first;
        break;
      }
    }
    
    // Close the LRU file
    pthread_mutex_lock(&(ref_fd_mutex_[lru_ref_id]));
    (*lru_file_it)->close();
    delete *lru_file_it;
    pthread_mutex_unlock(&(ref_fd_mutex_[lru_ref_id]));
    
    // Remove the LRU file from the map and linked list
    for (std::map<int, std::list<std::ifstream*>::iterator>::iterator it = ref_fd_map_.begin();
         it != ref_fd_map_.end(); ++it) {
      if (lru_file_it == it->second) {
        ref_fd_map_.erase(it);
        break;
      }
    }
    ref_fd_list_.pop_back();
    
    // Open new file and add to front of list
    std::ifstream* file = new std::ifstream;
    while(file->is_open() == false) {
      file->open(ref_file_[ref_id].c_str());
    }
    ref_fd_list_.push_front(file);
    ref_fd_map_[ref_id] = ref_fd_list_.begin();
  }
  
  std::ifstream* file = *(ref_fd_map_[ref_id]);
  
  pthread_mutex_unlock(&ref_fd_listmap_mutex_);

  return file;
}

char* RefSeqManager::GetRefSeq(int ref_id, int chr_id, long long int ref_offset, long long int ref_len) {
  assert(ref_id < ref_name_.size() && ref_id >= 0);
  assert(ref_offset + ref_len <= chr_length_[ref_id][chr_id]);
  
  pthread_mutex_lock(&(ref_fd_mutex_[ref_id]));
  
  struct timespec start, finish;
  double elapsed;
  
  clock_gettime(CLOCK_MONOTONIC, &start);
  std::ifstream* file = GetRefSeqFD(ref_id);
  assert(file->is_open());
  
  file->seekg(chr_filepos_[ref_id][chr_id] + ref_offset + (ref_offset / SEQLINE_WRAP_LEN));
  long long int cur_len = 0;
  std::string line;
  std::string seqline;
  while (seqline.size() < ref_len && getline(*file, line)) {
    seqline += line;
    if (seqline.size() > ref_len) {
      seqline.resize(ref_len);
    }
  }
  
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  file_read_time_ += elapsed;
  
  pthread_mutex_unlock(&(ref_fd_mutex_[ref_id]));  
  
  clock_gettime(CLOCK_MONOTONIC, &start);
  char* seq = new char[ref_len];
  seqline.copy(seq, ref_len);
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  seq_copy_time_ += elapsed;
  
  ref_seq_access_count_++;
  ref_length_read_ += ref_len;
  
  return seq;
}

long long int RefSeqManager::GetRefLength(int ref_id, int chr_id) {
  assert(ref_id < chr_length_.size());
  assert(chr_id < chr_length_[ref_id].size());
  return chr_length_[ref_id][chr_id];
}

int RefSeqManager::GetRefID(std::string ref_name) {
  if (ref_id_.count(ref_name) == 0) {
    return -1;
  }
  return ref_id_[ref_name];
}

int RefSeqManager::GetChrID(int ref_id, std::string chr_name) {
  if (ref_id >= chr_id_.size() || chr_id_[ref_id].count(chr_name) == 0) {
    return -1;
  }
  return chr_id_[ref_id][chr_name];
}

std::vector<int> RefSeqManager::GetChrIDs(int ref_id) {
  std::vector<int> chr_ids;
  if (ref_id < chr_name_.size()) {
    for (int i = 0; i < chr_name_[ref_id].size(); i++) {
      chr_ids.push_back(i);
    }
  }
  return chr_ids;
}

std::string RefSeqManager::GetRefName(int ref_id) {
  assert(ref_id < ref_name_.size());
  return ref_name_[ref_id];
}

std::string RefSeqManager::GetChrName(int ref_id, int chr_id) {
  assert(ref_id < chr_name_.size());
  assert(chr_id < chr_name_[ref_id].size());
  return chr_name_[ref_id][chr_id];
}

// NOTE: For ALL_CHR case, start_coord and end_coord arguments are ignored
std::vector<RefSeqManager::RefSeqBank> RefSeqManager::GetRefSeqBanks(int ref_id, int chr_id, 
                                                      long long int start_coord, long long int end_coord) {
  long long int ref_start_addr = fpga_dram_manager_.GetRefStartAddr(ref_id);
  assert(ref_start_addr >= 0);
  
  // ALL_CHR case
  //   Treat all chromosomes of ref seq as one long sequence
  if (chr_id == -1) {
    std::vector<RefSeqBank> ref_bank_locs = ref_bank_info_[ref_id];
    for (int i = 0; ref_bank_locs.size(); i++) {
      ref_bank_locs[i].addr = ref_start_addr;
    }
    return ref_bank_locs;
  }
  
  // Single chromosome case
  std::vector<RefSeqBank> chr_bank_locs;
  for (std::vector<RefSeqBank>::iterator it = chr_bank_info_[ref_id][chr_id].begin();
       it != chr_bank_info_[ref_id][chr_id].end();
       ++it) {
    RefSeqBank bank = *it;
    RefSeqBank loc;

    loc.fpga = bank.fpga;

    // Record new location if the bank overlaps with the requested region
    if (bank.start_coord < end_coord && bank.end_coord > start_coord) {
      // Adjust start coord if requested region starts after the bank start
      if (bank.start_coord < start_coord) {
        loc.start_coord = start_coord;
      } else {
        loc.start_coord = bank.start_coord;
      }
      loc.addr = bank.addr + ((loc.start_coord - bank.start_coord) / REF_BLOCK_LEN);

      // Adjust end coord if requested region ends before the bank end
      if (end_coord < bank.end_coord) {
        loc.end_coord = end_coord;
      } else {
        loc.end_coord = bank.end_coord;
      }
      
      // Adjust overlap length
      if (end_coord - bank.end_coord < bank.overlap_len) {
        loc.overlap_len = end_coord - bank.end_coord;
        loc.overlap_len = loc.overlap_len < 0 ? 0 : loc.overlap_len;
      } else {
        loc.overlap_len = bank.overlap_len;
      }
      
      chr_bank_locs.push_back(loc);
    }
  }
  
  for (int i = 0; i < chr_bank_locs.size(); i++) {
    chr_bank_locs[i].addr += ref_start_addr;
  }
  return chr_bank_locs;
}

void RefSeqManager::AllocateRef(int ref_id) {
  fpga_dram_manager_.AllocateRef(ref_id);
}

std::vector<int> RefSeqManager::GetAllocatedRefIds() {
  return fpga_dram_manager_.GetAllocatedRefIds();
}

void RefSeqManager::GetChrRegions(int ref_id, long long int start_coord, long long int end_coord,
                                  std::vector<int>* chr_ids,
                                  std::vector<long long int>* chr_offsets,
                                  std::vector<long long int>* chr_start_coords,
                                  std::vector<long long int>* chr_end_coords) {
  assert(ref_id < chr_name_.size());
  
  long long int cur_coord = 0;
  for (int i = 0; i < chr_length_[ref_id].size() && cur_coord < end_coord; i++) {  
    if (cur_coord < end_coord && (cur_coord + chr_length_[ref_id][i] > start_coord)) {
      int chr_id = i;
      long long int start = cur_coord < start_coord ? start_coord : cur_coord;
      long long int end = (cur_coord + chr_length_[ref_id][i]) < end_coord ? (cur_coord + chr_length_[ref_id][i]) : end_coord;
      
      chr_ids->push_back(i);
      chr_offsets->push_back(cur_coord);
      chr_start_coords->push_back(start - cur_coord);
      chr_end_coords->push_back(end - cur_coord);
    }
    cur_coord += ((long long int) ceil(((double) chr_length_[ref_id][i]) / REF_BLOCK_LEN)) * REF_BLOCK_LEN;
  }
}


int RefSeqManager::GetNumRefs() {
  return ref_name_.size();
}

long long int RefSeqManager::GetTotalRefLength() {
  return total_ref_length_;
}

void RefSeqManager::GetFPGAStorage(long long int* num_bytes) {
  for (int i = 0; i < NUM_FPGAS; i++) {
    num_bytes[i] = cur_block_[i] * REF_BLOCK_LEN / NT_PER_BYTE;
  }
}

double RefSeqManager::GetDiskRefSeqLoadTime() {
  return disk_refseqload_time_;
}

double RefSeqManager::GetFPGARefSeqLoadTime() {
  return fpga_refseqload_time_;
}

double RefSeqManager::GetFileReadTime() {
  return file_read_time_;
}

double RefSeqManager::GetSeqCopyTime() {
  return seq_copy_time_;
}

int RefSeqManager::GetRefSeqAccessCount() {
  return ref_seq_access_count_;
}

long long int RefSeqManager::GetRefLengthRead() {
  return ref_length_read_;
}

void RefSeqManager::ResetStats() {
  ref_seq_access_count_ = 0;
  file_read_time_ = 0;
  seq_copy_time_ = 0;
  ref_length_read_ = 0;
}

void RefSeqManager::AddRef(std::string ref_fa_filename, std::string ref_name) {
  std::ifstream file(ref_dir_ + "/" + ref_fa_filename);
  if (file.is_open() == false) {
    std::cerr << "Error: Could not open FASTA file " << ref_fa_filename << std::endl;
    file.close();
    return;
  }
  file.close();  
  
  // Check if fpga files are already built
  bool all_files_present = true;
  file.open(ref_dir_ + "/" + ref_name + ".meta");
  all_files_present &= file.is_open();
  file.close();
  for (int i = 0; i < NUM_FPGAS; i++) {
    file.open(ref_dir_ + "/" + ref_name + "." + std::to_string(i) + ".fpga2bit");
    all_files_present &= file.is_open();
    file.close();
  }

  // Build the fpga files if needed
  if (all_files_present == false) {
    BuildFpgaFiles(ref_fa_filename, ref_name);
  }
  
  // Load the fpga files
  LoadRef(ref_fa_filename, ref_name);
  
  // Initialize and add a mutex for ref seq file
  pthread_mutex_t ref_mutex;
  pthread_mutex_init(&ref_mutex, NULL);
  ref_fd_mutex_.push_back(ref_mutex);
}

void RefSeqManager::BuildFpgaFiles(std::string ref_fa_filename, std::string ref_name) {
  std::cout << "Building FPGA files for ref " << ref_name << "..." << std::endl;

  std::vector<std::vector<std::string> > descrips;
  std::vector<char*> seqs;
  std::vector<long long int> lengths;
  std::vector<long long int> fileposs;

  // Parse FASTA file
  ParseFastaFile(ref_dir_ + "/" + ref_fa_filename, &descrips, &seqs, &lengths, &fileposs);
  assert(descrips.size() == seqs.size());
  assert(seqs.size() == lengths.size());
  assert(lengths.size() == fileposs.size());
  
  // Compute ref seq bank lengths
  long long int total_num_blocks = 0;
  for (int i = 0; i < lengths.size(); i++) {
    total_num_blocks += (long long int) ceil(((double) lengths[i]) / REF_BLOCK_LEN);
  }
  long long int bank_num_blocks[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    bank_num_blocks[i] = total_num_blocks / NUM_FPGAS;
    if (i < total_num_blocks % NUM_FPGAS) {
      bank_num_blocks[i]++;
    }
  }

  // Build ref seq data
  std::vector<std::string> chr_names;
  std::vector<long long int> chr_lengths;
  std::vector<long long int> chr_filepos;
  std::vector<std::vector<RefSeqBank> > chr_bank_infos;
  std::vector<RefSeqBank> ref_bank_infos;
  for (int i = 0; i < NUM_FPGAS; i++) {
    RefSeqBank rsb;
    rsb.fpga = i;
    //rsb.addr = cur_block_[i];
    ref_bank_infos.push_back(rsb);
  }
  int cur_fpga = 0;
  int num_blocks_stored = 0;
  std::ofstream fpga2bitfiles[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    fpga2bitfiles[i].open(ref_dir_ + "/" + ref_name + "." + std::to_string(i) + ".fpga2bit");
  }
  
  long long int cur_block[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    cur_block[i] = 0;
  }

  long long int cur_ref_offset = 0;
  ref_bank_infos[0].start_coord = 0;
  for (int i = 0; i < seqs.size(); i++) {
    // Record sequence information
    chr_names.push_back(descrips[i][CHR_NAME_FIELD]);
    chr_lengths.push_back(lengths[i]);
    chr_filepos.push_back(fileposs[i]);
    
    long long int cur_offset = 0;
    std::vector<RefSeqBank> chr_seq_region_infos;
    while (cur_offset < lengths[i]) {
      // Compute sequence length to stream this iteration
      long long int seq_length = lengths[i] - cur_offset;
      long long int seq_num_blocks = (long long int) ceil(((double) seq_length) / REF_BLOCK_LEN);
      int overlap_length = 0;
      if (num_blocks_stored + seq_num_blocks > bank_num_blocks[cur_fpga]) {
        seq_length = (bank_num_blocks[cur_fpga] - num_blocks_stored) * REF_BLOCK_LEN;
        seq_num_blocks = bank_num_blocks[cur_fpga] - num_blocks_stored;
        overlap_length = kOverlapLength;
        if (cur_offset + seq_length + overlap_length > lengths[i]) {
          overlap_length = lengths[i] - (cur_offset + seq_length);
        }
      }
      long long int num_blocks_to_store = (long long int) ceil(((double) (seq_length + overlap_length)) / REF_BLOCK_LEN);

      //std::cout << cur_fpga << " " << descrips[i][CHR_NAME_FIELD] << " " << cur_offset << " " << seq_length << " " << overlap_length << std::endl;

      // Compute length of 2-bit formatted ref seq buffer
      //   Pad ref seq buffer to hold a multiple of REF_BLOCK_LEN nucleotides
      long long int twobit_buf_length = num_blocks_to_store * (REF_BLOCK_LEN / 4);

      // Build 2-bit formatted ref seq buffer
      //   Replace N's with random nucleotide
      char* twobit_buf = new char[twobit_buf_length];
      for (int j = 0; j < twobit_buf_length; j++) {
        char val = 0;
        for (int k = j*4+3; k >= j*4; k--) {
          val <<= 2;
          if (k < seq_length + overlap_length) {
            if (seqs[i][cur_offset + k] != 'N' && seqs[i][cur_offset + k] != 'n') {
              val += NtChar2Int(seqs[i][cur_offset + k]);
            } else {
              val += (rand() % 4);
            }
          }
        }
        twobit_buf[j] = val;
      }  
          
      // Write sequence to fpga2bit file
      fpga2bitfiles[cur_fpga].write(twobit_buf, twobit_buf_length);
      delete[] twobit_buf;
          
      // Store the chromosome bank information
      RefSeqBank loc;
      loc.fpga = cur_fpga;
      loc.start_coord = cur_offset;
      loc.end_coord = cur_offset + seq_length;
      loc.overlap_len = overlap_length;
      loc.addr = cur_block[cur_fpga];
      chr_seq_region_infos.push_back(loc);

      // Update counters
      cur_offset += seq_length;
      num_blocks_stored += seq_num_blocks;
      cur_block[cur_fpga] += num_blocks_to_store;
      cur_ref_offset += num_blocks_to_store * REF_BLOCK_LEN;
      assert(num_blocks_stored <= bank_num_blocks[cur_fpga]);
      if (num_blocks_stored == bank_num_blocks[cur_fpga]) {
        cur_ref_offset -= overlap_length;
        ref_bank_infos[cur_fpga].end_coord = cur_ref_offset;
        ref_bank_infos[cur_fpga].overlap_len = overlap_length;
        
        num_blocks_stored = 0;
        cur_fpga++;
        
        if (cur_fpga < NUM_FPGAS) {
          ref_bank_infos[cur_fpga].start_coord = cur_ref_offset;
        }
      }
    }
    
    chr_bank_infos.push_back(chr_seq_region_infos);
  }
  
  // Close fpga2bit file streams
  for (int i = 0; i < NUM_FPGAS; i++) {
    fpga2bitfiles[i].close();
  }

  // Write FPGA metadata file
  std::ofstream fpgametafile(ref_dir_ + "/" + ref_name + ".meta");
  assert(chr_names.size() == chr_lengths.size());
  assert(chr_lengths.size() == chr_filepos.size());
  assert(chr_filepos.size() == chr_bank_infos.size());
  std::string chr_num_str = std::to_string(chr_names.size());                     // Number of chromosomes
  fpgametafile.write(chr_num_str.c_str(), chr_num_str.size());
  fpgametafile.write("\n", 1);
  for (int i = 0; i < chr_names.size(); i++) {                                    // Chromosome names
    fpgametafile.write(chr_names[i].c_str(), chr_names[i].size());
    if (i != chr_names.size() - 1) {
      fpgametafile.write(" ", 1);
    } else {
      fpgametafile.write("\n", 1);
    }
  }
  for (int i = 0; i < chr_lengths.size(); i++) {                                  // Chromosome lengths
    std::string chr_length_str = std::to_string(chr_lengths[i]);
    fpgametafile.write(chr_length_str.c_str(), chr_length_str.size());
    if (i != chr_lengths.size() - 1) {
      fpgametafile.write(" ", 1);
    } else {
      fpgametafile.write("\n", 1);
    }
  }
  for (int i = 0; i < chr_filepos.size(); i++) {                                  // Chromosome file positions
    std::string chr_filepos_str = std::to_string(chr_filepos[i]);
    fpgametafile.write(chr_filepos_str.c_str(), chr_filepos_str.size());
    if (i != chr_filepos.size() - 1) {
      fpgametafile.write(" ", 1);
    } else {
      fpgametafile.write("\n", 1);
    }
  }
  for (int i = 0; i < chr_bank_infos.size(); i++) {
    std::string bank_size_str = std::to_string(chr_bank_infos[i].size());         // Number of chromosome banks
    fpgametafile.write(bank_size_str.c_str(), bank_size_str.size());
    fpgametafile.write("\n", 1);
    for (int j = 0; j < chr_bank_infos[i].size(); j++) {                          // Chromosome bank info
      std::string bank_str = std::to_string(chr_bank_infos[i][j].fpga) + " ";
      bank_str += std::to_string(chr_bank_infos[i][j].start_coord) + " ";
      bank_str += std::to_string(chr_bank_infos[i][j].end_coord) + " ";
      bank_str += std::to_string(chr_bank_infos[i][j].overlap_len) + " ";
      bank_str += std::to_string(chr_bank_infos[i][j].addr) + "\n";
      fpgametafile.write(bank_str.c_str(), bank_str.size());
    }  
  }
  for (int i = 0; i < NUM_FPGAS; i++) {                                           // Ref seq bank info
    std::string bank_str = std::to_string(ref_bank_infos[i].fpga) + " ";
    bank_str += std::to_string(ref_bank_infos[i].start_coord) + " ";
    bank_str += std::to_string(ref_bank_infos[i].end_coord) + " ";
    bank_str += std::to_string(ref_bank_infos[i].overlap_len) + "\n";
    fpgametafile.write(bank_str.c_str(), bank_str.size());
  }
  fpgametafile.close();
  
  // Clean up sequence memory
  for (int i = 0; i < seqs.size(); i++) {
    delete[] seqs[i];
  }
}

void RefSeqManager::LoadRef(std::string ref_fa_filename, std::string ref_name) {
  std::cout << "Loading ref " << ref_name << "..." << std::endl;

  struct timespec start, finish;
  double elapsed;
  
  // Load metadata file and store info in shared data structures
  int num_chr;
  std::map<std::string, int> chr_ids;
  std::vector<std::string> chr_names;
  std::vector<long long int> chr_lengths;
  std::vector<long long int> chr_fileposs;
  std::vector<std::vector<RefSeqBank> > chr_bank_infos;
  std::vector<RefSeqBank> ref_bank_infos;
  std::ifstream fpgametafile(ref_dir_ + "/" + ref_name + ".meta");
  assert(fpgametafile.is_open() == true);
  fpgametafile >> num_chr;
  for (int i = 0; i < num_chr; i++) {
    std::string chr_name;
    fpgametafile >> chr_name;
    chr_names.push_back(chr_name);
    chr_ids[chr_name] = i;
  }
  for (int i = 0; i < num_chr; i++) {
    long long int chr_length;
    fpgametafile >> chr_length;
    chr_lengths.push_back(chr_length);
  }
  for (int i = 0; i < num_chr; i++) {
    long long int chr_filepos;
    fpgametafile >> chr_filepos;
    chr_fileposs.push_back(chr_filepos);
  }
  for (int i = 0; i < num_chr; i++) {
    int num_banks;
    fpgametafile >> num_banks;
    std::vector<RefSeqBank> banks;
    for (int j = 0; j < num_banks; j++) {
      RefSeqBank bank;
      fpgametafile >> bank.fpga;
      fpgametafile >> bank.start_coord;
      fpgametafile >> bank.end_coord;
      fpgametafile >> bank.overlap_len;
      fpgametafile >> bank.addr;          // Address offset of the chr within the ref seq
      //bank.addr += cur_block_[bank.fpga]; // Compute absolute address within the DRAM
      banks.push_back(bank);
    }
    chr_bank_infos.push_back(banks);
  }
  long long int ref_bank_size = 0;
  for (int i = 0; i < NUM_FPGAS; i++) {
    RefSeqBank bank;
    fpgametafile >> bank.fpga;
    fpgametafile >> bank.start_coord;
    fpgametafile >> bank.end_coord;
    fpgametafile >> bank.overlap_len;
    //bank.addr = cur_block_[bank.fpga];
    //fpgametafile >> bank.addr;
    ref_bank_infos.push_back(bank);
    
    long long int cur_ref_bank_size = (long long int) ceil(((double) (bank.end_coord - bank.start_coord + bank.overlap_len)) / REF_BLOCK_LEN);
    ref_bank_size = ref_bank_size > cur_ref_bank_size ? ref_bank_size : cur_ref_bank_size;
  }
  fpgametafile.close();
  
  // Record reference sequence metadata
  ref_id_[ref_name] = ref_name_.size();
  ref_name_.push_back(ref_name);
  ref_file_.push_back(ref_dir_ + "/" + ref_fa_filename);
  chr_id_.push_back(chr_ids);
  chr_name_.push_back(chr_names);
  chr_filepos_.push_back(chr_fileposs);
  chr_length_.push_back(chr_lengths);
  chr_bank_info_.push_back(chr_bank_infos);
  ref_bank_info_.push_back(ref_bank_infos);

  // Load fpga2bit files to DRAM and update current block counters
  /*for (int i = 0; i < NUM_FPGAS; i++) {
    // Get file size
    clock_gettime(CLOCK_MONOTONIC, &start);
    std::ifstream fpga2bitfile(ref_dir_ + "/" + ref_name + "." + std::to_string(i) + ".fpga2bit");
    assert(fpga2bitfile.is_open() == true);
    fpga2bitfile.seekg(0, fpga2bitfile.end);
    long size = fpga2bitfile.tellg();
    fpga2bitfile.seekg(0);
    assert(size % (REF_BLOCK_LEN / NT_PER_BYTE) == 0);
    total_ref_length_ += (size * NT_PER_BYTE);
    
    // Read 2bit file into buffer
    char* buffer = new char[size];
    fpga2bitfile.read(buffer, size);
    fpga2bitfile.close();
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    disk_refseqload_time_ += elapsed;
    
    // Write the ref seq to the FPGA DRAM
    clock_gettime(CLOCK_MONOTONIC, &start);
    char ibuf[1024];
    int err = pico_drivers_[i]->WriteRam(cur_block_[i] * (REF_BLOCK_LEN / 4), (void*) buffer, size);
    if (err < 0) {
      fprintf(stderr, "Failed to write ref seq to FPGA %d, error: %s\n", i, 
              PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
    fpga_refseqload_time_ += elapsed;

    // Update counter
    cur_block_[i] += (size / (REF_BLOCK_LEN / 4));
    delete[] buffer;
  }*/
  
  // Store bookkeeping information into FPGA DRAM Manager
  fpga_dram_manager_.AddRef(ref_id_[ref_name], ref_bank_size, ref_name);
}
