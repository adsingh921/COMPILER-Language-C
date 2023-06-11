/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

// Adding the libraries
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "MIPS.h"

#define bool int
#define FALSE 0
#define TRUE 1

extern int yylex();// this is the function that calls the lexer
extern int yyparse();// this is the function that calls the parser
extern FILE* yyin;// this is the file that is being read
//FILE * IRcode;
void yyerror(const char* s);// this is the function that calls the error function
//may be best practice
#define FLAG 0// this is the flag that is used to determine if the parser is working

// Global Variables
char currentScope[50]; // global or the name of the function
int semanticCheckPassed = 1; //flags for correctness of semantic checks
int currentSum; // used for the statements that calculate something involving multiple variables
char strSum[50];
char operator[50];
bool condition = TRUE; // used for the if statements
bool inWhile = FALSE; // used for the while statements
int runBlock = 0;
// used for the expressions
// char globalValue1[50]; 
// char globalValue2[50]; 
// char globalValue3[50];
// char globalValue4[50];
// char globalValue5[50];
// char globalValue6[50];
// char globalValue7[50];
// char globalValue8[50];
// char globalValue9[50];
char prefix[200] = "globalValue"; // this is used to make sure the variables are unique
char thisVar[50]; 
int i = 1;
char intStr[50];// this is used to convert from int to str
char currentOp[5];// this is used to store the current operator
bool inExpr = FALSE;// this is used to make sure we are in the right scope
bool condition2 = FALSE;// this is used to make sure we are in the right scope
int numExp = 0;	// number of numbers in an expression
int globalvar[50]; // this is used to store the values for expression


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 54 "parser.y"
{ // this is the struct that holds the values of the tokens
	int number;
	char character;
	char* string;
	struct AST* ast;
}
/* Line 193 of yacc.c.  */
#line 227 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    10,    13,    20,    24,    25,
      34,    37,    39,    42,    46,    51,    54,    56,    57,    59,
      62,    64,    67,    72,    73,    76,    78,    81,    84,    85,
      90,    95,    99,   104,   112,   113,   114,   122,   126,   130,
     133,   136,   138,   142,   146,   150,   154,   158,   160,   162,
     166,   167,   174,   175,   183,   184,   187,   190,   192,   196,
     198,   200,   202,   204,   206,   208,   210,   212,   213,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    47,    -1,    -1,    39,    38,    -1,
      40,    38,    -1,     3,     5,    17,     8,    18,     6,    -1,
       3,     5,     6,    -1,    -1,     3,     5,    12,    41,    42,
      13,    46,     6,    -1,    43,    42,    -1,    43,    -1,     3,
       5,    -1,     3,     5,    16,    -1,     3,     5,    17,    18,
      -1,    45,    44,    -1,    45,    -1,    -1,     5,    -1,     5,
      16,    -1,    51,    -1,    51,    16,    -1,    14,    38,    47,
      15,    -1,    -1,    48,    47,    -1,    48,    -1,    55,    47,
      -1,    53,    47,    -1,    -1,     5,     7,     5,     6,    -1,
       5,     7,     8,     6,    -1,     9,     5,     6,    -1,     5,
       7,    52,     6,    -1,     5,    17,     8,    18,     7,    52,
       6,    -1,    -1,    -1,     5,    12,    49,    44,    13,    50,
       6,    -1,    35,    52,     6,    -1,    35,     5,     6,    -1,
      35,     6,    -1,    52,    51,    -1,    52,    -1,    52,    10,
      52,    -1,    52,    11,    52,    -1,    52,    27,    52,    -1,
      52,    28,    52,    -1,    52,    34,    52,    -1,     5,    -1,
       8,    -1,    12,    52,    13,    -1,    -1,    21,    54,    12,
      58,    13,    46,    -1,    -1,    19,    12,    58,    13,    46,
      56,    57,    -1,    -1,    20,    46,    -1,    20,    55,    -1,
      61,    -1,    61,    59,    58,    -1,    24,    -1,    25,    -1,
      29,    -1,    22,    -1,    23,    -1,    31,    -1,    30,    -1,
      32,    -1,    -1,     5,    60,     5,    -1,     5,    60,     8,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   123,   123,   132,   143,   172,   230,   230,
     261,   270,   280,   296,   311,   328,   337,   347,   347,   374,
     400,   403,   408,   418,   418,   427,   435,   443,   453,   453,
     507,   550,   582,   628,   665,   665,   665,   672,   677,   682,
     690,   694,   697,   705,   708,   711,   714,   717,   722,   760,
     777,   777,   784,   784,   790,   790,   792,   795,   798,   804,
     805,   806,   807,   808,   809,   810,   811,   813,   813,   859
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "FUNCTYPE", "ID", "SEMICOLON",
  "EQ", "NUMBER", "WRITE", "PLUS_OP", "MINUS_OP", "LPAR", "RPAR",
  "LCURBRACK", "RCURBRACK", "COMMA", "LSQUAREBRACK", "RSQUAREBRACK", "IF",
  "ELSE", "WHILE", "LT", "GT", "AND_OP", "OR_OP", "NOT_OP", "MULT_OP",
  "DIV_OP", "IS_EQ", "GR_EQ", "LS_EQ", "NOT_EQ", "BOOLEAN", "MOD_OP",
  "RETURN", "$accept", "Program", "DeclList", "Decl", "FunDecl", "@1",
  "ParamsList", "Params", "ArgsList", "Args", "Block", "StmtList", "Stmt",
  "@2", "@3", "ExprList", "Expr", "WhileStmt", "@5", "IfStmt", "@6",
  "Else", "CondList", "Conj", "CompOperator", "Cond", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    39,    39,    41,    40,
      42,    42,    43,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    46,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    48,    49,    50,    48,    48,    48,    48,
      51,    51,    52,    52,    52,    52,    52,    52,    52,    52,
      54,    53,    56,    55,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    61,    61,    61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     6,     3,     0,     8,
       2,     1,     2,     3,     4,     2,     1,     0,     1,     2,
       1,     2,     4,     0,     2,     1,     2,     2,     0,     4,
       4,     3,     4,     7,     0,     0,     7,     3,     3,     2,
       2,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       0,     6,     0,     7,     0,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    23,     3,     3,     0,     1,     0,     0,
       0,    50,     0,     2,    23,    23,    23,     4,     5,     7,
       8,     0,     0,    34,     0,     0,    67,     0,    47,    39,
      48,     0,     0,    24,    27,    26,     0,     0,    47,    48,
       0,    17,     0,    31,     0,     0,    57,    67,    38,    47,
       0,    37,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    29,    30,    32,    47,     0,    16,    20,    41,     0,
      62,    63,    61,    65,    64,    66,     0,     0,    59,    60,
      67,     0,    49,    42,    43,    44,    45,    46,    12,     0,
      10,     6,    19,    35,    15,    21,    40,     0,    68,    69,
       3,    52,    58,     0,    13,     0,     0,     0,     0,    23,
      54,    51,    14,     9,    36,    33,     0,     0,    53,    22,
      55,    56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    36,    58,    59,    65,    66,
     101,    13,    14,    41,   107,    67,    68,    15,    27,    16,
     110,   118,    45,    80,    76,    46
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int8 yypact[] =
{
       7,     3,    12,     2,     7,     7,    76,   -52,    98,    26,
      29,   -52,    59,   -52,     2,     2,     2,   -52,   -52,   -52,
     -52,     9,    20,   -52,    46,    55,    58,    66,    64,   -52,
     -52,   106,    16,   -52,   -52,   -52,    82,    62,    88,    92,
      45,   108,    83,   -52,    77,    89,     5,    58,   -52,   -52,
      49,   -52,   106,   106,   106,   106,   106,    99,    90,    82,
     111,   -52,   -52,   -52,    79,   109,   108,    96,     8,   112,
     -52,   -52,   -52,   -52,   -52,   -52,    81,   107,   -52,   -52,
      58,   110,   -52,     6,     6,   -52,   -52,   -52,    52,   107,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   106,   -52,   -52,
       7,   -52,   -52,   107,   -52,   113,   118,   119,    47,     2,
     114,   -52,   -52,   -52,   -52,   -52,   115,    -5,   -52,   -52,
     -52,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,    -4,   -52,   -52,   -52,    67,   -52,    61,   -52,
     -51,   -12,   -52,   -52,   -52,    60,    -7,   -52,   -52,    15,
     -52,   -52,   -41,   -52,   -52,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -19
static const yytype_int8 yytable[] =
{
      17,    18,    33,    34,    35,    32,    81,     8,     6,   100,
       1,     9,     7,    49,    10,    40,    30,    37,    52,    53,
      31,    10,    51,    11,    50,    38,    52,    53,    39,    78,
      79,    25,    31,    54,    55,    54,    55,    12,   106,   102,
      56,    26,    56,    54,    55,    83,    84,    85,    86,    87,
      56,    63,   111,   115,    42,    52,    53,    52,    53,    52,
      53,    43,    82,    44,    28,    29,   120,    30,   104,   105,
      48,    31,    54,    55,    54,    55,    54,    55,    47,    56,
      60,    56,    19,    56,   -18,    57,    98,   -18,    20,    99,
     108,   -18,   -18,    21,    61,    92,   109,   116,    62,    70,
      71,    69,    77,    89,    88,    22,    72,    73,    74,    75,
      23,    49,    95,    64,    30,    24,    30,    91,    31,    97,
      31,   100,    93,   103,   113,   114,    90,    94,    96,     0,
     119,   112,   121,     0,   117
};

static const yytype_int8 yycheck[] =
{
       4,     5,    14,    15,    16,    12,    47,     5,     5,    14,
       3,     9,     0,     5,    19,    22,     8,     8,    10,    11,
      12,    19,     6,    21,    31,     5,    10,    11,     8,    24,
      25,     5,    12,    27,    28,    27,    28,    35,    89,    80,
      34,    12,    34,    27,    28,    52,    53,    54,    55,    56,
      34,     6,   103,     6,     8,    10,    11,    10,    11,    10,
      11,     6,    13,     5,     5,     6,   117,     8,    16,    17,
       6,    12,    27,    28,    27,    28,    27,    28,    12,    34,
      18,    34,     6,    34,     5,     3,     5,     8,    12,     8,
      97,    12,    13,    17,     6,    16,   100,   109,     6,    22,
      23,    18,    13,    13,     5,     7,    29,    30,    31,    32,
      12,     5,    16,     5,     8,    17,     8,     6,    12,     7,
      12,    14,    13,    13,     6,     6,    59,    66,    68,    -1,
      15,    18,   117,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    37,    38,    39,    40,     5,     0,     5,     9,
      19,    21,    35,    47,    48,    53,    55,    38,    38,     6,
      12,    17,     7,    12,    17,     5,    12,    54,     5,     6,
       8,    12,    52,    47,    47,    47,    41,     8,     5,     8,
      52,    49,     8,     6,     5,    58,    61,    12,     6,     5,
      52,     6,    10,    11,    27,    28,    34,     3,    42,    43,
      18,     6,     6,     6,     5,    44,    45,    51,    52,    18,
      22,    23,    29,    30,    31,    32,    60,    13,    24,    25,
      59,    58,    13,    52,    52,    52,    52,    52,     5,    13,
      42,     6,    16,    13,    44,    16,    51,     7,     5,     8,
      14,    46,    58,    13,    16,    17,    46,    50,    52,    38,
      56,    46,    18,     6,     6,     6,    47,    20,    57,    15,
      46,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 5: /* "ID" */
#line 105 "parser.y"
	{ fprintf(yyoutput, "%s", (yyvaluep->string)); };
#line 878 "parser.tab.c"
	break;
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 113 "parser.y"
    {								
								  (yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast); // this is the root of the AST
								  (yyval.ast) = (yyvsp[(1) - (2)].ast); // this is the root of the AST
									printf("DollarDollar1");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
								;}
    break;

  case 4:
#line 123 "parser.y"
    { // Rule Recognition of the format: int x; int y;
									(yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast); //everytime it comes up, we are adding to the tree
								 	(yyval.ast) = (yyvsp[(1) - (2)].ast);
									printf("DollarDollar2");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of DeclList\n");
									printf("\n");
		;}
    break;

  case 5:
#line 132 "parser.y"
    {
									(yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast); //everytime it comes up, we are adding to the tree
								 	(yyval.ast) = (yyvsp[(1) - (2)].ast); // this is the root of the AST
									printf("DollarDollar3");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("test\n");
								;}
    break;

  case 6:
#line 143 "parser.y"
    {	// Rule Recognition of the format: int x[5];									
							if(condition == TRUE){ // this is used to make sure we are in the right scope								
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Array declaration %s\n", (yyvsp[(2) - (6)].string));
									// Symbol Table Actions and semantic analysis
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID LSQUAREBRACK RSQUAREBRACK SEMICOLON\n");
									int inSymTab = found((yyvsp[(2) - (6)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (6)].string), inSymTab);
									// if so, find the sum of $1 and $3
									if(inSymTab == 0){ // if the variable is not in the symbol table, add it
										addItem((yyvsp[(2) - (6)].string), "Array", (yyvsp[(1) - (6)].string), atoi((yyvsp[(4) - (6)].string)), currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Array %s is already in the symbol table", (yyvsp[(2) - (6)].string));
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for array dec\n");
									(yyval.ast) = AST_Type("Type", (yyvsp[(1) - (6)].string), (yyvsp[(2) - (6)].string)); // this is the root of the AST
									printAST((yyval.ast),2);
									printf("Built a subtree for array dec\n");
									printf("\n\n\n");																
							}
;}
    break;

  case 7:
#line 172 "parser.y"
    { 	// Rule Recognition of the format: int x;
								if(condition == TRUE){
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Variable declaration %s\n", (yyvsp[(2) - (3)].string));
									// Symbol Table Actions and semantic analysis																
									symTabAccess();									
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");
									int inSymTab = found((yyvsp[(2) - (3)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (3)].string), inSymTab);
									if(inSymTab == 0){ // if the variable is not in the symbol table, add it
										addItem((yyvsp[(2) - (3)].string), "Var", (yyvsp[(1) - (3)].string), 0, currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (3)].string));
									}
									printf("\n\n\n");
									showAllSymTable(); // this is the symbol table
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									(yyval.ast) = AST_Type("Type", (yyvsp[(1) - (3)].string), (yyvsp[(2) - (3)].string));
									printAST((yyval.ast),2);
									printf("Built a subtree for var dec\n");
									printf("\n\n\n");
									// IR Code Actions
									varDeclaration((yyvsp[(2) - (3)].string), currentScope);
								}
	;}
    break;

  case 8:
#line 230 "parser.y"
    {addToTables((yyvsp[(2) - (3)].string)); switchScope(currentScope, (yyvsp[(2) - (3)].string));;}
    break;

  case 9:
#line 230 "parser.y"
    { // Rule recognition for functions with parameters
								if(condition == TRUE){ // this is used to make sure we are in the right scope
									printf("\n\n"); 
									printf("\n RECOGNIZED RULE: Function declaration %s\n", (yyvsp[(2) - (8)].string)); 
									//add name to global symbol table									
									//Symbol Table Actions and semantic analysis									
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for Type ID LPAR Params RPAR BLOCK\n");
									int inSymTab = found((yyvsp[(2) - (8)].string), currentScope); 
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (8)].string), inSymTab); 
									if(inSymTab == 0){// if the variable is not in the symbol table, add it
										addItem((yyvsp[(2) - (8)].string), "Func", (yyvsp[(1) - (8)].string), 0, currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Func %s is already in the symbol table", (yyvsp[(2) - (8)].string));
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for var dec\n"); // this is the root of the AST
									(yyval.ast) = AST_Type("Type", (yyvsp[(1) - (8)].string), (yyvsp[(2) - (8)].string));
									printAST((yyval.ast),2);
									printf("Built a subtree for var dec\n"); 
									printf("\n\n\n");
									// MIPS Actions
								}
		;}
    break;

  case 10:
#line 261 "parser.y"
    {// Rule recognition for parameters
									(yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast);//everytime it comes up, we are adding to the tree
									(yyval.ast) = (yyvsp[(1) - (2)].ast);// this is the root of the AST
									printf("DollarDollar6");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of ParamsList\n");
								;}
    break;

  case 11:
#line 270 "parser.y"
    { 	// Rule recognition for parameters
									(yyval.ast) = (yyvsp[(1) - (1)].ast);// this is the root of the AST
									printf("DollarDollar7");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of Params\n\n");
								;}
    break;

  case 12:
#line 280 "parser.y"
    {	// Rule recognition for parameters
									printf("inside params\n");
									varDeclaration((yyvsp[(2) - (2)].string), currentScope);									
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");// Symbol Table Actions and semantic analysis
									int inSymTab = found((yyvsp[(2) - (2)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (2)].string), inSymTab);// checking to see if the variable is in the symbol table
									if(inSymTab == 0){// if the variable is not in the symbol table, add it
										addItem((yyvsp[(2) - (2)].string), "Var", (yyvsp[(1) - (2)].string), 0, currentScope);
									}
									else{// if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (2)].string));
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								;}
    break;

  case 13:
#line 296 "parser.y"
    {		// Rule recognition for parameters
									varDeclaration((yyvsp[(2) - (3)].string), currentScope);	// Symbol Table Actions and semantic analysis								
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");
									int inSymTab = found((yyvsp[(2) - (3)].string), currentScope);// checking to see if the variable is in the symbol table
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (3)].string), inSymTab);// if the variable is not in the symbol table, add it
									if(inSymTab == 0){
										addItem((yyvsp[(2) - (3)].string), "Var", (yyvsp[(1) - (3)].string), 0, currentScope);
									}
									else{
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (3)].string));
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								;}
    break;

  case 14:
