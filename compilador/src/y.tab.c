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
#line 1 "src/alfa.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "../inc/alfa.h"
  #include "../inc/tabla.h"



  void yyerror(const char *error);
  extern int linea ,columna;
  extern int error;
  extern FILE *yyin;
  extern FILE *salida;
  extern int yylex();
  extern int yyleng;
  extern bool invalidchar;
  extern bool longitud;

  char itoa[100];
  int cuantos_no;
  int tipoErrorSemantico = -1;
  /*Diferenciar globales y locales*/
  int ambito;

  /*Informacion de lo que estamos analizando*/
  int categoria_actual = 0;
  int clase_actual = 0;
  int tipo_actual = 0;
  int tamanio_vector_actual = 0;
  int num_variables_locales_actual = 0;
  int pos_variable_local_actual = 0;
  int num_parametros_actual = 0;
  int pos_parametro_actual = 0;
  int num_parametros_llamada_actual = 0;
  int llamada_funcion = 0;
  int return_funcion = 0;

  extern int etiqueta;


  /*Tablas de simbolos*/
  extern dataItem** tablaGlobal;
  extern dataItem** tablaLocal;

  extern dataItem** tablaActual;

  dataItem* itemActual;
  extern datainfo * infoActual;

  char nombreFuncion[100];

  int retorno=0;


#line 123 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOK_IDENTIFICADOR = 258,
    TOK_CONSTANTE_REAL = 259,
    TOK_CONSTANTE_ENTERA = 260,
    TOK_MAIN = 261,
    TOK_RETURN = 262,
    TOK_ARRAY = 263,
    TOK_INT = 264,
    TOK_BOOLEAN = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_IF = 268,
    TOK_ELSE = 269,
    TOK_WHILE = 270,
    TOK_OR = 271,
    TOK_AND = 272,
    TOK_NOT = 273,
    TOK_DISTINTO = 274,
    TOK_IGUAL = 275,
    TOK_MENOR = 276,
    TOK_MAYOR = 277,
    TOK_MENORIGUAL = 278,
    TOK_MAYORIGUAL = 279,
    TOK_COMA = 280,
    TOK_PUNTOYCOMA = 281,
    TOK_LLAVEIZQUIERDA = 282,
    TOK_LLAVEDERECHA = 283,
    TOK_CORCHETEIZQUIERDO = 284,
    TOK_CORCHETEDERECHO = 285,
    TOK_PARENTESISIZQUIERDO = 286,
    TOK_PARENTESISDERECHO = 287,
    TOK_MENOS = 288,
    TOK_MAS = 289,
    TOK_ASTERISCO = 290,
    TOK_DIVISION = 291,
    TOK_FUNCTION = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295,
    TOK_ASIGNACION = 296
  };
#endif
/* Tokens.  */
#define TOK_IDENTIFICADOR 258
#define TOK_CONSTANTE_REAL 259
#define TOK_CONSTANTE_ENTERA 260
#define TOK_MAIN 261
#define TOK_RETURN 262
#define TOK_ARRAY 263
#define TOK_INT 264
#define TOK_BOOLEAN 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_IF 268
#define TOK_ELSE 269
#define TOK_WHILE 270
#define TOK_OR 271
#define TOK_AND 272
#define TOK_NOT 273
#define TOK_DISTINTO 274
#define TOK_IGUAL 275
#define TOK_MENOR 276
#define TOK_MAYOR 277
#define TOK_MENORIGUAL 278
#define TOK_MAYORIGUAL 279
#define TOK_COMA 280
#define TOK_PUNTOYCOMA 281
#define TOK_LLAVEIZQUIERDA 282
#define TOK_LLAVEDERECHA 283
#define TOK_CORCHETEIZQUIERDO 284
#define TOK_CORCHETEDERECHO 285
#define TOK_PARENTESISIZQUIERDO 286
#define TOK_PARENTESISDERECHO 287
#define TOK_MENOS 288
#define TOK_MAS 289
#define TOK_ASTERISCO 290
#define TOK_DIVISION 291
#define TOK_FUNCTION 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295
#define TOK_ASIGNACION 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "src/alfa.y" /* yacc.c:355  */

  tipo_atributos atributos;
 

