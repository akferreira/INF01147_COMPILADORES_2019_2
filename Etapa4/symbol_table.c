#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



SYMBOL_STACK *semantic_stack = NULL;


int initialize_stack(){
    if(semantic_stack == NULL){
        //printf("First table\n");
        
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



int insert_new_table_entry(VALOR_LEXICO lexical){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    //printf("Inserting table entry at %d\n",semantic_stack->depth);
    
    if(top_table->symbol_info == NULL){
        //printf("First symbol %s\n",lexical.value.str_value);
        
        top_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        top_table->next = NULL;
        
        if(top_table->symbol_info != NULL){
            copy_lexical_to_symbol(top_table->symbol_info,lexical);
            free(lexical.value.str_value);
            return 0;
        }
        
        else return -1;
        
    }
    
    else{
        //printf("Non first %s//%s\n",semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value);
        
        //checa se a primeira entrada da tabela já é declaração repetida ou não
        if(strcmp(semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value) == 0){
            return ERR_DECLARED;
        }
        
        
        SYMBOL_TABLE* current_table = top_table;
        //printf("Current: %p \nnext %p \n",current_table,current_table->next);
        
        //printf("not first symbol\n");
        
        while(current_table->next != NULL){
           // printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
           //printf("Current: %p \nnext %p \n",current_table,current_table->next);
            
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("já existe\n");
                return ERR_DECLARED;
            }
            
            current_table = current_table->next;
           
            
        }
       //printf("\n%s comp %s\n",lexical.value.str_value,current_table->symbol_info->name);
        if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                printf("já existe\n");return ERR_DECLARED;
            }
            
            
        SYMBOL_TABLE *next_table = (SYMBOL_TABLE*) malloc(sizeof(SYMBOL_TABLE));
        next_table->argument_list = NULL;
        next_table->symbol_info = (SYMBOL_INFO*) malloc(sizeof(SYMBOL_INFO));
        next_table->next = NULL;
        
        
        current_table->next = next_table;
        current_table = next_table;
        
        if(current_table->symbol_info != NULL){
            
            copy_lexical_to_symbol(current_table->symbol_info,lexical);
            free(lexical.value.str_value);
            return 0;
        }
        
        else return -1;
    }
    
}

int insert_parameters_function_entry(VALOR_LEXICO argument){
    printf("\n\nArgument list \n\n");
    
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    
    if(top_table->argument_list == NULL){
        top_table->argument_list = malloc(sizeof(ARG_LIST));
        top_table->argument_list->next_argument = NULL;
        
        top_table->argument_list->arg_info = (VALOR_LEXICO*) malloc(sizeof(VALOR_LEXICO));
        
        memcpy(top_table->argument_list->arg_info,&argument,sizeof(VALOR_LEXICO));
        
        printf("alloced %d\n", top_table->argument_list->arg_info->line);
        
        
        printf("arg %s", top_table->argument_list->arg_info->value.str_value);
    }
    
    else{
        ARG_LIST* next_argument = top_table->argument_list;
        
        while(next_argument->next_argument != NULL){
            next_argument = next_argument->next_argument;
        }
        
        next_argument->next_argument = malloc(sizeof(ARG_LIST));
        next_argument->next_argument->next_argument = NULL;
        
        next_argument->next_argument->arg_info = (VALOR_LEXICO*) malloc(sizeof(VALOR_LEXICO));
        
        memcpy(next_argument->next_argument->arg_info,&argument,sizeof(VALOR_LEXICO));
        
        printf("alloced %d\n", next_argument->next_argument->arg_info->line);
        
        
        printf("arg %s", next_argument->next_argument->arg_info->value.str_value);
        
        
        
        
    }
    
    
    return 0;
}


SYMBOL_INFO* retrieve_symbol(VALOR_LEXICO lexical);
int check_symbol(VALOR_LEXICO lexical){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    
    SYMBOL_TABLE* current_table = top_table;
        
        while(current_table != NULL){
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                return 0;
            }
            
            current_table = current_table->next;
           
            
        }
        
        return ERR_UNDECLARED;
    
    
}
int check_type_compatibility(int type1, int type2);
