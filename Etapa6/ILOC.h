#ifndef ILOC_H_INCLUDED
#define ILOC_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "ast.h"

#define TEMP_NAME_SIZE 15
#define LOAD_INST_SIZE 50
#define STORE_INST_SIZE 50
#define OP_INST_SIZE 50

#define OFFSET_RETURN_ADDR 0
#define OFFSET_RSP 4
#define OFFSET_RFP 8
#define OFFSET_RETURN 12
#define OFFSET_FIRSTVAR 16


struct operacao
{
    char* operandor;
    char* operando1;
    char* operando2;
    char* destino;

};
typedef struct operacao OPERACAO;


LISTA_REMENDOS *remendo();
LISTA_REMENDOS *concatRemendo(LISTA_REMENDOS *l1, LISTA_REMENDOS *l2);
LISTA_REMENDOS *replaceRemendo(LISTA_REMENDOS *l1, char *novo_remendo);

//void operacoesBinaria(char operandor, SYMBOL_INFO operando1, SYMBOL_INFO operando2);
//SYMBOL_INFO lookup(ast_node *entrada);


int countLines(char *string, int size);
void Imprimir_codigo(char *codigo, int size);
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
char *storeTempToRegOffset(char *temp,char *reg , int offset);
char *Or_CC_Operation(char *reg1, char *reg2, char *dest);
char* loadValueToTemp(int value, char *temp);
char *AND_CC_Operation(char *reg1, char *reg2, char *dest);
char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest);
char *binaryOperationInteger(char *operation, char *reg1, int value, char *dest);
char *copyRegToReg(char *reg1, char *reg2);


char *jumpReg(char *reg);


ast_node *GenerateCompOPCode(ast_node *B, ast_node *b1, ast_node *b2, char *comp);

/*
 * strrep.c - C substring replacement.
 *
 * Written in 2011 by Drew Hess <dhess-src@bothan.net>.
 *
 * To the extent possible under law, the author(s) have dedicated all
 * copyright and related and neighboring rights to this software to
 * the public domain worldwide. This software is distributed without
 * any warranty.
 *
 * For the full statement of the dedication, see the Creative Commons
 * CC0 Public Domain Dedication at
 * <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
char *strrep(const char *s1, const char *s2, const char *s3);


#endif // ILOC_H_INCLUDED
