//  File Name        : symtab.hpp
//  Description      : Symbol table functions
//
//  Revision History :
//      Albert Ng   Apr 27 2014     Initial Revision
//      Albert Ng   May 13 2014     Include datatype.hpp

#ifndef SYMTAB_H_
#define SYMTAB_H_

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "datatype.hpp"

enum SymbolType {CHARACTER, CONST_SCALAR, CONST_MAT, DP_MAT, PARAM_SCALAR, PARAM_MAT, VAR_SCALAR, VAR_MAT};

class SymbolTableEntry {
  public:
    SymbolTableEntry(std::string name, SymbolType symboltype, DataType datatype, std::vector<int>* dimensions) : 
                            name_(name), symboltype_(symboltype), datatype_(datatype), dimensions_(dimensions) {}
    SymbolTableEntry(std::string name, SymbolType symboltype, DataType datatype) : 
                            name_(name), symboltype_(symboltype), datatype_(datatype), dimensions_(NULL) {}
    std::string get_name() { return name_; }
    SymbolType get_symboltype() { return symboltype_; }
    DataType get_datatype() { return datatype_; }
    std::vector<int>* get_dimensions() { return dimensions_; }
    void dump(std::ostream& stream, int depth);
  private:
    std::string name_;
    SymbolType symboltype_;
    DataType datatype_;
    std::vector<int>* dimensions_;
};

class SymbolTable {
  public:
    SymbolTable() {}

    // Add a new symbol to the symbol table if a symbol with that name doesn't already exit
    //   Returns true if successful
    bool AddEntry(SymbolTableEntry* entry);

    // Retrieve a symbol's data given its name
    SymbolTableEntry* GetEntry(std::string name);

    // Get the list of symbol names in the symbol table
    std::list<std::string> GetSymbolNames();


    void dump(std::ostream& stream, int depth);
  private:
    std::list<SymbolTableEntry*> table_;
};

#endif // SYMTAB_H_
