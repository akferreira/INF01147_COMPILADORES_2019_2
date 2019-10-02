#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right){
    if(left == NULL || right == NULL){
        return NULL;
    }
    
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    new_node->node_type = node_type;
    new_node->first_child = left;
    new_node->first_child->next_sibling = right;
    new_node->next_sibling = NULL;
    
    
    return new_node;
}





int main(){
ast_node test;

test.children_count = 2;
test.node_type = 4;
test.first_child = (ast_node*) malloc(sizeof(ast_node));
test.next_sibling = (ast_node*) malloc(sizeof(ast_node));

test.next_sibling->node_type = 4;
test.first_child->node_type = 2;

printf("\n%p -- %p\n|\n%p",&test,&test.next_sibling,&test.first_child);
    
    
    
return 0;
}
