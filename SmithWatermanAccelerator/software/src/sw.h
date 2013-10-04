//  File Name        : sw.h
//  Description      : Smith-Waterman software aligner definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//

#ifndef SW_H_
#define SW_H_

// Affine gap penalty scoring scheme data structure
struct SwAffineGapParams {
  uint32_t[4][4] sub_mat; // Substitution matrix
  uint32_t gap_open;      // Gap open penalty
  uint32_t gap_extend;    // Gap extend penalty
}

class 
