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




#line 235 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       2,     2,     2,    48,     2,    49,     2,    56,    51,     2,
      68,    69,    54,    52,    70,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    65,
       2,    73,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    50,    72,     2,     2,     2,     2,
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
      45,    46,    47,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   156,   160,   163,   164,   168,   168,   171,
     172,   174,   175,   180,   181,   182,   183,   184,   186,   187,
     189,   190,   197,   205,   219,   224,   230,   242,   244,   245,
     246,   247,   252,   256,   259,   260,   261,   262,   265,   265,
     265,   265,   265,   265,   265,   266,   268,   269,   274,   275,
     276,   278,   282,   297,   313,   317,   322,   324,   325,   326,
     330,   351,   353,   354,   360,   361,   363,   366,   369,   370,
     373,   374,   375,   377,   377,   378,   379,   382,   383,   385,
     385,   385,   397,   398,   402,   404,   405,   406,   407,   408,
     409,   410,   418,   436,   450,   462,   474,   475,   486,   496,
     498,   500,   503,   520,   522,   532,   537,   542,   547,   548
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
  "TK_IDENTIFICADOR", "TOKEN_ERRO", "'!'", "'#'", "'|'", "'&'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "'?'", "':'", "UNARY_QUESTION_MARK",
  "UNARY_PLUS", "UNARY_MINUS", "UNARY_ET", "UNARY_POINTER", "';'", "'['",
  "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "$accept",
  "enter_scope", "exit_scope", "null_node", "program", "grammars",
  "global_var_declaration", "primitive_type", "identifier",
  "simple_identifier", "vector", "vector_dimensions",
  "function_declaration", "function_id", "function_parameters_list",
  "function_parameters_argument", "function_command_block",
  "command_block", "command_list", "command", "modifiers", "no_modifier",
  "local_var_declaration", "local_var_initialization", "function_call",
  "call_parameter_list", "assignment_command", "input_command",
  "output_command", "shift", "shift_command", "command_return",
  "if_statement", "command_block_loop", "loops", "loop_while", "loop_for",
  "loop_for_command_list", "loop_for_command", "expression_list",
  "expression", "literal_id", YY_NULLPTR
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
     124,    38,    43,    45,    42,    47,    37,    94,    63,    58,
     303,   304,   305,   306,   307,    59,    91,    93,    40,    41,
      44,   123,   125,    61
};
# endif

#define YYPACT_NINF -185

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-185)))

