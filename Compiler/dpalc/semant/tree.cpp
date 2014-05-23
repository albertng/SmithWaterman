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
//      Albert Ng   May 13 2014     Type evaluation for expressions
//                                  Added scoping
//      Albert Ng   May 14 2014     Constant table
//                                  DP Matrix symbol table entries
//      Albert Ng   May 15 2014     Variable decls at start of function
//      Albert Ng   May 23 2014     Removed condition function and report statement

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <assert.h>
#include <set>
#include "symtab.hpp"
#include "consttab.hpp"
#include "tree.hpp"
#include "utils.hpp"
#include "datatype.hpp"

extern SymbolTable symbol_table;
extern ConstTable const_table;

static int semant_errors = 0;

void NProgram::Semant() {
  alphabet_decl->Semant();

  for (ConstDeclList::iterator it = const_decl_list->begin();
         it != const_decl_list->end(); it++) {
    (*it)->Semant();
  }
  for (DPMatrixDeclList::iterator it = dp_matrix_decl_list->begin(); 
         it != dp_matrix_decl_list->end(); it++) {
    (*it)->Semant();
  }

  // Check for score DP matrix declared
  SymbolTableEntry* score_entry = symbol_table.GetEntry("score");
  if (score_entry == NULL || score_entry->get_symboltype() != DP_MAT) {
    std::cerr << "Error: score[][] dynamic programming matrix not defined."
              << std::endl;
    semant_errors++;
  }
 
  cell_func_decl->Semant();

  if (semant_errors > 0) {
    std::cerr << "Exiting due to " << semant_errors << " semantic errors" << std::endl;
    exit(1);
  }
}

void NAlphabetDecl::Semant() {
  // Check all characters have either all explicit values or all implicit values
  bool all_explicit = true;
  bool all_implicit = true;
  for (CharacterDeclList::iterator it = characters->begin(); it != characters->end(); it++) {
    if ((*it)->value == NULL) {
      all_explicit = false;
    } else {
      all_implicit = false;
    }
  }
  if (!(all_explicit || all_implicit)) {
    std::cerr << "Error: Alphabet characters must have either all explicit or all implicit values." 
              << std::endl;
    semant_errors++;
  }

  // Check all explicit values are non-negative
  for (CharacterDeclList::iterator it = characters->begin(); it != characters->end(); it++) {
    if ((*it)->value != NULL && (*it)->value->value < 0) {
      std::cerr << "Error: Alphabet character '" << *((*it)->id->name) << "' explicit value must be non-negative."
                << std::endl;
      semant_errors++;
    }
  }

  // Fill in implicit values, and find maximum character bitwidth
  int max_val = 0;
  for (int i = 0; i < characters->size(); i++) {
    if (characters->at(i)->value == NULL) {
      characters->at(i)->value = new NIntConst(i);
      max_val = max_val > i ? max_val : i;
    } else {
      max_val = max_val > characters->at(i)->value->value ? max_val : characters->at(i)->value->value;
    }
  }
  int max_bitwidth;
  if (max_val <= 0) {
    max_bitwidth = 1;
  } else {
    max_bitwidth = ceil(log2((float) max_val));
    if ((max_val & (max_val - 1)) == 0) {
      max_bitwidth++;
    }
  }

  // Add alphabet characters to the symbol tables
  for (CharacterDeclList::iterator it = characters->begin(); it != characters->end(); it++) {
    SymbolTableEntry* entry = new SymbolTableEntry(*((*it)->id->name),
                                                   CHARACTER,
                                                   DataType(UNSIGNED, max_bitwidth),
                                                   true);
    if (!(symbol_table.AddEntry(entry))) {
      std::cerr << "Error: Alphabet character identifier '" << *((*it)->id->name) << "' previously declared."
                << std::endl;
      semant_errors++;
    }

    ConstData ct_data;
    ct_data.int_data = (*it)->value->value;
    ConstTableEntry* ct_entry = new ConstTableEntry(*(*it)->id->name,
                                                    INT_DATA,
                                                    ct_data);
    const_table.AddEntry(ct_entry);
  }
}

void NConstScalarDecl::Semant() {
  DataType dtype = type->GetDataType();
  DataType vtype = value->EvaluateType();

  // Check value data type
  DataType matchtype = DataType::Match(dtype, vtype);
  if (matchtype.type_name == ERROR_TYPE && vtype.type_name != ERROR_TYPE) {
    std::cerr << "Error: Constant scalar '" << *(id->name) << "' value assignment does not match declared type."
              << std::endl;
    semant_errors++;
  }

  // Add to symbol table
  SymbolTableEntry* entry = new SymbolTableEntry(*(id->name),
                                                 CONST_SCALAR,
                                                 vtype, // Don't care about bitwidth or signedness for constants
                                                 true);
  if (!(symbol_table.AddEntry(entry))) {
    std::cerr << "Error: Constant scalar '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
  }

  // Add constant value to constant table
  if (matchtype.type_name != ERROR_TYPE) {
    ConstData ct_data = value->GetConstData();
    ConstDataType ct_datatype = value->GetConstDataType();
    ConstTableEntry* ct_entry = new ConstTableEntry(*(id->name), ct_datatype, ct_data);
    const_table.AddEntry(ct_entry);
  }
}

