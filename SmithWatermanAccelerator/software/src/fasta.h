//  File Name        : fasta.h
//  Description      : FASTA file manipulator function declarations
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#ifndef FASTA_H_
#define FASTA_H_

#include <string>
#include <vector>

void ParseFastaFile(std::string filename, 
                    std::vector<std::string>* names,
                    std::vector<char*>* seqs,
                    std::vector<int>* lengths);

#endif // FASTA_H_
