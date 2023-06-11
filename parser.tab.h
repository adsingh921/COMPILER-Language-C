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
     TYPE = 258,
     FUNCTYPE = 259,
     ID = 260,
     SEMICOLON = 261,
     EQ = 262,
     NUMBER = 263,
     WRITE = 264,
     PLUS_OP = 265,
     MINUS_OP = 266,
     LPAR = 267,
     RPAR = 268,
     LCURBRACK = 269,
     RCURBRACK = 270,
     COMMA = 271,
     LSQUAREBRACK = 272,
     RSQUAREBRACK = 273,
     IF = 274,
     ELSE = 275,
     WHILE = 276,
     LT = 277,
     GT = 278,
     AND_OP = 279,
     OR_OP = 280,
     NOT_OP = 281,
     MULT_OP = 282,
     DIV_OP = 283,
     IS_EQ = 284,
     GR_EQ = 285,
     LS_EQ = 286,
     NOT_EQ = 287,
     BOOLEAN = 288,
     MOD_OP = 289,
     RETURN = 290
   };
#endif
/* Tokens.  */
#define TYPE 258
#define FUNCTYPE 259
#define ID 260
#define SEMICOLON 261
#define EQ 262
#define NUMBER 263
#define WRITE 264
#define PLUS_OP 265
#define MINUS_OP 266
#define LPAR 267
#define RPAR 268
#define LCURBRACK 269
#define RCURBRACK 270
#define COMMA 271
#define LSQUAREBRACK 272
#define RSQUAREBRACK 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define LT 277
#define GT 278
#define AND_OP 279
#define OR_OP 280
#define NOT_OP 281
#define MULT_OP 282
#define DIV_OP 283
#define IS_EQ 284
#define GR_EQ 285
#define LS_EQ 286
#define NOT_EQ 287
#define BOOLEAN 288
#define MOD_OP 289
#define RETURN 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 54 "parser.y"
{ // this is the struct that holds the values of the tokens
	int number;
	char character;
	char* string;
	struct AST* ast;
}
/* Line 1529 of yacc.c.  */
#line 126 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

