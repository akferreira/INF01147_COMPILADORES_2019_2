#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "parser.tab.h"
#include "symbol_table.h"

extern void *arvore;
extern SYMBOL_STACK *semantic_stack; 

void libera (void *arvore){
    printf("erase\n");
    erase_tree(arvore);
    //clean_stack(semantic_stack);
    

    
    
}

extern SYMBOL_STACK *semantic_stack;




void exporta (void *arvore){
    
     FILE *arq1;
     arq1=fopen("e3.csv","w+");
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
        
        VALOR_LEXICO new_valor_lexico;
        new_valor_lexico.line =0;
        new_valor_lexico.value.intvalue = 0;
        new_valor_lexico.token_type =  TOKEN_ERRO;
        new_valor_lexico.var_type = 0;
        //new_valor_lexico.value = NULL;
         
        
        new_node->ast_valor_lexico = new_valor_lexico;
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
    ast_node* io_node = new_leaf_node(node_type,lexico_io);
    
    
    
    if(io_node != NULL){
        insert_child(io_node,expression);
    }
    
    
    return io_node;
    
}


ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){
    
//     if(temp_table == NULL){
//         printf("create temp table\n");
//         temp_table = malloc(sizeof(SYMBOL_TABLE));
//     }
        
        
  /*      
    printf("%c",node_type);
    if(ast_valor_lexico.token_type == TK_TYPE_RESERVED_WORD || ast_valor_lexico.var_type == TK_LIT_STRING){
        printf("||%s",ast_valor_lexico.value.str_value);
    }*/
    
//     if(ast_valor_lexico.var_type == TK_LIT_INT){
//         printf("\n%d",ast_valor_lexico.value.intvalue);
//     }
    
//     printf("\n%d / %d\n",ast_valor_lexico.line,ast_valor_lexico.column);

    new_node->node_type = node_type;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->father = NULL;
    new_node->ast_valor_lexico = ast_valor_lexico;
    
    
    
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
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    new_node->node_type = node_type;
    new_node->first_child = expression;
    new_node->next_sibling = NULL;
    
    
    
    return new_node;
    
    
}

