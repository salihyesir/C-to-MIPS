/* A Bison parser, made by GNU Bison 3.3.1.  */

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
#define YYBISON_VERSION "3.3.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../bisonFiles/parser.y" /* yacc.c:337  */

#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include<stdio.h> 
#include<string.h> 

#include <map>
#include <string>
#include<fstream>
using namespace std;
extern int yylex(void);
extern int yylineno;
extern char* yytext;
void yyerror(char const*);	

struct Node
{
	int reg;
	int type;
	int value;
};
using namespace std;

ofstream sonuc; 
//.data alanını yazmak için
void data();
//hafıdan ilk boş olan yeri almak için
int hafizadan_al();
void hafizadan_sil(int);
void hafizayi_bosalt();
void arttir_azalt(char*,int,int,bool,char);

//tahsis işlemleri(int dizi char )içerisinde tip değişken kontrolü la li vs işlemler
void atama(string,int,int,int,int,int);
//temp
Node h_yukle(char*,int,int,int);

//add sub mult div seq sle slt sge sgt or and seq mtc1 cvt
//string işlem tipini belirler
Node islemler(int,int,string,int,int);


char temp[20]; //cout için kullanıldı. art azlt

int hafiza[1000];
//node f ve atama içeirisinde type a göre li ikinci kısımda kullan
//dizi için 4 int 1 char 
int size[3]={4,1};
map <string,int> type_map;
map <string,int> size_map;



#line 125 "parser.tab.c" /* yacc.c:337  */
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
# define YYERROR_VERBOSE 0
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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOPLA = 258,
    CIKAR = 259,
    CARP = 260,
    BOL = 261,
    MOD = 262,
    ESIT = 263,
    ARTTIR = 264,
    AZALT = 265,
    ESIT_MI = 266,
    ESITDEGIL_MI = 267,
    GT = 268,
    LT = 269,
    GTE = 270,
    LTE = 271,
    VEYA = 272,
    VE = 273,
    DEGIL = 274,
    B_OR = 275,
    B_AND = 276,
    B_XOR = 277,
    SOLPARANTEZ = 278,
    SAGPARANTEZ = 279,
    KOSELISOLPAR = 280,
    KOSELISAGPAR = 281,
    SOLSUSLUPAR = 282,
    SAGSUSLUPAR = 283,
    VIRGUL = 284,
    NOKTALIVIRGUL = 285,
    NOKTA = 286,
    IKINOKTA = 287,
    ELSE = 288,
    ERROR = 289,
    STRING_CONSTANT = 290,
    TIRNAK = 291,
    SAYI = 292,
    ID = 293,
    KARAKTER = 294,
    DATATYPE = 295,
    MAIN = 296,
    FOR = 297,
    WHILE = 298,
    IF = 299,
    EIF = 300,
    COUT = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 55 "../bisonFiles/parser.y" /* yacc.c:352  */

	struct Node
	{
		int reg;
		int type;
	}node;
	int type_val;
	char str[500];//sayı id char,,

#line 225 "parser.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  154

