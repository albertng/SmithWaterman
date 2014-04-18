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
     TCONST = 259,
     TTRUE = 260,
     TFALSE = 261,
     TUNSIGNED = 262,
     TSIGNED = 263,
     TBOOL = 264,
     TCELL = 265,
     TCONDITION = 266,
     TIF = 267,
     TELSE = 268,
     TSWITCH = 269,
     TCASE = 270,
     TREPORT = 271,
     TMAX = 272,
     TQUERYCHAR = 273,
     TREFCHAR = 274,
     TROW = 275,
     TCOL = 276,
     TINTCONST = 277,
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
#define TCONST 259
#define TTRUE 260
#define TFALSE 261
#define TUNSIGNED 262
#define TSIGNED 263
#define TBOOL 264
#define TCELL 265
#define TCONDITION 266
#define TIF 267
#define TELSE 268
#define TSWITCH 269
#define TCASE 270
#define TREPORT 271
#define TMAX 272
#define TQUERYCHAR 273
#define TREFCHAR 274
#define TROW 275
#define TCOL 276
#define TINTCONST 277
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
#line 19 "dpal.y"
{
  NProgram* program;
  NAlphabetDecl* alphabet_decl;
  NCharacterDecl* character_decl;
  CharacterDeclList* character_decl_list;
  NIdentifier *id;
  std::string* str_const;
  int int_const;
  int token;
}
/* Line 1529 of yacc.c.  */
#line 160 "dpal-parse.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

