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





void operacoesBinaria(char operandor, SYMBOL_INFO operando1, SYMBOL_INFO operando2)
{
    OPERACAO op;
    switch (operandor)
    {
    case '+':
        op.operandor = "add";
        op.operando1 = "r1";
        op.operando2 = "r2";
        op.destino = "r3";
        printf("%s      %s, %s   =>  %s\n",op.operandor,operando1.name,operando2.name,op.destino);

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
        printf("a");
        break;
        //op.operandor ="";
        //op.operando1 = "";
        //op.operando2 = "";
        //op.destino = "";

        //return op;
    }
}



SYMBOL_INFO lookup(ast_node *entrada){


    return retrieve_symbol(entrada->ast_valor_lexico);
}

/*int main()
{
    OPERACAO op = operacoesBinaria('+',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    op = operacoesBinaria('-',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    op = operacoesBinaria('*',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    op = operacoesBinaria('/',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    op = operacoesBinaria('a',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    op = operacoesBinaria('2',1,2);
    printf("%s      %s, %s   =>  %s\n",op.operandor,op.operando1,op.operando2,op.destino);
    return 0;
}*/
