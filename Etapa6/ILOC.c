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

int countLabel = 0;

int  count_Label = 0;


int tempCount = 0;


LABEL_LIST *funcoes = NULL;





char* newTemp(){
    
    
    char *buffer = malloc(TEMP_NAME_SIZE);
    
    
    if(buffer == NULL) return NULL;
    
    int cx = snprintf(buffer, TEMP_NAME_SIZE-1, "r%d",tempCount);
    tempCount++;
    return buffer;
    
}

LISTA_REMENDOS *remendo(){
    static int cc = 0;
    cc++;
    
    LISTA_REMENDOS *new = malloc(sizeof(LISTA_REMENDOS));
    
    if(new == NULL) return NULL;
    
    new->remendo = malloc(TEMP_NAME_SIZE);
    
    
    
    
    if( new->remendo == NULL) return NULL;
    
    int cx = snprintf( new->remendo, TEMP_NAME_SIZE-1, "L%d",countLabel);
	countLabel++;
    return new;
    
    
}

LISTA_REMENDOS *concatRemendo(LISTA_REMENDOS *l1, LISTA_REMENDOS *l2){
    if(l1 == NULL) return l2;
    LISTA_REMENDOS *l1_temp = l1;
    
    while(l1_temp->next) l1_temp = l1_temp->next;
    
    l1_temp->next = l2;
    
    return l1;
    
    
    
}

LISTA_REMENDOS *replaceRemendo(LISTA_REMENDOS *l1, char *novo_remendo){
     if(l1 == NULL) return NULL;
    LISTA_REMENDOS *l1_temp = l1;
    
    while(l1_temp) {
        l1_temp->remendo = novo_remendo;
        l1_temp = l1_temp->next;
    }
    
    return l1;
}





void Imprimir_codigo(char *codigo, int size)
{
    int stackForm = 1024;
    int numero_instrucoes = countLines(codigo, size);

    printf("loadI %d => rfp\n", stackForm);
    printf("loadI %d => rsp\n", stackForm);
    
    printf("loadI %d => rbss\n", numero_instrucoes + 5 + 1);
    //instrucoes do codigo + inicializacao rfs, rsp, rbss e halt e jumpI l0
    printf("jumpI -> %s\n",getFunctionLabel("main"));

    printf("%s",codigo);




    printf("halt\n");
}




















int countLines(char *string, int size){
    int count = 0;
    int newline = '\n';
    
    while(count < size && (*string) != '\0'){
        if(*string == newline) ++count;
        string = string + 1;
    }
    return count;
}

char* newLabel(){
    char *buffer = malloc(TEMP_NAME_SIZE);
    snprintf(buffer,TEMP_NAME_SIZE-1, "L%d", countLabel);
    countLabel++;
    return buffer;
    
}

void addFunction(char *label, char *name){
    if(funcoes == NULL) {
        funcoes = malloc(sizeof(LABEL_LIST));
        funcoes->next = NULL;
        funcoes->label = strdup(label);
        funcoes->fname = strdup(name);
    }
    
    else{
        LABEL_LIST *temp = funcoes;
        while(temp->next) temp = temp->next;
        temp->next = malloc(sizeof(LABEL_LIST));
        temp->next->label = strdup(label);
         temp->next->fname = strdup(name);
        temp->next->next = NULL;
    }
    
}

char *getFunctionLabel(char *name){
    if(funcoes == NULL) return NULL;
    
    LABEL_LIST *temp = funcoes;
    while(temp) {
        if( strcmp(temp->fname,name) == 0) return strdup(temp->label);
        temp = temp->next;
    }
    
    return NULL;
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

char *storeTempToRegOffset(char *temp,char *reg , int offset){
    if(temp == NULL) return NULL;
     char *buffer = malloc(STORE_INST_SIZE);
    
     if(buffer == NULL) return NULL;
     
    int cx = snprintf(buffer, STORE_INST_SIZE-1, "storeAI   %s => %s, %d \n",temp,reg,offset);
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



char *jumpReg(char *reg){
    char *buffer = malloc(OP_INST_SIZE);
    if(reg == NULL) return NULL;
    
    int c1 = snprintf(buffer, OP_INST_SIZE-1, "jump => %s\n",reg);


    return buffer;
    
    
}

char *jumpLabel(char *label){
     char *buffer = malloc(OP_INST_SIZE);
    if(label == NULL) return NULL;
    
    int c1 = snprintf(buffer, OP_INST_SIZE-1, "jumpI => %s\n",label);


    return buffer;
    
}









ast_node *GenerateCompOPCode(ast_node *B, ast_node *b1, ast_node *b2, char *comp){
    B->temp = newTemp();
	B->true = remendo();
	B->false = remendo();
    
    B->code = concatCode(B->code, b1->code);
	B->code = concatCode(B->code, b2->code);
	B->code = concatCode(B->code, binaryOperation(comp, b1->temp, b2->temp,B->temp));
	B->code = concatCode(B->code, strdup("cbr "));
	B->code = concatCode(B->code, B->temp);
	B->code = concatCode(B->code, strdup(" -> "));
	
	
	B->code = concatCode(B->code, B->true->remendo);
	B->code = concatCode(B->code, strdup(", "));
	B->code = concatCode(B->code, B->false->remendo);
	B->code = concatCode(B->code, strdup("\n"));
    
    return B;
}


char *strrep(const char *s1, const char *s2, const char *s3)
{
    if (!s1 || !s2 || !s3)
        return 0;
    size_t s1_len = strlen(s1);
    if (!s1_len)
        return (char *)s1;
    size_t s2_len = strlen(s2);
    if (!s2_len)
        return (char *)s1;

    /*
     * Two-pass approach: figure out how much space to allocate for
     * the new string, pre-allocate it, then perform replacement(s).
     */

    size_t count = 0;
    const char *p = s1;
    do {
        p = strstr(p, s2);
        if (p) {
            p += s2_len;
            ++count;
        }
    } while (p);

    if (!count)
        return (char *)s1;

   
    size_t s1_without_s2_len = s1_len - count * s2_len;
    size_t s3_len = strlen(s3);
    size_t s1_with_s3_len = s1_without_s2_len + count * s3_len;
    if (s3_len &&
        ((s1_with_s3_len <= s1_without_s2_len) || (s1_with_s3_len + 1 == 0)))
        /* Overflow. */
        return 0;
    
    char *s1_with_s3 = (char *)malloc(s1_with_s3_len + 1); /* w/ terminator */
    if (!s1_with_s3)
        /* ENOMEM, but no good way to signal it. */
        return 0;
    
    char *dst = s1_with_s3;
    const char *start_substr = s1;
    size_t i;
    for (i = 0; i != count; ++i) {
        const char *end_substr = strstr(start_substr, s2);
        size_t substr_len = end_substr - start_substr;
        memcpy(dst, start_substr, substr_len);
        dst += substr_len;
        memcpy(dst, s3, s3_len);
        dst += s3_len;
        start_substr = end_substr + s2_len;
    }

    /* copy remainder of s1, including trailing '\0' */
    size_t remains = s1_len - (start_substr - s1) + 1;
    memcpy(dst, start_substr, remains);
    return s1_with_s3;
}

