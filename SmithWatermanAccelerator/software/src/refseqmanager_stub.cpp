//  File Name        : refseqmanager_stub.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision (dummy implementation)
//

#include "refseqmanager_stub.h"
#include <string>

RefSeqManager::RefSeqManager() {
  ref_seq_ = new char[REF_LENGTH];
  std::string ref_seq = "AGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCG"
  memcpy(ref_seq_, ref_seq.c_str(), REF_LENGTH);
}

RefSeqManager::~RefSeqManager() {
  delete[] ref_seq_;
}

int RefSeqManager::ref_length() {
  return (int) REF_LENGTH;
}

char* GetRefSeq(uint32_t ref_id, uint32_t ref_offset, uint32_t ref_len) {
  if (ref_offset + ref_len > REF_LENGTH) {
    return NULL;
  }

  return &(ref_seq_[ref_offset]);
}