#line 311 "parser.y"
    {	// Rule recognition for parameters
									varDeclaration((yyvsp[(2) - (4)].string), currentScope);
									printf("Semantic Analysis for TYPE ID SEMICOLON\n"); // Symbol Table Actions and semantic analysis
									int inSymTab = found((yyvsp[(2) - (4)].string), currentScope); // checking to see if the variable is in the symbol table
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (4)].string), inSymTab);// if the variable is not in the symbol table, add it
									if(inSymTab == 0){
										addItem((yyvsp[(2) - (4)].string), "Var", (yyvsp[(1) - (4)].string), 0, currentScope);
									}
									else{
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[(2) - (4)].string));
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								;}
    break;

  case 15:
#line 328 "parser.y"
    {// Rule recognition for parameters
									(yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast);//everytime it comes up, we are adding to the tree
									(yyval.ast) = (yyvsp[(1) - (2)].ast);// this is the root of the AST
									printf("DollarDollar8");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of ArgsList\n");
								;}
    break;

  case 16:
#line 337 "parser.y"
    {	
									(yyval.ast) = (yyvsp[(1) - (1)].ast);
									printf("DollarDollar9");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of Params\n\n");
								;}
    break;

  case 18:
#line 347 "parser.y"
    {	// Rule recognition for parameters
									printf("inside params\n");
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON as a parameter\n");
									int inSymTab1 = found((yyvsp[(1) - (1)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(1) - (1)].string), inSymTab1);									
									// if so, find the sum of $1 and $3
									if(inSymTab1 == 1){
										// Semantic Actions
										// if the variables are in the symbol table, check to see if they are the same type
										printf("\nChecking types: \n");																				
										int typeMatch = 0;
										if (typeMatch == 0) {									
										semanticCheckPassed = 0;
										}
										else{
											printf("should be setting values here\n");										
										}
									}
									// if not, throw an error
									else{
										if(inSymTab1 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(1) - (1)].string));
										}									
									}
									showSymTable(tableHolder[findScope(currentScope)]);																		
								;}
    break;

  case 19:
