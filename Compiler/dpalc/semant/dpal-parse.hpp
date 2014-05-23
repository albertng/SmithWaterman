/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TALPHABET = 258,
     TDPMAT = 259,
     TCONST = 260,
     TUNSIGNED = 261,
     TSIGNED = 262,
     TBOOL = 263,
     TCELL = 264,
     TIF = 265,
     TELSE = 266,
     TSWITCH = 267,
     TCASE = 268,
     TDEFAULT = 269,
     TMAX = 270,
     TQUERYCHAR = 271,
     TREFCHAR = 272,
     TROW = 273,
     TCOL = 274,
     TINTCONST = 275,
     TBOOLCONST = 276,
     TIDENTIFIER = 277,
     TASSIGN = 278,
     TLBRACKET = 279,
     TRBRACKET = 280,
     TLBRACE = 281,
     TRBRACE = 282,
     TLPAREN = 283,
     TRPAREN = 284,
     TSEMICOLON = 285,
     TCOLON = 286,
     TCOMMA = 287,
     TPLUS = 288,
     TMINUS = 289,
     TCLT = 290,
     TCLE = 291,
     TCGT = 292,
     TCGE = 293,
     TCEQ = 294,
     TCNE = 295,
     TLNOT = 296,
     TLAND = 297,
     TLOR = 298,
     TLSHIFT = 299,
     TRSHIFT = 300,
     TAND = 301,
     TXOR = 302,
     TOR = 303,
     TNOT = 304,
     TERROR = 305,
     UMINUS = 306
   };
#endif
/* Tokens.  */
#define TALPHABET 258
#define TDPMAT 259
#define TCONST 260
#define TUNSIGNED 261
#define TSIGNED 262
#define TBOOL 263
#define TCELL 264
#define TIF 265
#define TELSE 266
#define TSWITCH 267
#define TCASE 268
#define TDEFAULT 269
#define TMAX 270
#define TQUERYCHAR 271
#define TREFCHAR 272
#define TROW 273
#define TCOL 274
#define TINTCONST 275
#define TBOOLCONST 276
#define TIDENTIFIER 277
#define TASSIGN 278
#define TLBRACKET 279
#define TRBRACKET 280
#define TLBRACE 281
#define TRBRACE 282
#define TLPAREN 283
#define TRPAREN 284
#define TSEMICOLON 285
#define TCOLON 286
#define TCOMMA 287
#define TPLUS 288
#define TMINUS 289
#define TCLT 290
#define TCLE 291
#define TCGT 292
#define TCGE 293
#define TCEQ 294
#define TCNE 295
#define TLNOT 296
#define TLAND 297
#define TLOR 298
#define TLSHIFT 299
#define TRSHIFT 300
#define TAND 301
#define TXOR 302
#define TOR 303
#define TNOT 304
#define TERROR 305
#define UMINUS 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "dpal.y"
{
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
  VariableDeclList* variable_decl_list;
  NVariableDecl* variable_decl;
  StmtList* stmt_list;
  NStmt* stmt;
  NIfStmt* if_stmt;
  NAssignStmt* assign_stmt;
  NSwitchStmt* switch_stmt;
  NCaseStmt* case_stmt;
  CaseStmtList* case_stmt_list;
  ExpressionList* expression_list;
  NExpression* expression;
  std::string* error_msg;
}
/* Line 1529 of yacc.c.  */
#line 190 "dpal-parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

