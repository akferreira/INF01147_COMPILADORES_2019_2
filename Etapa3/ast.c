#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

extern void *arvore;

void libera (void *arvore){
	printf("Libera\n");
	erase_tree(arvore);




}
void exporta (void *arvore){
	printf("print csv\n");
	FILE *arq1;
	arq1=fopen("output/e3.csv","w+");
	Percorrer_imprimir_file_DFS(arvore,arq1);
	fclose(arq1);

}

ast_node* get_null(){
	return NULL;

}


ast_node* new_empty_node(){
	ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));


	printf("new_empty_node - I\n");



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

	printf("new_empty_node - F\n");

	return new_node;


}



ast_node* insert_child(ast_node *node, ast_node *child)
{
	if (child == NULL)
		return node;

	printf("insert_child - I\n");

	if(node == NULL) 
		return NULL;

	if(node->first_child == NULL)
	{
		printf("		insert_child - t1\n");
		node->first_child = child;
		printf("		insert_child - t2\n");
		node->first_child->father = node;
		printf("		insert_child - t1\n");


		ast_node *temp = node->first_child;

		while(temp != NULL){
			temp = temp->next_sibling;

			if(temp != NULL && temp->father == NULL) temp->father = node;

		}


		printf("insert_child - F1\n");
		return node;
	}

	printf("insert_child - M\n");

	insert_sibling(node->first_child, child);
	printf("insert_child - F2\n");


	return node;

}


//Adiciona o siobling (irmao), percorrendo a arvore ate achar um vazio.
ast_node* insert_sibling(ast_node *node, ast_node *sibling)
{


	printf("insert_sibling - I\n");
	if(sibling == NULL)
		return node;

	if(node == NULL) return NULL;

	if(node->next_sibling == NULL)
	{
		node->next_sibling = sibling;
		node->next_sibling->father = node->father;


		printf("insert_sibling - F1\n");   

		return node;
	}



	ast_node *current_sibling =  node->next_sibling;
	printf("insert_sibling - bk1\n");
	while(current_sibling->next_sibling != NULL)
	{
		current_sibling = current_sibling->next_sibling;
		printf("insert_sibling - bk loop\n");
	}



	current_sibling->next_sibling = sibling;
	printf("insert_sibling - bk 3\n");
	current_sibling->next_sibling->father = current_sibling->father;
	printf("insert_sibling - F2\n");
	return node;
}

ast_node* new_ifelse_node(int node_type, ast_node* test_expression, ast_node *true_command_block , ast_node *false_command_block){
	printf("insert_sibling - I\n");
	ast_node* ifelse_node = new_empty_node();

	if(ifelse_node != NULL){
		ifelse_node->node_type = node_type;
		insert_child(ifelse_node,test_expression);
		insert_child(ifelse_node,true_command_block);
		if(false_command_block) insert_child(ifelse_node,false_command_block);
	}
	printf("insert_sibling - F\n");
	return ifelse_node;

}

ast_node* new_io_node(int node_type, VALOR_LEXICO lexico_io, ast_node *expression){


	printf("insert_sibling - I\n");
	ast_node* io_node = new_leaf_node(node_type,lexico_io);



	if(io_node != NULL){
		insert_child(io_node,expression);
	}

	printf("insert_sibling - F\n"); 
	return io_node;

}


ast_node* new_leaf_node(int node_type, VALOR_LEXICO ast_valor_lexico){

	printf("new_leaf_node - I\n");

	ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));



	if(new_node != NULL){

		new_node->node_type = node_type;
		new_node->first_child = NULL;
		new_node->next_sibling = NULL;
		new_node->father = NULL;
		new_node->ast_valor_lexico = ast_valor_lexico;



//     printf("Sucessfully allocated leaf_node : %c || %d  /%s\n",node_type, ast_valor_lexico.intvalue,ast_valor_lexico.value);

	}

	printf("new_leaf_node - F\n");
	return new_node;


}

ast_node* new_loop_for_node(int node_type, ast_node* initialization,ast_node *test_expression,ast_node* loop_command, ast_node* command_block){


	printf("new_loop_for_node - I\n");
	ast_node *for_loop_node = new_empty_node();

	if(for_loop_node != NULL){
		for_loop_node->node_type = node_type;
		insert_child(for_loop_node,initialization);
		insert_child(for_loop_node,test_expression);
		insert_child(for_loop_node,loop_command);
		insert_child(for_loop_node,command_block);
	}
	printf("new_loop_for_node - F\n");
	return for_loop_node;


}

