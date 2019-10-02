#include <stdlib.h>
#include <stdio.h>
#include "ast.h"





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
