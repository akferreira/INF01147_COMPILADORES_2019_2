/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:355  */

    #include "ast.h"
    //extern void *arvore;

#line 102 "parser.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_STRING = 262,
    TK_PR_IF = 263,
    TK_PR_THEN = 264,
    TK_PR_ELSE = 265,
    TK_PR_WHILE = 266,
    TK_PR_DO = 267,
    TK_PR_INPUT = 268,
    TK_PR_OUTPUT = 269,
    TK_PR_RETURN = 270,
    TK_PR_CONST = 271,
    TK_PR_STATIC = 272,
    TK_PR_FOREACH = 273,
    TK_PR_FOR = 274,
    TK_PR_SWITCH = 275,
    TK_PR_CASE = 276,
    TK_PR_BREAK = 277,
    TK_PR_CONTINUE = 278,
    TK_PR_CLASS = 279,
    TK_PR_PRIVATE = 280,
    TK_PR_PUBLIC = 281,
    TK_PR_PROTECTED = 282,
    TK_PR_END = 283,
    TK_PR_DEFAULT = 284,
    TK_OC_LE = 285,
    TK_OC_GE = 286,
    TK_OC_EQ = 287,
    TK_OC_NE = 288,
    TK_OC_AND = 289,
    TK_OC_OR = 290,
    TK_OC_SL = 291,
    TK_OC_SR = 292,
    TK_OC_FORWARD_PIPE = 293,
    TK_OC_BASH_PIPE = 294,
    TK_LIT_INT = 295,
    TK_LIT_FLOAT = 296,
    TK_LIT_FALSE = 297,
    TK_LIT_TRUE = 298,
    TK_LIT_CHAR = 299,
    TK_LIT_STRING = 300,
    TK_IDENTIFICADOR = 301,
    TOKEN_ERRO = 302,
    UNARY_QUESTION_MARK = 303,
    UNARY_PLUS = 304,
    UNARY_MINUS = 305,
    UNARY_ET = 306,
    UNARY_POINTER = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "parser.y" /* yacc.c:355  */

  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  MODIFIER_S var_modifier;
  ARRAY_DIMENSIONS *dimensions;
  
  

#line 176 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 17 "parser.y" /* yacc.c:358  */

#define DEBUG 0
//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol_table.h"
#include "ILOC.h"


extern void *arvore;
extern int get_line_number (void);
extern void exporta (void *arvore);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line %d Column %d : %s\n", get_line_number(),yylloc.last_column,s);
	 exit(1);
}
extern int yylex (void);
int yyparse (void);



#line 231 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,    58,    51,     2,
      70,    71,    56,    54,    72,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    67,
      52,    75,    53,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    50,    74,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    62,    63,    64,    65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   148,   152,   155,   156,   177,   177,   180,
     181,   183,   184,   189,   190,   191,   192,   193,   195,   196,
     198,   199,   257,   263,   273,   288,   308,   320,   322,   323,
     324,   325,   330,   341,   347,   362,   366,   378,   381,   381,
     381,   381,   381,   381,   381,   382,   384,   385,   390,   391,
     392,   394,   398,   412,   424,   428,   433,   435,   436,   437,
     441,   469,   471,   472,   478,   479,   481,   484,   487,   526,
     567,   568,   569,   571,   571,   574,   615,   656,   659,   660,
     662,   662,   662,   674,   675,   679,   681,   682,   683,   684,
     685,   686,   687,   695,   707,   717,   727,   737,   750,   778,
     804,   811,   817,   827,   833,   850,   856,   857,   866,   871,
     887,   907,   912,   919,   929,   933,   938,   942,   945
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_STRING", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE",
  "TK_PR_WHILE", "TK_PR_DO", "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN",
  "TK_PR_CONST", "TK_PR_STATIC", "TK_PR_FOREACH", "TK_PR_FOR",
  "TK_PR_SWITCH", "TK_PR_CASE", "TK_PR_BREAK", "TK_PR_CONTINUE",
  "TK_PR_CLASS", "TK_PR_PRIVATE", "TK_PR_PUBLIC", "TK_PR_PROTECTED",
  "TK_PR_END", "TK_PR_DEFAULT", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_OC_SL", "TK_OC_SR",
  "TK_OC_FORWARD_PIPE", "TK_OC_BASH_PIPE", "TK_LIT_INT", "TK_LIT_FLOAT",
  "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_LIT_STRING",
  "TK_IDENTIFICADOR", "TOKEN_ERRO", "'!'", "'#'", "'|'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'?'", "':'",
  "UNARY_QUESTION_MARK", "UNARY_PLUS", "UNARY_MINUS", "UNARY_ET",
  "UNARY_POINTER", "';'", "'['", "']'", "'('", "')'", "','", "'{'", "'}'",
  "'='", "$accept", "enter_scope", "exit_scope", "null_node", "program",
  "grammars", "global_var_declaration", "primitive_type", "identifier",
  "simple_identifier", "vector", "vector_dimensions",
  "function_declaration", "function_id", "function_parameters_list",
  "function_parameters_argument", "function_command_block",
  "command_block", "command_list", "command", "modifiers", "no_modifier",
  "local_var_declaration", "local_var_initialization", "function_call",
  "call_parameter_list", "assignment_command", "input_command",
  "output_command", "shift", "shift_command", "command_return",
  "if_statement", "command_block_loop", "loops", "loop_while", "loop_for",
  "loop_for_command_list", "loop_for_command", "expression_list",
  "expression", "dimension_exp_list", "literal_id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    33,    35,
     124,    38,    60,    62,    43,    45,    42,    47,    37,    94,
      63,    58,   303,   304,   305,   306,   307,    59,    91,    93,
      40,    41,    44,   123,   125,    61
};
# endif