void NConstMatrixDecl::Semant() {
  bool decl_error = false;

  // Check dimension list data types and build dimensions vector
  std::vector<int>* dimensions_vec = new std::vector<int>();
  for (ConstList::iterator it = dimensions->begin(); it != dimensions->end(); it++) {
    DataType dtype = (*it)->EvaluateType();
    if (dtype.type_name != INT_CONST) {
      std::cerr << "Error: Constant matrix '" << *(id->name) << "' dimensions must be constant integer type."
                << std::endl;
      semant_errors++;
      decl_error = true;
    } else {
      ConstData cdata = (*it)->GetConstData();
      ConstDataType cdatatype = (*it)->GetConstDataType();
      if (cdatatype != INT_DATA) {
        std::cerr << "Error: Constant matrix '" << *(id->name) << "' dimensions must be constant integer type."
                  << std::endl;
        semant_errors++;
        decl_error = true;
      }
      dimensions_vec->push_back(cdata.int_data);
    }
  }

  // Check matrix value data types
  DataType dtype = type->GetDataType();
  DataType vtype = matrix_element->EvaluateType();
  DataType matchtype = DataType::Match(dtype, vtype);
  if (matchtype.type_name == ERROR_TYPE) {
    std::cerr << "Error: Constant matrix '" << *(id->name) << "' value assignment does not match declared type."
              << std::endl;
    semant_errors++;
    decl_error = true;
  }

  // Check matrix dimensions valid
  if (matrix_element->CheckDimensions(*dimensions_vec) == false) {
    std::cerr << "Error: Constant matrix '" << *(id->name) << "' value assignment does not match declared dimensions."
              << std::endl;
    semant_errors++;
    decl_error = true;
  }

  if (decl_error == false) {
    // Add to symbol table
    SymbolTableEntry* entry = new SymbolTableEntry(*(id->name),
                                                   CONST_MAT,
                                                   matchtype,
                                                   dimensions_vec,
                                                   true);
    if (!(symbol_table.AddEntry(entry))) {
      std::cerr << "Error: Constant matrix '" << *(id->name) << "' previously declared."
                << std::endl;
      semant_errors++;
    }

    // Add constant value vector to constant table
    assert(matchtype.type_name != INT_CONST);
    if (matchtype.type_name != ERROR_TYPE) {
      std::vector<ConstData>* matrix_data = new std::vector<ConstData>();
      (*matrix_data) = matrix_element->GetConstData();

      ConstData ct_data;
      ct_data.matrix_data = matrix_data;

      ConstDataType ct_datatype;
      switch(matchtype.type_name) {
        case UNSIGNED :
        case SIGNED   : ct_datatype = INT_MATRIX_DATA;  break;
        case BOOL     : ct_datatype = BOOL_MATRIX_DATA; break;
        default       : assert(false); break;
      }

      ConstTableEntry* ct_entry = new ConstTableEntry(*(id->name),
                                                      ct_datatype,
                                                      ct_data,
                                                      dimensions_vec);
      const_table.AddEntry(ct_entry);
    }
  }
}
                                                 

void NProgram::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Symbol Table" << std::endl;
  symbol_table.dump(stream, depth+1);

  stream << pad(depth) << "Constant Table" << std::endl;
  const_table.dump(stream, depth+1);
 
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

DataType NIdentifier::EvaluateType() {
  SymbolTableEntry* entry = symbol_table.GetEntry(*name);

  if (entry == NULL) {
    return DataType(ERROR_TYPE, 0);
  } else {
    return entry->get_datatype();
  }
}

bool NIdentifier::CheckInit() {
  SymbolTableEntry* entry = symbol_table.GetEntry(*name);
  if (entry == NULL) {
    return false;
  } else {
    bool init = entry->get_init();
    if (init == false) {
      std::cerr << "Warning: Identifier '" << *name << "' may be uninitialized when referenced."
                << std::endl;
    }
    return init;
  }
}

void NIdentifier::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Identifier " << *name << std::endl;
}

DataType NIntConst::EvaluateType() {
  type = DataType(INT_CONST, 0);
  return type;
}

ConstData NIntConst::GetConstData() {
  ConstData data;
  data.int_data = value;
  return data;
}

ConstDataType NIntConst::GetConstDataType() {
  return INT_DATA;
}

void NIntConst::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Int Const " << value << std::endl;
}

ConstData NBoolConst::GetConstData() {
  ConstData data;
  data.bool_data = value;
  return data;
}

ConstDataType NBoolConst::GetConstDataType() {
  return BOOL_DATA;
}
  

