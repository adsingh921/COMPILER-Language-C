%{
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
%}
%union { // this is the struct that holds the values of the tokens
	int number;
	char character;
	char* string;
	struct AST* ast;
}
// Token Definitions
%token <string> TYPE
%token <string> FUNCTYPE
%token <string> ID
%token <string> SEMICOLON
%token <string> EQ
%token <string> NUMBER
%token <string> WRITE
%token <string> PLUS_OP
%token <string> MINUS_OP
%token <string> LPAR
%token <string> RPAR
%token <string> LCURBRACK
%token <string> RCURBRACK
%token <string> COMMA
%token <string> LSQUAREBRACK
%token <string> RSQUAREBRACK
%token <string> IF
%token <string> ELSE
%token <string> WHILE
%token <string> LT
%token <string> GT
%token <string> AND_OP
%token <string> OR_OP
%token <string> NOT_OP
%token <string> MULT_OP
%token <string> DIV_OP
%token <string> IS_EQ
%token <string> GR_EQ
%token <string> LS_EQ
%token <string> NOT_EQ
%token <string> BOOLEAN
%token <string> MOD_OP
%token <string> RETURN

// Order of operations
%left OR_OP
%left AND_OP
%left LT GT IS_EQ GR_EQ LS_EQ NOT_EQ
%left PLUS_OP MINUS_OP
%left MULT_OP DIV_OP MOD_OP
%left NOT_OP
%left LPAR RPAR

//Maybe we can remove this but we decided to have it
%printer { fprintf(yyoutput, "%s", $$); } ID; 

%type <ast> Program DeclList Decl FunDeclList FunDecl FunCallList FunCall Stmt StmtList Expr ExprList Params ParamsList Block /*MathList Math*/ CondList Cond IfStmt Args ArgsList Else CompOperator WhileStmt

// Function Prototypes
%start Program 
%%
// Function Definitions
Program: DeclList StmtList  	{								
								  $1->right = $2; // this is the root of the AST
								  $$ = $1; // this is the root of the AST
									printf("DollarDollar1");
									printf("\n");
									printf($$);
								  	printf("\n");
								}
;
// ------------------------------------ Decl (CTRL-F: -DECL) ------------------------------------- //
DeclList: |	Decl DeclList		{ // Rule Recognition of the format: int x; int y;
									$1->right = $2; //everytime it comes up, we are adding to the tree
								 	$$ = $1;
									printf("DollarDollar2");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of DeclList\n");
									printf("\n");
		} | FunDecl DeclList	{
									$1->right = $2; //everytime it comes up, we are adding to the tree
								 	$$ = $1; // this is the root of the AST
									printf("DollarDollar3");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("test\n");
								}								