#define YYPACT_NINF -192

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-192)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      82,  -192,  -192,  -192,  -192,  -192,    87,     5,    82,  -192,
     -15,  -192,  -192,   -13,  -192,  -192,  -192,   -55,   -35,   -38,
     -28,  -192,    20,     0,   140,  -192,     4,   140,    12,  -192,
      87,    28,    11,    23,  -192,    29,    15,    55,  -192,    54,
     140,    54,  -192,  -192,   118,  -192,  -192,  -192,    32,    58,
     428,   428,   428,  -192,   114,    66,    71,    72,    74,    76,
     105,   -30,    83,  -192,    85,    80,   118,    87,    98,    99,
     100,   102,   104,   112,   113,  -192,   118,  -192,  -192,   428,
     428,  -192,  -192,  -192,  -192,  -192,  -192,   -51,   428,   428,
     428,   428,   428,   428,   428,   428,    83,  -192,  -192,   455,
    -192,  -192,   210,   455,  -192,    34,  -192,  -192,   428,  -192,
     118,   151,  -192,  -192,   428,   428,   428,   118,  -192,  -192,
     136,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   272,
     303,   455,   455,  -192,  -192,  -192,  -192,   -11,   334,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,  -192,  -192,  -192,  -192,   128,   119,
     365,   116,   117,  -192,  -192,   455,   455,   127,   241,  -192,
    -192,   151,  -192,   187,  -192,   176,   176,   292,   474,   465,
     260,   260,   221,   221,   -11,   -11,   -11,   -11,   396,  -192,
     210,   428,    34,    74,  -192,  -192,  -192,  -192,  -192,   428,
    -192,   190,  -192,  -192,   428,   406,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,   -11,    34,  -192,   130,   201,   180,  -192,
    -192,  -192,   137,  -192
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    13,    14,    16,    15,    17,     0,     0,     5,     7,
       0,     8,     2,     0,     2,     1,     6,    26,     0,    26,
       0,    10,     0,     0,    27,     9,     0,    27,     0,    12,
       0,     0,     0,    28,    11,     0,    23,     0,    31,     0,
      27,     0,    22,    30,     2,    25,    29,    24,     0,     0,
       0,     0,     0,    50,    49,     0,     0,     0,    20,     0,
       0,     0,    18,    19,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     2,    74,    73,     0,
       0,   113,   114,   118,   117,   115,   116,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   111,    61,
     107,    63,    62,    67,    48,     0,    46,    47,     0,    21,
       2,     4,    64,    65,     0,     0,    59,     2,     3,    34,
       0,    39,    44,    41,    42,    43,    40,    45,    36,     0,
       0,    88,    92,    89,    86,    87,    90,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    80,    82,    81,     0,    79,
       0,     0,     0,    51,    51,    60,    66,     0,    58,    35,
      32,     0,     2,     2,    85,   101,   102,   100,    99,    98,
     104,   103,    93,    94,    95,    96,    97,   105,     0,    83,
      84,     0,     0,   109,     3,    55,    54,    53,    56,    59,
      52,     4,     2,    76,     0,     0,    78,   108,    33,    57,
       2,    68,    75,   106,     0,    69,     0,     0,     0,    72,
      77,    71,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,    13,    16,    19,   204,  -192,  -192,   219,  -192,   -44,
     -42,   -16,  -192,   207,   -19,  -192,   181,  -126,   -48,  -153,
    -192,    57,   -96,    67,   -40,    38,   -95,  -192,  -192,  -192,
     -94,  -192,  -192,    21,  -192,  -192,  -192,  -191,  -192,    95,
     -36,    59,    88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    59,   170,   163,     7,     8,     9,    60,    61,    96,
      97,    23,    11,    12,    32,    33,    45,    64,    65,    66,
      67,   196,    68,   164,    98,   167,    70,    71,    72,   115,
      73,    74,    75,   220,    76,    77,    78,   158,   159,   101,
     168,   109,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   206,    63,    26,    69,    15,   112,   113,    35,   155,
     156,   157,    21,    22,    99,   102,   103,   108,   119,   -20,
      42,    46,    62,   216,    63,    18,    69,    20,   128,    25,
      22,    17,    62,    19,    63,    24,    69,     1,     2,     3,
       4,     5,    27,   129,   130,   114,   201,   203,   151,   152,
      53,    54,   131,   132,   133,   134,   135,   136,   137,   138,
      28,   154,   161,    63,   219,   219,    62,    29,    63,   169,
      69,    34,   160,    62,    38,    63,   212,    69,   165,   166,
      58,    36,    39,    22,   215,     1,     2,     3,     4,     5,
       1,     2,     3,     4,     5,    40,   155,   156,   157,     6,
      41,    43,    79,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   190,   155,   156,
     157,     1,     2,     3,     4,     5,    48,    44,    80,    49,
     104,    50,    51,    52,    53,    54,   105,    55,   106,   107,
      56,    57,   108,     1,     2,     3,     4,     5,   154,   110,
      63,   111,   117,   116,   118,   205,    30,    81,    82,    83,
      84,    85,    86,    87,    58,   121,   122,   123,   213,   124,
     154,   125,    63,    62,    62,    63,    63,    69,    69,   126,
     127,   162,   171,     1,     2,     3,     4,     5,    48,   191,
     194,   192,   -37,    50,    51,    52,    53,    54,   198,   202,
     210,   217,    56,    57,     1,     2,     3,     4,     5,    48,
     208,   223,    16,    14,    50,    51,    52,    53,    54,    10,
     211,   197,    47,    56,    57,    13,    58,    10,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   209,   200,   222,
     139,   140,   141,    31,   142,   143,    31,    58,   189,    37,
     195,     0,   207,   218,   221,     0,     0,     0,     0,    31,
       0,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   139,   140,   141,   218,   142,   143,   148,   149,   150,
     151,   152,   153,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   139,   140,   141,     0,   142,   143,     0,     0,
       0,     0,     0,   199,   146,   147,   148,   149,   150,   151,
     152,     0,   139,   140,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   139,   140,   141,     0,   142,   143,     0,
       0,     0,     0,   172,   144,   145,   146,   147,   148,   149,
     150,   151,   152,     0,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   139,   140,   141,     0,   142,   143,
       0,     0,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   139,   140,   141,     0,   142,
     143,     0,     0,     0,     0,   174,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   139,   140,   141,     0,
     142,   143,     0,     0,   193,     0,   139,   140,   141,     0,
     142,   143,     0,     0,     0,     0,     0,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   204,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   214,    81,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,    90,
       0,     0,    91,    92,    93,   139,   140,   141,    94,   142,
     143,     0,     0,     0,     0,   139,   140,   141,    95,   142,
       0,     0,     0,     0,   139,   140,   141,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   144,   145,   146,   147,
     148,   149,   150,   151,   152
};

