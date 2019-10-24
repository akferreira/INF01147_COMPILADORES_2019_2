#ifndef SYMBOL_TABLE_H_INCLUDED
#define SYMBOL_TABLE_H_INCLUDED

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

enum nature {
    LITERAL,
    VARIABLE,
    VECTOR,
    CONST,
    FUNCTION
} SYMBOL_NATURE;





typedef struct  _symbol_info{
    int line;
    int column;
    int nature;
    int var_type;
    int size;
    char *name;
    
    
} SYMBOL_INFO;


typedef struct _arg_list{
    SYMBOL_INFO* arg_info;
    
    struct _arg_list *next_argument;
    
    
    
} ARG_LIST;




typedef struct _S_TABLE{
    int valid;
    
    SYMBOL_INFO* symbol_info;
    
    ARG_LIST* argument_list;
    
    struct _S_TABLE *next;
    
    
} SYMBOL_TABLE;

typedef struct _S_STACK{
    int depth;
    
    SYMBOL_TABLE* symbol_table;
    struct _S_STACK *next;
    
} SYMBOL_STACK;




SYMBOL_STACK* push_table(SYMBOL_TABLE symbol_table);
SYMBOL_STACK* pop_table(SYMBOL_TABLE symbol_table);

int initialize_stack();

extern SYMBOL_STACK *semantic_stack;


void copy_lexical_to_symbol(SYMBOL_INFO *symbol, VALOR_LEXICO lexical);
void clean_arg_list(ARG_LIST* arg_list);
void clean_table(SYMBOL_TABLE *table);
void clean_stack(SYMBOL_STACK *stack);

int create_new_scope();
int exit_scope();
int insert_new_table_entry(VALOR_LEXICO lexical, int lenght);
int insert_parameters_function_entry(VALOR_LEXICO argument, char *function_name, int lenght);
ARG_LIST* retrieve_arg_list(char *function_name);
SYMBOL_INFO retrieve_symbol(VALOR_LEXICO lexical);
int check_symbol(VALOR_LEXICO lexical);
int check_type_compatibility(int type1, int type2);
int type_coercion(int type1, int type2);






/*
 * Um identificador não declarado é encontrado
 */

#define ERR_UNDECLARED  10


/*
 * Um identificador já declarado é encontrado
 */
#define ERR_DECLARED    11

/*
 * O identificador encontrado deve ser utilizado como uma variável, em
 * situações onde este é encontrade sendo usado como função ou como vetor,
 * ou algum outro cenário semelhante.
 */
#define ERR_VARIABLE    20



/*
 * O identificador encontrado deve ser utilizado como um vetor, em
 * situações onde este é encontrado sendo usado como variável ou função,
 * ou algum outro cenário semelhante.
 */
#define ERR_VECTOR      21



/*
 * O identificador encontrado deve ser utilizado como uma função, em
 * situações onde este é encontrado sendo usado como variável ou vetor,
 * ou algum outro cenário semelhante.
 */
#define ERR_FUNCTION    22



/*
 * Os tipos (em atribuições e outras cenários) são incompatíveis.
 */
#define ERR_WRONG_TYPE  30

/*
 * Coerção impossível da variável do tipo string para outro tipo qualquer.
 */
#define ERR_STRING_TO_X 31



/*
 * Coerção impossível da variável do tipo char para outro tipo qualquer.
 */
#define ERR_CHAR_TO_X   32



/*
 * Faltam argumentos em uma chamada de função.
 */
#define ERR_MISSING_ARGS    40



/*
 * Sobram argumentos em uma chamada de função.
 */
#define ERR_EXCESS_ARGS     41



/*
 * Os parâmetros reais são de tipos incompatíveis com os correspondentes formais.
 */
#define ERR_WRONG_TYPE_ARGS 42 //argumentos incompatíveis



/*
 * No caso específico do comando input, o parâmetro não é identificador.
 */
#define ERR_WRONG_PAR_INPUT  50 //parâmetro não é identificador



/*
 * No caso específico do comando output, os parâmetros não são literal string ou expressão
 */
#define ERR_WRONG_PAR_OUTPUT 51



/*
 * No caso específico do comando return, o parâmetro não é compatível com tipo do retorno
 */
#define ERR_WRONG_PAR_RETURN 52








#endif // SYMBOL_TABLE_H_INCLUDED
