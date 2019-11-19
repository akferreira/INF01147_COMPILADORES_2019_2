%code requires {
    #include "ast.h"
    //extern void *arvore;
}


%union {
  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  MODIFIER_S var_modifier;
  ARRAY_DIMENSIONS *dimensions;
  
  
}


%{
#define DEBUG 0

//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol_table.h"
#include "ILOC.h"


extern void *arvore;
extern int get_line_number (void);
extern int tempCount;
extern int initial_local_var_position;
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



%right '!''#'

%left TK_OC_OR
%left TK_OC_AND 
%left TK_OC_EQ
%left TK_OC_LE TK_OC_GE

%left   '|'
%left   '&'
%left  TK_OC_SR TK_OC_SL '<' '>'
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
%type <ast_node> program grammars global_var_declaration function_call expression expression_list identifier  if_statement simple_identifier command_return shift_command shift output_command input_command assignment_command  vector  literal_id local_var_declaration   null_node command_block_loop command_block command command_list loops loop_for loop_while loop_for_command loop_for_command_list function_declaration function_parameters_argument function_parameters_list call_parameter_list local_var_initialization function_command_block dimension_exp_list;

%type <valor_lexico> primitive_type TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_STRING TK_PR_CHAR function_id TK_IDENTIFICADOR TK_LIT_CHAR TK_LIT_STRING TK_LIT_FLOAT TK_LIT_INT;
 
%type <var_modifier> modifiers no_modifier;

%type <dimensions> vector_dimensions;


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
program: grammars program  
{
	$$ =  new_global_grammar_node('|',arvore,$1,$2);




	char *code1,*code2;
	if($1 == NULL) code1 = NULL;
	else code1 = $1->code;


	if($2 == NULL) code2 = NULL;
	else code2 = $2->code;

	$$->code = concatCode(code1,code2);

};



grammars:global_var_declaration|function_declaration;
	
//Declaração de variaveis globais
global_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR ';'{$$ = new_static_global_var_declaration_node('g',$2,$<valor_lexico>3,NULL);};
global_var_declaration: primitive_type TK_IDENTIFICADOR';'{$$ = new_nonstatic_global_var_declaration_node('g',$1,$<valor_lexico>2,NULL);};

global_var_declaration: TK_PR_STATIC primitive_type TK_IDENTIFICADOR vector_dimensions';' {$$ = new_static_global_var_declaration_node('g',$2,$<valor_lexico>3,$4);};
global_var_declaration: primitive_type TK_IDENTIFICADOR vector_dimensions';'{$$ = new_nonstatic_global_var_declaration_node('g',$1,$<valor_lexico>2,$3);};


//decl: primitive_type identifier;

primitive_type: TK_PR_INT { $1.var_type = TYPE_INT; $$ = $1;}
|TK_PR_FLOAT { $1.var_type = TYPE_FLOAT; $$ = $1;}
|TK_PR_CHAR{ $1.var_type = TYPE_CHAR; $$ = $1;}
|TK_PR_BOOL{ $1.var_type = TYPE_BOOL; $$ = $1;}
|TK_PR_STRING{ $1.var_type = TYPE_STRING; $$ = $1;};

identifier: simple_identifier {$$ = $1;}
|vector {$$ = $1;};

simple_identifier: TK_IDENTIFICADOR {$$ = new_leaf_node(ID_NODE,$<valor_lexico>1);}
vector: TK_IDENTIFICADOR dimension_exp_list{

$$ = new_leaf_node(ID_NODE,$<valor_lexico>1);

SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>1);

$$->ast_valor_lexico.nature = id_info.nature;

if(id_info.nature == FUNCTION){
    printf("Semantical error line %d, column %d : ERR_FUNCTION\n",$<valor_lexico>1.line,$<valor_lexico>1.column);
    exit(ERR_FUNCTION);
}

ast_node* node = $2;
ARRAY_DIMENSIONS *d = id_info.vector_dimension;

$$->temp = newTemp();

int first_dimension_flag = 1;

while(node){
//previous_size = previous_size * vector_dimension->dsize + indexes->dsize;
    
    if(first_dimension_flag) {
        $$->code = concatCode($$->code,copyRegToReg(node->temp,$$->temp));
//         printf("%s =  %s\n",$$->temp,node->temp);
    }
    
    else{
        $$->code = concatCode($$->code,binaryOperationInteger("multI",$$->temp, d->dsize,$$->temp));
        $$->code = concatCode($$->code,binaryOperation("add",$$->temp, node->temp,$$->temp));
//         printf("%s = %s * %d\t",$$->temp,$$->temp,d->dsize);
//         printf("%s = %s + %s\n",$$->temp,$$->temp,node->temp);
    }
    
    first_dimension_flag = 0;
    
    //printf("exp %s || %d\n", node->temp,d->dsize);
    node = node->next_sibling;
    d = d->next;
}
$$->code = concatCode($$->code,binaryOperationInteger("multI",$$->temp, get_size2(id_info),$$->temp));
$$->code = concatCode($2->code,$$->code);

//printf("array calc:\n%s",$$->code);







$$->code = concatCode($$->code,storeVariableRegOffsetToTemp($$->temp,$$->temp, id_info.depth));



}

