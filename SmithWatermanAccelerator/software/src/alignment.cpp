//  File Name        : alignment.cpp
//  Description      : Nucleotide alignment class definitions
//
//  Revision History :
//      Albert Ng   Oct 02 2013     Initial Revision 
//      Albert Ng   Oct 03 2013     Changed Print() to take ostream& arg
//      Albert Ng   Oct 10 2013     Added target_offset_ and query_offset_
//      Albert Ng   Oct 15 2013     Changed target to ref
//                                  Added get_ref_offset(), get_query_offset()
//      Albert Ng   Oct 18 2013     Added GetLength()
//      Albert Ng   Oct 28 2013     Changed Print() to ToString()
//      Albert Ng   Oct 29 2013     Changed from list<pair> to string based

#include "alignment.h"
#include <utility>      // For std::pair
#include <list>
#include <sstream>
#include <string>

Alignment::Alignment() {
  ref_str_ = "";
  query_str_ = "";
}

Alignment::Alignment(long long int ref_offset, long long int query_offset) {
  //alignment_ = new std::list<std::pair<char, char> >;
  ref_str_ = "";
  query_str_ = "";
  ref_offset_ = ref_offset;
  query_offset_ = query_offset;
}

Alignment::~Alignment() {
  //delete alignment_;
}

std::string Alignment::ToString() {
  std::stringstream ss;

  ss << ref_offset_ << "\n"
     << ref_str_ << "\n"
     << query_str_ << "\n"
     << query_offset_ << std::endl;

  /*ss << ref_offset_ << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    ss << (*it).first;
  }
  ss << std::endl;
  for (std::list<std::pair<char, char> >::iterator it = alignment_->begin(); it != alignment_->end(); ++it) {
    ss << (*it).second;
  }
  ss << std::endl;
  ss << query_offset_ << std::endl;*/
  
  return ss.str();
}

void Alignment::Prepend(char ref_nt, char query_nt) {
  if (ref_nt != GAP) {
    ref_offset_--;
  }

  if (query_nt != GAP) {
    query_offset_--;
  }

  //alignment_->push_front(std::make_pair(ref_nt, query_nt));
  //std::cout<<"Prepending "<<ref_str_ << " : "<<query_str_<<std::endl;
  ref_str_.insert(0, 1, ref_nt);
  query_str_.insert(0, 1, query_nt);
}

int Alignment::GetLength() {
  //return alignment_->size();
  return ref_str_.length();
}

long long int Alignment::get_ref_offset() {
  return ref_offset_;
}

long long int Alignment::get_query_offset() {
  return query_offset_;
}
