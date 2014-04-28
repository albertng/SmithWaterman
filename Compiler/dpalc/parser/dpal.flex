/*  File Name        : dpal.flex
 *  Description      : Flex lexer description for DPAL
 *
 *  Revision History :
 *      Albert Ng   Apr 15 2014     Initial Revision
 *      Albert Ng   Apr 16 2014     Added comment capability
 *      Albert Ng   Apr 23 2014     Added dpmat token
 *      Albert Ng   Apr 24 2014     Added default token
 */

%option noyywrap

%{
#include <iostream>
#include "tree.hpp"
#include "dpal-parse.hpp"

extern FILE * yyin;
%}

%{
int line_num = 1;
%}

ALPHABET   (?i:alphabet)
DPMAT      (?i:dpmat)
CONST      (?i:const)
TRUE       (?i:true)
FALSE      (?i:false)
UNSIGNED   (?i:unsigned)
SIGNED     (?i:signed)
BOOL       (?i:bool)
CELL       (?i:cell)
CONDITION  (?i:condition)
IF         (?i:if)
ELSE       (?i:else)
SWITCH     (?i:switch)
CASE       (?i:case)
DEFAULT    (?i:default)
REPORT     (?i:report)
MAX        (?i:max)
QUERYCHAR  (?i:query_char)
REFCHAR    (?i:ref_char)
ROW        (?i:row)
COL        (?i:col)
DIGIT      [0-9]
ID         [a-zA-Z][a-zA-Z0-9_]*
WHITESPACE [ \t\b\f\r\v]+

%x COMMENT
%x COMMENT_LINE
%%

%{
%}
{ALPHABET}   { return TALPHABET; }
{DPMAT}      { return TDPMAT; }
{CONST}      { return TCONST; }
{UNSIGNED}   { return TUNSIGNED; }
{SIGNED}     { return TSIGNED; }
{BOOL}       { return TBOOL; }
{CELL}       { return TCELL; }
{CONDITION}  { return TCONDITION; }
{IF}         { return TIF; }
{ELSE}       { return TELSE; }
{SWITCH}     { return TSWITCH; }
{CASE}       { return TCASE; }
{DEFAULT}    { return TDEFAULT; }
{REPORT}     { return TREPORT; }
{MAX}        { return TMAX; }
{QUERYCHAR}  { return TQUERYCHAR; }
{REFCHAR}    { return TREFCHAR; }
{ROW}        { return TROW; }
{COL}        { return TCOL; }
{DIGIT}+     { yylval.int_const = atoi(yytext);
               return TINTCONST; }
{TRUE}       { yylval.bool_const = true;
               return TBOOLCONST; }
{FALSE}      { yylval.bool_const = false;
               return TBOOLCONST; }
{ID}         { yylval.id_name = new std::string(yytext, yyleng);
               return TIDENTIFIER; }
"="          { return TASSIGN; }
"["          { return TLBRACKET; }
"]"          { return TRBRACKET; }
"{"          { return TLBRACE; }
"}"          { return TRBRACE; }
"("          { return TLPAREN; }
")"          { return TRPAREN; }
";"          { return TSEMICOLON; }
":"          { return TCOLON; }
","          { return TCOMMA; }
"+"          { return TPLUS; }
"-"          { return TMINUS; }
"<"          { return TCLT; }
"<="         { return TCLE; }
">"          { return TCGT; }
">="         { return TCGE; }
"=="         { return TCEQ; }
"!="         { return TCNE; }
"!"          { return TLNOT; }
"&&"         { return TLAND; }
"||"         { return TLOR; }
"<<"         { return TLSHIFT; }
">>"         { return TRSHIFT; }
"&"          { return TAND; }
"^"          { return TXOR; }
"|"          { return TOR; }
"~"          { return TNOT; }
"\n"         { line_num++; }


{WHITESPACE} {}

"/*"                { BEGIN(COMMENT); }
<COMMENT>"\n"       { line_num++; }
<COMMENT>.          {}
<COMMENT>"*/"       { BEGIN(INITIAL); }
"//"                { BEGIN(COMMENT_LINE); }
<COMMENT_LINE>[^\n] {}
<COMMENT_LINE>"\n"  { line_num++;
                      BEGIN(INITIAL);
                    }

. { yylval.error_msg = new std::string(yytext, yyleng);
    return TERROR;
  }

%%

/* User Code */
/*int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./lexer <DPAL FILE>" << std::endl;
    return 1;
  }

  yyin = fopen(argv[1], "r");

  yylex();
}*/
