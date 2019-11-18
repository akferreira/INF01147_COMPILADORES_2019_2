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

int countLabel = 1;

int  count_Label =0;











char* newTemp(){
    static int temp = 0;
    temp++;
    
    char *buffer = malloc(TEMP_NAME_SIZE);
    
    
    if(buffer == NULL) return NULL;
    
    int cx = snprintf(buffer, TEMP_NAME_SIZE-1, "r%d",temp);

    return buffer;
    
}






void Imprimir_codigo(char *codigo, int size)
{
    int stackForm = 1024;
    int numero_instrucoes = countLines(codigo, size);

    printf("loadI %d => rfp\n", stackForm);
    printf("loadI %d => rsp\n", stackForm);
    
    printf("loadI %d => rbss\n", numero_instrucoes + 5 + 1);
    //instrucoes do codigo + inicializacao rfs, rsp, rbss e halt e jumpI l0
    printf("jumpI => L0\n");

    printf("%s",codigo);




    printf("halt\n");
}




















int countLines(char *string, int size){
    int count = 0;
    int newline = '\n';
    
    //printf("counting\n");
    
    while(count < size && (*string) != '\0'){
        if(*string == newline) ++count;
        
        string = string + 1;
        
    }
    
    
    return count;
}

char* newLabel(){
    char *buffer = malloc(TEMP_NAME_SIZE);
    snprintf(buffer,TEMP_NAME_SIZE-1, "L%d:  ", countLabel);
    countLabel++;
    return buffer;
    
}
char* concatCode(char *dest, char *source){
    
    if(dest == NULL ) return source;
    if(source == NULL) {
        return dest;
    }
    
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

char *loadMemRegToReg(char *reg1, char *reg2){
    char *buffer = malloc(OP_INST_SIZE);
    
    if(buffer == NULL) return NULL;
     
     int cx = snprintf(buffer, OP_INST_SIZE-1, "load %s => %s\n",reg1,reg2);
    
    return buffer;
    
    
}


char *storeVariableRegOffsetToTemp(char *temp,char *regoffset,int depth){
    if(temp == NULL) return NULL;
     char *buffer = malloc(STORE_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
     if(depth == 0){
         int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadA0 rbss, %s => %s  \n",regoffset,temp);
    }
    
    else{
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadA0 rfp, %s => %s  \n",regoffset,temp);
    }
     return buffer;
    
}

char *storeTempToVariableRegOffset(char *temp,char *regoffset,int depth){
    if(temp == NULL) return NULL;
     char *buffer = malloc(STORE_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
     if(depth == 0){
         int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeA0   %s => rbss, %s \n",temp,regoffset);
    }
    
    else{
        int cx = snprintf(buffer, STORE_INST_SIZE-1, "loadA0 rfp, %s => %s  \n",temp,regoffset);
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
     
     int cx = snprintf(buffer, OP_INST_SIZE-1, "%s %s, %s => %s\n",operation,reg1,reg2,dest);
    
    return buffer;
}

char *binaryOperationInteger(char *operation, char *reg1, int value, char *dest){
    char *buffer = malloc(OP_INST_SIZE);
    
    if(buffer == NULL) return NULL;
     
     int cx = snprintf(buffer, OP_INST_SIZE-1, "%s %s, %d => %s\n",operation,reg1,value,dest);
    
    return buffer;
    
    
}

char *copyRegToReg(char *reg1, char *reg2){
    char *buffer = malloc(OP_INST_SIZE);
    
    if(buffer == NULL) return NULL;
     
     int cx = snprintf(buffer, OP_INST_SIZE-1, "i2i %s => %s\n",reg1,reg2);
    
    return buffer;
    
}

char *Testar_desviar_cbr(char* exp, char* lbl_T, char* lbl_F)
{
    char *buffer = malloc(OP_INST_SIZE);

    if((lbl_T == NULL)||(lbl_F == NULL))
        return NULL;


    int c1 = snprintf(buffer, OP_INST_SIZE-1, "cbr %s -> %s, %s\n",exp,lbl_T,lbl_F);


    return buffer;
}

char *desvio_lbl_jumpI(char* lbl_destino)
{
    char *buffer = malloc(OP_INST_SIZE);
    if(lbl_destino == NULL)
        return NULL;
    int c1 = snprintf(buffer, OP_INST_SIZE-1, "jumpI %s\n",lbl_destino);


    return buffer;

}



char *Or_CC_Operation(char *reg1, char *reg2, char *dest)
{
    
    printf("debug: %s %s %s\n",reg1,reg2,dest);
    char *buffer = malloc(OP_INST_SIZE);

    char *lbl_true = malloc(OP_INST_SIZE);
    char *lbl_false = malloc(OP_INST_SIZE);
    char *buffer_lbl_aux = malloc(OP_INST_SIZE);

    char *buffer_l1 = malloc(OP_INST_SIZE);
    char *buffer_l2 = malloc(OP_INST_SIZE);
    char *buffer_l3 = malloc(OP_INST_SIZE);
    char *buffer_l4 = malloc(OP_INST_SIZE);
    char *buffer_l5 = malloc(OP_INST_SIZE);
    char *buffer_l6 = malloc(OP_INST_SIZE);
    char *lbl_aux1 = malloc(OP_INST_SIZE);
    char *lbl_aux2 = malloc(OP_INST_SIZE);


    if(buffer == NULL)
        return NULL;



    lbl_true = newLabel();
    lbl_false = newLabel();
    lbl_aux1 = newLabel();
    lbl_aux2 = newLabel();


    buffer_l1 = Testar_desviar_cbr(reg1, lbl_true, lbl_aux1);

    buffer_lbl_aux= concatCode(lbl_aux1,": ");


    buffer_l2 = concatCode(buffer_lbl_aux, Testar_desviar_cbr(reg2, lbl_true, lbl_false));
    buffer_lbl_aux= concatCode(lbl_true,": ");
    buffer_l3 = concatCode(buffer_lbl_aux,loadValueToTemp(1, dest));
    buffer_l4 = desvio_lbl_jumpI(lbl_aux2);

    buffer_lbl_aux= concatCode(lbl_false,": ");
    buffer_l5 = concatCode(buffer_lbl_aux,loadValueToTemp(0, dest));
    buffer_l6 = concatCode(lbl_aux2,": ");


    buffer = concatCode(buffer_l1,buffer_l2);
    buffer = concatCode(buffer,buffer_l3);
    buffer = concatCode(buffer,buffer_l4);
    buffer = concatCode(buffer,buffer_l5);
    buffer = concatCode(buffer,buffer_l6);




    //printf("%s", buffer);
    return buffer;
}







char *AND_CC_Operation(char *reg1, char *reg2, char *dest)
{
    char *buffer = malloc(OP_INST_SIZE);

    char *lbl_true = malloc(OP_INST_SIZE);
    char *lbl_false = malloc(OP_INST_SIZE);
    char *buffer_lbl_aux = malloc(OP_INST_SIZE);

    char *buffer_l1 = malloc(OP_INST_SIZE);
    char *buffer_l2 = malloc(OP_INST_SIZE);
    char *buffer_l3 = malloc(OP_INST_SIZE);
    char *buffer_l4 = malloc(OP_INST_SIZE);
    char *buffer_l5 = malloc(OP_INST_SIZE);
    char *buffer_l6 = malloc(OP_INST_SIZE);
    char *lbl_aux1 = malloc(OP_INST_SIZE);
    char *lbl_aux2 = malloc(OP_INST_SIZE);


    if(buffer == NULL)
        return NULL;



    lbl_true = newLabel();
    lbl_false = newLabel();
    lbl_aux1 = newLabel();
    lbl_aux2 = newLabel();


    buffer_l1 = Testar_desviar_cbr(reg1, lbl_aux1, lbl_false);
    buffer_lbl_aux= concatCode(lbl_aux1,": ");
    buffer_l2 = concatCode(buffer_lbl_aux, Testar_desviar_cbr(reg2, lbl_true, lbl_false));
    buffer_lbl_aux= concatCode(lbl_true,": ");
    buffer_l3 = concatCode(buffer_lbl_aux,loadValueToTemp(1, dest));
    buffer_l4 = desvio_lbl_jumpI(lbl_aux2);
    buffer_lbl_aux= concatCode(lbl_false,": ");
    buffer_l5 = concatCode(buffer_lbl_aux,loadValueToTemp(0, dest));
    buffer_l6 = concatCode(lbl_aux2,": ");


    buffer = concatCode(buffer_l1,buffer_l2);
    buffer = concatCode(buffer,buffer_l3);
    buffer = concatCode(buffer,buffer_l4);
    buffer = concatCode(buffer,buffer_l5);
    buffer = concatCode(buffer,buffer_l6);




    printf("%s", buffer);
    return buffer;
}




