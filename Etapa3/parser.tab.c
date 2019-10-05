/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 1 "parser.y"

    #include "ast.h"

#line 106 "parser.tab.c"

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
    TOKEN_ERRO = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 6 "parser.y"

  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  
  

#line 172 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Second part of user prologue.  */
#line 14 "parser.y"


//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
extern int get_line_number (void);
extern void exporta (void *arvore);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line %d : %s\n", get_line_number(),s);
}
extern int yylex (void);
int yyparse (void);



#line 207 "parser.tab.c"


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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

#define YYUNDEFTOK  2
#define YYMAXUTOK   302

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,    52,    55,     2,
      63,    64,    50,    53,    65,    54,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    60,
       2,    68,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    56,    67,     2,     2,     2,     2,
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   117,   118,   118,   121,   122,   123,   125,
     126,   127,   128,   129,   131,   132,   134,   135,   140,   141,
     142,   142,   142,   143,   144,   147,   149,   149,   149,   149,
     149,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   158,   159,   160,   164,   172,   176,   181,   185,   188,
     190,   191,   194,   195,   201,   201,   202,   205,   208,   209,
     212,   213,   214,   217,   218,   220,   220,   221,   221,   221,
     232,   233,   235,   239,   241,   242,   243,   244,   245,   246,
     247,   249,   250,   251,   252,   253,   254,   255,   256,   258,
     262,   264,   267,   270,   273,   276,   279,   282
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
  "TK_IDENTIFICADOR", "TOKEN_ERRO", "'!'", "'#'", "'*'", "'/'", "'%'",
  "'+'", "'-'", "'&'", "'|'", "'^'", "'?'", "':'", "';'", "'['", "']'",
  "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "program",
  "grammars", "global_var_declaration", "decl", "primitive_type",
  "identifier", "simple_identifier", "vector", "function_declaration",
  "function_parameters_list", "function_parameters_argument",
  "command_block", "command_list", "command", "modifiers",
  "local_var_declaration", "null_node", "assignment_command",
  "input_command", "output_command", "function_call", "shift",
  "shift_command", "command_return", "if_statement", "command_block_loop",
  "loop_while", "loop_for", "loop_for_command_list", "loop_for_command",
  "expression_list", "expression", "local_var_initialization", "literal", YY_NULLPTR
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
      42,    47,    37,    43,    45,    38,   124,    94,    63,    58,
      59,    91,    93,    40,    41,    44,   123,   125,    61
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     152,  -141,  -141,  -141,  -141,  -141,    61,    49,   152,  -141,
       1,    26,  -141,    23,    42,  -141,  -141,  -141,    -7,  -141,
    -141,  -141,  -141,    -1,    57,   301,   301,    27,    61,    53,
      41,    46,    43,  -141,    60,  -141,    47,   301,    47,  -141,
       7,  -141,  -141,  -141,    52,    62,   185,   159,   185,  -141,
      96,    63,  -141,  -141,    35,    70,    -5,  -141,    56,    72,
      61,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,     7,
       7,   185,   185,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
     185,   185,   185,   185,   185,   185,   185,   185,   288,  -141,
     185,  -141,   199,   288,  -141,   145,   159,   104,  -141,  -141,
    -141,   185,   185,  -141,     7,    93,  -141,  -141,   215,   230,
     288,   288,   -49,   -49,   -49,   -49,   -49,   245,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   288,   159,    79,
    -141,  -141,  -141,    82,    77,    81,   131,   270,  -141,  -141,
     288,   288,  -141,   104,    47,   114,  -141,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   268,  -141,   199,   185,   145,
    -141,  -141,  -141,  -141,   133,    87,  -141,  -141,   185,   278,
    -141,    47,  -141,    80,   -49,   145,  -141,  -141,   101,   114,
    -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     9,    10,    12,    11,    13,     0,     0,     2,     4,
       0,     0,     5,     0,     0,     1,     3,     7,    16,     8,
      14,    15,     6,    16,     0,    20,    20,     0,     0,     0,
       0,    21,     0,    17,     0,    24,     0,    20,     0,    23,
      30,    19,    22,    18,     0,     0,     0,     0,     0,    43,
      42,     0,    39,    40,    16,     0,     0,    29,     0,     0,
       0,    32,    34,    35,    36,    37,    33,    38,    31,    30,
      30,     0,     0,    92,    93,    97,    96,    94,    95,    91,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    72,
       0,    51,    50,    57,    41,     0,     0,    16,    47,    54,
      55,     0,     0,    25,    30,     0,    27,    28,     0,     0,
      76,    80,    78,    74,    75,    77,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    71,     0,    16,
      67,    69,    68,     0,    66,     0,     0,     0,    45,    46,
      48,    56,    26,     0,     0,     0,    73,    83,    84,    85,
      81,    82,    87,    86,    88,     0,    70,     0,     0,     0,
      52,    53,    90,    44,    58,     0,    62,    63,     0,     0,
      65,     0,    61,     0,    89,     0,    59,    60,     0,     0,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,   160,  -141,  -141,   161,   138,    36,   115,  -141,  -141,
      18,  -141,   -36,   -53,  -120,  -141,   -90,  -141,   -89,  -141,
    -141,  -141,  -141,   -88,  -141,  -141,  -131,  -141,  -141,  -140,
    -141,   -95,   -44,    28,    37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    55,    56,    20,    21,    12,
      30,    31,    57,    58,    59,    60,    61,   139,    62,    63,
      64,    65,   102,    66,    67,    68,   167,    69,    70,   133,
     134,    91,    88,   138,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,   135,    43,    92,    93,   130,   131,   132,   125,   126,
       1,     2,     3,     4,     5,    44,   106,   107,    45,   170,
      46,    47,    48,    49,    50,   166,    51,   108,   109,    52,
      53,    99,   100,   156,   173,   178,   110,   111,   112,   113,
     114,   115,   116,   117,    32,   166,   127,    19,   180,    15,
      19,   142,   136,    54,    24,    42,    25,   140,   141,   166,
      24,    17,    26,   101,     1,     2,     3,     4,     5,   130,
     131,   132,    18,    40,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    22,   157,   130,   131,   132,    23,    33,
       1,     2,     3,     4,     5,    44,    24,    27,    96,    35,
      46,    47,    48,    49,    50,    36,    39,    38,   164,    52,
      53,    37,    94,    40,   169,    71,    97,     1,     2,     3,
       4,     5,    44,   103,   174,    72,    95,    46,    47,    48,
      49,    50,   104,    54,   137,   176,    52,    53,    11,   143,
      24,   158,   159,   171,    14,   160,    11,   177,     1,     2,
       3,     4,     5,   165,   172,     1,     2,     3,     4,     5,
      54,    49,    50,    29,    29,   179,    34,    13,    16,     6,
      98,   163,     0,     0,   162,    29,     0,     0,     0,     0,
     165,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,   129,     0,     0,     0,   161,   128,     0,   105,    73,
      74,    75,    76,    77,    78,    79,     0,    80,    81,    82,
       0,     0,    83,    84,    85,     0,     0,    86,     0,     0,
       0,     0,    87,     0,    90,    73,    74,    75,    76,    77,
      78,    79,     0,    80,    81,    82,     0,     0,    83,    84,
      85,     0,     0,    86,     0,     0,     0,     0,    87,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,   128,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     0,     0,     0,     0,     0,   144,
     118,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,   145,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     1,     2,     3,     4,     5,   146,
      73,    74,    75,    76,    77,    78,    79,    28,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   168,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   175,   118,   119,
     120,   121,   122,   123,   124,   125,   126
};

