#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"







typedef struct  _valor_lexico{
    int line;
    int column;
    int nature;
    int token_type;
    int var_type;
//     char charvalue;
//     char *value;
//     int intvalue;
//     double fvalue;
    
    union{
        char charvalue;
        char *str_value;
        int intvalue;
        double fvalue;
    } value;
    
    
} VALOR_LEXICO;

typedef struct _modifiers{
    int is_static;
    int is_const;
} MODIFIER_S;




typedef struct _ast_node {
    int node_type;
    int children_count;
    VALOR_LEXICO ast_valor_lexico;
    
    
    struct _ast_node *first_child;
    struct _ast_node *next_sibling;
    struct _ast_node *father;
    
} ast_node;

extern void *arvore;
void erase_tree(ast_node *root);


    
ast_node* insert_child(ast_node *node,ast_node *child);

ast_node* insert_sibling(ast_node *node,ast_node *sibling);

void print_node_info_csv(ast_node * node,FILE *arq);

void Percorrer_imprimir_file_DFS(ast_node *Tree,FILE *arq);

void print_node_info(ast_node *node);

void print_tree(ast_node *root);

int get_child_count(ast_node *node);

int get_sibling_count(ast_node *node);

ast_node* get_null();

ast_node* get_nth_child_ast_node(int position);

ast_node* get_nth_sibling_ast_node(int position);

ast_node* new_assignment_node(ast_node *dest, ast_node *source);


ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right);

ast_node* new_command_block_node(int node_type,ast_node *command_list);

ast_node* new_command_list_node(ast_node* current_commands,ast_node *next_commands);

ast_node* new_empty_node();

ast_node* new_expression_list_node(ast_node* current_expressions,ast_node *next_expressions);

ast_node* new_nonstatic_function_declaration_node(int node_type, VALOR_LEXICO var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block);

ast_node* new_static_function_declaration_node(int node_type, VALOR_LEXICO static_lexical, VALOR_LEXICO var_type, ast_node* indentifier,ast_node* parameter_list, ast_node* command_block);
ast_node* new_function_declaration_node(int node_type, ast_node* modifier_static, VALOR_LEXICO var_type, ast_node* identifier ,ast_node* parameter_list, ast_node* command_block);




ast_node* new_parameter_list_node(ast_node* current_parameters,ast_node *next_parameters);


ast_node* new_const_parameter_node(int node_type,VALOR_LEXICO const_lexical,VALOR_LEXICO parameter_type,ast_node *identifier);
ast_node* new_nonconst_parameter_node(int node_type,VALOR_LEXICO parameter_type,ast_node *identifier);

ast_node* new_parameter_node(int node_type,ast_node* const_modifier,VALOR_LEXICO parameter_type,ast_node *identifier);



ast_node* new_function_call_node(int node_type, ast_node* identifier, ast_node* parameter_list);

ast_node* new_global_grammar_node(int node_type,ast_node *ast_root, ast_node *current_global_node, ast_node* next_global_nodes);

ast_node* new_ifelse_node(int node_type, ast_node* test_expression, ast_node *true_command_block , ast_node *false_command_block);

ast_node* new_io_node(int node_type, VALOR_LEXICO lexico_io, ast_node *expression);

ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico);

ast_node* new_loop_for_node(int node_type, ast_node* initialization,ast_node *test_expression,ast_node* loop_command, ast_node* command_block);

ast_node* new_loop_while_node(int node_type, ast_node* expression, ast_node* command_block);



MODIFIER_S modifier(int modifier_static, int modifier_const);

ast_node* new_static_global_var_declaration_node(int node_type,VALOR_LEXICO  var_type, VALOR_LEXICO identifier, int vector_lenght);
ast_node* new_nonstatic_global_var_declaration_node(int node_type,VALOR_LEXICO  var_type, VALOR_LEXICO identifier,int vector_lenght);

ast_node* new_global_var_declaration_node(int node_type, int is_static,VALOR_LEXICO  var_type, VALOR_LEXICO identifier,int vector_lenght);

ast_node* new_local_var_declaration_node(int node_type, MODIFIER_S modifiers ,VALOR_LEXICO var_type,VALOR_LEXICO identifier, ast_node* initialization);

ast_node* new_shift_command_node(int node_type,ast_node *identifier, ast_node *shift_type, ast_node *expression);

ast_node* new_return_command_node(int node_type, VALOR_LEXICO lexico, ast_node* expression);

ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *true_expression, ast_node *false_expression);

ast_node* new_unary_expression(int node_type, ast_node *expression);




#endif // AST_H_INCLUDED



