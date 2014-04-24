//  File Name        : tree.hpp
//  Description      : Abstract syntax tree definitions
//
//  Revision History :
//      Albert Ng   Apr 16 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant declaration nodes
//      Albert Ng   Apr 23 2014     Constant matrix declaration nodes
//                                  DP Matrix declaration nodes
//                                  Cell Function declaration nodes

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
class NParam;
class NParamScalar;
class NParamMatrix;
class NStmt;

typedef std::vector<NCharacterDecl*> CharacterDeclList;
typedef std::vector<NConstDecl*> ConstDeclList;
typedef std::vector<NConst*> ConstList;
typedef std::vector<NConstMatrixElem*> ConstMatrixElemList;
typedef std::vector<NDPMatrixDecl*> DPMatrixDeclList;
typedef std::vector<NParam*> ParamList;
typedef std::vector<NStmt*> StmtList;

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
    NProgram(NAlphabetDecl* alphabet_decl, ConstDeclList* const_decl_list, 
             DPMatrixDeclList* dp_matrix_decl_list, NCellFuncDecl* cell_func_decl) :
      alphabet_decl(alphabet_decl), const_decl_list(const_decl_list), 
      dp_matrix_decl_list(dp_matrix_decl_list), cell_func_decl(cell_func_decl) {}
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

class NIdentifier : public Node {
  public:
    std::string* name;
    NIdentifier(std::string* name) : name(name) {}
    void dump(std::ostream& stream, int depth);
};

class NConst : public Node {
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
  public:
    NStmt() {}
    void dump(std::ostream & stream, int depth);
};

#endif // TREE_H_
