//  File Name        : refseqmanager.h
//  Description      : Reference sequence manager definitions
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision (dummy implementation)
//

#ifndef REFSEQMANAGER_H_
#define REFSEQMANAGER_H_

// TODO: Complete
class RefSeqManager {
  public:
    RefSeqManager();
    char* GetRefSeq(uint32_t ref_id, uint32_t ref_offset, uint32_t ref_len);
};

#endif // REFSEQMANAGER_H_
