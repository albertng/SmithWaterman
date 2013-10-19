//  File Name        : def.h
//  Description      : General definitions
//
//  Revision History :
//      Albert Ng   Oct 03 2013     Initial Revision 
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams from another header file
//                                  Changed AlignmentResult to contain HighScoreRegion
//      Albert Ng   Oct 09 2013     Changed name to def.h, added other defs
//      Albert Ng   Oct 10 2013     Added AlignmentJob
//      Albert Ng   Oct 14 2013     Changed lengths and offsets to long long int
//      Albert Ng   Oct 15 2013     Added NUM_FPGAS and NUM_ENGINES_PER_FPGA

#ifndef DEF_H_
#define DEF_H_

#include "alignment.h"
#include <stdint.h>
#include <string>

// Hardware Parameter definitions
#define NUM_FPGAS 1
#define NUM_ENGINES_PER_FPGA 1
#define REF_BLOCK_LEN 128
#define MAX_QUERY_LEN 65535

// Nucleotide character definitions
#define T_NT 0
#define C_NT 1
#define A_NT 2
#define G_NT 3
#define N_NT -1
typedef int NtInt;

// Data structure holding an alignment job requested by a client
//   Can be used to hold a job requested from the client, or a sub-job
//   scheduled to an engine.
struct AlignmentJob {
  int query_id;
  int query_len;
  int ref_id;
  long long int ref_offset;
  long long int ref_len;
  int threshold;
};

// Data structure holding an alignment job scheduled to an engine.
//   Same as AlignmentJob except with an overlap_offset, indicating
//   the offset at which this job overlaps with the next job. Reported
//   high scoring regions must not begin past this offset, so there
//   are no duplicated regions.
struct EngineJob {
  int query_id;
  int query_len;
  int ref_id;
  long long int ref_offset;
  long long int ref_len;
  long long int overlap_offset;
  int threshold;
};

// Data structure holding a potential high scoring alignment region
//   discovered by the FPGA engines.
struct HighScoreRegion {
  int query_id;
  int ref_id;
  long long int len;
  long long int offset;
  long long int overlap_offset;
  int threshold;
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
