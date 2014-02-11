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
//      Albert Ng   Oct 22 2013     Changed SwAffineGapParams to a class in scoring.h
//                                  Added SwAffineGapParams to bookkeeping structs
//                                  Removed query_len from AlignmentJob
//      Albert Ng   Oct 28 2013     Changed AlignmentResult to store Alignment, not Alignment*
//      Albert Ng   Oct 30 2013     Added END_OF_ENGINE_ALIGNMENT
//      Albert Ng   Oct 31 2013     Added AlignmentResultComp
//      Albert Ng   Jan 14 2014     Added fpga_id and engine_id to EngineJob
//      Albert Ng   Jan 22 2014     Added ALL_REF
//      Albert Ng   Feb 10 2014     Added AlignmentResultScoreComp

#ifndef DEF_H_
#define DEF_H_

#include <stdint.h>
#include <string>
#include <functional>
#include "alignment.h"
#include "scoring.h"

#undef SIM_PICO

// Server configuration definitions
#define NUM_SW_THREADS 12

// Hardware Parameter definitions
#define NUM_FPGAS 6
#define NUM_ENGINES_PER_FPGA 5
#define REF_BLOCK_LEN 128
#define QUERY_BLOCK_LEN 64
#define MAX_QUERY_LEN 65535
#define NT_PER_BYTE 4

// Client-Server communication definitions
#define END_OF_QUERY_GROUP "END"
#define QUERY_GROUP_SUCCESS "SUCCESS"
#define QUERY_GROUP_FAIL "FAIL"
#define ALL_CHROM "ALLCHR"
#define ALL_REF "ALLREF"

// FPGA protocol definitions
#define END_OF_ENGINE_ALIGNMENT 0xFFFFFFFF  // High score block value indicating the end 
                                            //   of an alignment for an engine

// Alignment Job Queue definitions
#define PARAMS_JOB -1

// Nucleotide character definitions
#define T_NT 0
#define C_NT 1
#define A_NT 2
#define G_NT 3
#define N_NT -1
typedef int NtInt;

// Data structure holding an alignment job requested by a client, or
//   a change in scoring parameters.
struct AlignmentJob {
  int query_id;
  int ref_id;
  int chr_id;
  long long int ref_offset;
  long long int ref_len;
  int threshold;
  SwAffineGapParams params; // Unused when query_id != PARAMS_JOB
};

// Data structure holding an alignment job scheduled to an engine.
//   Same as AlignmentJob except with an overlap_offset, indicating
//   the offset at which this job overlaps with the next job. Reported
//   high scoring regions must not begin past this offset, so there
//   are no duplicated regions.
struct EngineJob {
  int fpga_id;
  int engine_id;
  int query_id;
  int ref_id;
  int chr_id;
  long long int ref_offset;
  long long int ref_len;
  long long int overlap_offset;
  long long int fpga_addr;
  long long int fpga_len;
  int threshold;
  SwAffineGapParams params;
};

// Data structure holding a potential high scoring alignment region
//   discovered by the FPGA engines.
struct HighScoreRegion {
  int query_id;
  int ref_id;
  int chr_id;
  long long int len;
  long long int offset;
  long long int overlap_offset;
  long long int job_offset;
  int threshold;
  SwAffineGapParams params;
};

// Data structure holding the traceback result of a high scoring alignment
struct AlignmentResult {
  HighScoreRegion hsr;
  Alignment alignment;
  int score;
  bool boundary;
  
  bool operator== (const AlignmentResult& a) const {
    return (hsr.ref_id == a.hsr.ref_id && hsr.chr_id == a.hsr.chr_id && 
            alignment.get_ref_offset() + alignment.GetRefLength() == a.alignment.get_ref_offset() + a.alignment.GetRefLength());
  }
};

// Alignment Result comparison
struct AlignmentResultComp {
  bool operator() (const AlignmentResult& lhs, const AlignmentResult& rhs) const {
    return lhs.alignment.get_ref_offset() < rhs.alignment.get_ref_offset();
  }
};

// Alignment Result comparison by score
struct AlignmentResultScoreComp {
  bool operator() (const AlignmentResult& lhs, const AlignmentResult& rhs) const {
    return lhs.score > rhs.score;
  }
};

// Hash combiner function
template <class T>
inline void hash_combine(std::size_t& seed, const T& v) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

// Hasher for AlignmentResult
//   Hashes by end-index for checking for same end-index duplicates
struct AlignmentResultHash {
  std::size_t operator()(const AlignmentResult& a) const {
    std::size_t seed = 0;
    std::hash<long long int> longlongint_hasher;
    std::hash<int> int_hasher;
    hash_combine(seed, longlongint_hasher(a.alignment.get_ref_offset() + a.alignment.GetRefLength()));
    hash_combine(seed, int_hasher(a.hsr.ref_id));
    hash_combine(seed, int_hasher(a.hsr.chr_id));
    return seed;
  }
};
  

#endif // DEF_H_
