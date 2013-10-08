/*  File Name        : alignment.cpp
 *  Description      : Nucleotide alignment class definitions
 *
 *  Revision History :
 *      Albert Ng   Oct 02 2013     Initial Revision 
 *      Albert Ng   Oct 03 2013     Changed Print() to take ostream& arg
 */

#include "alignment.h"
#include <utility>
#include <list>
#include <iostream>

Alignment::Alignment() {
  alignment_ = new std::list<std::pair<char, char> >;
}

Alignment::~Alignment() {
  delete alignment_;
}

void Alignment::Print(std::ostream& stream) {
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    stream << (*it).first;
  }
  stream << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    stream << (*it).second;
  }
  stream << std::endl;
}

void Alignment::Prepend(char target_nt, char query_nt) {
  alignment_->push_front(std::make_pair(target_nt, query_nt));
}
