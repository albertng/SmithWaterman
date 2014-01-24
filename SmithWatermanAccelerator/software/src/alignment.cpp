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
//      Albert Ng   Oct 31 2013     Added TrimEnd()
//      Albert Ng   Jan 24 2013     Added region end coords to ToString()

#include <list>
#include <sstream>
#include <string>
#include <assert.h>
#include "alignment.h"

Alignment::Alignment() {
  ref_str_ = "";
  query_str_ = "";
  ref_offset_ = 0;
  query_offset_ = 0;
}

Alignment::Alignment(long long int ref_offset, long long int query_offset) {
  ref_str_ = "";
  query_str_ = "";
  ref_offset_ = ref_offset;
  query_offset_ = query_offset;
}

Alignment::~Alignment() {
}

std::string Alignment::ToString() const {
  // Find region lengths
  int ref_length = 0;
  int query_length = 0;
  assert(ref_str_.size() == query_str_.size());
  for (int i = 0; i < ref_str_.size(); i++) {
    if (ref_str_[i] != GAP) {
      ref_length++;
    }
    if (query_str_[i] != GAP) {
      query_length++;
    }
  }
    
  std::stringstream ss;

  ss << ref_offset_ << ":" << ref_offset_ + ref_length << "\n"
     << ref_str_ << "\n"
     << query_str_ << "\n"
     << query_offset_ << ":" << query_offset_ + query_length << std::endl;

  return ss.str();
}

void Alignment::Prepend(char ref_nt, char query_nt) {
  if (ref_nt != GAP) {
    ref_offset_--;
  }

  if (query_nt != GAP) {
    query_offset_--;
  }

  ref_str_.insert(0, 1, ref_nt);
  query_str_.insert(0, 1, query_nt);
}

void Alignment::TrimEnd(int index) {
  ref_str_ = ref_str_.substr(0, index);
  query_str_ = query_str_.substr(0, index);
}

int Alignment::GetLength() const {
  return ref_str_.length();
}

long long int Alignment::get_ref_offset() const {
  return ref_offset_;
}

long long int Alignment::get_query_offset() const {
  return query_offset_;
}
