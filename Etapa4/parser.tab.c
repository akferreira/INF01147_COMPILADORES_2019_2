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
    //extern void *arvore;

#line 107 "parser.tab.c"

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
#line 7 "parser.y"

  ast_node* ast_node;
  VALOR_LEXICO valor_lexico;
  MODIFIER_S var_modifier;
  
  

#line 174 "parser.tab.c"

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

/* Second part of user prologue.  */
#line 16 "parser.y"


//#include "main.c"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "symbol_table.h"
extern void *arvore;
extern int get_line_number (void);
extern void exporta (void *arvore);
void yyerror (char const *s)
{

	 fprintf (stderr, "Line %d Column %d : %s\n", get_line_number(),yylloc.last_column,s);
}
extern int yylex (void);
int yyparse (void);



#line 225 "parser.tab.c"


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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

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
       2,     2,     2,    48,     2,    49,     2,    56,    51,     2,
      63,    64,    54,    52,    65,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    60,
       2,    68,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,    57,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    50,    67,     2,     2,     2,     2,
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
       0,   130,   130,   137,   139,   142,   143,   147,   147,   150,
     151,   154,   155,   156,   157,   158,   160,   161,   163,   164,
     169,   174,   179,   181,   182,   183,   184,   193,   195,   197,
     198,   199,   203,   203,   203,   203,   203,   203,   203,   204,
     205,   206,   211,   212,   213,   215,   219,   223,   227,   233,
     235,   235,   239,   243,   245,   246,   255,   256,   258,   261,
     264,   265,   268,   269,   270,   272,   272,   273,   274,   276,
     277,   278,   278,   278,   289,   290,   294,   296,   298,   299,
     300,   301,   302,   303,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   315,   319,   321,   325,   328,   331,   334,
     337,   340
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
  "'-'", "'*'", "'/'", "'%'", "'^'", "'?'", "':'", "';'", "'['", "']'",
  "'('", "')'", "','", "'{'", "'}'", "'='", "$accept", "enter_scope",
  "exit_scope", "null_node", "program", "grammars",
  "global_var_declaration", "primitive_type", "identifier",
  "simple_identifier", "vector", "function_declaration",
  "function_parameters_list", "function_parameters_argument",
  "command_block", "command_list", "command", "modifiers", "no_modifier",
  "local_var_declaration", "function_call", "call_parameter_list",
  "assignment_command", "input_command", "output_command", "shift",
  "shift_command", "command_return", "if_statement", "command_block_loop",
  "loops", "loop_while", "loop_for", "loop_for_command_list",
  "loop_for_command", "expression_list", "literal", "expression",
  "local_var_initialization", YY_NULLPTR
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
      59,    91,    93,    40,    41,    44,   123,   125,    61
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      62,  -166,  -166,  -166,  -166,  -166,   194,    16,    62,  -166,
     -11,  -166,   -11,  -166,  -166,   -23,    -8,     0,  -166,    11,
      10,    34,  -166,    78,  -166,    78,    18,   194,    45,    23,
      30,    32,  -166,    45,  -166,  -166,  -166,    78,  -166,  -166,
      54,  -166,  -166,  -166,   108,    55,    63,    92,   167,    92,
    -166,   112,    66,    82,    88,    45,   -32,    86,  -166,    85,
     108,   194,    93,    96,    98,   105,   106,   107,   120,  -166,
     108,  -166,  -166,    92,    92,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,    92,    92,    92,    92,    92,    92,    92,    92,
     264,    92,  -166,   131,   264,  -166,     8,  -166,  -166,   160,
    -166,  -166,    92,    92,    92,  -166,  -166,    45,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,   199,   214,   264,   264,
     279,   188,   188,   -49,   -49,   229,    92,    92,    92,    92,
      92,    92,    92,    92,    92,   264,   167,  -166,  -166,  -166,
    -166,   133,   129,  -166,  -166,  -166,   264,   264,   139,   183,
    -166,   160,  -166,   156,  -166,   272,   279,   188,   188,   -49,
     -49,   -49,   -49,   244,  -166,   131,    92,     8,  -166,  -166,
    -166,  -166,    92,  -166,   196,    26,  -166,  -166,    92,   254,
    -166,  -166,  -166,  -166,  -166,   137,   -49,     8,  -166,  -166,
     150,   156,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    11,    12,    14,    13,    15,     0,     0,     5,     7,
       0,     8,     0,     1,     6,    18,     0,    16,    17,     0,
      16,     0,    10,    22,     9,    22,     0,     0,     0,     0,
      23,     0,    19,     0,    18,    26,     2,    22,     2,    25,
       0,    21,    24,    20,     2,     0,     0,     0,     0,     0,
      44,    43,     0,     0,     0,     0,     0,    16,    30,     0,
       2,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       2,    66,    65,     0,     0,    96,    97,   101,   100,    98,
      99,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,    55,    54,    59,    42,     0,    40,    41,     4,
      56,    57,     0,     0,     0,     3,    28,     0,    33,    38,
      35,    36,    37,    34,    39,    29,     0,     0,    80,    84,
      81,    78,    79,    82,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,    16,    71,    73,
      72,     0,    70,    76,    45,    45,    52,    58,     0,    51,
      27,     0,     2,     0,    77,    90,    91,    85,    86,    87,
      88,    89,    92,     0,    74,     0,     0,     0,    94,    48,
      47,    49,     0,    46,     4,     0,    64,    67,     0,     0,
      69,    50,     2,    60,    63,     0,    93,     0,    61,    62,
       0,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,    43,   215,  -166,  -166,   168,    41,   -10,
    -166,  -166,    52,  -166,   -35,   -33,  -147,  -166,    79,   -89,
    -166,    56,   -79,  -166,  -166,  -166,   -77,  -166,  -166,  -165,
    -166,  -166,  -166,  -117,  -166,    90,  -166,   -27,    76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    40,   150,   144,     7,     8,     9,    55,    56,    57,
      18,    11,    29,    30,    58,    59,    60,    61,   169,    62,
      63,   148,    64,    65,    66,   103,    67,    68,    69,   177,
      70,    71,    72,   141,   142,    92,   168,   149,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    41,    20,    43,   100,   101,   176,   138,   133,   134,
     185,     1,     2,     3,     4,     5,    13,   139,    35,   140,
      90,    93,    94,    39,    50,    51,   192,   106,   176,     1,
       2,     3,     4,     5,    45,    15,   102,   115,    21,    47,
      48,    49,    50,    51,   176,    99,   116,   117,    53,    54,
     180,    16,    22,    19,    15,   118,   119,   120,   121,   122,
     123,   124,   125,    23,   135,     1,     2,     3,     4,     5,
     190,    24,    15,    25,    26,   146,   147,    31,   138,     6,
      32,     1,     2,     3,     4,     5,   137,    36,   139,    42,
     140,    34,   175,   184,    27,    37,    38,   151,   138,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   139,   165,
     140,     1,     2,     3,     4,     5,    45,   174,    73,    46,
      44,    47,    48,    49,    50,    51,    74,    52,    95,    96,
      53,    54,    75,    76,    77,    78,    79,    80,    81,   179,
      82,    83,    97,    84,    85,    86,    87,   188,    98,   104,
      88,   186,   105,   108,    15,    89,   109,   137,   110,     1,
       2,     3,     4,     5,    45,   111,   112,   113,    10,    47,
      48,    49,    50,    51,    12,   -31,    10,   137,    53,    54,
     114,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     143,    28,   166,    28,   167,    33,   136,     1,     2,     3,
       4,     5,    15,   171,   189,    28,   182,    75,    76,    77,
      78,    79,    80,    81,   191,    82,    83,   183,    84,    85,
      86,    87,   175,    14,   170,    88,   164,   173,   181,   107,
      89,     0,    91,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   130,   131,   132,   133,   134,     0,   172,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,   152,   126,   127,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,   153,   126,
     127,   128,   129,   130,   131,   132,   133,   134,     0,     0,
       0,     0,     0,   154,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   178,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   187,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   127,   128,   129,   130,   131,   132,   133,
     134,   128,   129,   130,   131,   132,   133,   134
};

