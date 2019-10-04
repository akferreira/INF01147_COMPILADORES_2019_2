
#include "ast.h"

//extern void *arvore;

void libera (void *arvore)
{
    liberta_arvore(arvore);
}


void liberta_arvore(ast_node *Tree)
{
    if(Tree == NULL)
        return;

    liberta_arvore(Tree->first_child);
    liberta_arvore(Tree->next_sibling);
    free(Tree);

}



void exporta (void *arvore)
{
    /*
        Imprime a arvore em um arquivo .csv, de forma recursivaseguindo o algoritmo DFS.
    */
    FILE *arq;
    arq=fopen("Arvore.csv","w+");

    Percorrer_imprimir_file_DFS(arvore,arq);

    fclose(arq);

}


void Percorrer_imprimir_file_DFS(ast_node *Tree,FILE *arq)
{
    if(Tree == NULL)
        return;
    Percorrer_imprimir_file_DFS(Tree->first_child,arq);
    fprintf(arq,"%p, %p\n",Tree->node_father, Tree);
    //printf("%p %d\n",Tree->node_father, Tree->node_type);
    Percorrer_imprimir_file_DFS(Tree->next_sibling,arq);

}




ast_node* new_empty_node()
{
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    if(new_node != NULL)
    {
        new_node->node_type = UNINITIALIZED;
        new_node->first_child = NULL;
        new_node->next_sibling = NULL;
    }


    return new_node;
}

int insert_child_ast_node(ast_node *node, ast_node *child)
{
    if(node == NULL)
        return -1;

    if(node->first_child == NULL)
    {
        //printf("First child\n");
        //printf("%d\n",child->node_type);
        node->first_child = child;
        node->first_child->node_father = node;

        return 0;
    }

    insert_ast_node_sibling_list(node->first_child, child);
    return 0;

}


//Adiciona o siobling (irmao), percorrendo a arvore ate achar um vazio.
int insert_ast_node_sibling_list(ast_node *node, ast_node *sibling)
{
    if(node == NULL)
    {
        return -1;
    }

    if(node->next_sibling == NULL)
    {
        //printf("Inserting first sibling\n");
        //printf("%d\n",sibling->node_type);
        node->next_sibling = sibling;
        node->next_sibling->node_father = node->node_father;
        return 0;
    }

    //printf("%p\n",*node->next_sibling);
    //printf("%d\n",node->next_sibling->node_type);
    //printf("%d\n",sibling->node_type);


    ast_node *current_sibling =  node->next_sibling;

    while(current_sibling->next_sibling != NULL)
    {
        current_sibling = current_sibling->next_sibling;
    }

    current_sibling->next_sibling = sibling;
    current_sibling->next_sibling->node_father = current_sibling->node_father;


    return 0;
}

ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico)
{
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    new_node->node_type = node_type;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->ast_valor_lexico = ast_valor_lexico;



    return new_node;


}


ast_node* new_unary_expression(int node_type, ast_node *expression)
{
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    new_node->node_type = node_type;
    new_node->first_child = expression;
    new_node->next_sibling = NULL;



    return new_node;


}

ast_node* new_binary_expression(int node_type, ast_node *left, ast_node *right)
{
    if(left == NULL || right == NULL)
    {
        return NULL;
    }

    ast_node *new_node = new_empty_node();

    if(new_node != NULL)
    {
        new_node->node_type = node_type;
        insert_child_ast_node(new_node,left);
        insert_child_ast_node(new_node,right);
    }

    return new_node;
}

ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *false_expression, ast_node *true_expression)
{
    if(test_expression == NULL || false_expression == NULL || true_expression == NULL)
    {
        return NULL;
    }

    ast_node *new_node = new_empty_node();

    if(new_node != NULL)
    {
        new_node->node_type = node_type;
        new_node->first_child = test_expression;
        insert_ast_node_sibling_list(new_node->first_child,false_expression);
        insert_ast_node_sibling_list(new_node->first_child,true_expression);
    }


    return new_node;

}

void print_node_info(ast_node *node)
{
    printf("\nNode type:%d | Address: %p| First_child: %p| Sibling: %p \ Father %p\n",node->node_type, node,node->first_child,node->next_sibling, node->node_father);
}

void print_tree(ast_node *root)
{
    if(root == NULL)
        return;

    print_node_info(root);

    print_tree(root->first_child);
    print_tree(root->next_sibling);





}

void erase_tree(ast_node *root)
{
    if(root == NULL) return;

    erase_tree(root->first_child);
    erase_tree(root->next_sibling);

    free(root);

}