#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    76,    77,    79,    80,    81,    82,    82,
      88,    92,    88,    97,    99,   101,   103,   105,    97,   110,
     112,   110,   118,   127,   128,   156,   158,   160,   163,   169,
     173,   174,   176,   178,   180,   184,   186,   188,   190,   192,
     194,   196,   198,   200,   202,   204,   206,   208,   210,   212,
     214,   216,   218,   221,   222,   223,   224,   226,   228,   229,
     231,   233,   235,   237,   239,   244,   247,   250,   253,   257,
     260,   263,   266,   270,   271
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOPLA", "CIKAR", "CARP", "BOL", "MOD",
  "ESIT", "ARTTIR", "AZALT", "ESIT_MI", "ESITDEGIL_MI", "GT", "LT", "GTE",
  "LTE", "VEYA", "VE", "DEGIL", "B_OR", "B_AND", "B_XOR", "SOLPARANTEZ",
  "SAGPARANTEZ", "KOSELISOLPAR", "KOSELISAGPAR", "SOLSUSLUPAR",
  "SAGSUSLUPAR", "VIRGUL", "NOKTALIVIRGUL", "NOKTA", "IKINOKTA", "ELSE",
  "ERROR", "STRING_CONSTANT", "TIRNAK", "SAYI", "ID", "KARAKTER",
  "DATATYPE", "MAIN", "FOR", "WHILE", "IF", "EIF", "COUT", "$accept", "s",
  "stm_list", "stm", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "simple_stm", "r_ifade", "sr_ifade", "ifade",
  "term", "factor", "artrazlt", "p_artrazlt", "temp_id", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -34

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-34)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,     3,    28,     2,    79,    40,    -6,    53,   -34,    75,
      95,    -1,    81,   -34,     2,   104,   -34,   -34,   -34,   116,
      73,   -34,   -34,    73,    -2,    85,    65,   123,    73,    73,
     134,   -34,   -34,   -34,   -34,   -28,   -10,    56,    76,    73,
      29,    10,   -34,    84,   142,   117,   136,   -34,   -34,   -34,
       7,    73,   112,   124,   -34,    73,    38,    84,    12,   -34,
     125,   -34,   -34,   -34,    76,   136,   -34,   109,   -34,   -34,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    76,
      76,    76,    76,    76,    76,    76,    76,   157,    84,   140,
       2,   137,    84,   -34,   144,   131,   132,    54,   141,   -34,
     -34,    99,   142,   142,   117,   117,   117,   117,   117,   117,
     136,   136,   136,   136,   136,   -34,   -34,   -34,    73,   -34,
     145,    73,   148,    27,    27,   -34,   -34,   -34,   -34,    73,
     -34,   -34,   -34,    84,   -34,    84,    27,   -34,   -34,   114,
     146,   -34,   147,   149,   -34,    27,   -34,    65,   -34,   -34,
     150,   -34,    27,   -34
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     4,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     2,     4,     0,    30,    66,    65,     0,
       0,    68,    67,     0,    27,     0,    31,     0,     0,     0,
       0,     1,     3,     5,     7,     0,     0,     0,     0,     0,
      53,    73,    64,    25,    34,    41,    48,    52,    58,    55,
       0,     0,     0,     0,    13,     0,     0,    19,     0,    56,
      73,    57,    60,    59,     0,    47,    52,     0,    62,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       4,     0,    11,     8,     0,     0,     0,     0,     0,    63,
      54,     0,    32,    33,    35,    36,    38,    37,    40,    39,
      42,    43,    45,    44,    46,    49,    50,    51,     0,    29,
       0,     0,     0,    31,    31,    70,    69,    72,    71,     0,
      22,    23,    74,    26,     6,    14,    31,     9,    20,     0,
       0,    12,     0,     0,    15,    31,    24,    31,    21,    16,
       0,    17,    31,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,     1,   -17,   -34,   -34,   -34,   -34,   -34,   -34,
     -34,   -34,   -34,   -34,   -25,   -21,    58,    86,   -22,   -33,
       0,   -34,   143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,   123,    27,   122,    91,   140,   147,
     150,   152,    94,   142,    15,    43,    44,    45,    46,    47,
      48,    98,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      16,    54,    50,    16,    19,    66,    51,    56,    57,    59,
      60,     1,     2,    30,    16,    32,    65,    25,    67,    21,
      22,    95,    96,    52,    71,    72,    16,    62,    17,     3,
      88,    99,   -31,    87,    92,    70,     1,     2,    68,    69,
       4,    17,     5,     6,     7,     8,     9,    10,    11,   101,
      97,   115,   116,   117,     3,    71,    72,   110,   111,   112,
     113,   114,    93,   127,   128,     4,    18,     5,     6,     7,
       8,     9,    10,    11,     1,     2,    26,    35,    24,   129,
      35,    31,    36,    37,   130,    36,    37,    20,    21,    22,
      16,   120,    38,    63,    18,    64,    39,   133,    28,    39,
     135,    71,    72,     4,    23,     5,   137,   138,   139,    53,
      40,    41,    42,    40,    41,    42,    71,    72,    29,   141,
      79,    80,   149,    16,    16,   132,    71,    72,   148,   102,
     103,    71,    72,   100,    33,   153,    16,    81,    82,    83,
     143,    84,    85,    86,    34,    16,    55,    16,    58,    89,
      70,    90,    16,    73,    74,    75,    76,    77,    78,   104,
     105,   106,   107,   108,   109,   118,   119,   121,   124,   125,
     126,   131,   136,   134,   151,     0,   144,     0,    61,   146,
     145
};

