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
#line 1 "alfa.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "tokens.h"

  void yyerror(const char *error);
  extern int linea ,columna;
  extern FILE *yyin;
  extern FILE *salida;
  extern int yylex();
  extern int yyleng;
  extern bool invalidchar;
  extern bool longitud;

#line 83 "alfa.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "alfa.tab.h".  */
#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_RETURN = 259,
    TOK_ARRAY = 260,
    TOK_INT = 261,
    TOK_BOOLEAN = 262,
    TOK_SCANF = 263,
    TOK_PRINTF = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_WHILE = 267,
    TOK_OR = 268,
    TOK_AND = 269,
    TOK_DISTINTO = 270,
    TOK_IGUAL = 271,
    TOK_MENORIGUAL = 272,
    TOK_MAYORIGUAL = 273,
    TOK_FUNCTION = 274,
    TOK_TRUE = 275,
    TOK_FALSE = 276,
    TOK_IDENTIFICADOR = 277,
    TOK_CONSTANTE_ENTERA = 278,
    left = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "alfa.y" /* yacc.c:355  */

 char* cadena;
 int numero;
 

#line 154 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 171 "alfa.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,     2,     2,     2,     2,     2,
      38,    39,    26,    24,    37,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
      29,    40,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    61,    65,    70,    75,    79,    84,    89,
      93,    98,   103,   107,   112,   117,   121,   126,   131,   135,
     140,   144,   149,   154,   158,   162,   167,   171,   176,   180,
     184,   188,   193,   197,   202,   206,   211,   216,   220,   225,
     230,   235,   240,   245,   249,   253,   257,   261,   265,   269,
     273,   277,   281,   285,   289,   293,   297,   302,   307,   311,
     316,   320,   324,   328,   332,   336,   340,   345,   349,   354,
     358,   363,   368,   372,   377,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_RETURN", "TOK_ARRAY",
  "TOK_INT", "TOK_BOOLEAN", "TOK_SCANF", "TOK_PRINTF", "TOK_IF",
  "TOK_ELSE", "TOK_WHILE", "TOK_OR", "TOK_AND", "TOK_DISTINTO",
  "TOK_IGUAL", "TOK_MENORIGUAL", "TOK_MAYORIGUAL", "TOK_FUNCTION",
  "TOK_TRUE", "TOK_FALSE", "TOK_IDENTIFICADOR", "TOK_CONSTANTE_ENTERA",
  "'+'", "'-'", "'*'", "'/'", "left", "'<'", "'>'", "'!'", "'{'", "'}'",
  "';'", "'['", "']'", "','", "'('", "')'", "'='", "$accept", "programa",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "numero", "identificador",
  "digito", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    43,    45,    42,    47,   279,    60,
      62,    33,   123,   125,    59,    91,    93,    44,    40,    41,
      61
};
# endif