static const yytype_int16 yycheck[] =
{
      44,   192,    44,    19,    44,     0,    36,    37,    27,   105,
     105,   105,    67,    68,    50,    51,    52,    68,    66,    70,
      36,    40,    66,   214,    66,    12,    66,    14,    76,    67,
      68,    46,    76,    46,    76,    70,    76,     3,     4,     5,
       6,     7,    70,    79,    80,    75,   172,   173,    59,    60,
      16,    17,    88,    89,    90,    91,    92,    93,    94,    95,
      40,   105,   110,   105,   217,   218,   110,    67,   110,   117,
     110,    67,   108,   117,    46,   117,   202,   117,   114,   115,
      46,    69,    71,    68,   210,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    72,   192,   192,   192,    17,
      71,    46,    70,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   214,   214,
     214,     3,     4,     5,     6,     7,     8,    73,    70,    11,
      16,    13,    14,    15,    16,    17,    70,    19,    67,    67,
      22,    23,    68,     3,     4,     5,     6,     7,   192,    73,
     192,    46,    67,    70,    74,   191,    16,    40,    41,    42,
      43,    44,    45,    46,    46,    67,    67,    67,   204,    67,
     214,    67,   214,   217,   218,   217,   218,   217,   218,    67,
      67,    30,    46,     3,     4,     5,     6,     7,     8,    61,
      74,    72,    74,    13,    14,    15,    16,    17,    71,    12,
      10,    71,    22,    23,     3,     4,     5,     6,     7,     8,
     194,    74,     8,     6,    13,    14,    15,    16,    17,     0,
     201,   164,    41,    22,    23,     6,    46,     8,    52,    53,
      54,    55,    56,    57,    58,    59,    60,   199,   171,   218,
      30,    31,    32,    24,    34,    35,    27,    46,   153,    30,
     162,    -1,   193,    73,    74,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    30,    31,    32,    73,    34,    35,    56,    57,    58,
      59,    60,    72,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    30,    31,    32,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    72,    54,    55,    56,    57,    58,    59,
      60,    -1,    30,    31,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    30,    31,    32,    -1,    34,    35,    -1,
      -1,    -1,    -1,    71,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    -1,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    30,    31,    32,    -1,    34,    35,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    30,    31,    32,    -1,    34,
      35,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    30,    31,    32,    -1,
      34,    35,    -1,    -1,    69,    -1,    30,    31,    32,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    -1,    51,
      -1,    -1,    54,    55,    56,    30,    31,    32,    60,    34,
      35,    -1,    -1,    -1,    -1,    30,    31,    32,    70,    34,
      -1,    -1,    -1,    -1,    30,    31,    32,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    52,    53,    54,    55,
      56,    57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    80,    81,    82,
      83,    88,    89,    83,    89,     0,    80,    46,    77,    46,
      77,    67,    68,    87,    70,    67,    87,    70,    40,    67,
      16,    83,    90,    91,    67,    90,    69,    83,    46,    71,
      72,    71,    87,    46,    73,    92,    90,    92,     8,    11,
      13,    14,    15,    16,    17,    19,    22,    23,    46,    77,
      83,    84,    85,    86,    93,    94,    95,    96,    98,   100,
     102,   103,   104,   106,   107,   108,   110,   111,   112,    70,
      70,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      51,    54,    55,    56,    60,    70,    85,    86,   100,   116,
     118,   115,   116,   116,    16,    70,    67,    67,    68,   117,
      73,    46,    36,    37,    75,   105,    70,    67,    74,    94,
      83,    67,    67,    67,    67,    67,    67,    67,    94,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,    30,
      31,    32,    34,    35,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    72,    85,    98,   102,   106,   113,   114,
     116,    94,    30,    79,    99,   116,   116,   101,   116,    94,
      78,    46,    71,    71,    71,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   115,
     116,    61,    72,    69,    74,   118,    97,    97,    71,    72,
      99,    93,    12,    93,    61,   116,   113,   117,    78,   101,
      10,    79,    93,   116,    61,    93,   113,    71,    73,    95,
     109,    74,   109,    74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    79,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    84,    84,
      85,    86,    87,    87,    88,    88,    89,    90,    90,    90,
      91,    91,    92,    93,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    97,    98,    98,    98,    99,   100,   101,   101,   101,
     102,   103,   104,   104,   105,   105,   106,   107,   108,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     118,   118,   118,   118,   118,   118,   118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     2,     1,     1,     4,
       3,     5,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     7,     6,     2,     0,     1,     3,
       3,     2,     4,     5,     2,     3,     2,     0,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     0,     4,     4,     4,     2,     4,     3,     1,     0,
       3,     2,     2,     2,     1,     1,     3,     2,     6,     7,
       3,     2,     1,     1,     1,     6,     5,     9,     3,     1,
       1,     1,     1,     3,     3,     3,     2,     2,     2,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 139 "parser.y" /* yacc.c:1646  */
    {
//printf("\nnew scope\n");
create_new_scope();


}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 148 "parser.y" /* yacc.c:1646  */
    {
//printf("\nexiting scope\n");  
exit_scope();}
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) =  new_global_grammar_node('|',arvore,(yyvsp[-1].ast_node),(yyvsp[0].ast_node));




	char *code1,*code2;
	if((yyvsp[-1].ast_node) == NULL) code1 = NULL;
	else code1 = (yyvsp[-1].ast_node)->code;


	if((yyvsp[0].ast_node) == NULL) code2 = NULL;
	else code2 = (yyvsp[0].ast_node)->code;

	(yyval.ast_node)->code = concatCode(code1,code2);

}
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 180 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_static_global_var_declaration_node('g',(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),NULL);}
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonstatic_global_var_declaration_node('g',(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),NULL);}
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_static_global_var_declaration_node('g',(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].dimensions));}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 184 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonstatic_global_var_declaration_node('g',(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].dimensions));}
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_INT; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_FLOAT; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_CHAR; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 192 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_BOOL; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 193 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_STRING; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node(ID_NODE,(yyvsp[0].valor_lexico));}
#line 1759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 199 "parser.y" /* yacc.c:1646  */
    {

(yyval.ast_node) = new_leaf_node(ID_NODE,(yyvsp[-1].valor_lexico));

SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-1].valor_lexico));