;
// ------------------------------------ Decl (CTRL-F: -DECL) ------------------------------------- //
Decl:	TYPE ID LSQUAREBRACK NUMBER RSQUAREBRACK SEMICOLON	{	// Rule Recognition of the format: int x[5];									
							if(condition == TRUE){ // this is used to make sure we are in the right scope								
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Array declaration %s\n", $2);
									// Symbol Table Actions and semantic analysis
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID LSQUAREBRACK RSQUAREBRACK SEMICOLON\n");
									int inSymTab = found($2, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
									// if so, find the sum of $1 and $3
									if(inSymTab == 0){ // if the variable is not in the symbol table, add it
										addItem($2, "Array", $1, atoi($4), currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Array %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for array dec\n");
									$$ = AST_Type("Type", $1, $2); // this is the root of the AST
									printAST($$,2);
									printf("Built a subtree for array dec\n");
									printf("\n\n\n");																
							}
}
	|
TYPE ID SEMICOLON		{ 	// Rule Recognition of the format: int x;
								if(condition == TRUE){
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table Actions and semantic analysis																
									symTabAccess();									
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");
									int inSymTab = found($2, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
									if(inSymTab == 0){ // if the variable is not in the symbol table, add it
										addItem($2, "Var", $1, 0, currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable(); // this is the symbol table
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									$$ = AST_Type("Type", $1, $2);
									printAST($$,2);
									printf("Built a subtree for var dec\n");
									printf("\n\n\n");
									// IR Code Actions
									varDeclaration($2, currentScope);
								}
	}	
;

FuncType:		FUNCTYPE		{ 	printf("end of FunType\n"); // Rule Recognition of the format: int x;
								}
				| TYPE						{ 	printf("end of FunType\n");
								}
;
// ------------------------------------ FunDecl (CTRL-F: -FUNDECL) ------------------------------------- //
FunDeclList: 					{ 	printf("end of FunDeclList\n");
								}
	| FunDecl FunDeclList		{ // Rule Recognition of the format: int x; int y;
								$1->right = $2; //everytime it comes up, we are adding to the tree
								$$ = $1; // this is the root of the AST
									printf("DollarDollar4");
									printf("\n");
									printf($$);
								  	printf("\n");
								printf("end of FunDeclList\n"); // this is the root of the AST
								}
	| FunDecl					{ 	
								$$ = $1;
									printf("DollarDollar5");
									printf("\n");
									printf($$);
								  	printf("\n");
								printf("end of FunDecl\n\n");
								}
;
// ------------------------------------ FunDecl (CTRL-F: -FUNDECL) ------------------------------------- //
FunDecl: TYPE ID LPAR {addToTables($2); switchScope(currentScope, $2);} ParamsList RPAR Block SEMICOLON { // Rule recognition for functions with parameters
								if(condition == TRUE){ // this is used to make sure we are in the right scope
									printf("\n\n"); 
									printf("\n RECOGNIZED RULE: Function declaration %s\n", $2); 
									//add name to global symbol table									
									//Symbol Table Actions and semantic analysis									
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for Type ID LPAR Params RPAR BLOCK\n");
									int inSymTab = found($2, currentScope); 
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab); 
									if(inSymTab == 0){// if the variable is not in the symbol table, add it
										addItem($2, "Func", $1, 0, currentScope);
									}
									else{ // if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Func %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
									// AST Actions
									printf("Attempting to build a subtree for var dec\n"); // this is the root of the AST
									$$ = AST_Type("Type", $1, $2);
									printAST($$,2);
									printf("Built a subtree for var dec\n"); 
									printf("\n\n\n");
									// MIPS Actions
								}
		}
;

ParamsList: Params ParamsList	{// Rule recognition for parameters
									$1->right = $2;//everytime it comes up, we are adding to the tree
									$$ = $1;// this is the root of the AST
									printf("DollarDollar6");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of ParamsList\n");
								}
	| Params					{ 	// Rule recognition for parameters
									$$ = $1;// this is the root of the AST
									printf("DollarDollar7");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of Params\n\n");
								}
;
// ------------------------------------ Params (CTRL-F: -PARAMS) ------------------------------------- //
Params: TYPE ID					{	// Rule recognition for parameters
									printf("inside params\n");
									varDeclaration($2, currentScope);									
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");// Symbol Table Actions and semantic analysis
									int inSymTab = found($2, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);// checking to see if the variable is in the symbol table
									if(inSymTab == 0){// if the variable is not in the symbol table, add it
										addItem($2, "Var", $1, 0, currentScope);
									}
									else{// if the variable is in the symbol table, throw an error
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								}
		| TYPE ID COMMA {		// Rule recognition for parameters
									varDeclaration($2, currentScope);	// Symbol Table Actions and semantic analysis								
									printf("Semantic Analysis for TYPE ID SEMICOLON\n");
									int inSymTab = found($2, currentScope);// checking to see if the variable is in the symbol table
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);// if the variable is not in the symbol table, add it
									if(inSymTab == 0){
										addItem($2, "Var", $1, 0, currentScope);
									}
									else{
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								}
		| TYPE ID LSQUAREBRACK RSQUAREBRACK	{	// Rule recognition for parameters
									varDeclaration($2, currentScope);
									printf("Semantic Analysis for TYPE ID SEMICOLON\n"); // Symbol Table Actions and semantic analysis
									int inSymTab = found($2, currentScope); // checking to see if the variable is in the symbol table
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);// if the variable is not in the symbol table, add it
									if(inSymTab == 0){
										addItem($2, "Var", $1, 0, currentScope);
									}
									else{
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									}
									printf("\n\n\n");
									showAllSymTable();
									printf("\n\n\n");
								}
;
// for arguments when calling a function 
ArgsList: Args ArgsList			{// Rule recognition for parameters
									$1->right = $2;//everytime it comes up, we are adding to the tree
									$$ = $1;// this is the root of the AST
									printf("DollarDollar8");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of ArgsList\n");
								}
	| Args						{	
									$$ = $1;
									printf("DollarDollar9");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of Params\n\n");
								}
;
// ------------------------------------ Args (CTRL-F: -ARGS) ------------------------------------- //
Args:	| ID						{	// Rule recognition for parameters
									printf("inside params\n");
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON as a parameter\n");
									int inSymTab1 = found($1, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $1, inSymTab1);									
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
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $1);
										}									
									}
									showSymTable(tableHolder[findScope(currentScope)]);																		
								}
		| ID COMMA 				{	// Rule recognition for parameters
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for TYPE ID SEMICOLON as a parameter\n");
									int inSymTab1 = found($1, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $1, inSymTab1);									
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
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $1);
										}
									}
									showSymTable(tableHolder[findScope(currentScope)]);
								}
		| ExprList				{	// Rule recognition for parameters 
									printf("inside params\n");
								}
		| ExprList COMMA			{	// Rule recognition for parameters 
									printf("inside params\n");
								}		