#define YYPACT_NINF -43

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -28,    23,    71,   -43,    28,   -43,   -43,     6,    71,
      10,   -43,   -43,   -43,    24,    28,   116,     6,   -43,   -43,
      30,    31,    44,    10,   166,    10,    10,    34,    35,    41,
     116,    53,   -43,   -43,    48,   -43,   -43,   -43,   -43,   -43,
     -11,   -43,   -43,    10,   -43,    54,    44,   -43,    51,   -43,
     -43,   166,   166,   166,   -43,   185,   -43,   -43,   -43,   -43,
     -30,   -43,   -43,   166,   166,   -43,   -43,   -43,   166,   166,
     166,   -43,   -43,   -43,    28,    40,   -43,    36,   166,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,    67,   118,   185,   154,   185,    10,    56,    64,   -43,
      40,    40,     1,     1,   -43,   -43,    40,    40,    40,    40,
     -43,   -43,   136,    60,    68,    72,   -43,   -43,    73,    28,
     -43,   166,   -43,   -43,   116,   116,    71,    64,   136,    70,
      74,   -43,   116,   -43,   -43,    97,   -43,    77,    81,   -43,
     116,    88,   -43
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,    10,    15,     3,
       0,     6,     8,     7,     0,     0,     0,    15,     4,    74,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    27,    28,     0,    32,    33,    29,    30,    31,
       0,    14,     5,     0,    75,     0,    71,    72,     0,    69,
      70,     0,     0,     0,    55,    42,    54,    52,    67,    68,
      51,    40,    41,     0,     0,     2,    25,    26,     0,     0,
       0,    13,    11,    73,    18,    47,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      58,     0,     0,    35,     0,    34,     0,     0,    20,    53,
      49,    48,    62,    61,    63,    64,    43,    44,    46,    45,
      65,    66,    60,     0,     0,     0,    36,    21,     0,     0,
      17,     0,    57,    56,     0,     0,    23,    20,    60,     0,
       0,    22,     0,    19,    59,    37,    39,     0,     0,    16,
       0,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,    -8,   -43,   -43,   -43,    -3,   -43,    80,   112,
     -43,   -43,    12,    18,   -43,   -23,   -43,   -43,   -43,   -43,
     -13,   -43,   -43,   -43,   -43,   -43,   -42,   -43,    13,   -43,
     -43,   -43,   124,   -43,   -10,    94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    13,    20,    16,
      17,    97,   120,    98,   132,    29,    30,    31,    32,    33,
      54,    35,    36,    37,    38,    39,    55,   113,   122,    56,
      57,    58,    59,    46,    60,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    18,    14,    34,     3,    69,    40,    66,    90,    75,
      76,    77,    23,    48,     1,    61,    62,    34,    82,    83,
      40,    91,    92,     4,    69,    15,    93,    94,    95,    70,
      88,    89,    19,    21,     6,     7,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    78,
      79,    80,    81,    82,    83,    80,    81,    82,    83,    22,
      84,    85,    86,    87,    42,    88,    89,    44,    43,    88,
      89,    96,    63,    64,    65,    99,     5,     6,     7,   128,
      78,    79,    80,    81,    82,    83,   117,    67,    68,    74,
      72,    84,    85,    86,    87,   118,    88,    89,   119,   123,
     124,   129,   130,   135,   125,   126,   114,   136,   138,   137,
     139,    34,    34,   140,    40,    40,    96,   141,   131,    34,
      24,   142,    40,    71,    25,    26,    27,    34,    28,    41,
      40,    78,    79,    80,    81,    82,    83,   127,    19,   133,
      73,   134,    84,    85,    86,    87,    45,    88,    89,    78,
      79,    80,    81,    82,    83,     0,     0,   115,     0,     0,
      84,    85,    86,    87,     0,    88,    89,    78,    79,    80,
      81,    82,    83,   121,     0,     0,     0,     0,    84,    85,
      86,    87,     0,    88,    89,     0,    49,    50,    19,    44,
     116,    51,     0,     0,     0,     0,     0,    52,    78,    79,
      80,    81,    82,    83,    53,     0,     0,     0,     0,    84,
      85,    86,    87,     0,    88,    89
};

static const yytype_int16 yycheck[] =
{
      10,     9,     5,    16,    32,    35,    16,    30,    38,    51,
      52,    53,    15,    23,     3,    25,    26,    30,    17,    18,
      30,    63,    64,     0,    35,    19,    68,    69,    70,    40,
      29,    30,    22,    43,     6,     7,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    13,
      14,    15,    16,    17,    18,    15,    16,    17,    18,    35,
      24,    25,    26,    27,    34,    29,    30,    23,    37,    29,
      30,    74,    38,    38,    33,    39,     5,     6,     7,   121,
      13,    14,    15,    16,    17,    18,    96,    34,    40,    38,
      36,    24,    25,    26,    27,    39,    29,    30,    34,    39,
      32,   124,   125,    33,    32,    32,    39,    33,    11,   132,
      33,   124,   125,    32,   124,   125,   119,   140,   126,   132,
       4,    33,   132,    43,     8,     9,    10,   140,    12,    17,
     140,    13,    14,    15,    16,    17,    18,   119,    22,   127,
      46,   128,    24,    25,    26,    27,    22,    29,    30,    13,
      14,    15,    16,    17,    18,    -1,    -1,    39,    -1,    -1,
      24,    25,    26,    27,    -1,    29,    30,    13,    14,    15,
      16,    17,    18,    37,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    29,    30,    -1,    20,    21,    22,    23,
      36,    25,    -1,    -1,    -1,    -1,    -1,    31,    13,    14,
      15,    16,    17,    18,    38,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    32,     0,     5,     6,     7,    43,    44,
      45,    46,    47,    48,    47,    19,    50,    51,    43,    22,
      49,    75,    35,    47,     4,     8,     9,    10,    12,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      75,    50,    34,    37,    23,    73,    74,    76,    75,    20,
      21,    25,    31,    38,    61,    67,    70,    71,    72,    73,
      75,    75,    75,    38,    38,    33,    56,    34,    40,    35,
      40,    49,    36,    76,    38,    67,    67,    67,    13,    14,
      15,    16,    17,    18,    24,    25,    26,    27,    29,    30,
      38,    67,    67,    67,    67,    67,    47,    52,    54,    39,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    39,    39,    36,    75,    39,    34,
      53,    37,    69,    39,    32,    32,    32,    54,    67,    56,
      56,    43,    55,    53,    69,    33,    33,    56,    11,    33,
      32,    56,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    63,
      64,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     2,     0,    10,     2,     0,     3,
       0,     2,     1,     0,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     7,    11,     7,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     1,     1,     4,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R1\t <programa> ::= main{<declaraciones> <funciones> <sentencias>}\n");
        }
