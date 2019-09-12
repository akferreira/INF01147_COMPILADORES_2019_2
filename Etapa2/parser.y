%{

//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
extern int get_line_number (void);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line:%d : %s\n", get_line_number(),s);
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
//%left TK_PR_INT TK_PR_FLOAT TK_PR_CHAR TK_PR_BOOL TK_PR_STRING
//%left '+' '-'
%left '*' '/' '+' '-'

%right TK_PR_STATIC


/*Mais Prioritário*/



%define parse.error verbose
%start program

%%
//programa:
program: /* empty */;
program:grammars program;
grammars:declaration|foo_declaration;
/*Line: TK_PR_END
Line: decl TK_PR_END*/


	
//Declaração de variaveis globais
declaration : TK_PR_STATIC decl';';
declaration : decl';';
//decl: TK_PR_STATIC all_types struct list { printf("Success!\n");} ;
decl: primitive_type struct list;
decl: TK_PR_STRING struct list;
decl: TK_PR_STRING struct
list: ','decl;
all_types: TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL|TK_PR_STRING;
primitive_type : TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL;
//all_types:  TK_PR_STRING | primitive_type ;
struct: TK_IDENTIFICADOR|TK_IDENTIFICADOR'['TK_LIT_INT']';



//Operaçoes basicasLALR
expr: TK_IDENTIFICADOR|TK_LIT_INT|TK_LIT_FLOAT{ $$=$1; };

expr: '(' expr ')' { $$ = $2; };
expr: expr '+' expr;
expr: expr '-' expr;
expr: expr '*' expr;
expr: expr '/' expr;

// expr: '(' expr ')' { $$ = $2; };
// expr: expr '+' expr { $$ = $1 + $3;}{ printf("+s!\n"); } ;
// expr: expr '-' expr { $$ = $1 - $3;}{ printf("-s!\n"); } ;
// expr: expr '*' expr { $$ = $1 * $3;}{ printf("*s!\n"); };
// expr: expr '/' expr { $$ = $1 / $3;}{ printf("/s!\n"); };





//Function Declaration
foo_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR function_list command_block;
foo_declaration: primitive_type TK_IDENTIFICADOR function_list command_block;
function_list: '('foo_parameters_list')';
foo_parameters_list: |foo_parameters_argument|foo_parameters_argument','foo_parameters_list;
	foo_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR;
	foo_parameters_argument:primitive_type TK_IDENTIFICADOR;

command_block: '{'command_block'}'
command_block: '{''}'
command_block: local_var_declaration| TK_PR_RETURN| TK_PR_BREAK|TK_PR_CONTINUE;

//input_command: ;






local_var_declaration:  TK_PR_STATIC TK_PR_CONST all_types TK_IDENTIFICADOR local_var_initialization';';
local_var_declaration: TK_PR_STATIC all_types TK_IDENTIFICADOR local_var_initialization';';
local_var_declaration: TK_PR_CONST all_types TK_IDENTIFICADOR local_var_initialization';';
local_var_declaration: all_types TK_IDENTIFICADOR local_var_initialization';';
local_var_declaration: all_types TK_IDENTIFICADOR';';
// local_var_declaration: TK_PR_STATIC TK_PR_CONST TK_PR_STRING TK_IDENTIFICADOR local_var_initialization;
// local_var_declaration: TK_PR_STATIC TK_PR_STRING  TK_IDENTIFICADOR local_var_initialization;
// local_var_declaration: TK_PR_CONST TK_PR_STRING  TK_IDENTIFICADOR local_var_initialization;
// local_var_declaration: TK_PR_STRING  TK_IDENTIFICADOR local_var_initialization;
local_var_initialization: TK_OC_LE TK_IDENTIFICADOR|TK_OC_LE TK_LIT_CHAR|TK_OC_LE TK_LIT_STRING|TK_OC_LE TK_LIT_FLOAT|TK_OC_LE TK_LIT_INT;








//If declaration -Não Funciona 
/*
if_declaration:closed_stmt|non_closed_stmt;
closed_stmt:TK_PR_IF '('')' closed_stmt TK_PR_ELSE closed_stmt|'{''}';
non_closed_stmt:TK_PR_IF '('')' '{''}'|TK_PR_IF '('')' closed_stmt TK_PR_ELSE non_closed_stmt;
*/
%%
