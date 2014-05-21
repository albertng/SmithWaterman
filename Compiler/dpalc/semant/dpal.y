//  File Name        : dpal.y
//  Description      : Bison parser description for DPAL
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant scalar declaration
//      Albert Ng   Apr 23 2014     Constant matrix declaration
//                                  DP Matrix declaration nodes
//                                  Cell Function declaration nodes
//      Albert Ng   Apr 24 2014     Initial implementation completed
//      Albert Ng   May 05 2014     Removed main() for semantic checker, externs
//      Albert Ng   May 15 2014     Variable decls at start of function

%{
#include <iostream>
#include "tree.hpp"
#include "utils.hpp"
#include "datatype.hpp"
#include <string>
#include <cstdlib>

extern int yylex();
void yyerror(char *s);

extern NProgram *root;
extern FILE * yyin;

int num_errors = 0;

extern std::string filename;
%}

%start program

%union {
  NProgram* program;
  NAlphabetDecl* alphabet_decl;
  CharacterDeclList* character_decl_list;
  NCharacterDecl* character_decl;
  ConstDeclList* const_decl_list;
  ConstList* const_list;
  NConstDecl* const_decl; 
  NConstScalarDecl* const_scalar_decl;
  NConstMatrixDecl* const_matrix_decl;
  NConstMatrixElem* const_matrix_elem;
  ConstMatrixElemList* const_matrix_elem_list;
  NConst* constant;
  NType* type;
  std::string* id_name;
  int int_const;
  bool bool_const;
  int token;
  DPMatrixDeclList* dp_matrix_decl_list;
  NDPMatrixDecl* dp_matrix_decl;
  NCellFuncDecl* cell_func_decl;
  NConditionFuncDecl* condition_func_decl;
  ParamList* param_list;
  NParam* param;
  NParamScalar* param_scalar;
  NParamMatrix* param_matrix;
  VariableDeclList* variable_decl_list;
  NVariableDecl* variable_decl;
  StmtList* stmt_list;
  NStmt* stmt;
  NIfStmt* if_stmt;
  NAssignStmt* assign_stmt;
  NSwitchStmt* switch_stmt;
  NCaseStmt* case_stmt;
  CaseStmtList* case_stmt_list;
  NReportStmt* report_stmt;
  ExpressionList* expression_list;
  NExpression* expression;
  std::string* error_msg;
}

%token <token> TALPHABET
%token <token> TDPMAT
%token <token> TCONST
%token <token> TUNSIGNED
%token <token> TSIGNED
%token <token> TBOOL
%token <token> TCELL
%token <token> TCONDITION
%token <token> TIF
%token <token> TELSE
%token <token> TSWITCH
%token <token> TCASE
%token <token> TDEFAULT
%token <token> TREPORT
%token <token> TMAX
%token <token> TQUERYCHAR
%token <token> TREFCHAR
%token <token> TROW
%token <token> TCOL
%token <int_const> TINTCONST
%token <bool_const> TBOOLCONST
%token <id_name> TIDENTIFIER
%token <token> TASSIGN
%token <token> TLBRACKET
%token <token> TRBRACKET
%token <token> TLBRACE
%token <token> TRBRACE
%token <token> TLPAREN
%token <token> TRPAREN
%token <token> TSEMICOLON
%token <token> TCOLON
%token <token> TCOMMA
%token <token> TPLUS
%token <token> TMINUS
%token <token> TCLT
%token <token> TCLE
%token <token> TCGT
%token <token> TCGE
%token <token> TCEQ
%token <token> TCNE
%token <token> TLNOT
%token <token> TLAND
%token <token> TLOR
%token <token> TLSHIFT
%token <token> TRSHIFT
%token <token> TAND
%token <token> TXOR
%token <token> TOR
%token <token> TNOT
%token <token> TERROR

