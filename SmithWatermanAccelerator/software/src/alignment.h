//  File Name        : alignment.h
//  Description      : Nucleotide alignment class definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//      Albert Ng   oct 03 2013     Changed Print() to take ostream& arg
//      Albert Ng   Oct 10 2013     Added target_offset_ and query_offset_

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <utility>    // For std::pair
#include <list>
#include <iostream>

#define GAP '-'

// Alignment information between two sequences
class Alignment {
  public :
    Alignment(int target_offset, int query_offset);
    ~Alignment();
    
    void Print(std::ostream& stream);

    // Alignments are built backwards, so we prepend to the beginning of
    // the alignment, rather than extend from the end of the alignment.
    void Prepend(char target_nt, char query_nt);
    
  private :
    std::list<std::pair<char, char> >* alignment_;
    int target_offset_;
    int query_offset_;
};

#endif // ALIGNMENT_H_

