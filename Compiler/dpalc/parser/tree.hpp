//  File Name        : tree.hpp
//  Description      : Abstract syntax tree definitions
//
//  Revision History :
//      Albert Ng   Apr 16 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant declaration nodes
//      Albert Ng   Apr 23 2014     Constant matrix declaration nodes
//                                  DP Matrix declaration nodes
//                                  Cell Function declaration nodes
//      Albert Ng   Apr 24 2014     Initial parser implementation completed

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>

class NProgram;
class NAlphabetDecl;
class NCharacterDecl;
class NIdentifier;
class NConst;
class NIntConst;
class NBoolConst;
class NIdConst;
class NType;
class NConstDecl;
class NConstScalarDecl;
class NConstMatrixDecl;
class NConstMatrixElem;
class NDPMatrixDecl;
class NCellFuncDecl;
class NConditionFuncDecl;
class NParam;
class NParamScalar;
class NParamMatrix;
class NStmt;
class NVariableDecl;
class NIfStmt;
class NAssignStmt;
class NSwitchStmt;
class NCaseStmt;
class NReportStmt;
class NExpression;

typedef std::vector<NCharacterDecl*> CharacterDeclList;
typedef std::vector<NConstDecl*> ConstDeclList;
typedef std::vector<NConst*> ConstList;
typedef std::vector<NConstMatrixElem*> ConstMatrixElemList;
typedef std::vector<NDPMatrixDecl*> DPMatrixDeclList;
typedef std::vector<NParam*> ParamList;
typedef std::vector<NStmt*> StmtList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NCaseStmt*> CaseStmtList;

enum TypeName {UNSIGNED, SIGNED, BOOL};

class Node {
  public:
    virtual void dump(std::ostream& stream, int depth) = 0;
};

class NProgram : public Node {
  public:
    NAlphabetDecl* alphabet_decl;
    ConstDeclList* const_decl_list;
    DPMatrixDeclList* dp_matrix_decl_list;
    NCellFuncDecl* cell_func_decl;
    NConditionFuncDecl* condition_func_decl;
    NProgram(NAlphabetDecl* alphabet_decl, ConstDeclList* const_decl_list, 
             DPMatrixDeclList* dp_matrix_decl_list, NCellFuncDecl* cell_func_decl,
             NConditionFuncDecl* condition_func_decl) :
      alphabet_decl(alphabet_decl), const_decl_list(const_decl_list), 
      dp_matrix_decl_list(dp_matrix_decl_list), cell_func_decl(cell_func_decl),
      condition_func_decl(condition_func_decl) {}
    void dump(std::ostream& stream, int depth);
};

class NAlphabetDecl : public Node {
  public:
    CharacterDeclList* characters;
    NAlphabetDecl(CharacterDeclList* characters) : characters(characters) {}
    void dump(std::ostream& stream, int depth);
};
    
class NCharacterDecl : public Node {
  public:
    NIdentifier* id;
    NIntConst* value;
    NCharacterDecl(NIdentifier* id, NIntConst* value) : id(id), value(value) {}
    NCharacterDecl(NIdentifier* id) : id(id), value(NULL) {}
    void dump(std::ostream& stream, int depth);
};

class NExpression : public Node {
};

class NIdentifier : public NExpression {
  public:
    std::string* name;
    NIdentifier(std::string* name) : name(name) {}
    void dump(std::ostream& stream, int depth);
};

class NConst : public NExpression {
};

class NIntConst : public NConst {
  public:
    int value;
    NIntConst(int value) : value(value) {}
    void dump(std::ostream& stream, int depth);
};

class NBoolConst : public NConst {
  public:
    bool value;
    NBoolConst(bool value) : value(value) {}
    void dump(std::ostream& stream, int depth);
};

class NIdConst : public NConst {
  public:
    NIdentifier* id;
    NIdConst(NIdentifier* id) : id(id) {}
    void dump(std::ostream& stream, int depth);
};

class NType : public Node {
  public:
    TypeName type;
    NConst* bitwidth;
    NType(TypeName type, NConst* bitwidth) : type(type), bitwidth(bitwidth) {}
    void dump(std::ostream& stream, int depth);
};

class NConstDecl : public Node {
  public:
    NIdentifier* id;
    NType* type;
};

class NConstScalarDecl : public NConstDecl {
  public:
    NIdentifier* id;
    NType* type;
    NConst* value;
    NConstScalarDecl(NIdentifier* id, NType* type, NConst* value) : id(id), type(type), value(value) {}
    void dump(std::ostream& stream, int depth);
};

class NConstMatrixDecl : public NConstDecl {
  public:
    NIdentifier* id;
    NType* type;
    ConstList* dimensions;
    NConstMatrixElem* matrix_element;
    NConstMatrixDecl(NIdentifier* id, NType* type, ConstList* dimensions, NConstMatrixElem* matrix_element) : 
                                  id(id), type(type), dimensions(dimensions), matrix_element(matrix_element) {}
    void dump(std::ostream& stream, int depth);
};

class NConstMatrixElem : public Node {
  public:
    ConstMatrixElemList* matrix_elements;
    ConstList* values;
    NConstMatrixElem(ConstMatrixElemList* matrix_elements) : 
                             matrix_elements(matrix_elements), values(NULL) {}
    NConstMatrixElem(ConstList* values) : matrix_elements(NULL), values(values) {} 
    void dump(std::ostream& stream, int depth);
}; 

class NDPMatrixDecl : public Node {
  public:
    NType* type;
    NIdentifier* id;
    NDPMatrixDecl(NIdentifier* id, NType* type) : id(id), type(type) {}
    void dump(std::ostream& stream, int depth);
};

