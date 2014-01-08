//  File Name        : fasta.cpp
//  Description      : FASTA file manipulator functions
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2013     Changed ParseFastaFile to return full descrip line

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "fasta.h"

static std::vector<std::string> SplitFields(std::string descrip_line) {
  std::vector<std::string> fields;
  std::string cur_str = "";
  for (int i = 1; i < descrip_line.length(); i++) {
    if (!isalpha(descrip_line[i]) && !isdigit(descrip_line[i]) && (descrip_line[i] != '_')) {
      fields.push_back(cur_str);
      cur_str = "";
    } else {
      cur_str.push_back(descrip_line[i]);
    }
  }
  fields.push_back(cur_str);
  
  return fields;
}

void ParseFastaFile(std::string filename,
                    std::vector<std::vector<std::string> >* descrips,
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
      std::vector<std::string> fields = SplitFields(line);
      descrips->push_back(fields);
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
      
