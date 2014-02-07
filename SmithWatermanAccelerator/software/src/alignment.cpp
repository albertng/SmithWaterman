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
//      Albert Ng   Jan 24 2014     Added region end coords to ToString()
//      Albert Ng   Jan 28 2014     Added GetRefLength() and GetQueryLength()

#include <list>
#include <sstream>
#include <string>
#include <assert.h>
#include "alignment.h"
#include "scoring.h"
#include "utils.h"

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
  long long int ref_length = GetRefLength();
  long long int query_length = GetQueryLength();
    
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

/*void Alignment::TrimEnd(int index) {
  ref_str_ = ref_str_.substr(0, index);
  query_str_ = query_str_.substr(0, index);
}*/

void Alignment::TrimEnd(SwAffineGapParams params) {
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  params.GetSubMat(sub_mat);
  int gap_open = params.GetGapOpen();
  int gap_extend = params.GetGapExtend();
  
  // Find index with highest score
  int max_score = 0;
  int max_index = 0;
  int cur_score = 0;
  bool gap = false;
  for (int i = 0; i < ref_str_.length(); i++) {
    if (ref_str_[i] == GAP || query_str_[i] == GAP) {
      if (!gap) {
        cur_score += gap_open;
      } else {
        cur_score += gap_extend;
      }
      gap = true;
    } else {
      cur_score += sub_mat[NtChar2Int(ref_str_[i])][NtChar2Int(query_str_[i])];
      gap = false;
    }
    
    if (cur_score >= max_score) {
      max_score = cur_score;
      max_index = i;
    }
  }
  
  for (int i = 0; i < 4; i++) {
    delete[] sub_mat[i];
  }
  delete[] sub_mat;
          
  ref_str_ = ref_str_.substr(0, max_index + 1);
  query_str_ = query_str_.substr(0, max_index + 1);
};

int Alignment::GetLength() const {
  return ref_str_.length();
}

long long int Alignment::GetRefLength() const {
  long long int ref_length = 0;
  for (int i = 0; i < ref_str_.size(); i++) {
    if (ref_str_[i] != GAP) {
      ref_length++;
    }
  }
  return ref_length;
}

long long int Alignment::GetQueryLength() const {
  long long int query_length = 0;
  for (int i = 0; i < query_str_.size(); i++) {
    if (query_str_[i] != GAP) {
      query_length++;
    }
  }
  return query_length;
}

long long int Alignment::get_ref_offset() const {
  return ref_offset_;
}

long long int Alignment::get_query_offset() const {
  return query_offset_;
}

int Alignment::ComputeScore(SwAffineGapParams params) const {
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  params.GetSubMat(sub_mat);
  int gap_open = params.GetGapOpen();
  int gap_extend = params.GetGapExtend();
  
  int score = 0;
  bool gap = false;
  for (int i = 0; i < ref_str_.length(); i++) {
    if (ref_str_[i] == GAP || query_str_[i] == GAP) {
      if (!gap) {
        score += gap_open;
      } else {
        score += gap_extend;
      }
      gap = true;
    } else {
      score += sub_mat[NtChar2Int(ref_str_[i])][NtChar2Int(query_str_[i])];
      gap = false;
    }
  }
  
  for (int i = 0; i < 4; i++) {
    delete[] sub_mat[i];
  }
  delete[] sub_mat;
          
  return score;
};
