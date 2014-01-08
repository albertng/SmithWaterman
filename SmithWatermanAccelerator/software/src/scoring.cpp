//  File Name        : scoring.cpp
//  Description      : Scoring Parameters classes
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Changed sub_mat_ to int** from [][]

#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <assert.h>
#include "def.h"
#include "scoring.h"

SwAffineGapParams::SwAffineGapParams() {
}

SwAffineGapParams::SwAffineGapParams(int sub_mat[][4], int gap_open, int gap_extend) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sub_mat_[i][j] = sub_mat[i][j];
    }
  }
  gap_open_ = gap_open;
  gap_extend_ = gap_extend;
  
  assert(IsValid());
}

// Throws std::ios_base::failure exception
SwAffineGapParams::SwAffineGapParams(std::string s) {
  std::istringstream iss(s);
  iss.exceptions(std::ios::failbit);
  iss >> sub_mat_[A_NT][A_NT];
  iss >> sub_mat_[A_NT][C_NT];
  iss >> sub_mat_[A_NT][G_NT];
  iss >> sub_mat_[A_NT][T_NT];
  iss >> sub_mat_[C_NT][C_NT];
  iss >> sub_mat_[C_NT][G_NT];
  iss >> sub_mat_[C_NT][T_NT];
  iss >> sub_mat_[G_NT][G_NT];
  iss >> sub_mat_[G_NT][T_NT];
  iss >> sub_mat_[T_NT][T_NT];
  iss >> gap_open_;
  iss >> gap_extend_;
  
  // Fill other half of matrix
  sub_mat_[C_NT][A_NT] = sub_mat_[A_NT][C_NT];
  sub_mat_[G_NT][A_NT] = sub_mat_[A_NT][G_NT];
  sub_mat_[G_NT][C_NT] = sub_mat_[C_NT][G_NT];
  sub_mat_[T_NT][A_NT] = sub_mat_[A_NT][T_NT];
  sub_mat_[T_NT][C_NT] = sub_mat_[C_NT][T_NT];
  sub_mat_[T_NT][G_NT] = sub_mat_[G_NT][T_NT];
}

SwAffineGapParams::~SwAffineGapParams() {
}

void SwAffineGapParams::GetSubMat(int** sub_mat) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sub_mat[i][j] = sub_mat_[i][j];
    }
  }
}

int SwAffineGapParams::GetGapOpen() {
  return gap_open_;
}

int SwAffineGapParams::GetGapExtend() {
  return gap_extend_;
}

bool SwAffineGapParams::IsValid() {
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      if (sub_mat_[i][j] != sub_mat_[j][i]) {
        return false;
      }
    }
  }
  
  return true;
}

std::string SwAffineGapParams::ToString() {
  std::stringstream ss;
  
  ss << sub_mat_[A_NT][A_NT] << " " << sub_mat_[A_NT][C_NT] << " " << sub_mat_[A_NT][G_NT] << " " 
     << sub_mat_[A_NT][T_NT] << " " << sub_mat_[C_NT][C_NT] << " " << sub_mat_[C_NT][G_NT] << " " 
     << sub_mat_[C_NT][T_NT] << " " << sub_mat_[G_NT][G_NT] << " " << sub_mat_[G_NT][T_NT] << " " 
     << sub_mat_[T_NT][T_NT] << " " << gap_open_ << " " << gap_extend_;
  return ss.str();
}

int* SwAffineGapParams::ToBuf(int* buf_len) {
  int* buf = new int[SW_PARAMS_BUF_LENGTH];
  buf[0] = sub_mat_[A_NT][A_NT];
  buf[1] = sub_mat_[A_NT][C_NT];
  buf[2] = sub_mat_[A_NT][G_NT];
  buf[3] = sub_mat_[A_NT][T_NT];
  buf[4] = sub_mat_[C_NT][C_NT];
  buf[5] = sub_mat_[C_NT][G_NT];
  buf[6] = sub_mat_[C_NT][T_NT];
  buf[7] = sub_mat_[G_NT][G_NT];
  buf[8] = sub_mat_[G_NT][T_NT];
  buf[9] = sub_mat_[T_NT][T_NT];
  buf[10] = gap_open_;
  buf[11] = gap_extend_;
  
  *buf_len = SW_PARAMS_BUF_LENGTH * sizeof(int); // 4 bytes per int
  
  return buf;
}

  
  
  

