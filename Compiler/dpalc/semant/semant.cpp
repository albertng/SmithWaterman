//  File Name        : semant.cpp
//  Description      : Semantic checker main function
//
//  Revision History :
//      Albert Ng   May 05 2014     Initial Revision

#include <iostream>
#include <string>
#include <cstdlib>
#include "tree.hpp"
#include "dpal-parse.hpp"

NProgram *root;
std::string filename;
extern FILE * yyin;
extern int yyparse(void);

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./semant <DPAL FILE>" << std::endl;
    return 1;
  }

  filename = std::string(argv[1]);
  yyin = fopen(argv[1], "r");

  root = NULL;
  yyparse();
  if (root) {  
    root->Semant();
    root->dump(std::cout, 0);
  }
}
  