ast_node* new_loop_while_node(int node_type, ast_node* expression, ast_node* command_block){

	printf("new_loop_while_node - I\n");

	ast_node* while_loop_node = new_empty_node();

	if(while_loop_node != NULL){
		while_loop_node->node_type = node_type;
		insert_child(while_loop_node,expression);
		insert_child(while_loop_node,command_block);

	}

	printf("new_loop_while_node - F\n");
	return while_loop_node;


}



ast_node* new_unary_expression(int node_type, ast_node *expression){
	ast_node *new_node = (ast_node*) malloc(sizeof(ast_node));


	printf("new_unary_expression - I\n");


	new_node->node_type = node_type;
	new_node->first_child = expression;
	new_node->next_sibling = NULL;


	printf("new_unary_expression - F\n");
	return new_node;


}

ast_node* new_assignment_node(ast_node *dest, ast_node *source){


	printf("new_assignment_node - I\n");

	if(dest == NULL || source == NULL){
		return NULL;
	}

	ast_node *new_node = new_empty_node();

	if(new_node != NULL){


		new_node->node_type = '=';
		insert_child(new_node,dest);
		insert_child(new_node,source);




	}
	printf("new_assignment_node - F\n");
	return new_node;
}



ast_node* new_assignment_node_array(ast_node *dest,ast_node *index, ast_node *source){


	printf("new_assignment_node_array - I\n");
	if(dest == NULL ||index|| source == NULL){
		printf("new_assignment_node_array - R1\n");
		return NULL;
	}

	ast_node *new_node = new_empty_node();

	if(new_node != NULL){


		new_node->node_type = '=';
		insert_child(new_node,dest);
		new_node->node_type = '[';
		insert_child(new_node,index);
		new_node->node_type = ']';
		insert_child(new_node,source);




	}
	printf("new_assignment_node_array - F\n");
	return new_node;

}











ast_node* new_binary_expression(int node_type, ast_node *left,ast_node *right){
	printf("new_binary_expression - I\n");
	if(left == NULL || right == NULL){
		printf("new_binary_expression - R1\n");
		return NULL;
	}

	ast_node *new_node = new_empty_node();

	if(new_node != NULL){



		new_node->node_type = node_type;
		insert_child(new_node,left);
		insert_child(new_node,right);


	}
	printf("new_binary_expression - F\n");
	return new_node;
}




ast_node* new_command_block_node(int node_type,ast_node *command_list){

	printf("new_command_block_node - I\n");

	if(command_list == NULL) return NULL;

	ast_node *command_block = new_empty_node();


	if(command_block != NULL){
		command_block->node_type = node_type;
		insert_child(command_block,command_list);
	}

	printf("new_command_block_node - F\n");
	return command_block;
}




ast_node* new_command_list_node(ast_node* current_commands,ast_node *next_commands){
	printf("new_command_list_node - I\n");


	if(next_commands == NULL) 
		return current_commands;

	if(current_commands != NULL){
		insert_sibling(current_commands,next_commands);
	}

	printf("new_command_list_node - F\n");
	return current_commands;
}





ast_node* new_expression_list_node(ast_node* current_expressions,ast_node *next_expressions){
	printf("new_expression_list_node - I\n");
	if(next_expressions == NULL) return NULL;

	if(current_expressions == NULL){
		insert_sibling(current_expressions,next_expressions);
	}
	printf("new_expression_list_node - F\n");
	return current_expressions;


}
ast_node* new_const_parameter_node(int node_type,VALOR_LEXICO const_lexical,ast_node* parameter_type,ast_node *identifier){


	printf("new_const_parameter_node - I\n");
	ast_node* const_node = new_leaf_node(node_type,const_lexical);
	printf("new_const_parameter_node - F\n");
	return new_parameter_node(node_type,const_node,parameter_type,identifier);
}

ast_node* new_nonconst_parameter_node(int node_type,ast_node* parameter_type,ast_node *identifier){
	printf("new_nonconst_parameter_node - I\n");
	printf("new_nonconst_parameter_node - F\n");
	return new_parameter_node(node_type,NULL,parameter_type,identifier);

}

ast_node* new_parameter_node(int node_type,ast_node* const_modifier,ast_node* parameter_type,ast_node *identifier){

	printf("new_parameter_node - I\n");
	ast_node* parameter_node = new_empty_node();

	if(parameter_node != NULL){
		parameter_node->node_type = node_type;
		if(const_modifier != NULL) insert_child(parameter_node,const_modifier);
		insert_child(parameter_node,parameter_type);
		insert_child(parameter_node,identifier);
	}
	printf("new_parameter_node - F\n");
	return parameter_node;

}