#line 1369 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R2\t <declaraciones> ::= <declaracion>\n");
        }
#line 1377 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R3\t <declaraciones> ::= <declaracion> <declaraciones>\n");
        }
#line 1385 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R4\t <declaracion> ::= <clase> <identificadores>;\n");
        }
#line 1393 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R5\t <clase> ::= <clase_escalar>\n");
        }
#line 1401 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R6\t <clase> ::= <clase_vector>\n");
        }
#line 1409 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 85 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R9\t <clase_escalar> ::= <tipo>\n");
        }
#line 1417 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 90 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R10\t <tipo> ::= int\n");
        }
#line 1425 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 94 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R11\t <tipo> ::= boolean\n");
        }
#line 1433 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R15\t <clase_escalar> ::= array <tipo> [<constante_entera>]\n");
        }
#line 1441 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R18\t <identificadores> ::= <identificador>\n");
        }
#line 1449 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 108 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R19\t <identificadores> ::= <identificador> , <identificadores>\n");
        }
#line 1457 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 113 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R20\t <funciones> ::= <funcion> <funciones>\n");
        }
#line 1465 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R21\t <funciones> ::= \n");
        }
#line 1473 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R22\t <funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
        }
#line 1481 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 127 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R23\t <parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
        }
#line 1489 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R24\t <parametros_funcion> ::= \n");
        }
#line 1497 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R25\t <resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>\n");
        }
#line 1505 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R26\t <resto_parametros_funcion> ::= \n");
        }
#line 1513 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 145 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R27\t <parametro_funcion> ::= <tipo> <identificador>\n");
        }
#line 1521 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R28\t <declaraciones_funcion> ::= <declaraciones>\n");
        }
#line 1529 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 154 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R29\t <declaraciones_funcion> ::= \n");
        }
#line 1537 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 159 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R30\t <sentencias> ::= <sentencia>\n");
        }
#line 1545 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 163 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R31\t <sentencias> ::= <sentencia> <sentencias>\n");
        }
#line 1553 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 168 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R32\t <sentencia> ::= <sentencia_simple>;\n");
        }
#line 1561 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 172 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R33\t <sentencia> ::= <bloque>");
        }
#line 1569 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 177 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R34\t <sentencia_simple> ::= <asignacion>\n");
        }
#line 1577 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 181 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R35\t <sentencia_simple> ::= <lectura>\n");
        }
#line 1585 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 185 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R36\t <sentencia_simple> ::= <escritura>\n");
        }
#line 1593 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R38\t <sentencia_simple> ::= <retorno_funcion>\n");
        }
#line 1601 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 194 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R40\t <bloque> ::= <condicional>\n");
        }
#line 1609 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 198 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R41\t <bloque> ::= <bucle>\n");
        }
#line 1617 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 203 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R43\t <asignacion> ::= <identificador> = <exp>\n");
        }
#line 1625 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, "R44\t <asignacion> ::= <elemento_vector> = <exp>\n");
        }