#define YYTABLE_NINF -38

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,  -185,  -185,  -185,  -185,  -185,    83,     2,   120,  -185,
     -35,  -185,  -185,    23,  -185,  -185,  -185,    -4,   -10,     8,
      -2,  -185,    35,    15,   135,  -185,    16,   135,    36,  -185,
      83,    56,    13,    21,  -185,    48,    38,    72,  -185,    49,
     135,    49,  -185,  -185,   160,  -185,  -185,  -185,    51,    61,
     193,   193,   193,  -185,   114,    63,    67,    69,    38,    65,
      97,   -20,    79,  -185,    84,    76,   160,    83,    85,    93,
      94,    95,   104,   105,   107,  -185,   160,  -185,  -185,   193,
     193,  -185,  -185,  -185,  -185,  -185,  -185,   110,   193,   193,
     193,   193,   193,   193,   193,   193,    79,  -185,   292,  -185,
    -185,    58,   292,  -185,    24,  -185,  -185,  -185,   160,   150,
    -185,  -185,   193,   193,   193,   160,  -185,  -185,   144,  -185,
    -185,  -185,  -185,  -185,  -185,  -185,  -185,   233,   242,   292,
     292,  -185,  -185,  -185,  -185,    20,   262,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,  -185,  -185,  -185,
    -185,   122,   121,   127,   263,  -185,  -185,   292,   292,   123,
     212,  -185,  -185,   150,  -185,   208,  -185,   220,   299,    98,
      98,    20,    20,    20,    20,   271,  -185,    58,   193,    24,
    -185,  -185,  -185,  -185,  -185,   193,  -185,   183,   181,  -185,
    -185,   193,   282,  -185,  -185,  -185,  -185,  -185,  -185,   128,
      20,    24,  -185,  -185,   132,   208,  -185
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
       0,   104,   105,   109,   108,   106,   107,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,    61,   101,
      63,    62,    67,    48,     0,    46,    47,    21,     2,     4,
      64,    65,     0,     0,    59,     2,     3,    34,     0,    39,
      44,    41,    42,    43,    40,    45,    36,     0,     0,    87,
      91,    88,    85,    86,    89,    90,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,    79,    81,
      80,     0,    78,     0,     0,    51,    51,    60,    66,     0,
      58,    35,    32,     0,     2,     0,    84,    97,    98,    92,
      93,    94,    95,    96,    99,     0,    82,    83,     0,     0,
       3,    55,    54,    53,    56,    59,    52,     4,     0,    72,
      75,     0,     0,    77,    33,    57,     2,    68,    71,     0,
     100,     0,    69,    70,     0,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -185,    45,    22,    30,   197,  -185,  -185,    12,  -185,   -44,
    -185,    18,  -185,   201,   -14,  -185,   167,  -145,   -52,  -150,
    -185,    53,   -96,    47,   -43,    33,   -95,  -185,  -185,  -185,
     -94,  -185,  -185,  -184,  -185,  -185,  -185,  -176,  -185,    73,
     -45,    66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    59,   162,   155,     7,     8,     9,    60,    61,    96,
      63,    23,    11,    12,    32,    33,    45,    64,    65,    66,
      67,   182,    68,   156,    97,   159,    70,    71,    72,   113,
      73,    74,    75,   190,    76,    77,    78,   151,   152,   100,
     160,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    69,    15,   193,   199,    98,   101,   102,   148,   149,
     150,    17,    10,    35,   117,   189,   110,   111,    13,   187,
      10,   206,    62,    69,   126,   204,    46,     1,     2,     3,
       4,     5,    62,    69,   127,   128,    31,    26,   189,    31,
      53,    54,    37,   129,   130,   131,   132,   133,   134,   135,
     136,   202,    31,   112,    42,   189,   153,    18,    24,    20,
     147,    21,    22,   161,    62,    69,    27,   157,   158,    19,
      58,    62,    69,    25,    22,    28,   107,   144,   145,   118,
      29,    34,    39,   148,   149,   150,     1,     2,     3,     4,
       5,    40,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   177,    38,    36,    22,   148,   149,   150,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    41,    43,    79,
      44,    62,    69,     1,     2,     3,     4,     5,   146,    80,
     103,   104,   105,   192,   106,   147,   108,     6,     1,     2,
       3,     4,     5,   109,    62,    69,   200,   114,   116,   115,
     119,    30,   141,   142,   143,   144,   145,   147,   120,   121,
     122,    62,    69,     1,     2,     3,     4,     5,    48,   123,
     124,    49,   125,    50,    51,    52,    53,    54,   -20,    55,
     154,   178,    56,    57,     1,     2,     3,     4,     5,    48,
     163,   179,   184,   196,    50,    51,    52,    53,    54,   180,
     203,   205,   194,    56,    57,    16,    58,    14,    47,   183,
     186,     1,     2,     3,     4,     5,    48,   197,   195,   176,
     181,    50,    51,    52,    53,    54,     0,    58,     0,     0,
      56,    57,   -37,    81,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,    90,    91,    92,    93,     0,     0,
       0,    94,   188,   198,    58,     0,     0,     0,     0,     0,
       0,    95,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   138,   139,   140,   141,   142,   143,   144,   145,   188,
       0,     0,   185,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,   164,    81,    82,    83,    84,    85,    86,    87,
       0,   165,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     191,   166,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   201,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   139,   140,   141,   142,   143,   144,   145
};

