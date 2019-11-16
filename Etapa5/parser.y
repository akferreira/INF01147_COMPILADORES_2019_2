%code requires {
    #include "ast.h"
    //extern void *arvore;
}


%union {
  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  MODIFIER_S var_modifier;
  
  
}


%{

//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol_table.h"
#include "ILOC.h"

extern void *arvore;
extern int get_line_number (void);
extern void exporta (void *arvore);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line %d Column %d : %s\n", get_line_number(),yylloc.last_column,s);
	 exit(1);
}
extern int yylex (void);
int yyparse (void);


%}


%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_CONST
%token TK_PR_STATIC
%token TK_PR_FOREACH
%token TK_PR_FOR
%token TK_PR_SWITCH
%token TK_PR_CASE
%token TK_PR_BREAK
%token TK_PR_CONTINUE
%token TK_PR_CLASS
%token TK_PR_PRIVATE
%token TK_PR_PUBLIC
%token TK_PR_PROTECTED
%token TK_PR_END
%token TK_PR_DEFAULT
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_SL
%token TK_OC_SR
%token TK_OC_FORWARD_PIPE
%token TK_OC_BASH_PIPE
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO


/*Menos Prioritário*/

//https://en.cppreference.com/w/c/language/operator_precedence
/*unary precedence
%right '+' '-'
       '!'
       '*'
       '&'
*/


%right '!''#'



%left TK_OC_EQ
%left TK_OC_LE TK_OC_GE

%left   '|'
%left   '&'
%left  TK_OC_SR TK_OC_SL
%left   '+' '-'
%left  '*' '/' '%'


%right '^'
       '?' ':'
%right TK_PR_STATIC


%left UNARY_QUESTION_MARK
%right UNARY_PLUS UNARY_MINUS
%right UNARY_ET UNARY_POINTER


/*Mais Prioritário*/



%define parse.error verbose
%start program
%locations

%%
%type <ast_node> program grammars global_var_declaration function_call expression expression_list identifier  if_statement simple_identifier command_return shift_command shift output_command input_command assignment_command  vector  literal_id local_var_declaration   null_node command_block_loop command_block command command_list loops loop_for loop_while loop_for_command loop_for_command_list function_declaration function_parameters_argument function_parameters_list call_parameter_list local_var_initialization function_command_block;

%type <valor_lexico> primitive_type TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_STRING TK_PR_CHAR function_id TK_IDENTIFICADOR TK_LIT_CHAR TK_LIT_STRING TK_LIT_FLOAT TK_LIT_INT;
 
%type <var_modifier> modifiers no_modifier;


enter_scope: {
//printf("\nnew scope\n");
create_new_scope();


};



exit_scope: {
//printf("\nexiting scope\n");  
exit_scope();};

null_node: {$$ = get_null();};

//programa:
program: /* empty */{$$ = get_null();};
program: grammars program  {$$ =  new_global_grammar_node('|',arvore,$1,$2);};



grammars:global_var_declaration|function_declaration;
	
//Declaração de variaveis globais
global_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR ';'{$$ = new_static_global_var_declaration_node('g',$2,$<valor_lexico>3,-1);};
global_var_declaration: primitive_type TK_IDENTIFICADOR';'{$$ = new_nonstatic_global_var_declaration_node('g',$1,$<valor_lexico>2,-1);};

global_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR'['TK_LIT_INT']'';' {$$ = new_static_global_var_declaration_node('g',$2,$<valor_lexico>3,$<valor_lexico>5.value.intvalue);};
global_var_declaration: primitive_type TK_IDENTIFICADOR'['TK_LIT_INT']'';'{$$ = new_nonstatic_global_var_declaration_node('g',$1,$<valor_lexico>2,$<valor_lexico>4.value.intvalue);};


//decl: primitive_type identifier;

primitive_type: TK_PR_INT { $1.var_type = TYPE_INT; $$ = $1;}
|TK_PR_FLOAT { $1.var_type = TYPE_FLOAT; $$ = $1;}
|TK_PR_CHAR{ $1.var_type = TYPE_CHAR; $$ = $1;}
|TK_PR_BOOL{ $1.var_type = TYPE_BOOL; $$ = $1;}
|TK_PR_STRING{ $1.var_type = TYPE_STRING; $$ = $1;};

identifier: simple_identifier {$$ = $1;}
|vector {$$ = $1;};

