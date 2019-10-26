




%option yylineno
%x BLOCK_COMMENT
%x LINE_COMMENT
%x QUOTES

%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "tokens.h"
#include "symbol_table.h"

int offset;
extern YYLTYPE yylloc;

#define YY_USER_ACTION token_location();



int get_line_number(){
    return yylineno;
}

int get_column_number(){
    return yylloc.first_column;
}

void update_lexical_location(){
yylval.valor_lexico.line = get_line_number();
yylval.valor_lexico.column = get_column_number();
}


void token_location(){

    yylloc.first_column = yylloc.last_column; 
    yylloc.first_line = yylloc.last_line;
    for(int i = 0; yytext[i] != '\0'; i++) { 
        if(yytext[i] == '\n') { 
            yylloc.last_column = 0; 
            yylloc.last_line = yylineno;
        } 
        else { 
            yylloc.last_column++; 
        } 
    }

}


void integer_lexical(){

update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_LITERAL;
yylval.valor_lexico.value.intvalue = atoi(yytext);
yylval.valor_lexico.var_type = TYPE_INT;
}

void char_lexical(){
/* char *literal_char = yytext;
 literal_char[strlen(literal_char) - 1] = 0;
 literal_char = literal_char + 1;*/



update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_LITERAL;
yylval.valor_lexico.value.charvalue = *(yytext+1);
yylval.valor_lexico.var_type = TYPE_CHAR;

//free(yytext);



}

void string_lexical(){
//copia literal "string", remove aspas
int lenght = strlen(yytext)-2;
yylval.valor_lexico.value.str_value = malloc(lenght);


int quotes =0 ;
int i;
for (i=1;i<=lenght;i++){
   // printf("%p",(yylval.valor_lexico.value.str_value+i-1));
    *(yylval.valor_lexico.value.str_value+i-1) = *(yytext+i);
   // printf("\tcharrrr %c\n",*(yytext+i));
    
    if(*(yytext+1) == '"') quotes++;
    if(quotes >= 2) break;
    

}




printf("string read %s\n",yylval.valor_lexico.value.str_value);




update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_LITERAL;
//yylval.valor_lexico.value.str_value = strdup(literal_char) ;
yylval.valor_lexico.var_type = TYPE_STRING;


}



void float_lexical(){
update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_LITERAL;
yylval.valor_lexico.value.fvalue = atof(yytext);
yylval.valor_lexico.var_type = TYPE_FLOAT;
}

void bool_lexical(int bool_value){
update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_LITERAL;
yylval.valor_lexico.value.intvalue = bool_value;
yylval.valor_lexico.var_type = TYPE_BOOL;
}

int keyword_lexical(int var_type){

update_lexical_location();
yylval.valor_lexico.token_type = TK_TYPE_RESERVED_WORD;
yylval.valor_lexico.value.str_value = strdup(yytext);
yylval.valor_lexico.var_type = var_type;
return var_type;


}


int identifier_lexical(int token_type){
update_lexical_location();
yylval.valor_lexico.token_type = token_type;

yylval.valor_lexico.value.str_value = strdup(yytext);


yylval.valor_lexico.var_type = -1;

return TK_IDENTIFICADOR;


}

%}


letter [a-zA-z]
ASCII [\x00-\x7F] 
digit [0-9]
integer ([+|-]?){digit}+
alphanumeric [a-zA-z0-9]
id [a-zA-Z_][a-zA-Z0-9_]*

literal_char '{ASCII}'
literal_int {integer}

literal_string \"([^\\\"]|\\.)*\"

power (["e"|"E"]{integer})
literal_float {integer}"."({integer}?)({power}?)
literal_float1 {integer}"."

whitespace [ \n\t\r]+



%%
"/*" {BEGIN(BLOCK_COMMENT);}
"//" {BEGIN(LINE_COMMENT);}
<BLOCK_COMMENT>"*/" { BEGIN(INITIAL);}
<BLOCK_COMMENT>\n   { }
<BLOCK_COMMENT>.    { }