vector_dimensions: '['TK_LIT_INT']' vector_dimensions {
$$ = malloc(sizeof(ARRAY_DIMENSIONS));
$$->dsize = $<valor_lexico>2.value.intvalue;
$$->next = $4;

}
| '['TK_LIT_INT']'{
$$ = malloc(sizeof(ARRAY_DIMENSIONS));
$$->dsize = $<valor_lexico>2.value.intvalue;
$$->next = NULL;

};



//Function declaration
function_declaration: TK_PR_STATIC function_id enter_scope  '('function_parameters_list')' function_command_block 
{
$$ = new_static_function_declaration_node('M',$2,$5,$7);
char *l0 = malloc(10);
strcpy(l0,"L0: ");

$$->label = l0;
char *first_inst = malloc(50);
strncpy(first_inst, "addI rsp, 4 => rsp\n",50);
$$->label = concatCode($$->label, first_inst );
$$->code = concatCode($$->label,$7->code);



};
function_declaration: function_id enter_scope '('function_parameters_list')' function_command_block {

 char *label = getFunctionLabel($1.value.str_value);
 
 //fprintf(stderr, "\n%s FUNCTION. Label : %s\n",$1.value.str_value,label);
$$ = new_nonstatic_function_declaration_node('M',$1,$4,$6);


if(initial_local_var_position != 0){

    $$->label = concatCode(label, ": ");
    
    
    
    int parameters_total_size = 0;
    int id_size = 4;
    
    
    ast_node *loop = $4;
    //if(loop) fprintf(stderr, "%s loop\n",loop->ast_valor_lexico.value.str_value);
    
    
    
    while(loop){
    
    //fprintf(stderr, "%s : load %d\n", loop->ast_valor_lexico.value.str_value, parameters_total_size+12);
    
    parameters_total_size += get_size(loop->ast_valor_lexico);
    
    loop = loop->next_sibling;
    }
    
    //printf("total parameters size : %d\n",parameters_total_size);
    
    int first_local_var_position = id_size + parameters_total_size + 12;
    
  //   printf("first local var: %d\n",first_local_var_position);
     
      
     
     char *activation_register = concatCode(copyRegToReg("rsp", "rfp"),binaryOperationInteger("addI", "rsp" , first_local_var_position, "rsp"));
    
     char *code = strdup($6->code);
     
    $$->code = concatCode($$->label,activation_register); 
   
     //printf("code : %s\n",code);
    $$->code = concatCode($$->code, code);
    
    char *reg_retorno = newTemp();
    char *reg_rsp = newTemp();
    char *reg_rfp = newTemp();
    
    $$->code =  concatCode($$->code, binaryOperationInteger("loadAI", "rfp" , OFFSET_RETURN_ADDR, reg_retorno));
    $$->code = concatCode($$->code, binaryOperationInteger("loadAI", "rfp" , OFFSET_RSP, reg_rsp));
    $$->code = concatCode($$->code, binaryOperationInteger("loadAI", "rfp" , OFFSET_RFP, reg_rfp));
    $$->code = concatCode($$->code, copyRegToReg(reg_rsp,"rsp") );
    $$->code = concatCode($$->code, copyRegToReg(reg_rfp,"rfp") );
    $$->code = concatCode($$->code, jumpReg(reg_retorno));

}



else if($$ != NULL && $6 != NULL ){
    
    $$->label = concatCode(label, ": ");

    char *first_inst = malloc(50);
    strncpy(first_inst, " : addI rsp, 4 => rsp\n",50);
    $$->label = concatCode($$->label, first_inst );
    
    $$->code = concatCode($$->label,$6->code);
}
//printf("function\n%s",$$->code);
};

