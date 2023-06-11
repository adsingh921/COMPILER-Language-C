//This file emits MIPS code. It includes the standard library <stdio.h> and <string.h>. 
//It uses 3 files to write the MIPS code - MIPScode.asm, MIPSfuncs.asm and MIPSfinal.asm


#include <stdio.h>
#include <string.h>
// Set of functions to emit MIPS code
FILE * MIPScode;
FILE * MIPSfuncs;
FILE * MIPSfinal;
int regCount = 1;

struct Entry buffer[100][2];

struct var_table_entry {
    char* id;
    int addr;
};

int reg_table[16] = {0}; // 0 = free, 1 = used
//logic for finding the first free register
int findReg() {
    for (int i = 0; i < sizeof(reg_table); i++) {
        if (reg_table[i] == 0) {
            reg_table[i] = 1;
            return i + 16; // MIPS registers start at 16?
        }
    }
    return -1; // if no registers are free
}

void addEndLoop(){// Adds the endloop function to the MIPSfuncs.asm file
    fprintf(MIPSfuncs, "endloop:\n"); // function header (e.g. 'func:')
    fprintf(MIPSfuncs, "\n\tjal next       # return to main\n\n");
    printf("MIPS Created.\n\n\n");
}

void  initAssemblyFile(){
    // Creates a MIPS file with a generic header that needs to be in every file
    MIPScode = fopen("MIPScode.asm", "w");  
    
    fprintf(MIPScode, ".text\n");
    fprintf(MIPScode, "main:\n");
    fprintf(MIPScode, "# -----------------------\n");

    fclose(MIPScode);

    MIPSfuncs = fopen("MIPSfuncs.asm", "w");  
    addEndLoop();
    fclose(MIPSfuncs);
}

int regFound(char str[]){
	return 0;
}
void emitMIPSAssignment(char * id1, char * id2){// id1 = id2
    MIPScode = fopen("MIPScode.asm", "a");  
  fprintf(MIPScode, "lw $t4,%s\n", id1);
  fprintf(MIPScode, "lw $t5,%s\n", id2);
  fprintf(MIPScode, "move $t4,$t5\n");
  fclose(MIPScode);
}

void emitMIPSConstantIntAssignment(char * id1, char * id2){// id1 = id2
    MIPScode = fopen("MIPScode.asm", "a");  
    fprintf(MIPScode, "li $t%d,%s\n", regCount, id2);
    regCount++;
    fclose(MIPScode);
}

void emitMIPSWriteId(char * id){// print id
    MIPScode = fopen("MIPScode.asm", "a");
    fprintf(MIPScode, "move $a0,%s\n", "$t2");
    fclose(MIPScode);
}

void emitEndOfAssemblyCode(){// Adds the endloop function to the MIPSfuncs.asm file
    // We also need to combine the two files into one
    MIPSfinal = fopen("MIPSfinal.asm", "a");

    fprintf(MIPSfinal, "# -----------------\n");
    fprintf(MIPSfinal, "#  Done, terminate program.\n\n");
    fprintf(MIPSfinal, "li $v0,1   # call code for terminate\n");
    fprintf(MIPSfinal, "syscall      # system call (terminate)\n");
    fprintf(MIPSfinal, "li $v0,10   # call code for terminate\n");
    fprintf(MIPSfinal, "syscall      # system call (terminate)\n");
    fprintf(MIPSfinal, ".end main\n");
    fclose(MIPSfinal);
}

