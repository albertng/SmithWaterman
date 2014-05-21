//  File Name        : datatype.hpp
//  Description      : Data type class
//
//  Revision History :
//      Albert Ng   May 13 2014     Initial Revision
//      Albert Ng   May 21 2014     ROW and COL types

#ifndef DATATYPE_H_
#define DATATYPE_H_

enum DataTypeName {UNSIGNED, 
                   SIGNED,
                   BOOL, 
                   INT_CONST,     // Numeric constants have no intrinsic signedness and bitwidth
                   ROW_TYPE,
                   COL_TYPE,
                   ERROR_TYPE};

class DataType {
  public:
    DataTypeName type_name;
    int bitwidth;
    DataType() {}
    DataType(DataTypeName type_name, int bitwidth) : type_name(type_name), bitwidth(bitwidth) {}

    static DataType Match(DataType dt1, DataType dt2); 
};

#endif // DATATYPE_H_
