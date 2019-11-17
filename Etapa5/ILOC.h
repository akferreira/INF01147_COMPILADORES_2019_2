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

struct nodo
{
    char* instrucao;
    struct nodo* proximo;
};
typedef struct  nodo LISTA_INSTRUCOES;




void Imprimir_codigo();
void operacoesBinaria(char operandor, SYMBOL_INFO operando1, SYMBOL_INFO operando2);
SYMBOL_INFO lookup(ast_node *entrada);


char *Or_CC_Operation(char *reg1, char *reg2, char *dest);
char *AND_CC_Operation(char *reg1, char *reg2, char *dest);
char *loadMemRegToReg(char *reg1, char *reg2);
char* newTemp();
char * gerar_label();
char *storeVariableRegOffsetToTemp(char *temp,char *regoffset,int depth);
char* concatCode(char *dest, char *source);
char *storeTempToVariableRegOffset(char *temp,char *regoffset,int depth);
char *storeTempToVariable(char *temp, int depth, int position);
char *storeVariableToTemp(char *temp, int depth, int position);
char* loadValueToTemp(int value, char *temp);
int countLines(char *string, int size);
char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest);

char *copyRegToReg(char *reg1, char *reg2);

void inserir_instrucao(LISTA_INSTRUCOES** lista_instrucoes, char* nova_instrucao);
int contar_instrucoes(LISTA_INSTRUCOES* lista_instrucoes);

char *binaryOperationInteger(char *operation, char *reg1, int value, char *dest);

char *Testar_desviar_cbr(char* exp, char* lbl_T, char* lbl_F);
char *desvio_lbl_jumpI(char* lbl_destino);