static const yytype_int16 yycheck[] =
{
       0,    26,    23,     3,     3,    38,     8,    28,    29,    37,
      38,     9,    10,    14,    14,    14,    38,    23,    39,     9,
      10,     9,    10,    25,    17,    18,    26,    37,    38,    27,
      51,    64,    30,    26,    55,    25,     9,    10,     9,    10,
      38,    38,    40,    41,    42,    43,    44,    45,    46,    70,
      38,    84,    85,    86,    27,    17,    18,    79,    80,    81,
      82,    83,    24,     9,    10,    38,    38,    40,    41,    42,
      43,    44,    45,    46,     9,    10,    23,     4,    38,    25,
       4,     0,     9,    10,    30,     9,    10,     8,     9,    10,
      90,    90,    19,    37,    38,    19,    23,   118,    23,    23,
     121,    17,    18,    38,    25,    40,   123,   124,   129,    24,
      37,    38,    39,    37,    38,    39,    17,    18,    23,   136,
       3,     4,   147,   123,   124,    26,    17,    18,   145,    71,
      72,    17,    18,    24,    30,   152,   136,    20,    21,    22,
      26,     5,     6,     7,    28,   145,    23,   147,    14,    37,
      25,    27,   152,    11,    12,    13,    14,    15,    16,    73,
      74,    75,    76,    77,    78,     8,    26,    30,    24,    38,
      38,    30,    24,    28,    24,    -1,    30,    -1,    35,    30,
      33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    10,    27,    38,    40,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    61,    67,    38,    38,    49,
       8,     9,    10,    25,    38,    23,    23,    52,    23,    23,
      14,     0,    49,    30,    28,     4,     9,    10,    19,    23,
      37,    38,    39,    62,    63,    64,    65,    66,    67,    69,
      62,     8,    25,    24,    61,    23,    62,    62,    14,    37,
      38,    69,    37,    37,    19,    65,    66,    62,     9,    10,
      25,    17,    18,    11,    12,    13,    14,    15,    16,     3,
       4,    20,    21,    22,     5,     6,     7,    26,    62,    37,
      27,    54,    62,    24,    59,     9,    10,    38,    68,    66,
      24,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    66,    66,    66,     8,    26,
      49,    30,    53,    51,    24,    38,    38,     9,    10,    25,
      30,    30,    26,    62,    28,    62,    24,    50,    50,    62,
      55,    50,    60,    26,    30,    33,    30,    56,    50,    61,
      57,    24,    58,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    50,
      52,    53,    50,    54,    55,    56,    57,    58,    50,    59,
      60,    50,    50,    50,    50,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     6,     3,     0,     6,
       0,     0,     7,     0,     0,     0,     0,     0,    14,     0,
       0,     9,     5,     5,     8,     3,     6,     2,     4,     5,
       1,     0,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     1,     1,     3,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     4
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
        case 3:
#line 76 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {}
#line 1428 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 77 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {}
#line 1434 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 80 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {/*cout<<"\tjr  $ra"<<endl; sonuc<<"\tjr  $ra"<<endl;*/}
#line 1440 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 81 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {}
#line 1446 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 82 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			cout<<"\tbeq $t"<<(yyvsp[-1].node).reg<<",$zero,end_"<<(yyvsp[-3].type_val)<<endl;hafizadan_sil((yyvsp[-1].node).reg);
	  	sonuc<<"\tbeq $t"<<(yyvsp[-1].node).reg<<",$zero,end_"<<(yyvsp[-3].type_val)<<endl;hafizadan_sil((yyvsp[-1].node).reg);}
#line 1454 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 84 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
				cout<<"\tj end_"<<(yyvsp[-5].type_val)<<endl;sonuc<<"\tj end_"<<(yyvsp[-5].type_val)<<endl;
		 		cout<<"end_"<<(yyvsp[-5].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
		 		sonuc<<"end_"<<(yyvsp[-5].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
#line 1463 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 88 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			cout<<"while_loop_"<<(yyvsp[0].type_val)<<":"<<endl<<"\tadd $t0,$t0,$zero"<<endl;
			sonuc<<"while_loop_"<<(yyvsp[0].type_val)<<":"<<endl<<"\tadd $t0,$t0,$zero"<<endl;
			}
#line 1472 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 92 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
				cout<<"\tbeq $t"<<(yyvsp[0].node).reg<<",$zero,e"<<(yyvsp[-3].type_val)<<endl; sonuc<<"\tbeq $t"<<(yyvsp[0].node).reg<<",$zero,e"<<(yyvsp[-3].type_val)<<endl; 
				hafizadan_sil((yyvsp[0].node).reg);}
