//Symbol table header
#include <string.h>
#include <stdio.h>

// Define boolean type
#define bool int
#define FALSE 0
#define TRUE 1

// Global Variables
int dictCount;
char freeSymTab[50];

// This is a very simplistic implementation of a symbol table
// You will use this as reference and build a much more robust one
 
struct Entry
{
	int itemID;
	char itemName[50];  //the name of the identifier
	char itemKind[8];  //is it a function or a variable?
	char itemType[8];  // Is it int, char, etc.?
	char itemValue[50]; // Value of the item
 	int arrayLength;	// length of the array
	int paramsNum;		// number of parameters
	bool used;			// has the item been used?
};
 // Struct for symbol table                                                                        
struct SymbolTable
{
    struct Entry entries[100]; // array of entries
    int numEntries;     // number of entries in the array
	char scope[50];     // global, or the name of the function
	int symTabIndex;
};

struct SymbolTable tableHolder[10]; // array of 10 symbol tables

void addSymbolTable(){
	// search entries for a free entry. add symbol table and change scope
}
//creating our arrays for our symbol tables
struct Entry globalSymTab[100];
struct Entry func1[100];
struct Entry func2[100];
struct Entry func3[100];
struct Entry func4[100];
struct Entry func5[100];

//creating our dictionary
struct dictionaryItems
{
	char scope[50];
	char funcName[50];
};
struct dictionaryItems dictionary[100];
// Add function name to the symbol table
void addFunc(char funcName[100]){
	//struct Entry funcName;
	//strcpy(funcName.scope, funcName);
}
// Define global variables
int tableIndex = 1;
int SYMTABSIZE = 20;
// Function to print a message when symbol table is accessed
void symTabAccess(void){
	printf("::::> Symbol table accessed.\n");
}
// Function to find a scope in the symbol table
int findScope(char scope[50]){
	printf("scope argument: %s\n", scope);
	for(int i=0; i<sizeof(tableHolder); i++){
		if(strcmp(tableHolder[i].scope, scope) == 0){
			return i;
		}
	}
	return -1;
}
// Function to add an item to the symbol table
void addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50]){
		int symTab = findScope(scope);
		int index = tableHolder[symTab].symTabIndex;
		tableHolder[symTab].entries[index].itemID = index;
		strcpy(tableHolder[symTab].entries[index].itemName, itemName);
		strcpy(tableHolder[symTab].entries[index].itemKind, itemKind);
		strcpy(tableHolder[symTab].entries[index].itemType, itemType);
		tableHolder[symTab].entries[index].arrayLength = arrayLength;
		strcpy(tableHolder[symTab].scope, scope);
		// If the entry in the symbol table at the specified index has kind "Array"
		if(strcmp(tableHolder[symTab].entries[index].itemKind, "Array") == 0){
			// print 
			// Create a new string called "array" with a maximum length of 50
			char array[50] = "";
			// Loop through the array length and add the string "NULL, " to "array"
			for(int i = 0; i < tableHolder[symTab].entries[index].arrayLength - 1; i++){
				strcat(array, "NULL, ");
			}
			// Add the string "NULL" to the end of "array"
			strcat(array, "NULL");
			// Copy the string "array" into the "itemValue" field of the symbol table entry
			strcpy(tableHolder[symTab].entries[index].itemValue, array);
		}
		// If the entry in the symbol table at the specified index has any other kind
		else{
			// Copy the string "NULL" into the "itemValue" field of the symbol table entry
			strcpy(tableHolder[symTab].entries[index].itemValue, "NULL");
		}
		//we have to make this individual for each table
		tableHolder[symTab].symTabIndex++;
		tableHolder[symTab].numEntries++;
}
//make new function for adding values to variables
void setValue(char itemName[50], char itemValue[50], char scope[50]){
	// symTabItemsSize works by dividing the size of the array by the size of each element
	int symTab = findScope(scope);
    for(int i=0; i<tableHolder[symTab].numEntries; i++){
        if(strcmp(tableHolder[symTab].scope, scope) == 0 &&
           strcmp(tableHolder[symTab].entries[i].itemName, itemName) == 0){
            strcpy(tableHolder[symTab].entries[i].itemValue, itemValue);
            tableHolder[symTab].entries[i].itemValue[49] = '\0';
        }
    }
}
// Define a new function called "printArrayValue" that takes in two strings as arguments
void printArrayValue(char itemName[50], char scope[50]){
	int symTab = findScope(scope);
	for(int i=0; i<tableHolder[symTab].numEntries; i++){
		if(strcmp(tableHolder[symTab].scope, scope) == 0 &&
		   strcmp(tableHolder[symTab].entries[i].itemName, itemName) == 0){
			for(int j=0; j<tableHolder[symTab].entries[i].arrayLength; j++){
				printf("%7s\n", tableHolder[symTab].entries[i].itemValue[j]);
			}
		}
	}
}
// return the value of a variable
// Define a new function called "returnValue" that takes in two strings as arguments and returns a string
char* returnValue(char itemName[50], char scope[50]){
	int symTab = findScope(scope);

	for(int i=0; i<sizeof(tableHolder); i++){
		int str1 = strcmp(tableHolder[symTab].scope,scope);
		int str2 = strcmp(tableHolder[symTab].entries[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return tableHolder[symTab].entries[i].itemValue;
		}
	}
	return "NULL";
}
// return the value of a variable
char* returnType(char itemName[50], char scope[50]){
	int symTab = findScope(scope);

	for(int i=0; i<sizeof(tableHolder); i++){
		int str1 = strcmp(tableHolder[symTab].scope, scope);
		int str2 = strcmp(tableHolder[symTab].entries[i].itemName, itemName);
		if( str1 == 0 && str2 == 0){
			return tableHolder[symTab].entries[i].itemType;
		}
	}
	return "NULL";
}
//showing the symbol table
void showSymTable(struct SymbolTable symTable){
	printf("itemID    itemName    itemKind    itemType     itemValue     ArrayLength    itemScope    used\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	for (int i=0; i < symTable.numEntries; i++){
		if(strcmp(symTable.entries[i].itemKind, "Array") == 0){
			printf("%5d %10s  %10s  %10s %13s %10d %15s %10d \n",symTable.entries[i].itemID, symTable.entries[i].itemName, 
			symTable.entries[i].itemKind, symTable.entries[i].itemType, symTable.entries[i].itemValue, 
			symTable.entries[i].arrayLength, symTable.scope, symTable.entries[i].used);
		}
		else if(strcmp(symTable.entries[i].itemKind, "function") == 0 || strcmp(symTable.entries[i].itemKind, "procedure") == 0){
			printf("%5d %10s  %10s  %10s %13s %10s %15s %10d \n",symTable.entries[i].itemID, symTable.entries[i].itemName, 
			symTable.entries[i].itemKind, symTable.entries[i].itemType, symTable.entries[i].itemValue, 
			"NULL", symTable.scope, symTable.entries[i].used);
		}
		else{
			printf("%5d %10s  %10s  %10s %13s %10d %15s %10d \n",symTable.entries[i].itemID, symTable.entries[i].itemName, 
			symTable.entries[i].itemKind, symTable.entries[i].itemType, symTable.entries[i].itemValue, 
			symTable.entries[i].arrayLength, symTable.scope, symTable.entries[i].used);
		}
		
	}
	printf("-----------------------------------------------------------------------------------------------\n");
}
void showAllSymTable(){
	for(int i=0; i<tableIndex; i++){
		showSymTable(tableHolder[i]);
	}
}
int found(char itemName[50], char scope[50]){
	// Lookup an identifier in the symbol table
	// return TRUE or FALSE
	int symTab = findScope(scope);
	for(int i=0; i<100; i++){
		int str1 = strcmp(tableHolder[symTab].entries[i].itemName, itemName);
		int str2 = strcmp(tableHolder[symTab].scope,scope);
		if( str1 == 0 && str2 == 0){
			return 1; // found the ID in the table
		}
	}
	return 0;
}
// Define a new function called "getVariableType" that takes in two strings as arguments and returns a string
const char* getVariableType(char itemName[50], char scope[50]){
	int symTab = findScope(scope);
	for(int i=0; i<SYMTABSIZE; i++){
		int str1 = strcmp(tableHolder[symTab].entries[i].itemName, itemName);
		int str2 = strcmp(tableHolder[symTab].scope,scope); 
		if( str1 == 0 && str2 == 0){
			return tableHolder[symTab].entries[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

int compareTypesConst(const char* type1, const char* type2, const char* scope) {
	return 1; 
}

int compareTypesVars(const char* type1, const char* type2, const char* scope) {
	return 1; 
}
void addToTables(char nameGiven[50]){
	if(tableIndex < SYMTABSIZE){
			strcpy(tableHolder[tableIndex].scope, nameGiven);
			tableIndex++;
			tableHolder[tableIndex].symTabIndex = 0;
			return;
	}
}
// switch scopes
void switchScope(char currentScope[50], char scope[50]){
	strcpy(currentScope, scope);
}
// return the value of a variable
int findItemID(char itemName[100], char scope[100]) {
	int symTab = findScope(scope);
	for(int i=0; i<tableHolder[symTab].numEntries; i++){
		int str1 = strcmp(tableHolder[symTab].entries[i].itemName, itemName); 
		
		if( str1 == 0 ) {
			return tableHolder[symTab].entries[i].itemID;
		}
	}
	return 0;
}
//checking outcome of condition
bool checkCondOutcome(char* dollar){
	return TRUE;
}
int compareInts(char type[50], int a, int b){
	printf("type: %s, a: %d, b: %d", type, a, b);
	if(!strcmp(type, "==")){
		if(a == b){
			return 1;
		}
	}
	else if(!strcmp(type, "!=")){
		if(a != b){
			return 1;
		}
	}
	else if(!strcmp(type, "<")){
		if(a < b){
			return 1;
		}
	}
	else if(!strcmp(type, ">")){
		if(a > b){
			return 1;
		}
	}
	else if(!strcmp(type, "<=")){
		if(a <= b){
			return 1;
		}
	}
	else if(!strcmp(type, ">=")){
		if(a >= b){
			return 1;
		}
	}
	return 0;
}
//This function is used to mark a symbol table entry as "used" when a corresponding identifier is encountered in the source code. 
//The used field can be used later to determine whether or not an identifier is actually used in the program and 
//to generate appropriate warnings or errors if necessary.
void isUsed(char itemName[50], char scope[50]){
	int symTab = findScope(scope);
	for(int i=0; i<tableHolder[symTab].numEntries; i++){
		int str1 = strcmp(tableHolder[symTab].entries[i].itemName, itemName); 
		if( str1 == 0 ) {
			tableHolder[symTab].entries[i].used = TRUE;

		}
	}
	return;
}