<LINE_COMMENT>\n   { BEGIN(INITIAL);}
<LINE_COMMENT>.    { }

\n { }
{whitespace} {}

	/* caracteres especiais */
"," {return ',';}
";" {return ';';}
":" {return ':';}
"(" {return '(';}
")" {return ')';}
"[" {return '[';}
"]" {return ']';}
"{" {return '{';}
"}" {return '}';}
"+" {return '+';}
"-" {return '-';}
"|" {return '|';}
"?" {return '?';}
"@" {return '@';}
"*" {return '*';}
"/" {return '/';}
"<" {return '<';}
">" {return '>';}
"=" {return '=';}
"!" {return '!';}
"&" {return '&';}
"%" {return '%';}
"#" {return '#';}
"^" {return '^';}
"." {return '.';}
"$" {return '$';}
"~" {return '~';}
"`" {return '`';}

	/* operadores compostos */
"<=" {return TK_OC_LE;}
">=" {return TK_OC_GE;}
"=="  {return TK_OC_EQ;}
"!=" {return TK_OC_NE;}
"&&"  {return TK_OC_AND;}
"||"  {return TK_OC_OR;}
">>"   {return TK_OC_SR;}
"<<"    {return TK_OC_SL;}
"%>%" {return TK_OC_FORWARD_PIPE;}
"%|%" {return TK_OC_BASH_PIPE;}

"false" {
bool_lexical(0);

return TK_LIT_FALSE;}


"true" {
bool_lexical(1);


return TK_LIT_TRUE;}

	/* palavras reservadas */
"int" {
keyword_lexical(TYPE_INT);

return TK_PR_INT;}


"float" { keyword_lexical(TYPE_FLOAT);  return TK_PR_FLOAT;}
"bool" {  keyword_lexical(TYPE_BOOL); return TK_PR_BOOL;}
"char" {keyword_lexical(TYPE_CHAR); return TK_PR_CHAR;}
"string" {keyword_lexical(TYPE_STRING); return TK_PR_STRING;}
"if" {return keyword_lexical(TK_PR_IF);}
"then" {return keyword_lexical(TK_PR_THEN);}
"else" {return keyword_lexical(TK_PR_ELSE);}
"while" {return keyword_lexical(TK_PR_WHILE);}
"do" {return keyword_lexical(TK_PR_DO);}
"input" {return keyword_lexical(TK_PR_INPUT);}
"output" {return keyword_lexical(TK_PR_OUTPUT);}
"return" {return keyword_lexical(TK_PR_RETURN);}
"const" {return keyword_lexical(TK_PR_CONST);}
"static" {return keyword_lexical(TK_PR_STATIC);}
"foreach" {return keyword_lexical(TK_PR_FOREACH);}
"for" {return keyword_lexical(TK_PR_FOR);}
"switch" {return keyword_lexical(TK_PR_SWITCH);}
"case" {return keyword_lexical(TK_PR_CASE);}
"break" {return keyword_lexical(TK_PR_BREAK);}
"continue" {return keyword_lexical(TK_PR_CONTINUE);}
"class" {return keyword_lexical(TK_PR_CLASS);}
"private" {return keyword_lexical(TK_PR_PRIVATE);}
"public" {return keyword_lexical(TK_PR_PUBLIC);}
"protected" {return keyword_lexical(TK_PR_PROTECTED);}
"end" {return keyword_lexical(TK_PR_END);}
"default" {return keyword_lexical(TK_PR_DEFAULT);}


{id} {return identifier_lexical(TK_TYPE_ID);}

{literal_char} {

char_lexical();



return TK_LIT_CHAR;}

{literal_string} {
//printf("string lexical %s\n",yytext);

string_lexical();
return TK_LIT_STRING;}

{literal_float} {
float_lexical();
return TK_LIT_FLOAT;}

{literal_int} {
integer_lexical();
return TK_LIT_INT;}





. {return TOKEN_ERRO; }
%%



