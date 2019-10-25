#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int returning_own_function;

extern int line,column;

SYMBOL_STACK *semantic_stack = NULL;

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
            semantic_stack->depth = previous_depth++;
            
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

void insert_function_entry(VALOR_LEXICO lexical){
    initialize_stack();
    //char *function_name = strdup(lexical.value.str_value);
    insert_new_table_entry(lexical,1);
    //printf("ll name %s\n",lexical.value.str_value);
    lexical.value.str_value = NULL;
    
    //lexical.value.str_value = function_name;
    
    //printf("ll name %s\n",lexical.value.str_value);
    //printf("ff name %s\n",function_name);
    //free(function_name);
    
}



int insert_new_table_entry(VALOR_LEXICO lexical, int lenght){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    //printf("Inserting table entry at %d\n",semantic_stack->depth);
     //printf("table %p\n",top_table);
    
    if(top_table->symbol_info == NULL){
        //printf("First symbol %s\n",lexical.value.str_value);
        
        top_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        top_table->next = NULL;
        
        //printf("%p\n",top_table->symbol_info);
        
        if(top_table->symbol_info != NULL){
            copy_lexical_to_symbol(top_table->symbol_info,lexical);
            top_table->symbol_info->size = get_size(lexical)*lenght;
            
            
            //printf("%s size %d\n",lexical.value.str_value ,get_size(lexical)*lenght);
            //free(lexical.value.str_value);
            //lexical.value.str_value = NULL;
            return 0;
        }
        
        else return -1;
        
    }
    
    else{
        //printf("Non first %s//%s\n",semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value);
        
        //checa se a primeira entrada da tabela já é declaração repetida ou não
        if(strcmp(semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value) == 0){
            printf("ERR_DECLARED\n\n");
            exit(ERR_DECLARED);
        }
        
        
        SYMBOL_TABLE* current_table = top_table;
        //printf("Current: %p \nnext %p \n",current_table,current_table->next);
        
        //printf("not first symbol\n\n");
        
        while(current_table->next != NULL){
            //printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
           //printf("Current: %p \nnext %p \n",current_table,current_table->next);
            
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("ERR_DECLARED\n\n");
                exit(ERR_DECLARED);
            }
            
            current_table = current_table->next;
           
            
        }
       //printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
        if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("ERR_DECLARED\n\n");
                exit(ERR_DECLARED);
            }
            
            
        SYMBOL_TABLE *next_table = (SYMBOL_TABLE*) malloc(sizeof(SYMBOL_TABLE));
        next_table->argument_list = NULL;
        next_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        next_table->next = NULL;
        
        
        current_table->next = next_table;
        current_table = next_table;
        
        if(current_table->symbol_info != NULL){
            
            
            
            copy_lexical_to_symbol(current_table->symbol_info,lexical);
            current_table->symbol_info->size = get_size(lexical)*lenght;
            
            //printf("%s size %d\n",lexical.value.str_value ,current_table->symbol_info->size );
            //free(lexical.value.str_value);
            //lexical.value.str_value = NULL;
            return 0;
        }
        
        else return -1;
    }
    
}

int insert_parameters_function_entry(VALOR_LEXICO argument, char *function_name, int lenght){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    
    while(top_table != NULL && top_table->symbol_info->name != NULL && strcmp(top_table->symbol_info->name, function_name) != 0){
        //printf("%s name entry %s\n",function_name,top_table->symbol_info->name);
        top_table = top_table->next;
    }
    //printf("%s name entry %s\n",function_name,top_table->symbol_info->name);
    //printf("\n\nArgument list for %s\n\n",semantic_stack->symbol_table->symbol_info->name);
    
    
    
    
    if(top_table->argument_list == NULL){
        top_table->argument_list = malloc(sizeof(ARG_LIST));
        top_table->argument_list->next_argument = NULL;
        
        top_table->argument_list->arg_info = (SYMBOL_INFO*) malloc(sizeof(VALOR_LEXICO));
        copy_lexical_to_symbol(top_table->argument_list->arg_info,argument);
        
        //memcpy(top_table->argument_list->arg_info,&argument,sizeof(VALOR_LEXICO));
        
        //printf("alloced %d\n", top_table->argument_list->arg_info->line);
        
        
       // printf("arg %s", top_table->argument_list->arg_info->name);
    }
    
    else{
        ARG_LIST* next_argument = top_table->argument_list;
        
        while(next_argument->next_argument != NULL){
            next_argument = next_argument->next_argument;
        }
        
        next_argument->next_argument = malloc(sizeof(ARG_LIST));
        next_argument->next_argument->next_argument = NULL;
        
        next_argument->next_argument->arg_info = (SYMBOL_INFO*) malloc(sizeof(VALOR_LEXICO));
        
        copy_lexical_to_symbol(next_argument->next_argument->arg_info,argument);
        
        //printf("alloced %d\n", next_argument->next_argument->arg_info->line);
        
        
        //printf("arg %s", next_argument->next_argument->arg_info->name);
        
        
        
        
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
                //printf("%s returned size %d\n",current_table->symbol_info->name,current_table->symbol_info->size);
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
    
    if(returning_own_function) return -1;
    
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