//regra para definir o tipo do identificador da função
function_id: primitive_type TK_IDENTIFICADOR {

$<valor_lexico>2.var_type = $1.var_type;
$<valor_lexico>2.nature = FUNCTION;
insert_function_entry($<valor_lexico>2);
$$ = $<valor_lexico>2;
free($1.value.str_value);
addFunction(newLabel(), $$.value.str_value);

};


function_parameters_list: {$$ = get_null();}

|function_parameters_argument {$$ = $1;}

|function_parameters_argument','function_parameters_list { $$ = new_parameter_list_node($1,$3);};
function_parameters_argument:TK_PR_CONST primitive_type TK_IDENTIFICADOR { $$ = new_const_parameter_node('p',$2,$<valor_lexico>3);};
function_parameters_argument:primitive_type TK_IDENTIFICADOR {      $$ = new_nonconst_parameter_node('p',$1,$<valor_lexico>2); };




function_command_block: '{'command_list'}' exit_scope { 
$$ = new_command_block_node('{',$2);

if($2 != NULL) $$->code = concatCode($2->code, $$->code);
else if($$ != NULL) $$->code = NULL;

$$->temp = malloc(strlen("r999999"));
sprintf($$->temp, "r%d", tempCount-1);
// printf("r%d <> \n%s\n", tempCount-1, $2->code);


};


//Command Block
command_block: enter_scope '{'command_list'}' exit_scope { 
$$ = new_command_block_node('{',$3);
$$->code = concatCode($3->code, $$->code);
};

command_list: 
command command_list {
$$ = new_command_list_node($1,$2);
char *code1,*code2;
if($1 == NULL) code1 = NULL;
else {
    code1 = $1->code;
    $$->temp = $1->temp;
}

if($2 == NULL) code2 = NULL;
else{
code2 = $2->code;
}

$$->code = concatCode(code1, code2);



}
|command_block';' command_list {
new_command_list_node($1,$3);
$$->code = concatCode($1->code, $3->code);
}
| loops command_list {
$$ = new_command_list_node($1,$2);

char *code1 = NULL;
char *code2 = NULL;

if($1) code1 = $1->code;
if($2) code2 = $2->code;

$$->code = concatCode(code1, code2);

}
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

    if($4->ast_valor_lexico.nature == LITERAL){
        SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>3);

        $$->code = storeTempToVariable($4->temp, id_info.depth, id_info.position);
        $$->code = concatCode($4->code, $$->code);
        
        
        $$->temp = $4->temp;

        //printf("local decl code : %s",$$->code);
    }

};

local_var_declaration: primitive_type TK_IDENTIFICADOR local_var_initialization no_modifier{
    $$ = new_local_var_declaration_node('<', $4 ,$1,$<valor_lexico>2,$3 ) ;


    if($3->ast_valor_lexico.nature == LITERAL){
        SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>2);

        $$->code = storeTempToVariable($3->temp, id_info.depth, id_info.position);
        $$->code = concatCode($3->code, $$->code);
        $$->temp = $3->temp;
    }

};
local_var_declaration: primitive_type TK_IDENTIFICADOR null_node no_modifier{
$$ = new_local_var_declaration_node('<', $4 ,$1,$<valor_lexico>2,$3) ;
};
//Local Var Initialization
local_var_initialization: TK_OC_LE literal_id{ $$ = $2;}


//Chamada de Função

function_call: simple_identifier '(' call_parameter_list ')'{ 
$$ = new_function_call_node(FUNCTION_CALL_NODE,$1,$3);
int expression_line_count;
char *param_code = NULL;

if($3) {
    expression_line_count = countLines($3->code,strlen($3->code));
    param_code = $3->code;
}
else expression_line_count = 0;




char * regRetornoAddr = newTemp();
$$->temp = newTemp();

//$$->code = concatCode($$->code, binaryOperationInteger("addI","rsp",4, "rsp") );
$$->code = concatCode($$->code, binaryOperationInteger("addI","rpc",expression_line_count*2 + 5, regRetornoAddr) );
$$->code = concatCode($$->code, param_code);
$$->code = concatCode($$->code, storeTempToRegOffset(regRetornoAddr, "rsp", OFFSET_RETURN_ADDR));
$$->code = concatCode($$->code, storeTempToRegOffset("rsp", "rsp", OFFSET_RSP));
$$->code = concatCode($$->code, storeTempToRegOffset("rfp", "rsp", OFFSET_RFP));


int numParameter = 0;

ast_node *loop_exp = $3;

while(loop_exp){

$$->code = concatCode($$->code, storeTempToRegOffset(loop_exp->temp, "rsp", OFFSET_FIRSTVAR + numParameter * get_size(loop_exp->ast_valor_lexico) ));
// printf("Reg exp %s\n", loop_exp->temp);
loop_exp = loop_exp->next_sibling;
numParameter++;
}
$$->code = concatCode($$->code, jumpLabel( getFunctionLabel($1->ast_valor_lexico.value.str_value) ));
$$->code = concatCode($$->code, binaryOperationInteger("loadAI", "rsp", OFFSET_RETURN,$$->temp));
};