(yyval.ast_node)->ast_valor_lexico.nature = id_info.nature;

if(id_info.nature == FUNCTION){
    printf("Semantical error line %d, column %d : ERR_FUNCTION\n",(yyvsp[-1].valor_lexico).line,(yyvsp[-1].valor_lexico).column);
    exit(ERR_FUNCTION);
}

ast_node* node = (yyvsp[0].ast_node);
ARRAY_DIMENSIONS *d = id_info.vector_dimension;

(yyval.ast_node)->temp = newTemp();

int first_dimension_flag = 1;

while(node){
//previous_size = previous_size * vector_dimension->dsize + indexes->dsize;
    
    if(first_dimension_flag) {
        (yyval.ast_node)->code = concatCode((yyval.ast_node)->code,copyRegToReg(node->temp,(yyval.ast_node)->temp));
//         printf("%s =  %s\n",$$->temp,node->temp);
    }
    
    else{
        (yyval.ast_node)->code = concatCode((yyval.ast_node)->code,binaryOperationInteger("multI",(yyval.ast_node)->temp, d->dsize,(yyval.ast_node)->temp));
        (yyval.ast_node)->code = concatCode((yyval.ast_node)->code,binaryOperation("add",(yyval.ast_node)->temp, node->temp,(yyval.ast_node)->temp));
//         printf("%s = %s * %d\t",$$->temp,$$->temp,d->dsize);
//         printf("%s = %s + %s\n",$$->temp,$$->temp,node->temp);
    }
    
    first_dimension_flag = 0;
    
    //printf("exp %s || %d\n", node->temp,d->dsize);
    node = node->next_sibling;
    d = d->next;
}
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,binaryOperationInteger("multI",(yyval.ast_node)->temp, get_size2(id_info),(yyval.ast_node)->temp));
(yyval.ast_node)->code = concatCode((yyvsp[0].ast_node)->code,(yyval.ast_node)->code);

