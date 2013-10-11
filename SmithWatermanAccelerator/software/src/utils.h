//  File Name        : utils.h
//  Description      : General utility definitions
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision
//      Albert Ng   Oct 05 2013     Made NtChar2Int inline
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams to another header file
//      Albert Ng   Oct 09 2013     Added def.h reference

#ifndef UTILS_H_
#define UTILS_H_

#include "def.h"

// Converts a nucleotide char to nucleotide integer, accepting
// both lowercase and uppercase. Returns -1 if not TCAG.
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
    default: return N_NT;
  }
}



#endif // UTILS_H_

