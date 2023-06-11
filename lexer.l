%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#define YY_DECL int yylex()
#include "parser.tab.h"

//for debugging
int words = 0;
int chars = 0;
int lines = 0;
//look up string literal and char literal and floats
%}
letter      [a-zA-Z]
digit       [0-9]
boolean     [true]|[false]
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
FLOAT       {digit}*\.{digit}+(E[+\-]?{digit}+)?
NUMBER      {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    				{
							int c;
							printf("%s : COMMENT\n", yytext);
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}

"//"    				{
							int c;
							printf("%s : COMMENT\n", yytext);
							while((c = input()) != 0) {
								if(c == '\n')
									break;
							}
						}

"float"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"int"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"bool"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"char"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"string" { words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"double" { words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"void"	{words++; chars += strlen(yytext);
			printf("%s : FUNCTYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return FUNCTYPE;
		}

"write"	{words++; chars += strlen(yytext);
			printf("%s : WRITE\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}

"while"	{words++; chars += strlen(yytext);
			printf("%s : WHILE\n", yytext);
			yylval.string = strdup(yytext); 
			return WHILE;
		}

"if"	{words++; chars += strlen(yytext);
			printf("%s : IF\n", yytext);
			yylval.string = strdup(yytext); 
			return IF;
		}

"else"	{words++; chars += strlen(yytext);
			printf("%s : ELSE\n", yytext);
			yylval.string = strdup(yytext); 
			return ELSE;
		}

{boolean} {words++; chars += strlen(yytext);
			printf("%s : BOOLEAN\n", yytext);
			yylval.string = strdup(yytext); 
			return BOOLEAN;
		}

"return"	{words++; chars += strlen(yytext);
			printf("%s : RETURN\n", yytext);
			yylval.string = strdup(yytext); 
			return RETURN;
		}

{ID}	{words++; chars += strlen(yytext);
			  printf("%s : IDENTIFIER\n",yytext);
			  yylval.string = strdup(yytext); 
			  return ID;
			}

{NUMBER}		{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			  //yylval.number = atoi(strdup(yytext)); 
			  yylval.string = strdup(yytext); 
			  return NUMBER;
			}
			
";"		{chars++;
		  printf("%s : SEMICOLON\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SEMICOLON;
		}

"=="	{chars++;
		  printf("%s : IS_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return IS_EQ;
		}
		
">="	{chars++;
		  printf("%sx : GR_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return GR_EQ;
		}

"<="	{chars++;
		  printf("%s : LS_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LS_EQ;
		}

"!="	{chars++;
		  printf("%s : NOT_EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return NOT_EQ;
		}
		
"="		{chars++;
		  printf("%s : EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return EQ;
		}

"+"		{chars++;
		  printf("%s : PLUS_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return PLUS_OP;
		}

"-"		{chars++;
		  printf("%s : SUB_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return MINUS_OP;
		}

"*"		{chars++;
		  printf("%s : MULT_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return MULT_OP;
		}

"/"		{chars++;
		  printf("%s : DIV_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return DIV_OP;
		}

"%"     {chars++;
		  printf("%s : MOD_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return MOD_OP;
		}

"("		{chars++;
		  printf("%s : LPAR\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LPAR;
		}

")"		{chars++;
		  printf("%s : RPAR\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RPAR;
		}

"{"		{chars++;
		  printf("%s : LCURBRACK\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LCURBRACK;
		}

"}"		{chars++;
		  printf("%s : RCURBRACK\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RCURBRACK;
		}

","		{chars++;
		  printf("%s : COMMA\n", yytext);
		  yylval.string = strdup(yytext); 
		  return COMMA;
		}
	
"["		{chars++;
		  printf("%s : LSQUAREBRACK\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LSQUAREBRACK;
		}

"]"		{chars++;
		  printf("%s : RSQUAREBRACK\n", yytext);
		  yylval.string = strdup(yytext); 
		  return RSQUAREBRACK;
		}

"&&"	{chars++;
		  printf("%s : AND_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return AND_OP;
		}

"||"	{chars++;
		  printf("%s : OR_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return OR_OP;
		}

"!"		{chars++;
		  printf("%s : NOT_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return NOT_OP;
		}

"<"		{chars++;
		  printf("%s : LESS_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LT;
		}

">"		{chars++;
		  printf("%s : GREATER_OP\n", yytext);
		  yylval.string = strdup(yytext); 
		  return GT;
		}

[\n]	{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
%%