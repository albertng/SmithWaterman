//  File Name        : dpal.y
//  Description      : Bison parser description for DPAL
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision

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
  NCharacterDecl* character_decl;
  CharacterDeclList* character_decl_list;
  NIdentifier *id;
  std::string* str_const;
  int int_const;
  int token;
}

%token <token> TALPHABET
%token <token> TCONST
%token <token> TTRUE 
%token <token> TFALSE
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
%token <str_const> TIDENTIFIER
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
%type <character_decl> character_decl
%type <character_decl_list> character_decl_list

%%

program : alphabet_decl 
          { $$ = new NProgram($1);
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

%%

/* User Code */
int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./parser <DPAL FILE>" << std::endl;
    return 1;
  }

  yyin = fopen(argv[1], "r");

  yyparse();
  root->dump(std::cout, 0);
}

// This function is automatically called when Bison detects a parse error.
void yyerror (char *s) {
  extern int line_num;

  std::cerr << "Line " << line_num << ": " << s << std::endl;
}