static const yytype_int16 yycheck[] =
{
      36,    96,    38,    47,    48,    95,    95,    95,    57,    58,
       3,     4,     5,     6,     7,     8,    69,    70,    11,   159,
      13,    14,    15,    16,    17,   145,    19,    71,    72,    22,
      23,    36,    37,   128,   165,   175,    80,    81,    82,    83,
      84,    85,    86,    87,    26,   165,    90,    11,   179,     0,
      14,   104,    96,    46,    61,    37,    63,   101,   102,   179,
      61,    60,    63,    68,     3,     4,     5,     6,     7,   159,
     159,   159,    46,    66,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    60,   128,   175,   175,   175,    46,    62,
       3,     4,     5,     6,     7,     8,    61,    40,    63,    46,
      13,    14,    15,    16,    17,    64,    46,    64,   144,    22,
      23,    65,    16,    66,   158,    63,    46,     3,     4,     5,
       6,     7,     8,    67,   168,    63,    63,    13,    14,    15,
      16,    17,    60,    46,    30,   171,    22,    23,     0,    46,
      61,    59,    65,    10,     6,    64,     8,    67,     3,     4,
       5,     6,     7,    66,    67,     3,     4,     5,     6,     7,
      46,    16,    17,    25,    26,    64,    28,     6,     8,    17,
      55,   143,    -1,    -1,   137,    37,    -1,    -1,    -1,    -1,
      66,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    46,    -1,    -1,    -1,    64,    65,    -1,    60,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      -1,    -1,    53,    54,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    63,    -1,    65,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    -1,    -1,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     3,     4,     5,     6,     7,    64,
      40,    41,    42,    43,    44,    45,    46,    16,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    50,    51,
      52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    70,    71,    72,
      73,    74,    78,    73,    74,     0,    70,    60,    46,    75,
      76,    77,    60,    46,    61,    63,    63,    40,    16,    74,
      79,    80,    79,    62,    74,    46,    64,    65,    64,    46,
      66,    81,    79,    81,     8,    11,    13,    14,    15,    16,
      17,    19,    22,    23,    46,    74,    75,    81,    82,    83,
      84,    85,    87,    88,    89,    90,    92,    93,    94,    96,
      97,    63,    63,    40,    41,    42,    43,    44,    45,    46,
      48,    49,    50,    53,    54,    55,    58,    63,   101,   103,
      65,   100,   101,   101,    16,    63,    63,    46,    76,    36,
      37,    68,    91,    67,    60,    74,    82,    82,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   101,    65,    46,
      85,    87,    92,    98,    99,   100,   101,    30,   102,    86,
     101,   101,    82,    46,    64,    64,    64,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   100,   101,    59,    65,
      64,    64,   103,   102,    81,    66,    83,    95,    59,   101,
      98,    10,    67,    95,   101,    59,    81,    67,    98,    64,
      95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    72,    73,    74,
      74,    74,    74,    74,    75,    75,    76,    77,    78,    78,
      79,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    85,    86,    87,    88,
      89,    89,    90,    90,    91,    91,    92,    93,    94,    94,
      95,    95,    95,    96,    97,    98,    98,    99,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   103,   103,   103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     7,     6,
       0,     1,     3,     3,     2,     3,     3,     2,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     4,     3,     3,     0,     3,     2,
       2,     2,     4,     4,     1,     1,     3,     2,     5,     7,
       3,     2,     1,     5,     9,     3,     1,     1,     1,     1,
       3,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       2,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 9:
#line 125 "parser.y"
    {(yyval.ast_node) = new_leaf_node('t',(yyvsp[0].valor_lexico));}
#line 1460 "parser.tab.c"
    break;

  case 10:
#line 126 "parser.y"
    {(yyval.ast_node) = new_leaf_node('t',(yyvsp[0].valor_lexico));}
#line 1466 "parser.tab.c"
    break;

  case 11:
#line 127 "parser.y"
    {(yyval.ast_node) = new_leaf_node('t',(yyvsp[0].valor_lexico));}
#line 1472 "parser.tab.c"
    break;

  case 12:
#line 128 "parser.y"
    {(yyval.ast_node) = new_leaf_node('t',(yyvsp[0].valor_lexico));}
#line 1478 "parser.tab.c"
    break;

  case 13:
#line 129 "parser.y"
    {(yyval.ast_node) = new_leaf_node('t',(yyvsp[0].valor_lexico));}
#line 1484 "parser.tab.c"
    break;

  case 14:
#line 131 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1490 "parser.tab.c"
    break;

  case 15:
#line 132 "parser.y"
    {(yyval.ast_node) = new_leaf_node('I',(yyvsp[0].valor_lexico));}
#line 1496 "parser.tab.c"
    break;

  case 16:
#line 134 "parser.y"
    {(yyval.ast_node) = new_leaf_node('I',(yyvsp[0].valor_lexico));}
#line 1502 "parser.tab.c"
    break;

  case 32:
#line 153 "parser.y"
    {exporta((yyvsp[0].ast_node));}
#line 1508 "parser.tab.c"
    break;

  case 34:
#line 153 "parser.y"
    {exporta((yyvsp[0].ast_node));}
#line 1514 "parser.tab.c"
    break;

  case 41:
#line 158 "parser.y"
    { (yyval.ast_node) = new_modifier_node('S','C',(yyvsp[-1].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1520 "parser.tab.c"
    break;

  case 42:
#line 159 "parser.y"
    { (yyval.ast_node) = new_modifier_node('S', 0 ,(yyvsp[0].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1526 "parser.tab.c"
    break;

  case 43:
#line 160 "parser.y"
    { (yyval.ast_node) = new_modifier_node('C',0,(yyvsp[0].valor_lexico),(yyvsp[0].valor_lexico));}
#line 1532 "parser.tab.c"
    break;

  case 44:
#line 164 "parser.y"
    {
(yyval.ast_node) = new_local_var_declaration_node('<',(yyvsp[-3].ast_node),(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node) ) ;

}
#line 1541 "parser.tab.c"
    break;

  case 45:
#line 172 "parser.y"
    {
(yyval.ast_node) = new_local_var_declaration_node('<', NULL ,(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node) ) ;

}
#line 1550 "parser.tab.c"
    break;

  case 46:
#line 176 "parser.y"
    {
printf("oh no\n");
(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].ast_node) ,(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node)) ;
}
#line 1559 "parser.tab.c"
    break;

  case 47:
#line 181 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1565 "parser.tab.c"
    break;

  case 48:
#line 185 "parser.y"
    { (yyval.ast_node) = new_assignment_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1571 "parser.tab.c"
    break;

  case 70:
#line 232 "parser.y"
    { (yyval.ast_node) = insert_ast_node_sibling_list((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1577 "parser.tab.c"
    break;

  case 71:
#line 233 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1583 "parser.tab.c"
    break;

  case 72:
#line 235 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1589 "parser.tab.c"
    break;

  case 73:
#line 239 "parser.y"
    { printf("aaaaa\n");}
#line 1595 "parser.tab.c"
    break;

  case 74:
#line 241 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1601 "parser.tab.c"
    break;

  case 75:
#line 242 "parser.y"
    { (yyval.ast_node) = new_unary_expression('-',(yyvsp[0].ast_node));}
#line 1607 "parser.tab.c"
    break;

  case 76:
#line 243 "parser.y"
    { (yyval.ast_node) = new_unary_expression('!',(yyvsp[0].ast_node)); }
#line 1613 "parser.tab.c"
    break;

  case 77:
#line 244 "parser.y"
    { (yyval.ast_node) = new_unary_expression('@',(yyvsp[0].ast_node)); }
#line 1619 "parser.tab.c"
    break;

  case 78:
#line 245 "parser.y"
    {(yyval.ast_node) = new_unary_expression('$',(yyvsp[0].ast_node)); }
#line 1625 "parser.tab.c"
    break;

  case 79:
#line 246 "parser.y"
    {(yyval.ast_node) = new_unary_expression('~',(yyvsp[0].ast_node)); }
#line 1631 "parser.tab.c"
    break;

  case 80:
#line 247 "parser.y"
    {(yyval.ast_node) = new_unary_expression('#',(yyvsp[0].ast_node)); }
#line 1637 "parser.tab.c"
    break;

  case 81:
#line 249 "parser.y"
    {(yyval.ast_node) = new_binary_expression('+',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1643 "parser.tab.c"
    break;

  case 82:
#line 250 "parser.y"
    {(yyval.ast_node) = new_binary_expression('-',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1649 "parser.tab.c"
    break;

  case 83:
#line 251 "parser.y"
    {(yyval.ast_node) = new_binary_expression('*',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1655 "parser.tab.c"
    break;

  case 84:
#line 252 "parser.y"
    {(yyval.ast_node) = new_binary_expression('/',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1661 "parser.tab.c"
    break;

  case 85:
#line 253 "parser.y"
    {(yyval.ast_node) = new_binary_expression('%',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1667 "parser.tab.c"
    break;

  case 86:
#line 254 "parser.y"
    {(yyval.ast_node) = new_binary_expression('|',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1673 "parser.tab.c"
    break;

  case 87:
#line 255 "parser.y"
    {(yyval.ast_node) = new_binary_expression('&',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1679 "parser.tab.c"
    break;

  case 88:
#line 256 "parser.y"
    {(yyval.ast_node) = new_binary_expression('^',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1685 "parser.tab.c"
    break;

  case 89:
#line 258 "parser.y"
    { (yyval.ast_node) =  new_ternary_expression('?', (yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1691 "parser.tab.c"
    break;

  case 90:
#line 262 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1697 "parser.tab.c"
    break;

  case 91:
#line 264 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('I',(yyvsp[0].valor_lexico));
}
#line 1705 "parser.tab.c"
    break;

  case 92:
#line 267 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('d',(yyvsp[0].valor_lexico));
}
#line 1713 "parser.tab.c"
    break;

  case 93:
#line 270 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('f',(yyvsp[0].valor_lexico));
}
#line 1721 "parser.tab.c"
    break;

  case 94:
#line 273 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('c',(yyvsp[0].valor_lexico));
}
#line 1729 "parser.tab.c"
    break;

  case 95:
#line 276 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('s',(yyvsp[0].valor_lexico));
}
#line 1737 "parser.tab.c"
    break;

  case 96:
#line 279 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('T',(yyvsp[0].valor_lexico));
}
#line 1745 "parser.tab.c"
    break;

  case 97:
#line 282 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('F',(yyvsp[0].valor_lexico));
}
#line 1753 "parser.tab.c"
    break;


#line 1757 "parser.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 291 "parser.y"

