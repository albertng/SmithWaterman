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
    char *GetRefSeq(int ref_id, long long int ref_offset, long long int ref_len);
    long long int GetRefAddr(int ref_id);
    long long int GetRefLength(int ref_id);
  private :
    char* ref_seq_;
    long long int ref_seq_offset_;
};

#endif // REFSEQMANAGERSTUB_H_