%type <program> program
%type <alphabet_decl> alphabet_decl
%type <character_decl_list> character_decl_list
%type <character_decl> character_decl
%type <const_decl_list> const_decl_list
%type <const_decl> const_decl
%type <const_scalar_decl> const_scalar_decl
%type <type> type
%type <const_matrix_decl> const_matrix_decl
%type <const_list> dimension_list
%type <const_matrix_elem> const_matrix_elem
%type <const_matrix_elem_list> const_matrix_elem_list
%type <const_list> const_list
%type <constant> constant
%type <dp_matrix_decl_list> dp_matrix_decl_list
%type <dp_matrix_decl> dp_matrix_decl
%type <cell_func_decl> cell_func_decl
%type <condition_func_decl> condition_func_decl
%type <param_list> param_list
%type <param> param
%type <param_scalar> param_scalar
%type <param_matrix> param_matrix
%type <variable_decl_list> variable_decl_list
%type <variable_decl> variable_decl
%type <stmt_list> stmt_list
%type <stmt> stmt
%type <if_stmt> if_stmt
%type <assign_stmt> assign_stmt
%type <switch_stmt> switch_stmt
%type <case_stmt_list> case_stmt_list
%type <case_stmt> case_stmt
%type <report_stmt> report_stmt
%type <expression_list> index_list
%type <expression> expression
%type <expression_list> arg_list

%left TCOMMA
%left TLOR
%left TLAND
%left TOR
%left TXOR
%left TAND
%nonassoc TCLT TCLE TCGT TCGE TCEQ TCNE
%left TLSHIFT TRSHIFT
%left TPLUS TMINUS
%right TNOT TLNOT UMINUS

%%

program : alphabet_decl const_decl_list dp_matrix_decl_list cell_func_decl condition_func_decl
          { $$ = new NProgram($1, $2, $3, $4, $5);
            root = $$; }
        ;

alphabet_decl : TALPHABET TASSIGN TLBRACE character_decl_list TRBRACE TSEMICOLON
                { $$ = new NAlphabetDecl($4); }
              ;

character_decl_list : character_decl_list TCOMMA character_decl
                      { $$ = $1;
                        $$->push_back($3); }
                    | character_decl { $$ = new CharacterDeclList(); 
                                       $$->push_back($1); }
                    ;

character_decl : TIDENTIFIER 
                 { $$ = new NCharacterDecl(new NIdentifier($1)); } // Need symbol table here
               | TIDENTIFIER TASSIGN TINTCONST
                 { $$ = new NCharacterDecl(new NIdentifier($1), new NIntConst($3)); }
               | TIDENTIFIER TASSIGN TMINUS TINTCONST
                 { $$ = new NCharacterDecl(new NIdentifier($1), new NIntConst(-$4)); }
               ;

const_decl_list : const_decl_list const_decl
                  { $$ = $1;
                    $$->push_back($2); }
                | { $$ = new ConstDeclList(); }

const_decl : const_scalar_decl { $$ = $1; }
           | const_matrix_decl { $$ = $1; }

const_scalar_decl : TCONST type TIDENTIFIER TASSIGN constant TSEMICOLON
                    { $$ = new NConstScalarDecl(new NIdentifier($3), $2, $5); }
                  | TCONST type TIDENTIFIER TASSIGN TIDENTIFIER TSEMICOLON
                    { $$ = new NConstScalarDecl(new NIdentifier($3), $2, new NIdConst(new NIdentifier($5))); }

type : TUNSIGNED TCLT TINTCONST TCGT
       { $$ = new NType(UNSIGNED, new NIntConst($3)); }
     | TUNSIGNED TCLT TIDENTIFIER TCGT
       { $$ = new NType(UNSIGNED, new NIdConst(new NIdentifier($3))); } 
     | TUNSIGNED
       { $$ = new NType(UNSIGNED, new NIntConst(32)); }
     | TSIGNED TCLT TINTCONST TCGT
       { $$ = new NType(SIGNED, new NIntConst($3)); }
     | TSIGNED TCLT TIDENTIFIER TCGT
       { $$ = new NType(SIGNED, new NIdConst(new NIdentifier($3))); } 
     | TSIGNED
       { $$ = new NType(SIGNED, new NIntConst(32)); }
     | TBOOL
       { $$ = new NType(BOOL, new NIntConst(1)); }

constant : TBOOLCONST { $$ = new NBoolConst($1); }
         | TINTCONST { $$ = new NIntConst($1); }
         | TMINUS TINTCONST { $$ = new NIntConst(-$2); }

const_matrix_decl : TCONST type TIDENTIFIER dimension_list TASSIGN const_matrix_elem TSEMICOLON
                    { $$ = new NConstMatrixDecl(new NIdentifier($3), $2, $4, $6); }

