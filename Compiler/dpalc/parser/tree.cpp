//  File Name        : tree.cpp
//  Description      : Abstract syntax tree
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision

#include <iostream>
#include "tree.hpp"
#include "utils.hpp"

void NProgram::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Program" << std::endl;
  alphabet_decl->dump(stream, depth+1);
}

void NAlphabetDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Alphabet Declaration" << std::endl;
  for (CharacterDeclList::iterator it = characters->begin(); it != characters->end(); it++) {
    (*it)->dump(stream, depth+1);
  }
}

void NCharacterDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Character Declaration" << std::endl;
  id->dump(stream, depth+1);
  if (value != NULL) {
    value->dump(stream, depth+1);
  }
}

void NIdentifier::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Identifier " << *name << std::endl;
}

void NIntConst::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Int Const " << value << std::endl;
}