class NCellFuncDecl : public Node {
  public:
    ParamList* param_list;
    StmtList* stmt_list;
    NCellFuncDecl(ParamList* param_list, StmtList* stmt_list) : 
                        param_list(param_list), stmt_list(stmt_list) {}
    void dump(std::ostream& stream, int depth);
};

class NConditionFuncDecl : public Node {
  public:
    ParamList* param_list;
    StmtList* stmt_list;
    NConditionFuncDecl(ParamList* param_list, StmtList* stmt_list) :
                        param_list(param_list), stmt_list(stmt_list) {}
    void dump(std::ostream& stream, int depth);
};

class NParam : public Node {
};

class NParamScalar : public NParam {
  public:
    NIdentifier* id;
    NType* type;
    NParamScalar(NIdentifier*id, NType* type) : id(id), type(type) {}
    void dump(std::ostream& stream, int depth);
};

class NParamMatrix : public NParam {
  public:
    NIdentifier* id;
    NType* type;
    ConstList* dimensions;
    NParamMatrix(NIdentifier* id, NType* type, ConstList* dimensions) : id(id), type(type), dimensions(dimensions) {}
    void dump(std::ostream& stream, int depth);
};

class NStmt : public Node {
};

class NVariableDecl : public NStmt {
  public:
    NType* type; 
    NIdentifier* id;
    NExpression* value;
    NVariableDecl(NType* type, NIdentifier* id, NExpression* value) : id(id), type(type), value(value) {}
    NVariableDecl(NType* type, NIdentifier* id) : id(id), type(type), value(NULL) {}
    void dump(std::ostream &stream, int depth);
};

class NIfStmt : public NStmt {
  public:
    NExpression* condition;
    StmtList* if_body;
    StmtList* else_body;
    NIfStmt(NExpression* condition, StmtList* if_body) : 
                                      condition(condition), if_body(if_body), else_body(NULL) {}
    NIfStmt(NExpression* condition, StmtList* if_body, StmtList* else_body) : 
                                      condition(condition), if_body(if_body), else_body(else_body) {}
    void dump(std::ostream &stream, int depth);
};

class NAssignStmt : public NStmt {
  public:
    NIdentifier* id;
    ExpressionList* indices;
    NExpression* value;
    NAssignStmt(NIdentifier* id, ExpressionList* indices, NExpression* value) : 
                                      id(id), indices(indices), value(value) {}
    NAssignStmt(NIdentifier* id, NExpression* value) :
                                      id(id), indices(NULL), value(value) {}
    void dump(std::ostream &stream, int depth);
};

class NSwitchStmt : public NStmt {
  public:
    NExpression* control_expr;
    CaseStmtList* case_stmts;
    NSwitchStmt(NExpression* control_expr, CaseStmtList* case_stmts) :
                            control_expr(control_expr), case_stmts(case_stmts) {}
    void dump(std::ostream &stream, int depth);
};

class NCaseStmt : public Node {
  public:
    NExpression* case_expr;
    StmtList* case_body;
    NCaseStmt(NExpression* case_expr, StmtList* case_body) : case_expr(case_expr), case_body(case_body) {}
    NCaseStmt(StmtList* case_body) : case_expr(NULL), case_body(case_body) {}
    void dump(std::ostream &stream, int depth);
};

class NReportStmt : public NStmt {
  public:
    NReportStmt() {}
    void dump(std::ostream &stream, int depth);
};

class NMaxExpr : public NExpression {
  public:
    ExpressionList* arguments;
    NMaxExpr(ExpressionList* arguments) : arguments(arguments) {}
    void dump(std::ostream &stream, int depth);
};

class NPlusExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NPlusExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NMinusExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NMinusExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCLTExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCLTExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCLEExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCLEExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCGTExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCGTExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCGEExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCGEExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCEQExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCEQExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NCNEExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NCNEExpr(NExpression*op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NLNOTExpr : public NExpression {
  public:
    NExpression* op1;
    NLNOTExpr(NExpression* op1) : op1(op1) {}
    void dump(std::ostream &stream, int depth);
};

class NLANDExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NLANDExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NLORExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NLORExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NLShiftExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NLShiftExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NRShiftExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NRShiftExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NANDExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NANDExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NXORExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NXORExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NORExpr : public NExpression {
  public:
    NExpression* op1;
    NExpression* op2;
    NORExpr(NExpression* op1, NExpression* op2) : op1(op1), op2(op2) {}
    void dump(std::ostream &stream, int depth);
};

class NNotExpr : public NExpression {
  public:
    NExpression* op1;
    NNotExpr(NExpression* op1) : op1(op1) {}
    void dump(std::ostream &stream, int depth);
};

class NNegExpr : public NExpression {
  public:
    NExpression* op1;
    NNegExpr(NExpression *op1) : op1(op1) {}
    void dump(std::ostream &stream, int depth);
};

class NMatrixElemExpr : public NExpression {
  public:
    NIdentifier* id;
    ExpressionList* indices;
    NMatrixElemExpr(NIdentifier* id, ExpressionList* indices) : id(id), indices(indices) {}
    void dump(std::ostream &stream, int depth);
};

class NQueryCharExpr : public NExpression {
  public:
    NQueryCharExpr() {}
    void dump(std::ostream &stream, int depth);
};

class NRefCharExpr : public NExpression {
  public:
    NRefCharExpr() {}
    void dump(std::ostream &stream, int depth);
};

class NRowExpr : public NExpression {
  public:
    NRowExpr() {}
    void dump(std::ostream &stream, int depth);
};

class NColExpr : public NExpression {
  public:
    NColExpr() {}
    void dump(std::ostream &stream, int depth);
};

#endif // TREE_H_