//printf("array calc:\n%s",$$->code);







(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,storeVariableRegOffsetToTemp((yyval.ast_node)->temp,(yyval.ast_node)->temp, id_info.depth));



}
#line 1821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 257 "parser.y" /* yacc.c:1646  */
    {
(yyval.dimensions) = malloc(sizeof(ARRAY_DIMENSIONS));
(yyval.dimensions)->dsize = (yyvsp[-2].valor_lexico).value.intvalue;
(yyval.dimensions)->next = (yyvsp[0].dimensions);

}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 263 "parser.y" /* yacc.c:1646  */
    {
(yyval.dimensions) = malloc(sizeof(ARRAY_DIMENSIONS));
(yyval.dimensions)->dsize = (yyvsp[-1].valor_lexico).value.intvalue;
(yyval.dimensions)->next = NULL;

}
#line 1843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 274 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_static_function_declaration_node('M',(yyvsp[-5].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
char *l0 = malloc(10);
strcpy(l0,"L0: ");

(yyval.ast_node)->label = l0;
char *first_inst = malloc(50);
strncpy(first_inst, "addI rsp, 4 => rsp\n",50);
(yyval.ast_node)->label = concatCode((yyval.ast_node)->label, first_inst );
(yyval.ast_node)->code = concatCode((yyval.ast_node)->label,(yyvsp[0].ast_node)->code);



}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 288 "parser.y" /* yacc.c:1646  */
    {
//insert_function_entry($<valor_lexico>2);
(yyval.ast_node) = new_nonstatic_function_declaration_node('M',(yyvsp[-5].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));

if((yyval.ast_node) != NULL && (yyvsp[0].ast_node) != NULL ){
    
    char *l0 = newLabel();

    (yyval.ast_node)->label = l0;

    char *first_inst = malloc(50);
    strncpy(first_inst, " : addI rsp, 4 => rsp\n",50);
    (yyval.ast_node)->label = concatCode((yyval.ast_node)->label, first_inst );
    
    (yyval.ast_node)->code = concatCode((yyval.ast_node)->label,(yyvsp[0].ast_node)->code);
}
//printf("function\n%s",$$->code);
}
#line 1885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 308 "parser.y" /* yacc.c:1646  */
    {

(yyvsp[0].valor_lexico).var_type = (yyvsp[-1].valor_lexico).var_type;
(yyvsp[0].valor_lexico).nature = FUNCTION;
insert_function_entry((yyvsp[0].valor_lexico));
(yyval.valor_lexico) = (yyvsp[0].valor_lexico);

free((yyvsp[-1].valor_lexico).value.str_value);

}
#line 1900 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 323 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_parameter_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_const_parameter_node('p',(yyvsp[-1].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 325 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonconst_parameter_node('p',(yyvsp[-1].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 330 "parser.y" /* yacc.c:1646  */
    { 
(yyval.ast_node) = new_command_block_node('{',(yyvsp[-2].ast_node));

if((yyvsp[-2].ast_node) != NULL) (yyval.ast_node)->code = concatCode((yyvsp[-2].ast_node)->code, (yyval.ast_node)->code);
else if((yyval.ast_node) != NULL) (yyval.ast_node)->code = NULL;


}
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 341 "parser.y" /* yacc.c:1646  */
    { 
(yyval.ast_node) = new_command_block_node('{',(yyvsp[-2].ast_node));
(yyval.ast_node)->code = concatCode((yyvsp[-2].ast_node)->code, (yyval.ast_node)->code);
}
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 347 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));
char *code1,*code2;
if((yyvsp[-1].ast_node) == NULL) code1 = NULL;
else code1 = (yyvsp[-1].ast_node)->code;