ast_node* new_parameter_list_node(ast_node* current_parameters,ast_node *next_parameters){
	printf("new_parameter_list_node - I\n");
	if(next_parameters == NULL) return NULL;

	if(current_parameters == NULL){
		insert_sibling(current_parameters,next_parameters);
	}
	printf("new_parameter_list_node - F\n");
	return current_parameters;


}

ast_node* new_nonstatic_function_declaration_node(int node_type, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){
	printf("new_nonstatic_function_declaration_node - I F\n");
	return new_function_declaration_node(node_type,NULL,var_type, identifier,parameter_list,command_block);

}




ast_node* new_static_function_declaration_node(int node_type, VALOR_LEXICO static_lexical, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){
	printf("new_static_function_declaration_node - I \n");
	ast_node* static_node = new_leaf_node('S',static_lexical);
	printf("new_static_function_declaration_node - F \n");
	return new_function_declaration_node(node_type,static_node,var_type,  identifier,parameter_list,command_block);
}

/*
ast_node* new_function_declaration_node(int node_type, ast_node* modifier_static, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){

	printf("new_function_declaration_node - I \n");

	ast_node *function_node = new_empty_node();

	if(function_node != NULL){
		function_node->node_type = node_type;

		if(modifier_static != NULL){
			insert_child(function_node,modifier_static);
		}


		insert_child(function_node,var_type);
		insert_child(function_node,identifier);
		if(parameter_list != NULL) insert_child(function_node,parameter_list);

		insert_child(function_node,command_block);

	}

	printf("new_function_declaration_node - F \n"); 
	 function_node = NULL;
	return function_node;
}
*/
ast_node* new_function_declaration_node(int node_type, ast_node* modifier_static, ast_node* var_type, ast_node* identifier,ast_node* parameter_list, ast_node* command_block){

erase_tree(modifier_static);
erase_tree(var_type);
erase_tree(identifier);
erase_tree(parameter_list);

return command_block;


}











ast_node* new_function_call_node(int node_type, ast_node* identifier, ast_node* parameter_list){

	printf("new_function_call_node - I \n");  
	ast_node *function_call_node = new_empty_node();

	if(function_call_node != NULL){
		function_call_node->node_type = node_type;
		insert_child(function_call_node,identifier);
		insert_child(function_call_node,parameter_list);

	}
	printf("new_function_call_node - F \n");  
	return function_call_node;
}

ast_node* new_static_global_var_declaration_node(int node_type, VALOR_LEXICO static_lexical,ast_node* var_type, ast_node* identifier){
	printf("new_static_global_var_declaration_node - I \n");  
	ast_node* static_node = new_leaf_node('S',static_lexical);
	printf("new_static_global_var_declaration_node - F \n");   
	return new_global_var_declaration_node(node_type,static_node,var_type,identifier);


}
ast_node* new_nonstatic_global_var_declaration_node(int node_type,ast_node* var_type, ast_node* identifier){
	printf("new_nonstatic_global_var_declaration_node - I F \n");
	return new_global_var_declaration_node(node_type,NULL,var_type,identifier);
}

ast_node* new_global_var_declaration_node(int node_type, ast_node* modifier_static,ast_node* var_type, ast_node* identifier){
	printf("new_global_var_declaration_node - I  \n");
	ast_node* global_var_node = new_empty_node();

	if(global_var_node != NULL){
		global_var_node->node_type = node_type;
		if(modifier_static != NULL) insert_child(global_var_node,modifier_static); 
		insert_child(global_var_node,var_type);
		insert_child(global_var_node,identifier);

	}
	global_var_node = NULL;
	printf("new_global_var_declaration_node - F  \n");    
	return global_var_node;
}

ast_node* new_global_grammar_node(int node_type,ast_node *ast_root, ast_node *current_global_node, ast_node* next_global_nodes){

	printf("new_global_grammar_node - I  \n");

	if(ast_root == NULL){
		ast_node* temp_node = new_empty_node();
		temp_node->node_type = node_type;
		arvore = temp_node;



		insert_child(arvore,current_global_node);
		if(next_global_nodes != NULL) 
			insert_child(arvore,next_global_nodes);
		printf("new_global_grammar_node - F  \n");
		return ast_root;
	}

	else{
		if(next_global_nodes != NULL) 
			insert_sibling(current_global_node,next_global_nodes);
		printf("new_global_grammar_node - F  \n");
		return current_global_node;

	}



}


