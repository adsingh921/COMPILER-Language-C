#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#include "symbolTable.h"
//These are the header files needed for the program.
FILE * IRcode;
FILE * IRFuncs;
int currRegister;

currRegister = 0; 

// declare global array of strings to store the IR code
//These are global variables that will be used throughout the program.
int varCount;
char varList[50][50];
char fileSwitch[50];

// ---- Functions to handle IR code emissions ---- //
//These are global arrays that will store variable names and the IR code.
void switchFile(int file){
    switch (file){
        case 0: sprintf(fileSwitch, "IRcode.ir"); 
        break;
        case 1: sprintf(fileSwitch, "IRFuncs.ir"); 
        break;
    }
}
//This function will set the fileSwitch variable to either "IRcode.ir" or "IRFuncs.ir" depending on the argument passed to the function.
void  initIRcodeFile(){
    IRcode = fopen("IRcode.ir", "w");
    fprintf(IRcode, "\n\n#### IR Code ####\n\n");
    fclose(IRcode);

    IRFuncs = fopen("IRFuncs.ir", "w");
    fprintf(IRcode, "\n\n#### IR Functions ####\n\n");
    fclose(IRFuncs);
}
// this function will perform computations
//This function initializes two files for the IR code and IR functions.
void emitBinaryOp(char op[1], const char* id1, const char* id2){

    IRcode = fopen(fileSwitch, "a");
    fprintf(IRcode, "T%d = %s %s %s\n", currRegister, id1, op, id2);
    fclose(IRcode);
    printf("IR Code generated.\n");
    currRegister++;

}

//This function will emit IR code for a binary operation.
void emitIDeqIDAssign(char * id1, char * id2, char scope[50]){
    IRcode = fopen(fileSwitch, "a");
    fprintf(IRcode, "T%d = T%d\n", currRegister, currRegister);
    printf("problem3.\n");
    fclose(IRcode);
    printf("IR Code generated.\n");
}

//This function will emit IR code for an assignment
void varDeclaration(char id[50], char scope[50]) {
    // add the variable into the list of variables
    strcpy(varList[varCount], id); // add it to names array
    // this is hardcoded because we haven't used the switchFile function yet
    sprintf(fileSwitch, "IRcode.ir"); 
    IRcode = fopen(fileSwitch, "a");
    char str[50];
    strcpy(str, id);
    fprintf(IRcode, "T%d = %s\n", varCount, str);
    fclose(IRcode);
    varCount++;
    printf("IR Code generated.\n");
}
//This function will declare a variable by adding it to the varList array and emitting IR code.
void emitWriteId(char * id){

}
//This function will emit IR code to write an identifier to the console.
void getNextTemp(char * temp){
    // This is the temporary approach, until temporary variables management is implemented
    //strcpy(temp, "T2");
}
//This function will get the next temporary variable.
void emitAssignment(char * id1, char * id2){
    printf("Problem of managing registers\n");
    printf("1. Find an open register\n");
    printf("2. Assign the register to the variable\n");
    printf("3. When the variable is no longer used, free the register\n");
    printf("4. When a new variable is assigned, find an open register\n");
    printf("5. If no open registers, then find the least recently used register and free it\n");
    printf("6. Assign the new variable to the register\n");
    printf("7. Repeat");
}

int sumOfInts(int a, int b){
    return a + b;
}

void emitIRAdd(char* op, char* arg1, char* arg2, int result) {
    FILE* fp = fopen("IRCode.ir", "a");
    fprintf(fp, "%s %s %s %d\n", op, arg1, arg2, result);
    fclose(fp);
}