if((yyvsp[0].ast_node) == NULL) code2 = NULL;
else code2 = (yyvsp[0].ast_node)->code;


(yyval.ast_node)->code = concatCode(code1, code2);


}
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 362 "parser.y" /* yacc.c:1646  */
    {
new_command_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));
(yyval.ast_node)->code = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
}
#line 1975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 366 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));

char *code1 = NULL;
char *code2 = NULL;

if((yyvsp[-1].ast_node)) code1 = (yyvsp[-1].ast_node)->code;
if((yyvsp[0].ast_node)) code2 = (yyvsp[0].ast_node)->code;

(yyval.ast_node)->code = concatCode(code1, code2);

}
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 381 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('b',(yyvsp[-1].valor_lexico));}
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 385 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('.',(yyvsp[-1].valor_lexico));}
#line 2040 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 390 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(1,1);}
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(1,0);}
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(0,1);}
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 394 "parser.y" /* yacc.c:1646  */
    {(yyval.var_modifier) = modifier(0,0);}
#line 2064 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 398 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ast_node) = new_local_var_declaration_node('<',(yyvsp[-3].var_modifier),(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node) ) ;

    if((yyvsp[0].ast_node)->ast_valor_lexico.nature == LITERAL){
        SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-1].valor_lexico));

        (yyval.ast_node)->code = storeTempToVariable((yyvsp[0].ast_node)->temp, id_info.depth, id_info.position);
        (yyval.ast_node)->code = concatCode((yyvsp[0].ast_node)->code, (yyval.ast_node)->code);

        //printf("local decl code : %s",$$->code);
    }

}
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 412 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node) ) ;


    if((yyvsp[-1].ast_node)->ast_valor_lexico.nature == LITERAL){
        SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-2].valor_lexico));

        (yyval.ast_node)->code = storeTempToVariable((yyvsp[-1].ast_node)->temp, id_info.depth, id_info.position);
        (yyval.ast_node)->code = concatCode((yyvsp[-1].ast_node)->code, (yyval.ast_node)->code);
    }

}
#line 2099 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 424 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node)) ;
}
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 428 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 433 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_function_call_node(FUNCTION_CALL_NODE,(yyvsp[-3].ast_node),(yyvsp[-1].ast_node));}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 435 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 437 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 441 "parser.y" /* yacc.c:1646  */
    { 
//printf("assign %p , %p\n",$1,$3);
(yyval.ast_node) = new_assignment_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node),0);

//printf("assign %p , %p\n",$1,$3);
SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-2].valor_lexico));

if(id_info.nature == VECTOR){
    (yyval.ast_node)->code = concatCode((yyvsp[-2].ast_node)->code, storeTempToVariableRegOffset((yyvsp[0].ast_node)->temp,(yyvsp[-2].ast_node)->temp,id_info.depth));
}

else {
    if((yyvsp[0].ast_node)->ast_valor_lexico.nature == VECTOR) (yyval.ast_node)->code = concatCode(loadMemRegToReg((yyvsp[0].ast_node)->temp,(yyvsp[0].ast_node)->temp),storeTempToVariable((yyvsp[0].ast_node)->temp, id_info.depth, id_info.position));
    
    else (yyval.ast_node)->code = concatCode((yyval.ast_node)->code,storeTempToVariable((yyvsp[0].ast_node)->temp, id_info.depth, id_info.position));

// $$->code = concatCode( storeTempToVariable($3->temp, id_info.depth, id_info.position);
}


(yyval.ast_node)->code = concatCode((yyvsp[0].ast_node)->code,(yyval.ast_node)->code);




}
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 469 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(INPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 471 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(OUTPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 472 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(OUTPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 478 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_leaf_node('L',(yyvsp[0].valor_lexico));}
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 479 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_leaf_node('R',(yyvsp[0].valor_lexico));}
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 481 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_shift_command_node('X',(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_return_command_node('R',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 487 "parser.y" /* yacc.c:1646  */
    {

(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-3].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));
(yyval.ast_node)->code = (yyvsp[-3].ast_node)->code;

char *true_block_label = (yyvsp[-3].ast_node)->true->remendo;
char *false_block_label = (yyvsp[-3].ast_node)->false->remendo;

(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,true_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[-1].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,false_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));

if(DEBUG) fprintf( stderr,"%p // %p\n",(yyvsp[-3].ast_node)->true, (yyvsp[-3].ast_node)->false);


LISTA_REMENDOS *lr_tempt = (yyvsp[-3].ast_node)->true;
LISTA_REMENDOS *lr_tempf = (yyvsp[-3].ast_node)->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",(yyvsp[-3].ast_node)->true, (yyvsp[-3].ast_node)->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}

if(DEBUG) fprintf( stderr, "if code\n%s\n",(yyval.ast_node)->code);


}
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 526 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
(yyval.ast_node)->code = concatCode((yyvsp[-4].ast_node)->code,(yyvsp[-2].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[0].ast_node)->code);

char *true_block_label = (yyvsp[-4].ast_node)->true->remendo;
char *false_block_label = (yyvsp[-4].ast_node)->false->remendo;

(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,true_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[-2].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,false_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[0].ast_node)->code);


