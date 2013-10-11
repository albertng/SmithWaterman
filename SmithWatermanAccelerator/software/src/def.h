//  File Name        : def.h
//  Description      : General definitions
//
//  Revision History :
//      Albert Ng   Oct 03 2013     Initial Revision 
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams from another header file
//                                  Changed AlignmentResult to contain HighScoreRegion
//      Albert Ng   Oct 09 2013     Changed name to def.h, added other defs
//      Albert Ng   Oct 10 2013     Added AlignmentJob

#ifndef DEF_H_
#define DEF_H_

#include "alignment.h"
#include <stdint.h>
#include <string>

// Nucleotide character definitions
#define T_NT 0
#define C_NT 1
#define A_NT 2
#define G_NT 3
#define N_NT -1
typedef int NtInt;

// Data structure holding an alignment job scheduled to an FPGA engine
struct AlignmentJob {
  int query_id;
  int query_len;
  int ref_id;
  int ref_offset;
  int threshold;
};

// Data structure holding a high scoring alignment region
struct HighScoreRegion {
  uint32_t     query_id;
  uint32_t     ref_id;
  uint32_t     ref_offset; // Offset of target seq within ref seq
  uint32_t     len;        // Number of bp in the high scoring region
  uint32_t     offset;     // Offset of HSR within target seq
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
  uint32_t sub_mat[4][4]; // Substitution matrix
  uint32_t gap_open;      // Gap open penalty
  uint32_t gap_extend;    // Gap extend penalty
};

#endif // DEF_H_
