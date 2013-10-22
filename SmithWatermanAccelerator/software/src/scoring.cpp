//  File Name        : scoring.cpp
//  Description      : Scoring Parameters classes
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#include "scoring.h"
#include <iostream>
#include <sstream>
#include "def.h"
#include <string>

SwAffineGapParams::SwAffineGapParams(int** sub_mat, int gap_open, int gap_extend) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      sub_mat_[i][j] = sub_mat[i][j];
    }
  }
  gap_open_ = gap_open;
  gap_extend_ = gap_extend;
  
  if (!IsValid()) {
    std::cerr << "Warning: Nonsymmetric SW Affine Gap Params substitution matrix!" << std::endl;
  }
}

// Note: No error checking, assumes string is in the right format
SwAffineGapParams::SwAffineGapParams(std::string s) {
  std::istringstream iss(s);
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
}

SwAffineGapParams::~SwAffineGapParams() {
}

void SwAffineGapParams::GetSubMat(int** sub_mat) {
  sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
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
  stringstream ss;
  
  ss << sub_mat_[A_NT][A_NT] << " " << sub_mat_[A_NT][C_NT] << " " << sub_mat_[A_NT][G_NT] << " " 
     << sub_mat_[A_NT][T_NT] << " " << sub_mat_[C_NT][C_NT] << " " << sub_mat_[C_NT][G_NT] << " " 
     << sub_mat_[C_NT][T_NT] << " " << sub_mat_[G_NT][G_NT] << " " << sub_mat_[G_NT][T_NT] << " " 
     << sub_mat_[T_NT][T_NT] << " " << gap_open_ << " " << gap_extend_;
  return ss.str();
}

int SwAffineGapParams::ToBuf(int* buf) {
  buf = new int[SW_PARAMS_BUF_LENGTH];
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
  
  return SW_PARAMS_BUF_LENGTH * sizeof(int);  // 4 bytes per int
}

  
  
  