#line 374 "parser.y"
    {	// Rule recognition for parameters
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON as a parameter\n");
									int inSymTab1 = found((yyvsp[(1) - (2)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(1) - (2)].string), inSymTab1);									
									// if so, find the sum of $1 and $3
									if(inSymTab1 == 1){
										// Semantic Actions
										// if the variables are in the symbol table, check to see if they are the same type
										printf("\nChecking types: \n");
										int typeMatch = 0;
										if (typeMatch == 0) {
										semanticCheckPassed = 0;
										}
										else{
											printf("should be setting values here\n");
										}
									}
									// if not, throw an error
									else{
										if(inSymTab1 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(1) - (2)].string));
										}
									}
									showSymTable(tableHolder[findScope(currentScope)]);
								;}
    break;

  case 20:
#line 400 "parser.y"
    {	// Rule recognition for parameters 
									printf("inside params\n");
								;}
    break;

  case 21:
#line 403 "parser.y"
    {	// Rule recognition for parameters 
									printf("inside params\n");
								;}
    break;

  case 22:
#line 408 "parser.y"
    {// Rule recognition for parameters
									switchScope(currentScope, "global"); // this is used to make sure we are in the right scope					
									printf("DollarDollar10"); // this is the root of the AST
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of Block\n");									
								;}
    break;

  case 24:
#line 418 "parser.y"
    { // Rule Recognition of the format: int x; int y;
									(yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast);
									(yyval.ast) = (yyvsp[(1) - (2)].ast);
									printf("DollarDollar11");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of Stmt StmtList\n");
								;}
    break;

  case 25:
#line 427 "parser.y"
    { 
									(yyval.ast) = (yyvsp[(1) - (1)].ast);
									printf("DollarDollar12");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of Stmt\n");
								;}
    break;

  case 26:
#line 435 "parser.y"
    {
									(yyval.ast) = (yyvsp[(1) - (2)].ast);
									printf("DollarDollar13");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of IfStmt\n");
								;}
    break;

  case 27:
#line 443 "parser.y"
    {
									(yyval.ast) = (yyvsp[(1) - (2)].ast);
									printf("DollarDollar14");
									printf("\n");
									printf((yyval.ast));
								  	printf("\n");
									printf("end of WhileStmt\n");
								;}
    break;

  case 29:
#line 453 "parser.y"
    { 	// Rule Recognition of the format: x = y;
									if(condition == TRUE){ 
									isUsed((yyvsp[(1) - (4)].string), currentScope);// Symbol Table Actions and semantic analysis
									printf("kyle test\n"); // checking to see if the variable is in the symbol table
									printf((yyvsp[(1) - (4)].string)); 
									isUsed((yyvsp[(3) - (4)].string), currentScope); // for a deadcode
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Assignment statement\n"); 
									// Symbol Table Actions and semantic analysis									
									symTabAccess();
									// Semantic Analysis
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID EQ ID\n");
									int inSymTab1 = found((yyvsp[(1) - (4)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(1) - (4)].string), inSymTab1);
									int inSymTab2 = found((yyvsp[(3) - (4)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(3) - (4)].string), inSymTab2);
									// if so, find the sum of $1 and $3
									if(inSymTab1 == 1 && inSymTab2 == 1){
										// Semantic Actions
										// if the variables are in the symbol table, check to see if they are the same type
										printf("\nChecking types: \n"); 
										int typeMatch = compareTypesVars((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string), currentScope); // this is the function that compares the types of the variables
										if (typeMatch == 0) { // if the types do not match, throw an error
										printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));
										semanticCheckPassed = 0; // this is used to make sure the semantic analysis passed
										}
										else{ // if the types do match, set $1 to the value of $3
											printf("should be setting values here\n");
											setValue((yyvsp[(1) - (4)].string), returnValue((yyvsp[(3) - (4)].string), currentScope), currentScope);
										}
									}
									// if not, throw an error
									else{
										if(inSymTab1 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(1) - (4)].string));
										}
										if(inSymTab2 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(3) - (4)].string));
										}
									}
									showSymTable(tableHolder[findScope(currentScope)]); // this is the symbol table
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									(yyval.ast) = AST_assignment("=", (yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));
									printAST((yyval.ast), 2);
									printf("Built a subtree for var dec\n");
									// IR Code Actions*/
									// ---- EMIT IR 3-ADDRESS CODE ---- //
									// The IR  code is printed to a separate file
									switchFile(0);
									emitIDeqIDAssign((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string), currentScope);
									}
								;}
    break;

  case 30:
