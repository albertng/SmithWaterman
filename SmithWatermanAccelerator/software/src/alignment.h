//  File Name        : alignment.h
//  Description      : Nucleotide alignment class definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//      Albert Ng   Oct 03 2013     Changed Print() to take ostream& arg
//      Albert Ng   Oct 10 2013     Added target_offset_ and query_offset_
//      Albert Ng   Oct 15 2013     Changed target to ref
//                                  Added get_ref_offset(), get_query_offset()
//      Albert Ng   Oct 18 2013     Added GetLength();
//      Albert Ng   Oct 28 2013     Changed Print() to ToString()
//      Albert Ng   Oct 29 2013     Changed from list<pair> to string based
//      Albert Ng   Oct 31 2013     Added TrimEnd()
//      Albert Ng   Jan 28 2014     Added GetRefLength() and GetQueryLength()

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <list>
#include <iostream>
#include <string>

#define GAP '-'

// Alignment information between two sequences
class Alignment {
  public :
    Alignment();
    Alignment(long long int ref_offset, long long int query_offset);
    ~Alignment();
    
    std::string ToString() const;

    // Alignments are built backwards, so we prepend to the beginning of
    //   the alignment, rather than extend from the end of the alignment.
    void Prepend(char ref_nt, char query_nt);
    
    // Trim off the end of the alignment STARTING from index (i.e. keep the
    //   first index characters of the alignment)
    //   e.g. "ACG-T" TrimEnd(2) becomes "AC"
    void TrimEnd(int index);
    
    // Compute length of the alignment
    int GetLength() const;
    long long int GetRefLength() const;
    long long int GetQueryLength() const;
    
    // Accessor functions
    long long int get_ref_offset() const;
    long long int get_query_offset() const;

  private :
    std::string ref_str_;
    std::string query_str_;
    long long int ref_offset_;
    long long int query_offset_;
};

#endif // ALIGNMENT_H_