DataType NBoolConst::EvaluateType() {
  type = DataType(BOOL, 0);
  return type;
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

DataType NIdConst::EvaluateType() {
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));

  if (entry == NULL) { 
    std::cerr << "Error: Identifier '" << *(id->name) << "' previously undeclared."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = entry->get_datatype();
  }

  return type;
}

ConstData NIdConst::GetConstData() {
  ConstData data;

  ConstTableEntry* entry = const_table.GetEntry(*(id->name));
  if (entry != NULL) {
    data = entry->get_data();
  }
  
  return data;
}

ConstDataType NIdConst::GetConstDataType() {
  ConstDataType datatype;
  
  ConstTableEntry* entry = const_table.GetEntry(*(id->name));
  if (entry != NULL) {
    datatype = entry->get_datatype();
  }

  return datatype;
}

void NIdConst::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Identifier Const" << std::endl;
  id->dump(stream, depth+1);
}

DataType NType::GetDataType() {
  DataType dtype;
  dtype.type_name = type_name;
  if (bitwidth_int != NULL) {
    dtype.bitwidth = bitwidth_int->value;
  } else {
    ConstTableEntry* entry = const_table.GetEntry(*(bitwidth_id->id->name));
    if (entry == NULL) {
      std::cerr << "Error: Constant identifier '" << *(bitwidth_id->id->name) << "' previously undeclared."
                << std::endl;
      semant_errors++;
    } else if (entry->get_datatype() != INT_DATA) {
      std::cerr << "Error: Type bitwidth identifier '" << *(bitwidth_id->id->name) << "' must be of integer type."
                << std::endl;
      semant_errors++;
    } else {
      dtype.bitwidth = (entry->get_data()).int_data;
    }
  }

  return dtype;
} 

void NType::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Type" << std::endl;

  stream << pad(depth+1) << "Typename ";
  switch(type_name) {
    case UNSIGNED : stream << "unsigned ";
                    break;
    case SIGNED   : stream << "signed ";
                    break;
    case BOOL     : stream << "bool ";
                    break;
    default       : break;
  }
  stream << std::endl;

  if (bitwidth_int != NULL) {
    bitwidth_int->dump(stream, depth+1);
  } else {
    bitwidth_id->dump(stream, depth+1);
  }
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

DataType NConstMatrixElem::EvaluateType() {
  // Leaf node: Match types of all values
  if (matrix_elements == NULL) {
    for (ConstList::iterator it = values->begin(); it != values->end(); it++) {
      ConstDataType ct_datatype = (*it)->GetConstDataType();
      if (ct_datatype == INT_MATRIX_DATA || ct_datatype == BOOL_MATRIX_DATA) {
        std::cerr << "Error: Constant value assignment must be scalar values."
                  << std::endl;
        semant_errors++;
      }
      if (it == values->begin()) {
        type = (*it)->EvaluateType();
      } else {
        DataType value_type = (*it)->EvaluateType();
        type = DataType::Match(type, value_type);
      }
    }
  } else { // Inside node: Match types of child nodes
    for (ConstMatrixElemList::iterator it = matrix_elements->begin(); it != matrix_elements->end(); it++) {
      if (it == matrix_elements->begin()) {
        type = (*it)->EvaluateType();
      } else {
        DataType value_type = (*it)->EvaluateType();
        type = DataType::Match(type, value_type);
      }
    }
  }
  return type;
}

std::vector<ConstData> NConstMatrixElem::GetConstData() {
  std::vector<ConstData> cdata;

  // Leaf node: Build vector of values from leaves
  if (matrix_elements == NULL) {
    for (ConstList::iterator it = values->begin(); it != values->end(); it++) {
      cdata.push_back((*it)->GetConstData());
    }
  } else { // Inside node: Build vector from sub-nodes
    for (ConstMatrixElemList::iterator it = matrix_elements->begin(); it != matrix_elements->end(); it++) {
      ConstData child_cdata;
      child_cdata.matrix_data = new std::vector<ConstData>();
      (*child_cdata.matrix_data) = (*it)->GetConstData();
      cdata.push_back(child_cdata);
    }
  }

  return cdata;
}

bool NConstMatrixElem::CheckDimensions(std::vector<int> dimensions) {
  // Leaf node: Check number of values is equal to last dimension
  if (matrix_elements == NULL) {
    if (dimensions.size() != 1 || dimensions[0] != values->size()) {
      return false;
    } else {
      return true;
    }
  } else { // Inside node: Check number of child nodes is equal to current dimension
    if (dimensions.size() <= 1 || dimensions[0] != matrix_elements->size()) {
      return false;
    } else {
      // Check leaf node dimensions are valid
      dimensions.erase(dimensions.begin());
      for (ConstMatrixElemList::iterator it = matrix_elements->begin(); it != matrix_elements->end(); it++) {
        if ((*it)->CheckDimensions(dimensions) == false) {
          return false;
        }
      }
      return true;
    }
  }
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

void NDPMatrixDecl::Semant() {
  SymbolTableEntry* entry = new SymbolTableEntry(*(id->name),
                                                 DP_MAT,
                                                 type->GetDataType(),
                                                 true);
  if (!symbol_table.AddEntry(entry)) {
    std::cerr << "Error: Dynamic programming matrix identifier '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
  } 
}

void NDPMatrixDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "DP Matrix Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
}

