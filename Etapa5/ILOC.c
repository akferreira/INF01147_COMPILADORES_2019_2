#include "ILOC.h"
#include "symbol_table.h"


/*

typedef struct  _symbol_info{
    int line;
    int column;
    int nature;
    int var_type;
    int size;
    char *name;


} SYMBOL_INFO;

*/



int countRegistor = 0;

int countLabel = 0;


LISTA_INSTRUCOES *instrucoes = NULL;







void Imprimir_codigo()
{
    int stackForm = 1024;
    int numero_instrucoes = contar_instrucoes(instrucoes);

    printf("loadI %d => rfp\n", stackForm);
    printf("loadI %d => rsp\n", stackForm);
    //instrucoes do codigo + inicializacao rfs, rsp, rbss e halt
    printf("loadI %d => rbss\n", numero_instrucoes + 4);

    printf("%s\n", gerar_label());

    while(instrucoes != NULL)
    {
        printf("%s\n",instrucoes->instrucao);
        instrucoes = instrucoes->proximo;
    }



    printf("halt\n");
}
























/*

void operacoesBinaria(char operandor, SYMBOL_INFO operando1, SYMBOL_INFO operando2)
{


    sprintf("op1 pos: %d, op2 pos : %d\n",operando1.position,operando2.position);

    printf("op1 pos: %d, op2 pos : %d\n",operando1.position,operando2.position);

}

*/



char* newTemp()
{
    static int temp = 0;
    temp++;
    char *buffer = malloc(TEMP_NAME_SIZE);

    if(buffer == NULL) return NULL;

    int cx = snprintf(buffer, TEMP_NAME_SIZE-1, "r%d",temp);
//     printf("%d\n",cx);
//     printf("buffer = %s\n",buffer);

    return buffer;

}



char * gerar_label()
{
    char *label = (char*) malloc(sizeof(char));
    char *count_label_str = (char*) malloc(sizeof(char));


    strncat(label,"L",2);
    snprintf(count_label_str,4, "%d:", countLabel);

    strncat(label,count_label_str,5);

    countRegistor ++;

    return label;
}






char* concatCode(char *dest, char *source)
{
    if(dest == NULL ) return source;
    if(source == NULL) return dest;


    int lenght = strlen(dest)+strlen(source)+1;

    dest = realloc(dest, lenght);
    if(dest == NULL) return NULL;

    dest =  strncat(dest,source,lenght);



    return dest;
}

char *storeTempToVariable(char *temp, int depth, int position)
{
    if(temp == NULL) return NULL;
    char *buffer = malloc(STORE_INST_SIZE);

    if(buffer == NULL) return NULL;

    if(depth == 0)
    {
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeAI %s => rbss, %d \n",temp,position);
    }

    else
    {
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeAI %s => rfp, %d \n",temp,position);
    }



    return buffer;

}

char *storeVariableToTemp(char *temp, int depth, int position)
{
    if(temp == NULL) return NULL;
    char *buffer = malloc(STORE_INST_SIZE);

    if(buffer == NULL) return NULL;

    if(depth == 0)
    {
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadAI rbss, %d => %s  \n",position,temp);
    }

    else
    {
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadAI rfp, %d => %s  \n",position,temp);
    }
    return buffer;

}

char* loadValueToTemp(int value, char *temp)
{
    if(temp == NULL) return NULL;

    char *buffer = malloc(LOAD_INST_SIZE);

    if(buffer == NULL) return NULL;

    int cx = snprintf(buffer, LOAD_INST_SIZE-1, "loadI %d => %s\n",value,temp);

//      printf("size %lu\n",sizeof(buffer));
//      printf("lenght %lu\n",strlen(buffer));
    return buffer;

}

char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest)
{
    char *buffer = malloc(OP_INST_SIZE);

    if(buffer == NULL)
        return NULL;

    int cx = snprintf(buffer, OP_INST_SIZE-1, "%s %s, %s => %s\n",operation,reg1,reg2,dest);




    //inserir_instrucao(&instrucoes, buffer);
    return buffer;
}



void inserir_instrucao(LISTA_INSTRUCOES** lista_instrucoes, char* nova_instrucao)
{
    LISTA_INSTRUCOES* novo_nodo = (LISTA_INSTRUCOES*) malloc(sizeof(LISTA_INSTRUCOES));


    novo_nodo->instrucao  = nova_instrucao;
    novo_nodo->proximo = (*lista_instrucoes);
    (*lista_instrucoes) = novo_nodo;
}



//Conta o numero de nodos instrucoes da lista
int contar_instrucoes(LISTA_INSTRUCOES* lista_instrucoes)
{
    int count = 0;
    LISTA_INSTRUCOES* instrucoes = lista_instrucoes;
    while (instrucoes != NULL)
    {
        count++;
        instrucoes = instrucoes->proximo;
    }
    return count;
}


/*
#include "ILOC.h"
#include "symbol_table.h"




typedef struct  _symbol_info{
    int line;
    int column;
    int nature;
    int var_type;
    int size;
    char *name;


} SYMBOL_INFO;




int countRegistor = 0;
int count_temp = 0;
int countLabel = 0;

char **Instrucoes;
LISTA_INSTRUCOES *instrucoes = NULL;



loadI 1024 => rfp
loadI 1024 => rsp


void Imprimir_codigo()
{
    int stackForm = 1024;
    int numero_instrucoes = contar_instrucoes(instrucoes);

    printf("loadI %d => rfp\n", stackForm);
    printf("loadI %d => rsp\n", stackForm);
    //instrucoes do codigo + inicializacao rfs, rsp, rbss e halt
    printf("loadI %d => rbss\n", numero_instrucoes + 4);

    printf("%s\n", gerar_label());

    while(instrucoes != NULL)
    {
        printf("%s\n",instrucoes->instrucao);
        instrucoes = instrucoes->proximo;
    }



    printf("halt\n");
}
















char * gerar_registrador()
{
    char *registrador = (char*) malloc(sizeof(char));
    char *countRegistor_str = (char*) malloc(sizeof(char));


    countRegistor ++;


    sprintf(countRegistor_str, "%d", countRegistor);
    strcat(registrador,"r");
    strcat(registrador,countRegistor_str);

    return registrador;
}

char * gerar_label()
{
    char *label = (char*) malloc(sizeof(char));
    char *count_label_str = (char*) malloc(sizeof(char));


    strcat(label,"L");
    sprintf(count_label_str, "%d:", countLabel);

    strcat(label,count_label_str);

    countRegistor ++;

    return label;
}






12w


//insere instrucao na lista de instrucoes
void inserir_instrucao(LISTA_INSTRUCOES** lista_instrucoes, char* nova_instrucao)
{
    LISTA_INSTRUCOES* novo_nodo = (LISTA_INSTRUCOES*) malloc(sizeof(LISTA_INSTRUCOES));


    novo_nodo->instrucao  = nova_instrucao;
    novo_nodo->proximo = (*lista_instrucoes);
    (*lista_instrucoes) = novo_nodo;
}



//Conta o numero de nodos instrucoes da lista
int contar_instrucoes(LISTA_INSTRUCOES* lista_instrucoes)
{
    int count = 0;
    LISTA_INSTRUCOES* instrucoes = lista_instrucoes;
    while (instrucoes != NULL)
    {
        count++;
        instrucoes = instrucoes->proximo;
    }
    return count;
}



*/
