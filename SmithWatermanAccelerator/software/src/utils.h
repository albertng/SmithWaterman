//  File Name        : utils.h
//  Description      : General utility definitions
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision
//      Albert Ng   Oct 05 2013     Made NtChar2Int inline
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams to another header file
//      Albert Ng   Oct 09 2013     Added def.h reference
//      Albert Ng   Oct 18 2013     Added invalid char chaeck to NtChar2Int

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <assert.h>
#include "def.h"

// Converts a nucleotide char to nucleotide integer, accepting
// both lowercase and uppercase.
inline NtInt NtChar2Int (char nt) {
  switch(nt) {
    case 't':
    case 'T': return T_NT;
    case 'c':
    case 'C': return C_NT;
    case 'a':
    case 'A': return A_NT;
    case 'g':
    case 'G': return G_NT;
    case 'n':
    case 'N': return N_NT;
    default: assert(false);
  }
}

// Converts a nucleotide integer to nucleotide char,
inline char NtInt2Char (NtInt nt) {
  switch(nt) {
    case T_NT: return 'T';
    case C_NT: return 'C';
    case A_NT: return 'A';
    case G_NT: return 'G';
    case N_NT: return 'N';
    default  : assert(false);
  }
}

#endif // UTILS_H_

