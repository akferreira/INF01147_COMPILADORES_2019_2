#include<stdio.h>
#include<stdlib.h>
struct operacao
{
    char* operandor;
    char* operando1;
    char* operando2;
    char* destino;

};
typedef struct operacao OPERACAO;



OPERACAO operacoesBinaria(char operandor, int operando1, int operando2);
