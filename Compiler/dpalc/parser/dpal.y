//  File Name        : dpal.y
//  Description      : Bison parser description for DPAL
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision
//      Albert Ng   Apr 20 2014     Constant scalar declaration
//      Albert Ng   Apr 23 2014     Constant matrix declaration
//                                  DP Matrix declaration nodes
//                                  Cell Function declaration nodes

%{
#include <iostream>
#include "tree.hpp"
extern int yylex();
void yyerror(char *s);

NProgram *root;
extern FILE * yyin;
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
  ParamList* param_list;
  NParam* param;
  NParamScalar* param_scalar;
  NParamMatrix* param_matrix;
  StmtList* stmt_list;
  NStmt* stmt;
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
%token <token> TNEG

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
%type <param_list> param_list
%type <param> param
%type <param_scalar> param_scalar
%type <param_matrix> param_matrix
%type <stmt_list> stmt_list
%type <stmt> stmt

%%

program : alphabet_decl const_decl_list dp_matrix_decl_list cell_func_decl
          { $$ = new NProgram($1, $2, $3, $4);
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
               ;

const_decl_list : const_decl_list const_decl
                  { $$ = $1;
                    $$->push_back($2); }
                | { $$ = new ConstDeclList(); }

const_decl : const_scalar_decl { $$ = $1; }
           | const_matrix_decl { $$ = $1; }

const_scalar_decl : TCONST type TIDENTIFIER TASSIGN constant TSEMICOLON
                    { $$ = new NConstScalarDecl(new NIdentifier($3), $2, $5); }

type : TUNSIGNED TCLT constant TCGT
       { $$ = new NType(UNSIGNED, $3); }
     | TUNSIGNED
       { $$ = new NType(UNSIGNED, new NIntConst(32)); }
     | TSIGNED TCLT constant TCGT
       { $$ = new NType(SIGNED, $3); }
     | TSIGNED
       { $$ = new NType(SIGNED, new NIntConst(32)); }
     | TBOOL
       { $$ = new NType(BOOL, new NIntConst(1)); }

constant : TBOOLCONST { $$ = new NBoolConst($1); }
         | TINTCONST { $$ = new NIntConst($1); }
         | TIDENTIFIER { $$ = new NIdConst(new NIdentifier($1)); }

const_matrix_decl : TCONST type TIDENTIFIER dimension_list TASSIGN const_matrix_elem TSEMICOLON
                    { $$ = new NConstMatrixDecl(new NIdentifier($3), $2, $4, $6); }

dimension_list : dimension_list TLBRACKET constant TRBRACKET
                 { $$ = $1;
                   $$->push_back($3); }
               | TLBRACKET constant TRBRACKET
                 { $$ = new ConstList();
                   $$->push_back($2); }

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
           | constant
             { $$ = new ConstList(); 
               $$->push_back($1); }

dp_matrix_decl_list : dp_matrix_decl_list dp_matrix_decl
                      { $$ = $1;
                        $$->push_back($2); }
                    | dp_matrix_decl
                      { $$ = new DPMatrixDeclList();
                        $$->push_back($1); }

dp_matrix_decl : TDPMAT type TIDENTIFIER TLBRACKET TRBRACKET TLBRACKET TRBRACKET TSEMICOLON
                 { $$ = new NDPMatrixDecl(new NIdentifier($3), $2); } 

cell_func_decl : TCELL TLPAREN param_list TRPAREN TLBRACE stmt_list TRBRACE
                 { $$ = new NCellFuncDecl($3, $6); }

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

stmt_list : stmt_list stmt
            { $$ = $1;
              $$->push_back($2); }
          | stmt
            { $$ = new StmtList();
              $$->push_back($1); }

stmt : TIDENTIFIER { $$ = new NStmt(); }


%%

/* User Code */
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./parser <DPAL FILE>" << std::endl;
    return 1;
  }

  yyin = fopen(argv[1], "r");

  root = NULL;
  yyparse();
  if (root) {
    root->dump(std::cout, 0);
  }
}

// This function is automatically called when Bison detects a parse error.
void yyerror (char *s) {
  extern int line_num;

  std::cerr << "Line " << line_num << ": " << s << std::endl;
}
