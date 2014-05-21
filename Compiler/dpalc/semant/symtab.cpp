//  File Name        : symtab.cpp
//  Description      : Symbol table functions
//
//  Revision History :
//      Albert Ng   May 05 2014     Initial Revision
//      Albert Ng   May 13 2014     Added symbol table global instances
//                                  Include datatype.hpp
//      Albert Ng   May 21 2014     GetSymbolNamesWithType()

#include "symtab.hpp"
#include "utils.hpp"
#include "datatype.hpp"
#include <string>
#include <list>
#include <vector>
#include <iostream>

void SymbolTableEntry::dump(std::ostream& stream, int depth) {
  stream << pad(depth) << name_ << "\t";

  switch(symboltype_) {
    case CHARACTER    : stream << "CHARACTER\t";           break;
    case CONST_SCALAR : stream << "CONST SCALAR\t";        break;
    case CONST_MAT    : stream << "CONST MAT\t";           break;
    case DP_MAT       : stream << "DP MAT\t";              break;
    case PARAM_SCALAR : stream << "PARAM SCALAR\t";        break;
    case PARAM_MAT    : stream << "PARAM MAT\t";           break;
    case VAR          : stream << "VAR\t";             break;
    default           : stream << "UNKNOWN SYMBOL TYPE\t"; break;
  }

  switch(datatype_.type_name) {
    case UNSIGNED   : stream << "UNSIGNED\t" << datatype_.bitwidth << "\t"; break; 
    case SIGNED     : stream << "SIGNED\t"   << datatype_.bitwidth << "\t"; break;
    case BOOL       : stream << "BOOL\t";             break;
    case INT_CONST  : stream << "INT_CONST\t";        break;
    case ERROR_TYPE : stream << "ERROR TYPE\t";       break;
    default         : stream << "UKNOWN DATA TYPE\t"; break;
  }

  if (dimensions_ != NULL) {
    for (std::vector<int>::iterator it = dimensions_->begin(); it != dimensions_->end(); it++) {
      stream << *it << " ";
    }
  }
  stream << std::endl;
}

bool SymbolTable::AddEntry(SymbolTableEntry* entry) {
  // Check for existing symbol with the same name
  for (std::list<SymbolTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    if ((*it)->get_name() == entry->get_name()) {
      return false;
    }
  }

  table_.push_back(entry);
  return true;
}

SymbolTableEntry* SymbolTable::GetEntry(std::string name) {
  for (std::list<SymbolTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    if ((*it)->get_name() == name) {
      return *it;
    }
  }

  return NULL;
}

std::list<std::string> SymbolTable::GetSymbolNamesWithType(SymbolType stype) {
  std::list<std::string> symbol_names;
  for (std::list<SymbolTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    if ((*it)->get_symboltype() == stype) {
      symbol_names.push_back((*it)->get_name());
    }
  }
  return symbol_names;
}

void SymbolTable::dump(std::ostream& stream, int depth) {
  stream << pad(depth) << "Symbol Table" << std::endl;
  for (std::list<SymbolTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    (*it)->dump(stream, depth+1);
  }
}

SymbolTable global_symbol_table;
SymbolTable cell_symbol_table;
SymbolTable condition_symbol_table;