#line 507 "parser.y"
    { 	// Rule Recognition of the format: x = 5;
									if(condition == TRUE){
										printf("\n\n");
										printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 				
										isUsed((yyvsp[(1) - (4)].string), currentScope); // maybe this is a deadcode
										// Symbol Table Actions and semantic analysis
										symTabAccess();
										// checking to see if the variable is in the symbol table
										printf("Semantic Analysis for ID EQ NUMBER SEMICOLON\n");
										int inSymTab = found((yyvsp[(1) - (4)].string), currentScope);
										printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (4)].string), inSymTab);
										// if so, set $1 to the value of $3
										if(inSymTab == 1){
											setValue((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string), currentScope);
										}
										// if not, throw an error
										else{
											printf("SEMANTIC ERROR: Var %s is not in the symbol table", (yyvsp[(2) - (4)].string));
										}
										setValue((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string), currentScope);
										printf("\n\n\n");
										showSymTable(tableHolder[findScope(currentScope)]);
										printf("\n\n\n");
										// AST Actions
										char str[50];
										sprintf(str, "%s", (yyvsp[(3) - (4)].string)); // this converts from int to str
										printf("Attempting to build a subtree for var dec\n");
										(yyval.ast) = AST_assignment("=",(yyvsp[(1) - (4)].string), str);
										printAST((yyval.ast),2);
										printf("Built a subtree for var dec\n");
										printf("\n\n\n");
										// IR Code Actions
										if (semanticCheckPassed == 1) {
											printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");
											// ---- EMIT IR 3-ADDRESS CODE ---- //
											// The IR  code is printed to a separate file
											// MIPS Code Actions
											emitMIPSConstantIntAssignment((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].string));									
										} else {
											printf("\n\n>>> AssignStmt Rule is SEMANTICALLY incorrect and IR code is not emitted! <<<\n\n");
										}
									}
								;}
    break;

  case 31:
#line 550 "parser.y"
    { 	// Rule Recognition of the format: write x;
									if(condition == TRUE){
										printf("\n\n");
										printf("\n RECOGNIZED RULE: WRITE statement\n");
										// Symbol Table Actions
										printf("\n\n\n");
										showSymTable(tableHolder[findScope(currentScope)]);
										//showAllSymTable();
										printf("\n\n\n");
										// checking to see if the variable is in the symbol table
										printf("Semantic Analysis for WRITE ID  SEMICOLON\n");
										int inSymTab = found((yyvsp[(2) - (3)].string), currentScope);
										printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (3)].string), inSymTab);
										//if so, set $1 to the value of $3
										if(inSymTab == 1){
											// AST Actions
											printf("Attempting to build a subtree for var dec\n");
											(yyval.ast) = AST_Write("Write", (yyvsp[(1) - (3)].string), (yyvsp[(2) - (3)].string));
											printAST((yyval.ast),2);
											printf("Built a subtree for var dec\n");
										}
										// if not, throw an error
										else{
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(2) - (3)].string));
										}
										showSymTable(tableHolder[findScope(currentScope)]);
										// IR Code Actions
										//MIPS Code actions
										emitMIPSWriteId((yyvsp[(2) - (3)].string));
										isUsed((yyvsp[(2) - (3)].string), currentScope);
									}
								;}
    break;

  case 32:
#line 582 "parser.y"
    {	// Rule recognition for expression statement

								if(condition == TRUE){
									isUsed((yyvsp[(1) - (4)].string), currentScope);									
									printf("inside expression statement\n");
  									printf("\n RECOGNIZED RULE: Expression statement\n");									
									// Symbol Table Actions and semantic analysis
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID EQ Expr SEMICOLON\n");
									int inSymTab = found((yyvsp[(1) - (4)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (4)].string), inSymTab);
									// if so, set $1 to the value of the expression
									if(inSymTab == 1){
										sprintf(strSum, "%d", currentSum);
										// Symbol Table Actions
										char str[50];
										sprintf(str, "%s", (yyvsp[(3) - (4)].ast)); // this converts from struct to str
										setValue((yyvsp[(1) - (4)].string), strSum, currentScope);
										//showAllSymTable();
										printf("error here\n");
										currentSum = 0;
									}
									// if not, throw an error
									else{
										printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(2) - (4)].string));
									}									
									showSymTable(tableHolder[findScope(currentScope)]);
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									(yyval.ast) = AST_assignment("=",(yyvsp[(1) - (4)].string), AST_assignment(operator,(yyvsp[(1) - (4)].string),(yyvsp[(3) - (4)].ast)));
									printAST((yyval.ast),2);
									printf("Built a subtree for var dec\n");
									// MIPS Code Actions
									emitMIPSConstantIntAssignment((yyvsp[(1) - (4)].string), strSum);


									//reset expression variables
									for(int i = 0; i < numExp; i++){
										globalvar[i] = 0;
									}
									//globalvar[0] = '\0';
									numExp = 0;
									
								}
								;}
    break;

  case 33:
#line 628 "parser.y"
    { 	// Rule Recognition of the format: x[5] = 5 + 6;
									if(condition == TRUE){
									isUsed((yyvsp[(1) - (7)].string), currentScope);
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Array statement\n");
									// Symbol Table Actions
									printf("\n\n\n");
									showSymTable(tableHolder[findScope(currentScope)]);
									//showAllSymTable();
									printf("\n\n\n");
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID LSQUAREBRACK NUMBER RSQUAREBRACK EQ Expr SEMICOLON\n");
									int inSymTab = found((yyvsp[(1) - (7)].string), currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(2) - (7)].string), inSymTab);
									// if so, set $1 to the value of the expression
									if(inSymTab == 1){
										sprintf(strSum, "%d", currentSum);
										// Symbol Table Actions
										char str[50];
										sprintf(str, "%s", (yyvsp[(3) - (7)].string)); // this converts from struct to str
										printf("error here\n");
										currentSum = 0;
									}
									// if not, throw an error
									else{
										printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", (yyvsp[(2) - (7)].string));
									}
									showSymTable(tableHolder[findScope(currentScope)]);
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									(yyval.ast) = AST_assignment("=",(yyvsp[(1) - (7)].string), AST_assignment(operator,(yyvsp[(1) - (7)].string),(yyvsp[(3) - (7)].string)));
									printAST((yyval.ast),2);
									printf("Built a subtree for var dec\n");
									// MIPS Code Actions
									emitMIPSConstantIntAssignment((yyvsp[(1) - (7)].string), strSum);
								}
								;}
    break;

  case 34:
#line 665 "parser.y"
    {switchScope(currentScope, (yyvsp[(1) - (2)].string));;}
    break;

  case 35:
#line 665 "parser.y"
    {switchScope(currentScope, "global");;}
    break;

  case 36:
#line 665 "parser.y"
    { 	// Rule Recognition of function calls
									if(condition == TRUE){ // this is used to make sure we are in the right scope
									isUsed((yyvsp[(1) - (7)].string), currentScope);// Symbol Table Actions and semantic analysis
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Function call statement\n");
									}									
		;}
    break;

  case 37:
#line 672 "parser.y"
    {// Rule Recognition of the format: return 5 + 6;
			if(condition == TRUE){
			// Rule Recognition of the format: return 5 + 6;
			}
		;}
    break;

  case 38:
#line 677 "parser.y"
    { 	
			if(condition == TRUE){ // this is used to make sure we are in the right scope
				// Rule Recognition of the format: return x;
			}
		;}
    break;

  case 39:
#line 682 "parser.y"
    { 	
			if(condition == TRUE){
			// Rule Recognition of the format: return;
			}
		;}
    break;

  case 40:
#line 690 "parser.y"
    { // Rule Recognition of the format: int x; int y;
            (yyvsp[(1) - (2)].ast)->right = (yyvsp[(2) - (2)].ast); //everytime it comes up, we are adding to the tree
            (yyval.ast) = (yyvsp[(1) - (2)].ast); // this is the root of the AST
        ;}
    break;

  case 41:
#line 694 "parser.y"
    { // Rule Recognition of the format: int x;
            (yyval.ast) = (yyvsp[(1) - (1)].ast);
        ;}
    break;

  case 42:
#line 697 "parser.y"
    {// Rule Recognition of the format: 5 + 6;
		printAdd();// IR Code Actions

		
		emitAdditionMIPS(globalvar[0], globalvar[1]);
		
	;}
    break;

  case 43:
#line 705 "parser.y"
    {// Rule Recognition of the format: 5 - 6;
		printSub();
    ;}
    break;

  case 44:
#line 708 "parser.y"
    {// Rule Recognition of the format: 5 * 6;
		printMult();
    ;}
    break;

  case 45:
#line 711 "parser.y"
    {// Rule Recognition of the format: 5 / 6;
		printDiv();
    ;}
    break;

  case 46:
#line 714 "parser.y"
    {// Rule Recognition of the format: 5 % 6;
		printMod();
    ;}
    break;

  case 47:
#line 717 "parser.y"
    {// Rule Recognition of the format: x;
		printf("\n\n");// Symbol Table Actions and semantic analysis
		printf("\n RECOGNIZED RULE: an ID\n");// checking to see if the variable is in the symbol table

    ;}
    break;

  case 48:
#line 722 "parser.y"
    {// Rule Recognition of the format: 5;
		// the whole purpose of this is to have variables you can then use
		// in the MIPS code generation
		// make an if statement that checks if we are in an expression

		
		globalvar[numExp] = atoi((yyvsp[(1) - (1)].string));
		printf("globalvar is\n");
		printf("%d", globalvar[numExp]);
		numExp++;

		//do expression
		for(int i = 0; i < numExp; i++){

			//do expression
		}

		



		
		// if(inExpr == TRUE){
		// printf("step 0\n");
		// sprintf(intStr, "%d", i);// this converts from int to str
		// printf("step 1\n");// this is the root of the AST
		// printf("intStr is %s\n", intStr);
		// printf("step 2\n");
		// strcpy(thisVar, strcat(prefix, intStr));// this is the root of the AST
		// printf("step 3\n");
		// printf("thisVar is %s\n", thisVar);
		// strcpy(thisVar, $1);
		// i++;
		// printf("thisVar2 is %s\n", thisVar);// this is the root of the AST
		// }
		printf("\n\n");
		printf("\n RECOGNIZED RULE: a number\n");// Symbol Table Actions and semantic analysis
    ;}
    break;

  case 49:
#line 760 "parser.y"
    {// Rule Recognition of the format: (5);
    ;}
    break;

  case 50:
#line 777 "parser.y"
    {inWhile = TRUE;;}
    break;

  case 51:
#line 777 "parser.y"
    {// Rule Recognition of the format: while (x < 5) { x = x + 1; }
	condition = TRUE;// Symbol Table Actions and semantic analysis
	printf("RECOGNIZED WHILE STATEMENT\n");// checking to see if the variable is in the symbol table
	inWhile = FALSE;// if so, find the sum of $1 and $3
;}
    break;

  case 52:
#line 784 "parser.y"
    {condition = TRUE;;}
    break;

  case 53:
#line 784 "parser.y"
    {
// If the condition is true, a global variable is set to true, 
// which allows every statement to be executed.
// If it is false, no statements will execute until the end of the block is reached.
;}
    break;

  case 55:
#line 790 "parser.y"
    {// Rule Recognition of the format: else { x = x + 1; }
;}
    break;

  case 56:
#line 792 "parser.y"
    {// Rule Recognition of the format: else if (x < 5) { x = x + 1; }
;}
    break;

  case 57:
#line 795 "parser.y"
    {// Rule Recognition of the format: x < 5
			(yyval.ast) = (yyvsp[(1) - (1)].ast);
		 ;}
    break;

  case 58:
#line 799 "parser.y"
    {
			(yyvsp[(1) - (3)].ast)->right = (yyvsp[(3) - (3)].ast);
			(yyval.ast) = (yyvsp[(1) - (3)].ast);
		 ;}
    break;

  case 61:
#line 806 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 62:
#line 807 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 63:
#line 808 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 64:
#line 809 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 65:
#line 810 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 66:
#line 811 "parser.y"
    {strcpy(currentOp,(yyvsp[(1) - (1)].string));;}
    break;

  case 68:
#line 813 "parser.y"
    {// Rule Recognition of the format: x < 5
	printf("before while loop %d\n", inWhile);// Symbol Table Actions and semantic analysis
	if(inWhile == TRUE){
		printf("in while loop %s %s %s %s\n", (yyvsp[(1) - (3)].string), currentOp, (yyvsp[(3) - (3)].string), currentScope);
		emitWhile((yyvsp[(1) - (3)].string), currentOp, (yyvsp[(3) - (3)].string), currentScope, 0, 0);
	}
	int inSymTab1 = found((yyvsp[(1) - (3)].string), currentScope);// checking to see if the variable is in the symbol table
	printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(1) - (3)].string), inSymTab1);
	int inSymTab2 = found((yyvsp[(3) - (3)].string), currentScope);
	printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(3) - (3)].string), inSymTab2);
	if(inSymTab1 == 1 && inSymTab2 == 1){
		// Semantic Actions
		// if the variables are in the symbol table, check to see if they are the same type
		printf("\nChecking types: \n");
		int typeMatch = compareTypesVars((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), currentScope);
		if (typeMatch == 0) {
		printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
		semanticCheckPassed = 0;
		}
		else{// if the types do match, set $1 to the value of $3
			char str1[50];
			char str2[50];
			sprintf(str1, "%s", (yyvsp[(1) - (3)].string)); // this converts from int to str
			sprintf(str2, "%s", (yyvsp[(3) - (3)].string)); // this converts from int to str
			printf("Attempting to build a subtree for var dec\n");
			(yyval.ast) = AST_assignment("==",str1, str2);// this is the root of the AST
			printAST((yyval.ast),2);
			printf("Built a subtree for var dec\n");
		}
	}
	//if so, check to see if they are equal
	if(semanticCheckPassed == 1){// if the types do match, set $1 to the value of $3
		if(compareInts((yyvsp[(2) - (3)].ast), atoi(returnValue((yyvsp[(1) - (3)].string), currentScope)), atoi(returnValue((yyvsp[(3) - (3)].string), currentScope)))){    
			printf("Condition passed.\n");
			condition = TRUE;
		}
		else{
			printf("Condition failed.\n");
			condition = FALSE;
		}
		// if not, return false
	}
	// if so, return true
	// if not, return false
;}
    break;

  case 69:
#line 859 "parser.y"
    {// Rule Recognition of the format: x < 5
	printf("before while loop %d\n", inWhile);
	if(inWhile == TRUE){
		printf("in while loop %s %s %s %s\n", (yyvsp[(1) - (3)].string), currentOp, (yyvsp[(3) - (3)].string), currentScope);
		emitWhile((yyvsp[(1) - (3)].string), currentOp, (yyvsp[(3) - (3)].string), currentScope, 0, 1);
	}
	// check to see if the variables are in the symbol table
	int inSymTab1 = found((yyvsp[(1) - (3)].string), currentScope);
	printf("looking for %s in symtab - found: %d\n\n\n", (yyvsp[(1) - (3)].string), inSymTab1);
	if(inSymTab1 == 1){
		// Semantic Actions
		// if the variables are in the symbol table, check to see if they are the same type
		printf("\nChecking types: \n");
		int typeMatch = compareTypesVars((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string), currentScope);
		if (typeMatch == 0) {
		printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", (yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
		semanticCheckPassed = 0;
		}
		else{
			char str1[50];
			char str2[50];
			sprintf(str1, "%s", (yyvsp[(1) - (3)].string)); // this converts from int to str
			sprintf(str2, "%s", (yyvsp[(3) - (3)].string)); // this converts from int to str
			printf("Attempting to build a subtree for var dec\n");
			(yyval.ast) = AST_assignment("==",str1, str2);
			printAST((yyval.ast),2);
			printf("Built a subtree for var dec\n");
		}
	}
	//if so, check to see if they are equal
	if(semanticCheckPassed == 1){// if the types do match, set $1 to the value of $3
		if(compareInts((yyvsp[(2) - (3)].ast), atoi(returnValue((yyvsp[(1) - (3)].string), currentScope)), atoi((yyvsp[(3) - (3)].string)))){
			printf("Condition passed.\n");// if so, return true
			condition = TRUE;
		}
		else{// if not, return false
			printf("Condition failed.\n");
			condition = FALSE;
		}
		// if not, return false
	}
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2507 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 902 "parser.y"


//Main function
int main(int argc, char**argv)
{
	time_t startTime, endTime; // variables to store start and end times
    clock_t startClock, endClock; // variables to store start and end CPU time
    double cpuTimeUsed; // variable to store CPU time used
	strcpy(currentScope,"global"); // initialize the current scope
	strcpy(tableHolder[0].scope, "global"); // initialize the first entry in the symbol table
	tableHolder[0].symTabIndex = 0;

	printf("\n\n##### COMPILER STARTED #####\n\n");

	startTime = time(NULL); //get the start time
	startClock = clock(); // get the start CPU time
	initIRcodeFile(); //initialize the IR code file
	initAssemblyFile(); //initialize the assembly code file
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse(); //parse the input code
	emitEndOfAssemblyCode(); // emit the end of the assembly code
	sleep(2); //sleep for 2 seconds to allow the user to see the output
     endClock = clock(); //get the end CPU time
     endTime = time(NULL); //get the end time
     cpuTimeUsed = ((double) (endClock - startClock)) / CLOCKS_PER_SEC; // calculate the CPU time used
	printf("\n\n##### COMPILER ENDED #####\n\n");
	printf("Compilation time: %ld seconds\n", (long) (endTime - startTime)); // print the total compilation time
    printf("Execution time: %f seconds\n", cpuTimeUsed); // print the total execution time
	
	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);// print the parse error
	exit(1);// exit the program with error code 1
}
