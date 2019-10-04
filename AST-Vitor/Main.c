#include "ast.h"

int main()
{
    VALOR_LEXICO a;
    a.line = 0;

    ast_node *test = new_leaf_node(1,a);

    insert_child_ast_node(test,new_leaf_node(2,a));
    insert_child_ast_node(test,new_leaf_node(8,a));
    insert_child_ast_node(test,new_leaf_node(9,a));
    //insert_child_ast_node(test, new_leaf_node(3,a));
    insert_child_ast_node(test->first_child,new_leaf_node(3,a));
    //insert_child_ast_node(test->next_sibling, new_leaf_node(5,a));
    //insert_child_ast_node(test->first_child,new_leaf_node(6,a));
    //insert_child_ast_node(test->first_child,new_leaf_node(7,a));


    exporta (test);
    libera (test);


    return 0;
}
