/*  File Name        : alignment.cpp
 *  Description      : Nucleotide alignment class definitions
 *
 *  Revision History :
 *      Albert Ng   Oct 02 2013     Initial Revision 
 *      Albert Ng   Oct 03 2013     Changed Print() to take ostream& arg
 *      Albert Ng   Oct 10 2013     Added target_offset_ and query_offset_
 */

#include "alignment.h"
#include <utility>      // For std::pair
#include <list>
#include <iostream>

Alignment::Alignment(int target_offset, int query_offset) {
  alignment_ = new std::list<std::pair<char, char> >;
  target_offset_ = target_offset;
  query_offset_ = query_offset;
}

Alignment::~Alignment() {
  delete alignment_;
}

void Alignment::Print(std::ostream& stream) {
  stream << target_offset_ << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    stream << (*it).first;
  }
  stream << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    stream << (*it).second;
  }
  stream << std::endl;
  stream << query_offset_ << std::endl;
}

void Alignment::Prepend(char target_nt, char query_nt) {
  if (target_nt != GAP) {
    target_offset_--;
  }

  if (query_nt != GAP) {
    query_offset_--;
  }

  alignment_->push_front(std::make_pair(target_nt, query_nt));
}
