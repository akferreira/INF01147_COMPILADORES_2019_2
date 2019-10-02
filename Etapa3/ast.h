#ifndef AST_H
#define AST_H

enum TOKEN_TYPE {
    TK_TYPE_RESERVED_WORD, 
    TK_TYPE_SPECIAL_CHAR, 
    TK_TYPE_OPERATOR, 
    TK_TYPE_ID, 
    TK_TYPE_LITERAL 
};

enum NODE_TYPE{
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    INVERT
    
};




typedef struct  _valor_lexico{
    int line;
    int token_type;
    int var_type;
    
    union{
        char charvalue;
        char *value;
        int intvalue;
        double fvalue;
    } value;
    
    
} VALOR_LEXICO;

typedef struct _symbol_info{
    
    
} symbol_info;




typedef struct _ast_node {
    int node_type;
    int children_count;
    VALOR_LEXICO ast_valor_lexico;
    
    
    struct _ast_node *first_child;
    struct _ast_node *next_sibling;
    
} ast_node;

ast_node* new_unary_expression(int node_type, ast_node *exp);

ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right);

ast_node* new_ternary_expression(int node_type, ast_node *test_exp,ast_node *false_exp, ast_node *true_exp);


#endif // AST_H_INCLUDED
