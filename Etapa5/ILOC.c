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
int count_temp = 0;
int countLabel = 0;






/*loadI 1024 => rfp
loadI 1024 => rsp*/


void Imprimir_codigo(){
    int stackForm = 1024;

    printf("loadI %d => rfp\n", stackForm);
    printf("loadI %d => rsp\n", stackForm);

    printf("%s\n", gerar_label());




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



    sprintf(count_label_str, "%d:", countLabel);
    strcat(label,"L");
    strcat(label,count_label_str);

    countRegistor ++;

    return label;
}



void Instrucoes(char *instrucao){
    char **Instrucoes = (char**) malloc(sizeof(char*)*(sizeof(char)));
    Instrucoes = &instrucao;
    printf("instrucoes %d\n",strlen(*Instrucoes));
}



TEMP *gerar_temp(int valor){
    TEMP *temp;

    temp->nome = (char*) malloc(sizeof(char));
    char *count_temp_str = (char*) malloc(sizeof(char));


    count_temp ++;


    sprintf(count_temp_str, "%d", count_temp);
    strcat(temp->nome,"temp_");
    strcat(temp->nome,count_temp_str);
    //printf("%s \n ",temp->nome );


    temp->valor = valor;

    return temp;
}




void operacoesBinaria(char operandor, SYMBOL_INFO operando_esquerdo, SYMBOL_INFO operando_direito)
{
    char *operation = (char*) malloc(sizeof(char));
    OPERACAO op;

    switch (operandor)
    {
    case '+':
        op.operandor = "add";
        op.operando_esquerdo = gerar_registrador();
        op.operando_direito = gerar_registrador();
        op.destino = "r3";

        printf("%s      %s, %s   =>  %s\n",op.operandor,operando_esquerdo.name,operando_direito.name,op.destino);
        Instrucoes("i");
break;
        //return operation;

    //return op;
    /* case '-':
         op.operandor = "sub";
         op.operando1 = "r1";
         op.operando2 = "r2";
         op.destino = "r3";

         //return op;
     case '*':
         op.operandor = "mult";
         op.operando1 = "r1";
         op.operando2 = "r2";
         op.destino = "r3";

         //return op;
     case '/':
         op.operandor = "div";
         op.operando1 = "r1";
         op.operando2 = "r2";
         op.destino = "r3";

         //return op;*/
    default:
        printf ("ERRO");
        break;
        //op.operandor ="";
        //op.operando1 = "";
        //op.operando2 = "";
        //op.destino = "";

        //return op;
    }
}









SYMBOL_INFO lookup(ast_node *entrada)
{


    return retrieve_symbol(entrada->ast_valor_lexico);
}


/*

int main()
{

    char *a =
    printf("%s", a);
    return 0;
}

*/
