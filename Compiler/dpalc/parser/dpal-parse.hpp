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
     TREPORT = 270,
     TMAX = 271,
     TQUERYCHAR = 272,
     TREFCHAR = 273,
     TROW = 274,
     TCOL = 275,
     TINTCONST = 276,
     TBOOLCONST = 277,
     TIDENTIFIER = 278,
     TASSIGN = 279,
     TLBRACKET = 280,
     TRBRACKET = 281,
     TLBRACE = 282,
     TRBRACE = 283,
     TLPAREN = 284,
     TRPAREN = 285,
     TSEMICOLON = 286,
     TCOLON = 287,
     TCOMMA = 288,
     TPLUS = 289,
     TMINUS = 290,
     TCLT = 291,
     TCLE = 292,
     TCGT = 293,
     TCGE = 294,
     TCEQ = 295,
     TCNE = 296,
     TLNOT = 297,
     TLAND = 298,
     TLOR = 299,
     TLSHIFT = 300,
     TRSHIFT = 301,
     TAND = 302,
     TXOR = 303,
     TOR = 304,
     TNEG = 305
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
#define TREPORT 270
#define TMAX 271
#define TQUERYCHAR 272
#define TREFCHAR 273
#define TROW 274
#define TCOL 275
#define TINTCONST 276
#define TBOOLCONST 277
#define TIDENTIFIER 278
#define TASSIGN 279
#define TLBRACKET 280
#define TRBRACKET 281
#define TLBRACE 282
#define TRBRACE 283
#define TLPAREN 284
#define TRPAREN 285
#define TSEMICOLON 286
#define TCOLON 287
#define TCOMMA 288
#define TPLUS 289
#define TMINUS 290
#define TCLT 291
#define TCLE 292
#define TCGT 293
#define TCGE 294
#define TCEQ 295
#define TCNE 296
#define TLNOT 297
#define TLAND 298
#define TLOR 299
#define TLSHIFT 300
#define TRSHIFT 301
#define TAND 302
#define TXOR 303
#define TOR 304
#define TNEG 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "dpal.y"
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
  StmtList* stmt_list;
  NStmt* stmt;
}
/* Line 1529 of yacc.c.  */
#line 178 "dpal-parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

