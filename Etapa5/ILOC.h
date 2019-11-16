#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbol_table.h"
struct operacao
{
    char* operandor;
    char* operando_esquerdo;
    char* operando_direito;
    char* destino;

};
typedef struct operacao OPERACAO;

struct temp{
    char* nome;
    int valor;
};
typedef struct temp TEMP;




void operacoesBinaria(char operandor, SYMBOL_INFO operando_esquerdo, SYMBOL_INFO operando_direito);
SYMBOL_INFO lookup(ast_node *entrada);
char * gerar_registrador();
TEMP * gerar_temp(int valor);
