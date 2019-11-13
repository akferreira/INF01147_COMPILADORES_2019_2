#include "ILOC.h"

OPERACAO operacoesBinaria(char operandor, int operando1, int operando2)
{
    OPERACAO op;
    switch (operandor)
    {
    case '+':
        op.operandor = "add";
        op.operando1 = "r1";
        op.operando2 = "r2";
        op.destino = "r3";

        return op;
    case '-':
        op.operandor = "sub";
        op.operando1 = "r1";
        op.operando2 = "r2";
        op.destino = "r3";

        return op;
    case '*':
        op.operandor = "mult";
        op.operando1 = "r1";
        op.operando2 = "r2";
        op.destino = "r3";

        return op;
    case '/':
        op.operandor = "div";
        op.operando1 = "r1";
        op.operando2 = "r2";
        op.destino = "r3";

        return op;
    default:
        op.operandor ="";
        op.operando1 = "";
        op.operando2 = "";
        op.destino = "";

        return op;
    }
}



int main()
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
}
