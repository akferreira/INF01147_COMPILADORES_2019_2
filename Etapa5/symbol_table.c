#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int returning_own_function;
int debug = 0;
extern int line,column;

SYMBOL_STACK *semantic_stack = NULL;

int get_size2(SYMBOL_INFO info){
    int type = info.var_type;
    int lenght;
    
    switch (type){
        case TYPE_BOOL:
        case TYPE_CHAR:
            return 1;
        case TYPE_FLOAT:
            return 8;
            
        case TYPE_INT:
            return 4;
        
        case TYPE_STRING:
            return 0;
            
        default:
            return 4;
            
            
        
    }
    
}

int get_size(VALOR_LEXICO lexical){
    int type = lexical.var_type;
    int lenght;
    
    switch (type){
        case TYPE_BOOL:
        case TYPE_CHAR:
            return 1;
        case TYPE_FLOAT:
            return 8;
            
        case TYPE_INT:
            return 4;
        
        case TYPE_STRING:
            return 0;
            
        default:
            return 4;
            
            
        
    }
    
}


int initialize_stack(){
    if(semantic_stack == NULL){
        //printf("First table\n\n");
        
        semantic_stack = malloc(sizeof(SYMBOL_STACK));
        if(semantic_stack != NULL){
            semantic_stack->next = NULL;
            semantic_stack->symbol_table = malloc(sizeof(SYMBOL_TABLE));
            semantic_stack->symbol_table->symbol_info = NULL;
            semantic_stack->symbol_table->next = NULL;
            semantic_stack->symbol_table->argument_list = NULL;
            semantic_stack->depth = 0;
            
            
        
            return 0;
        }
        
        else return -1;
        
        
    }
    return 0;
}



int create_new_scope(){
        if (semantic_stack == NULL){
            return initialize_stack();
        }
    
        SYMBOL_STACK* new_stack_entry = malloc(sizeof(SYMBOL_STACK));
        
        if(new_stack_entry != NULL){
            
            new_stack_entry->next = NULL;
            new_stack_entry->symbol_table = malloc(sizeof(SYMBOL_TABLE));
            new_stack_entry->symbol_table->symbol_info = NULL;
            new_stack_entry->symbol_table->argument_list = NULL;
            new_stack_entry->symbol_table->next = NULL;
            new_stack_entry->next = semantic_stack;
            
            int previous_depth = semantic_stack->depth;
            
           
            
            semantic_stack = new_stack_entry;
            semantic_stack->depth = ++previous_depth;
            
            //printf("Current stack depth:%d\n",semantic_stack->depth);
            
            return 0;
        }
        
        else return -1;
    
    
}

void clean_stack(SYMBOL_STACK *stack){
    if(stack == NULL) return;
    
    clean_stack(stack->next);
    
    clean_table(stack->symbol_table);
    free(stack);
    
}

void clean_table(SYMBOL_TABLE *table){
    if(table == NULL) return;
    
    clean_table(table->next);
    
    
    if(table->symbol_info) {
        if(table->symbol_info->name) free(table->symbol_info->name);
        table->symbol_info->name = NULL;
        free(table->symbol_info);
        table->symbol_info = NULL;
    }
    if(table->argument_list) {
        
        clean_arg_list(table->argument_list);
        table->argument_list = NULL;
    }
    free(table);
    
}

void clean_arg_list(ARG_LIST* arg_list){
    if(arg_list == NULL) return;
    
    clean_arg_list(arg_list->next_argument);
    
    if(arg_list->arg_info->name) free(arg_list->arg_info->name);
    arg_list->arg_info->name = NULL;
    free(arg_list->arg_info);
    arg_list->arg_info = NULL;
    free(arg_list);
    arg_list = NULL;
}



