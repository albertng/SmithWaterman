//  File Name        : refseqmanager_stub.h
//  Description      : Reference sequence manager definitions
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision (dummy implementation)
//

#ifndef REFSEQMANAGERSTUB_H_
#define REFSEQMANAGERSTUB_H_

#include <stdint.h>

class RefSeqManager {
  public :
    RefSeqManager();
    ~RefSeqManager();
    char *GetRefSeq(uint32_t ref_id, uint32_t ref_offset, uint32_t ref_len);
    int ref_length();

  private :
    char* ref_seq_;
    static const int REF_LENGTH = 256;
    
};

#endif // REFSEQMANAGERSTUB_H_
