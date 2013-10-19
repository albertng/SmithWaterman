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

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <utility>    // For std::pair
#include <list>
#include <iostream>

#define GAP '-'

// Alignment information between two sequences
class Alignment {
  public :
    Alignment(long long int ref_offset, long long int query_offset);
    ~Alignment();
    
    void Print(std::ostream& stream);

    // Alignments are built backwards, so we prepend to the beginning of
    // the alignment, rather than extend from the end of the alignment.
    void Prepend(char ref_nt, char query_nt);
    
    // Compute length of the alignment
    int GetLength();
    
    // Accessor functions
    long long int get_ref_offset();
    long long int get_query_offset();

  private :
    std::list<std::pair<char, char> >* alignment_;
    long long int ref_offset_;
    long long int query_offset_;
};

#endif // ALIGNMENT_H_

