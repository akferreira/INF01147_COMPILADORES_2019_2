%option yylineno
%x BLOCK_COMMENT
%x LINE_COMMENT

%{
//{newline} {line_number++;}newline \n$
#include <stdio.h>
#include "tokens.h"
int get_line_number();
int line_number = 1;
%}


letter [a-zA-z]
digit [0-9]
integer ([+|-]?){digit}+
alphanumeric [a-zA-z0-9]
id {letter}({alphanumeric}+?)

literal_char '{letter}'
literal_int {integer}
literal_string \"{letter}+\"

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



	/* palavras reservadas */
"int" {return TK_PR_INT;}
"float" {return TK_PR_FLOAT;}
"bool" {return TK_PR_BOOL;}
"char" {return TK_PR_CHAR;}
"string" {return TK_PR_STRING;}
"if" {return TK_PR_IF;}
"then" {return TK_PR_THEN;}
"else" {return TK_PR_ELSE;}
"while" {return TK_PR_WHILE;}
"do" {return TK_PR_DO;}
"input" {return TK_PR_INPUT;}
"output" {return TK_PR_OUTPUT;}
"return" {return TK_PR_RETURN;}
"const" {return TK_PR_CONST;}
"static" {return TK_PR_STATIC;}
"foreach" {return TK_PR_FOREACH;}
"for" {return TK_PR_FOR;}
"switch" {return TK_PR_SWITCH;}
"case" {return TK_PR_CASE;}
"break" {return TK_PR_BREAK;}
"continue" {return TK_PR_CONTINUE;}
"class" {return TK_PR_CLASS;}
"private" {return TK_PR_PRIVATE;}
"public" {return TK_PR_PUBLIC;}
"protected" {return TK_PR_PROTECTED;}
"end" {return TK_PR_END;}
"default" {return TK_PR_DEFAULT;}


{literal_char} {return TK_LIT_CHAR;}

{literal_string} {return TK_LIT_STRING;}
{literal_float} {return TK_LIT_FLOAT;}

{literal_int} {return TK_LIT_INT;}

"false" {return TK_LIT_FALSE;}
"true" {return TK_LIT_TRUE;}

{id} {return TK_IDENTIFICADOR;}

. {return TOKEN_ERRO;}
%%

int get_line_number(){
    return yylineno;
}

