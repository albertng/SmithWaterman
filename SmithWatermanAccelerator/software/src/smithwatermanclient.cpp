//  File Name        : smithwatermanclient.cpp
//  Description      : Client Process main thread
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#include "clientsocket.h"
#include "def.h"
#include "fasta.h"
#include "scoring.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: ./smithwatermanclient <QUERY SEQ FASTA FILE1> [<QUERY SEQ FASTA FILE2> ...]\n");
    exit(1);
  }
  
  std::vector<std::string> names;
  std::vector<char*> seqs;
  std::vector<int> lengths;
  
  // Parse the files
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ParseFastaFile(filename, &names, &seqs, &lengths);
  }
  
  SwAffineGapParams params("2 -2 -2 -2 2 -2 -2 2 -2 2 -2 -1");
