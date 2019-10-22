#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



SYMBOL_STACK *semantic_stack = NULL;

int create_new_scope(){
    if(semantic_stack == NULL){
        semantic_stack = malloc(sizeof(SYMBOL_STACK));
        if(semantic_stack != NULL){
            semantic_stack->next = NULL;
            semantic_stack->symbol_table = malloc(sizeof(SYMBOL_TABLE));
            semantic_stack->symbol_table->symbol_info = NULL;
            semantic_stack->symbol_table->next = NULL;
            semantic_stack->symbol_table->argument_list = NULL;
        
            return 0;
        }
        
        else return -1;
        
        
    }
    
    else{
        SYMBOL_STACK* new_stack_entry = malloc(sizeof(SYMBOL_STACK));
        
        if(new_stack_entry != NULL){
            SYMBOL_STACK *current_stack_entry = semantic_stack;
            
            new_stack_entry->next = NULL;
            new_stack_entry->symbol_table = malloc(sizeof(SYMBOL_TABLE));
            new_stack_entry->symbol_table->symbol_info = NULL;
            new_stack_entry->symbol_table->argument_list = NULL;
            new_stack_entry->next = current_stack_entry;
            
            semantic_stack = new_stack_entry;
            
            return 0;
        }
        
        else return -1;
        
        
    }
    
    
}


void copy_lexical_to_symbol(SYMBOL_INFO *symbol, VALOR_LEXICO lexical){
    
    symbol->line = lexical.line;
    symbol->column = lexical.column;
    symbol->nature = lexical.nature;
    symbol->var_type = lexical.var_type;
    strcpy(symbol->name,lexical.value.str_value);
    
    
}



int insert_new_table_entry(VALOR_LEXICO lexical){
    SYMBOL_TABLE* top_table = semantic_stack->symbol_table;
    
    
    if(top_table->symbol_info == NULL){
        top_table->symbol_info = malloc(sizeof(SYMBOL_INFO));
        
        if(top_table->symbol_info != NULL){
            copy_lexical_to_symbol(top_table->symbol_info,lexical);
            return 0;
        }
        
        else return -1;
        
    }
    
    else{
        //checa se a primeira entrada da tabela já é declaração repetida ou não
        if(strcmp(semantic_stack->symbol_table->symbol_info->name,lexical.value.str_value) == 0){
            return ERR_DECLARED;
        }
        
        SYMBOL_TABLE* current_table = semantic_stack->symbol_table->next;
        
        while(current_table != NULL){
            if(strcmp(current_table->symbol_info->name,lexical.value.str_value) == 0){
                return ERR_DECLARED;
            }
            
            current_table = current_table->next;
            
        }
        
        current_table->symbol_info = malloc(sizeof(SYMBOL_INFO));
        
        if(current_table->symbol_info != NULL){
            copy_lexical_to_symbol(current_table->symbol_info,lexical);
            return 0;
        }
        
        else return -1;
    }
    
}
SYMBOL_INFO* retrieve_symbol(VALOR_LEXICO lexical);
int check_symbol(VALOR_LEXICO lexical);
int check_type_compatibility(VALOR_LEXICO lexical1, VALOR_LEXICO lexical2);
