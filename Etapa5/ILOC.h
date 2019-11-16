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


/* Link list node */
struct nodo
{
    char* instrucao;
    struct nodo* proximo;
};
typedef struct  nodo LISTA_INSTRUCOES;


void Instrucoesf(char *instrucao);


char * gerar_label();
void Imprimir_codigo();
void operacoesBinaria(char operandor, SYMBOL_INFO operando_esquerdo, SYMBOL_INFO operando_direito);
SYMBOL_INFO lookup(ast_node *entrada);
char * gerar_registrador();
TEMP * gerar_temp(int valor);





void inserir_instrucao(LISTA_INSTRUCOES** lista_instrucoes, char* nova_instrucao);
int contar_instrucoes(LISTA_INSTRUCOES* lista_instrucoes);
