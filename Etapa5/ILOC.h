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


int countLines(char *string, int size);

char * gerar_label();
char* newTemp();
char* newLabel();
char* concatCode(char *dest, char *source);

char *loadMemRegToReg(char *reg1, char *reg2);
char *storeTempToVariable(char *temp, int depth, int position);
char *storeVariableToTemp(char *temp, int depth, int position);
char *desvio_lbl_jumpI(char* lbl_destino);
char *storeVariableRegOffsetToTemp(char *temp,char *regoffset,int depth);
char *storeTempToVariableRegOffset(char *temp,char *regoffset,int depth);
char *Or_CC_Operation(char *reg1, char *reg2, char *dest);
char* loadValueToTemp(int value, char *temp);
char *AND_CC_Operation(char *reg1, char *reg2, char *dest);
char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest);
char *binaryOperationInteger(char *operation, char *reg1, int value, char *dest);

char *copyRegToReg(char *reg1, char *reg2);
