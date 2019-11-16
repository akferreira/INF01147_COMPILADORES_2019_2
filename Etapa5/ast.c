

#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"
#include "symbol_table.h"
#include <string.h>

extern void *arvore;
extern SYMBOL_STACK *semantic_stack; 

int returning_own_function = 0;
int return_type = -1;
int line,column;

void libera (void *arvore){
    //printf("erase\n");
    erase_tree(arvore);
    clean_stack(semantic_stack);
    

    
    
}

extern SYMBOL_STACK *semantic_stack;




void exporta (void *arvore){
    
     FILE *arq1;
     arq1=fopen("e4.csv","w+");
     Percorrer_imprimir_file_DFS(arvore,arq1);
     fclose(arq1);
    
}

ast_node* get_null(){
    return NULL;
    
}


ast_node* new_empty_node(){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){
        new_node->node_type = 0;
        new_node->first_child = NULL;
        new_node->next_sibling = NULL;
        new_node->father = NULL;
        new_node->temp = NULL;
        new_node->code = NULL;
         new_node->vector_position = NULL;
        
        
        VALOR_LEXICO new_valor_lexico;
        new_valor_lexico.line =0;
        new_valor_lexico.value.intvalue = 0;
        new_valor_lexico.token_type =  TOKEN_ERRO;
        new_valor_lexico.var_type = 0;
        new_valor_lexico.value.str_value = NULL;
         
        
        new_node->ast_valor_lexico = new_valor_lexico;
        new_node->ast_valor_lexico.value.str_value = NULL;
    }
    
    
    return new_node;
    
    
}



ast_node* insert_child(ast_node *node, ast_node *child)
{
    if(node == NULL) return NULL;

    if(node->first_child == NULL)
    {
        node->first_child = child;
        node->first_child->father = node;
        
        node->ast_valor_lexico.line = child->ast_valor_lexico.line;
        node->ast_valor_lexico.column = child->ast_valor_lexico.column;
        
        
        
        ast_node *temp = node->first_child;
        
        while(temp != NULL){
            
            temp = temp->next_sibling;
            
            if(temp != NULL && temp->father == NULL) temp->father = node;
            
        }
        
        

        return node;
    }
    
    
     
    insert_sibling(node->first_child, child);
    
    
    return node;

}


//Adiciona o siobling (irmao), percorrendo a arvore ate achar um vazio.
ast_node* insert_sibling(ast_node *node, ast_node *sibling)
{
    if(node == NULL) return NULL;

    if(node->next_sibling == NULL)
    {
        node->next_sibling = sibling;
        
        
        
        
        
        node->next_sibling->father = node->father;
        
        ast_node *temp = node->next_sibling;
        
        
        
        while(temp != NULL){
            
             temp = temp->next_sibling;
            
            if(temp != NULL && temp->father == NULL) temp->father = node->father;
            
        }
        
        
        
        
        return node;
    }

    

    ast_node *current_sibling =  node->next_sibling;

    while(current_sibling->next_sibling != NULL)
    {
        current_sibling = current_sibling->next_sibling;
    }

    current_sibling->next_sibling = sibling;
    current_sibling->next_sibling->father = current_sibling->father;


    return node;
}

ast_node* new_ifelse_node(int node_type, ast_node* test_expression, ast_node *true_command_block , ast_node *false_command_block){
    ast_node* ifelse_node = new_empty_node();
    
    if(ifelse_node != NULL){
        ifelse_node->node_type = node_type;
        insert_child(ifelse_node,test_expression);
        insert_child(ifelse_node,true_command_block);
        if(false_command_block) insert_child(ifelse_node,false_command_block);
    }
    
    return ifelse_node;
    
}