#line 1480 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 94 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
					cout<<"\tj while_loop_"<<(yyvsp[-6].type_val)<<"\n"<<"e"<<(yyvsp[-6].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
		 			sonuc<<"\tj while_loop_"<<(yyvsp[-6].type_val)<<"\n"<<"e"<<(yyvsp[-6].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
#line 1488 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 97 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		cout<<"for_loop_"<<(yyvsp[-2].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
	  sonuc<<"for_loop_"<<(yyvsp[-2].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
#line 1496 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 99 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			cout<<"\tbeq $t"<<(yyvsp[0].node).reg<<",$zero,e"<<(yyvsp[-5].type_val)<<endl;hafizadan_sil((yyvsp[0].node).reg);
		 	sonuc<<"\tbeq $t"<<(yyvsp[0].node).reg<<",$zero,e"<<(yyvsp[-5].type_val)<<endl;hafizadan_sil((yyvsp[0].node).reg);}
#line 1504 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 101 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
				 	cout<<"\tj f"<<(yyvsp[-7].type_val)<<"\n"<<"ef"<<(yyvsp[-7].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
					sonuc<<"\tj f"<<(yyvsp[-7].type_val)<<"\n"<<"ef"<<(yyvsp[-7].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
#line 1512 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 103 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
						cout<<"\tj for_loop_"<<(yyvsp[-9].type_val)<<endl; sonuc<<"\tj for_loop_"<<(yyvsp[-9].type_val)<<endl;}
#line 1519 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 105 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
								cout<<"\tf"<<(yyvsp[-11].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
								sonuc<<"\tf"<<(yyvsp[-11].type_val)<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
#line 1527 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 107 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
									cout<<"\tj ef"<<(yyvsp[-13].type_val)<<"\n"<<"e"<<(yyvsp[-13].type_val)<<":\n\tadd $t0,$t0,$zero"<<endl;
									sonuc<<"\tj ef"<<(yyvsp[-13].type_val)<<"\n"<<"e"<<(yyvsp[-13].type_val)<<":\n\tadd $t0,$t0,$zero"<<endl;}
#line 1535 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 110 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		cout<<"beq $t"<< (yyvsp[0].node).reg <<",$zero,else_"<<(yyvsp[-2].type_val)<<endl;
		sonuc<<"beq $t"<< (yyvsp[0].node).reg <<",$zero,else_"<<(yyvsp[-2].type_val)<<endl;hafizadan_sil((yyvsp[0].node).reg);}
#line 1543 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 112 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		cout<<"j end_"<<(yyvsp[-5].type_val)<<endl;sonuc<<"j end_"<<(yyvsp[-5].type_val)<<endl;
		cout<<"else_"<<(yyvsp[-5].type_val)<<":\n\tadd $t0,$t0,$zero"<<endl;sonuc<<"else_"<<(yyvsp[-5].type_val)<<":\n\tadd $t0,$t0,$zero"<<endl;}
#line 1551 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 115 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		cout<<"j end_"<<(yyvsp[-8].type_val)<<endl;sonuc<<"j end_"<<(yyvsp[-8].type_val)<<endl;
		cout<<"end_"<<(yyvsp[-8].type_val)<<":\nadd $t0,$t0,$zero"<<endl;sonuc<<"end_"<<(yyvsp[-8].type_val)<<":\nadd $t0,$t0,$zero"<<endl;}
#line 1559 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 118 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			if(type_map.find(string((yyvsp[-1].str)))!=type_map.end()){	
				if(type_map[string((yyvsp[-1].str))] == 0){ cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
					cout<<"\tlw $a0"<<","<<(yyvsp[-1].str)<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<(yyvsp[-1].str)<<endl<<"\tsyscall"<<endl;}	 
			if(type_map[string((yyvsp[-1].str))] == 1){
				cout<<"\tli $v0, 4"<<endl;sonuc<<"\tli $v0, 4"<<endl; 
				cout<<"\tla $a0"<<","<<(yyvsp[-1].str)<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tla $a0"<<","<<(yyvsp[-1].str)<<endl<<"\tsyscall"<<endl;
			}
		}else yyerror("Degisken tipi bildirilmemis");}
#line 1573 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 127 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {}
#line 1579 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 128 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			if(type_map.find(string((yyvsp[-4].str)))!=type_map.end()){	
				if(type_map[string((yyvsp[-4].str))] == 0){ cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl;
					int temp = hafizadan_al();
					cout<<"\tla $t"<<temp<<","<<(yyvsp[-4].str)<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<(yyvsp[-4].str)<<"_degiskeni"<<endl;
					cout<<"\tmul $t"<<(yyvsp[-2].node).reg<<",$t"<<(yyvsp[-2].node).reg<<","<<4<<endl;sonuc<<"\tmul $t"<<(yyvsp[-2].node).reg<<","<<4<<endl;
					cout<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<(yyvsp[-2].node).reg<<endl;sonuc<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<(yyvsp[-2].node).reg<<endl;
					cout<<"\tlw $a0"<<","<<"($t"<<temp<<")"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<"($t"<<temp<<")"<<endl<<"\tsyscall"<<endl;
					hafizadan_sil(temp);}
			if(type_map[string((yyvsp[-4].str))] == 1){
					cout<<"\t#Butun karakter dizi basilacaktir. Bu sekilde tasarladim."<<endl;
					cout<<"\tli $v0, 4"<<endl;sonuc<<"\tli $v0, 4"<<endl; 
					int temp = hafizadan_al();
					cout<<"\tla $a0,"<<(yyvsp[-4].str)<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tla $t"<<temp<<","<<(yyvsp[-4].str)<<"_degiskeni"<<endl;
					hafizadan_sil(temp);}
			}
		else yyerror("Degisken tipi bildirilmemis");}
#line 1601 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 156 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		atama(string((yyvsp[-2].str)),(yyvsp[0].node).type,(yyvsp[0].node).reg,0,0,0);hafizayi_bosalt();}
#line 1608 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 158 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			atama(string((yyvsp[-5].str)),(yyvsp[0].node).type,(yyvsp[0].node).reg,(yyvsp[-3].node).type,(yyvsp[-3].node).reg,1);hafizayi_bosalt();}
#line 1615 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 160 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		if(type_map.find(string((yyvsp[0].str)))==type_map.end()){type_map[string((yyvsp[0].str))]=(yyvsp[-1].type_val);}
	  else yyerror("Degisken tipi bildirilmemis");hafizayi_bosalt();}
