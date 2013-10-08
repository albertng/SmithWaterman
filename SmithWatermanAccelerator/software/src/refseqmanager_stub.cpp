//  File Name        : refseqmanager_stub.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision (dummy implementation)
//

#include "refseqmanager_stub.h"
#include <string>

RefSeqManager::RefSeqManager() {
  ref_seq_ = (char*) "AGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCG";
}

RefSeqManager::~RefSeqManager() {
}

int RefSeqManager::ref_length() {
  return (int) REF_LENGTH;
}

char* RefSeqManager::GetRefSeq(uint32_t ref_id, uint32_t ref_offset, uint32_t ref_len) {
  if (ref_offset + ref_len > REF_LENGTH) {
    return NULL;
  }

  return &(ref_seq_[ref_offset]);
}