LISTA_REMENDOS *lr_tempt = (yyvsp[-4].ast_node)->true;
LISTA_REMENDOS *lr_tempf = (yyvsp[-4].ast_node)->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",(yyvsp[-4].ast_node)->true, (yyvsp[-4].ast_node)->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}

if(DEBUG) fprintf( stderr, "if code\n%s\n",(yyval.ast_node)->code);



}
#line 2292 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2298 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 568 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 574 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_loop_while_node('w',(yyvsp[-3].ast_node),(yyvsp[0].ast_node));
char *true_block_label = (yyvsp[-3].ast_node)->true->remendo;
char *false_block_label = (yyvsp[-3].ast_node)->false->remendo;
char *loop_start = newLabel();
char *loop_start1 = strdup(loop_start);



(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,loop_start);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[-3].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,true_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[0].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup("jumpI -> "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,loop_start1);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup("\n"));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,false_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));

LISTA_REMENDOS *lr_tempt = (yyvsp[-3].ast_node)->true;
LISTA_REMENDOS *lr_tempf = (yyvsp[-3].ast_node)->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",(yyvsp[-3].ast_node)->true, (yyvsp[-3].ast_node)->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}


}
#line 2350 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 615 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_loop_while_node('w',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
char *true_block_label = (yyvsp[-2].ast_node)->true->remendo;
char *false_block_label = (yyvsp[-2].ast_node)->false->remendo;
char *loop_start = newLabel();
char *loop_start1 = strdup(loop_start);



(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,loop_start);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[-2].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,true_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,(yyvsp[0].ast_node)->code);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup("jumpI -> "));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,loop_start1);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup("\n"));
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,false_block_label);
(yyval.ast_node)->code = concatCode((yyval.ast_node)->code,strdup(": "));

LISTA_REMENDOS *lr_tempt = (yyvsp[-2].ast_node)->true;
LISTA_REMENDOS *lr_tempf = (yyvsp[-2].ast_node)->false;
if(DEBUG) fprintf( stderr,"%p // %p\n",(yyvsp[-2].ast_node)->true, (yyvsp[-2].ast_node)->false);

while(lr_tempt){
if(DEBUG) fprintf( stderr, "label true exp %s\n",lr_tempt->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempt->remendo, true_block_label);
lr_tempt = lr_tempt->next;

}