dimension_list : dimension_list TLBRACKET TINTCONST TRBRACKET
                 { $$ = $1;
                   $$->push_back(new NIntConst($3)); }
               | dimension_list TLBRACKET TIDENTIFIER TRBRACKET
                 { $$ = $1;
                   $$->push_back(new NIdConst(new NIdentifier($3))); }
               | TLBRACKET TINTCONST TRBRACKET
                 { $$ = new ConstList();
                   $$->push_back(new NIntConst($2)); }
               | TLBRACKET TIDENTIFIER TRBRACKET
                 { $$ = new ConstList();
                   $$->push_back(new NIdConst(new NIdentifier($2))); }

const_matrix_elem : TLBRACE const_matrix_elem_list TRBRACE
                    { $$ = new NConstMatrixElem($2); }
                  | TLBRACE const_list TRBRACE
                    { $$ = new NConstMatrixElem($2); }

const_matrix_elem_list : const_matrix_elem_list TCOMMA const_matrix_elem
                         { $$ = $1;
                           $$->push_back($3); }
                       | const_matrix_elem
                         { $$ = new ConstMatrixElemList(); 
                           $$->push_back($1); }

const_list : const_list TCOMMA constant 
             { $$ = $1;
               $$->push_back($3); }
           | const_list TCOMMA TIDENTIFIER
             { $$ = $1;
               $$->push_back(new NIdConst(new NIdentifier($3))); }
           | constant
             { $$ = new ConstList(); 
               $$->push_back($1); }
           | TIDENTIFIER
             { $$ = new ConstList();
               $$->push_back(new NIdConst(new NIdentifier($1))); }

dp_matrix_decl_list : dp_matrix_decl_list dp_matrix_decl
                      { $$ = $1;
                        $$->push_back($2); }
                    | dp_matrix_decl
                      { $$ = new DPMatrixDeclList();
                        $$->push_back($1); }

dp_matrix_decl : TDPMAT type TIDENTIFIER TLBRACKET TRBRACKET TLBRACKET TRBRACKET TSEMICOLON
                 { $$ = new NDPMatrixDecl(new NIdentifier($3), $2); } 

cell_func_decl : TCELL TLPAREN param_list TRPAREN TLBRACE variable_decl_list stmt_list TRBRACE
                 { $$ = new NCellFuncDecl($3, $6, $7); }

condition_func_decl : TCONDITION TLPAREN param_list TRPAREN TLBRACE variable_decl_list stmt_list TRBRACE
                      { $$ = new NConditionFuncDecl($3, $6, $7); }

param_list : param_list TCOMMA param
             { $$ = $1;
               $$->push_back($3); }
           | param
             { $$ = new ParamList();
               $$->push_back($1); }
           | { $$ = new ParamList(); }

param : param_scalar { $$ = $1; }
      | param_matrix { $$ = $1; }

param_scalar : type TIDENTIFIER
               { $$ = new NParamScalar(new NIdentifier($2), $1); }

param_matrix : type TIDENTIFIER dimension_list
               { $$ = new NParamMatrix(new NIdentifier($2), $1, $3); }

variable_decl_list : variable_decl_list variable_decl
                     { $$ = $1;
                       $$->push_back($2); }
                   | { $$ = new VariableDeclList(); }

variable_decl : type TIDENTIFIER TSEMICOLON
                { $$ = new NVariableDecl($1, new NIdentifier($2)); }
              | type TIDENTIFIER TASSIGN expression TSEMICOLON
                { $$ = new NVariableDecl($1, new NIdentifier($2), $4); }

stmt_list : stmt_list stmt
            { $$ = $1;
              $$->push_back($2); }
          | { $$ = new StmtList(); }

stmt : if_stmt       { $$ = $1; }
     | assign_stmt   { $$ = $1; }
     | switch_stmt   { $$ = $1; }
     | report_stmt   { $$ = $1; }

if_stmt : TIF TLPAREN expression TRPAREN TLBRACE stmt_list TRBRACE
          { $$ = new NIfStmt($3, $6); }
        | TIF TLPAREN expression TRPAREN TLBRACE stmt_list TRBRACE TELSE TLBRACE stmt_list TRBRACE
          { $$ = new NIfStmt($3, $6, $10); }
        | TIF TLPAREN expression TRPAREN TLBRACE stmt_list TRBRACE TELSE if_stmt
          { $$ = new NIfStmt($3, $6, new StmtList()); 
            $$->else_body->push_back($9); }

