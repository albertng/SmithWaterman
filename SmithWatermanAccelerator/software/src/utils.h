//  File Name        : utils.h
//  Description      : General utility definitions
//
//  Revision History :
//      Albert Ng   Oct 04 2013     Initial Revision
//      Albert Ng   Oct 05 2013     Made NtChar2Int inline
//      Albert Ng   Oct 07 2013     Moved SwAffineGapParams to another header file
//      Albert Ng   Oct 09 2013     Added def.h reference
//      Albert Ng   Oct 18 2013     Added invalid char check to NtChar2Int
//      Albert Ng   Feb 19 2014     Added NtComp() and RevComp()

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <assert.h>
#include "def.h"
#include <string>

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
    default:  std::cout<<"Bad Nt char: "<<nt<<" "<<(int)nt<<std::endl;
              assert(false);
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
    default  : std::cout<<"Bad NtInt: "<<nt<<std::endl;
               assert(false);
  }
}

// Gets the complement of to nucleotide.
inline char NtComp (char nt) {
  switch(nt) {
    case 'a': return 't';
    case 'A': return 'T';
    case 't': return 'a';
    case 'T': return 'A';
    case 'c': return 'g';
    case 'C': return 'G';
    case 'g': return 'c';
    case 'G': return 'C';
    case '-': return '-';
    default  : std::cout<<"Bad Nt: "<<nt<<std::endl;
               //assert(false);
  }
}

// Gets the reverse complement of the sequence.
inline std::string RevComp(std::string seq) {
  std::string rc_seq = "";

  for (int i = seq.size()-1; i >= 0; i--) {
    char comp = NtComp(seq[i]);
    if (NtComp == 'N') {
      std::cout << "Bad Nt seq: " << seq << std::endl;
      assert(false);
    }
    rc_seq += NtComp(seq[i]);
  }
  return rc_seq;
}

#endif // UTILS_H_

