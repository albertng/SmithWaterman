//  File Name        : utils.cpp
//  Description      : Useful utility functions
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision
//      Albert Ng   May 23 2014     Removed condition and report tokens

#include "tree.hpp"
#include "dpal-parse.hpp"
#include "utils.hpp"
#include <string>
#include <cctype>
#include <iomanip>

static const int PADSPACES = 2;

std::string pad(int depth) {
  if (depth <= 0) {
    return "";
  }

  return std::string(depth * PADSPACES, ' ');
}

void print_escaped_string(std::ostream& stream, std::string str) {
  for (int i = 0; i < str.size(); i++) {
    switch(str[i]) {
      case '\\' : stream << "\\\\"; break;
      case '\"' : stream << "\\\""; break;
      case '\n' : stream << "\\n";  break;
      case '\t' : stream << "\\t";  break;
      case '\b' : stream << "\\b";  break;
      case '\f' : stream << "\\f";  break;
      default : if (isprint(str[i])) {
                  stream << str[i];
                } else {
                  stream << '\\' << std::oct << std::setfill('0') << std::setw(3)
                         << (int) ((unsigned char) (str[i]))
                         << std::dec << std::setfill(' ');
                  break;
                }
    }
  }
}
      
void print_token(std::ostream &stream, int token) {
  stream << token_to_string(token);

  switch(token) {
    case TINTCONST :
      stream << " = " << yylval.int_const;
      break;

    case TBOOLCONST :
      stream << " = " << (yylval.bool_const ? "true" : "false");
      break;

    case TIDENTIFIER :
      stream << " = " << *(yylval.id_name);
      break;

    case TERROR :
      stream << " = ";
      print_escaped_string(stream, *(yylval.error_msg));
      break;
  } 
}

std::string token_to_string(int token) {
  switch(token) {
    case 0 :           return("EOF");        break;
    case TALPHABET :   return("ALPHABET");   break;
    case TDPMAT :      return("DPMAT");      break;
    case TCONST :      return("CONST");      break;
    case TUNSIGNED :   return("UNSIGNED");   break;
    case TSIGNED :     return("SIGNED");     break;
    case TBOOL :       return("BOOL");       break;
    case TCELL :       return("CELL");       break;
    case TIF :         return("IF");         break;
    case TELSE :       return("ELSE");       break;
    case TSWITCH :     return("SWITCH");     break;
    case TCASE :       return("CASE");       break;
    case TDEFAULT :    return("DEFAULT");    break;
    case TMAX :        return("MAX");        break;
    case TQUERYCHAR :  return("QUERY_CHAR"); break;
    case TREFCHAR :    return("REF_CHAR");   break;
    case TROW :        return("ROW");        break;
    case TCOL :        return("COL");        break;
    case TINTCONST :   return("INT_CONST");  break;
    case TBOOLCONST :  return("BOOL_CONST"); break;
    case TIDENTIFIER : return("IDENTIFIER"); break;
    case TASSIGN :     return("=");          break;
    case TLBRACKET :   return("[");          break;
    case TRBRACKET :   return("]");          break;
    case TLBRACE :     return("{");          break;
    case TRBRACE :     return("}");          break;
    case TLPAREN :     return("(");          break;
    case TRPAREN :     return(")");          break;
    case TSEMICOLON :  return(";");          break;
    case TCOLON :      return(":");          break;
    case TCOMMA :      return(",");          break;
    case TPLUS :       return("+");          break;
    case TMINUS :      return("-");          break;
    case TCLT :        return("<");          break;
    case TCLE :        return("<=");         break;
    case TCGT :        return(">");          break;
    case TCGE :        return(">=");         break;
    case TCEQ :        return("==");         break;
    case TCNE :        return("!=");         break;
    case TLNOT :       return("!");          break;
    case TLAND :       return("&&");         break;
    case TLOR :        return("||");         break;
    case TLSHIFT :     return("<<");         break;
    case TRSHIFT :     return(">>");         break;
    case TAND :        return("&");          break;
    case TXOR :        return("^");          break;
    case TOR :         return("|");          break;
    case TNOT :        return("~");          break;
    default :          return("<Invalid Token>");
  }
}
