//  File Name        : tree.cpp
//  Description      : Abstract syntax tree
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant declaration nodes
//      Albert Ng   Apr 23 2014     Constant matrix declaration nodes
//                                  DP Matrix declaration nodes
//                                  Cell function declaration nodes

#include <iostream>
#include "tree.hpp"
#include "utils.hpp"

void NProgram::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Program" << std::endl;
  alphabet_decl->dump(stream, depth+1);
  for (ConstDeclList::iterator it = const_decl_list->begin(); it != const_decl_list->end(); it++) {
    (*it)->dump(stream, depth+1);
  }
  for (DPMatrixDeclList::iterator it = dp_matrix_decl_list->begin(); it != dp_matrix_decl_list->end(); it++) {
    (*it)->dump(stream, depth+1);
  }
  cell_func_decl->dump(stream, depth+1);
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

void NBoolConst::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bool Const ";
  if (value) {
    stream << "true";
  } else {
    stream << "false";
  }
  stream << std::endl;
}

void NIdConst::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Identifier Const " << std::endl;
  id->dump(stream, depth+1);
}

void NType::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Type" << std::endl;

  stream << pad(depth+1) << "Typename ";
  switch(type) {
    case UNSIGNED : stream << "unsigned ";
                    break;
    case SIGNED   : stream << "signed ";
                    break;
    case BOOL     : stream << "bool ";
                    break;
    default       : break;
  }
  stream << std::endl;

  bitwidth->dump(stream, depth+1);
}

void NConstScalarDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Const Scalar Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
  value->dump(stream, depth+1);
}

void NConstMatrixDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Const Matrix Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);

  stream << pad(depth+1) << "Dimensions" << std::endl;
  for (ConstList::iterator it = dimensions->begin(); it != dimensions->end(); it++) {
    (*it)->dump(stream, depth+2);
  }

  stream << pad(depth+1) << "Const Matrix Data" << std::endl;
  matrix_element->dump(stream, depth+2);
}

void NConstMatrixElem::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Const Matrix Element" << std::endl;
  if (matrix_elements == NULL) {
    for (ConstList::iterator it = values->begin(); it != values->end(); it++) {
      (*it)->dump(stream, depth+1);
    }
  } else {
    for (ConstMatrixElemList::iterator it = matrix_elements->begin(); it != matrix_elements->end(); it++) {
      (*it)->dump(stream, depth+1);
    }
  }
}

void NDPMatrixDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "DP Matrix Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
}

void NCellFuncDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Cell Function Declaration" << std::endl;

  stream << pad(depth+1) << "Parameters" << std::endl;
  for (ParamList::iterator it = param_list->begin(); it != param_list->end(); it++) {
    (*it)->dump(stream, depth+2);
  }

  stream << pad(depth+1) << "Statements" << std::endl;
  for (StmtList::iterator it = stmt_list->begin(); it != stmt_list->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NParamScalar::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Scalar Parameter Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
}

void NParamMatrix::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Matrix Parameter Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
  stream << pad(depth+1) << "Dimensions" << std::endl;
  for (ConstList::iterator it = dimensions->begin(); it != dimensions->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NStmt::dump(std::ostream &stream, int depth) {


}
