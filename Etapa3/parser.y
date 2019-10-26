%code requires {
    #include "ast.h"
}


%union {
	ast_node* ast_node;
	VALOR_LEXICO valor_lexico;
}




%{

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
extern void *arvore;
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




%type <ast_node> program
%type <ast_node> grammars
%type <ast_node> global_var_declaration
%type <ast_node> function_declaration
%type <ast_node> null_node
%type <ast_node> expression
%type <ast_node> expression_list
%type <ast_node> command_block
%type <ast_node> command_list
%type <ast_node> command





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
%left       '&'
%left       '|'
%left       TK_OC_SR TK_OC_SL
%left       '+' '-'
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
%type <ast_node>  loops loop_for loop_while loop_for_command loop_for_command_list    TK_IDENTIFICADOR TK_LIT_INT TK_LIT_FLOAT TK_LIT_TRUE TK_LIT_FALSE TK_PR_INT TK_PR_FLOAT TK_PR_CHAR TK_PR_BOOL TK_PR_STRING ;

null_node: {$$ = get_null();};


//programa:
program: /* empty */{$$ = get_null();};
program:grammars program {$$ =  new_global_grammar_node('|',arvore,$1,$2);};
grammars:global_var_declaration|function_declaration;
	
//Declaração de variaveis globais
global_var_declaration: TK_PR_STATIC decl';'{$<valor_lexico>1;};
global_var_declaration: decl';'{$<valor_lexico>1;};
decl: primitive_type identifier|primitive_type array_identifier;
primitive_type: TK_PR_INT{'t',$<valor_lexico>1;}|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL|TK_PR_STRING;
identifier: TK_IDENTIFICADOR;
array_identifier:TK_IDENTIFICADOR'['TK_LIT_INT']';



//Function declaration
function_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block{'M',$<valor_lexico>1;};
function_declaration: primitive_type TK_IDENTIFICADOR '('function_parameters_list')' command_block{'M',$<valor_lexico>1;};
function_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR '('')' command_block{'M',$<valor_lexico>1;};
function_declaration: primitive_type TK_IDENTIFICADOR '('')' command_block{'M',$<valor_lexico>1;};

function_parameters_list:function_parameters_argument|function_parameters_argument','function_parameters_list;
function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR;
function_parameters_argument:primitive_type TK_IDENTIFICADOR;

//Command Block

command_block: '{'command_list'}';
command_list: command';' command_list{$$ = new_command_list_node($1,$3);} | loop_while command_list{$$ = new_command_list_node($1,$2);}|loop_for command_list{$$ = new_command_list_node($1,$2);} |command_block';'{$$ = $1;}|{$$ = get_null();};




command: local_var_declaration|assignment_command|input_command|output_command|function_call|shift_command|command_return|TK_PR_BREAK|TK_PR_CONTINUE|if_statement|loop_for|loop_while;

//Local Var declaration
local_var_declaration: TK_PR_STATIC TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: TK_PR_CONST primitive_type TK_IDENTIFICADOR local_var_initialization;
local_var_declaration: primitive_type TK_IDENTIFICADOR local_var_initialization;

local_var_declaration: TK_PR_STATIC TK_PR_CONST primitive_type TK_IDENTIFICADOR;
local_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR;
local_var_declaration: TK_PR_CONST primitive_type TK_IDENTIFICADOR;
local_var_declaration: primitive_type TK_IDENTIFICADOR;





//Local Var Initialization
local_var_initialization: TK_OC_LE TK_IDENTIFICADOR|TK_OC_LE TK_LIT_CHAR|TK_OC_LE TK_LIT_STRING|TK_OC_LE TK_LIT_FLOAT|TK_OC_LE TK_LIT_INT;

//global_var_assignment


//Comando de Atribuição
assignment_command: identifier '=' expression;
assignment_command: identifier'['expression']' '=' expression;




//Comandos de Entrada e Saída
input_command: TK_PR_INPUT expression;

output_command: TK_PR_OUTPUT expression expression_list;
//output_command: TK_PR_OUTPUT TK_IDENTIFICADOR output_id_list;
//output_id_list: |','output_id_list;




//Chamada de Função
//function_call: identifier '('')'{$$ = new_function_call_node('K',$1,$3);};
function_call: identifier '(' call_parameter_list ')';
call_parameter_list:expression ',' call_parameter_list | expression|;


//shift
shift: TK_OC_SL| TK_OC_SR;
shift_command: identifier shift expression;

//Retorno
command_return: TK_PR_RETURN expression;

//If Statement
if_statement: TK_PR_IF '(' expression ')' command_block null_node;
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



//Operaçoes basicasLALR
expression_list: ','expression expression_list{ $$ = new_expression_list_node($2,$3);}|{$$ = get_null();};
expression: TK_IDENTIFICADOR{ $$ = $1;}|TK_LIT_INT{ $$ = $1;}|TK_LIT_FLOAT{ $$ = $1;};
expression: '(' expression ')'{ $$ = $2;};




//Unários
expression:'+'expression %prec UNARY_PLUS { $$ = $2;};
expression:'-'expression %prec UNARY_MINUS { $$ = new_unary_expression('-',$2);};
expression:'!'expression { $$ = new_unary_expression('!',$2); };
expression:'&'expression %prec UNARY_ET { $$ = new_unary_expression('@',$2); };
expression:'*'expression %prec UNARY_POINTER {$$ = new_unary_expression('$',$2); };
expression:'?'expression %prec UNARY_QUESTION_MARK {$$ = new_unary_expression('~',$2); };
expression:'#'expression {$$ = new_unary_expression('#',$2); };
//Binários

//Expressoes Aritmeticas
expression: expression '+' expression {$$ = new_binary_expression('+',$1,$3);};
expression: expression '-' expression {$$ = new_binary_expression('-',$1,$3);};
expression: expression '*' expression {$$ = new_binary_expression('*',$1,$3);};
expression: expression '/' expression {$$ = new_binary_expression('/',$1,$3);};
expression: expression '%' expression {$$ = new_binary_expression('%',$1,$3);};
expression: expression '^' expression {$$ = new_binary_expression('^',$1,$3);};


//Expressoes Logicas
expression: expression TK_OC_EQ expression expression {$$ = new_binary_expression('^',$1,$3);};
expression: expression TK_OC_LE expression expression {$$ = new_binary_expression('^',$1,$3);};
expression: expression TK_OC_GE expression expression {$$ = new_binary_expression('^',$1,$3);};
expression: expression '|' expression expression {$$ = new_binary_expression('^',$1,$3);};
expression: expression '&' expression expression {$$ = new_binary_expression('^',$1,$3);};


//Ternários
expression: expression'?'expression':'expression { $$ =  new_ternary_expression('?', $1,$3,$5); };

//Function Call
expression:function_call;
//Boolean Values
expression:TK_LIT_FALSE | TK_LIT_TRUE;






      





%%
