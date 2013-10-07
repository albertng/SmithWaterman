//  File Name        : sharedstructs.h
//  Description      : Shared data structures 
//
//  Revision History :
//      Albert Ng   Oct 03 2013     Initial Revision 
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams from another header file
//                                  Changed AlignmentResult to contain HighScoreRegion
//

#ifndef SHAREDSTRUCTS_H_
#define SHAREDSTRUCTS_H_

#include "alignment.h"
#include <string>

// Data structure holding a high scoring alignment region
struct HighScoreRegion {
  uint32_t     query_id;
  std::string* query_seq;
  uint32_t     query_len;
  uint32_t     ref_id; 
  uint32_t     ref_offset; 
  uint32_t     ref_len;
  int          threshold;
};

// Data structure holding the traceback result of a high scoring alignment
struct AlignmentResult {
  HighScoreRegion hsr;
  Alignment* alignment;
  int score;
};

// Data structure holding affine gap penalty scoring scheme parameters
struct SwAffineGapParams {
  uint32_t[4][4] sub_mat; // Substitution matrix
  uint32_t gap_open;      // Gap open penalty
  uint32_t gap_extend;    // Gap extend penalty
};

#endif // SHAREDSTRUCTS_H_