void NCellFuncDecl::Semant() {
  // Check and add parameters to symbol table
  for (ParamList::iterator it = param_list->begin(); it != param_list->end(); it++) {
    (*it)->Semant();
  }

  // Check and add variables to symbol table
  for (VariableDeclList::iterator it = variable_decl_list->begin(); it != variable_decl_list->end(); it++) {
    (*it)->Semant();
  }

  // Statement TypeChecking
  for (StmtList::iterator it = stmt_list->begin(); it != stmt_list->end(); it++) {
    (*it)->Semant(true);
  }

  // Check all DP matrices are assigned unconditionally
  std::list<std::string> dp_mat_names = symbol_table.GetSymbolNamesWithType(DP_MAT);
  for (StmtList::iterator it = stmt_list->begin(); it != stmt_list->end(); it++) {
    std::string dp_mat_name = (*it)->GetAssignDPMatrixName();
    if (dp_mat_name != "") {
      for (std::list<std::string>::iterator n_it = dp_mat_names.begin(); n_it != dp_mat_names.end(); n_it++) {
        if ((*n_it) == dp_mat_name) {
          dp_mat_names.erase(n_it);
          break;
        }
      }
    }
  }
  for (std::list<std::string>::iterator it = dp_mat_names.begin(); it != dp_mat_names.end(); it++) {
    std::cerr << "Warning: Dynamic programming matrix '" << *it << "' may not be assigned in CELL() function."
              << std::endl;
  }
}

void NCellFuncDecl::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Cell Function Declaration" << std::endl;

  stream << pad(depth+1) << "Parameters" << std::endl;
  for (ParamList::iterator it = param_list->begin(); it != param_list->end(); it++) {
    (*it)->dump(stream, depth+2);
  }

  stream << pad(depth+1) << "Variable Declarations" << std::endl;
  for (VariableDeclList::iterator it = variable_decl_list->begin(); it != variable_decl_list->end(); it++) {
    (*it)->dump(stream, depth+2);
  }

  stream << pad(depth+1) << "Statements" << std::endl;
  for (StmtList::iterator it = stmt_list->begin(); it != stmt_list->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

void NParamScalar::Semant() {
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry != NULL) {
    std::cerr << "Error: Scalar param identifier '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
  } else {
    entry = new SymbolTableEntry(*(id->name),
                                 PARAM_SCALAR,
                                 type->GetDataType(),
                                 true);

    if (!(symbol_table.AddEntry(entry))) {
      std::cerr << "Error: Scalar parameter identifier '" << *(id->name) << "' previously declared."
                << std::endl;
      semant_errors++;
    }
  }                                              
}

void NParamScalar::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Scalar Parameter Declaration" << std::endl;
  id->dump(stream, depth+1);
  type->dump(stream, depth+1);
}

void NParamMatrix::Semant() {
  bool decl_error = false;

  // Check identifier not previously declared
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry != NULL) {
    std::cerr << "Error: Matrix parameter identifier '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
    decl_error = true;
  }

  // Check dimension list data types and build dimensions vector
  std::vector<int>* dimensions_vec = new std::vector<int>();
  for (ConstList::iterator it = dimensions->begin(); it != dimensions->end(); it++) {
    DataType dtype = (*it)->EvaluateType();
    if (dtype.type_name != INT_CONST) {
      std::cerr << "Error: Constant matrix '" << *(id->name) << "' dimensions must be constant integer type."
                << std::endl;
      semant_errors++;
      decl_error = true;
    } else {
      ConstData cdata = (*it)->GetConstData();
      ConstDataType cdatatype = (*it)->GetConstDataType();
      if (cdatatype != INT_DATA) {
        std::cerr << "Error: Constant matrix '" << *(id->name) << "' dimensions must be constant integer type."
                  << std::endl;
        semant_errors++;
        decl_error = true;
      }
      dimensions_vec->push_back(cdata.int_data);
    }
  }

  // Add symbol to function symbol table if no declaration error
  if (decl_error == false) {
    entry = new SymbolTableEntry(*(id->name),
                                 PARAM_MAT,
                                 type->GetDataType(),
                                 dimensions_vec,
                                 true);

    // Add entry while checking if previously declared.
    if (!(symbol_table.AddEntry(entry))) {
      std::cerr << "Error: Matrix parameter identifier '" << *(id->name) << "' previously declared."
                << std::endl;
      semant_errors++;
    }
  }
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