;
// ------------------------------------ Expr (CTRL-F: -EXPR) ------------------------------------- //
Block: LCURBRACK DeclList StmtList RCURBRACK {// Rule recognition for parameters
									switchScope(currentScope, "global"); // this is used to make sure we are in the right scope					
									printf("DollarDollar10"); // this is the root of the AST
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of Block\n");									
								}
;

StmtList:	| Stmt StmtList		{ // Rule Recognition of the format: int x; int y;
									$1->right = $2;
									$$ = $1;
									printf("DollarDollar11");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of Stmt StmtList\n");
								}
			| Stmt				{ 
									$$ = $1;
									printf("DollarDollar12");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of Stmt\n");
								}
			| IfStmt StmtList			{
									$$ = $1;
									printf("DollarDollar13");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of IfStmt\n");
								}
			| WhileStmt StmtList		{
									$$ = $1;
									printf("DollarDollar14");
									printf("\n");
									printf($$);
								  	printf("\n");
									printf("end of WhileStmt\n");
								}
;
// ------------------------------------ Stmt (CTRL-F: -STMT) ------------------------------------- //
Stmt:  | ID EQ ID SEMICOLON		{ 	// Rule Recognition of the format: x = y;
									if(condition == TRUE){ 
									isUsed($1, currentScope);// Symbol Table Actions and semantic analysis
									printf("kyle test\n"); // checking to see if the variable is in the symbol table
									printf($1); 
									isUsed($3, currentScope); // for a deadcode
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Assignment statement\n"); 
									// Symbol Table Actions and semantic analysis									
									symTabAccess();
									// Semantic Analysis
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID EQ ID\n");
									int inSymTab1 = found($1, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $1, inSymTab1);
									int inSymTab2 = found($3, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $3, inSymTab2);
									// if so, find the sum of $1 and $3
									if(inSymTab1 == 1 && inSymTab2 == 1){
										// Semantic Actions
										// if the variables are in the symbol table, check to see if they are the same type
										printf("\nChecking types: \n"); 
										int typeMatch = compareTypesVars($1, $3, currentScope); // this is the function that compares the types of the variables
										if (typeMatch == 0) { // if the types do not match, throw an error
										printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
										semanticCheckPassed = 0; // this is used to make sure the semantic analysis passed
										}
										else{ // if the types do match, set $1 to the value of $3
											printf("should be setting values here\n");
											setValue($1, returnValue($3, currentScope), currentScope);
										}
									}
									// if not, throw an error
									else{
										if(inSymTab1 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $1);
										}
										if(inSymTab2 == 1){
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $3);
										}
									}
									showSymTable(tableHolder[findScope(currentScope)]); // this is the symbol table
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									$$ = AST_assignment("=", $1, $3);
									printAST($$, 2);
									printf("Built a subtree for var dec\n");
									// IR Code Actions*/
									// ---- EMIT IR 3-ADDRESS CODE ---- //
									// The IR  code is printed to a separate file
									switchFile(0);
									emitIDeqIDAssign($1, $3, currentScope);
									}
								}
	| ID EQ NUMBER SEMICOLON	{ 	// Rule Recognition of the format: x = 5;
									if(condition == TRUE){
										printf("\n\n");
										printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 				
										isUsed($1, currentScope); // maybe this is a deadcode
										// Symbol Table Actions and semantic analysis
										symTabAccess();
										// checking to see if the variable is in the symbol table
										printf("Semantic Analysis for ID EQ NUMBER SEMICOLON\n");
										int inSymTab = found($1, currentScope);
										printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
										// if so, set $1 to the value of $3
										if(inSymTab == 1){
											setValue($1, $3, currentScope);
										}
										// if not, throw an error
										else{
											printf("SEMANTIC ERROR: Var %s is not in the symbol table", $2);
										}
										setValue($1, $3, currentScope);
										printf("\n\n\n");
										showSymTable(tableHolder[findScope(currentScope)]);
										printf("\n\n\n");
										// AST Actions
										char str[50];
										sprintf(str, "%s", $3); // this converts from int to str
										printf("Attempting to build a subtree for var dec\n");
										$$ = AST_assignment("=",$1, str);
										printAST($$,2);
										printf("Built a subtree for var dec\n");
										printf("\n\n\n");
										// IR Code Actions
										if (semanticCheckPassed == 1) {
											printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");
											// ---- EMIT IR 3-ADDRESS CODE ---- //
											// The IR  code is printed to a separate file
											// MIPS Code Actions
											emitMIPSConstantIntAssignment($1, $3);									
										} else {
											printf("\n\n>>> AssignStmt Rule is SEMANTICALLY incorrect and IR code is not emitted! <<<\n\n");
										}
									}
								}
	| WRITE ID SEMICOLON		{ 	// Rule Recognition of the format: write x;
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
										int inSymTab = found($2, currentScope);
										printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
										//if so, set $1 to the value of $3
										if(inSymTab == 1){
											// AST Actions
											printf("Attempting to build a subtree for var dec\n");
											$$ = AST_Write("Write", $1, $2);
											printAST($$,2);
											printf("Built a subtree for var dec\n");
										}
										// if not, throw an error
										else{
											printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $2);
										}
										showSymTable(tableHolder[findScope(currentScope)]);
										// IR Code Actions
										//MIPS Code actions
										emitMIPSWriteId($2);
										isUsed($2, currentScope);
									}
								}
	| ID EQ Expr SEMICOLON	{	// Rule recognition for expression statement

								if(condition == TRUE){
									isUsed($1, currentScope);									
									printf("inside expression statement\n");
  									printf("\n RECOGNIZED RULE: Expression statement\n");									
									// Symbol Table Actions and semantic analysis
									symTabAccess();
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID EQ Expr SEMICOLON\n");
									int inSymTab = found($1, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
									// if so, set $1 to the value of the expression
									if(inSymTab == 1){
										sprintf(strSum, "%d", currentSum);
										// Symbol Table Actions
										char str[50];
										sprintf(str, "%s", $3); // this converts from struct to str
										setValue($1, strSum, currentScope);
										//showAllSymTable();
										printf("error here\n");
										currentSum = 0;
									}
									// if not, throw an error
									else{
										printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $2);
									}									
									showSymTable(tableHolder[findScope(currentScope)]);
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									$$ = AST_assignment("=",$1, AST_assignment(operator,$1,$3));
									printAST($$,2);
									printf("Built a subtree for var dec\n");
									// MIPS Code Actions
									emitMIPSConstantIntAssignment($1, strSum);


									//reset expression variables
									for(int i = 0; i < numExp; i++){
										globalvar[i] = 0;
									}
									//globalvar[0] = '\0';
									numExp = 0;
									
								}
								}
	| ID LSQUAREBRACK NUMBER RSQUAREBRACK EQ Expr SEMICOLON		{ 	// Rule Recognition of the format: x[5] = 5 + 6;
									if(condition == TRUE){
									isUsed($1, currentScope);
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Array statement\n");
									// Symbol Table Actions
									printf("\n\n\n");
									showSymTable(tableHolder[findScope(currentScope)]);
									//showAllSymTable();
									printf("\n\n\n");
									// checking to see if the variable is in the symbol table
									printf("Semantic Analysis for ID LSQUAREBRACK NUMBER RSQUAREBRACK EQ Expr SEMICOLON\n");
									int inSymTab = found($1, currentScope);
									printf("looking for %s in symtab - found: %d\n\n\n", $2, inSymTab);
									// if so, set $1 to the value of the expression
									if(inSymTab == 1){
										sprintf(strSum, "%d", currentSum);
										// Symbol Table Actions
										char str[50];
										sprintf(str, "%s", $3); // this converts from struct to str
										printf("error here\n");
										currentSum = 0;
									}
									// if not, throw an error
									else{
										printf("SEMANTIC ERROR: Var %s is not in the symbol table\n", $2);
									}
									showSymTable(tableHolder[findScope(currentScope)]);
									// AST Actions
									printf("Attempting to build a subtree for var dec\n");
									$$ = AST_assignment("=",$1, AST_assignment(operator,$1,$3));
									printAST($$,2);
									printf("Built a subtree for var dec\n");
									// MIPS Code Actions
									emitMIPSConstantIntAssignment($1, strSum);
								}
								}
		| ID LPAR {switchScope(currentScope, $1);} ArgsList RPAR {switchScope(currentScope, "global");} SEMICOLON		{ 	// Rule Recognition of function calls
									if(condition == TRUE){ // this is used to make sure we are in the right scope
									isUsed($1, currentScope);// Symbol Table Actions and semantic analysis
									printf("\n\n");
									printf("\n RECOGNIZED RULE: Function call statement\n");
									}									
		}
		| RETURN Expr SEMICOLON		{// Rule Recognition of the format: return 5 + 6;
			if(condition == TRUE){
			// Rule Recognition of the format: return 5 + 6;
			}
		}
		| RETURN ID SEMICOLON		{ 	
			if(condition == TRUE){ // this is used to make sure we are in the right scope
				// Rule Recognition of the format: return x;
			}
		}
		| RETURN SEMICOLON			{ 	
			if(condition == TRUE){
			// Rule Recognition of the format: return;
			}
		}