#line 1623 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 163 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		if(type_map.find(string((yyvsp[-2].str)))==type_map.end()){
			type_map[string((yyvsp[-2].str))]=(yyvsp[-3].type_val);
	  	atama(string((yyvsp[-2].str)),(yyvsp[0].node).type,(yyvsp[0].node).reg,0,0,0);}
			else{
					yyerror("Degisken tipi bildirilmemis");};hafizayi_bosalt();}
#line 1634 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 169 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		if(type_map.find(string((yyvsp[-3].str)))==type_map.end()){
				size_map[string((yyvsp[-3].str))]=atoi((yyvsp[-1].str));type_map[string((yyvsp[-3].str))]=(yyvsp[-4].type_val);
				}else {yyerror("Degisken tipi bildirilmemis");};hafizayi_bosalt();}
#line 1643 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 173 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {hafizayi_bosalt();}
#line 1649 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 174 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {}
#line 1655 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 176 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"||",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1662 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 178 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"&&",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1669 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 180 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1675 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 184 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
			Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"==",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1682 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 186 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"!=",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1689 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 188 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"<",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1696 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 190 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,">",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1703 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 192 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"<=",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1710 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 194 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,">=",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1717 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 196 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1723 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 198 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"+",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1730 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 200 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"-",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1737 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 202 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"&",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1744 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 204 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"|",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1751 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 206 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"^",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1758 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 208 "../bisonFiles/parser.y" /* yacc.c:1652  */
    { 
		Node n = islemler((yyvsp[0].node).reg,(yyvsp[0].node).reg,"!",(yyvsp[0].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1765 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 210 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1771 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 212 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"*",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1778 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 214 "../bisonFiles/parser.y" /* yacc.c:1652  */
    { 
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"/",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1785 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 216 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {
		Node n = islemler((yyvsp[-2].node).reg,(yyvsp[0].node).reg,"%",(yyvsp[-2].node).type,(yyvsp[0].node).type);(yyval.node).reg = n.reg;(yyval.node).type = n.type;}
#line 1792 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 218 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1798 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 221 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[0].str)<<endl;sonuc<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[0].str)<<endl;(yyval.node).type=0;}
#line 1804 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 222 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1810 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 223 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1816 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 224 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[0].str)<<endl;
		sonuc<<"\tli $t"<<(yyval.node).reg<<","<<((yyvsp[0].str))<<endl;(yyval.node).type=0;}
#line 1823 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 226 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {cout<<"neg $t"<<(yyvsp[0].node).reg<<","<<"$t"<<(yyvsp[0].node).reg<<endl;
		sonuc<<"neg $t"<<(yyvsp[0].node).reg<<","<<"$t"<<(yyvsp[0].node).reg<<endl;(yyval.node)=(yyvsp[0].node);}
#line 1830 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 228 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1836 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 229 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<atoi((yyvsp[0].str))-1<<endl;
		sonuc<<"\tli $t"<<(yyval.node).reg<<","<<atoi((yyvsp[0].str))-1<<endl;(yyval.node).type=0;}
#line 1843 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 231 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<atoi((yyvsp[0].str))+1<<endl;
		sonuc<<"\tli $t"<<(yyval.node).reg<<","<<atoi((yyvsp[0].str))+1<<endl;(yyval.node).type=0;}
#line 1850 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 233 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[-1].str)<<endl;
		sonuc<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[-1].str)<<endl;(yyval.node).type=0;}
#line 1857 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 235 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[-1].str)<<endl;
		sonuc<<"\tli $t"<<(yyval.node).reg<<","<<(yyvsp[-1].str)<<endl;(yyval.node).type=0;}
#line 1864 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 237 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {cout<<"\tseq $t"<<(yyvsp[0].node).reg<<",$t"<<(yyvsp[0].node).reg<<",$zero"<<endl;
		sonuc<<"\tseq $t"<<(yyvsp[0].node).reg<<",$t"<<(yyvsp[0].node).reg<<",$zero"<<endl;(yyval.node) = (yyvsp[0].node);}
#line 1871 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 239 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {(yyval.node).reg=hafizadan_al();cout<<"\tli $t"<<(yyval.node).reg<<","<<int((yyvsp[0].str)[1])<<endl;sonuc<<"\tli $t"<<(yyval.node).reg<<","<<int((yyvsp[0].str)[1])<<endl;(yyval.node).type=1;}
#line 1877 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 244 "../bisonFiles/parser.y" /* yacc.c:1652  */
    { if(type_map.find(string((yyvsp[0].str)))!=type_map.end()){
					arttir_azalt((yyvsp[0].str),1,(yyval.node).reg=hafizadan_al(),false,'-');(yyval.node).type=type_map[string((yyvsp[0].str))]; strcpy(temp, (yyvsp[0].str));}
					else {yyerror("Degisken tipi bildirilmemis");}}
#line 1885 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 247 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[0].str)))!=type_map.end()){
						arttir_azalt((yyvsp[0].str),1,(yyval.node).reg=hafizadan_al(),false,'+');(yyval.node).type=type_map[string((yyvsp[0].str))]; strcpy(temp, (yyvsp[0].str));}
						else {yyerror("Degisken tipi bildirilmemis");}}
