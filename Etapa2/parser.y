%{

#include "main.c"
void yyerror (char const *s)
{
	 fprintf (stderr, "%s\n", s);
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
%left TK_PR_INT TK_PR_FLOAT TK_PR_CHAR TK_PR_BOOL TK_PR_STRING
%left '+' '-' 
%left '*' '/'
/*Mais Prioritário*/


%error-verbose
%start Input

%%
//programa:
Input: /* empty */;
Input:grammars Input;
grammars:decl|expr|foo_declaration|local_var_declaration;
/*Line: TK_PR_END
Line: decl TK_PR_END*/


	
//Declaração de variaveis globais
decl: modifcador type struct list { printf("Success!\n");} ;
list: ','decl|';';
modifcador: TK_PR_STATIC| ;
type: TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL|TK_PR_STRING;
struct: TK_IDENTIFICADOR|TK_IDENTIFICADOR'['TK_LIT_INT']';



//Operaçoes basicasLALR
expr: TK_IDENTIFICADOR|TK_LIT_INT|TK_LIT_FLOAT{ $$=$1; };
expr: expr '+' expr { $$ = $1 + $3;}{ printf("+s!\n"); } ;
expr: expr '-' expr { $$ = $1 - $3;}{ printf("-s!\n"); } ;
expr: expr '*' expr { $$ = $1 * $3;}{ printf("*s!\n"); };
expr: expr '/' expr { $$ = $1 / $3;}{ printf("/s!\n"); };


//Function Declaration
foo_declaration: foo_modifire foo_type foo_nome'('foo_parameters_list')';
foo_modifire: |TK_PR_STATIC;
foo_type: TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL;
foo_nome: TK_IDENTIFICADOR;
foo_parameters_list: |foo_parameters_argument|foo_parameters_argument','foo_parameters_list;
	foo_parameters_argument:foo_parameters_modifire foo_parameters_type foo_parameters_name;
	foo_parameters_modifire:TK_PR_CONST| ;
	foo_parameters_type:TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL;
	foo_parameters_name:TK_IDENTIFICADOR;


//Local Variable Declaration
local_var_declaration: local_var_const_modifire local_var_static_modifore local_var_type TK_IDENTIFICADOR local_var_initialization;
local_var_const_modifire:TK_PR_CONST| ;
local_var_static_modifore: |TK_PR_STATIC;
local_var_type:TK_PR_INT|TK_PR_FLOAT|TK_PR_CHAR|TK_PR_BOOL|TK_PR_STRING;
local_var_initialization: |TK_OC_LE TK_IDENTIFICADOR|TK_OC_LE TK_LIT_CHAR|TK_OC_LE TK_LIT_STRING|TK_OC_LE TK_LIT_FLOAT|TK_OC_LE TK_LIT_INT;








//If declaration -Não Funciona 
/*
if_declaration:closed_stmt|non_closed_stmt;
closed_stmt:TK_PR_IF '('')' closed_stmt TK_PR_ELSE closed_stmt|'{''}';
non_closed_stmt:TK_PR_IF '('')' '{''}'|TK_PR_IF '('')' closed_stmt TK_PR_ELSE non_closed_stmt;
*/
%%
