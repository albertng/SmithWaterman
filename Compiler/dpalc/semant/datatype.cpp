//  File Name        : datatype.cpp
//  Description      : Data type class
//
//  Revision History :
//      Albert Ng   May 13 2014     Initial Revision

#include "datatype.hpp"

DataType DataType::Match(DataType dt1, DataType dt2) {
  switch(dt1.type_name) {
    case UNSIGNED:
      switch(dt2.type_name) {
        case UNSIGNED   : if (dt1.bitwidth == dt2.bitwidth) {
                            return dt1;
                          } else {
                            return DataType(ERROR_TYPE, 0);
                          }
        case SIGNED     : return DataType(ERROR_TYPE, 0);
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt1;
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case SIGNED:
      switch(dt2.type_name) {
        case UNSIGNED   : return DataType(ERROR_TYPE, 0);
        case SIGNED     : if (dt1.bitwidth == dt2.bitwidth) {
                            return dt1;
                          } else {
                            return DataType(ERROR_TYPE, 0);
                          }
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt1;
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case BOOL:
      switch(dt2.type_name) {
        case UNSIGNED   : return DataType(ERROR_TYPE, 0);
        case SIGNED     : return DataType(ERROR_TYPE, 0);
        case BOOL       : return dt1;
        case INT_CONST  : return DataType(ERROR_TYPE, 0);
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case INT_CONST:
      switch(dt2.type_name) {
        case UNSIGNED   : return dt2;
        case SIGNED     : return dt2;
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt2;
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case ERROR_TYPE:
      return DataType(ERROR_TYPE, 0);
    default:
      return DataType(ERROR_TYPE, 0);
  }
};