#line 1893 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 250 "../bisonFiles/parser.y" /* yacc.c:1652  */
    { if(type_map.find(string((yyvsp[-1].str)))!=type_map.end()){
				arttir_azalt((yyvsp[-1].str),2,(yyval.node).reg=hafizadan_al(),false,'-');(yyval.node).type=type_map[string((yyvsp[-1].str))]; strcpy(temp, (yyvsp[-1].str));}
			else {yyerror("Degisken tipi bildirilmemis");}}
#line 1901 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 253 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[-1].str)))!=type_map.end()){
		arttir_azalt((yyvsp[-1].str),2,(yyval.node).reg=hafizadan_al(),false,'+');(yyval.node).type=type_map[string((yyvsp[-1].str))]; strcpy(temp, (yyvsp[-1].str));}
		else {yyerror("Degisken tipi bildirilmemis");}}
#line 1909 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 257 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[0].str)))!=type_map.end()){
					 arttir_azalt((yyvsp[0].str),1,(yyval.node).reg=hafizadan_al(),true,'-');(yyval.node).type=type_map[string((yyvsp[0].str))]; strcpy(temp, (yyvsp[0].str)); }
					 else {yyerror("Degisken tipi bildirilmemis");}}
#line 1917 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 260 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[0].str)))!=type_map.end()){
							arttir_azalt((yyvsp[0].str),1,(yyval.node).reg=hafizadan_al(),true,'+');(yyval.node).type=type_map[string((yyvsp[0].str))]; strcpy(temp, (yyvsp[0].str));}
							else {yyerror("Degisken tipi bildirilmemis");}}
#line 1925 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 263 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[-1].str)))!=type_map.end()){
							arttir_azalt((yyvsp[-1].str),2,(yyval.node).reg=hafizadan_al(),true,'-');(yyval.node).type=type_map[string((yyvsp[-1].str))]; strcpy(temp, (yyvsp[-1].str));}
							else {yyerror("Degisken tipi bildirilmemis");}}
#line 1933 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 266 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {if(type_map.find(string((yyvsp[-1].str)))!=type_map.end()){
								arttir_azalt((yyvsp[-1].str),2,(yyval.node).reg=hafizadan_al(),true,'+');(yyval.node).type=type_map[string((yyvsp[-1].str))]; strcpy(temp, (yyvsp[-1].str));}
								else {yyerror("Degisken tipi bildirilmemis");}}
#line 1941 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 270 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {Node n = h_yukle((yyvsp[0].str),0,0,0);(yyval.node).reg=n.reg;(yyval.node).type=n.type;}
#line 1947 "parser.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 271 "../bisonFiles/parser.y" /* yacc.c:1652  */
    {Node n = h_yukle((yyvsp[-3].str),(yyvsp[-1].node).type,(yyvsp[-1].node).reg,1);(yyval.node).reg=n.reg;(yyval.node).type=n.type;}
#line 1953 "parser.tab.c" /* yacc.c:1652  */
    break;


#line 1957 "parser.tab.c" /* yacc.c:1652  */
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
#line 272 "../bisonFiles/parser.y" /* yacc.c:1918  */


//yacc fonksiyonu grammer hatası tespiti için burada derleme olmuyor direk syntaxt hatası der.
void yyerror(char const* msg)
{
	fprintf(stderr,"Hata : %s , %d. satirda \n",msg,yylineno);
}
int main(){
	
	sonuc.open("assembly.asm");
	cout<<".text"<<endl<<".globl main"<<endl<<"main:"<<endl;sonuc<<".text"<<endl<<".globl main"<<endl<<"main:"<<endl;
	//C kodunu parse et; Hata varsa result 1 yoksa 0 döner.
	int result = yyparse();
	//memory'i boşalt
	for(int i=0;i<1000;i++)
		hafiza[i]=0;
	//Sonlandır
	cout<<"\tli $v0,10\n\tsyscall"<<endl;	sonuc<<"\tli $v0,10\n\tsyscall"<<endl;	
	cout<<"\n.data\n"; sonuc<<"\n.data\n";
	data();
	
	if(result == 0)
	{ 	
		fprintf(stderr,"#Program sozdizimsel olarak gecerlidir\n");sonuc<<"#Program sozdizimsel olarak gecerlidir"<<endl;
	}
	else{
		fprintf(stderr,"#syntax hatalari algilandi\n");sonuc<<"#syntax hatalari algilandi"<<endl; 
	}

	sonuc.close();  
	return result;
}

/* 
			Yöntemler
	1: azalt ID, ARTTIR ID  ++a, --a
	2: ID azalt, ID ARTTIR a++, a--; 
		sembol ++ , --
*/

