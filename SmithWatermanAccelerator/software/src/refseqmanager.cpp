//  File Name        : refseqmanager.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 19 2013     Completed StreamRefSeq()
//      Albert Ng   Oct 29 2013     Uses fasta.h to parse FASTA files
//      Albert Ng   Nov 01 2013     Added GetRefName()
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 14 2013     Added ref seq banking

#include "def.h"
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
  //cur_block_ = 0;
  for (int i = 0; i < NUM_FPGAS; i++) {
    cur_block_[i] = 0;
  }
  srand(time(NULL));
}

RefSeqManager::RefSeqManager(PicoDrv** pico_drivers) {
  Init(pico_drivers);
}

void RefSeqManager::Init(PicoDrv** pico_drivers) {
  //cur_block_ = 0;
  for (int i = 0; i < NUM_FPGAS; i++) {
    cur_block_[i] = 0;
  }
  pico_drivers_ = pico_drivers;
}

char* RefSeqManager::GetRefSeq(int ref_id, int chr_id, long long int ref_offset, long long int ref_len) {
  assert(ref_id < ref_seq_.size());
  assert(ref_offset + ref_len <= ref_length_[ref_id][chr_id]);
  char* ref_seq = ref_seq_[ref_id][chr_id];
  return &(ref_seq[ref_offset]);
}

long long int RefSeqManager::GetRefAddr(int ref_id, int chr_id) {
  assert(ref_id < ref_addr_.size());
  assert(chr_id < ref_addr_[ref_id].size());
  return ref_addr_[ref_id][chr_id];
}