static const yytype_int16 yycheck[] =
{
      10,    36,    12,    38,    36,    37,   153,    96,    57,    58,
     175,     3,     4,     5,     6,     7,     0,    96,    28,    96,
      47,    48,    49,    33,    16,    17,   191,    60,   175,     3,
       4,     5,     6,     7,     8,    46,    68,    70,    61,    13,
      14,    15,    16,    17,   191,    55,    73,    74,    22,    23,
     167,    10,    60,    12,    46,    82,    83,    84,    85,    86,
      87,    88,    89,    63,    91,     3,     4,     5,     6,     7,
     187,    60,    46,    63,    40,   102,   103,    25,   167,    17,
      62,     3,     4,     5,     6,     7,    96,    64,   167,    37,
     167,    46,    66,    67,    16,    65,    64,   107,   187,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   187,   136,
     187,     3,     4,     5,     6,     7,     8,   152,    63,    11,
      66,    13,    14,    15,    16,    17,    63,    19,    16,    63,
      22,    23,    40,    41,    42,    43,    44,    45,    46,   166,
      48,    49,    60,    51,    52,    53,    54,   182,    60,    63,
      58,   178,    67,    60,    46,    63,    60,   167,    60,     3,
       4,     5,     6,     7,     8,    60,    60,    60,     0,    13,
      14,    15,    16,    17,     6,    67,     8,   187,    22,    23,
      60,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      30,    23,    59,    25,    65,    27,    65,     3,     4,     5,
       6,     7,    46,    64,    67,    37,    10,    40,    41,    42,
      43,    44,    45,    46,    64,    48,    49,   174,    51,    52,
      53,    54,    66,     8,   145,    58,   136,   151,   172,    61,
      63,    -1,    65,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    54,    55,    56,    57,    58,    -1,    65,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    64,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    -1,
      -1,    -1,    -1,    64,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    51,    52,    53,    54,    55,    56,    57,
      58,    52,    53,    54,    55,    56,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    17,    73,    74,    75,
      76,    80,    76,     0,    73,    46,    77,    78,    79,    77,
      78,    61,    60,    63,    60,    63,    40,    16,    76,    81,
      82,    81,    62,    76,    46,    78,    64,    65,    64,    78,
      70,    83,    81,    83,    66,     8,    11,    13,    14,    15,
      16,    17,    19,    22,    23,    76,    77,    78,    83,    84,
      85,    86,    88,    89,    91,    92,    93,    95,    96,    97,
      99,   100,   101,    63,    63,    40,    41,    42,    43,    44,
      45,    46,    48,    49,    51,    52,    53,    54,    58,    63,
     106,    65,   104,   106,   106,    16,    63,    60,    60,    78,
      36,    37,    68,    94,    63,    67,    84,    76,    60,    60,
      60,    60,    60,    60,    60,    84,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,    50,    51,    52,    53,
      54,    55,    56,    57,    58,   106,    65,    78,    88,    91,
      95,   102,   103,    30,    72,   107,   106,   106,    90,   106,
      71,    78,    64,    64,    64,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   104,   106,    59,    65,   105,    87,
      87,    64,    65,   107,    83,    66,    85,    98,    59,   106,
     102,    90,    10,    72,    67,    98,   106,    59,    83,    67,
     102,    64,    98
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    77,    77,    78,    79,
      80,    80,    81,    81,    81,    82,    82,    83,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    87,    88,    88,    88,    89,
      90,    90,    91,    92,    93,    93,    94,    94,    95,    96,
      97,    97,    98,    98,    98,    99,    99,   100,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   107,   106,   106,   106,   106,   106,
     106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,     2,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       7,     6,     0,     1,     3,     3,     2,     5,     2,     2,
       1,     0,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     0,     4,     4,     4,     4,
       3,     1,     3,     2,     2,     2,     1,     1,     3,     2,
       6,     7,     3,     2,     1,     1,     1,     5,     9,     3,
       1,     1,     1,     1,     3,     2,     0,     3,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     2,     1,     1,     1,     1,     1,
       1,     1
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 130 "parser.y"
    {
printf("\nnew scope\n");
printf("%d\n",create_new_scope());


}
#line 1586 "parser.tab.c"
    break;

  case 3:
#line 137 "parser.y"
    {printf("exiting scope\n");  printf("%d\n",exit_scope());}
#line 1592 "parser.tab.c"
    break;

  case 4:
#line 139 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1598 "parser.tab.c"
    break;

  case 5:
#line 142 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1604 "parser.tab.c"
    break;

  case 6:
#line 143 "parser.y"
    {(yyval.ast_node) =  new_global_grammar_node('|',arvore,(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1610 "parser.tab.c"
    break;

  case 9:
#line 150 "parser.y"
    {(yyval.ast_node) = new_static_global_var_declaration_node('g',(yyvsp[-3].valor_lexico),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node));}
#line 1616 "parser.tab.c"
    break;

  case 10:
#line 151 "parser.y"
    {(yyval.ast_node) = new_nonstatic_global_var_declaration_node('g',(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node));}
#line 1622 "parser.tab.c"
    break;

  case 16:
#line 160 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1628 "parser.tab.c"
    break;

  case 17:
#line 161 "parser.y"
    {(yyval.ast_node) = new_leaf_node('V',(yyvsp[0].valor_lexico));}
#line 1634 "parser.tab.c"
    break;

  case 18:
#line 163 "parser.y"
    {(yyval.ast_node) = new_leaf_node('I',(yyvsp[0].valor_lexico));}
#line 1640 "parser.tab.c"
    break;

  case 20:
#line 170 "parser.y"
    {
(yyval.ast_node) = new_static_function_declaration_node('M',(yyvsp[-6].valor_lexico),(yyvsp[-5].valor_lexico),(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));

}
#line 1649 "parser.tab.c"
    break;

  case 21:
#line 174 "parser.y"
    {
(yyval.ast_node) = new_nonstatic_function_declaration_node('M',(yyvsp[-5].valor_lexico),(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));
}
#line 1657 "parser.tab.c"
    break;

  case 22:
#line 179 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1663 "parser.tab.c"
    break;

  case 24:
#line 182 "parser.y"
    {(yyval.ast_node) = new_parameter_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1669 "parser.tab.c"
    break;

  case 25:
#line 183 "parser.y"
    {(yyval.ast_node) = new_const_parameter_node('p',(yyvsp[-2].valor_lexico),(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1675 "parser.tab.c"
    break;

  case 26:
#line 184 "parser.y"
    {(yyval.ast_node) = new_nonconst_parameter_node('p',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1681 "parser.tab.c"
    break;

  case 27:
#line 193 "parser.y"
    {(yyval.ast_node) = new_command_block_node('{',(yyvsp[-2].ast_node));}
#line 1687 "parser.tab.c"
    break;

  case 28:
#line 195 "parser.y"
    {(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1693 "parser.tab.c"
    break;

  case 29:
#line 197 "parser.y"
    {(yyval.ast_node) = new_command_list_node((yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1699 "parser.tab.c"
    break;

  case 30:
#line 198 "parser.y"
    {(yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1705 "parser.tab.c"
    break;

  case 31:
#line 199 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1711 "parser.tab.c"
    break;

  case 35:
#line 203 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1717 "parser.tab.c"
    break;

  case 36:
#line 203 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1723 "parser.tab.c"
    break;

  case 37:
#line 203 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1729 "parser.tab.c"
    break;

  case 38:
#line 203 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1735 "parser.tab.c"
    break;

  case 39:
#line 204 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1741 "parser.tab.c"
    break;

  case 40:
#line 205 "parser.y"
    {(yyval.ast_node) = new_leaf_node('b',(yyvsp[-1].valor_lexico));}
#line 1747 "parser.tab.c"
    break;

  case 41:
#line 206 "parser.y"
    {(yyval.ast_node) = new_leaf_node('.',(yyvsp[-1].valor_lexico));}
#line 1753 "parser.tab.c"
    break;

  case 42:
#line 211 "parser.y"
    { (yyval.var_modifier) = modifier(1,1);}
#line 1759 "parser.tab.c"
    break;

  case 43:
#line 212 "parser.y"
    { (yyval.var_modifier) = modifier(1,0);}
#line 1765 "parser.tab.c"
    break;

  case 44:
#line 213 "parser.y"
    { (yyval.var_modifier) = modifier(0,1);}
#line 1771 "parser.tab.c"
    break;

  case 45:
#line 215 "parser.y"
    {(yyval.var_modifier) = modifier(0,0);}
#line 1777 "parser.tab.c"
    break;

  case 46:
#line 219 "parser.y"
    {
(yyval.ast_node) = new_local_var_declaration_node('<',(yyvsp[-3].var_modifier),(yyvsp[-2].valor_lexico),(yyvsp[-1].ast_node),(yyvsp[0].ast_node) ) ;
}
#line 1785 "parser.tab.c"
    break;

  case 47:
#line 223 "parser.y"
    {
(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[-1].ast_node) ) ;

}
#line 1794 "parser.tab.c"
    break;

  case 48:
#line 227 "parser.y"
    {
(yyval.ast_node) = new_local_var_declaration_node('<', (yyvsp[0].var_modifier) ,(yyvsp[-3].valor_lexico),(yyvsp[-2].ast_node),(yyvsp[-1].ast_node)) ;
}
#line 1802 "parser.tab.c"
    break;

  case 49:
#line 233 "parser.y"
    {(yyval.ast_node) = new_function_call_node('K',(yyvsp[-3].ast_node),(yyvsp[-1].ast_node));}
#line 1808 "parser.tab.c"
    break;

  case 50:
#line 235 "parser.y"
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1814 "parser.tab.c"
    break;

  case 52:
#line 239 "parser.y"
    { 
(yyval.ast_node) = new_assignment_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1821 "parser.tab.c"
    break;

  case 53:
#line 243 "parser.y"
    {(yyval.ast_node) = new_io_node('i',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1827 "parser.tab.c"
    break;

  case 54:
#line 245 "parser.y"
    {(yyval.ast_node) = new_io_node('o',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1833 "parser.tab.c"
    break;

  case 55:
#line 246 "parser.y"
    {(yyval.ast_node) = new_io_node('o',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1839 "parser.tab.c"
    break;

  case 56:
#line 255 "parser.y"
    { (yyval.ast_node) = new_leaf_node('L',(yyvsp[0].valor_lexico));}
#line 1845 "parser.tab.c"
    break;

  case 57:
#line 256 "parser.y"
    { (yyval.ast_node) = new_leaf_node('R',(yyvsp[0].valor_lexico));}
#line 1851 "parser.tab.c"
    break;

  case 58:
#line 258 "parser.y"
    { (yyval.ast_node) = new_shift_command_node('X',(yyvsp[-2].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1857 "parser.tab.c"
    break;

  case 59:
#line 261 "parser.y"
    {(yyval.ast_node) = new_return_command_node('R',(yyvsp[-1].valor_lexico),(yyvsp[0].ast_node));}
#line 1863 "parser.tab.c"
    break;

  case 60:
#line 264 "parser.y"
    {(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-3].ast_node),(yyvsp[-1].ast_node),(yyvsp[0].ast_node));}
#line 1869 "parser.tab.c"
    break;

  case 61:
#line 265 "parser.y"
    {(yyval.ast_node) = new_ifelse_node(':',(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1875 "parser.tab.c"
    break;

  case 62:
#line 268 "parser.y"
    {(yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1881 "parser.tab.c"
    break;

  case 63:
#line 269 "parser.y"
    {(yyval.ast_node) = get_null();}
#line 1887 "parser.tab.c"
    break;

  case 67:
#line 273 "parser.y"
    {(yyval.ast_node) = new_loop_while_node('w',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1893 "parser.tab.c"
    break;

  case 68:
#line 274 "parser.y"
    {(yyval.ast_node) = new_loop_for_node('j',(yyvsp[-6].ast_node),(yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1899 "parser.tab.c"
    break;

  case 69:
#line 276 "parser.y"
    {(yyval.ast_node) = new_command_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1905 "parser.tab.c"
    break;

  case 74:
#line 289 "parser.y"
    { (yyval.ast_node) = new_expression_list_node((yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1911 "parser.tab.c"
    break;

  case 75:
#line 290 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1917 "parser.tab.c"
    break;

  case 76:
#line 294 "parser.y"
    {}
#line 1923 "parser.tab.c"
    break;

  case 77:
#line 296 "parser.y"
    { (yyval.ast_node) = (yyvsp[-1].ast_node);}
#line 1929 "parser.tab.c"
    break;

  case 78:
#line 298 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 1935 "parser.tab.c"
    break;

  case 79:
#line 299 "parser.y"
    { (yyval.ast_node) = new_unary_expression('-',(yyvsp[0].ast_node));}
#line 1941 "parser.tab.c"
    break;

  case 80:
#line 300 "parser.y"
    { (yyval.ast_node) = new_unary_expression('!',(yyvsp[0].ast_node)); }
#line 1947 "parser.tab.c"
    break;

  case 81:
#line 301 "parser.y"
    { (yyval.ast_node) = new_unary_expression('@',(yyvsp[0].ast_node)); }
#line 1953 "parser.tab.c"
    break;

  case 82:
#line 302 "parser.y"
    {(yyval.ast_node) = new_unary_expression('$',(yyvsp[0].ast_node)); }
#line 1959 "parser.tab.c"
    break;

  case 83:
#line 303 "parser.y"
    {(yyval.ast_node) = new_unary_expression('~',(yyvsp[0].ast_node)); }
#line 1965 "parser.tab.c"
    break;

  case 84:
#line 304 "parser.y"
    {(yyval.ast_node) = new_unary_expression('#',(yyvsp[0].ast_node)); }
#line 1971 "parser.tab.c"
    break;

  case 85:
#line 306 "parser.y"
    {(yyval.ast_node) = new_binary_expression('+',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1977 "parser.tab.c"
    break;

  case 86:
#line 307 "parser.y"
    {(yyval.ast_node) = new_binary_expression('-',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1983 "parser.tab.c"
    break;

  case 87:
#line 308 "parser.y"
    {(yyval.ast_node) = new_binary_expression('*',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 1989 "parser.tab.c"
    break;

  case 88:
#line 309 "parser.y"
    {(yyval.ast_node) = new_binary_expression('/',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 1995 "parser.tab.c"
    break;

  case 89:
#line 310 "parser.y"
    {(yyval.ast_node) = new_binary_expression('%',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2001 "parser.tab.c"
    break;

  case 90:
#line 311 "parser.y"
    {(yyval.ast_node) = new_binary_expression('|',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2007 "parser.tab.c"
    break;

  case 91:
#line 312 "parser.y"
    {(yyval.ast_node) = new_binary_expression('&',(yyvsp[-2].ast_node),(yyvsp[0].ast_node));}
#line 2013 "parser.tab.c"
    break;

  case 92:
#line 313 "parser.y"
    {(yyval.ast_node) = new_binary_expression('^',(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2019 "parser.tab.c"
    break;

  case 93:
#line 315 "parser.y"
    { (yyval.ast_node) =  new_ternary_expression('?', (yyvsp[-4].ast_node),(yyvsp[-2].ast_node),(yyvsp[0].ast_node)); }
#line 2025 "parser.tab.c"
    break;

  case 94:
#line 319 "parser.y"
    { (yyval.ast_node) = (yyvsp[0].ast_node);}
#line 2031 "parser.tab.c"
    break;

  case 95:
#line 321 "parser.y"
    { 

(yyval.ast_node) = new_leaf_node('I',(yyvsp[0].valor_lexico));
}
#line 2040 "parser.tab.c"
    break;

  case 96:
#line 325 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('d',(yyvsp[0].valor_lexico));
}
#line 2048 "parser.tab.c"
    break;

  case 97:
#line 328 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('f',(yyvsp[0].valor_lexico));
}
#line 2056 "parser.tab.c"
    break;

  case 98:
#line 331 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('c',(yyvsp[0].valor_lexico));
}
#line 2064 "parser.tab.c"
    break;

  case 99:
#line 334 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('s',(yyvsp[0].valor_lexico));
}
#line 2072 "parser.tab.c"
    break;

  case 100:
#line 337 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('T',(yyvsp[0].valor_lexico));
}
#line 2080 "parser.tab.c"
    break;

  case 101:
#line 340 "parser.y"
    { 
(yyval.ast_node) = new_leaf_node('F',(yyvsp[0].valor_lexico));
}
#line 2088 "parser.tab.c"
    break;


#line 2092 "parser.tab.c"

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
#line 349 "parser.y"