int exit_scope(){
    if(semantic_stack != NULL){
        SYMBOL_STACK* next_stack_entry = semantic_stack->next;
        SYMBOL_STACK* current_stack_entry = semantic_stack;
        
        
        
        semantic_stack = next_stack_entry;
        
        
        
        clean_table(current_stack_entry->symbol_table);
        free(current_stack_entry);
        
    }
    
    
    
    return 0;
}


void copy_lexical_to_symbol(SYMBOL_INFO *symbol, VALOR_LEXICO lexical){
    symbol->line = lexical.line;
    symbol->column = lexical.column;
    symbol->nature = lexical.nature;
    symbol->var_type = lexical.var_type;    
    
    symbol->name = strdup(lexical.value.str_value);
    
    //free(lexical.value.str_value);
    
    
}

int get_last_position_toptable(){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    printf("top %p\n",top_table);
    if(top_table == NULL) return 0;
    
    else{
        SYMBOL_TABLE* current_table = top_table;
        while(current_table->next != NULL) current_table = current_table->next;
        
        if(current_table->symbol_info){
            return current_table->symbol_info->position;
        }
        else return -1;
        
    }
}


void insert_function_entry(VALOR_LEXICO lexical){
    
    initialize_stack();
    insert_new_table_entry(lexical,NULL);
    lexical.value.str_value = NULL;
    
}


int calculate_vector_size(ARRAY_DIMENSIONS *vector_dimension){
    if(vector_dimension == NULL) return -1;
    
    int position = 1;
    while(vector_dimension){
        position *= vector_dimension->dsize;
        vector_dimension = vector_dimension->next;
    }
    
    return position;
    
    
}





int calculate_vector_position(ARRAY_DIMENSIONS *vector_dimension,ARRAY_DIMENSIONS *indexes){
    if(vector_dimension == NULL) return -1;
    //INCOMPATIBLE_VECTOR_DIMENSIONS
    
    int position = 0;
    int previous_size = 0;
    
    int d = indexes->dsize;
    int size = vector_dimension->dsize;
    
   // vector_dimension = vector_dimension->next;
  //  indexes = indexes->next;
    
    while(vector_dimension){
        if(indexes == NULL) return INCOMPATIBLE_VECTOR_DIMENSIONS;
        
        //printf("%p\n",vector_dimension->next);
        
        position += vector_dimension->dsize * indexes->dsize *previous_size;
        previous_size = previous_size * vector_dimension->dsize + indexes->dsize;
        vector_dimension = vector_dimension->next;
        indexes = indexes->next;
    }
    
    return previous_size;
    
    
//     static int depth = 0;
//     printf("%p\n",indexes);
//     
//     //if(indexes == NULL || vector_dimension == NULL) return 0;
//     
//     if(indexes->next == NULL){
//         depth++;
//         printf("i%d %d\n",depth,indexes->dsize);
//         return indexes->dsize;
//     }
//     
//     else{
//         int d = calculate_vector_position(vector_dimension->next,indexes->next);
//         
//         depth++;
//         printf("i%d : %d * %d + %d\n",depth,d,vector_dimension->dsize,indexes->dsize);
//         
//         return (d * vector_dimension->dsize + indexes->dsize );
//     }
    
    
}