simple_identifier: TK_IDENTIFICADOR {$$ = new_leaf_node(ID_NODE,$<valor_lexico>1);}
vector: TK_IDENTIFICADOR'['TK_LIT_INT']' {    $$ = new_leaf_node(VECTOR_NODE,$<valor_lexico>1); $$->  vector_position = $<valor_lexico>3.value.intvalue; }  ;



//Function declaration
function_declaration: TK_PR_STATIC function_id enter_scope  '('function_parameters_list')' function_command_block 
{
$$ = new_static_function_declaration_node('M',$2,$5,$7);

};
function_declaration: function_id enter_scope '('function_parameters_list')' function_command_block {
//insert_function_entry($<valor_lexico>2);
$$ = new_nonstatic_function_declaration_node('M',$1,$4,$6);
};

//regra para definir o tipo do identificador da função
function_id: primitive_type TK_IDENTIFICADOR {

$<valor_lexico>2.var_type = $1.var_type;
$<valor_lexico>2.nature = FUNCTION;
insert_function_entry($<valor_lexico>2);
$$ = $<valor_lexico>2;

free($1.value.str_value);

};


function_parameters_list: {$$ = get_null();}

|function_parameters_argument 
|function_parameters_argument','function_parameters_list {$$ = new_parameter_list_node($1,$3);};
function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR {$$ = new_const_parameter_node('p',$2,$<valor_lexico>3);};
function_parameters_argument:primitive_type TK_IDENTIFICADOR {$$ = new_nonconst_parameter_node('p',$1,$<valor_lexico>2);};




function_command_block: '{'command_list'}' exit_scope { $$ = new_command_block_node('{',$2);};


//Command Block
command_block: enter_scope '{'command_list'}' exit_scope { $$ = new_command_block_node('{',$3);};

command_list: 
	command command_list {$$ = new_command_list_node($1,$2);}
	|command_block';' command_list {new_command_list_node($1,$3);}
	| loops command_list {$$ = new_command_list_node($1,$2);}
	|{$$ = get_null();};

//command
command: if_statement | local_var_declaration';' | shift_command';' | assignment_command';' {$$ = $1;}  | input_command';'{$$ = $1;}| output_command';'{$$ = $1;}| function_call';'{ $$ = $1;}
|command_return';'{$$ = $1;}

| TK_PR_BREAK';'  {$$ = new_leaf_node('b',$<valor_lexico>1);}
|TK_PR_CONTINUE';' {$$ = new_leaf_node('.',$<valor_lexico>1);};




modifiers: TK_PR_STATIC TK_PR_CONST { $$ = modifier(1,1);}
| TK_PR_STATIC { $$ = modifier(1,0);}
| TK_PR_CONST{ $$ = modifier(0,1);};

no_modifier: {$$ = modifier(0,0);}


//Local Var declaration
local_var_declaration:  modifiers primitive_type TK_IDENTIFICADOR local_var_initialization {
$$ = new_local_var_declaration_node('<',$1,$2,$<valor_lexico>3,$4 ) ;
};

local_var_declaration: primitive_type TK_IDENTIFICADOR local_var_initialization no_modifier{
$$ = new_local_var_declaration_node('<', $4 ,$1,$<valor_lexico>2,$3 ) ;

};
local_var_declaration: primitive_type TK_IDENTIFICADOR null_node no_modifier{
$$ = new_local_var_declaration_node('<', $4 ,$1,$<valor_lexico>2,$3) ;
};
//Local Var Initialization
local_var_initialization: TK_OC_LE literal_id{ $$ = $2;}


//Chamada de Função

function_call: simple_identifier '(' call_parameter_list ')'{ $$ = new_function_call_node(FUNCTION_CALL_NODE,$1,$3);};

call_parameter_list:expression ',' call_parameter_list {$$ = new_expression_list_node($1,$3);};
| expression 
| {$$ = get_null();};


//Comando de Atribuição
assignment_command: identifier '=' expression {$$ = new_assignment_node($1,$3,0);};

//Comandos de Entrada e Saída
input_command: TK_PR_INPUT expression {$$ = new_io_node(INPUT_NODE,$<valor_lexico>1,$2);};

output_command: TK_PR_OUTPUT expression{$$ = new_io_node(OUTPUT_NODE,$<valor_lexico>1,$2);};
output_command: TK_PR_OUTPUT expression_list{$$ = new_io_node(OUTPUT_NODE,$<valor_lexico>1,$2);};



//shift
shift: 
	TK_OC_SL { $$ = new_leaf_node('L',$<valor_lexico>1);}
	|TK_OC_SR { $$ = new_leaf_node('R',$<valor_lexico>1);};