;

// ------------------------------------ Expr (CTRL-F: -EXP) ------------------------------------- //
ExprList: Expr ExprList { // Rule Recognition of the format: int x; int y;
            $1->right = $2; //everytime it comes up, we are adding to the tree
            $$ = $1; // this is the root of the AST
        }
        | Expr { // Rule Recognition of the format: int x;
            $$ = $1;
        };
Expr: Expr PLUS_OP Expr {// Rule Recognition of the format: 5 + 6;
		printAdd();// IR Code Actions

		
		emitAdditionMIPS(globalvar[0], globalvar[1]);
		
	}
    
    | Expr MINUS_OP Expr {// Rule Recognition of the format: 5 - 6;
		printSub();
    }
    | Expr MULT_OP Expr {// Rule Recognition of the format: 5 * 6;
		printMult();
    }
    | Expr DIV_OP Expr {// Rule Recognition of the format: 5 / 6;
		printDiv();
    }
    | Expr MOD_OP Expr {// Rule Recognition of the format: 5 % 6;
		printMod();
    }
     | ID {// Rule Recognition of the format: x;
		printf("\n\n");// Symbol Table Actions and semantic analysis
		printf("\n RECOGNIZED RULE: an ID\n");// checking to see if the variable is in the symbol table

    }
    | NUMBER {// Rule Recognition of the format: 5;
		// the whole purpose of this is to have variables you can then use
		// in the MIPS code generation
		// make an if statement that checks if we are in an expression

		
		globalvar[numExp] = atoi($1);
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
    }
    | LPAR Expr RPAR {// Rule Recognition of the format: (5);
    }
	;
