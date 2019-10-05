%code requires {
    #include "ast.h"
}


%union {
  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  
  
}


%{

//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
extern int get_line_number (void);
extern void exporta (void *arvore);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line %d : %s\n", get_line_number(),s);
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

%left  '*' '/' '%'
       '+' '-'
       TK_OC_SR TK_OC_SL
       '&'
       '|'

%right '^'
       '?' ':'
%right TK_PR_STATIC


/*Mais Prioritário*/



%define parse.error verbose
%start program
%locations

%%
%type <ast_node> function_call expression expression_list identifier  simple_identifier command_return shift_command shift output_command input_command assignment_command TK_IDENTIFICADOR vector local_var_initialization literal local_var_declaration primitive_type modifiers null_node;


null_node: {$$ = get_null();};

//programa:
program: /* empty */;
program:grammars program;
grammars:global_var_declaration|function_declaration;
	
//Declaração de variaveis globais
global_var_declaration: TK_PR_STATIC decl';';
global_var_declaration: decl';';
decl: primitive_type identifier;

primitive_type: TK_PR_INT {$$ = new_leaf_node('t',$<valor_lexico>1);}
|TK_PR_FLOAT{$$ = new_leaf_node('t',$<valor_lexico>1);}
|TK_PR_CHAR{$$ = new_leaf_node('t',$<valor_lexico>1);}
|TK_PR_BOOL{$$ = new_leaf_node('t',$<valor_lexico>1);}
|TK_PR_STRING{$$ = new_leaf_node('t',$<valor_lexico>1);};

identifier: simple_identifier {$$ = $1;}
|vector {$$ = new_leaf_node('I',$<valor_lexico>1);};

simple_identifier: TK_IDENTIFICADOR {$$ = new_leaf_node('I',$<valor_lexico>1);}
vector: TK_IDENTIFICADOR'['TK_LIT_INT']';



//Function declaration
function_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block;
function_declaration: primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block;
	function_parameters_list: |function_parameters_argument|function_parameters_argument','function_parameters_list;
	function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR;
	function_parameters_argument:primitive_type TK_IDENTIFICADOR;

//Command Block
command_block: '{'command_list'}';

command_list: command command_list | loop_while command_list|loop_for command_list |command_block|;


//command
command: if_statement | local_var_declaration';' {exporta($1);}| shift_command';'; | assignment_command';' {exporta($1);} | input_command';'| output_command';'| function_call';'|command_return';'| TK_PR_BREAK';' |TK_PR_CONTINUE';';




modifiers: TK_PR_STATIC TK_PR_CONST { $$ = new_modifier_node('S','C',$<valor_lexico>1,$<valor_lexico>2);}
| TK_PR_STATIC { $$ = new_modifier_node('S', 0 ,$<valor_lexico>1,$<valor_lexico>1);}
| TK_PR_CONST{ $$ = new_modifier_node('C',0,$<valor_lexico>1,$<valor_lexico>1);};


//Local Var declaration
local_var_declaration:  modifiers primitive_type TK_IDENTIFICADOR local_var_initialization {
$$ = new_local_var_declaration_node('<',$1,$2,$3,$4 ) ;
};
local_var_declaration: primitive_type simple_identifier local_var_initialization{
$$ = new_local_var_declaration_node('<', NULL ,$1,$2,$3 ) ;

};
local_var_declaration: primitive_type simple_identifier null_node{
printf("%d || %d\n",@1.first_line,@1.last_line);
printf("%d || %d\n",@2.first_column,@2.last_column);
$$ = new_local_var_declaration_node('<', $3 ,$1,$2,$3) ;
};

//Chamada de Função
function_call: simple_identifier '(' expression_list ')'{$$ = new_function_call_node('K',$1,$3);};
function_call: simple_identifier '(' expression ')'{$$ = new_function_call_node('K',$1,$3);};




//Comando de Atribuição
assignment_command: identifier '=' expression { $$ = new_assignment_node($1,$3);};

//Comandos de Entrada e Saída
input_command: TK_PR_INPUT expression {$$ = new_io_node('i',$<valor_lexico>1,$2);};

output_command: TK_PR_OUTPUT expression{$$ = new_io_node('o',$<valor_lexico>1,$2);};
output_command: TK_PR_OUTPUT expression_list{$$ = new_io_node('o',$<valor_lexico>1,$2);};



//function_call: TK_IDENTIFICADOR '(' call_parameter_list ')';
//call_parameter_list:expression ',' call_parameter_list | expression;


//shift
shift: TK_OC_SL { $$ = new_leaf_node('L',$<valor_lexico>1);}
| TK_OC_SR { $$ = new_leaf_node('R',$<valor_lexico>1);};

shift_command: identifier shift expression { $$ = new_shift_command_node('X',$1,$2,$3);};

//Retorno
command_return: TK_PR_RETURN expression {$$ = new_return_command_node('R',$<valor_lexico>1,$2);};

//If Statement
if_statement: TK_PR_IF '(' expression ')' command_block;
if_statement: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block;

//Loops
 command_block_loop: '{'command_block_loop'}';
 command_block_loop: '{''}';
 command_block_loop: command;
	//While

	loop_while:TK_PR_WHILE'('expression')' command_block_loop;
    	loop_for:TK_PR_FOR'('loop_for_command_list':'expression':'loop_for_command_list')'command_block_loop;
    
    	loop_for_command_list:loop_for_command','loop_for_command_list|loop_for_command;
    	loop_for_command: local_var_declaration| shift_command | assignment_command;



//Expressions






expression_list:  expression ',' expression_list { $$ = insert_ast_node_sibling_list($1,$3);};
|  ',' expression { $$ = $2;};

expression: literal { $$ = $1;};
//expression: expression_unary | expression_binary| expression_ternary;


expression: '(' expression ')'{ printf("aaaaa\n");};
//Unários
expression:'+'expression{ $$ = $2;};
expression:'-'expression{ $$ = new_unary_expression('-',$2);};
expression:'!'expression{ $$ = new_unary_expression('!',$2); };
expression:'&'expression { $$ = new_unary_expression('@',$2); };
expression:'*'expression {$$ = new_unary_expression('$',$2); };
expression:'?'expression{$$ = new_unary_expression('~',$2); };
expression:'#'expression{$$ = new_unary_expression('#',$2); };
//Binários
expression: expression '+' expression {$$ = new_binary_expression('+',$1,$3);};
expression: expression '-' expression{$$ = new_binary_expression('-',$1,$3); };
expression: expression '*' expression{$$ = new_binary_expression('*',$1,$3);};
expression: expression '/' expression{$$ = new_binary_expression('/',$1,$3); };
expression: expression '%' expression{$$ = new_binary_expression('%',$1,$3); };
expression: expression '|' expression{$$ = new_binary_expression('|',$1,$3); };
expression: expression '&' expression{$$ = new_binary_expression('&',$1,$3);};
expression: expression '^' expression{$$ = new_binary_expression('^',$1,$3); };
//Ternários
expression: expression'?'expression':'expression{ $$ =  new_ternary_expression('?', $1,$3,$5); };
      

//Local Var Initialization
local_var_initialization: TK_OC_LE literal { $$ = $2;};

literal:  TK_IDENTIFICADOR{ 
$$ = new_leaf_node('I',$<valor_lexico>1);
}
|TK_LIT_INT{ 
$$ = new_leaf_node('d',$<valor_lexico>1);
}
|TK_LIT_FLOAT{ 
$$ = new_leaf_node('f',$<valor_lexico>1);
}
|TK_LIT_CHAR{ 
$$ = new_leaf_node('c',$<valor_lexico>1);
}
|TK_LIT_STRING{ 
$$ = new_leaf_node('s',$<valor_lexico>1);
}
|TK_LIT_TRUE{ 
$$ = new_leaf_node('T',$<valor_lexico>1);
}
|TK_LIT_FALSE{ 
$$ = new_leaf_node('F',$<valor_lexico>1);
};






%%
