#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

extern void *arvore;

void libera (void *arvore){
    printf("Liberating %p\n",arvore);
    
    
}
void exporta (void *arvore){
    printf("Exporting %p\n",arvore);
    
}

ast_node* new_empty_node(){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){
        new_node->node_type = UNINITIALIZED;
        new_node->first_child = NULL;
        new_node->next_sibling = NULL;
        VALOR_LEXICO new_valor_lexico;
        new_valor_lexico.line =0;
        new_valor_lexico.intvalue = 0;
        new_valor_lexico.token_type = 0;
        new_valor_lexico.value = NULL;
         
        
        new_node->ast_valor_lexico = new_valor_lexico;
    }
    
    
    return new_node;
    
    
}

int insert_child_ast_node(ast_node *node,ast_node *child){
    if(node == NULL) return -1;
    
    if(node->first_child == NULL) {
        node->first_child = child;
        return 0;
    }
    
    insert_ast_node_sibling_list(node->first_child,child);
    return 0;
    
}

int insert_ast_node_sibling_list(ast_node *node,ast_node *sibling){
//     printf("Inserting Sibling\n");
    
    if(node == NULL){
        return -1;
    }
    
    if(node->next_sibling == NULL) {
//         printf("Inserting first sibling\n");
//         printf("%d\n",sibling->node_type);
        node->next_sibling = sibling;
        return 0;
    }
    
    printf("%p\n",node->next_sibling);
    printf("%d\n",node->next_sibling->node_type);
    printf("%d\n",sibling->node_type);
    
    
    ast_node *current_sibling =  node->next_sibling;
    
    while(current_sibling->next_sibling != NULL){
        current_sibling = current_sibling->next_sibling;
    }
    
    current_sibling->next_sibling = sibling;
    
    
    return 0;
}

ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){

    new_node->node_type = node_type;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->ast_valor_lexico = ast_valor_lexico;
    
    
    
//     printf("Sucessfully allocated leaf_node : %c || %d  /%s\n",node_type, ast_valor_lexico.intvalue,ast_valor_lexico.value);
    
    }
    
    
    return new_node;
    
    
}


ast_node* new_unary_expression(int node_type, ast_node *expression){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));

    new_node->node_type = node_type;
    new_node->first_child = expression;
    new_node->next_sibling = NULL;
    
    
    
    return new_node;
    
    
}

ast_node* new_assignment_node(ast_node *dest, ast_node *source){
    if(dest == NULL || source == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    if(new_node != NULL){
        
        
        new_node->node_type = '=';
        insert_child_ast_node(new_node,dest);
        insert_child_ast_node(new_node,source);
         
        
    }
    
    return new_node;
}

    



ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right){
    if(left == NULL || right == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    if(new_node != NULL){
//          printf("\nLine : %d \t Binary : %c\n", left->ast_valor_lexico.line, node_type);
//          print_node_info(left);
//          print_node_info(right);
        
        
        
        new_node->node_type = node_type;
        insert_child_ast_node(new_node,left);
        insert_child_ast_node(new_node,right);
        
//         printf("new_node");
//         print_node_info(new_node);
//         printf("left and right");
         
        
    }
    
    return new_node;
}

ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *false_expression, ast_node *true_expression){
    if(test_expression == NULL || false_expression == NULL || true_expression == NULL){
        return NULL;
    }
    
    ast_node *new_node = new_empty_node();
    
    if(new_node != NULL){
        new_node->node_type = node_type;
        new_node->first_child = test_expression;
        insert_ast_node_sibling_list(new_node->first_child,false_expression);
        insert_ast_node_sibling_list(new_node->first_child,true_expression);
    }
    
    
    return new_node;
    
}

void print_node_info(ast_node *node){
    printf("\nNode type:%c | Address: %p| First_child: %p| Sibling: %p\n",node->node_type, node,node->first_child,node->next_sibling);
    printf("[%d]",node->ast_valor_lexico.intvalue);
}


void print_node_info_csv(ast_node * node){
    if(node == NULL) return;
    
    ast_node *root = node;
    
    printf("\nNode type %c \t[%d] \t | Address: %p|\n",node->node_type,node->ast_valor_lexico.intvalue,node);
    
    
    if(node->first_child != NULL){
        printf("%p,%p\n",root,node->first_child);
        
        ast_node *next = node->first_child->next_sibling;
        
        while(next != NULL){
            printf("%p,%p\n",root,next);
            next = next->next_sibling;
        }
    print_node_info_csv(node->first_child);
    print_node_info_csv(node->first_child->next_sibling);    
        
    }
    
    
    
    
}


void print_tree(ast_node *root){
    if(root == NULL) return;
    
    print_node_info(root);
    
    print_tree(root->first_child);
    
    
    
    if(root->first_child){
        print_tree(root->first_child->next_sibling);
        
    }
    
    //print_tree(root->next_sibling);
    
   
    
    
}

void erase_tree(ast_node *root){
    if(root == NULL) return;
    
    erase_tree(root->first_child);
    erase_tree(root->next_sibling);
    
    free(root);
    
}








/*
int main(){
VALOR_LEXICO a;
a.line = 0;

ast_node *test = new_leaf_node(1,a);

insert_child_ast_node(test,new_leaf_node(2,a));
insert_child_ast_node(test,new_leaf_node(8,a));

insert_child_ast_node(test, new_leaf_node(3,a));
insert_child_ast_node(test->first_child,new_leaf_node(4,a));
insert_child_ast_node(test->first_child,new_leaf_node(5,a));
insert_child_ast_node(test->first_child,new_leaf_node(6,a));
insert_child_ast_node(test->first_child,new_leaf_node(7,a));





printf("\n\n");
print_tree(test);
erase_tree(test);
    
    
return 0;
}*/
