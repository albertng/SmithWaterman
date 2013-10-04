//  File Name        : alignment.h
//  Description      : Nucleotide alignment class definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//

#ifndef ALIGNMENT_H_
#define ALIGNMENT_H_

#include <utility>
#include <list>

// Alignment information between two sequences
class Alignment {
  public :
    Alignment();
    ~Alignment();
    
    void Print();
    void Prepend(char target_nt, char query_nt);
    
  private :
    std::list<std::pair<char, char> > alignment_;
};

#endif // ALIGNMENT_H_