//Burada olan type flag mantığı ileride belki float eklersek diye t
//O yüzden gerekli tip eklenince lazım olucak
////id: id(parse olarak) , tipi: type 0 int yada 1char olur, reg: reg olan t0 t1 ,0,0,0 ,, dizi ise index.type r ifade  ve flag 1 olur
void atama(string id,int tipi,int reg,int index_type,int offset_location,int flag)
{
	//Yukarda zaten kontolü koyduk ama yinede kalsın ilerisi için
	if(type_map.find(id)==type_map.end()){
		yyerror("#Bu degisken tipi belirtilmemis");
		sonuc<<"#Bu degisken tipi belirtilmemis"<<endl;
		return;
	}
	//char dizi yok veya başka veri tipinde
	if(flag==1 && index_type!=0){
		yyerror("#tam sayi olmali");
		sonuc<<"#tam sayi olmali"<<endl;
		return;
	}
	//gerekli
	int temp_type = type_map[id];
	char degisken[id.length()+1]; 
	strcpy(degisken,id.c_str());
		//dizi değilse 
	if(flag==0){
		if(temp_type==0){
			cout<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
		}
		else{
			cout<<"\tsb $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsb $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
		}
		
	}
	//diziyse
	else	{
		int temp = hafizadan_al();
		int temp2 = hafizadan_al();
		//base adres alınır
		cout<<"\tla $t"<<temp<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<degisken<<"_degiskeni"<<endl;
		// size temp int se 4 char sa 1 olmalı
		//cout<<"\tli $t"<<temp2<<","<<size[temp_type]<<endl;sonuc<<"\tli $t"<<temp2<<","<<size[temp_type]<<endl;
		cout<<"\tmul $t"<<offset_location<<",$t"<<offset_location<<","<<size[temp_type]<<endl;sonuc<<"\tmul $t"<<offset_location<<","<<size[temp_type]<<endl;
		cout<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<offset_location<<endl;sonuc<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<offset_location<<endl;
		if(temp_type == 0){//storeword
			cout<<"\tsw $t"<<reg<<",($t"<<temp<<")"<<endl;sonuc<<"\tsw $t"<<reg<<",($t"<<temp<<")"<<endl;
		}
		else{//storebyte
			cout<<"\tsb $t"<<reg<<",-1($t"<<temp<<")"<<endl;sonuc<<"\tsb $t"<<reg<<",-1($t"<<temp<<")"<<endl;
		}

		hafizadan_sil(temp);
		hafizadan_sil(temp2);
		hafizadan_sil(offset_location);
		}
		hafizadan_sil(reg);
		if( temp_type == 1 && tipi== 0 || temp_type == 0 && tipi== 1 )
			yyerror("#Tip eslesmedi!");
}

void arttir_azalt(char *degisken,int yontem,int reg, bool print, char sembol)
{	
	if(yontem ==2 && print ){
		cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
		cout<<"\tlw $a0"<<","<<degisken<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<degisken<<endl<<"\tsyscall"<<endl;
	}
	cout<<"\tlw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tlw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
	//+
	if(sembol == '+'){
		cout<<"\taddi $t"<<reg<<","<<"$t"<<reg<<",1"<<endl;sonuc<<"\taddi $t"<<reg<<","<<"$t"<<reg<<",1"<<endl;
	}	//-	
	else{
		cout<<"\taddi $t"<<reg<<",$t"<<reg<<",-1"<<endl;sonuc<<"\taddi $t"<<reg<<",$t"<<reg<<",-1"<<endl;
	}
	cout<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
	if(yontem == 1 && print ){
		cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
		cout<<"\tlw $a0"<<","<<degisken<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<degisken<<endl<<"\tsyscall"<<endl;
	}
	//en son sil
	hafizadan_sil(reg);
}
//hafıdan ilk boş olan yeri al
//programın en sonunda boşaltılacaktır.
int hafizadan_al()
{
	for(int i=0;i<1000;i++)
	{
		if(hafiza[i]==0)
		{
			hafiza[i]=1;
			return i;
		}
	}
    return 0;		
}

//a. indeksi boşalt 
void hafizadan_sil(int a)
{
	hafiza[a]=0;
	return;
}

//hepsini boşalt
void hafizayi_bosalt()
{
	for(int i=0;i<1000;i++)
		hafiza[i]=0;
}

