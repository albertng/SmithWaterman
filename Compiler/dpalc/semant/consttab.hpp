//  File Name        : consttab.hpp
//  Description      : Constant table class
//
//  Revision History :
//      Albert Ng   May 13 2014     Initial Revision

#ifndef CONSTTAB_H_
#define CONSTTAB_H_

#include <iostream>
#include <vector>
#include <list>

enum ConstDataType { INT_DATA, BOOL_DATA, INT_MATRIX_DATA, BOOL_MATRIX_DATA };

union ConstData {
  int int_data;
  bool bool_data;
  std::vector<ConstData>* matrix_data;
};

class ConstTableEntry {
  public:
    ConstTableEntry(std::string name, ConstDataType datatype, ConstData data) :
                  name_(name), datatype_(datatype), data_(data), dimensions_(NULL) {} 
    ConstTableEntry(std::string name, ConstDataType datatype, ConstData data, std::vector<int>* dimensions) :
                  name_(name), datatype_(datatype), data_(data), dimensions_(dimensions) {}
    std::string       get_name()     { return name_; }
    ConstDataType     get_datatype() { return datatype_; }
    ConstData         get_data()     { return data_; }
    std::vector<int>* get_dimensions() { return dimensions_; }
    
    void dump(std::ostream& stream, int depth);

  private:
    std::string name_;
    ConstDataType datatype_;
    ConstData data_;
    std::vector<int>* dimensions_;
};

class ConstTable {
  public:
    ConstTable() {}

    bool AddEntry(ConstTableEntry* entry);

    ConstTableEntry* GetEntry(std::string name);

    void dump(std::ostream& stream, int depth);

  private:
    std::list<ConstTableEntry*> table_;  
};

#endif // CONSTTAB_H_
