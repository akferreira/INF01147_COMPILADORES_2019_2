#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

extern void *arvore;

void libera (void *arvore){
    printf("Liberating %p\n",arvore);
    
    erase_tree(arvore);
    

    
    
}
void exporta (void *arvore){
    printf("Exporting %p\n",arvore);
    
     FILE *arq1;
     arq1=fopen("Arvore1.csv","a+");
     Percorrer_imprimir_file_DFS(arvore,arq1);
     fclose(arq1);
        
     FILE *arq2;
     arq2=fopen("Arvore2.csv","a+");
     
    
    print_node_info_csv(arvore,arq2);

    
    fclose(arq2);
    
}

ast_node* get_null(){
    return NULL;
    
}


ast_node* new_empty_node(){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){
        new_node->node_type = UNINITIALIZED;
        new_node->first_child = NULL;
        new_node->next_sibling = NULL;
        new_node->father = NULL;
        
        VALOR_LEXICO new_valor_lexico;
        new_valor_lexico.line =0;
        new_valor_lexico.intvalue = 0;
        new_valor_lexico.token_type = 0;
        new_valor_lexico.value = NULL;
         
        
        new_node->ast_valor_lexico = new_valor_lexico;
    }
    
    
    return new_node;
    
    
}



ast_node* insert_child_ast_node(ast_node *node, ast_node *child)
{
    if(node == NULL) return NULL;

    if(node->first_child == NULL)
    {
        //printf("First child\n");
        //printf("%d\n",child->node_type);
        node->first_child = child;
        node->first_child->father = node;
        

        return node;
    }
    
    

    insert_ast_node_sibling_list(node->first_child, child);
    
    
    return node;

}


//Adiciona o siobling (irmao), percorrendo a arvore ate achar um vazio.
ast_node* insert_ast_node_sibling_list(ast_node *node, ast_node *sibling)
{
    if(node == NULL) return NULL;

    if(node->next_sibling == NULL)
    {
        //printf("%d\n",sibling->node_type);
        node->next_sibling = sibling;
        
        
        
        node->next_sibling->father = node->father;
        
        
        
        
        return node;
    }

    

    ast_node *current_sibling =  node->next_sibling;

    while(current_sibling->next_sibling != NULL)
    {
        current_sibling = current_sibling->next_sibling;
    }

    current_sibling->next_sibling = sibling;
    current_sibling->next_sibling->father = current_sibling->father;


    return node;
}
ast_node* new_io_node(int node_type, VALOR_LEXICO lexico_io, ast_node *expression){
    ast_node* io_node = new_leaf_node(node_type,lexico_io);
    ast_node* io_command_node = new_empty_node();
    
    
    
    if(io_node != NULL){
        
    }
    
    
    return NULL;
    
}


ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico){
    ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));
    
    if(new_node != NULL){

    new_node->node_type = node_type;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    new_node->father = NULL;
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

ast_node* new_command_block_node(int node_type,ast_node *command_list){
    if(command_list == NULL) return NULL;
    
    ast_node *command_block = new_empty_node();
    
    if(command_block == NULL){
        command_block->node_type = node_type;
        insert_child_ast_node(command_block,command_list);
    }
    return command_block;
}

ast_node* new_function_declaration_node(int node_type, ast_node* modifier_static, ast_node* var_type, ast_node* parameter_list, ast_node* command_block){
    ast_node *function_node = new_empty_node();
    
    if(function_node != NULL){
        function_node->node_type = node_type;
        
        if(modifier_static != NULL){
            insert_child_ast_node(function_node,modifier_static);
        }
        
        
        insert_child_ast_node(function_node,var_type);
        insert_child_ast_node(function_node,parameter_list);
        insert_child_ast_node(function_node,command_block);
    }
    
    
    return function_node;
}

ast_node* new_modifier_node(int node_type1, int node_type2, VALOR_LEXICO lexico1, VALOR_LEXICO lexico2){
    ast_node* modifier1 = new_leaf_node(node_type1,lexico1);
    
    if(node_type2){
        ast_node* modifier2 = new_leaf_node(node_type2,lexico2);
        insert_ast_node_sibling_list(modifier1 , modifier2);
    }
    
    return modifier1;
    
    
}

ast_node* new_local_var_declaration_node(int node_type, ast_node* modifiers,ast_node* var_type, ast_node* identifier, ast_node* initialization){
    if(var_type == NULL || identifier == NULL) return NULL;
    
    ast_node *new_node = new_empty_node();
    
    
    if(new_node != NULL){
        new_node->node_type = node_type;
        
        
        if(modifiers != NULL) insert_child_ast_node(new_node, modifiers);
        
        insert_child_ast_node(new_node,var_type);
        
        insert_child_ast_node(new_node,identifier);
        
        
        if(initialization != NULL) insert_child_ast_node(new_node,initialization);
        
        
    }
    
    
    return new_node;
    
    
}

ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *true_expression, ast_node *false_expression){
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


void Percorrer_imprimir_file_DFS(ast_node *Tree,FILE *arq)
{
    if(Tree == NULL)
        return;
    Percorrer_imprimir_file_DFS(Tree->first_child,arq);
    fprintf(arq,"\n%p, %p [%c] \n",Tree->father, Tree,Tree->node_type);
    //printf("%p %d\n",Tree->node_node_father, Tree->node_type);
    Percorrer_imprimir_file_DFS(Tree->next_sibling,arq);

}


void print_node_info_csv(ast_node * node, FILE *arq){
    if(node == NULL) return;
    
    ast_node *root = node;
    
    fprintf(arq,"Node type %c \t[%d] \t | Address: %p|\n",node->node_type,node->ast_valor_lexico.intvalue,node);
    
    
    if(node->first_child != NULL){
        fprintf(arq,"%p, %p [%c]\n",root,node->first_child,node->node_type);
        
        ast_node *next = node->first_child->next_sibling;
        
        while(next != NULL){
            fprintf(arq,"%p,%p [%c]\n",root,next,next->node_type);
            next = next->next_sibling;
        }
    print_node_info_csv(node->first_child,arq);
    print_node_info_csv(node->first_child->next_sibling,arq);    
        
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
    printf("erasing\n");
    
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