long long int RefSeqManager::GetRefLength(int ref_id, int chr_id) {
  assert(ref_id < ref_length_.size());
  assert(chr_id < ref_length_[ref_id].size());
  return ref_length_[ref_id][chr_id];
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

/*void RefSeqManager::AddRef(std::string filename, std::string ref_name) {
  std::vector<std::vector<std::string> > descrips;
  std::vector<char*> seqs;
  std::vector<int> lengths;
  
  ParseFastaFile(filename, &descrips, &seqs, &lengths);

  int ref_id;
  if (ref_id_.count(ref_name) == 0) {
    ref_id = ref_name_.size();
    ref_id_[ref_name] = ref_id;
    
    std::map<std::string, int> chr_id_v;
    chr_id_.push_back(chr_id_v);
    
    ref_name_.push_back(ref_name);
    
    std::vector<std::string> chr_name_v;
    chr_name_.push_back(chr_name_v);
    
    std::vector<char*> ref_seq_v;
    ref_seq_.push_back(ref_seq_v);
    
    std::vector<long long int> ref_addr_v;
    ref_addr_.push_back(ref_addr_v);
    
    std::vector<long long int> ref_length_v;
    ref_length_.push_back(ref_length_v);
  } else {
    ref_id = ref_id_[ref_name];
  }
    
  for (int i = 0; i < seqs.size(); i++) {     
    // Stream ref seq to DRAM
    StreamRefSeq(seqs[i], ((long long int) cur_block_) * (REF_BLOCK_LEN/4), lengths[i]);
    
    // Record ref seq information
    int chr_id = chr_name_[ref_id].size();
    chr_id_[ref_id][descrips[i][CHR_NAME_FIELD]] = chr_id;
    chr_name_[ref_id].push_back(descrips[i][CHR_NAME_FIELD]);
    ref_seq_[ref_id].push_back(seqs[i]);
    ref_addr_[ref_id].push_back(cur_block_);
    ref_length_[ref_id].push_back(lengths[i]);

    std::cout << "Ref ID: " << ref_id << "\tRef Name: " << ref_name_[ref_id] 
              << "\tChr ID: " << chr_id << "\tChr Name: " << chr_name_[ref_id][chr_id]
              << "\tRef Len: " << ref_length_[ref_id][chr_id] << "\tRef Addr: " << ref_addr_[ref_id][chr_id]
              << std::endl;

    //std::cout<<"Ref ID: "<<cur_ref_id_<<"\tName: "<<ref_name_[cur_ref_id_]<<"\tRef Len: "<<ref_length_[cur_ref_id_]<<"\tRef Addr: "<<ref_addr_[cur_ref_id_]<<std::endl;
    //for (int j = 0; j < ref_length_[cur_ref_id_]; j++) {
    //  std::cout<<seqs[i][j];
    //}
    //std::cout << '\n' << std::endl;

    // Move to next ref seq
    if (lengths[i] % REF_BLOCK_LEN == 0) {
      cur_block_ += (lengths[i] / REF_BLOCK_LEN);
    } else {
      cur_block_ += ((lengths[i] / REF_BLOCK_LEN) + 1);
    }
  }
}*/

void RefSeqManager::AddRef(std::vector<std::string> ref_files, std::string ref_name) {
  std::vector<std::vector<std::string> > descrips;
  std::vector<char*> seqs;
  std::vector<int> lengths;

  // Parse FASTA files
  for (int i = 0; i < ref_files.size(); i++) {
    ParseFastaFile(filename, &descrips, &seqs, &lengths);
  }

  // Compute ref seq bank lengths
  long long int total_num_blocks = 0;
  for (int i = 0; i < lengths.size(); i++) {
    total_num_blocks += (long long int) ceil(((float) lengths[i]) / REF_BLOCK_LEN);
  }
  long long int bank_num_blocks[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    bank_num_blocks[i] = total_num_blocks / NUM_FPGAS;
    if (i < total_num_blocks % NUM_FPGAS) {
      bank_num_blocks[i]++;
    }
  }

  // Store ref seq data
  int ref_id = ref_name_.size();
  std::map<std::string, int> chr_ids;
  std::vector<std::string> chr_names;
  std::vector<char*> chr_seqs;
  std::vector<long long int> chr_lengths;
  std::vector<std::vector<RefSeqBank> > ref_seq_bank_infos;
  int cur_fpga = 0;
  int num_blocks_stored = 0;
  for (int i = 0; i < seqs.size(); i++) {
    // Record sequence information
    int chr_id = chr_names.size();
    chr_ids[descrips[i][CHR_NAME_FIELD]] = chr_id;
    chr_names.push_back(descrips[i][CHR_NAME_FIELD]);
    chr_seqs.push_back(seqs[i]); // TODO: Probably change this
    chr_lengths.push_back(lengths[i]);
    
    long long int cur_offset = 0;
    std::vector<RefSeqBank> chr_seq_region_infos;
    while (cur_offset < lengths[i]) {
      // Compute sequence length to stream this iteration
      long long int seq_length = lengths[i] - cur_offset;
      long long int seq_num_blocks = (long long int) ceil(((float) seq_length) / REF_BLOCK_LEN);
      int overlap_length = 0;
      if (num_blocks_stored + seq_num_blocks > bank_num_blocks[cur_fpga]) {
        seq_length = (bank_num_blocks[cur_fpga] - num_blocks_stored) * (REF_BLOCK_LEN / 4);
        overlap_length = kOverlapLength;
        if (cur_offset + seq_length + overlap_length > lengths[i]) {
          overlap_length = lengths[i] - (cur_offset + seq_length);
        }
      }
      long long int num_blocks_to_store = (long long int) ceil(((float) (seq_length + overlap_length)) / REF_BLOCK_LEN)

      // Stream the sequence
      StreamRefSeq(cur_fpga, &(seqs[i][cur_offset]), cur_block_[cur_fpga] * (REF_BLOCK_LEN / 4), seq_length + overlap_length);
      std::cout << "Ref ID: "           << ref_id 
                << "\tRef Name: "       << ref_name 
                << "\tChr ID: "         << chr_id 
                << "\tChr Name: "       << descrips[i][CHR_NAME_FIELD] 
                << "\tChr Offset: "     << cur_offset
                << "\tSeq Length: "     << seq_length
                << "\tOverlap Length: " << overlap_length
                << "\tFPGA: "           << cur_fpga
                << "\tAddress: "        << cur_block_[cur_fpga]
                << std::endl;
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
      num_blocks_stored += num_blocks_to_store;
      if (num_blocks_stored >= bank_num_blocks[cur_fpga]) {
        num_blocks_stored = 0;
        cur_fpga++;
      }
    }
    
    ref_seq_bank_infos.push_back(chr_seq_region_infos);
  }

  // Record reference sequence metadata
  ref_name_.push_back(ref_name);
  ref_id_[ref_name] = ref_id;
  chr_id_.push_back(chr_ids);
  chr_name_.push_back(chr_names);
  ref_seq_.push_back(chr_seqs);
  ref_length_.push_back(chr_lengths);
  ref_seq_bank_info_.push_back(ref_seq_bank_infos);
}

// Note: ref_addr is the BYTE address in the FPGA DRAM to stream to
void RefSeqManager::StreamRefSeq(int fpga, char* ref_seq, long long int ref_addr, long long int ref_length) {
  assert(REF_BLOCK_LEN % 4 == 0);

  // Compute length of 2-bit formatted ref seq buffer
  // Pad ref seq buffer to hold a multiple of REF_BLOCK_LEN nucleotides
  long long int twobit_buf_length = ((long long int) ceil(((float) ref_length) / REF_BLOCK_LEN)) * (REF_BLOCK_LEN / 4);

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
  err = pico_drivers_[fpga]->WriteRam(ref_addr, (void*) twobit_buf, twobit_buf_length);
  if (err < 0) {
    fprintf(stderr, "Failed to write ref seq to FPGA %d, error: %s\n", fpga, 
            PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
  }

  delete[] twobit_buf;
}

std::vector<RefSeqBank> RefSeqManager::GetRefSeqBanks(int ref_id, int chr_id, 
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
    }
  
    locs.push_back(loc);
  }
  
  return locs;
}