while(lr_tempf){
if(DEBUG) fprintf( stderr, "label false exp %s\n",lr_tempf->remendo);
(yyval.ast_node)->code = strrep((yyval.ast_node)->code, lr_tempf->remendo, false_block_label);
lr_tempf = lr_tempf->next;

}


}
#line 2396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 656 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_loop_for_node('j',(yyvsp[-6].ast_node),(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 659 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_command_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 674 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 675 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 679 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 681 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 682 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('-',(yyvsp[0].ast_node));}
#line 2438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 683 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('!',(yyvsp[0].ast_node)); }
#line 2444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 684 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('@',(yyvsp[0].ast_node)); }
#line 2450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 685 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('$',(yyvsp[0].ast_node)); }
#line 2456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 686 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('~',(yyvsp[0].ast_node)); }
#line 2462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 687 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('#',(yyvsp[0].ast_node)); }
#line 2468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 696 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('+',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("add", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);
	
	//printf("Add code:\t: %s\n",$$->code);
	
}
#line 2483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 708 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('-',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); 
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("sub", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	//printf("sub code:\t: %s\n",$$->code);
}
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 718 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('*',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("mult", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	//printf("mul code:\t: %s\n",$$->code);
}
#line 2511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 728 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('/',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); 
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("div", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	//printf("div code:\t: %s\n",$$->code);
}
#line 2525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 737 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_binary_expression('%',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 751 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('|',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	

	(yyval.ast_node)->temp = newTemp();
	
	
	char *cc_label = (yyvsp[-2].ast_node)->false->remendo;
	char *old_label = (yyvsp[-2].ast_node)->false->remendo;
	
	(yyval.ast_node)->false = (yyvsp[0].ast_node)->false;
	(yyval.ast_node)->true = concatRemendo((yyvsp[-2].ast_node)->true, (yyvsp[0].ast_node)->true);
	//$1->false = replaceRemendo($1->false, cc_label);
	
// 	fprintf( stderr, "orleft %s\n",$1->true->remendo);
	if(DEBUG) fprintf( stderr, "orleft %s \t%s\n",(yyvsp[-2].ast_node)->false->remendo,cc_label);
// 	fprintf( stderr, "orright %s\n",$3->true->remendo);
// 	fprintf( stderr, "orright %s\n",$3->false->remendo);

    (yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[-2].ast_node)->code);
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, cc_label);
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, strdup(": "));
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[0].ast_node)->code);
	//$$->code = replace_str(old_label,$$->code, cc_label);
	if(DEBUG) fprintf( stderr, "%s\n\n\n",(yyval.ast_node)->code);
}
#line 2562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 779 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('&',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	
	(yyval.ast_node)->temp = newTemp();
	char *cc_label = (yyvsp[-2].ast_node)->true->remendo;
	(yyval.ast_node)->true = (yyvsp[0].ast_node)->true;
	(yyval.ast_node)->false = concatRemendo((yyvsp[-2].ast_node)->false, (yyvsp[0].ast_node)->false);
	
	    (yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[-2].ast_node)->code);
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, cc_label);
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, strdup(": "));
	(yyval.ast_node)->code = concatCode((yyval.ast_node)->code, (yyvsp[0].ast_node)->code);
	
	if(DEBUG) fprintf( stderr, "%s\n\n\n",(yyval.ast_node)->code);

}
#line 2583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 805 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression(TK_OC_EQ,(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node) = GenerateCompOPCode((yyval.ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node), strdup("cmp_NE"));
    

}
#line 2594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 812 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression(TK_OC_LE,(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node) = GenerateCompOPCode((yyval.ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node), strdup("cmp_LE"));
}
#line 2603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 818 "parser.y" /* yacc.c:1646  */
    {
	
	(yyval.ast_node) = new_binary_expression(TK_OC_GE,(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node) = GenerateCompOPCode((yyval.ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node), strdup("cmp_GE"));
}
#line 2613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 828 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('>',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node) = GenerateCompOPCode((yyval.ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node), strdup("cmp_GT"));
}
#line 2622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 834 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('<',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node) = GenerateCompOPCode((yyval.ast_node), (yyvsp[-2].ast_node), (yyvsp[0].ast_node), strdup("cmp_LT"));
}
#line 2631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 850 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_binary_expression('^',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2637 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 856 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) =  new_ternary_expression('?', (yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 857 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2649 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 867 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->code = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
}
#line 2658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 871 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 888 "parser.y" /* yacc.c:1646  */
    { 

	(yyval.ast_node) = new_leaf_node(ID_NODE,(yyvsp[0].valor_lexico));
	SYMBOL_INFO id_info = retrieve_symbol((yyvsp[0].valor_lexico));
	(yyval.ast_node)->ast_valor_lexico.nature = id_info.nature;


	if(id_info.nature == FUNCTION)
	{
	    printf("Semantical error line %d, column %d : ERR_FUNCTION\n",(yyvsp[0].valor_lexico).line,(yyvsp[0].valor_lexico).column);
	    exit(ERR_FUNCTION);
	}

	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = storeVariableToTemp((yyval.ast_node)->temp, id_info.depth, id_info.position);

	//printf("code id: %s\n",$$->code);

}
#line 2688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 908 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = (yyvsp[0].ast_node);
}
#line 2696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 913 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = (yyvsp[0].ast_node);
}
#line 2704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 920 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_INT;
	(yyval.ast_node) = new_leaf_node('d',(yyvsp[0].valor_lexico));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = loadValueToTemp((yyvsp[0].valor_lexico).value.intvalue, (yyval.ast_node)->temp);

	//printf("code %s\n",$$->code);

}
#line 2718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 929 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_FLOAT;
	(yyval.ast_node) = new_leaf_node('f',(yyvsp[0].valor_lexico));
}
#line 2727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 933 "parser.y" /* yacc.c:1646  */
    { 

(yyvsp[0].valor_lexico).var_type = TYPE_CHAR;
	(yyval.ast_node) = new_leaf_node('c',(yyvsp[0].valor_lexico));
}
#line 2737 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 938 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_STRING;
	(yyval.ast_node) = new_leaf_node('s',(yyvsp[0].valor_lexico));
}
#line 2746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 942 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.ast_node) = new_leaf_node('T',(yyvsp[0].valor_lexico));
}
#line 2754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 945 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.ast_node) = new_leaf_node('F',(yyvsp[0].valor_lexico));
}
#line 2762 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2766 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 953 "parser.y" /* yacc.c:1906  */

