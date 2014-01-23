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
#include "refseqmanager.h"
#include "utils.h"
#include "fasta.h"
#ifdef SIM_PICO
  #include "picodrv_sim.h"
#else
  #include <picodrv.h>
  #include <pico_errors.h>
#endif

static const int CHR_NAME_FIELD = 0;

RefSeqManager::RefSeqManager() {
}

RefSeqManager::RefSeqManager(PicoDrv** pico_drivers) {
  Init(pico_drivers);
}

void RefSeqManager::Init(PicoDrv** pico_drivers) {
  srand(time(NULL));
  
  for (int i = 0; i < NUM_FPGAS; i++) {
    cur_block_[i] = 0;
  }
  pico_drivers_ = pico_drivers;
  total_ref_length_ = 0;
  
  pthread_mutex_init(&ref_fd_listmap_mutex_, NULL);
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
  
  pthread_mutex_unlock(&(ref_fd_mutex_[ref_id]));  
  
  char* seq = new char[ref_len];
  seqline.copy(seq, ref_len);
  
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

void RefSeqManager::AddRef(std::string ref_file, std::string ref_name) {
  std::vector<std::vector<std::string> > descrips;
  std::vector<char*> seqs;
  std::vector<long long int> lengths;
  std::vector<long long int> fileposs;

  // Parse FASTA files
  ParseFastaFile(ref_file, &descrips, &seqs, &lengths, &fileposs);
  assert(descrips.size() == seqs.size());
  assert(seqs.size() == lengths.size());
  assert(lengths.size() == fileposs.size());
  
  // Compute ref seq bank lengths
  long long int total_num_blocks = 0;
  for (int i = 0; i < lengths.size(); i++) {
    total_num_blocks += (long long int) ceil(((double) lengths[i]) / REF_BLOCK_LEN);
  }
  //std::cout << ref_name << " total num blocks: " << total_num_blocks << std::endl;
  long long int bank_num_blocks[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    bank_num_blocks[i] = total_num_blocks / NUM_FPGAS;
    if (i < total_num_blocks % NUM_FPGAS) {
      bank_num_blocks[i]++;
    }
    //std::cout << "Bank " << i << " num blocks: " << bank_num_blocks[i] << std::endl;
  }

  // Store ref seq data
  int ref_id = ref_name_.size();
  std::map<std::string, int> chr_ids;
  std::vector<std::string> chr_names;
  std::vector<long long int> chr_lengths;
  std::vector<long long int> chr_filepos;
  std::vector<std::vector<RefSeqBank> > ref_seq_bank_infos;
  int cur_fpga = 0;
  int num_blocks_stored = 0;

  for (int i = 0; i < seqs.size(); i++) {
    // Record sequence information
    int chr_id = chr_names.size();
    chr_ids[descrips[i][CHR_NAME_FIELD]] = chr_id;
    chr_names.push_back(descrips[i][CHR_NAME_FIELD]);
    chr_lengths.push_back(lengths[i]);
    chr_filepos.push_back(fileposs[i]);
    total_ref_length_ += lengths[i];
    
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
      //std::cout << "Bank length " << seq_length << "\tOverlap length " << overlap_length << "\tNum blocks to store " << num_blocks_to_store<<std::endl;

      // Stream the sequence
      StreamRefSeq(cur_fpga, &(seqs[i][cur_offset]), cur_block_[cur_fpga], seq_length + overlap_length);
      /*std::cout << "Ref ID: "           << ref_id 
                << "\tRef Name: "       << ref_name 
                << "\tChr ID: "         << chr_id 
                << "\tChr Name: "       << descrips[i][CHR_NAME_FIELD] 
                << "\tChr Offset: "     << cur_offset
                << "\tSeq Length: "     << seq_length
                << "\tOverlap Length: " << overlap_length
                << "\tFPGA: "           << cur_fpga
                << "\tAddress: "        << cur_block_[cur_fpga]
                << std::endl;*/
                
      // Store the chromosome bank information
      RefSeqBank loc;
      loc.fpga = cur_fpga;
      loc.start_coord = cur_offset;
      loc.end_coord = cur_offset + seq_length;
      loc.overlap_len = overlap_length;
      loc.addr = cur_block_[cur_fpga];
      chr_seq_region_infos.push_back(loc);

      // Update counters
      cur_offset += seq_length;
      cur_block_[cur_fpga] += num_blocks_to_store;
      num_blocks_stored += seq_num_blocks;
      assert(num_blocks_stored <= bank_num_blocks[cur_fpga]);
      if (num_blocks_stored == bank_num_blocks[cur_fpga]) {
        num_blocks_stored = 0;
        cur_fpga++;
      }
    }
    
    ref_seq_bank_infos.push_back(chr_seq_region_infos);
  }

  // Record reference sequence metadata
  ref_name_.push_back(ref_name);
  ref_file_.push_back(ref_file);
  ref_id_[ref_name] = ref_id;
  chr_id_.push_back(chr_ids);
  chr_name_.push_back(chr_names);
  chr_filepos_.push_back(chr_filepos);
  chr_length_.push_back(chr_lengths);
  ref_seq_bank_info_.push_back(ref_seq_bank_infos);
  
  // Initialize and add a mutex for ref seq file
  pthread_mutex_t ref_mutex;
  pthread_mutex_init(&ref_mutex, NULL);
  ref_fd_mutex_.push_back(ref_mutex);
  
  // Clean up ref seq memory
  for (int i = 0; i < seqs.size(); i++) {
    delete seqs[i];
  }
}