void emitWhile(char val1[50], char condition[5], char val2[50], char scope[50], int first, int second){
    MIPSfuncs = fopen("MIPSfuncs.asm", "a");
    fprintf(MIPSfuncs, "\n# while loop");
    fprintf(MIPSfuncs, "\nWhileLoop:\n");
    // load temp registers
    if (first == 0 && second == 0) { // id and id
        fprintf(MIPSfuncs, "\n\tlw $t0, %s%s              # load the variable into $t0", scope, val1);//lw $t0, var1
        fprintf(MIPSfuncs, "\n\tlw $t1, %s%s              # load the variable into $t1", scope, val2);//lw $t1, var2
    }
    else if (first == 0 && second == 1) { //id and num
        fprintf(MIPSfuncs, "\n\tlw $t0, %s%s              # load the variable into $t0", scope, val1);//lw $t0, var1
        fprintf(MIPSfuncs, "\n\tli $t1, %s               # load the number into $t1", val2);//li $t1, num
    }
    //check condition
    if(strcmp(condition,"==") == 0){ //while ( _ == _ )
        fprintf(MIPSfuncs, "\n\tbne $t0, $t1, endloop   # break loop if true \n", val1, val2);//bgt $t0, $t1, endloop
    }
    else if(strcmp(condition,"!=") == 0){ //while ( _ < _ )
        fprintf(MIPSfuncs, "\n\tbeq $t0, $t1, endloop   # break loop if true \n", val1, val2);//bgt $t0, $t1, endloop
    }
    else if(strcmp(condition,"<") == 0){ //while ( _ < _ )
        fprintf(MIPSfuncs, "\n\tbgt $t0, $t1, endloop   # break loop if true \n",val1,val2);//bgt $t0, $t1, endloop
    }
    else if(strcmp(condition,"<=") == 0){ //while ( _ > _ )
        fprintf(MIPSfuncs, "\n\tbge $t0, $t1, endloop   # break loop if true \n",val1,val2);//bge $t0, $t1, endloop
    }
    else if(strcmp(condition,">") == 0){ //while ( _ > _ )
        fprintf(MIPSfuncs, "\n\tblt $t0, $t1, endloop   # break loop if true \n",val1,val2);//blt $t0, $t1, endloop
    }
    else if(strcmp(condition,">=") == 0){ //while ( _ > _ )
        fprintf(MIPSfuncs, "\n\tble $t0, $t1, endloop   # break loop if true \n",val1,val2);//ble $t0, $t1, endloop
    }

    fprintf(MIPSfuncs, "\n\tj WhileLoop       # loop back\n\n");// jump back to loop
    printf("While Loop Created.\n\n\n");// print to console
    fclose(MIPSfuncs);
}

void emitSubtractionMIPS(int left_operand, int right_operand) { // left - right
    MIPScode = fopen("MIPScode.asm", "a");  
    printf("You made it into the emit mips function\n");
    fprintf(MIPScode, "sub $t%d,%d,%d\n", regCount, left_operand, right_operand);// sub $t0,$t1,$t2
    regCount++;
    fclose(MIPScode);
}

void emitAdditionMIPS(int left_operand, int right_operand) { // left + right
    MIPScode = fopen("MIPScode.asm", "a");  
    printf("You made it into the emit mips function\n");
    fprintf(MIPScode, "add $t%d,%d,%d\n", regCount, left_operand, right_operand);// add $t0,$t1,$t2
    regCount++;
    fclose(MIPScode);
}

void emitMultiplicationMIPS(int left_operand, int right_operand) {// left * right
    MIPScode = fopen("MIPScode.asm", "a"); 
    printf("You made it into the emit mips function\n");
    fprintf(MIPScode, "mul $t%d,%d,%d\n", regCount, left_operand, right_operand);// mul $t0,$t1,$t2
    regCount++;
    fclose(MIPScode);
}

void emitDivisionMIPS(int left_operand, int right_operand) { // left / right
    MIPScode = fopen("MIPScode.asm", "a"); 
    printf("You made it into the emit mips function\n");
    fprintf(MIPScode, "div $t%d,%d,%d\n", regCount, left_operand, right_operand);// div $t0,$t1,$t2
    regCount++;
    fclose(MIPScode);
}

void printAdd() { // prints the addition expression to the MIPScode.asm file
    MIPScode = fopen("MIPScode.asm", "a"); // append to file
    fprintf(MIPScode, "Additon Expression\n");// print to file
    fclose(MIPScode);
}

void printSub() {// prints the subtraction expression to the MIPScode.asm file
    MIPScode = fopen("MIPScode.asm", "a"); 
    fprintf(MIPScode, "Subtraction Expression\n");
    fclose(MIPScode);
}

void printMult() {// prints the multiplication expression to the MIPScode.asm file
    MIPScode = fopen("MIPScode.asm", "a"); 
    fprintf(MIPScode, "Multiplication Expression\n");
    fclose(MIPScode);
}

void printDiv() {// prints the division expression to the MIPScode.asm file
    MIPScode = fopen("MIPScode.asm", "a"); 
    fprintf(MIPScode, "Division Expression\n");
    fclose(MIPScode);
}

void printMod() {// prints the modulus expression to the MIPScode.asm file
    MIPScode = fopen("MIPScode.asm", "a"); 
    fprintf(MIPScode, "Modulus Expression\n");
    fclose(MIPScode);
}