int insert_new_table_entry(VALOR_LEXICO lexical,ARRAY_DIMENSIONS *vector_dimension){
    initialize_stack();
    
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    //printf("Inserting table entry at %d\n",semantic_stack->depth);
     //printf("table %p\n",top_table);f
    
    if(top_table->symbol_info == NULL){
        
        top_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        top_table->next = NULL;
        
        //printf("%p\n",top_table->symbol_info);
        
        if(top_table->symbol_info != NULL){
            copy_lexical_to_symbol(top_table->symbol_info,lexical);
            top_table->symbol_info->position = 0;
            top_table->symbol_info->depth = semantic_stack->depth;
            
            if(vector_dimension == NULL){
                if(debug) printf("aaa\n");
                top_table->symbol_info->size = get_size(lexical);
                top_table->symbol_info->vector_dimension = NULL;
                if(debug) printf("bbb\n");
            }
            
            else{
                int size = 0;
                int dimension_size= calculate_vector_size(vector_dimension);
                top_table->symbol_info->vector_dimension = vector_dimension;
                top_table->symbol_info->size = get_size(lexical)*dimension_size;
                
                
            }
            
            return 0;
        }
        
        else return -1;
        
    }
    
    else{
       
        
        //checa se a primeira entrada da tabela já é declaração repetida ou não
        if(strcmp(semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value) == 0){
            printf("Semantical error line %d, column %d : ERR_DECLARED\n",lexical.line, lexical.column);
            exit(ERR_DECLARED);
        }
        
        
        SYMBOL_TABLE* current_table = top_table;
        //printf("Current: %p \nnext %p \n",current_table,current_table->next);
        
        //printf("not first symbol\n\n");
        int current_position = 0;
        
        while(current_table->next != NULL){
            //printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
           //printf("Current: %p \nnext %p \n",current_table,current_table->next);
            
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("Semantical error line %d, column %d : ERR_DECLARED\n",lexical.line, lexical.column);
                exit(ERR_DECLARED);
            }
            
            int size = get_size2(*current_table->symbol_info);
            current_position+= size;
            
            current_table = current_table->next;
           
            
        }
       //printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
        if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("Semantical error line %d, column %d : ERR_DECLARED\n",lexical.line, lexical.column);
                exit(ERR_DECLARED);
            }
        int size = get_size2(*current_table->symbol_info);
        current_position+= size;    
            
        SYMBOL_TABLE *next_table = (SYMBOL_TABLE*) malloc(sizeof(SYMBOL_TABLE));
        next_table->argument_list = NULL;
        next_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        next_table->next = NULL;
        
        
        current_table->next = next_table;
        current_table = next_table;
        
        if(current_table->symbol_info != NULL){
            copy_lexical_to_symbol(current_table->symbol_info,lexical);
            current_table->symbol_info->position = current_position;
            current_table->symbol_info->depth = semantic_stack->depth;
            
            if(vector_dimension == NULL){
                current_table->symbol_info->size = get_size(lexical);
                current_table->symbol_info->vector_dimension = NULL;
            }
            
            else{
                int size = 0;
                current_table->symbol_info->vector_dimension = vector_dimension;
                
                int dimension_size = calculate_vector_size(vector_dimension);
                
                current_table->symbol_info->size = get_size(lexical)*dimension_size;
                
                
            }
            return 0;
        }
        
        else return -1;
    }
    
}

int insert_parameters_function(VALOR_LEXICO argument){
    SYMBOL_TABLE* current_table = semantic_stack->next->symbol_table;
    if(current_table != NULL){
        
        while(current_table->next != NULL) current_table = current_table->next;
        
        if(current_table->symbol_info->nature == FUNCTION){
            ARG_LIST* arg_list = current_table->argument_list;
            
            if(arg_list == NULL){
                
                current_table->argument_list = malloc(sizeof(ARG_LIST));
                current_table->argument_list->next_argument = NULL;
        
                current_table->argument_list->arg_info = (SYMBOL_INFO*) malloc(sizeof(VALOR_LEXICO));
                copy_lexical_to_symbol(current_table->argument_list->arg_info,argument);
            }
            
            else{
                while(arg_list->next_argument != NULL) arg_list = arg_list->next_argument;
                
                arg_list->next_argument = malloc(sizeof(ARG_LIST));
                arg_list->next_argument->next_argument = NULL;
                
                arg_list->next_argument->arg_info = (SYMBOL_INFO*) malloc(sizeof(VALOR_LEXICO));
                
                copy_lexical_to_symbol(arg_list->next_argument->arg_info,argument);
                
            }
            
            
            
        
        }
    
}



return 0;
}






