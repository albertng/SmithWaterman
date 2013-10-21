//  File Name        : refseqmanager.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 18 2013     Initial Revision
//      Albert Ng   Oct 19 2013     Completed StreamRefSeq()

#include "refseqmanager.h"
#include "def.h"
#include "utils.h"
#include "picodrv_stub.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

RefSeqManager::RefSeqManager() {
  cur_ref_id_ = 0;
  cur_block_ = 0;
  srand(time(NULL));
}

RefSeqManager::RefSeqManager(PicoDrv* pico_drivers) {
  Init(pico_drivers);
}

void RefSeqManager::Init(PicoDrv* pico_drivers) {
  cur_ref_id_ = 0;
  cur_block_ = 0;
  pico_drivers_ = pico_drivers;
}

char* RefSeqManager::GetRefSeq(int ref_id, long long int ref_offset, long long int ref_len) {
  if (ref_seq_.count(ref_id) > 0) {
    if (ref_offset + ref_len <= ref_length_[ref_id]) {
      char* ref_seq = ref_seq_[ref_id];
      return &(ref_seq[ref_offset]);
    } else {
      std::cerr << "Error: Ref offset and length exceed reference sequence bounds." << std::endl;
    }
  } else {
    std::cerr << "Error: Invalid ref ID " << ref_id << "." << std::endl;
    return NULL;
  }
}

long long int RefSeqManager::GetRefAddr(int ref_id) {
  return ref_addr_[ref_id];
}

long long int RefSeqManager::GetRefLength(int ref_id) {
  return ref_length_[ref_id];
}

int RefSeqManager::GetRefID(std::string ref_name) {
  return ref_id_[ref_name];
}

// Note: FASTA reader not very robust
void RefSeqManager::AddRef(std::string filename) {
  std::ifstream ref_file(filename.c_str());
  if (!ref_file.is_open()) {
    std::cerr << "Error: Could not open reference sequence file " << filename << "." << std::endl;
    return;
  }

  // First go through the file to assign ref IDs and get sequence names, 
  //   lengths, and block addresses
  std::string line;
  int cur_length = 0;
  int first_ref_id = cur_ref_id_;
  std::vector<int> lengths;
  bool first_ref = true;
  while (getline(ref_file, line)) {
    if (line.length() == 0) {
      continue;
    }
    if (line[0] == '>') {
      if (first_ref == false) {
        if (cur_length % REF_BLOCK_LEN == 0) {
          cur_block_ += (cur_length / REF_BLOCK_LEN);
        } else {
          cur_block_ += ((cur_length / REF_BLOCK_LEN) + 1);
        }

        ref_length_[cur_ref_id_ - 1] = cur_length;
        lengths.push_back(cur_length);
        cur_length = 0;
      }
      std::string name = GetFastaSeqName(line);
      ref_id_[name] = cur_ref_id_;
      ref_name_[cur_ref_id_] = name;
      ref_addr_[cur_ref_id_] = cur_block_;
      cur_ref_id_++;
    } else {
      cur_length += line.length();
    }
    first_ref = false;
  }
  ref_length_[cur_ref_id_ - 1] = cur_length;
  lengths.push_back(cur_length);

  // Allocate char array memory
  for (int i = 0; i < lengths.size(); i++) {
    char* seq = new char[lengths[i]];
    ref_seq_[i + first_ref_id] = seq;
  }

  // Go through file again and fill char arrays with sequences
  ref_file.close();
  ref_file.open(filename.c_str());
  //ref_file.seekg(0, std::ios::beg);
  int cur_ref = first_ref_id - 1;
  char* seq;
  int index;
  bool first = true;
  while (getline(ref_file, line)) {
    if (line[0] == '>') {
      if (first == false) {
        StreamRefSeq(ref_seq_[cur_ref], ref_addr_[cur_ref], ref_length_[cur_ref]);
      }
      cur_ref++;
      seq = ref_seq_[cur_ref];
      index = 0;
    } else {
      line.copy(&(seq[index]), line.length());
      index += line.length();
    }
  }
  StreamRefSeq(ref_seq_[cur_ref], ref_addr_[cur_ref], ref_length_[cur_ref]);

  for (int i = 0; i < lengths.size(); i++) {
    int ref_id = i + first_ref_id;
    std::cout<<"Ref ID: "<<ref_id<<"\tName: "<<ref_name_[ref_id]<<"\tRef Len: "<<ref_length_[ref_id]<<"\tRef Addr: "<<ref_addr_[ref_id]<<std::endl;
    char* seq = ref_seq_[ref_id];
    for (int j = 0; j < ref_length_[ref_id]; j++) {
      std::cout << seq[j];
    }
    std::cout << '\n' << std::endl;
  } 
}

std::string RefSeqManager::GetFastaSeqName(std::string line) {
  std::string name;
  for (int i = 1; i < line.length(); i++) {
    if (isalpha(line[i]) || isdigit(line[i])) {
      name.push_back(line[i]);
    } else {
      break;
    }
  }
  return name;
}

void RefSeqManager::StreamRefSeq(char* ref_seq, long long int ref_addr, long long int ref_length) {
  // Compute length of 2-bit formatted ref seq buffer
  // Pad ref seq buffer hold a multiple of REF_BLOCK_LEN nucleotides
  int ref_buf_length = ref_length / REF_BLOCK_LEN;
  if (ref_length % REF_BLOCK_LEN != 0) {
    ref_buf_length++;
  }
  ref_buf_length *= (REF_BLOCK_LEN / 4);

  // Build 2-bit formatted ref seq buffer
  // Replace N's with random nucleotide
  char* ref_buf = new char[ref_buf_length];
  for (int i = 0; i < ref_buf_length; i++) {
    char val = 0;
    for (int j = i*4+3; j >= i*4; j--) {
      val <<= 2;
      if (j < ref_length) {
        if (ref_seq[j] != 'N') {
          val += NtChar2Int(ref_seq[j]);
        } else {
          val += (rand() % 4);
        }
      }
    }
    ref_buf[i] = val;
  }

  // Write the ref seq to the FPGA DRAMS
  int err;
  char ibuf[1024];
  for (int i = 0; i < NUM_FPGAS; i++) {
    err = pico_drivers[i].WriteRam(ref_addr, ref_buf, ref_buf_length, PICO_DDR3_0);
    if (err < 0) {
      fprintf(stderr, "Failed to write ref seq to FPGA %d, error: %s\n", i, 
              PicoErrors_FullError(err, ibuf, sizeof(ibuf)));
    }
  }

  delete[] ref_buf;
}