ast_node* new_modifier_node(int node_type1, int node_type2, VALOR_LEXICO lexico1, VALOR_LEXICO lexico2){

	printf("new_modifier_node - I  \n");
	ast_node* modifier1 = new_leaf_node(node_type1,lexico1);

	if(node_type2){
		ast_node* modifier2 = new_leaf_node(node_type2,lexico2);
		insert_sibling(modifier1 , modifier2);
	}
	printf("new_modifier_node - F  \n");
	return modifier1;


}
/*
ast_node* new_local_var_declaration_node(int node_type, ast_node* modifiers,ast_node* var_type, ast_node* identifier, ast_node* initialization){
	printf("new_local_var_declaration_node - I  \n");
	if(var_type == NULL || identifier == NULL) 
		return NULL;

	ast_node *new_node = new_empty_node();


	if(new_node != NULL){
		new_node->node_type = node_type;


		if(modifiers != NULL) 
			insert_child(new_node, modifiers);

		insert_child(new_node,var_type);

		insert_child(new_node,identifier);


		if(initialization != NULL) 
			insert_child(new_node,initialization);


	}

	printf("new_local_var_declaration_node - F  \n");
	return new_node;


}

*/


ast_node* new_local_var_declaration_node(int node_type, ast_node* modifiers,ast_node* var_type, ast_node* identifier, ast_node* initialization){
	printf("new_local_var_declaration_node - I  \n");

	erase_tree(modifiers);
	erase_tree(var_type);
	erase_tree(initialization);

	
	

	printf("new_local_var_declaration_node - F  \n");
	return identifier;


}



ast_node* new_shift_command_node(int node_type,ast_node *identifier, ast_node *shift_type, ast_node *expression){
	printf("new_shift_command_node - I  \n");
	ast_node* shift_node = new_empty_node();

	if(shift_node != NULL){
		shift_node->node_type = node_type;
		insert_child(shift_node,identifier);
		insert_child(shift_node,shift_type);
		insert_child(shift_node,expression);

	}
	printf("new_shift_command_node - F  \n");
	return shift_node;


}

ast_node* new_return_command_node(int node_type, VALOR_LEXICO lexico, ast_node* expression){
	ast_node* return_node = new_leaf_node(node_type,lexico);
	printf("new_return_command_node - I  \n");
	if(return_node != NULL){
		insert_child(return_node,expression);


	}
	printf("new_return_command_node - F  \n");
	return return_node;

}


ast_node* new_ternary_expression(int node_type, ast_node *test_expression,ast_node *true_expression, ast_node *false_expression){
	printf("new_ternary_expression - I  \n");    
	if(test_expression == NULL || false_expression == NULL || true_expression == NULL){
		printf("new_ternary_expression - F  \n");  
		return NULL;
	}

	ast_node *new_node = new_empty_node();

	if(new_node != NULL){
		new_node->node_type = node_type;
		new_node->first_child = test_expression;
		insert_sibling(new_node->first_child,false_expression);
		insert_sibling(new_node->first_child,true_expression);
	}

	printf("new_ternary_expression - F  \n");  
	return new_node;

}

void print_node_info(ast_node *node){
	printf("\nNode type:%c | Address: %p| First_child: %p| Sibling: %p\n",node->node_type, node,node->first_child,node->next_sibling);
	printf("[%d]",node->ast_valor_lexico.intvalue);
}


void Percorrer_imprimir_file_DFS(ast_node *Tree,FILE *arq)
{
	printf("Percorrer_imprimir_file_DFS - I  \n");  
	if(Tree == NULL)
		return;

	fprintf(arq,"%p, %p [%c][%d]\n",Tree->father, Tree,Tree->node_type,Tree->ast_valor_lexico.intvalue);

	Percorrer_imprimir_file_DFS(Tree->first_child,arq);
    //printf("%p %d\n",Tree->node_node_father, Tree->node_type);
	Percorrer_imprimir_file_DFS(Tree->next_sibling,arq);
	printf("Percorrer_imprimir_file_DFS - F \n");  
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




void erase_tree(ast_node *root){
	printf("erase_tree - I  \n");  
	if(root == NULL) return;

	erase_tree(root->first_child);
	erase_tree(root->next_sibling);


    //printf("\naaa   %d | %p | %c | %s\n",root->ast_valor_lexico.column,root->ast_valor_lexico.value,root->node_type,root->ast_valor_lexico.value);
	free(root->ast_valor_lexico.value);
	root->ast_valor_lexico.value = NULL;
	free(root);
	root = NULL;
	printf("erase_tree - F  \n");  

}