static const yytype_int16 yycheck[] =
{
      44,    44,     0,   179,   188,    50,    51,    52,   104,   104,
     104,    46,     0,    27,    66,   165,    36,    37,     6,   164,
       8,   205,    66,    66,    76,   201,    40,     3,     4,     5,
       6,     7,    76,    76,    79,    80,    24,    19,   188,    27,
      16,    17,    30,    88,    89,    90,    91,    92,    93,    94,
      95,   196,    40,    73,    36,   205,   108,    12,    68,    14,
     104,    65,    66,   115,   108,   108,    68,   112,   113,    46,
      46,   115,   115,    65,    66,    40,    58,    57,    58,    67,
      65,    65,    69,   179,   179,   179,     3,     4,     5,     6,
       7,    70,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,    46,    67,    66,   201,   201,   201,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    69,    46,    68,
      71,   165,   165,     3,     4,     5,     6,     7,    70,    68,
      16,    68,    65,   178,    65,   179,    71,    17,     3,     4,
       5,     6,     7,    46,   188,   188,   191,    68,    72,    65,
      65,    16,    54,    55,    56,    57,    58,   201,    65,    65,
      65,   205,   205,     3,     4,     5,     6,     7,     8,    65,
      65,    11,    65,    13,    14,    15,    16,    17,    68,    19,
      30,    59,    22,    23,     3,     4,     5,     6,     7,     8,
      46,    70,    69,    10,    13,    14,    15,    16,    17,    72,
      72,    69,   180,    22,    23,     8,    46,     6,    41,   156,
     163,     3,     4,     5,     6,     7,     8,   187,   185,   146,
     154,    13,    14,    15,    16,    17,    -1,    46,    -1,    -1,
      22,    23,    72,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    58,    71,    72,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    51,    52,    53,    54,    55,    56,    57,    58,    71,
      -1,    -1,    70,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    -1,    69,    40,    41,    42,    43,    44,    45,    46,
      -1,    69,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    69,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    78,    79,    80,
      81,    86,    87,    81,    87,     0,    78,    46,    75,    46,
      75,    65,    66,    85,    68,    65,    85,    68,    40,    65,
      16,    81,    88,    89,    65,    88,    67,    81,    46,    69,
      70,    69,    85,    46,    71,    90,    88,    90,     8,    11,
      13,    14,    15,    16,    17,    19,    22,    23,    46,    75,
      81,    82,    83,    84,    91,    92,    93,    94,    96,    98,
     100,   101,   102,   104,   105,   106,   108,   109,   110,    68,
      68,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      51,    52,    53,    54,    58,    68,    83,    98,   114,   115,
     113,   114,   114,    16,    68,    65,    65,    85,    71,    46,
      36,    37,    73,   103,    68,    65,    72,    92,    81,    65,
      65,    65,    65,    65,    65,    65,    92,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    70,    83,    96,   100,
     104,   111,   112,    92,    30,    77,    97,   114,   114,    99,
     114,    92,    76,    46,    69,    69,    69,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   113,   114,    59,    70,
      72,   115,    95,    95,    69,    70,    97,    91,    71,    93,
     107,    59,   114,   111,    76,    99,    10,    77,    72,   107,
     114,    59,    91,    72,   111,    69,   107
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    77,    78,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    82,    82,
      83,    84,    85,    85,    86,    86,    87,    88,    88,    88,
      89,    89,    90,    91,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    96,    96,    96,    97,    98,    99,    99,    99,
     100,   101,   102,   102,   103,   103,   104,   105,   106,   106,
     107,   107,   107,   108,   108,   109,   110,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115
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
       3,     2,     1,     1,     1,     5,     9,     3,     1,     1,
       1,     1,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 147 "parser.y" /* yacc.c:1646  */
    {
//printf("\nnew scope\n");
create_new_scope();


}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 156 "parser.y" /* yacc.c:1646  */
    {
//printf("\nexiting scope\n");  
exit_scope();}
#line 1612 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1624 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 164 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) =  new_global_grammar_node('|',arvore,(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_static_global_var_declaration_node('g',(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),NULL);}
#line 1636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonstatic_global_var_declaration_node('g',(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),NULL);}
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_static_global_var_declaration_node('g',(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].dimensions));}
#line 1648 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonstatic_global_var_declaration_node('g',(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].dimensions));}
#line 1654 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_INT; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_FLOAT; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_CHAR; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_BOOL; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1678 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0].valor_lexico).var_type = TYPE_STRING; (yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1690 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 187 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1696 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node(ID_NODE,(yyvsp[0].valor_lexico));}
#line 1702 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "parser.y" /* yacc.c:1646  */
    {   
	printf("vector\n"); 
	(yyval.ast_node) = new_leaf_node(VECTOR_NODE,(yyvsp[-1].valor_lexico));
	(yyval.ast_node)->vector_position = (yyvsp[0].dimensions); printf("p:%p\n",(yyvsp[0].dimensions));
}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 197 "parser.y" /* yacc.c:1646  */
    {
	printf("vector %d\n", (yyvsp[-2].valor_lexico).value.intvalue);
	(yyval.dimensions) = malloc(sizeof(ARRAY_DIMENSIONS));
	(yyval.dimensions)->dsize = (yyvsp[-2].valor_lexico).value.intvalue;
	(yyval.dimensions)->next = (yyvsp[0].dimensions);
	printf("p:%p -> %p\n",(yyval.dimensions),(yyval.dimensions)->next);

}
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "parser.y" /* yacc.c:1646  */
    {
	printf("vector %d\n", (yyvsp[-1].valor_lexico).value.intvalue);
	(yyval.dimensions) = malloc(sizeof(ARRAY_DIMENSIONS));
	(yyval.dimensions)->dsize = (yyvsp[-1].valor_lexico).value.intvalue;
	(yyval.dimensions)->next = NULL;

	printf("p:%p\n",(yyval.dimensions));

}
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 220 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_static_function_declaration_node('M',(yyvsp[-5].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));

}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 224 "parser.y" /* yacc.c:1646  */
    {
//insert_function_entry($<valor_lexico>2);
(yyval.ast_node) = new_nonstatic_function_declaration_node('M',(yyvsp[-5].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
}
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 230 "parser.y" /* yacc.c:1646  */
    {

(yyvsp[0].valor_lexico).var_type = (yyvsp[-1].valor_lexico).var_type;
(yyvsp[0].valor_lexico).nature = FUNCTION;
insert_function_entry((yyvsp[0].valor_lexico));
(yyval.valor_lexico) = (yyvsp[0].valor_lexico);

free((yyvsp[-1].valor_lexico).value.str_value);

}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_parameter_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_const_parameter_node('p',(yyvsp[-1].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_nonconst_parameter_node('p',(yyvsp[-1].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 252 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_command_block_node('{',(yyvsp[-2].ast_node));}
#line 1802 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 256 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_command_block_node('{',(yyvsp[-2].ast_node));}
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1814 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 260 "parser.y" /* yacc.c:1646  */
    {new_command_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1820 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 261 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1832 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1856 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 266 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('b',(yyvsp[-1].valor_lexico));}
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('.',(yyvsp[-1].valor_lexico));}
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(1,1);}
#line 1880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(1,0);}
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.var_modifier) = modifier(0,1);}
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.var_modifier) = modifier(0,0);}
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 282 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_local_var_declaration_node('<',(yyvsp[-3].var_modifier),(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node) ) ;

	if((yyvsp[0].ast_node)->ast_valor_lexico.nature == LITERAL)
	{
		SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-1].valor_lexico));

		(yyval.ast_node)->code = storeTempToVariable((yyvsp[0].ast_node)->temp, id_info.depth, id_info.position);
		(yyval.ast_node)->code = concatCode((yyvsp[0].ast_node)->code, (yyval.ast_node)->code);

		printf("local decl code : %s",(yyval.ast_node)->code);
	}

}
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 298 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node) ) ;


	if((yyvsp[-1].ast_node)->ast_valor_lexico.nature == LITERAL)
	{
		SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-2].valor_lexico));

		(yyval.ast_node)->code = storeTempToVariable((yyvsp[-1].ast_node)->temp, id_info.depth, id_info.position);
		(yyval.ast_node)->code = concatCode((yyvsp[-1].ast_node)->code, (yyval.ast_node)->code);

		printf("local decl code : %s",(yyval.ast_node)->code);
	}

}
#line 1937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 313 "parser.y" /* yacc.c:1646  */
    {
(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node)) ;
}
#line 1945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 322 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_function_call_node(FUNCTION_CALL_NODE,(yyvsp[-3].ast_node),(yyvsp[-1].ast_node));}
#line 1957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 326 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 1969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 330 "parser.y" /* yacc.c:1646  */
    { 

	(yyval.ast_node) = new_assignment_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node),0);

	LISTA_INSTRUCOES *instrucoes = NULL;
	SYMBOL_INFO id_info = retrieve_symbol((yyvsp[-2].valor_lexico));

	(yyval.ast_node)->code = storeTempToVariable((yyvsp[0].ast_node)->temp, id_info.depth, id_info.position);
	(yyval.ast_node)->code = concatCode((yyvsp[0].ast_node)->code,(yyval.ast_node)->code);

	//printf("assignment code : %s",$$->code);


	printf("\n\n\n\n");
	inserir_instrucao(&instrucoes, (yyval.ast_node)->code);
	Imprimir_codigo();


}
#line 1993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 351 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(INPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1999 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(OUTPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2005 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 354 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_io_node(OUTPUT_NODE,(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 360 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_leaf_node('L',(yyvsp[0].valor_lexico));}
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 361 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_leaf_node('R',(yyvsp[0].valor_lexico));}
#line 2023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 363 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_shift_command_node('X',(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 2029 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_return_command_node('R',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 369 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-3].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 370 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 373 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2053 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 374 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = get_null();}
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_loop_while_node('w',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_loop_for_node('j',(yyvsp[-6].ast_node),(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_command_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 397 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 398 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 402 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 404 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 405 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('-',(yyvsp[0].ast_node));}
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 406 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('!',(yyvsp[0].ast_node)); }
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 407 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) = new_unary_expression('@',(yyvsp[0].ast_node)); }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 408 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('$',(yyvsp[0].ast_node)); }
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 409 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('~',(yyvsp[0].ast_node)); }
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 410 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_unary_expression('#',(yyvsp[0].ast_node)); }
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 419 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('+',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	
	LISTA_INSTRUCOES *instrucoes = NULL;
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("add", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);
	

	inserir_instrucao(&instrucoes, (yyval.ast_node)->code);
	//printf("Add code:\t: %s\n",$$->code);
	printf("\n\n\n\n");
	Imprimir_codigo();
	
}
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 437 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('-',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); 
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("sub", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	printf("sub code:\t: %s\n",(yyval.ast_node)->code);
	

}
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 451 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('*',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("mul", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	printf("mul code:\t: %s\n",(yyval.ast_node)->code);
	

}
#line 2190 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 463 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('/',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); 
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("div", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	printf("div code:\t: %s\n",(yyval.ast_node)->code);
}
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 474 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_binary_expression('%',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 476 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('|',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = binaryOperation("or", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	printf("or code:\t: %s\n",(yyval.ast_node)->code);	
}
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 487 "parser.y" /* yacc.c:1646  */
    {
	(yyval.ast_node) = new_binary_expression('&',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
	(yyval.ast_node)->code = binaryOperation("and", (yyvsp[-2].ast_node)->temp, (yyvsp[0].ast_node)->temp,(yyval.ast_node)->temp);
	char *subexpression_code  = concatCode((yyvsp[-2].ast_node)->code, (yyvsp[0].ast_node)->code);
	(yyval.ast_node)->code = concatCode(subexpression_code, (yyval.ast_node)->code);

	printf("and code:\t: %s\n",(yyval.ast_node)->code);
}
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 496 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_binary_expression('^',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2243 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval.ast_node) =  new_ternary_expression('?', (yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2249 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 500 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2255 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 504 "parser.y" /* yacc.c:1646  */
    { 
	(yyval.ast_node) = new_leaf_node(ID_NODE,(yyvsp[0].valor_lexico));
	SYMBOL_INFO id_info = retrieve_symbol((yyvsp[0].valor_lexico));
	(yyval.ast_node)->ast_valor_lexico.nature = id_info.nature;


	if(id_info.nature == FUNCTION){
	    printf("Semantical error line %d, column %d : ERR_FUNCTION\n",(yyvsp[0].valor_lexico).line,(yyvsp[0].valor_lexico).column);
	    exit(ERR_FUNCTION);
	}

	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = storeVariableToTemp((yyval.ast_node)->temp, id_info.depth, id_info.position);

	printf("code id: %s\n",(yyval.ast_node)->code);
}
#line 2276 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 520 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 523 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_INT;
	(yyval.ast_node) = new_leaf_node('d',(yyvsp[0].valor_lexico));
	(yyval.ast_node)->temp = newTemp();
	(yyval.ast_node)->code = loadValueToTemp((yyvsp[0].valor_lexico).value.intvalue, (yyval.ast_node)->temp);

	printf("code %s\n",(yyval.ast_node)->code);

}
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 533 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_FLOAT;
	(yyval.ast_node) = new_leaf_node('f',(yyvsp[0].valor_lexico));
}
#line 2305 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 538 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_CHAR;
	(yyval.ast_node) = new_leaf_node('c',(yyvsp[0].valor_lexico));
}
#line 2314 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 543 "parser.y" /* yacc.c:1646  */
    { 
	(yyvsp[0].valor_lexico).var_type = TYPE_STRING;
	(yyval.ast_node) = new_leaf_node('s',(yyvsp[0].valor_lexico));
}
#line 2323 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 547 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('T',(yyvsp[0].valor_lexico));}
#line 2329 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 548 "parser.y" /* yacc.c:1646  */
    {(yyval.ast_node) = new_leaf_node('F',(yyvsp[0].valor_lexico));}
#line 2335 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2339 "parser.tab.c" /* yacc.c:1646  */
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
#line 555 "parser.y" /* yacc.c:1906  */

