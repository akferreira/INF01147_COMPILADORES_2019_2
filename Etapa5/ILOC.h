#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "symbol_table.h"

#define TEMP_NAME_SIZE 15
#define LOAD_INST_SIZE 50
#define STORE_INST_SIZE 50
#define OP_INST_SIZE 50


struct operacao
{
    char* operandor;
    char* operando1;
    char* operando2;
    char* destino;

};
typedef struct operacao OPERACAO;



void operacoesBinaria(char operandor, SYMBOL_INFO operando1, SYMBOL_INFO operando2);
SYMBOL_INFO lookup(ast_node *entrada);





char* newTemp();
char* newLabel();
char* concatCode(char *dest, char *source);

char *storeTempToVariable(char *temp, int depth, int position);
char *storeVariableToTemp(char *temp, int depth, int position);
char* loadValueToTemp(int value, char *temp);

char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest);
