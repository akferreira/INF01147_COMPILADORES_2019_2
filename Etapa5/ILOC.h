#include<stdio.h>
#include<stdlib.h>
#include "symbol_table.h"
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
