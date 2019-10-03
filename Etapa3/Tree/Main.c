
#include "AST.h"
#include "AST.c"
int main()
{
    int i;
    node *root = new_node(0);

    for ( i = 1; i <= 3; i++ )
       add_child(root, i);
    printf("oi");
}