assign_stmt : TIDENTIFIER TASSIGN expression TSEMICOLON
              { $$ = new NAssignStmt(new NIdentifier($1), $3); }
            | TIDENTIFIER index_list TASSIGN expression TSEMICOLON
              { $$ = new NAssignStmt(new NIdentifier($1), $2, $4); }

index_list : index_list TLBRACKET expression TRBRACKET
             { $$ = $1;
               $$->push_back($3); }
           | TLBRACKET expression TRBRACKET
             { $$ = new ExpressionList();
               $$->push_back($2); }

switch_stmt : TSWITCH TLPAREN expression TRPAREN TLBRACE case_stmt_list TRBRACE
              { $$ = new NSwitchStmt($3, $6); }

case_stmt_list : case_stmt_list case_stmt
                 { $$ = $1;
                   $$->push_back($2); }
               | { $$ = new CaseStmtList(); }

case_stmt : TCASE constant TCOLON stmt_list
            { $$ = new NCaseStmt($2, $4); }
          | TCASE TIDENTIFIER TCOLON stmt_list
            { $$ = new NCaseStmt(new NIdConst(new NIdentifier($2)), $4); }
          | TDEFAULT TCOLON stmt_list
            { $$ = new NCaseStmt($3); }

report_stmt : TREPORT TLPAREN TRPAREN TSEMICOLON
            { $$ = new NReportStmt(); }

expression : TMAX TLPAREN arg_list TRPAREN { $$ = new NMaxExpr($3); }
           | TLPAREN expression TRPAREN { $$ = $2; }
           | TMINUS TLPAREN expression TRPAREN { $$ = new NNegExpr($3); }
           | expression TPLUS expression { $$ = new NPlusExpr($1, $3); }
           | expression TMINUS expression { $$ = new NMinusExpr($1, $3); }
           | expression TCLT expression { $$ = new NCLTExpr($1, $3); }
           | expression TCLE expression { $$ = new NCLEExpr($1, $3); }
           | expression TCGT expression { $$ = new NCGTExpr($1, $3); }
           | expression TCGE expression { $$ = new NCGEExpr($1, $3); }
           | expression TCEQ expression { $$ = new NCEQExpr($1, $3); }
           | expression TCNE expression { $$ = new NCNEExpr($1, $3); }
           | TLNOT expression { $$ = new NLNOTExpr($2); }
           | expression TLAND expression { $$ = new NLANDExpr($1, $3); }
           | expression TLOR expression { $$ = new NLORExpr($1, $3); }
           | expression TLSHIFT expression { $$ = new NLShiftExpr($1, $3); }
           | expression TRSHIFT expression { $$ = new NRShiftExpr($1, $3); }
           | expression TAND expression { $$ = new NANDExpr($1, $3); }
           | expression TXOR expression { $$ = new NXORExpr($1, $3); }
           | expression TOR expression { $$ = new NORExpr($1, $3); }
           | TNOT expression { $$ = new NNotExpr($2); }
           | constant { $$ = $1; }
           | TIDENTIFIER { $$ = new NIdentifier($1); }
           | TMINUS TIDENTIFIER { $$ = new NNegExpr(new NIdentifier($2)); }
           | TIDENTIFIER index_list { $$ = new NMatrixElemExpr(new NIdentifier($1), $2); }
           | TQUERYCHAR { $$ = new NQueryCharExpr(); }
           | TREFCHAR { $$ = new NRefCharExpr(); }
           | TROW { $$ = new NRowExpr(); }
           | TCOL { $$ = new NColExpr(); }

arg_list : arg_list TCOMMA expression
           { $$ = $1;
             $$->push_back($3); }
         | expression
           { $$ = new ExpressionList();
             $$->push_back($1); }


%%

/* User Code */

// This function is automatically called when Bison detects a parse error.
void yyerror (char *s) {
  extern int line_num;

  std::cerr << "\"" << filename << "\", line " << line_num << ": " << s
            << " at or near '";
  print_token(std::cerr, yychar);
  std::cerr << "'" << std::endl;
  
  num_errors++;
  if (num_errors > 50) {
    std::cerr << "More than 50 errors" << std::endl;
    exit(1);
  } 
}