// Aritmatik işlemlerin hepsi
// t1 + t2 <= 1 || (t1==1 && t2==1 float ekliyceksek ileride else if şartı bu olmalı
// diğer veri tipleri için n.type değiştirilmeli yerine göre
Node islemler(int reg,int reg2,string islem,int t1,int t2)
{
	Node n;
	n.reg = reg;	
	char temp;
	if( t1 == 1){
		cout<<"\t#char tipi icin islem yapılıyor"<<endl;sonuc<<"\t#char tipi icin islem yapılıyor"<<endl;
	}
	if(t1==t2){ 
		//ilk karakter alındığı için, || yerine | case içeride  bitwise yok .
		switch(islem[0]){
			case '+':
				cout<<"\tadd $t"<<reg<<",$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tadd $t"<<reg<<",$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '-':
				cout<<"\tsub $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsub $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '*':
				cout<<"\tmult $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;sonuc<<"\tmult $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;
				break;
			case '/':
				cout<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;sonuc<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;
				break;
			case '%':
				cout<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmfhi,$t"<<reg<<endl;sonuc<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmfhi,$t"<<reg<<endl;
				break;
			case '=':
				cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '>':
				if(islem.length()>1){
					cout<<"\tsge $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsge $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				else{
					cout<<"\tsgt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsgt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				break;
			case '<':
				if(islem.length()>1){
					cout<<"\tsle $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsle $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				else{
					cout<<"\tslt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tslt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				break;
			case '!':
				//değil olarak eşit değil mi vs de
				if(islem.length() > 1){
					cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
					cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$zero"<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$zero"<<endl;
				}//bitwise olarak
				else{
					cout<<"\tnot $t"<<reg2<<","<<"$t"<<reg2<<endl;sonuc<<"\tnot $t"<<reg2<<","<<"$t"<<reg2<<endl;
				}
				break;
			case '|':
				cout<<"\tor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '&':
				cout<<"\tand $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tand $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '^':
				cout<<"\txor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\txor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
		}
		n.type = 0;
	}
	else
	{
		yyerror("Uyumsuz tip!!");sonuc<<"Uyumsuz tip!!"<<endl;
	}
	hafizadan_sil(reg2);
	return n;
}

//node f temp id için işlemler cıkar temp_id
//flag = 1 dizi ,  dizi için ve normal yoldan iki tane yolladık
Node h_yukle(char* a,int offset_type,int offset_location,int flag)
{
	Node n;
	if(type_map.find(string(a))==type_map.end())
	{
		yyerror("Bilinmeyen tipte degisken");sonuc<<"Bilinmeyen tipte degisken"<<endl;
		return n;
	}
	n.type=type_map[string(a)];
	if(flag==0)
	{
		n.reg=hafizadan_al();
		cout<<"\tlw $t"<<n.reg<<","<<a<<"_degiskeni"<<endl;sonuc<<"\tlw $t"<<n.reg<<","<<a<<"_degiskeni"<<endl;
	}
	else
	{
		if(offset_type != 0)
		{
			yyerror("Dizin integer tipte olmalı");sonuc<<"Dizin integer tipte olmalı"<<endl;
			return n;
		}
		int temp,temp2;
		temp=hafizadan_al();
		temp2=hafizadan_al();
		cout<<"\tla $t"<<temp<<","<<a<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<a<<"_degiskeni"<<endl;
		temp2=hafizadan_al();
		cout<<"\tli $t"<<temp2<<","<<size[n.type]<<endl;sonuc<<"\tli $t"<<temp2<<","<<size[n.type]<<endl;
		cout<<"\tmult $t"<<offset_location<<","<<"$t"<<temp2<<endl;sonuc<<"\tmult $t"<<offset_location<<","<<"$t"<<temp2<<endl;
		cout<<"\tmflo $t"<<offset_location<<endl;sonuc<<"\tmflo $t"<<offset_location<<endl;
		cout<<"\tadd $t"<<temp<<","<<"$t"<<temp<<",$t"<<offset_location<<endl;sonuc<<"\tadd $t"<<temp<<","<<"$t"<<temp<<",$t"<<offset_location<<endl;
		n.reg=hafizadan_al();
		cout<<"\tlw $t"<<n.reg<<",($t"<<temp<<")"<<endl;sonuc<<"\tlw $t"<<n.reg<<",($t"<<temp<<")"<<endl;
		hafizadan_sil(offset_location);
		hafizadan_sil(temp);
		hafizadan_sil(temp2);
	}
	return n;
}

void data(){
	for(map<string,int>::iterator it = type_map.begin(); it != type_map.end(); ++it) {
		string a = it->first;
		string b = a;
		char degisken[a.length()+1]; 
		if (size_map.find(a)==size_map.end())
		{
			strcpy(degisken,a.c_str());
			//int' se 
			if(type_map[b]==0){
				cout<<degisken<<"_degiskeni: .word 0"<<endl;sonuc<<degisken<<"_degiskeni: .word 0"<<endl;
			}
				
			//char sa
			if(type_map[b]==1){
				cout<<degisken<<"_degiskeni: .byte 0"<<endl;sonuc<<degisken<<"_degiskeni: .word 0"<<endl;
			}
				
		}	
		else{
			strcpy(degisken,a.c_str());
			if(type_map[b]==0){
				cout<<degisken<<"_degiskeni: .word 0:"<<size_map[b]<<endl;sonuc<<degisken<<"_degiskeni: .word 0:"<<size_map[b]<<endl;
			}
			if(type_map[b]==1){
				cout<<degisken<<"_degiskeni: .byte 0:"<<size_map[b]<<endl;sonuc<<degisken<<"_degiskeni: .byte 0:"<<size_map[b]<<endl;
			}	
		}
	}
}
