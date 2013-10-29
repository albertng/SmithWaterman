//  File Name        : fasta.cpp
//  Description      : FASTA file manipulator functions
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2013     Changed ParseFastaFile to return full descrip line

#include "fasta.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

void ParseFastaFile(std::string filename,
                    std::vector<std::string>* descrips,
                    std::vector<char*>* seqs,
                    std::vector<int>* lengths) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open FASTA file " << filename << "." << std::endl;
    return;
  }
  
  int start_size = lengths->size();
  
  // First go through to get sequence names and lengths
  std::string line;
  int cur_length = 0;
  bool first_seq = true;
  while (getline(file, line)) {
    if (line.length() == 0) {
      continue;
    }
    if (line[0] == '>') {
      if (first_seq == false) {
        lengths->push_back(cur_length);
        cur_length = 0;
      }
      descrips->push_back(line);
    } else {
      cur_length += line.length();
    }
    first_seq = false;
  }
  lengths->push_back(cur_length);
  
  // Allocate char array memory
  for (int i = 0; i < lengths->size() - start_size; i++) {
    char* seq = new char[lengths->at(i + start_size)];
    seqs->push_back(seq);
  }
  
  // Go through file again and fill char arrays with sequences
  file.close();
  file.open(filename.c_str());
  char* seq;
  int index;
  int cur_ref = start_size - 1;
  first_seq = true;
  while (getline(file, line)) {
    if (line[0] == '>') {
      cur_ref++;
      seq = seqs->at(cur_ref);
      index = 0;
    } else {
      line.copy(&(seq[index]), line.length());
      index += line.length();
    }
  }
}

static void GetSeqName(std::string line, std::string* name, std::string* descrip) {
  bool in_name = true;
  for (int i = 1; i < line.length(); i++) {
    if (in_name && (isalpha(line[i]) || isdigit(line[i]))) {
      name->push_back(line[i]);
    } else {
      in_name = false;
      descrip->push_back(line[i]);
    }
  }
}
      