ast_node* new_io_node(int node_type, VALOR_LEXICO lexico_io, ast_node *expression){
    if(node_type == INPUT_NODE){
        if(expression->ast_valor_lexico.token_type != TK_TYPE_ID){
            printf("Semantical error line %d, column %d : ERR_WRONG_PAR_INPUT\n",expression->ast_valor_lexico.line,expression->ast_valor_lexico.column);
            exit(ERR_WRONG_PAR_INPUT);
        }
        
    }
    
    else{
        int expression_type;
        if(expression->ast_valor_lexico.token_type == TK_TYPE_ID){
            expression_type = check_symbol(expression->ast_valor_lexico);
        }
        
        else expression_type = expression->ast_valor_lexico.var_type;
        
        //printf("%d-----%d",TYPE_CHAR,expression_type);
        
        
        if(expression_type == TYPE_CHAR) {
            printf("Semantical error line %d, column %d : ERR_WRONG_PAR_OUTPUT\n",expression->ast_valor_lexico.line,expression->ast_valor_lexico.column);
            exit(ERR_WRONG_PAR_OUTPUT);
            
        }
        
    }
    
    ast_node* io_node = new_leaf_node(node_type,lexico_io);
    
    //printf("Node type %d",node_type);
    
    if(io_node != NULL){
        insert_child(io_node,expression);
    }
    
    
    return io_node;
    
}


ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){

    new_node->node_type = node_type;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->father = NULL;
    new_node->ast_valor_lexico = ast_valor_lexico;
    new_node->vector_position = NULL;
    new_node->temp = NULL;
    new_node->code = NULL;
    
    if(node_type == VECTOR_NODE) new_node->ast_valor_lexico.nature = VECTOR;
    else if(node_type == ID_NODE) new_node->ast_valor_lexico.nature = VARIABLE;
    
    
    
//     printf("Sucessfully allocated leaf_node : %c || %d  /%s\n",node_type, ast_valor_lexico.intvalue,ast_valor_lexico.value);
    
    }
    
    
    return new_node;
    
    
}

ast_node* new_loop_for_node(int node_type, ast_node* initialization,ast_node *test_expression,ast_node* loop_command, ast_node* command_block){
    ast_node *for_loop_node = new_empty_node();
    
    if(for_loop_node != NULL){
        for_loop_node->node_type = node_type;
        insert_child(for_loop_node,initialization);
        insert_child(for_loop_node,test_expression);
        insert_child(for_loop_node,loop_command);
        insert_child(for_loop_node,command_block);
    }
    
    return for_loop_node;
    
    
}

ast_node* new_loop_while_node(int node_type, ast_node* expression, ast_node* command_block){
    ast_node* while_loop_node = new_empty_node();
    
    if(while_loop_node != NULL){
        while_loop_node->node_type = node_type;
        insert_child(while_loop_node,expression);
        insert_child(while_loop_node,command_block);
        
    }
    
    return while_loop_node;
    
    
}



ast_node* new_unary_expression(int node_type, ast_node *expression){
    printf("unary\n");
    
    if(expression->node_type == ID_NODE){
        SYMBOL_INFO exp_symbol = retrieve_symbol(expression->ast_valor_lexico);
        if(exp_symbol.nature == FUNCTION){
            printf("Semantical error line %d, column %d : ERR_FUNCTION\n",expression->ast_valor_lexico.line,expression->ast_valor_lexico.column);
            exit(ERR_FUNCTION);
    }
        
    }
    
    
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    new_node->node_type = node_type;
    new_node->first_child = expression;
    new_node->next_sibling = NULL;
    new_node->father = NULL;
    
    
    
    
    return new_node;
    
    
}

