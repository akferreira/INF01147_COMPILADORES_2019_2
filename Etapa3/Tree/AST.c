#include "AST.h"

node * new_node(int data)
{
    node *new_node = malloc(sizeof(node));

    if ( new_node ) {
        new_node->next = NULL;
        new_node->child = NULL;
        new_node->data = data;
    }

    return new_node;
}

node * add_sibling(node * n, int data)
{
    if ( n == NULL )
        return NULL;

    while (n->next)
        n = n->next;

    return (n->next = new_node(data));
}

node * add_child(node * n, int data)
{
    if ( n == NULL )
        return NULL;

    if ( n->child )
        return add_sibling(n->child, data);
    else
        return (n->child = new_node(data));
}