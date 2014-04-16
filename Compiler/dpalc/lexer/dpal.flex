%option noyywrap

%{
#include <iostream>
%}

%{
int line_num = 1;
%}

ALPHABET   (?i:alphabet)
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
{ALPHABET}  { std::cout << "alphabet" << std::endl; }
{CONST}     { std::cout << "const" << std::endl; }
{TRUE}      { std::cout << "true" << std::endl; }
{FALSE}     { std::cout << "false" << std::endl; }
{UNSIGNED}  { std::cout << "unsigned" << std::endl; }
{SIGNED}    { std::cout << "signed" << std::endl; }
{BOOL}      { std::cout << "bool" << std::endl; }
{CELL}      { std::cout << "cell" << std::endl; }
{CONDITION} { std::cout << "condition" << std::endl; }
{IF}        { std::cout << "if" << std::endl; }
{ELSE}      { std::cout << "else" << std::endl; }
{SWITCH}    { std::cout << "switch" << std::endl; }
{CASE}      { std::cout << "case" << std::endl; }
{REPORT}    { std::cout << "report" << std::endl; }
{MAX}       { std::cout << "max" << std::endl; }
{QUERYCHAR} { std::cout << "query_char" << std::endl; }
{REFCHAR}   { std::cout << "ref_char" << std::endl; }
{ROW}       { std::cout << "row" << std::endl; }
{COL}       { std::cout << "col" << std::endl; }
{DIGIT}+    { std::cout << "int_const " << yytext << std::endl; }
{ID}        { std::cout << "id " << yytext << std::endl; }
"="         { std::cout << "assign" << std::endl; }
"["         { std::cout << "left bracket" << std::endl; }
"]"         { std::cout << "right bracket" << std::endl; }
"{"         { std::cout << "left brace" << std::endl; }
"}"         { std::cout << "right brace" << std::endl; }
"("         { std::cout << "left parenthesis" << std::endl; }
")"         { std::cout << "right parenthesis" << std::endl; }
";"         { std::cout << "semicolon" << std::endl; }
":"         { std::cout << "colon" << std::endl; }
","         { std::cout << "comma" << std::endl; }
"+"         { std::cout << "plus" << std::endl; }
"-"         { std::cout << "minus" << std::endl; }
"<"         { std::cout << "less than" << std::endl; }
"<="        { std::cout << "less than or equal" << std::endl; }
">"         { std::cout << "greater than" << std::endl; }
">="        { std::cout << "greater than or equal" << std::endl; }
"=="        { std::cout << "equals" << std::endl; }
"!="        { std::cout << "not equals" << std::endl; }
"!"         { std::cout << "not" << std::endl; }
"&&"        { std::cout << "and" << std::endl; }
"||"        { std::cout << "or" << std::endl; }
"<<"        { std::cout << "left shift" << std::endl; }
">>"        { std::cout << "right shift" << std::endl; }
"&"         { std::cout << "logical and" << std::endl; }
"^"         { std::cout << "logical xor" << std::endl; }
"|"         { std::cout << "logical or" << std::endl; }
"~"         { std::cout << "logical not" << std::endl; }
"\n"        { line_num++; }


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

.           { std::cout << "Error in line " << line_num << std::endl; }

%%

/* User Code */
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./lexer <DPAL FILE>" << std::endl;
    return 1;
  }

  yyin = fopen(argv[1], "r");

  yylex();
}