call_parameter_list:expression ',' call_parameter_list {
$$ = new_expression_list_node($1,$3);
char *code = NULL;
if($3) code = $3->code;
// printf("code 1:%s\n code 2 %s\n",$1->code,code);



if($3)$$->code = concatCode($3->code, $$->code);



};
| expression 
| {$$ = get_null();};


//Comando de Atribuição
assignment_command: identifier '=' expression { 
//printf("assign %p , %p\n",$1,$3);
$$ = new_assignment_node($1,$3,0);

//printf("assign %p , %p\n",$1,$3);
SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>1);
if(id_info.nature == VECTOR){
    $$->code = concatCode($1->code, storeTempToVariableRegOffset($3->temp,$1->temp,id_info.depth));
}

else {
    if($3->ast_valor_lexico.nature == VECTOR) $$->code = concatCode(loadMemRegToReg($3->temp,$3->temp),storeTempToVariable($3->temp, id_info.depth, id_info.position));
    
    else $$->code = concatCode($$->code,storeTempToVariable($3->temp, id_info.depth, id_info.position));

// $$->code = concatCode( storeTempToVariable($3->temp, id_info.depth, id_info.position);
}


$$->code = concatCode($3->code,$$->code);

$$->temp = $3->temp;


};

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
command_return: TK_PR_RETURN expression { 
$$ = new_return_command_node('R',$<valor_lexico>1,$2);

if($2->ast_valor_lexico.nature == LITERAL){
    $$->temp = $2->temp;
    $$->code = $2->code;
}

else if($2->ast_valor_lexico.nature == VECTOR){
    $$->code = concatCode($2->code, loadMemRegToReg($2->temp,$2->temp));
    $$->temp = $2->temp;
}

else  {
$$->code = $2->code;
$$->temp = $2->temp;


}

$$->code = concatCode($$->code,storeTempToVariable($2->temp, 1, OFFSET_RETURN));

};

//If Statement
if_statement: TK_PR_IF '(' expression ')' command_block null_node {

$$ = new_ifelse_node(':',$3,$5,$6);
$$->code = $3->code;

char *true_block_label = $3->true->remendo;
char *false_block_label = $3->false->remendo;

$$->code = concatCode($$->code,true_block_label);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code,$5->code);
$$->code = concatCode($$->code,false_block_label);
$$->code = concatCode($$->code,strdup(": "));

if(DEBUG) fprintf( stderr,"%p // %p\n",$3->true, $3->false);


LISTA_REMENDOS *lr_tempt = $3->true;
LISTA_REMENDOS *lr_tempf = $3->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",$3->true, $3->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
$$->code = strrep($$->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
$$->code = strrep($$->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}

if(DEBUG) fprintf( stderr, "if code\n%s\n",$$->code);


};
if_statement: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block {
$$ = new_ifelse_node(':',$3,$5,$7);
$$->code = concatCode($3->code,$5->code);
$$->code = concatCode($$->code,$7->code);

char *true_block_label = $3->true->remendo;
char *false_block_label = $3->false->remendo;

$$->code = concatCode($$->code,true_block_label);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code,$5->code);
$$->code = concatCode($$->code,false_block_label);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code,$7->code);


LISTA_REMENDOS *lr_tempt = $3->true;
LISTA_REMENDOS *lr_tempf = $3->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",$3->true, $3->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
$$->code = strrep($$->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
$$->code = strrep($$->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}

if(DEBUG) fprintf( stderr, "if code\n%s\n",$$->code);



};

