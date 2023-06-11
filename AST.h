//Abstract Syntax Tree Implementation
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//define the struct for the AST
struct AST{
	char nodeType[50];
	char LHS[50];
	char RHS[50];
	struct AST * left;
	struct AST * right;
};

//create a new AST for an assignment statement
struct AST * AST_assignment(char nodeType[50], char LHS[50], char RHS[50]){
	struct AST* ASTassign = malloc(sizeof(struct AST));
	strcpy(ASTassign->nodeType, nodeType);
	strcpy(ASTassign->LHS, LHS);
	strcpy(ASTassign->RHS, RHS);

	return ASTassign;
	
}
// Create a new AST node for a binary expression
struct AST * AST_BinaryExpression(char nodeType[50], char LHS[50], char RHS[50]){
	struct AST* ASTBinExp = malloc(sizeof(struct AST));
	strcpy(ASTBinExp->nodeType, nodeType);
	strcpy(ASTBinExp->LHS, LHS);
	strcpy(ASTBinExp->RHS, RHS);
	return ASTBinExp;
}

//this function creates a subtree for a var declaration
struct AST * AST_Type(char nodeType[50], char LHS[50], char RHS[50]){

	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
}
// Create a new AST node for a function
struct AST * AST_Func(char nodeType[50], char LHS[50], char RHS[50]){
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->RHS, RHS);
		
	return ASTtype;
	
}
// Create a new AST node for a write statement
struct AST * AST_Write(char nodeType[50], char LHS[50], char RHS[50]){
	struct AST* ASTtype = malloc(sizeof(struct AST));
	strcpy(ASTtype->nodeType, nodeType);
	strcpy(ASTtype->LHS, LHS);
	strcpy(ASTtype->LHS, RHS);
		
	return ASTtype;
	
}
// Helper function to print dots for indentation
void printDots(int num)
{
	for (int i = 0; i < num; i++)
		printf("  -->   ");
}
// Recursively print the AST
void printAST(struct AST* tree, int level){
		if (tree == NULL) return;
		printDots(level);
		printf("%s\n", tree->nodeType);
		printDots(level);
		//if LHS and RHS are not nodeType (do the code below)
		printf("%s %s\n", tree->LHS, tree->RHS);
		if(tree->left != NULL) printAST(tree->left, level+1); else return;
		if(tree->right != NULL) printAST(tree->right, level+1); else return;
}

// Struct for an AST variable
typedef struct {
    char* name;
} ASTVariable;

// Create a new AST variable node
ASTVariable* ast_variable(char* name) {
    ASTVariable* node = (ASTVariable*)malloc(sizeof(ASTVariable));
    node->name = (char*)malloc(strlen(name) + 1);
    strcpy(node->name, name);
    return node;
}