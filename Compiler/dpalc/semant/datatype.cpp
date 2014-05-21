//  File Name        : datatype.cpp
//  Description      : Data type class
//
//  Revision History :
//      Albert Ng   May 13 2014     Initial Revision
//      Albert Ng   May 21 2014     ROW and COL types

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
        case ROW_TYPE   : return dt2;
        case COL_TYPE   : return dt2;
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
        case ROW_TYPE   : return dt2;
        case COL_TYPE   : return dt2;
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case BOOL:
      switch(dt2.type_name) {
        case UNSIGNED   : return DataType(ERROR_TYPE, 0);
        case SIGNED     : return DataType(ERROR_TYPE, 0);
        case BOOL       : return dt1;
        case INT_CONST  : return DataType(ERROR_TYPE, 0);
        case ROW_TYPE   : return DataType(ERROR_TYPE, 0);
        case COL_TYPE   : return DataType(ERROR_TYPE, 0);
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case INT_CONST:
      switch(dt2.type_name) {
        case UNSIGNED   : return dt2;
        case SIGNED     : return dt2;
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt2;
        case ROW_TYPE   : return dt2;
        case COL_TYPE   : return dt2;
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case ROW_TYPE:
      switch(dt2.type_name) {
        case UNSIGNED   : return dt1;
        case SIGNED     : return dt1;
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt1;
        case ROW_TYPE   : return DataType(ERROR_TYPE, 0); // Shouldn't ever have a case where we need to match two ROW types
        case COL_TYPE   : return DataType(ERROR_TYPE, 0);
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case COL_TYPE:
      switch(dt2.type_name) {
        case UNSIGNED   : return dt1;
        case SIGNED     : return dt1;
        case BOOL       : return DataType(ERROR_TYPE, 0);
        case INT_CONST  : return dt1;
        case ROW_TYPE   : return DataType(ERROR_TYPE, 0);
        case COL_TYPE   : return DataType(ERROR_TYPE, 0); // Shouldn't ever have a case where we need to match two COL types
        case ERROR_TYPE : return DataType(ERROR_TYPE, 0);
        default         : return DataType(ERROR_TYPE, 0);
      }
    case ERROR_TYPE:
      return DataType(ERROR_TYPE, 0);
    default:
      return DataType(ERROR_TYPE, 0);
  }
};

