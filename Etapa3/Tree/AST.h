#include<stdio.h>
#include<stdlib.h>



struct stru_node {
    int data;
    struct stru_node *next;
    struct stru_node *child;
};typedef struct stru_node node;

node * new_node(int);
node * add_sibling(node *, int);
node * add_child(node *, int);