void NVariableDecl::Semant() {
  // Check assignment type
  bool init = false;
  if (value != NULL) {
    DataType dtype = type->GetDataType();
    DataType vtype = value->EvaluateType();
    DataType matchtype = DataType::Match(dtype, vtype);
    if (matchtype.type_name == ERROR_TYPE && vtype.type_name != ERROR_TYPE) {
      std::cerr << "Error: Identifier '" << *(id->name) << "' assign statement does not match type."
                << std::endl;
      semant_errors++;
    } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
      std::cerr << "Error: Identifier '" << *(id->name) << "' assign statement value type is invalid."
                << std::endl;
      semant_errors++;
    }
    init = true;
  }

  // Check if previously defined in symbol table
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry != NULL) {
    std::cerr << "Error: Variable identifier '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
  }

  entry = new SymbolTableEntry(*(id->name),
                               VAR,
                               type->GetDataType(),
                               init);

  if (!(symbol_table.AddEntry(entry))) {
    std::cerr << "Error: Variable identifier '" << *(id->name) << "' previously declared."
              << std::endl;
    semant_errors++;
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

void NIfStmt::Semant(bool toplevel) {
  // Check condition type
  DataType cond_type = condition->EvaluateType();
  if (cond_type.type_name != BOOL && cond_type.type_name != ERROR_TYPE) {
    std::cerr << "Error: If statement condition must be bool type."
              << std::endl;
    semant_errors++;
  }

  // Check if statement block
  for (StmtList::iterator it = if_body->begin(); it != if_body->end(); it++) {
    (*it)->Semant(false);
  }

  // Check else statement block
  if (else_body != NULL) {
    for (StmtList::iterator it = else_body->begin(); it != else_body->end(); it++) {
      (*it)->Semant(false);
    }
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

std::string NAssignStmt::GetAssignDPMatrixName() {
  std::string dp_mat_name = "";

  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry != NULL && entry->get_symboltype() == DP_MAT) {
    dp_mat_name = *(id->name);
  }

  return dp_mat_name;
}

void NAssignStmt::Semant(bool toplevel) {
  // Check identifier declared
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry == NULL) {
    std::cerr << "Error: Variable '" << *(id->name) << "' not previously declared."
              << std::endl;
    semant_errors++;
    return;
  }

  // Check identifier not constant
  SymbolType symbol_type = entry->get_symboltype();
  if (symbol_type == CONST_SCALAR || symbol_type == CONST_MAT) {
    std::cerr << "Error: Cannot assign value to constant identifier '" << *(id->name) << "'."
              << std::endl;
    semant_errors++;
    return;
  }

  // Check identifier not a character
  if (symbol_type == CHARACTER) {
    std::cerr << "Error: Cannot assign value to character identifier '" << *(id->name) << "'."
              << std::endl;
    semant_errors++;
    return;
  }

  // Check identifier not a parameter
  if (symbol_type == PARAM_SCALAR || symbol_type == PARAM_MAT) {
    std::cerr << "Error: Cannot assign value to parameter identifier '" << *(id->name) << "'."
              << std::endl;
    semant_errors++;
    return;
  }

  // Check assignment data type
  DataType dtype = entry->get_datatype();
  DataType vtype = value->EvaluateType();
  DataType matchtype = DataType::Match(dtype, vtype);
  if (matchtype.type_name == ERROR_TYPE && vtype.type_name != ERROR_TYPE) {
    std::cerr << "Error: Identifier '" << *(id->name) << "' assign statement does not match type."
              << std::endl;
    semant_errors++;
  } else if ((matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) && vtype.type_name != ERROR_TYPE) {
    std::cerr << "Error: Identifier '" << *(id->name) << "' assign statement value type is invalid."
              << std::endl;
    semant_errors++;
  }

  // Check DP matrix assignments
  if (symbol_type == DP_MAT) {
    if (indices == NULL || indices->size() != 2) {
      std::cerr << "Error: Dynamic programming matrix identifier '" << *(id->name) << "' reference must have 2 dimensions."
                << std::endl;
      semant_errors++;
    } else {
      DataType rtype = indices->at(0)->EvaluateType();
      DataType ctype = indices->at(1)->EvaluateType();
      if (rtype.type_name != ROW_TYPE || ctype.type_name != COL_TYPE) {
        std::cerr << "Error: Dynamic programming matrix assignment must have [row][col] indices."
                  << std::endl;
        semant_errors++;
      }
    }

    // Check assignment value is a max function
    if (value->IsMax() == false) {
      std::cerr << "Error: Dynamic programming matrix assignment value must be the result of a MAX() call."
                << std::endl;
      semant_errors++;
    }  
  } else if (indices != NULL) {
    std::cerr << "Error: Assignment subscripted identifier '" << *(id->name) << "' is not a dynamic programming matrix."
              << std::endl;
    semant_errors++;
  }

  // Check and warn if identifier reference may be undefined
  if (indices != NULL) {
    for (ExpressionList::iterator it = indices->begin(); it != indices->end(); it++) {
      (*it)->CheckInit();
    }
  }
  value->CheckInit();

  // Flag top level assignments as initialized in symbol table
  if (toplevel == true) {
    entry->set_init(true);
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

void NSwitchStmt::Semant(bool toplevel) {
  // Check there's at most one default statement
  int num_defaults = 0;
  for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
    if ((*it)->IsDefault()) {
      num_defaults++;
    }
  }
  if (num_defaults > 1) {
    std::cerr << "Error: Switch statement contains more than one default case."
              << std::endl;
    semant_errors++;
  }

  // Check case types
  DataType control_type = control_expr->EvaluateType();
  bool case_types_valid = true;
  for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
    if (!(*it)->IsDefault()) {
      DataType case_type = (*it)->case_const->EvaluateType();
      DataType match_type = DataType::Match(control_type, case_type);
      if (match_type.type_name == ERROR_TYPE && control_type.type_name != ERROR_TYPE && case_type.type_name != ERROR_TYPE) {
        std::cerr << "Error: Case constant type does not match switch control expression type."
                  << std::endl;
        semant_errors++;
        case_types_valid = false;
      }
    }
  }

  // Check for duplicate cases
  if (control_type.type_name != ERROR_TYPE && case_types_valid == true) {
    if (control_type.type_name == BOOL) { // Bool Data
      std::set<bool> case_constants;
      for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
        if (!(*it)->IsDefault()) {
          ConstData cdata = (*it)->case_const->GetConstData();
          ConstDataType cdatatype = (*it)->case_const->GetConstDataType();
          assert(cdatatype == BOOL_DATA);

          if (case_constants.count(cdata.bool_data) != 0) {
            std::cerr << "Error: Duplicate case value '" << cdata.bool_data << "'."
                      << std::endl;
            semant_errors++;
          }
          case_constants.insert(cdata.bool_data);
        }
      }
    } else {  // Int Data
      std::set<int> case_constants;
      for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
        if (!(*it)->IsDefault()) {
          ConstData cdata = (*it)->case_const->GetConstData();
          ConstDataType cdatatype = (*it)->case_const->GetConstDataType();
          assert(cdatatype == INT_DATA);

          if (case_constants.count(cdata.int_data) != 0) {
            std::cerr << "Error: Duplicate case value '" << cdata.int_data << "'."
                      << std::endl;
            semant_errors++;
          }
          case_constants.insert(cdata.int_data);
        }
      }
    }
  }
      
  for (CaseStmtList::iterator it = case_stmts->begin(); it != case_stmts->end(); it++) {
    (*it)->Semant();
  }
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

