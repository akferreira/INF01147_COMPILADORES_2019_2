#pragma once

#include <stdio.h> 
#include <stdlib.h> 


typedef struct tabela_de_sinbolos {
	int data;
}TABELA_DE_VALORES;

typedef struct StackNode {
	TABELA_DE_VALORES tabela_de_simbolos;
	struct StackNode* next;
}NODO_PILHA;



NODO_PILHA* Novo_Nodo(int data);
int PilhaVazia(NODO_PILHA* root);
void push(NODO_PILHA** root, int data);
int pop(NODO_PILHA** root);
int ConsultarPilha(NODO_PILHA* root);