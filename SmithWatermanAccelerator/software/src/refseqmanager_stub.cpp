//  File Name        : refseqmanager_stub.cpp
//  Description      : Reference sequence manager
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision (dummy implementation)
//

#include "refseqmanager_stub.h"
#include <cstring>

RefSeqManager::RefSeqManager() {
  ref_seq_ = (char*) "AGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCGAGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCGAGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCGAGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCG";
}

RefSeqManager::~RefSeqManager() {
}

long long int RefSeqManager::ref_length() {
  return (long long int) strlen(ref_seq_);
}

char* RefSeqManager::GetRefSeq(int ref_id, long long int ref_offset, long long int ref_len) {
  if (ref_offset + ref_len > strlen(ref_seq_)) {
    return NULL;
  }

  return &(ref_seq_[ref_offset]);
}