bool NCaseStmt::IsDefault() {
  return (case_const == NULL);
}

void NCaseStmt::Semant() {
  for (StmtList::iterator it = case_body->begin(); it != case_body->end(); it++) {
    (*it)->Semant(false);
  }
}

void NCaseStmt::dump(std::ostream &stream, int depth) {
  if (case_const) {
    stream << pad(depth) << "Case Statement" << std::endl;

    stream << pad(depth+1) << "Case Constant" << std::endl;
    case_const->dump(stream, depth+2);
  } else {
    stream << pad(depth) << "Default Case Statement" << std::endl;
  }

  stream << pad(depth+1) << "Case Body" << std::endl;
  for (StmtList::iterator it = case_body->begin(); it != case_body->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

DataType NMaxExpr::EvaluateType() {
  bool args_valid_type = true;
  for (ExpressionList::iterator it = arguments->begin(); it != arguments->end(); it++) {
    if (it == arguments->begin()) {
      type = arguments->front()->EvaluateType();
      if (type.type_name == ERROR_TYPE) {
        args_valid_type = false;
      }
    } else {
      DataType arg_type = (*it)->EvaluateType();
      if (arg_type.type_name == ERROR_TYPE) {
        args_valid_type = false;
      }
      type = DataType::Match(type, arg_type);
    } 
  }

  if (args_valid_type == true && type.type_name == ERROR_TYPE) {
    std::cerr << "Error: MAX() argument types do not match."
              << std::endl;
    semant_errors++;
  } else if (args_valid_type == true && (type.type_name == ROW_TYPE || type.type_name == COL_TYPE)) {
    std::cerr << "Error: MAX() argument type is invalid."
              << std::endl;
    semant_errors++;
  }

  // TODO: argument dependency graph

  return type;
}

bool NMaxExpr::CheckInit() {
  bool init = true;
  for (ExpressionList::iterator it = arguments->begin(); it != arguments->end(); it++) {
    init = init && (*it)->CheckInit();
  }
  return init;
}

void NMaxExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Max Function Call Expression" << std::endl;
  
  stream << pad(depth+1) << "Arguments" << std::endl;
  for (ExpressionList::iterator it = arguments->begin(); it != arguments->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

DataType NPlusExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  type = DataType::Match(op1type, op2type);

  if (type.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '+' operator argument types do not match."
              << std::endl;
    semant_errors++;
  }

  return type;
}

bool NPlusExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NPlusExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Plus Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NMinusExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  type = DataType::Match(op1type, op2type);

  if (type.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '-' operator argument types do not match."
              << std::endl;
    semant_errors++;
  }

  return type;
}

bool NMinusExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NMinusExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Minus Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NCLTExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '<' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '<' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

bool NCLTExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NCLTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Less Than Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NCLEExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '<=' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '<=' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

bool NCLEExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NCLEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Less or Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NCGTExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '>' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '>' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

bool NCGTExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NCGTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Greater Than Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NCGEExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '>=' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '>=' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

bool NCGEExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NCGEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Greater or Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NCEQExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '==' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '==' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

void NCEQExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

bool NCEQExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

DataType NCNEExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '!=' operator argument types do not match."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (matchtype.type_name == ROW_TYPE || matchtype.type_name == COL_TYPE) {
    std::cerr << "Error: '!=' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = DataType(BOOL, 0);
  }

  return type;
}

