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
     TCONDITION = 265,
     TIF = 266,
     TELSE = 267,
     TSWITCH = 268,
     TCASE = 269,
     TDEFAULT = 270,
     TREPORT = 271,
     TMAX = 272,
     TQUERYCHAR = 273,
     TREFCHAR = 274,
     TROW = 275,
     TCOL = 276,
     TINTCONST = 277,
     TBOOLCONST = 278,
     TIDENTIFIER = 279,
     TASSIGN = 280,
     TLBRACKET = 281,
     TRBRACKET = 282,
     TLBRACE = 283,
     TRBRACE = 284,
     TLPAREN = 285,
     TRPAREN = 286,
     TSEMICOLON = 287,
     TCOLON = 288,
     TCOMMA = 289,
     TPLUS = 290,
     TMINUS = 291,
     TCLT = 292,
     TCLE = 293,
     TCGT = 294,
     TCGE = 295,
     TCEQ = 296,
     TCNE = 297,
     TLNOT = 298,
     TLAND = 299,
     TLOR = 300,
     TLSHIFT = 301,
     TRSHIFT = 302,
     TAND = 303,
     TXOR = 304,
     TOR = 305,
     TNOT = 306,
     TERROR = 307,
     UMINUS = 308
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
#define TCONDITION 265
#define TIF 266
#define TELSE 267
#define TSWITCH 268
#define TCASE 269
#define TDEFAULT 270
#define TREPORT 271
#define TMAX 272
#define TQUERYCHAR 273
#define TREFCHAR 274
#define TROW 275
#define TCOL 276
#define TINTCONST 277
#define TBOOLCONST 278
#define TIDENTIFIER 279
#define TASSIGN 280
#define TLBRACKET 281
#define TRBRACKET 282
#define TLBRACE 283
#define TRBRACE 284
#define TLPAREN 285
#define TRPAREN 286
#define TSEMICOLON 287
#define TCOLON 288
#define TCOMMA 289
#define TPLUS 290
#define TMINUS 291
#define TCLT 292
#define TCLE 293
#define TCGT 294
#define TCGE 295
#define TCEQ 296
#define TCNE 297
#define TLNOT 298
#define TLAND 299
#define TLOR 300
#define TLSHIFT 301
#define TRSHIFT 302
#define TAND 303
#define TXOR 304
#define TOR 305
#define TNOT 306
#define TERROR 307
#define UMINUS 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "dpal.y"
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
  NConditionFuncDecl* condition_func_decl;
  ParamList* param_list;
  NParam* param;
  NParamScalar* param_scalar;
  NParamMatrix* param_matrix;
  StmtList* stmt_list;
  NStmt* stmt;
  NVariableDecl* variable_decl;
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
/* Line 1529 of yacc.c.  */
#line 195 "dpal-parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