#line 1633 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 212 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R48\t <elemento_vector> ::= identificador[<exp>]\n");
        }
#line 1641 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 217 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R50\t <condicional> ::= if (<exp>) {<sentencias>}\n");
        }
#line 1649 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 221 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R51\t <condicional> ::= if (<exp>) {<sentencias>} then {<sentencias>}\n");
        }
#line 1657 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 226 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R52\t <bucle> ::= while (<exp>) {<sentencias>}\n");
        }
#line 1665 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 231 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R54\t <lectura> ::= scanf <identificador>\n");
        }
#line 1673 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 236 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R56\t <escritura> ::= printf <identificador>\n");
        }
#line 1681 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 241 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R61\t <retorno_funcion> ::= return <exp>\n");
        }
#line 1689 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 246 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R72\t <exp> ::= <exp> + <exp>\n");
        }
#line 1697 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 250 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R73\t <exp> ::= <exp> - <exp>\n");
        }
#line 1705 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R74\t <exp> ::= <exp> / <exp>\n");
        }
#line 1713 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 258 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R75\t <exp> ::= <exp> * <exp>\n");
        }
#line 1721 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 262 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R76\t <exp> ::= -<exp>\n");
        }
#line 1729 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 266 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R77\t <exp> ::= <exp> && <exp>\n");
        }
#line 1737 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 270 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R78\t <exp> ::= <exp> || <exp>\n");
        }
#line 1745 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 274 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R79\t <exp> ::= !<exp>\n");
        }
#line 1753 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 278 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R80\t <exp> ::= <identificador>\n");
        }
#line 1761 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 282 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R81\t <exp> ::= <constante>\n");
        }
#line 1769 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 286 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R82\t <exp> ::= (<exp>)\n");
        }
#line 1777 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 290 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R83\t <exp> ::= <comparacion>\n");
        }
#line 1785 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 294 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R85\t <exp> ::= <elemento_vector>\n");
        }
#line 1793 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 298 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R88\t <exp> ::= <identificador> (<lista_expresiones>)\n");
        }
#line 1801 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 303 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, "R89\t <lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
        }
#line 1809 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 307 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, "R90\t <lista_expresiones> ::= \n");
        }
#line 1817 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 312 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R91\t <resto_lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
        }
#line 1825 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 316 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R92\t <resto_lista_expresiones> ::= \n");
        }
#line 1833 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 321 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R93\t <comparacion> ::= <exp> == <exp>\n");
        }
#line 1841 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 325 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R94\t <comparacion> ::= <exp> != <exp>\n");
        }
#line 1849 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 329 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R95\t <comparacion> ::= <exp> <= <exp>\n");
        }
#line 1857 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 333 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R96\t <comparacion> ::= <exp> >= <exp>\n");
        }
#line 1865 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 337 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R97\t <comparacion> ::= <exp> < <exp>\n");
        }
#line 1873 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 341 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R98\t <comparacion> ::= <exp> > <exp>\n");
        }
#line 1881 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 346 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R99\t <constante> ::= <constante_logica>\n");
        }
#line 1889 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 350 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R100\t <constante> ::= <constante_entera>\n");
        }
#line 1897 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 355 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R102\t <constante_logica> ::= true\n");
        }
#line 1905 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 359 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R103\t <constante_logica> ::= false\n");
        }
#line 1913 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 364 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R104\t <constante_entera> ::= <numero>\n");
        }
#line 1921 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 369 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R105\t <numero> ::= <digito>\n");
        }
#line 1929 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 373 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R106\t <numero> ::= <numero> <digito>\n");
        }
#line 1937 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 378 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R108\t <identificador> ::= TOK_IDENTIFICADOR\n");
        }
#line 1945 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 383 "alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R115\t <digito> ::= TOK_CONSTANTE_ENTERA\t");
        }
#line 1953 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 1957 "alfa.tab.c" /* yacc.c:1646  */
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
#line 387 "alfa.y" /* yacc.c:1906  */



void yyerror(const char * error) {
    if(!error) {
        printf("****Error sintactico en [linea %d, columna %d]\n", linea, columna-yyleng);
    }
    error = 0;
}