shift_command: identifier shift expression { $$ = new_shift_command_node('X',$1,$2,$3);};

//Retorno
command_return: TK_PR_RETURN expression { $$ = new_return_command_node('R',$<valor_lexico>1,$2);};

//If Statement
if_statement: TK_PR_IF '(' expression ')' command_block null_node {$$ = new_ifelse_node(':',$3,$5,$6);};
if_statement: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block {$$ = new_ifelse_node(':',$3,$5,$7);};

//Loops
 command_block_loop: '{'command_block_loop'}' {$$ = $2;};
 command_block_loop: '{''}' {$$ = get_null();};
 command_block_loop: command;

loops: loop_for | loop_while; 
loop_while:TK_PR_WHILE'('expression')' command_block_loop {$$ = new_loop_while_node('w',$3,$5);};
loop_for:TK_PR_FOR'('loop_for_command_list':'expression':'loop_for_command_list')'command_block_loop {$$ = new_loop_for_node('j',$3,$5,$7,$9);};

loop_for_command_list:
	loop_for_command','loop_for_command_list {$$ = new_command_list_node($1,$3);}
	|loop_for_command;
loop_for_command:
	local_var_declaration| shift_command | assignment_command;



//Expressions






expression_list:  
	expression ',' expression_list { $$ = new_expression_list_node($1,$3);};
	|expression ',' expression { $$ = new_expression_list_node($1,$3);};


//literal: {};
expression: '(' expression ')'{ $$ = $2;};
//Unários
expression:'+'expression %prec UNARY_PLUS { $$ = $2;};
expression:'-'expression  %prec UNARY_MINUS { $$ = new_unary_expression('-',$2);};
expression:'!'expression{ $$ = new_unary_expression('!',$2); };
expression:'&'expression  %prec UNARY_ET { $$ = new_unary_expression('@',$2); };
expression:'*'expression %prec UNARY_POINTER  {$$ = new_unary_expression('$',$2); };
expression:'?'expression{$$ = new_unary_expression('~',$2); };
expression:'#'expression{$$ = new_unary_expression('#',$2); };






//Binários
expression: expression '+' expression 
{
	$$ = new_binary_expression('+',$1,$3);
	operacoesBinaria('+', lookup($1),lookup($3));
	
	/*TEMP *temp;
	temp = gerar_temp(5);
	printf("oi %s \n ",temp->nome );*/
Imprimir_codigo();
	
};










expression: expression '-' expression{$$ = new_binary_expression('-',$1,$3); };
expression: expression '*' expression{$$ = new_binary_expression('*',$1,$3);};
expression: expression '/' expression{$$ = new_binary_expression('/',$1,$3); };
expression: expression '%' expression{$$ = new_binary_expression('%',$1,$3); };
expression: expression '|' expression{$$ = new_binary_expression('|',$1,$3); };
expression: expression '&' expression{$$ = new_binary_expression('&',$1,$3);};
expression: expression '^' expression{$$ = new_binary_expression('^',$1,$3); };
//Ternários
expression: expression'?'expression':'expression{ $$ =  new_ternary_expression('?', $1,$3,$5); };
      
expression : literal_id {$$ = $1;};

//era expression
literal_id:  
	TK_IDENTIFICADOR
	{ 
		$$ = new_leaf_node(ID_NODE,$<valor_lexico>1);
		SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>1);
		if(id_info.nature == FUNCTION)
		{
    			printf("Semantical error line %d, column %d : ERR_FUNCTION\n",$<valor_lexico>1.line,$<valor_lexico>1.column);
    			exit(ERR_FUNCTION);
		}
	}
	| function_call
	{
		$$ = $1;
	}

	|TK_LIT_INT
	{ 
		$1.var_type = TYPE_INT;
		$$ = new_leaf_node('d',$<valor_lexico>1);
	}
	|TK_LIT_FLOAT
	{ 
		$1.var_type = TYPE_FLOAT;
		$$ = new_leaf_node('f',$<valor_lexico>1);
	}
	|TK_LIT_CHAR
	{ 
		$1.var_type = TYPE_CHAR;
		$$ = new_leaf_node('c',$<valor_lexico>1);
	}
	|TK_LIT_STRING
	{ 
		$1.var_type = TYPE_STRING;
		$$ = new_leaf_node('s',$<valor_lexico>1);
	}
	|TK_LIT_TRUE
	{ 
		$$ = new_leaf_node('T',$<valor_lexico>1);
	}
	|TK_LIT_FALSE
	{ 
		$$ = new_leaf_node('F',$<valor_lexico>1);
	};






%%