ast_node* new_assignment_node(ast_node *dest, ast_node *source, int initialization){
    //printf("assignment node \n");
  //  printf("Dest %s\n",dest->ast_valor_lexico.value.str_value);
    
    if(dest == NULL || source == NULL){
        return NULL;
    }
    ast_node *new_node = new_empty_node();
    
    //printf("used nat %d\t\n",dest->ast_valor_lexico.nature);
    
    
    
    SYMBOL_INFO dest_symbol = retrieve_symbol(dest->ast_valor_lexico);
    
    //printf("nat %d\n",dest_symbol.nature);
   // printf("size %d\n",dest_symbol.size);
    
    if(dest_symbol.nature == VECTOR && dest->ast_valor_lexico.nature != VECTOR){
        printf("Semantical error line %d, column %d : ERR_VECTOR\n",dest->ast_valor_lexico.line,dest->ast_valor_lexico.column);
        exit(ERR_VECTOR);
    }
    
     if(dest_symbol.nature == VECTOR){
         printf("%p\n",dest_symbol.vector_dimension);
        printf("vector dest %d\n",calculate_vector_position(dest_symbol.vector_dimension,dest->vector_position));   
     }
//         int max_vector_size = (dest_symbol.size/ get_size(dest->ast_valor_lexico))-1;
//         
//         if(dest->vector_position > max_vector_size || dest->vector_position < 0){
//             printf("Semantical error line %d, column %d : ERR_OUT_OF_BOUNDS\n",dest->ast_valor_lexico.line,dest->ast_valor_lexico.column);
//             exit(ERR_OUT_OF_BOUNDS);
//         }
//         
//         
//         
//         //printf("pos %d of %d \n",dest->vector_position,max_vector_size);
//     }
    
    
    
    if(dest_symbol.nature == VARIABLE && dest->ast_valor_lexico.nature != VARIABLE  && dest->ast_valor_lexico.nature != CONST){
        printf("Semantical error line %d, column %d : ERR_VARIABLE\n",dest->ast_valor_lexico.line,dest->ast_valor_lexico.column);
        exit(ERR_VARIABLE);
    }
    
    
    
    //Constantes só podem ser atribuidas em inicializações
    if(dest_symbol.nature == CONST && initialization == 0) {
        printf("Semantical error line %d, column %d : ERR_CONST\n",dest->ast_valor_lexico.line,dest->ast_valor_lexico.column);
        exit(ERR_CONST);
    }
    
    
    //Não pode se atribuir a uma função
    if(dest_symbol.nature == FUNCTION){
        printf("Semantical error line %d, column %d : ERR_FUNCTION\n",dest->ast_valor_lexico.line,dest->ast_valor_lexico.column);
        exit(ERR_FUNCTION);
    }
    int source_type;
   
    
    //Obtenção do tipo da expressão fonte
    if(source->ast_valor_lexico.token_type == TK_TYPE_ID){
        
        SYMBOL_INFO source_symbol =  retrieve_symbol(source->ast_valor_lexico);
        source_type = source_symbol.var_type;
    }
    
    else{
        source_type = source->ast_valor_lexico.var_type;
    }
    
    
    
    if(dest_symbol.var_type == TYPE_STRING || dest_symbol.var_type == TYPE_CHAR){
         line = dest->ast_valor_lexico.line; column = dest->ast_valor_lexico.column;
        
         new_node->ast_valor_lexico.var_type = check_assignment_type_compatibility(dest_symbol.var_type,source_type);
    }
    
    else{
        line = dest->ast_valor_lexico.line; column = dest->ast_valor_lexico.column;
        new_node->ast_valor_lexico.var_type = check_type_compatibility(dest_symbol.var_type,source_type);
    }
    
    
    
    
    
    
    
    if(new_node != NULL){
        
        
        new_node->node_type = '=';
        insert_child(new_node,dest);
        insert_child(new_node,source);
        
       // printf("checking %s dest %d\n",dest->ast_valor_lexico.value.str_value,check_symbol(dest->ast_valor_lexico));
        
        
         
        
    }
    
    return new_node;
}

    



ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right){
    if(left == NULL || right == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    
    if(new_node != NULL){
        
        
        
        new_node->node_type = node_type;
        insert_child(new_node,left);
        insert_child(new_node,right);
        
        int type1,type2;
        
        if(left->ast_valor_lexico.token_type == TK_TYPE_ID) {
            type1 = check_symbol(left->ast_valor_lexico);
        }
        else type1 = left->ast_valor_lexico.var_type;
        
            
        if(right->ast_valor_lexico.token_type ==  TK_TYPE_ID){
            type2 = check_symbol(right->ast_valor_lexico);
        }
        
        else type2 = right->ast_valor_lexico.var_type;
        
            
        if(left->node_type == ID_NODE){
            SYMBOL_INFO left_info = retrieve_symbol(left->ast_valor_lexico);
            if(left_info.nature == FUNCTION){
                printf("Semantical error line %d, column %d : ERR_FUNCTION\n",left->ast_valor_lexico.line,left->ast_valor_lexico.column);
                exit(ERR_FUNCTION);
            }
            
        }
        
         if(right->node_type == ID_NODE){
            SYMBOL_INFO right_info = retrieve_symbol(right->ast_valor_lexico);
            if(right_info.nature == FUNCTION){
                printf("Semantical error line %d, column %d : ERR_FUNCTION\n",right->ast_valor_lexico.line,right->ast_valor_lexico.column);
                exit(ERR_FUNCTION);
            }
            
        }
        
        new_node->ast_valor_lexico.var_type = check_type_compatibility(type1,type2);
         
        
    }
    
    return new_node;
}




ast_node* new_command_block_node(int node_type,ast_node *command_list){
    //printf("heey %p %d\n",command_list,command_list->ast_valor_lexico.line);
    
    if(command_list == NULL) return NULL;
    
    ast_node *command_block = new_empty_node();
    
    
    if(command_block != NULL){
        command_block->node_type = node_type;
        insert_child(command_block,command_list);
    }
    
    //printf("command block node %p//%p\n", command_block,command_list);

    return command_block;
}

ast_node* new_command_list_node(ast_node* current_commands,ast_node *next_commands){
    
    if(next_commands == NULL) return current_commands;
    
    
    if(current_commands != NULL){
//         printf("command list line %d\n",current_commands->ast_valor_lexico.line);
        if(next_commands != NULL) insert_sibling(current_commands,next_commands);
        return current_commands;
    }
    
    else return next_commands;
    
}

ast_node* new_expression_list_node(ast_node* current_expressions,ast_node *next_expressions){
    if(next_expressions == NULL) return NULL;
    
    if(current_expressions != NULL){
        
        
        if(current_expressions->node_type == ID_NODE){
            SYMBOL_INFO current_exp_symbol = retrieve_symbol(current_expressions->ast_valor_lexico);
            if(current_exp_symbol.nature == FUNCTION && current_expressions->node_type == ID_NODE){
                printf("Semantical error line %d, column %d : ERR_FUNCTION\n",current_expressions->ast_valor_lexico.line,current_expressions->ast_valor_lexico.column);
                exit(ERR_FUNCTION);
            }
        }
        
        
        if(next_expressions->node_type == ID_NODE){        
            SYMBOL_INFO next_exp_symbol = retrieve_symbol(next_expressions->ast_valor_lexico);

            if(next_exp_symbol.nature == FUNCTION && next_expressions->node_type == ID_NODE){
                printf("Semantical error line %d, column %d : ERR_FUNCTION\n",current_expressions->ast_valor_lexico.line,current_expressions->ast_valor_lexico.column);
                exit(ERR_FUNCTION);
            }
        }
       
       
        
        insert_sibling(current_expressions,next_expressions);
    }
    return current_expressions;
    
    
}
ast_node* new_const_parameter_node(int node_type,VALOR_LEXICO parameter_type,VALOR_LEXICO identifier){
    
    return new_parameter_node(node_type,1,parameter_type,identifier);
}

ast_node* new_nonconst_parameter_node(int node_type,VALOR_LEXICO parameter_type,VALOR_LEXICO identifier){
    return new_parameter_node(node_type,0,parameter_type,identifier);
    
}

ast_node* new_parameter_node(int node_type,int is_const,VALOR_LEXICO parameter_type,VALOR_LEXICO identifier){
   //printf("Paramter  %s\n", identifier.value.str_value);
    
    
    
    if(is_const) {
        identifier.nature = CONST;
        //insert_child(parameter_node,const_modifier);
    
    }
    
    else identifier.nature = VARIABLE;
    
    identifier.var_type = parameter_type.var_type;
    insert_parameters_function(identifier);
    
    insert_new_table_entry( identifier,NULL);
    free(parameter_type.value.str_value);
    //return NULL;
    ast_node *parameter_node = new_leaf_node('i',identifier);
    return parameter_node;
    
    
    //insert_child(parameter_node,parameter_type);
    //insert_child(parameter_node,identifier);
        
        
        
        
    
    
    
    
}



ast_node* new_parameter_list_node(ast_node* current_parameters,ast_node *next_parameters){
    if(next_parameters == NULL) return NULL;
    
    if(current_parameters != NULL){
        insert_sibling(current_parameters,next_parameters);

    }
    return current_parameters;
    
    
}

ast_node* new_nonstatic_function_declaration_node(int node_type, VALOR_LEXICO identifier,ast_node* parameter_list, ast_node* command_block){
    return new_function_declaration_node(node_type,0, identifier,parameter_list,command_block);
    
}




ast_node* new_static_function_declaration_node(int node_type, VALOR_LEXICO identifier,ast_node* parameter_list, ast_node* command_block){
    
    return new_function_declaration_node(node_type,1,  identifier,parameter_list,command_block);
}




ast_node* new_function_declaration_node(int node_type, int is_static, VALOR_LEXICO identifier, ast_node* parameter_list, ast_node* command_block)
{
    initialize_stack();

    //printf("function declaration %s\n",identifier.value.str_value);
        
    //identifier.var_type = var_type.var_type;
    identifier.nature = FUNCTION;
    
    if(return_type >= 0){
        //printf("hey %d, %d\n",identifier.var_type,return_type);
        
        check_return_type_compatibility(identifier.var_type,return_type);
        
        return_type = -1;
        
    }
    
    
    erase_tree(parameter_list);
    //free(var_type.value.str_value);
    //free(function_name);
    free(identifier.value.str_value);
        
        
    
    
    
    //printf("command block%p\n",command_block);
    return command_block;
}




ast_node* new_function_call_node(int node_type, ast_node* identifier, ast_node* parameter_list){
    ast_node *function_call_node = new_empty_node();
    
    //printf("function call\n");
    //
    
    if(function_call_node != NULL){
        function_call_node->node_type = node_type;
        function_call_node->ast_valor_lexico.token_type = identifier->ast_valor_lexico.token_type;
        
        insert_child(function_call_node,identifier);
        if(parameter_list) insert_child(function_call_node,parameter_list);
        function_call_node->ast_valor_lexico.value.str_value = strdup(identifier->ast_valor_lexico.value.str_value);
        
        
        
        
    }
    
    else {
        return NULL;
    }
    
    //printf("check %s\n",identifier->ast_valor_lexico.value.str_value);
    check_symbol(identifier->ast_valor_lexico);
    //printf("Function name check %d\n",check_symbol(identifier->ast_valor_lexico));
    
    ARG_LIST *arg_list = retrieve_arg_list(identifier->ast_valor_lexico.value.str_value);
    
    
  //  printf("arg list %p\n\n",arg_list);
   // printf("%s\n",arg_list->arg_info->name);
    
    ARG_LIST *next_arg = arg_list;
    ast_node *next_parameter = parameter_list;
    
    while(next_arg != NULL && next_parameter != NULL){
        if(next_parameter->ast_valor_lexico.token_type == TK_TYPE_ID){
            next_parameter->ast_valor_lexico.var_type = check_symbol(next_parameter->ast_valor_lexico);
        }
        
        
        line = next_parameter->ast_valor_lexico.line;
        column = next_parameter->ast_valor_lexico.column;
        //printf("%d||%d\n",next_arg->arg_info->var_type,next_parameter->ast_valor_lexico.var_type);
        check_parameter_type_compatibility(next_arg->arg_info->var_type,next_parameter->ast_valor_lexico.var_type);
        
        next_arg = next_arg->next_argument;
        next_parameter = next_parameter->next_sibling;
        
        
    }
    
    if(next_arg != NULL && next_parameter == NULL) {
        printf("Semantical error line %d, column %d : ERR_MISSING_ARGS\n",identifier->ast_valor_lexico.line,identifier->ast_valor_lexico.column);
        exit(ERR_MISSING_ARGS);
    }
    if(next_arg == NULL && next_parameter != NULL) {
        printf("Semantical error line %d, column %d : ERR_EXCESS_ARGS\n",identifier->ast_valor_lexico.line,identifier->ast_valor_lexico.column);
        exit(ERR_EXCESS_ARGS);
    }
     
     
    
    
    return function_call_node;
}

ast_node* new_static_global_var_declaration_node(int node_type,VALOR_LEXICO  var_type,  VALOR_LEXICO identifier, ARRAY_DIMENSIONS *vector_dimension){
    
    return new_global_var_declaration_node(node_type, 1,var_type,identifier, vector_dimension);
    
    
}
ast_node* new_nonstatic_global_var_declaration_node(int node_type,VALOR_LEXICO  var_type,  VALOR_LEXICO identifier,ARRAY_DIMENSIONS *vector_dimension){
    return new_global_var_declaration_node(node_type,0,var_type,identifier, vector_dimension);
}

ast_node* new_global_var_declaration_node(int node_type, int is_static,VALOR_LEXICO  var_type, VALOR_LEXICO identifier, ARRAY_DIMENSIONS *vector_dimension){
    
    if(vector_dimension != NULL){
       identifier.nature = VECTOR;
    }
    
    //ast_node* global_var_node = new_empty_node();
    //printf("global declaration of lenght %d\n",vector_lenght);
    initialize_stack();
        
        
    identifier.var_type = var_type.var_type;
    insert_new_table_entry( identifier,vector_dimension);
    //printf("Declaration returned %d\n",insert_new_table_entry( identifier,vector_lenght));
        
        
        
    
    free(var_type.value.str_value);
    var_type.value.str_value = NULL;
    free(identifier.value.str_value);
    
    //erase_tree(global_var_node);
    return NULL;
}

ast_node* new_global_grammar_node(int node_type,ast_node *ast_root, ast_node *current_global_node, ast_node* next_global_nodes){
   
   
    
    if(arvore == NULL){
        
        ast_node* temp_node = new_empty_node();
        temp_node->node_type = node_type;
        arvore = temp_node;
        
        
        
       if(current_global_node != NULL)  insert_child(arvore,current_global_node);
        if(next_global_nodes != NULL) insert_child(arvore,next_global_nodes);
        return ast_root;
        
        
        
    }
    
    else{
        if(current_global_node != NULL)  insert_child(arvore,current_global_node);
        
        //if(next_global_nodes != NULL) insert_child(ast_root,next_global_nodes);
        
        
        return ast_root;
        
        
        
    }
    
    
    
}

MODIFIER_S modifier(int modifier_static, int modifier_const){
    MODIFIER_S modifier;
    modifier.is_const = modifier_const;
    modifier.is_static = modifier_static;
    
    return modifier;
    
}




ast_node* new_local_var_declaration_node(int node_type, MODIFIER_S modifiers,VALOR_LEXICO var_type, VALOR_LEXICO identifier, ast_node* initialization){
   // printf("local var\n");
    
    identifier.var_type = var_type.var_type;
    
    if(modifiers.is_const) identifier.nature = CONST;
    else identifier.nature = VARIABLE;
    
    if( var_type.value.str_value != NULL) {
        free(var_type.value.str_value);
        var_type.value.str_value = NULL;
    }
    
    
    //char *name = strdup(identifier.value.str_value);
    
    insert_new_table_entry( identifier,NULL);
    
    //printf("local var 2\n");

    if(initialization != NULL) {
        
        //identifier.value.str_value = name;
        
        return new_assignment_node(new_leaf_node('I',identifier), initialization,1);
    }
        
        
    
//     if( var_type.value.str_value != NULL) {
//         free(var_type.value.str_value);
//         var_type.value.str_value = NULL;
//     }
//     
    //free(name);
    free(identifier.value.str_value);
    return NULL;
    
    
}
ast_node* new_shift_command_node(int node_type,ast_node *identifier, ast_node *shift_type, ast_node *expression){
    ast_node* shift_node = new_empty_node();
    
    if(shift_node != NULL){
        shift_node->node_type = node_type;
        insert_child(shift_node,identifier);
        insert_child(shift_node,shift_type);
        insert_child(shift_node,expression);
        
    }
    
    return shift_node;
    
    
}

ast_node* new_return_command_node(int node_type, VALOR_LEXICO lexico, ast_node* expression){
    ast_node* return_node = new_leaf_node(node_type,lexico);
    
    if(return_node != NULL){
        insert_child(return_node,expression);
        
        
    }
    
    //printf("%d return\n",expression->ast_valor_lexico.var_type);
    
    if(expression->ast_valor_lexico.token_type == TK_TYPE_ID){
        //printf("Expression Node type %c ",expression->node_type);
        return_type = check_symbol(expression->ast_valor_lexico);
        
        
        
    }
    
    else{
        return_type = expression->ast_valor_lexico.var_type;
    }
    
    
    
    return return_node;
    
}


ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *true_expression, ast_node *false_expression){
    if(test_expression == NULL || false_expression == NULL || true_expression == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    if(new_node != NULL){
        new_node->node_type = node_type;
        new_node->first_child = test_expression;
        insert_sibling(new_node->first_child,false_expression);
        insert_sibling(new_node->first_child,true_expression);
    }
    
    
    return new_node;
    
}

void print_node_info(ast_node *node){
    printf("\nNode type:%c | Address: %p| First_child: %p| Sibling: %p\n",node->node_type, node,node->first_child,node->next_sibling);
    printf("[%d]",node->ast_valor_lexico.value.intvalue);
}


void Percorrer_imprimir_file_DFS(ast_node *Tree,FILE *arq)
{
    if(Tree == NULL)
        return;
    
    fprintf(arq,"%p, %p [%c] \t%d",Tree->father, Tree,Tree->node_type,Tree->ast_valor_lexico.line);
    
    fprintf(arq,"\n");
    
    Percorrer_imprimir_file_DFS(Tree->first_child,arq);
    //printf("%p %d\n",Tree->node_node_father, Tree->node_type);
    Percorrer_imprimir_file_DFS(Tree->next_sibling,arq);

}


void print_node_info_csv(ast_node * node, FILE *arq){
    if(node == NULL) return;
    
    ast_node *root = node;
    
    fprintf(arq,"Node type %c \t[%d] \t | Address: %p|\n",node->node_type,node->ast_valor_lexico.value.intvalue,node);
    
    
    if(node->first_child != NULL){
        fprintf(arq,"%p, %p [%c]\n",root,node->first_child,node->node_type);
        
        ast_node *next = node->first_child->next_sibling;
        
        while(next != NULL){
            fprintf(arq,"%p,%p [%c]\n",root,next,next->node_type);
            next = next->next_sibling;
        }
    print_node_info_csv(node->first_child,arq);
    print_node_info_csv(node->first_child->next_sibling,arq);    
        
    }
    
    
    
    
}




void erase_tree(ast_node *root){
    
    if(root == NULL) return;
    
    erase_tree(root->first_child);
    erase_tree(root->next_sibling);
    
    if(root->ast_valor_lexico.token_type == TK_TYPE_RESERVED_WORD || root->ast_valor_lexico.token_type == TK_TYPE_ID || root->ast_valor_lexico.var_type == TYPE_STRING ){
        //printf("%d|%d\n",root->ast_valor_lexico.line,root->ast_valor_lexico.column);
        if(root->ast_valor_lexico.value.str_value) free(root->ast_valor_lexico.value.str_value);
        root->ast_valor_lexico.value.str_value = NULL;
    }

    free(root);
    root = NULL;
    
}


void free_lexical(VALOR_LEXICO lexical){
    if(lexical.value.str_value == NULL){
        return;
    }
    
    free(lexical.value.str_value);
    lexical.value.str_value = NULL;
    
}












