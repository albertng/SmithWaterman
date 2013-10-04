/*  File Name        : alignment.cpp
 *  Description      : Nucleotide alignment class definitions
 *
 *  Revision History :
 *      Albert Ng   Oct 02 2013     Initial Revision 
 */

#include "alignment.h"
#include <iostream>

Alignment::Alignment() {
  alignment_ = new std::list<std::pair<char, char> >;
}

Alignment::~Alignment() {
  delete alignment_;
}

void Alignment::Print() {
  for (std::list<std::pair<char, char> >::iterator it = alignment_.begin(); it != alignment_.end(); ++it) {
    std::cout << *it.first;
  }
  std::cout << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_.begin(); it != alignment_.end(); ++it) {
    std::cout << *it.second;
  }
  std::cout << std::endl;
}

void Alignment::Prepend(char target_nt, char query_nt) {
  alignment_.push_front(std::make_pair(target_nt, query_nt));
}
