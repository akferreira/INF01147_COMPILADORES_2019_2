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
    printf("op1 pos: %d, op2 pos : %d\n",operando1.position,operando2.position);
//     newTemp();
//     newTemp();
//     newTemp();
    
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

char* newTemp(){
    static int temp = 0;
    temp++;
    char *buffer = malloc(TEMP_NAME_SIZE);
    
    if(buffer == NULL) return NULL;
    
    int cx = snprintf(buffer, TEMP_NAME_SIZE-1, "r%d",temp);
//     printf("%d\n",cx);
//     printf("buffer = %s\n",buffer);
    
    return buffer;
    
}



char* newLabel(){
    char *buffer = malloc(TEMP_NAME_SIZE);
    
    static int temp = 0;
    //char buffer [temp+1];
    
    return buffer;
    
}
char* concatCode(char *dest, char *source){
    if(dest == NULL ) return source;
    if(source == NULL) return dest;
    
    
    int lenght = strlen(dest)+strlen(source)+1;
    
    dest = realloc(dest, lenght);
    if(dest == NULL) return NULL;
    
    dest =  strncat(dest,source,lenght);
    
    
    
    return dest;
}

char *storeTempToVariable(char *temp, int depth, int position){
     if(temp == NULL) return NULL;
     char *buffer = malloc(STORE_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
     if(depth == 0){
         int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeAI %s => rbss, %d \n",temp,position);
    }
    
    else{
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeAI %s => rfp, %d \n",temp,position);
    }
    
    
     
     return buffer;
    
}

char *storeVariableToTemp(char *temp, int depth, int position){
     if(temp == NULL) return NULL;
     char *buffer = malloc(STORE_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
     if(depth == 0){
         int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadAI rbss, %d => %s  \n",position,temp);
    }
    
    else{
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadAI rfp, %d => %s  \n",position,temp);
    }
     return buffer;
    
}

char* loadValueToTemp(int value, char *temp){
    if(temp == NULL) return NULL;
    
    char *buffer = malloc(LOAD_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
     int cx = snprintf(buffer, LOAD_INST_SIZE-1, "loadI %d => %s\n",value,temp);
     
//      printf("size %lu\n",sizeof(buffer));
//      printf("lenght %lu\n",strlen(buffer));
     return buffer;
    
}

char *binaryOperation(char *operation, char *reg1, char *reg2, char *dest){
    char *buffer = malloc(OP_INST_SIZE);
    
    if(buffer == NULL) return NULL;
     
     int cx = snprintf(buffer, OP_INST_SIZE-1, "%s %s,  %s => %s\n",operation,reg1,reg2,dest);
    
    return buffer;
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
