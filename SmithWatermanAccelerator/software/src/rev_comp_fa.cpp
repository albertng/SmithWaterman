#include <iostream>
#include <fstream>
#include <string>
#include <map>

std::map<char, char> rcmap;

std::string RevComp(std::string seq) {
  std::string rc;

  for (int i = seq.size()-1; i >= 0; i--) {
    rc += rcmap[seq[i]];
  }

  return rc;
}

void WriteSeq(std::string seq, std::ofstream* file) {
  while (seq.size() > 0) {
    int len = seq.size() > 50 ? 50 : seq.size();
    (*file) << seq.substr(0, len) << std::endl;
    seq = seq.substr(len);
  }
}

int main (int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Usage: ./rev_comp_fa <INPUT FILE> <OUTPUT FILE>" << std::endl;
    return(1);
  }

  rcmap['a'] = 'T';
  rcmap['A'] = 'T';
  rcmap['t'] = 'A';
  rcmap['T'] = 'A';
  rcmap['c'] = 'G';
  rcmap['C'] = 'G';
  rcmap['g'] = 'C';
  rcmap['G'] = 'C';

  std::ifstream in_file(argv[1]);
  std::ofstream out_file(argv[2]);

  std::string line;
  std::string seq = "";
  bool start = true;
  while (getline(in_file, line)) {
    if (line.size() == 0) {
      continue;
    }
    if (line.find('>') != std::string::npos) {
      out_file << line << std::endl;
      if (start == false) {
        WriteSeq(RevComp(seq), &out_file);
        seq = "";
      }
    } else {
      seq += line;
    }
  }
  WriteSeq(RevComp(seq), &out_file);
  out_file.close();
}