void RefSeqManager::StreamRefSeq(int fpga, char* ref_seq, long long int ref_addr, long long int ref_length) {
  assert(REF_BLOCK_LEN % 4 == 0);
  //std::cout << "Streaming to FPGA " << fpga << "\tRef addr " << ref_addr << "\t Ref len " << ref_length << std::endl;

  // Compute length of 2-bit formatted ref seq buffer
  //   Pad ref seq buffer to hold a multiple of REF_BLOCK_LEN nucleotides
  long long int twobit_buf_length = ((long long int) ceil(((double) ref_length) / REF_BLOCK_LEN)) * (REF_BLOCK_LEN / 4);

  // Build 2-bit formatted ref seq buffer
  // Replace N's with random nucleotide
  char* twobit_buf = new char[twobit_buf_length];
  for (int i = 0; i < twobit_buf_length; i++) {
    char val = 0;
    for (int j = i*4+3; j >= i*4; j--) {
      val <<= 2;
      if (j < ref_length) {
        if (ref_seq[j] != 'N' && ref_seq[j] != 'n') {
          val += NtChar2Int(ref_seq[j]);
        } else {
          val += (rand() % 4);
        }
      }
    }
    twobit_buf[i] = val;
  }

  // Write the ref seq to the FPGA DRAM
  int err;
  char ibuf[1024];
  err = pico_drivers_[fpga]->WriteRam(ref_addr * (REF_BLOCK_LEN / 4), (void*) twobit_buf, twobit_buf_length);
  if (err < 0) {
    fprintf(stderr, "Failed to write ref seq to FPGA %d, error: %s\n", fpga, 
            PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
  }

  delete[] twobit_buf;
}

std::vector<RefSeqManager::RefSeqBank> RefSeqManager::GetRefSeqBanks(int ref_id, int chr_id, 
                                                      long long int start_coord, long long int end_coord) {
  std::vector<RefSeqBank> locs;
  for (std::vector<RefSeqBank>::iterator it = ref_seq_bank_info_[ref_id][chr_id].begin();
       it != ref_seq_bank_info_[ref_id][chr_id].end();
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
      
      locs.push_back(loc);
    }
  }
  
  return locs;
}

long long int RefSeqManager::GetTotalRefLength() {
  return total_ref_length_;
}
