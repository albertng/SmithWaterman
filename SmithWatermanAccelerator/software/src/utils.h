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

#include "def.h"
#include <iostream>

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
    case 'n':
    case 'N': return N_NT;
    default: std::err << "Invalid nucleotide character " << nt 
                      << ". Replacing with 'N'." << std::endl;
             return N_NT;
  }
}



#endif // UTILS_H_