SYMBOL_INFO retrieve_symbol(VALOR_LEXICO lexical){
    SYMBOL_STACK* stack = semantic_stack;
    
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    
    SYMBOL_TABLE* current_table = top_table;
    
    //printf("compare start\n\n");
        
        
        
    while(current_table != NULL){
        //printf("%p\n",current_table->symbol_info);
        
        while(current_table != NULL && current_table->symbol_info != NULL){
            //printf("compare %p\n",current_table->symbol_info);   
            
            //printf("cmp %s\n",current_table->symbol_info->name);
                
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                return *(current_table->symbol_info);
            }
            
            current_table = current_table->next;
        
        
        }
    
    if(stack->next != NULL){
        
        //printf("next stack level\n\n");    
        stack = stack->next;
        current_table =  stack->symbol_table;
    }
    
        
    }
    
    
    
    printf("ERR_UNDECLARED\n");
    exit(ERR_UNDECLARED);
    
}





ARG_LIST* retrieve_arg_list(char *function_name){
    
    
    SYMBOL_STACK* stack = semantic_stack;
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    SYMBOL_TABLE* current_table = top_table;
    
    //printf("compare start\n\n");
        
        
        
    while(current_table != NULL){
        //printf("%p\n",current_table->symbol_info);
        
        while(current_table != NULL && current_table->symbol_info != NULL){
            //printf("compare %p\n",current_table->symbol_info);   
            
           // printf("cmp %s\n",current_table->symbol_info->name);
                
            if(strcmp(current_table->symbol_info->name,function_name) == 0){
                if(current_table->symbol_info->nature == VARIABLE) {
                    printf("ERR_VARIABLE\n");  
                    exit(ERR_VARIABLE);
                    
                }
                if(current_table->symbol_info->nature == VECTOR) {
                    printf("ERR_VECTOR\n");
                    exit(ERR_VECTOR);
                    
                }
                if(current_table->symbol_info->nature == CONST) {
                    printf("ERR_VARIABLE\n");
                    exit(ERR_VARIABLE);
                    
                }
                
                return current_table->argument_list;
            }
            
            current_table = current_table->next;
        
        
        }
    
        if(stack->next != NULL){
            //printf("next stack level\n\n");    
            stack = stack->next;
            current_table =  stack->symbol_table;
        }
    
        
    }
    
    return NULL;
    
}

int check_symbol(VALOR_LEXICO lexical){
    
    SYMBOL_STACK* stack = semantic_stack;
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    SYMBOL_TABLE* current_table = top_table;
    
    
   // printf("compare start\n\n");
        
        
        
    while(current_table != NULL){
        //printf("%p\n",current_table->symbol_info);
        
        while(current_table != NULL && current_table->symbol_info != NULL){
            //printf("compare %p\n",current_table->symbol_info);   
            
            //printf("cmp %s\n",current_table->symbol_info->name);
                
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                return current_table->symbol_info->var_type;
            }
            
            current_table = current_table->next;
        
        
        }
    
    if(stack->next != NULL){
        
        //printf("next stack level\n\n");    
        stack = stack->next;
        current_table =  stack->symbol_table;
    }
    
        
    }
    
    printf("ERR_UNDECLARED\n");
    exit(ERR_UNDECLARED);
    
    
}
int check_type_compatibility(int type1, int type2){
    if(type1 == TYPE_STRING && type2 != TYPE_STRING) {printf("Semantical error line %d, columns %d :  ERR_STRING_TO_X\n" ,line,column);  exit(ERR_STRING_TO_X);}
    else if(type2 == TYPE_STRING && type1 != TYPE_STRING) {printf("Semantical error line %d, columns %d :  ERR_STRING_TO_X\n" ,line,column);  exit(ERR_STRING_TO_X);}
    else if(type2 == TYPE_STRING && type1 == TYPE_STRING) return TYPE_STRING;
    
    
   if(type1 == TYPE_CHAR && type2 != TYPE_CHAR) {printf("Semantical error line %d, columns %d :  ERR_CHAR_TO_X\n" ,line,column);  exit(ERR_CHAR_TO_X);}
    else if(type2 == TYPE_CHAR && type1 != TYPE_CHAR) {printf("Semantical error line %d, columns %d :  ERR_CHAR_TO_X\n" ,line,column);  exit(ERR_CHAR_TO_X);}
    else if(type2 == TYPE_CHAR && type1 == TYPE_CHAR) return TYPE_CHAR;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_INT || type2 == TYPE_INT) return TYPE_INT;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_BOOL || type2 == TYPE_BOOL) return TYPE_BOOL;
    
    
    return -1;
}

