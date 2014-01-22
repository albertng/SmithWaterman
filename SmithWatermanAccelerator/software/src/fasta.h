//  File Name        : fasta.h
//  Description      : FASTA file manipulator function declarations
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Jan 21 2014     Added file positions

#ifndef FASTA_H_
#define FASTA_H_

#include <string>
#include <vector>

#define SEQLINE_WRAP_LEN 50

void ParseFastaFile(std::string filename, 
                    std::vector<std::vector<std::string> >* descrips,
                    std::vector<char*>* seqs,
                    std::vector<int>* lengths,
                    std::vector<long long int>* fileposs);

#endif // FASTA_H_
