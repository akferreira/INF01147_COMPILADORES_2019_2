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

%%
//programa:
program: /* empty */;
program:grammars program;
grammars:global_var_declaration|function_declaration;
	
//Declaração de variaveis globais
global_var_declaration: TK_PR_STATIC decl';';
global_var_declaration: decl';';
decl: primitive_type identifier;
primitive_type: TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL|TK_PR_STRING;
identifier: TK_IDENTIFICADOR|TK_IDENTIFICADOR'['TK_LIT_INT']';


//Function declaration
function_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block;
function_declaration: primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block;
	function_parameters_list: |function_parameters_argument|function_parameters_argument','function_parameters_list;
	function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR;
	function_parameters_argument:primitive_type TK_IDENTIFICADOR;

//Command Block
command_block: '{'command_list'}';

command_list: command';' command_list | loop_while command_list|loop_for command_list |command_block|;


//command
command: if_statement | local_var_declaration| shift_command | assignment_command| input_command| output_command| function_call|command_return| TK_PR_BREAK |TK_PR_CONTINUE;



//Local Var declaration
local_var_declaration:  TK_PR_STATIC TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: primitive_type TK_IDENTIFICADOR;


//Comando de Atribuição
assignment_command: identifier '=' expression {}

//Comandos de Entrada e Saída
input_command: TK_PR_INPUT expression;

output_command: TK_PR_OUTPUT expression;
output_command: TK_PR_OUTPUT expression_list;
//expression
//Chamada de Função
function_call: TK_IDENTIFICADOR '(' expression_list ')';
function_call: TK_IDENTIFICADOR '(' expression ')';
//function_call: TK_IDENTIFICADOR '(' call_parameter_list ')';
//call_parameter_list:expression ',' call_parameter_list | expression;


//shift
shift: TK_OC_SL | TK_OC_SR;
shift_command: identifier shift expression;

//Retorno
command_return: TK_PR_RETURN expression;

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



%type <ast_node> expression expression_list ;


expression_list:  expression ',' expression_list { printf("aaaaa\n");};
|  ',' expression {printf("aaaaa\n");};

expression: terminal_expression{ 
$$ = new_leaf_node(TERMINAL,$<valor_lexico>1);
};

terminal_expression: TK_IDENTIFICADOR|TK_LIT_INT|TK_LIT_FLOAT|TK_LIT_CHAR|TK_LIT_STRING|TK_LIT_TRUE|TK_LIT_FALSE;

//expression: expression_unary | expression_binary| expression_ternary;


expression: '(' expression ')'{ printf("aaaaa\n");};
//Unários
expression:'+'expression{ $$ = $2;};
expression:'-'expression{ $$ = new_unary_expression(MINUS,$2);};
expression:'!'expression{ $$ = new_unary_expression(INVERT,$2); };
expression:'&'expression { $$ = new_unary_expression(ADDRESS,$2); };
expression:'*'expression {$$ = new_unary_expression(CONTENT,$2); };
expression:'?'expression{$$ = new_unary_expression(BOOL_EVAL,$2); };
expression:'#'expression{$$ = new_unary_expression(HASH,$2); };
//Binários
expression: expression '+' expression {$$ = new_binary_expression(ADD,$1,$3);};
expression: expression '-' expression{$$ = new_binary_expression(SUB,$1,$3); };
expression: expression '*' expression{$$ = new_binary_expression(MUL,$1,$3);};
expression: expression '/' expression{$$ = new_binary_expression(DIV,$1,$3); };
expression: expression '%' expression{$$ = new_binary_expression(MOD,$1,$3); };
expression: expression '|' expression{$$ = new_binary_expression(OR,$1,$3); };
expression: expression '&' expression{$$ = new_binary_expression(AND,$1,$3);};
expression: expression '^' expression{$$ = new_binary_expression(POWER,$1,$3); };
//Ternários
expression: expression'?'expression':'expression{printf("\nhey = "); printf("%d",$<valor_lexico.intvalue>1); };
      

//Local Var Initialization
local_var_initialization: TK_OC_LE TK_IDENTIFICADOR|TK_OC_LE TK_LIT_CHAR|TK_OC_LE TK_LIT_STRING|TK_OC_LE TK_LIT_FLOAT|TK_OC_LE TK_LIT_INT;




%%
