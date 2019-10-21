%{

//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
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

%left UNARY_QUESTION_MARK
%right UNARY_PLUS UNARY_MINUS
%right UNARY_ET UNARY_POINTER

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
function_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR '('')' command_block;

function_declaration: primitive_type TK_IDENTIFICADOR '('')' command_block;


function_parameters_list:function_parameters_argument|function_parameters_argument','function_parameters_list;

function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR;
function_parameters_argument:primitive_type TK_IDENTIFICADOR;

//Command Block
//command_block: '{'command_block'}';
command_block: '{'command_list'}';
//command_block: command_list;

command_list: command';' command_list | loop_while command_list|loop_for command_list |command_block';'|;


//command
/*command: if_statement | local_var_declaration| shift_command | assignment_command| input_command| output_command| function_call|command_return| TK_PR_BREAK |TK_PR_CONTINUE;*/

command: local_var_declaration|assignment_command|input_command|output_command|function_call|shift_command|command_return|TK_PR_BREAK|TK_PR_CONTINUE|if_statement|loop_for|loop_while;

//Local Var declaration
local_var_declaration:  TK_PR_STATIC TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: primitive_type TK_IDENTIFICADOR;
local_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR;
local_var_declaration: TK_PR_CONST primitive_type TK_IDENTIFICADOR;
local_var_declaration: TK_PR_STATIC TK_PR_CONST primitive_type TK_IDENTIFICADOR;

//Comando de Atribuição
assignment_command: identifier '=' expression;

//Comandos de Entrada e Saída
input_command: TK_PR_INPUT expression;

output_command: TK_PR_OUTPUT expression expression_list;
//output_command: TK_PR_OUTPUT TK_IDENTIFICADOR output_id_list;
//output_id_list: |','output_id_list;

//Operaçoes basicasLALR
expression_list: ','expression expression_list|;
expression: TK_IDENTIFICADOR|TK_LIT_INT|TK_LIT_FLOAT;
expression: '(' expression ')';



//Chamada de Função
function_call: TK_IDENTIFICADOR '('')';
function_call: TK_IDENTIFICADOR '(' call_parameter_list ')';
call_parameter_list:expression ',' call_parameter_list | expression;


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
	loop_while:TK_PR_WHILE'('expression')'TK_PR_DO command_block_loop;
	loop_while:TK_PR_WHILE'('expression')' command_block_loop;
    	//For
    	loop_for:TK_PR_FOR'('loop_for_command_list':'expression':'loop_for_command_list')' command_block_loop;
    	loop_for_command_list:loop_for_command','loop_for_command_list|loop_for_command;
    	loop_for_command: local_var_declaration| shift_command | assignment_command;




//Unários
expression:'+'expression %prec UNARY_PLUS;
expression:'-'expression %prec UNARY_MINUS;
expression:'!'expression;
expression:'&'expression %prec UNARY_ET;
expression:'*'expression %prec UNARY_POINTER;
expression:'?'expression %prec UNARY_QUESTION_MARK;
expression:'#'expression;
//Binários

//Expressoes Aritmeticas
expression: expression '+' expression;
expression: expression '-' expression;
expression: expression '*' expression;
expression: expression '/' expression;
expression: expression '%' expression;
expression: expression '^' expression;


//Expressoes Logicas
expression: expression TK_OC_EQ expression;
expression: expression TK_OC_LE expression;
expression: expression TK_OC_GE expression;
expression: expression '|' expression;
expression: expression '&' expression;


//Ternários
expression: expression'?'expression':'expression;

expression:function_call;


      

//Local Var Initialization
local_var_initialization: TK_OC_LE TK_IDENTIFICADOR|TK_OC_LE TK_LIT_CHAR|TK_OC_LE TK_LIT_STRING|TK_OC_LE TK_LIT_FLOAT|TK_OC_LE TK_LIT_INT;




%%