//Loops
 command_block_loop: '{'command_block_loop'}' {$$ = $2;};
 command_block_loop: '{''}' {$$ = get_null();};
 command_block_loop: command;

loops: loop_for | loop_while; 


loop_while:TK_PR_WHILE'('expression')' TK_PR_DO command_block{
$$ = new_loop_while_node('w',$3,$6);
char *true_block_label = $3->true->remendo;
char *false_block_label = $3->false->remendo;
char *loop_start = newLabel();
char *loop_start1 = strdup(loop_start);



$$->code = concatCode($$->code,loop_start);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code, $3->code);
$$->code = concatCode($$->code,true_block_label);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code,$6->code);
$$->code = concatCode($$->code,strdup("jumpI -> "));
$$->code = concatCode($$->code,loop_start1);
$$->code = concatCode($$->code,strdup("\n"));
$$->code = concatCode($$->code,false_block_label);
$$->code = concatCode($$->code,strdup(": "));

LISTA_REMENDOS *lr_tempt = $3->true;
LISTA_REMENDOS *lr_tempf = $3->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",$3->true, $3->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
$$->code = strrep($$->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
$$->code = strrep($$->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}


}
loop_while:TK_PR_WHILE'('expression')' command_block {
$$ = new_loop_while_node('w',$3,$5);
char *true_block_label = $3->true->remendo;
char *false_block_label = $3->false->remendo;
char *loop_start = newLabel();
char *loop_start1 = strdup(loop_start);



$$->code = concatCode($$->code,loop_start);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code, $3->code);
$$->code = concatCode($$->code,true_block_label);
$$->code = concatCode($$->code,strdup(": "));
$$->code = concatCode($$->code,$5->code);
$$->code = concatCode($$->code,strdup("jumpI -> "));
$$->code = concatCode($$->code,loop_start1);
$$->code = concatCode($$->code,strdup("\n"));
$$->code = concatCode($$->code,false_block_label);
$$->code = concatCode($$->code,strdup(": "));

LISTA_REMENDOS *lr_tempt = $3->true;
LISTA_REMENDOS *lr_tempf = $3->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",$3->true, $3->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
$$->code = strrep($$->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
$$->code = strrep($$->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}


};
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
	$$->temp = newTemp();
	$$->code = binaryOperation("add", $1->temp, $3->temp,$$->temp);
	char *subexpression_code  = concatCode($1->code, $3->code);
	$$->code = concatCode(subexpression_code, $$->code);
	
	//printf("Add code:\t: %s\n",$$->code);
	
};

expression: expression '-' expression
{
	$$ = new_binary_expression('-',$1,$3); 
	$$->temp = newTemp();
	$$->code = binaryOperation("sub", $1->temp, $3->temp,$$->temp);
	char *subexpression_code  = concatCode($1->code, $3->code);
	$$->code = concatCode(subexpression_code, $$->code);

	//printf("sub code:\t: %s\n",$$->code);
};
expression: expression '*' expression
{
	$$ = new_binary_expression('*',$1,$3);
	$$->temp = newTemp();
	$$->code = binaryOperation("mult", $1->temp, $3->temp,$$->temp);
	char *subexpression_code  = concatCode($1->code, $3->code);
	$$->code = concatCode(subexpression_code, $$->code);

	//printf("mul code:\t: %s\n",$$->code);
};
expression: expression '/' expression
{
	$$ = new_binary_expression('/',$1,$3); 
	$$->temp = newTemp();
	$$->code = binaryOperation("div", $1->temp, $3->temp,$$->temp);
	char *subexpression_code  = concatCode($1->code, $3->code);
	$$->code = concatCode(subexpression_code, $$->code);

	//printf("div code:\t: %s\n",$$->code);
};
expression: expression '%' expression{$$ = new_binary_expression('%',$1,$3); };












expression: expression TK_OC_OR expression
{
	$$ = new_binary_expression('|',$1,$3);
	

	$$->temp = newTemp();
	
	
	char *cc_label = $1->false->remendo;
	char *old_label = $1->false->remendo;
	
	$$->false = $3->false;
	$$->true = concatRemendo($1->true, $3->true);
	//$1->false = replaceRemendo($1->false, cc_label);
	
// 	fprintf( stderr, "orleft %s\n",$1->true->remendo);
	if(DEBUG) fprintf( stderr, "orleft %s \t%s\n",$1->false->remendo,cc_label);
// 	fprintf( stderr, "orright %s\n",$3->true->remendo);
// 	fprintf( stderr, "orright %s\n",$3->false->remendo);

    $$->code = concatCode($$->code, $1->code);
	$$->code = concatCode($$->code, cc_label);
	$$->code = concatCode($$->code, strdup(": "));
	$$->code = concatCode($$->code, $3->code);
	//$$->code = replace_str(old_label,$$->code, cc_label);
	if(DEBUG) fprintf( stderr, "%s\n\n\n",$$->code);
};

