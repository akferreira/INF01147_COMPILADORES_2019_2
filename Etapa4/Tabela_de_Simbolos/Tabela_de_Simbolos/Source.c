#include "Header.h"

NODO_PILHA* Novo_Nodo(int data)
{
	NODO_PILHA* stackNode = (struct NODO_PILHA*)malloc(sizeof(NODO_PILHA));
	stackNode->tabela_de_simbolos.data = data;
	stackNode->next = NULL;
	return stackNode;
}


int PilhaVazia(NODO_PILHA* root)
{
	if (root)
		return 0;
	else
		return 1;
}

void push(NODO_PILHA** root, int data)
{
	NODO_PILHA* stackNode = Novo_Nodo(data);
	stackNode->next = *root;
	*root = stackNode;
}

int pop(NODO_PILHA** root)
{
	if (PilhaVazia(*root))
		return -1;
	NODO_PILHA* temp = *root;
	*root = (*root)->next;
	int popped = temp->tabela_de_simbolos.data;
	free(temp);

	return popped;
}

int ConsultarPilha(NODO_PILHA* root)
{
	if (PilhaVazia(root))
		return -1;
	return root->tabela_de_simbolos.data;
}

int main()
{
	/*TESTES*/
	NODO_PILHA* root = NULL;
	
	printf("Pilha vazia %d\n", PilhaVazia(root));
	printf("topo== %d\n", ConsultarPilha(root));
	push(&root, 20);
	
	printf("topo== %d\n", ConsultarPilha(root));
	push(&root, 50);
	printf("pop== %d\n", pop(&root));
	printf("topo== %d\n", ConsultarPilha(root));
	push(&root, 60);
	printf("topo== %d\n", ConsultarPilha(root));

	return 0;
}