#line 250 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 267 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   144,   151,   157,   162,   163,   165,   167,
     167,   169,   176,   181,   187,   203,   204,   206,   207,   209,
     227,   244,   306,   307,   309,   310,   312,   314,   338,   339,
     341,   342,   344,   345,   347,   347,   347,   347,   349,   353,
     358,   470,   489,   590,   595,   602,   617,   623,   628,   634,
     648,   656,   733,   744,   788,   823,   830,   846,   862,   883,
     899,   913,   927,   941,   956,  1058,  1064,  1070,  1076,  1082,
    1114,  1146,  1152,  1156,  1163,  1167,  1169,  1178,  1187,  1203,
    1219,  1235,  1252,  1260,  1268,  1276,  1287,  1302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_REAL", "TOK_CONSTANTE_ENTERA", "TOK_MAIN", "TOK_RETURN",
  "TOK_ARRAY", "TOK_INT", "TOK_BOOLEAN", "TOK_SCANF", "TOK_PRINTF",
  "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_OR", "TOK_AND", "TOK_NOT",
  "TOK_DISTINTO", "TOK_IGUAL", "TOK_MENOR", "TOK_MAYOR", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_COMA", "TOK_PUNTOYCOMA", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO", "TOK_MENOS",
  "TOK_MAS", "TOK_ASTERISCO", "TOK_DIVISION", "TOK_FUNCTION", "TOK_TRUE",
  "TOK_FALSE", "TOK_ERROR", "TOK_ASIGNACION", "$accept", "programa",
  "escritura1", "escritura2", "escritura3", "declaraciones", "declaracion",
  "clase", "clase_escalar", "tipo", "clase_vector", "identificadores",
  "funciones", "funcion", "fn_declaration", "fn_name",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "idpf", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "bloque", "asignacion", "elemento_vector",
  "condicional", "if_exp", "if_exp_sentencias", "bucle",
  "while_exp_sentencias", "while_exp", "while", "lectura", "escritura",
  "retorno_funcion", "initretorno", "exp", "llamadaAFuncion",
  "lista_expresiones", "argumento", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera",
  "identificador", YY_NULLPTR
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
     295,   296
};
# endif

