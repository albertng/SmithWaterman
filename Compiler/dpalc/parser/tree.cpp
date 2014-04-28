//  File Name        : tree.cpp
//  Description      : Abstract syntax tree
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant declaration nodes
//      Albert Ng   Apr 23 2014     Constant matrix declaration nodes
//                                  DP Matrix declaration nodes
//                                  Cell function declaration nodes
//      Albert Ng   Apr 24 2014     Initial parser implementation completed

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
  condition_func_decl->dump(stream, depth+1);
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

void NConditionFuncDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Condition Function Declaration" << std::endl;

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

void NVariableDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Variable Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
  if (value) {
    value->dump(stream, depth+1);
  }
}

void NIfStmt::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "If Statement" << std::endl;
  
  stream << pad(depth+1) << "Condition Expression" << std::endl;
  condition->dump(stream, depth+2);

  stream << pad(depth+1) << "If Body" << std::endl;
  for (StmtList::iterator it = if_body->begin(); it != if_body->end(); it++) {
    (*it)->dump(stream, depth+2);
  }

  if (else_body) {
    stream << pad(depth+1) << "Else Body" << std::endl;
    for (StmtList::iterator it = else_body->begin(); it != else_body->end(); it++) {
      (*it)->dump(stream, depth+2);
    }
  }
}

void NAssignStmt::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Assign Statement" << std::endl;
  
  id->dump(stream, depth+1);
  
  if (indices) {
    stream << pad(depth+1) << "Matrix Index Expressions" << std::endl;
    for (ExpressionList::iterator it = indices->begin(); it != indices->end(); it++) {
      (*it)->dump(stream, depth+2);
    }
  }

  value->dump(stream, depth+1);
}

void NSwitchStmt::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Switch Statement" << std::endl;
  
  stream << pad(depth+1) << "Control Expression" << std::endl;
  control_expr->dump(stream, depth+2);

  stream << pad(depth+1) << "Case List" << std::endl;
  for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NCaseStmt::dump(std::ostream &stream, int depth) {
  if (case_expr) {
    stream << pad(depth) << "Case Statement" << std::endl;

    stream << pad(depth+1) << "Case Expression" << std::endl;
    case_expr->dump(stream, depth+2);
  } else {
    stream << pad(depth) << "Default Case Statement" << std::endl;
  }

  stream << pad(depth+1) << "Case Body" << std::endl;
  for (StmtList::iterator it = case_body->begin(); it != case_body->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NReportStmt::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Report Function Call" << std::endl;
}

void NMaxExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Max Function Call Expression" << std::endl;
  
  stream << pad(depth+1) << "Arguments" << std::endl;
  for (ExpressionList::iterator it = arguments->begin(); it != arguments->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NPlusExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Plus Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NMinusExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Minus Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCLTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Less Than Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCLEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Less or Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCGTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Greater Than Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCGEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Greater or Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCEQExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NCNEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Not Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NLNOTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical NOT Expression" << std::endl;
  op1->dump(stream, depth+1);
}

void NLANDExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical AND Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NLORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical OR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NLShiftExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Left Shift Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NRShiftExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Right Shift Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NANDExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise AND Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NXORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise XOR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise OR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

void NNotExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise NOT Expression" << std::endl;
  op1->dump(stream, depth+1);
}

void NNegExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Unary Negative Expression" << std::endl;
  op1->dump(stream, depth+1);
}

void NMatrixElemExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Matrix Element Expression" << std::endl;
  id->dump(stream, depth+1);
  
  stream << pad(depth+1) << "Matrix Index Expressions" << std::endl;
  for (ExpressionList::iterator it = indices->begin(); it != indices->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NQueryCharExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Query Char Expression" << std::endl;
}

void NRefCharExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Ref Char Expression" << std::endl;
}

void NRowExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Row Expression" << std::endl;
}

void NColExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Col Expression" << std::endl;
}