int check_return_type_compatibility(int type1, int type2){
    if(type1 == TYPE_STRING && type2 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_PAR_RETURN\n",line,column);  exit(ERR_WRONG_PAR_RETURN);}
    else if(type2 == TYPE_STRING && type1 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_PAR_RETURN\n",line,column);  exit(ERR_WRONG_PAR_RETURN);}
    else if(type2 == TYPE_STRING && type1 == TYPE_STRING) return TYPE_STRING;
    
    
   if(type1 == TYPE_CHAR && type2 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_PAR_RETURN\n",line,column);  exit(ERR_WRONG_PAR_RETURN);}
    else if(type2 == TYPE_CHAR && type1 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_PAR_RETURN\n",line,column);  exit(ERR_WRONG_PAR_RETURN);}
    else if(type2 == TYPE_CHAR && type1 == TYPE_CHAR) return TYPE_CHAR;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_INT || type2 == TYPE_INT) return TYPE_INT;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_BOOL || type2 == TYPE_BOOL) return TYPE_BOOL;
    
    
    return -1;
}

int check_assignment_type_compatibility(int type1, int type2){
    if(type1 == TYPE_STRING && type2 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE\n",line,column);  exit(ERR_WRONG_TYPE);}
    else if(type2 == TYPE_STRING && type1 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE\n",line,column);  exit(ERR_WRONG_TYPE);}
    else if(type2 == TYPE_STRING && type1 == TYPE_STRING) return TYPE_STRING;
    
    
   if(type1 == TYPE_CHAR && type2 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE\n",line,column);  exit(ERR_WRONG_TYPE);}
    else if(type2 == TYPE_CHAR && type1 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE\n",line,column);  exit(ERR_WRONG_TYPE);}
    else if(type2 == TYPE_CHAR && type1 == TYPE_CHAR) return TYPE_CHAR;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_INT || type2 == TYPE_INT) return TYPE_INT;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_BOOL || type2 == TYPE_BOOL) return TYPE_BOOL;
    
    
    return -1;
    
}

int check_parameter_type_compatibility(int type1, int type2){
    if(type1 == TYPE_STRING && type2 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE_ARGS\n",line,column);  exit(ERR_WRONG_TYPE_ARGS);}
    else if(type2 == TYPE_STRING && type1 != TYPE_STRING) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE_ARGS\n",line,column);  exit(ERR_WRONG_TYPE_ARGS);}
    else if(type2 == TYPE_STRING && type1 == TYPE_STRING) return TYPE_STRING;
    
    
   if(type1 == TYPE_CHAR && type2 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE_ARGS\n",line,column);  exit(ERR_WRONG_TYPE_ARGS);}
    else if(type2 == TYPE_CHAR && type1 != TYPE_CHAR) {printf("Semantical error line %d, columns %d : ERR_WRONG_TYPE_ARGS\n",line,column);  exit(ERR_WRONG_TYPE_ARGS);}
    else if(type2 == TYPE_CHAR && type1 == TYPE_CHAR) return TYPE_CHAR;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_INT || type2 == TYPE_INT) return TYPE_INT;
    
    if(type1 == TYPE_FLOAT || type2 == TYPE_FLOAT) return TYPE_FLOAT;
    
    if(type1 == TYPE_BOOL || type2 == TYPE_BOOL) return TYPE_BOOL;
    
    
    return -1;
    
}