#define YYPACT_NINF -30

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define YYTABLE_NINF -71

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,   -19,     5,   -30,   -30,     2,    21,   -30,   -30,   -30,
       2,    13,   -30,   -30,   -30,    -6,   -18,   -30,   -30,     8,
      10,    31,    21,   -30,   -18,    34,    12,   -30,    13,    14,
      45,    34,   -30,   -27,   -30,    49,    24,    22,   -30,    28,
      34,    33,   -30,   -30,    19,   -30,    34,    47,   -30,   -30,
      34,    37,   -30,   -30,   -30,    24,    21,   -30,   -30,   -30,
      59,    24,    24,    70,   -30,    -9,   -30,    24,    24,    24,
     -30,   -30,   -30,   164,    57,   -30,   -30,   -30,   -30,    24,
     -30,   -30,   -30,    24,    72,    75,    73,    24,   164,   100,
      79,    80,   -30,    74,   164,   -30,   101,   185,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,   122,   164,   -30,    34,   -30,   143,   -30,   -30,    78,
      21,   -30,   -30,   -30,    62,    62,    43,    43,   -30,   -30,
     -30,   -30,   185,   185,   185,   185,   164,    81,    87,    89,
      86,    92,     2,    80,   -30,    24,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,    87,   -30
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,     0,    12,    13,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    87,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,     0,
       0,     0,    17,     0,    55,     0,     0,     0,    50,     0,
      30,     0,    33,    34,     0,    38,     0,    43,    39,    47,
       0,     0,    35,    36,    37,     0,    23,    16,    14,    21,
       0,     0,     0,    51,    52,    64,    86,     0,     0,     0,
      84,    85,    68,    53,     0,    67,    65,    82,    83,     0,
      19,    31,    32,     0,     0,     0,     0,     0,    54,     0,
       0,    25,     2,     0,    40,    63,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,    41,    46,     0,    48,     0,    27,    26,     0,
       0,    22,    42,    66,    62,    61,    77,    76,    80,    81,
      78,    79,    57,    56,    59,    58,    73,     0,    75,     0,
       0,     0,    29,    25,    69,     0,    71,    45,    44,    49,
      28,    20,    24,    75,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -30,   -30,   -10,   -30,   -30,   -30,    -5,
     -30,    98,   103,   -30,   -30,   -30,   -30,   -15,     9,   -30,
     -30,   -25,   -30,   -30,   -30,   -30,   -22,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -29,   -30,
     -30,   -14,   -23,   -30,   -30,   -30,   -30,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    16,    31,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    90,   121,    91,   118,
     151,    39,    40,    41,    42,    43,    72,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,   136,    74,
     137,   138,   146,    75,    76,    77,    78,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    15,    61,    44,     1,     4,    60,    73,     3,    44,
       6,     7,     8,    64,    62,    81,    18,    30,    44,    22,
      61,    84,   -70,    21,    44,    86,    88,    65,    44,    66,
       7,     8,    93,    94,    27,    28,    29,    33,    95,    96,
      97,    34,    67,    56,    58,    35,    36,    37,    59,    38,
     111,    89,    63,    79,   112,    68,    80,    69,   116,    82,
      83,    85,    70,    71,   102,   103,   104,   105,    87,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   100,   101,   102,   103,   104,   105,    92,   110,   140,
      98,    99,    44,   100,   101,   102,   103,   104,   105,    61,
     113,   115,   114,   117,   122,   142,   120,   106,   107,   108,
     109,   119,   145,   144,   148,    89,   147,    98,    99,   149,
     100,   101,   102,   103,   104,   105,    57,    32,   152,   143,
     154,   153,   150,   123,   106,   107,   108,   109,    98,    99,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,   139,   106,   107,   108,   109,    98,
      99,     0,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   141,   106,   107,   108,   109,
      98,    99,     0,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
     109,    98,    99,     0,   100,   101,   102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      10,     6,    29,    25,     6,     0,    31,    36,    27,    31,
       8,     9,    10,    35,    41,    40,     3,    22,    40,    37,
      29,    46,    31,    29,    46,    50,    55,     3,    50,     5,
       9,    10,    61,    62,    26,    25,     5,     3,    67,    68,
      69,     7,    18,    31,    30,    11,    12,    13,     3,    15,
      79,    56,     3,    31,    83,    31,    28,    33,    87,    26,
      41,    14,    38,    39,    21,    22,    23,    24,    31,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    19,    20,    21,    22,    23,    24,    28,    31,   114,
      16,    17,   114,    19,    20,    21,    22,    23,    24,    29,
      28,    28,    27,     3,    30,    27,    26,    33,    34,    35,
      36,    32,    25,    32,    28,   120,    27,    16,    17,    27,
      19,    20,    21,    22,    23,    24,    28,    24,   143,   120,
     153,   145,   142,    32,    33,    34,    35,    36,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    16,    17,    -1,    19,    20,    21,    22,    23,    24
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    43,    27,     0,    44,     8,     9,    10,    47,
      48,    49,    50,    51,    52,    51,    45,    47,     3,    53,
      89,    29,    37,    54,    55,    56,    57,    26,    25,     5,
      51,    46,    54,     3,     7,    11,    12,    13,    15,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    31,    53,    30,     3,
      63,    29,    41,     3,    68,     3,     5,    18,    31,    33,
      38,    39,    68,    80,    81,    85,    86,    87,    88,    31,
      28,    63,    26,    41,    63,    14,    63,    31,    80,    51,
      58,    60,    28,    80,    80,    80,    80,    80,    16,    17,
      19,    20,    21,    22,    23,    24,    33,    34,    35,    36,
      31,    80,    80,    28,    27,    28,    80,     3,    61,    32,
      26,    59,    30,    32,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    82,    83,    32,
      63,    32,    27,    60,    32,    25,    84,    27,    28,    27,
      47,    62,    59,    83,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    47,    47,    48,    49,
      49,    50,    51,    51,    52,    53,    53,    54,    54,    55,
      56,    57,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    63,    64,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    69,    69,    70,    71,    72,    73,    74,
      75,    76,    76,    77,    78,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    82,    82,    83,    84,    84,    85,    85,    85,    85,
      85,    85,    86,    86,    87,    87,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     1,     5,     5,     3,     1,     3,     5,
       1,     2,     2,     2,     2,     1,     3,     3,     3,     3,
       2,     3,     3,     2,     1,     1,     3,     1,     1,     4,
       1,     2,     0,     1,     3,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1
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
#line 138 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Final del fichero */
          escribir_fin(salida);
        }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 144 "src/alfa.y" /* yacc.c:1646  */
    {
          escribir_subseccion_data(salida);
          escribir_cabecera_bss(salida);

        }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "src/alfa.y" /* yacc.c:1646  */
    {
          escribir_segmento_codigo(salida);

        }
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 157 "src/alfa.y" /* yacc.c:1646  */
    {
          escribir_inicio_main(salida);
        }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Obtenemos clase */
          clase_actual = ESCALAR;
          /* Tipo se obtiene en tipo */
        }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Obtenemos tipo */
          tipo_actual = INT;
        }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 182 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Obtenemos tipo */
          tipo_actual = BOOLEAN;
        }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 188 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Obtenemos clase */
          clase_actual = VECTOR;
          tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
          categoria_actual = VARIABLE;
          if (tamanio_vector_actual>MAX_TAMANIO_VECTOR || tamanio_vector_actual<1){
            error = -1;
            tipoErrorSemantico = 2;
            yyerror ((yyvsp[-1].atributos).lexema);
            return -1;
          }

          
        }
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 210 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R22:\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
          vaciar(tablaActual);
          tablaActual = tablaGlobal;
          itemActual = buscaElemento(tablaGlobal, (yyvsp[-2].atributos).lexema);

          if(itemActual == NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
          }

          itemActual->data->num_parametros = num_parametros_actual;
        }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 228 "src/alfa.y" /* yacc.c:1646  */
    {
          itemActual = buscaElemento(tablaLocal, (yyvsp[-5].atributos).lexema);

          if(itemActual == NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror((yyvsp[-5].atributos).lexema);
              return -1;
          }
          itemActual->data->num_parametros = num_parametros_actual;

          strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);

          declararFuncion(salida, (yyvsp[-5].atributos).lexema, num_variables_locales_actual);
        }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 245 "src/alfa.y" /* yacc.c:1646  */
    {
          return_funcion = 0;
          itemActual = buscaElemento(tablaActual, (yyvsp[0].atributos).lexema);

          if(itemActual != NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
          }
          else{
            strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
            categoria_actual = FUNCION;
            clase_actual = ESCALAR;
            num_variables_locales_actual = 0;
            pos_variable_local_actual = 0;
            num_parametros_actual = 0;
            pos_parametro_actual = 0;


            infoActual = malloc(sizeof(datainfo));
            infoActual->categoria = FUNCION;
            infoActual->clase = clase_actual;
            infoActual->tipo = tipo_actual;
            infoActual->tamanio_vector = tamanio_vector_actual;
            infoActual->num_variables_locales = num_variables_locales_actual;
            infoActual->pos_variable_local = pos_variable_local_actual;
            infoActual->num_parametros = num_parametros_actual;
            infoActual->pos_parametro = pos_parametro_actual;            

            if(!insertaElemento(tablaActual, (yyvsp[0].atributos).lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }

            tablaActual = tablaLocal;
            infoActual = malloc(sizeof(datainfo));
            infoActual->categoria = FUNCION;
            infoActual->clase = clase_actual;
            infoActual->tipo = tipo_actual;
            infoActual->tamanio_vector = tamanio_vector_actual;
            infoActual->num_variables_locales = num_variables_locales_actual;
            infoActual->pos_variable_local = pos_variable_local_actual;
            infoActual->num_parametros = num_parametros_actual;
            infoActual->pos_parametro = pos_parametro_actual;

            if(!insertaElemento(tablaActual, (yyvsp[0].atributos).lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }

            categoria_actual = 0;
            clase_actual = 0;
            tipo_actual = 0;
          }
        }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 315 "src/alfa.y" /* yacc.c:1646  */
    {

          infoActual = malloc(sizeof(datainfo));
          infoActual->categoria = categoria_actual;
          infoActual->clase = clase_actual;
          infoActual->tipo = tipo_actual;
          infoActual->tamanio_vector = tamanio_vector_actual;
          infoActual->num_variables_locales = num_variables_locales_actual;
          infoActual->pos_variable_local = pos_variable_local_actual;
          infoActual->num_parametros = ++num_parametros_actual;
          infoActual->pos_parametro = pos_parametro_actual++;

          if(!insertaElemento(tablaLocal, (yyvsp[0].atributos).lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
          }


          strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
        }
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 350 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R40:\t<bloque> ::= <condicional>\n");
        }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 354 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R41:\t<bloque> ::= <bucle>\n");
        }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 359 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R43:\t<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>\n");
          
          if(tablaActual == tablaGlobal){
            
            itemActual = buscaElemento(tablaGlobal, (yyvsp[-2].atributos).lexema);
            if(itemActual == NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }
            

            else if (itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else if(itemActual->data->clase == VECTOR){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else if(itemActual->data->tipo != (yyvsp[0].atributos).tipo){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else{
              (yyvsp[-2].atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
              asignar(salida, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
            }
          }

          else{
            itemActual = buscaElemento(tablaLocal, (yyvsp[-2].atributos).lexema);
            if(itemActual == NULL){
              itemActual = buscaElemento(tablaGlobal, (yyvsp[-2].atributos).lexema);
              if(itemActual == NULL){
                error = -1;
                tipoErrorSemantico = 1;
                yyerror((yyvsp[-2].atributos).lexema);
                return -1;
              }

              else if (itemActual->data->categoria == FUNCION){
                error = -1;
                tipoErrorSemantico = 8;
                yyerror((yyvsp[-2].atributos).lexema);
                return -1;
              }

              else if(itemActual->data->clase == VECTOR){
                error = -1;
                tipoErrorSemantico = 8;
                yyerror((yyvsp[-2].atributos).lexema);
                return -1;
              }

              else if(itemActual->data->tipo != (yyvsp[0].atributos).tipo){
                error = -1;
                tipoErrorSemantico = 8;
                yyerror((yyvsp[-2].atributos).lexema);
                return -1;
              }

              else{
                (yyvsp[-2].atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                asignar(salida, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
              }
            }

            else if (itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else if(itemActual->data->clase == VECTOR){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else if(itemActual->data->tipo != (yyvsp[0].atributos).tipo){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[-2].atributos).lexema);
              return -1;
            }

            else{
              (yyvsp[-2].atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
			        asignarIdentLocal(salida, (yyvsp[0].atributos).es_direccion);
            }
          }
          



        }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 471 "src/alfa.y" /* yacc.c:1646  */
    {
          
          if((yyvsp[0].atributos).tipo!=(yyvsp[-2].atributos).tipo)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror("vector");
            return -1;
          }
          if(categoria_actual==FUNCION){
            asignarElemVec(salida, 1);
          } else{
            asignarElemVec(salida, 0);
          }          
          fprintf(salida, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
          categoria_actual = 0;
        }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 490 "src/alfa.y" /* yacc.c:1646  */
    {
          if(tablaActual == tablaGlobal){
            itemActual = NULL;
            itemActual = buscaElemento(tablaGlobal, (yyvsp[-3].atributos).lexema);

            if (itemActual==NULL){
              error = -1;
              tipoErrorSemantico=1;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }            

            if (itemActual->data->categoria==FUNCION){
              error = -1;
              tipoErrorSemantico=9;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }
            if (itemActual->data->clase!=VECTOR){
              error = -1;
              tipoErrorSemantico=9;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }

            if((yyvsp[-1].atributos).tipo!=INT){
              error = -1;
              tipoErrorSemantico=10;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }
            (yyval.atributos).es_direccion=1;
            strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
            (yyval.atributos).tipo = itemActual->data->tipo;
            escribir_elemento_vector(salida, (yyvsp[-3].atributos).lexema, itemActual->data->tamanio_vector, (yyvsp[-3].atributos).es_direccion);
          }
          else{
            itemActual = buscaElemento(tablaLocal, (yyvsp[-3].atributos).lexema);
            if (itemActual==NULL){
              itemActual = buscaElemento(tablaGlobal, (yyvsp[-3].atributos).lexema);
              if (itemActual==NULL){
                error = -1;
                tipoErrorSemantico=1;
                yyerror((yyvsp[-3].atributos).lexema);
                return -1;
              }

              if (itemActual->data->categoria==FUNCION){
                error = -1;
                tipoErrorSemantico=9;
                yyerror((yyvsp[-3].atributos).lexema);
                return -1;
              }
              
              if (itemActual->data->clase!=VECTOR){
                error = -1;
                tipoErrorSemantico=9;
                yyerror((yyvsp[-3].atributos).lexema);
                return -1;
              }

              if((yyvsp[-1].atributos).tipo!=INT){
                error = -1;
                tipoErrorSemantico=10;
                yyerror((yyvsp[-3].atributos).lexema);
                return -1;
              }
              (yyval.atributos).es_direccion=1;
              strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
              (yyval.atributos).tipo = itemActual->data->tipo;
              escribir_elemento_vector(salida, (yyvsp[-3].atributos).lexema, itemActual->data->tamanio_vector, (yyvsp[-3].atributos).es_direccion);
              }

              if (itemActual->data->categoria==FUNCION){
              error = -1;
              tipoErrorSemantico=9;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }
            if (itemActual->data->clase!=VECTOR){
              error = -1;
              tipoErrorSemantico=9;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }

            if((yyvsp[-1].atributos).tipo!=INT){
              error = -1;
              tipoErrorSemantico=10;
              yyerror((yyvsp[-3].atributos).lexema);
              return -1;
            }
            (yyval.atributos).es_direccion=1;
            strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
            (yyval.atributos).tipo = itemActual->data->tipo;
            escribir_elemento_vector(salida, (yyvsp[-3].atributos).lexema, itemActual->data->tamanio_vector, (yyvsp[-3].atributos).es_direccion);
          }
          fprintf(salida, ";R48:\t<elemento_vector> ::= TOK_IDENTIFICADOR[<exp>]\n");
        }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 591 "src/alfa.y" /* yacc.c:1646  */
    {
          ifthenelse_fin(salida, (yyvsp[0].atributos).etiqueta);
          fprintf(salida, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
        }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 596 "src/alfa.y" /* yacc.c:1646  */
    {
          ifthenelse_fin(salida, (yyvsp[-4].atributos).etiqueta);
          fprintf(salida, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} then {<sentencias>}\n");
        }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 603 "src/alfa.y" /* yacc.c:1646  */
    {

          if((yyvsp[-2].atributos).tipo != BOOLEAN){
            error = -1;
            tipoErrorSemantico = 5;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          else {
            (yyval.atributos).etiqueta = etiqueta++;
            ifthen_inicio(salida, (yyvsp[-2].atributos).es_direccion?1:0, (yyval.atributos).etiqueta);
          }
        }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 618 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
          ifthenelse_fin_then(salida, (yyvsp[-2].atributos).etiqueta);
        }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 624 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
        }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 629 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
          while_fin(salida, (yyvsp[-2].atributos).etiqueta);
        }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 635 "src/alfa.y" /* yacc.c:1646  */
    {
          if((yyvsp[-2].atributos).tipo != BOOLEAN){
            error = -1;
            tipoErrorSemantico = 6;
            yyerror((yyvsp[-4].atributos).lexema);
            return -1;
          }
          else {
            (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta;
            while_exp_pila(salida, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
          }
        }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 649 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).etiqueta = etiqueta++;
          while_inicio(salida, (yyval.atributos).etiqueta);
        }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 657 "src/alfa.y" /* yacc.c:1646  */
    {

          if(tablaActual==tablaGlobal){
            itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);
            if(!itemActual){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 0;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            else if(itemActual->data->clase != ESCALAR){
              error = -1;
              tipoErrorSemantico = 0;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            else{
              leer(salida, itemActual->lexema, itemActual->data->tipo);
            }
          }

          else{

            itemActual = buscaElemento(tablaLocal, (yyvsp[0].atributos).lexema);
            if(!itemActual){
              itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);
              if(!itemActual){
                error = -1;
                tipoErrorSemantico = 1;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              else if(itemActual->data->categoria == FUNCION){
                error = -1;
                tipoErrorSemantico = 0;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              else if(itemActual->data->clase != ESCALAR){
                error = -1;
                tipoErrorSemantico = 0;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              else{
                leer(salida, itemActual->lexema, itemActual->data->tipo);
              }
            }
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 0;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            else if(itemActual->data->clase != ESCALAR){
              error = -1;
              tipoErrorSemantico = 0;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            else{
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
              escribirScanfFuncion(salida, itemActual->data->tipo);
            }

          }

          
          /*fprintf(salida, ";R54:\t<lectura> ::= scanf <TOK_IDENTIFICADOR>\n");*/
        }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 734 "src/alfa.y" /* yacc.c:1646  */
    {
          if(categoria_actual==FUNCION){
            asignarElemVec(salida, 1);
          } else{
            asignarElemVec(salida, 0);
          }          
          fprintf(salida, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
          categoria_actual = 0;
        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 745 "src/alfa.y" /* yacc.c:1646  */
    {
          fprintf(salida, ";R56:\t<escritura> ::= printf <exp>\n");
        
          if((yyvsp[0].atributos).es_direccion){
            if(tablaActual == tablaGlobal){
              itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);
              if(!itemActual){
                error = -1;
                tipoErrorSemantico = 1;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              escribir(salida, 1, itemActual->data->tipo);
            } 
          
            else
            {
              itemActual = buscaElemento(tablaLocal, (yyvsp[0].atributos).lexema);
              if(!itemActual){

                itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);
                if(!itemActual){
                  error = -1;
                  tipoErrorSemantico = 1;
                  yyerror((yyvsp[0].atributos).lexema);
                  return -1;
                }
                escribir(salida, 1, itemActual->data->tipo);
              } else{
                escribir(salida, 1, itemActual->data->tipo);
              }
              
            }
            
            
          } else{
            escribir(salida, 0, (yyvsp[0].atributos).tipo);
          }
          

        }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 789 "src/alfa.y" /* yacc.c:1646  */
    {

          if((yyvsp[0].atributos).es_direccion){
            if(tablaLocal==tablaGlobal)
            {
              error=-1;
              tipoErrorSemantico=11;
              yyerror("\n");
              return -1;
            }
            itemActual = buscaElemento(tablaLocal, (yyvsp[0].atributos).lexema);
            
            if(itemActual == NULL)
            {
              error=-1;
              tipoErrorSemantico=1;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }

            if((yyvsp[0].atributos).tipo!=itemActual->data->tipo)
            {
              error=-1;
              tipoErrorSemantico=8;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            
            
          }
          retornarFuncion(salida, (yyvsp[0].atributos).es_direccion);
          retorno = 0;
        }
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 824 "src/alfa.y" /* yacc.c:1646  */
    {
          retorno = 1;
        }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 831 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Sumamos las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
          error = -1;
          tipoErrorSemantico = 3;
          yyerror((yyvsp[-2].atributos).lexema);
          return -1;
          }
          else if ((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            sumar(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
            (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero + (yyvsp[0].atributos).valor_entero;
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion=0;
          }
        }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 847 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Restamos las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          else if((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            restar(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
            (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero - (yyvsp[0].atributos).valor_entero;
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion=0;
          }
        }
#line 2259 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 863 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Dividimos las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          else if((yyvsp[0].atributos).valor_entero == 0){
            error = -1;
            yyerror("Division entre 0");
            return -1;
          }
          else if((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            dividir(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
            (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero / (yyvsp[0].atributos).valor_entero;
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion=0;
          }
        }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 884 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Multiplicamos las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == BOOLEAN || (yyvsp[0].atributos).tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          else if((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            multiplicar(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
            (yyval.atributos).valor_entero = (yyvsp[-2].atributos).valor_entero * (yyvsp[0].atributos).valor_entero;
            (yyval.atributos).tipo = INT;
            (yyval.atributos).es_direccion=0;
          }
        }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 900 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Multiplicamos por -1 la expresion */
          if ((yyvsp[0].atributos).tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }
          cambiar_signo(salida, (yyvsp[0].atributos).es_direccion);
          (yyval.atributos).valor_entero = -1 * (yyvsp[0].atributos).valor_entero;
          (yyval.atributos).tipo = INT;
          (yyval.atributos).es_direccion=0;
        }
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 914 "src/alfa.y" /* yacc.c:1646  */
    {
          /* AND LOGICO entre las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          y(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion=0;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 928 "src/alfa.y" /* yacc.c:1646  */
    {
          /* OR LOGICO entre las dos expresiones */
          if ((yyvsp[-2].atributos).tipo == INT || (yyvsp[0].atributos).tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror((yyvsp[-2].atributos).lexema);
            return -1;
          }
          o(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion=0;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 942 "src/alfa.y" /* yacc.c:1646  */
    {
          /* NEGAMOS la expresion (logica) */
          if ((yyvsp[0].atributos).tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }
          no(salida, (yyvsp[0].atributos).es_direccion, cuantos_no);
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion=0;
          cuantos_no++;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 957 "src/alfa.y" /* yacc.c:1646  */
    {
          

          if(tablaActual==tablaGlobal){
            itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);

            /*Si no lo encuentra error*/
            if (itemActual == NULL){
              error=-1;
              tipoErrorSemantico=1;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            /*Si categoria es funicon error*/
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            /*CORRECTO*/
            else {
              
              (yyval.atributos).tipo = itemActual->data->tipo;
              
              (yyval.atributos).es_direccion = 1;
              (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
              strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
              
              categoria_actual = itemActual->data->categoria;




              /* Asignamos valor */
              escribir_operando(salida, (yyvsp[0].atributos).lexema, (yyval.atributos).es_direccion);
            }
            /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/
          }



          else{

            itemActual = buscaElemento(tablaLocal, (yyvsp[0].atributos).lexema);

            /*Si no lo encuentra error*/
            if (itemActual == NULL){
              itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);

              /*Si no lo encuentra error*/
              if (itemActual == NULL){
                error=-1;
                tipoErrorSemantico=1;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              /*Si categoria es funicon error*/
              else if(itemActual->data->categoria == FUNCION){
                error = -1;
                tipoErrorSemantico = 8;
                yyerror((yyvsp[0].atributos).lexema);
                return -1;
              }
              /*CORRECTO*/
              else {
                (yyval.atributos).tipo = itemActual->data->tipo;
                
                (yyval.atributos).es_direccion = 1;
                (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                categoria_actual = itemActual->data->categoria;
                

                /* Asignamos valor */
                escribir_operando(salida, itemActual->lexema, (yyval.atributos).es_direccion);
              }
            }
            /*Si categoria es funicon error*/
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror((yyvsp[0].atributos).lexema);
              return -1;
            }
            /*CORRECTO*/
            else {
              (yyval.atributos).tipo = itemActual->data->tipo;
              (yyval.atributos).es_direccion = 1;
              (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
              categoria_actual = itemActual->data->categoria;


              /* Asignamos valor */
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
            }
            /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/

          }
        }
#line 2481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1059 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
          fprintf(salida, ";R81:\t<exp> ::= <constante>\n");
        }
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1065 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R82:\t<exp> ::= (<exp>)\n");*/
          (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
        }
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1071 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R83:\t<exp> ::= <comparacion>\n");*/
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        }
#line 2511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1077 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
          fprintf(salida, ";R85:\t<exp> ::= <elemento_vector>\n");
        }
#line 2521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1083 "src/alfa.y" /* yacc.c:1646  */
    {

          itemActual = buscaElemento(tablaGlobal, (yyvsp[-3].atributos).lexema);
          if(itemActual == NULL)
          {
            error=-1;
            tipoErrorSemantico=1;
            yyerror((yyvsp[-3].atributos).lexema);
            return -1;
          }
          if(itemActual->data->categoria != FUNCION)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror((yyvsp[-3].atributos).lexema);
            return -1;
          }
          if(itemActual->data->num_parametros != num_parametros_llamada_actual){
            error=-1;
            tipoErrorSemantico=7;
            yyerror((yyvsp[-3].atributos).lexema);
            return -1;
          }
          
          fprintf(salida, ";R88:\t<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)\n");
          llamarFuncion(salida, (yyvsp[-3].atributos).lexema, 1);
          categoria_actual = FUNCION;
          llamada_funcion = 0;
        }
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1115 "src/alfa.y" /* yacc.c:1646  */
    {
          itemActual = buscaElemento(tablaGlobal, (yyvsp[0].atributos).lexema);
          if(itemActual == NULL)
          {
            error=-1;
            tipoErrorSemantico=1;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }
          if(itemActual->data->categoria != FUNCION)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }
          if(llamada_funcion) {
            error = -1;
            tipoErrorSemantico = 12;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }
          llamada_funcion = 1;
          num_parametros_llamada_actual=0;
          strcpy((yyval.atributos).lexema,(yyvsp[0].atributos).lexema);
          (yyval.atributos).tipo = itemActual->data->tipo;
          
          
        }
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1147 "src/alfa.y" /* yacc.c:1646  */
    {
          llamada_funcion = 0;
          num_parametros_llamada_actual++;
        }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1152 "src/alfa.y" /* yacc.c:1646  */
    {
          llamada_funcion = 0;
        }
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1157 "src/alfa.y" /* yacc.c:1646  */
    {
  if((yyvsp[0].atributos).es_direccion){
    argumentoFuncionVariable(salida);
  }
}
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1164 "src/alfa.y" /* yacc.c:1646  */
    {
          num_parametros_llamada_actual++;
        }
#line 2624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1170 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R93:\t<comparacion> ::= <exp> == <exp>\n");*/
          
          igual(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
          etiqueta++;
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion = 0;
        }
#line 2637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1179 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R94:\t<comparacion> ::= <exp> != <exp>\n");*/
          
          distinto(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
          etiqueta++;
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion = 0;
        }
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1188 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");*/
          if (((yyvsp[-2].atributos).tipo == INT) && ((yyvsp[0].atributos).tipo == INT)){
              menor_igual(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
              etiqueta++;
              (yyval.atributos).tipo = BOOLEAN;
              (yyval.atributos).es_direccion = 0;
          }else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1204 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");*/
          if (((yyvsp[-2].atributos).tipo == INT) && ((yyvsp[0].atributos).tipo == INT)){
              mayor_igual(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
              etiqueta++;
              (yyval.atributos).tipo = BOOLEAN;
              (yyval.atributos).es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
#line 2690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1220 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R97:\t<comparacion> ::= <exp> < <exp>\n");*/
          if (((yyvsp[-2].atributos).tipo == INT) && ((yyvsp[0].atributos).tipo == INT)){
              menor(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
              etiqueta++;
              (yyval.atributos).tipo = BOOLEAN;
              (yyval.atributos).es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1236 "src/alfa.y" /* yacc.c:1646  */
    {
          /*fprintf(salida, ";R98:\t<comparacion> ::= <exp> > <exp>\n");*/
          if (((yyvsp[-2].atributos).tipo == INT) && ((yyvsp[0].atributos).tipo == INT)){
              mayor(salida, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
              etiqueta++;
              (yyval.atributos).tipo = BOOLEAN;
              (yyval.atributos).es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1253 "src/alfa.y" /* yacc.c:1646  */
    {
          clase_actual = ESCALAR;
          categoria_actual = VARIABLE;
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
          
        }
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1261 "src/alfa.y" /* yacc.c:1646  */
    {
          clase_actual = ESCALAR;
          categoria_actual = VARIABLE;
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        }
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1269 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).valor_entero = 1;
          (yyval.atributos).es_direccion = 0;
          
          escribir_operando(salida, "1", (yyval.atributos).es_direccion);
        }
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1277 "src/alfa.y" /* yacc.c:1646  */
    {
          (yyval.atributos).tipo = BOOLEAN;
          (yyval.atributos).es_direccion = 0;
          escribir_operando(salida, "0", (yyval.atributos).es_direccion);
        }
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1288 "src/alfa.y" /* yacc.c:1646  */
    {
          /* Sintesis del valor */
          (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
          (yyval.atributos).tipo = INT;
          (yyval.atributos).es_direccion = 0;
          

          /* Transformamos entero a string para adaptarnos al formato de generacion */
          sprintf(itoa, "%d", (yyvsp[0].atributos).valor_entero);

          /* Asignamos valor */
          escribir_operando(salida, itoa, (yyval.atributos).es_direccion);
        }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1303 "src/alfa.y" /* yacc.c:1646  */
    {
          if(tablaActual==tablaLocal){
            pos_variable_local_actual++;
            num_variables_locales_actual++;
          }

          categoria_actual = VARIABLE;
          if(tablaActual == tablaGlobal)
          declarar_variable(salida, (yyvsp[0].atributos).lexema, tipo_actual, 1);
          infoActual = malloc(sizeof(datainfo));
          infoActual->categoria = categoria_actual;
          infoActual->clase = clase_actual;
          infoActual->tipo = tipo_actual;
          infoActual->tamanio_vector = tamanio_vector_actual;
          infoActual->num_variables_locales = num_variables_locales_actual;
          infoActual->pos_variable_local = pos_variable_local_actual;
          infoActual->num_parametros = num_parametros_actual;
          infoActual->pos_parametro = pos_parametro_actual;

          if(!insertaElemento(tablaActual, (yyvsp[0].atributos).lexema, infoActual)){
            error = -1;
            tipoErrorSemantico = 13;
            yyerror((yyvsp[0].atributos).lexema);
            return -1;
          }

          categoria_actual = 0;
        }
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2830 "y.tab.c" /* yacc.c:1646  */
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
#line 1333 "src/alfa.y" /* yacc.c:1906  */



void yyerror(const char * perror) {
printf("%d\n", error);
    if(error==-1) {
    if (tipoErrorSemantico==0)
    			fprintf(stderr,"****Error semantico en lin %d: %s\n",linea,perror);
    		else if (tipoErrorSemantico==1)
    			fprintf(stderr,"****Error semantico en lin %d: Acceso a variable no declarada (%s).\n",linea,perror);
    		else if (tipoErrorSemantico==2)
    			fprintf(stderr,"****Error semantico en lin %d: El tamanyo del vector <%s> excede los limites permitidos (1,64).\n",linea,perror);
        else if(tipoErrorSemantico==3)
          fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
        else if (tipoErrorSemantico==4)
          fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", linea);
        else if (tipoErrorSemantico==5)
          fprintf(stderr, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", linea);
        else if (tipoErrorSemantico==6)
          fprintf(stderr, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", linea);
        else if (tipoErrorSemantico==7)
          fprintf(stderr, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", linea);
        else if (tipoErrorSemantico==8)
          fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
        else if (tipoErrorSemantico==9)
          fprintf(stderr, "****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
        else if (tipoErrorSemantico==10)
          fprintf(stderr, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero\n", linea);
        else if (tipoErrorSemantico==11)
          fprintf(stderr, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una función.\n", linea);
        else if (tipoErrorSemantico==12)
          fprintf(stderr, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
        else if (tipoErrorSemantico==13){
          fprintf(stderr, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
        }
    		else
    			fprintf(stderr,"****Error semantico en lin %d: Funcion <%s> sin sentencia de retorno.\n",linea,perror);
    }
    else if (error == 0){
      fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", linea, columna-1);
    }
    error = 0;
    fclose(salida);

    liberaTabla(tablaLocal);
    liberaTabla(tablaGlobal);
    error = 0;
}