expression: expression TK_OC_AND expression
{
	$$ = new_binary_expression('&',$1,$3);
	
	$$->temp = newTemp();
	char *cc_label = $1->true->remendo;
	$$->true = $3->true;
	$$->false = concatRemendo($1->false, $3->false);
	
	    $$->code = concatCode($$->code, $1->code);
	$$->code = concatCode($$->code, cc_label);
	$$->code = concatCode($$->code, strdup(": "));
	$$->code = concatCode($$->code, $3->code);
	
	if(DEBUG) fprintf( stderr, "%s\n\n\n",$$->code);

};









expression: expression TK_OC_EQ expression
{
	$$ = new_binary_expression(TK_OC_EQ,$1,$3);
	$$ = GenerateCompOPCode($$, $1, $3, strdup("cmp_NE"));
    

};
expression: expression TK_OC_LE expression
{
	$$ = new_binary_expression(TK_OC_LE,$1,$3);
	$$ = GenerateCompOPCode($$, $1, $3, strdup("cmp_LE"));
};

expression: expression TK_OC_GE expression
{
	
	$$ = new_binary_expression(TK_OC_GE,$1,$3);
	$$ = GenerateCompOPCode($$, $1, $3, strdup("cmp_GE"));
};




expression: expression '>' expression
{
	$$ = new_binary_expression('>',$1,$3);
	$$ = GenerateCompOPCode($$, $1, $3, strdup("cmp_GT"));
};

expression: expression '<' expression
{
	$$ = new_binary_expression('<',$1,$3);
	$$ = GenerateCompOPCode($$, $1, $3, strdup("cmp_LT"));
};












expression: expression '^' expression{$$ = new_binary_expression('^',$1,$3); };




//Ternários
expression: expression'?'expression':'expression{ $$ =  new_ternary_expression('?', $1,$3,$5); };   
expression : literal_id {$$ = $1;};








dimension_exp_list: '['expression']' dimension_exp_list
{
	$$ = new_expression_list_node($2,$4);
	$$->code = concatCode($2->code, $4->code);
}
| '['expression']' {$$ = $2;}














//era expression
literal_id:  TK_IDENTIFICADOR
{ 

	$$ = new_leaf_node(ID_NODE,$<valor_lexico>1);
	SYMBOL_INFO id_info = retrieve_symbol($<valor_lexico>1);
	$$->ast_valor_lexico.nature = id_info.nature;


	if(id_info.nature == FUNCTION)
	{
	    printf("Semantical error line %d, column %d : ERR_FUNCTION\n",$<valor_lexico>1.line,$<valor_lexico>1.column);
	    exit(ERR_FUNCTION);
	}

	$$->temp = newTemp();
	$$->code = storeVariableToTemp($$->temp, id_info.depth, id_info.position);

	//printf("code id: %s\n",$$->code);

}
| function_call 
{
	$$ = $1;
}

| vector 
{
	$$ = $1;
}



|TK_LIT_INT
{ 
	$1.var_type = TYPE_INT;
	$$ = new_leaf_node('d',$<valor_lexico>1);
	$$->temp = newTemp();
	$$->code = loadValueToTemp($<valor_lexico>1.value.intvalue, $$->temp);

	//printf("code %s\n",$$->code);

}
|TK_LIT_FLOAT{ 
	$1.var_type = TYPE_FLOAT;
	$$ = new_leaf_node('f',$<valor_lexico>1);
}
|TK_LIT_CHAR{ 

$1.var_type = TYPE_CHAR;
	$$ = new_leaf_node('c',$<valor_lexico>1);
}
|TK_LIT_STRING{ 
	$1.var_type = TYPE_STRING;
	$$ = new_leaf_node('s',$<valor_lexico>1);
}
|TK_LIT_TRUE{ 
	$$ = new_leaf_node('T',$<valor_lexico>1);
}
|TK_LIT_FALSE{ 
	$$ = new_leaf_node('F',$<valor_lexico>1);
};





%%
