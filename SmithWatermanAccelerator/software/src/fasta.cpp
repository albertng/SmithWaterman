//  File Name        : fasta.cpp
//  Description      : FASTA file manipulator functions
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2013     Changed ParseFastaFile to return full descrip line
//      Albert Ng   Jan 21 2014     Added file positions

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
                    std::vector<long long int>* lengths,
                    std::vector<long long int>* fileposs) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: Could not open FASTA file " << filename << "." << std::endl;
    return;
  }
  
  int start_size = lengths->size();
  
  // First go through to get sequence descriptions, lengths, and file positions
  std::string line;
  long long int cur_length = 0;
  bool first_seq = true;
  long long int last_length;
  while (getline(file, line)) {
    if (line.length() == 0) {
      continue;
    }
    
    if (line[0] == '>') {
      std::vector<std::string> fields = SplitFields(line);
      descrips->push_back(fields);
      fileposs->push_back(file.tellg());
      
      if (first_seq == false) {
        lengths->push_back(cur_length);
        cur_length = 0;
      }
 
      first_seq = false;
      last_length = SEQLINE_WRAP_LEN;
    } else {
      // Check file starts with description line
      if (first_seq == true) {
        std::cerr << "Error in file " << filename << ": File begins with non-description line!" << std::endl;
        return;
      }
      
      // Check sequence lines are wrapped to MAX_SEQLINE_LEN characters
      if ((line.length() > SEQLINE_WRAP_LEN) || (line.length() < SEQLINE_WRAP_LEN && last_length != SEQLINE_WRAP_LEN)) {
        std::cerr << "Error in file " << filename << ": FASTA sequence lines need to be wrapped to " << SEQLINE_WRAP_LEN << " characters!" << std::endl;
        return;
      }
      
      cur_length += line.length();
      last_length = line.length();
    }
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
  long long int index;
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
      