ast_node* new_assignment_node(ast_node *dest, ast_node *source){
    //printf("assignment node\n");
    
    if(dest == NULL || source == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    if(new_node != NULL){
        
        
        new_node->node_type = '=';
        insert_child(new_node,dest);
        insert_child(new_node,source);
        
        //printf("checking dest %d\n",check_symbol(dest->ast_valor_lexico));
        
        
         
        
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
        
        //printf()
        
        if(left->ast_valor_lexico.token_type == TK_TYPE_ID) check_symbol(left->ast_valor_lexico);
        
            
            if(right->ast_valor_lexico.token_type ==  TK_TYPE_ID) check_symbol(right->ast_valor_lexico);
        
        //printf("binary %d//%d\n",left->ast_valor_lexico.var_type,right->ast_valor_lexico.var_type);
        
//         printf("new_node");
//         print_node_info(new_node);
//         printf("left and right");
         
        
    }
    
    return new_node;
}




ast_node* new_command_block_node(int node_type,ast_node *command_list){
    //printf("command list %p\n",command_list);
   
    
    if(command_list == NULL) return NULL;
    
    ast_node *command_block = new_empty_node();
    
    
    if(command_block != NULL){
        command_block->node_type = node_type;
        insert_child(command_block,command_list);
    }
    
   
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
    
    if(current_expressions == NULL){
        insert_sibling(current_expressions,next_expressions);
    }
    return current_expressions;
    
    
}
ast_node* new_const_parameter_node(int node_type,VALOR_LEXICO const_lexical,ast_node* parameter_type,ast_node *identifier){
    ast_node* const_node = new_leaf_node(node_type,const_lexical);
    
    return new_parameter_node(node_type,const_node,parameter_type,identifier);
}

ast_node* new_nonconst_parameter_node(int node_type,ast_node* parameter_type,ast_node *identifier){
    return new_parameter_node(node_type,NULL,parameter_type,identifier);
    
}

ast_node* new_parameter_node(int node_type,ast_node* const_modifier,ast_node* parameter_type,ast_node *identifier){
    ast_node* parameter_node = new_empty_node();
    
    if(parameter_node != NULL){
        parameter_node->node_type = node_type;
        if(const_modifier != NULL) {
            identifier->ast_valor_lexico.nature = CONST;
            insert_child(parameter_node,const_modifier);
        
        }
        
        else identifier->ast_valor_lexico.nature = VARIABLE;
        
        identifier->ast_valor_lexico.var_type = parameter_type->ast_valor_lexico.var_type;
        
        insert_child(parameter_node,parameter_type);
        insert_child(parameter_node,identifier);
        
        
        
        
    }
    
    return parameter_node;
    
}



ast_node* new_parameter_list_node(ast_node* current_parameters,ast_node *next_parameters){
    if(next_parameters == NULL) return NULL;
    
    if(current_parameters == NULL){
        insert_sibling(current_parameters,next_parameters);
    }
    return current_parameters;
    
    
}

ast_node* new_nonstatic_function_declaration_node(int node_type, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){
    return new_function_declaration_node(node_type,NULL,var_type, identifier,parameter_list,command_block);
    
}




ast_node* new_static_function_declaration_node(int node_type, VALOR_LEXICO static_lexical, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){
    ast_node* static_node = new_leaf_node('S',static_lexical);
    
    return new_function_declaration_node(node_type,static_node,var_type,  identifier,parameter_list,command_block);
}


ast_node* new_function_declaration_node(int node_type, ast_node* modifier_static, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){
   
    
    ast_node *function_node = new_empty_node();
    
    if(function_node != NULL){
         printf("function declaration %s\n",identifier->ast_valor_lexico.value.str_value);
        
       
        
        function_node->node_type = node_type;
        
        if(modifier_static != NULL){
            insert_child(function_node,modifier_static);
        }
        
        
        insert_child(function_node,var_type);
        insert_child(function_node,identifier);
        if(parameter_list != NULL) insert_child(function_node,parameter_list);
        insert_child(function_node,command_block);
        
        identifier->ast_valor_lexico.var_type = var_type->ast_valor_lexico.var_type;
        identifier->ast_valor_lexico.nature = FUNCTION;
        
        insert_new_table_entry(identifier->ast_valor_lexico);
        erase_tree(function_node);
        
        
    }
    
    return NULL;
    return function_node;
}

ast_node* new_function_call_node(int node_type, ast_node* identifier, ast_node* parameter_list){
    ast_node *function_call_node = new_empty_node();
    
    if(function_call_node != NULL){
        function_call_node->node_type = node_type;
        insert_child(function_call_node,identifier);
        insert_child(function_call_node,parameter_list);
        
    }
    
    return function_call_node;
}

ast_node* new_static_global_var_declaration_node(int node_type, VALOR_LEXICO static_lexical,ast_node* var_type, ast_node* identifier){
    ast_node* static_node = new_leaf_node('S',static_lexical);
    
    return new_global_var_declaration_node(node_type,static_node,var_type,identifier);
    
    
}
ast_node* new_nonstatic_global_var_declaration_node(int node_type,ast_node* var_type, ast_node* identifier){
    return new_global_var_declaration_node(node_type,NULL,var_type,identifier);
}

ast_node* new_global_var_declaration_node(int node_type, ast_node* modifier_static,ast_node* var_type, ast_node* identifier){
    ast_node* global_var_node = new_empty_node();
    printf("global declaration\n");
    initialize_stack();
    
    
    if(global_var_node != NULL){
        
        global_var_node->node_type = node_type;
        if(modifier_static != NULL) insert_child(global_var_node,modifier_static); 
        insert_child(global_var_node,var_type);
        insert_child(global_var_node,identifier);
        
        identifier->ast_valor_lexico.var_type = var_type->ast_valor_lexico.var_type;
        printf("Declaration returned %d\n",insert_new_table_entry( identifier->ast_valor_lexico));
        
        
        
    }
    
    erase_tree(global_var_node);
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


ast_node* new_modifier_node(int node_type1, int node_type2, VALOR_LEXICO lexico1, VALOR_LEXICO lexico2){
    ast_node* modifier1 = new_leaf_node(node_type1,lexico1);
    
    if(node_type2){
        ast_node* modifier2 = new_leaf_node(node_type2,lexico2);
        insert_sibling(modifier1 , modifier2);
    }
    
    return modifier1;
    
    
}

ast_node* new_local_var_declaration_node(int node_type, ast_node* modifiers,ast_node* var_type, ast_node* identifier, ast_node* initialization){
    if(var_type == NULL || identifier == NULL) return NULL;
    
    ast_node *new_node = new_empty_node();
   
    
    
    if(new_node != NULL){
         printf("%s [%s] local declaration\n",var_type->ast_valor_lexico.value.str_value,identifier->ast_valor_lexico.value.str_value);
        
        new_node->node_type = node_type;
        
        
        if(modifiers != NULL) {
            erase_tree(modifiers);
            //insert_child(new_node, modifiers);
        }
        
        //insert_child(new_node,var_type);
        
        
        
        
        
        identifier->ast_valor_lexico.var_type = var_type->ast_valor_lexico.var_type;
        printf("Local Declaration returned %d\n",insert_new_table_entry( identifier->ast_valor_lexico));
        
        if(initialization != NULL) {
            insert_child(new_node,identifier);
            insert_child(new_node,initialization);
            return new_node;
        }
        
        erase_tree(var_type);
    }
    
    
    erase_tree(new_node);
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
    
    fprintf(arq,"%p, %p [%c]\n",Tree->father, Tree,Tree->node_type);
    
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
//     printf("erase\n");
//     
//     //printf("\naaa   %d | %p | %c | %s\n",root->ast_valor_lexico.column,root->ast_valor_lexico.value,root->node_type,root->ast_valor_lexico.value);
//     printf("%d||%d\n", root->ast_valor_lexico.token_type,TK_TYPE_RESERVED_WORD);
//     printf("%d||%d\n", root->ast_valor_lexico.var_type,TK_LIT_STRING); TK_LIT_STRING
//     printf("child : %c\n",root->node_type);
    
    if(root->ast_valor_lexico.token_type == TK_TYPE_RESERVED_WORD || root->ast_valor_lexico.var_type == TYPE_STRING){
//         printf("freeing\n");
        free(root->ast_valor_lexico.value.str_value);
        root->ast_valor_lexico.value.str_value = NULL;
    }
    free(root);
    root = NULL;
    
}