FunCallList: | FunCall FunCallList {// Rule Recognition of the format: int x; int y;
									$1->right = $2;
									$$ = $1;		
									}
			 | FunCall			{// Rule Recognition of the format: int x;
								$$ = $1;
								}
;

// should we move it to the stmtlist? 
FunCall: ID LPAR {switchScope(currentScope, $2);} ArgsList RPAR SEMICOLON {
		// need to switch out of the scope at some point
}
;
WhileStmt: WHILE {inWhile = TRUE;} LPAR CondList RPAR Block {// Rule Recognition of the format: while (x < 5) { x = x + 1; }
	condition = TRUE;// Symbol Table Actions and semantic analysis
	printf("RECOGNIZED WHILE STATEMENT\n");// checking to see if the variable is in the symbol table
	inWhile = FALSE;// if so, find the sum of $1 and $3
}
;
//This is a midaction rule. It is the only problem. we will Figure it out later.
IfStmt: IF LPAR CondList RPAR Block {condition = TRUE;} Else {
// If the condition is true, a global variable is set to true, 
// which allows every statement to be executed.
// If it is false, no statements will execute until the end of the block is reached.
} 
;
Else: | ELSE Block {// Rule Recognition of the format: else { x = x + 1; }
}
| ELSE IfStmt {// Rule Recognition of the format: else if (x < 5) { x = x + 1; }
}
;
CondList: Cond {// Rule Recognition of the format: x < 5
			$$ = $1;
		 }
		 | Cond Conj CondList  //Conj is && or ||
		 {
			$1->right = $3;
			$$ = $1;
		 }