bool NCNEExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NCNEExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Compare Not Equal Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NLNOTExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  
  if (op1type.type_name != BOOL && op1type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '!' operator requires boolean argument type."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = op1type;
  }

  return type;
}

bool NLNOTExpr::CheckInit() {
  return op1->CheckInit();
}

void NLNOTExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical NOT Expression" << std::endl;
  op1->dump(stream, depth+1);
}

DataType NLANDExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name != BOOL && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '&&' operator requires boolean argument types."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = matchtype;
  }

  return type;
}

bool NLANDExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NLANDExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical AND Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NLORExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  DataType matchtype = DataType::Match(op1type, op2type);

  if (matchtype.type_name != BOOL && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '||' operator requires boolean argument types."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = matchtype;
  }

  return type;
}

bool NLORExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NLORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Logical OR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NLShiftExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();

  if (((op1type.type_name != UNSIGNED && op1type.type_name != SIGNED && op1type.type_name != INT_CONST) ||
       (op2type.type_name != UNSIGNED && op2type.type_name != SIGNED && op2type.type_name != INT_CONST)) &&
      (op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE)) { 
    std::cerr << "Error: '<<' operator requires integer argument types."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    type = op1type;
  } else {
    type = DataType(ERROR_TYPE, 0);
  }
  
  return type;
}

bool NLShiftExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NLShiftExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Left Shift Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NRShiftExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();

  if (((op1type.type_name != UNSIGNED && op1type.type_name != SIGNED && op1type.type_name != INT_CONST) ||
       (op2type.type_name != UNSIGNED && op2type.type_name != SIGNED && op2type.type_name != INT_CONST)) &&
      (op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE)) { 
    std::cerr << "Error: '>>' operator requires integer argument types."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    type = op1type;
  } else {
    type = DataType(ERROR_TYPE, 0);
  }

  return type;
}

bool NRShiftExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NRShiftExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Right Shift Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NANDExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  type = DataType::Match(op1type, op2type);

  if (type.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '&' operator argument types do not match."
              << std::endl;
    semant_errors++;
  } else if (type.type_name == ROW_TYPE || type.type_name == COL_TYPE) {
    std::cerr << "Error: '&' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  }

  return type;
}

bool NANDExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NANDExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise AND Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NXORExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  type = DataType::Match(op1type, op2type);

  if (type.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '^' operator argument types do not match."
              << std::endl;
    semant_errors++;
  } else if (type.type_name == ROW_TYPE || type.type_name == COL_TYPE) {
    std::cerr << "Error: '^' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  }

  return type;
}

bool NXORExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NXORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise XOR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NORExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
  DataType op2type = op2->EvaluateType();
  type = DataType::Match(op1type, op2type);

  if (type.type_name == ERROR_TYPE && op1type.type_name != ERROR_TYPE && op2type.type_name != ERROR_TYPE) {
    std::cerr << "Error: '|' operator argument types do not match."
              << std::endl;
    semant_errors++;
  } else if (type.type_name == ROW_TYPE || type.type_name == COL_TYPE) {
    std::cerr << "Error: '|' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  }

  return type;
}

bool NORExpr::CheckInit() {
  return op1->CheckInit() && op2->CheckInit();
}

void NORExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise OR Expression" << std::endl;
  op1->dump(stream, depth+1);
  op2->dump(stream, depth+1);
}

DataType NNotExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();

  if (op1type.type_name == ROW_TYPE || op1type.type_name == COL_TYPE) {
    std::cerr << "Error: '~' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = op1type;
  }

  return type;
}

bool NNotExpr::CheckInit() {
  return op1->CheckInit();
}

void NNotExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Bitwise NOT Expression" << std::endl;
  op1->dump(stream, depth+1);
}

DataType NNegExpr::EvaluateType() {
  DataType op1type = op1->EvaluateType();
 
  if (op1type.type_name != UNSIGNED && op1type.type_name != SIGNED && op1type.type_name != INT_CONST &&
      op1type.type_name != ERROR_TYPE) {
    std::cerr << "Error: Unary '-' operator requires integer argument type."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else if (op1type.type_name == ROW_TYPE || op1type.type_name == COL_TYPE) {
    std::cerr << "Error: Unary '-' operator argument types are invalid."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
  } else {
    type = op1type;
  }

  return type;
}

bool NNegExpr::CheckInit() {
  return op1->CheckInit();
}

void NNegExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Unary Negative Expression" << std::endl;
  op1->dump(stream, depth+1);
}

DataType NMatrixElemExpr::EvaluateType() {
  // Check identifier previously declared
  SymbolTableEntry* entry = symbol_table.GetEntry(*(id->name));
  if (entry == NULL) {
    std::cerr << "Error: Identifier '" << *(id->name) << "' previously undeclared."
              << std::endl;
    semant_errors++;
    type = DataType(ERROR_TYPE, 0);
    return type;
  } 

  // Check indices are valid types
  bool indices_valid = true;

  // Dynamic programming matrix
  if (entry->get_symboltype() == DP_MAT) {
    // Check exactly 2 dimensions: first dependent on ROW, second dependent on COL
    if (indices->size() != 2) {
      std::cerr << "Error: Dynamic programming matrix identifier '" << *(id->name) << "' reference must have 2 dimensions."
                << std::endl;
      semant_errors++;
      indices_valid = false;
    } else {
      DataType rtype = indices->at(0)->EvaluateType();
      DataType ctype = indices->at(1)->EvaluateType();
      if (rtype.type_name != ROW_TYPE && rtype.type_name != ERROR_TYPE) {
        std::cerr << "Error: Dynamic programming matrix '" << *(id->name) << "' reference must have first index dependent upon ROW."
                  << std::endl;
        semant_errors++;
        indices_valid = false;
      }
      if (ctype.type_name != COL_TYPE && ctype.type_name != ERROR_TYPE) {
        std::cerr << "Error: Dynamic programming matrix '" << *(id->name) << "' reference must have second index dependent upon COL."
                  << std::endl;
        semant_errors++;
        indices_valid = false;
      }
    }
  } else { // Other matrix
    // Check indices are integer type
    for (ExpressionList::iterator it = indices->begin(); it != indices->end(); it++) {
      DataType index_type = (*it)->EvaluateType();
      if (index_type.type_name != UNSIGNED && index_type.type_name != SIGNED &&
          index_type.type_name != INT_CONST && index_type.type_name != ERROR_TYPE) {
        std::cerr << "Error: Matrix '" << *(id->name) << "' reference index must be integer type."
                  << std::endl;
        semant_errors++;
        indices_valid = false;
      } else if (index_type.type_name == ERROR_TYPE) {
        indices_valid = false;
      } 
    }

    // Check right number of dimensions
    std::vector<int>* id_dims = entry->get_dimensions();
    if (id_dims == NULL) {
      std::cerr << "Error: Subscripted identifier '" << *(id->name) << "' is not an array."
                << std::endl;
      semant_errors++;
      indices_valid = false;
    } else if (id_dims->size() != indices->size()) {
      std::cerr << "Error: Matrix '" << *(id->name) << "' reference does not match declared dimensions."
                << std::endl;
      semant_errors++;
      indices_valid = false;
    }
  }

  if (indices_valid == true) {
    type = entry->get_datatype();
  } else {
    type = DataType(ERROR_TYPE, 0);
  }

  return type;
}

void NMatrixElemExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Matrix Element Expression" << std::endl;
  id->dump(stream, depth+1);
  
  stream << pad(depth+1) << "Matrix Index Expressions" << std::endl;
  for (ExpressionList::iterator it = indices->begin(); it != indices->end(); it++) {
    (*it)->dump(stream, depth+2);
  }
}

DataType NQueryCharExpr::EvaluateType() {
  type = DataType(INT_CONST, 0);
  return type;
}

void NQueryCharExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Query Char Expression" << std::endl;
}

DataType NRefCharExpr::EvaluateType() {
  type = DataType(INT_CONST, 0);
  return type;
}

void NRefCharExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Ref Char Expression" << std::endl;
}

DataType NRowExpr::EvaluateType() {
  type = DataType(ROW_TYPE, 0);
  return type;
}

void NRowExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Row Expression" << std::endl;
}

DataType NColExpr::EvaluateType() {
  type = DataType(COL_TYPE, 0);
  return type;
}

void NColExpr::dump(std::ostream &stream, int depth) {
  stream << pad(depth) << "Col Expression" << std::endl;
}

