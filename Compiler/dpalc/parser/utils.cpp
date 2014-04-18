//  File Name        : utils.cpp
//  Description      : Useful utility functions
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision

#include "utils.hpp"
#include <string>

static const int PADSPACES = 2;

std::string pad(int depth) {
  if (depth <= 0) {
    return "";
  }

  return std::string(depth * PADSPACES, ' ');
}