;
Conj: AND_OP// Rule Recognition of the format: &&
	 | OR_OP;// Rule Recognition of the format: ||
CompOperator: IS_EQ {strcpy(currentOp,$1);} 		// ==
			| LT {strcpy(currentOp,$1);}        // <
			| GT {strcpy(currentOp,$1);}        // >
			| LS_EQ {strcpy(currentOp,$1);}     // <=
			| GR_EQ {strcpy(currentOp,$1);}     // ?=
			| NOT_EQ {strcpy(currentOp,$1);}    // !=

Cond: | ID CompOperator ID {// Rule Recognition of the format: x < 5
	printf("before while loop %d\n", inWhile);// Symbol Table Actions and semantic analysis
	if(inWhile == TRUE){
		printf("in while loop %s %s %s %s\n", $1, currentOp, $3, currentScope);
		emitWhile($1, currentOp, $3, currentScope, 0, 0);
	}
	int inSymTab1 = found($1, currentScope);// checking to see if the variable is in the symbol table
	printf("looking for %s in symtab - found: %d\n\n\n", $1, inSymTab1);
	int inSymTab2 = found($3, currentScope);
	printf("looking for %s in symtab - found: %d\n\n\n", $3, inSymTab2);
	if(inSymTab1 == 1 && inSymTab2 == 1){
		// Semantic Actions
		// if the variables are in the symbol table, check to see if they are the same type
		printf("\nChecking types: \n");
		int typeMatch = compareTypesVars($1, $3, currentScope);
		if (typeMatch == 0) {
		printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		semanticCheckPassed = 0;
		}
		else{// if the types do match, set $1 to the value of $3
			char str1[50];
			char str2[50];
			sprintf(str1, "%s", $1); // this converts from int to str
			sprintf(str2, "%s", $3); // this converts from int to str
			printf("Attempting to build a subtree for var dec\n");
			$$ = AST_assignment("==",str1, str2);// this is the root of the AST
			printAST($$,2);
			printf("Built a subtree for var dec\n");
		}
	}
	//if so, check to see if they are equal
	if(semanticCheckPassed == 1){// if the types do match, set $1 to the value of $3
		if(compareInts($2, atoi(returnValue($1, currentScope)), atoi(returnValue($3, currentScope)))){    
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
}

| ID CompOperator NUMBER {// Rule Recognition of the format: x < 5
	printf("before while loop %d\n", inWhile);
	if(inWhile == TRUE){
		printf("in while loop %s %s %s %s\n", $1, currentOp, $3, currentScope);
		emitWhile($1, currentOp, $3, currentScope, 0, 1);
	}
	// check to see if the variables are in the symbol table
	int inSymTab1 = found($1, currentScope);
	printf("looking for %s in symtab - found: %d\n\n\n", $1, inSymTab1);
	if(inSymTab1 == 1){
		// Semantic Actions
		// if the variables are in the symbol table, check to see if they are the same type
		printf("\nChecking types: \n");
		int typeMatch = compareTypesVars($1, $3, currentScope);
		if (typeMatch == 0) {
		printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
		semanticCheckPassed = 0;
		}
		else{
			char str1[50];
			char str2[50];
			sprintf(str1, "%s", $1); // this converts from int to str
			sprintf(str2, "%s", $3); // this converts from int to str
			printf("Attempting to build a subtree for var dec\n");
			$$ = AST_assignment("==",str1, str2);
			printAST($$,2);
			printf("Built a subtree for var dec\n");
		}
	}
	//if so, check to see if they are equal
	if(semanticCheckPassed == 1){// if the types do match, set $1 to the value of $3
		if(compareInts($2, atoi(returnValue($1, currentScope)), atoi($3))){
			printf("Condition passed.\n");// if so, return true
			condition = TRUE;
		}
		else{// if not, return false
			printf("Condition failed.\n");
			condition = FALSE;
		}
		// if not, return false
	}
}
;
%%

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
	//sleep(2); //sleep for 2 seconds to allow the user to see the output
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