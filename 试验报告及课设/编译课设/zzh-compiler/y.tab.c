
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "zzh.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#else
#include <unistd.h>
#define ACCESS access
#define MKDIR(a) mkdir((a), 0777) // 0777 是权限设置，表示所有用户可读写执行
#endif

#define TYPE_NAME(x) _Generic((x), \
    int: 1, \
    double: 2, \
    char*: 3 )

void yyerror(char *msg);
int yylex();

extern FILE *yyin;

int linecount = 1;
int isif=0;
int iselse=0;
int isStatement = 0;
int isPushType = 1;

int idNum = 0;
int if_flag=1;

FILE *treeFile;
FILE *errorFile;
FILE *tokenFile;

struct word {
    char *word_name;
    int word_type;
    union {
        int int_value;
        double double_value;
        char *string_value;
    } value;
    struct word *next;
};

struct word *word_list = NULL;

void pushType(int idNum,int type);

void free_list(struct word *head);

struct word *isExist(char *word);

char* string_add(const char* str1, const char* str2);

char* string_subtract(const char* str1, const char* str2);

void outputIDS();

void createOutputFolder();



/* Line 189 of yacc.c  */
#line 145 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     DNUM = 260,
     STR = 261,
     VAR = 262,
     IF = 263,
     ELSE = 264,
     FOR = 265,
     WHILE = 266,
     INT = 267,
     DOUBLE = 268,
     STRING = 269,
     BOOL = 270,
     PLUS = 271,
     MINUS = 272,
     MULT = 273,
     DIV = 274,
     ASSIGN = 275,
     EQ = 276,
     NE = 277,
     LT = 278,
     GT = 279,
     LE = 280,
     GE = 281,
     COLON = 282,
     COMMA = 283,
     LBRACKET = 284,
     RBRACKET = 285,
     LPAREN = 286,
     RPAREN = 287,
     LBRACE = 288,
     RBRACE = 289,
     PRINT = 290
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define DNUM 260
#define STR 261
#define VAR 262
#define IF 263
#define ELSE 264
#define FOR 265
#define WHILE 266
#define INT 267
#define DOUBLE 268
#define STRING 269
#define BOOL 270
#define PLUS 271
#define MINUS 272
#define MULT 273
#define DIV 274
#define ASSIGN 275
#define EQ 276
#define NE 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define COLON 282
#define COMMA 283
#define LBRACKET 284
#define RBRACKET 285
#define LPAREN 286
#define RPAREN 287
#define LBRACE 288
#define RBRACE 289
#define PRINT 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 72 "zzh.y"

    int intVal;
    double doubleVal;
    char* strVal;
    char* id;



/* Line 214 of yacc.c  */
#line 260 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 272 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    23,    29,    31,    35,    37,    39,    41,    43,    46,
      49,    53,    58,    62,    66,    74,    86,    94,   102,   106,
     110,   114,   118,   122,   126,   128,   130,   134,   138,   142,
     146,   150,   152,   156,   160,   164,   169,   174
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    39,    38,    -1,    -1,    40,
      -1,    44,    -1,    45,    -1,    46,    -1,    50,    -1,     7,
      41,    42,    -1,     7,    41,    42,    20,    48,    -1,     3,
      -1,     3,    28,    41,    -1,    12,    -1,    13,    -1,    14,
      -1,    15,    -1,    12,    43,    -1,    13,    43,    -1,    29,
       4,    30,    -1,    29,     4,    30,    43,    -1,     3,    20,
      49,    -1,     3,    20,    48,    -1,     8,    31,    47,    32,
      33,    38,    34,    -1,     8,    31,    47,    32,    33,    38,
      34,     9,    33,    38,    34,    -1,    10,     3,    27,     3,
      33,    38,    34,    -1,    11,    31,    47,    32,    33,    38,
      34,    -1,    48,    21,    48,    -1,    48,    22,    48,    -1,
      48,    23,    48,    -1,    48,    25,    48,    -1,    48,    24,
      48,    -1,    48,    26,    48,    -1,     4,    -1,     3,    -1,
      31,    48,    32,    -1,    48,    16,    48,    -1,    48,    17,
      48,    -1,    48,    18,    48,    -1,    48,    19,    48,    -1,
       6,    -1,    31,    49,    32,    -1,    49,    16,    49,    -1,
      49,    17,    49,    -1,    35,    31,     6,    32,    -1,    35,
      31,    48,    32,    -1,    35,    31,    49,    32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   105,   106,   109,   110,   111,   112,   113,
     116,   117,   120,   121,   124,   128,   132,   136,   140,   141,
     144,   145,   148,   189,   224,   236,   251,   252,   255,   256,
     257,   258,   259,   260,   263,   264,   279,   280,   281,   282,
     283,   286,   287,   288,   289,   292,   307,   319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "DNUM", "STR", "VAR",
  "IF", "ELSE", "FOR", "WHILE", "INT", "DOUBLE", "STRING", "BOOL", "PLUS",
  "MINUS", "MULT", "DIV", "ASSIGN", "EQ", "NE", "LT", "GT", "LE", "GE",
  "COLON", "COMMA", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "PRINT", "$accept", "program", "statement_list", "statement",
  "variable_declaration", "id_list", "type", "array_dimensions",
  "assignment", "if_statement", "loop_statement", "condition",
  "expression", "expression2", "print_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      40,    40,    41,    41,    42,    42,    42,    42,    42,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    49,    49,    50,    50,    50
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     5,     1,     3,     1,     1,     1,     1,     2,     2,
       3,     4,     3,     3,     7,    11,     7,     7,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,     6,     7,     8,     9,     0,    12,     0,     0,     0,
       0,     0,     1,     3,    35,    34,    41,     0,    23,    22,
       0,    14,    15,    16,    17,    10,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    46,    47,    36,
      42,    37,    38,    39,    40,     0,    43,    44,     0,    11,
       4,    28,    29,    30,    32,    31,    33,     4,     4,    20,
       0,     0,     0,    21,    24,    26,    27,     0,     4,     0,
      25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    17,    35,    54,    11,    12,
      13,    37,    38,    45,    14
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -32
static const yytype_int8 yypact[] =
{
       9,    -7,    12,    -1,    15,    11,    20,    55,   -32,     9,
     -32,   -32,   -32,   -32,   -32,     1,    29,    84,    25,    36,
      25,    21,   -32,   -32,   -32,   -32,   -32,     1,    65,    24,
      12,    39,    39,   -32,   -32,    49,    25,    38,    69,    70,
      40,    42,    43,    -6,    48,     5,    25,    25,    25,    25,
       0,     0,   -32,    72,   -32,   -32,    25,    44,    25,    25,
      25,    25,    25,    25,    67,    68,   -32,   -32,   -32,   -32,
     -32,    35,    35,   -32,   -32,     0,   -32,   -32,    73,    65,
       9,    65,    65,    65,    65,    65,    65,     9,     9,    39,
      71,    74,    75,   -32,    93,   -32,   -32,    77,     9,    78,
     -32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    -9,   -32,   -32,    76,   -32,   -31,   -32,   -32,
     -32,    87,   -13,   -12,   -32
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      23,    55,    28,    29,    24,    25,    26,    26,    42,    43,
      50,    51,     1,    15,    44,    16,     2,     3,    19,     4,
       5,    50,    51,    44,    24,    25,    68,    41,    24,    25,
      18,    75,    27,    71,    72,    73,    74,    70,    76,    77,
      50,    51,    20,    79,     6,    81,    82,    83,    84,    85,
      86,    21,    27,    48,    49,    22,    36,    30,    93,    46,
      47,    48,    49,    39,    46,    47,    48,    49,    53,    56,
      57,    90,    65,    64,    66,    67,    78,    80,    91,    92,
      69,    46,    47,    48,    49,    46,    47,    48,    49,    99,
      58,    59,    60,    61,    62,    63,    31,    32,    33,    34,
      87,    88,    97,    89,     0,    94,    52,    40,    95,    96,
      98,     0,   100
};

static const yytype_int8 yycheck[] =
{
       9,    32,    15,    15,     3,     4,     6,     6,    21,    21,
      16,    17,     3,    20,    27,     3,     7,     8,     3,    10,
      11,    16,    17,    36,     3,     4,    32,     6,     3,     4,
      31,    31,    31,    46,    47,    48,    49,    32,    50,    51,
      16,    17,    31,    56,    35,    58,    59,    60,    61,    62,
      63,    31,    31,    18,    19,     0,    31,    28,    89,    16,
      17,    18,    19,    27,    16,    17,    18,    19,    29,    20,
      32,    80,    32,     3,    32,    32,     4,    33,    87,    88,
      32,    16,    17,    18,    19,    16,    17,    18,    19,    98,
      21,    22,    23,    24,    25,    26,    12,    13,    14,    15,
      33,    33,     9,    30,    -1,    34,    30,    20,    34,    34,
      33,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     7,     8,    10,    11,    35,    37,    38,    39,
      40,    44,    45,    46,    50,    20,     3,    41,    31,     3,
      31,    31,     0,    38,     3,     4,     6,    31,    48,    49,
      28,    12,    13,    14,    15,    42,    31,    47,    48,    27,
      47,     6,    48,    49,    48,    49,    16,    17,    18,    19,
      16,    17,    41,    29,    43,    43,    20,    32,    21,    22,
      23,    24,    25,    26,     3,    32,    32,    32,    32,    32,
      32,    48,    48,    48,    48,    31,    49,    49,     4,    48,
      33,    48,    48,    48,    48,    48,    48,    33,    33,    30,
      38,    38,    38,    43,    34,    34,    34,     9,    33,    38,
      34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 102 "zzh.y"
    { fprintf(treeFile, "program --> statement_list\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 105 "zzh.y"
    { fprintf(treeFile, "statement_list --> statement statement_list\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 106 "zzh.y"
    { fprintf(treeFile, "statement_list --> ε\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 109 "zzh.y"
    { fprintf(treeFile, "statement --> variable_declaration\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 110 "zzh.y"
    { fprintf(treeFile, "statement --> assignment\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 111 "zzh.y"
    { fprintf(treeFile, "statement --> if_statement\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 112 "zzh.y"
    { fprintf(treeFile, "statement --> loop_statement\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 113 "zzh.y"
    { fprintf(treeFile, "statement --> print_statement\n"); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 116 "zzh.y"
    { fprintf(treeFile, "variable_declaration --> var id_list type\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 117 "zzh.y"
    { fprintf(treeFile, "variable_declaration --> var id_list type = expression\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 120 "zzh.y"
    { isStatement = 0; fprintf(treeFile, "id_list --> %s\n",(yyvsp[(1) - (1)].id));}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 121 "zzh.y"
    { fprintf(treeFile, "id_list --> %s , id_list\n",(yyvsp[(1) - (3)].id));}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 124 "zzh.y"
    {
            pushType(idNum,1);
            fprintf(treeFile, "type --> int\n");
         }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 128 "zzh.y"
    {
                pushType(idNum,2); 
                fprintf(treeFile, "type --> double\n");
            }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 132 "zzh.y"
    { 
                pushType(idNum,3); 
                fprintf(treeFile, "type --> string\n");
            }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 136 "zzh.y"
    { 
                pushType(idNum,4); 
                fprintf(treeFile, "type --> bool\n");
            }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 140 "zzh.y"
    { fprintf(treeFile, "type --> int array_dimensions\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 141 "zzh.y"
    { fprintf(treeFile, "type --> double array_dimensions\n");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 144 "zzh.y"
    { fprintf(treeFile, "array_dimensions --> [ %d ]\n",(yyvsp[(2) - (3)].intVal));}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "zzh.y"
    { fprintf(treeFile, "array_dimensions --> [ %d ] array_dimensions\n",(yyvsp[(2) - (4)].intVal));}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 148 "zzh.y"
    {
                                    if(!isif){
                                        char * name = (yyvsp[(1) - (3)].id);
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME((yyvsp[(3) - (3)].strVal));
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.string_value = (char*)malloc(strlen((yyvsp[(3) - (3)].strVal)) + 1); // +1 是为了 '\0'
                                                if (w->value.string_value == NULL) {
                                                    printf("%s's Memory allocation failed\n",w->word_name);
                                                    fprintf(errorFile, "%s's Memory allocation failed at line: %d\n",w->word_name,linecount);
                                                }
                                                strcpy(w->value.string_value, (yyvsp[(3) - (3)].strVal)); 
                                                //printf("%s:%s\n",$1,w->value.string_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                                fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",(yyvsp[(1) - (3)].id));
                                    }
                                    else if(if_flag!=0){
                                        char * name = (yyvsp[(1) - (3)].id);
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME((yyvsp[(3) - (3)].strVal));
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.string_value = (char*)malloc(strlen((yyvsp[(3) - (3)].strVal)) + 1); // +1 是为了 '\0'
                                                if (w->value.string_value == NULL) {
                                                    printf("%s's Memory allocation failed\n",w->word_name);
                                                    fprintf(errorFile, "%s's Memory allocation failed at line: %d\n",w->word_name,linecount);
                                                }
                                                strcpy(w->value.string_value, (yyvsp[(3) - (3)].strVal)); 
                                                //printf("%s:%s\n",$1,w->value.string_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",(yyvsp[(1) - (3)].id));
                                    }
                                 }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 189 "zzh.y"
    {       
                                        if(!isif){
                                        char * name = (yyvsp[(1) - (3)].id);
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME((yyvsp[(3) - (3)].intVal));
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.int_value = (yyvsp[(3) - (3)].intVal); 
                                                //printf("%s:%d\n",$1,w->value.int_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                                fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",(yyvsp[(1) - (3)].id));
                                        }
                                        else if(if_flag!=0){
                                                //printf("if语句中的赋值:");
                                                char * name = (yyvsp[(1) - (3)].id);
                                                struct word *w = isExist(name);
                                                int type = TYPE_NAME((yyvsp[(3) - (3)].intVal));
                                                if(w != NULL){
                                                    if(w->word_type == type){
                                                        w->value.int_value = (yyvsp[(3) - (3)].intVal); 
                                                        //printf("%s:%d\n",$1,w->value.int_value);
                                                    }else{
                                                        printf("error: %s's type mismatch\n",name);
                                                        fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                                    }
                                                }
                                                fprintf(treeFile, "assignment --> %s = expression\n",(yyvsp[(1) - (3)].id));
                                        }
                                }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 224 "zzh.y"
    { 
    isif=0;
    fprintf(treeFile, "if_statement --> if ( condition ) { statement_list }\n");
            if ((yyvsp[(3) - (7)].intVal)) {  // 如果条件为真
            if_flag=1;
                // printf("执行if\n");
                (yyval.strVal)=(yyvsp[(6) - (7)].strVal);
            }
            else{
                // printf("if_statement不执行\n");
            (yyval.strVal)="NULL";}
}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 237 "zzh.y"
    {   isif=0;
                fprintf(treeFile, "if_statement --> if ( condition ) { statement_list } else { statement_list }\n");
                        if ((yyvsp[(3) - (11)].intVal)) {  // 如果条件为真
                        if_flag=1;
                // printf("执行if\n");
                (yyval.strVal)=(yyvsp[(6) - (11)].strVal);
            } else {
                if_flag=0;
                // printf("执行else\n");
                (yyval.strVal)=(yyvsp[(10) - (11)].strVal);
            }
            }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 251 "zzh.y"
    { fprintf(treeFile, "loop_statement --> for %s : %s { statement_list }\n", (yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].id));}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 252 "zzh.y"
    { fprintf(treeFile, "loop_statement --> while ( condition ) { statement_list }\n");}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 255 "zzh.y"
    { fprintf(treeFile, "condition --> expression == expression\n");if_flag=((yyvsp[(1) - (3)].intVal) == (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) == (yyvsp[(3) - (3)].intVal));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 256 "zzh.y"
    { fprintf(treeFile, "condition --> expression != expression\n");if_flag=((yyvsp[(1) - (3)].intVal) != (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) != (yyvsp[(3) - (3)].intVal)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 257 "zzh.y"
    { fprintf(treeFile, "condition --> expression < expression\n");if_flag=((yyvsp[(1) - (3)].intVal) < (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) < (yyvsp[(3) - (3)].intVal)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 258 "zzh.y"
    { fprintf(treeFile, "condition --> expression <= expression\n");if_flag=((yyvsp[(1) - (3)].intVal) <= (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) <= (yyvsp[(3) - (3)].intVal));}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 259 "zzh.y"
    { fprintf(treeFile, "condition --> expression > expression\n"); if_flag=((yyvsp[(1) - (3)].intVal) > (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) > (yyvsp[(3) - (3)].intVal));}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 260 "zzh.y"
    { fprintf(treeFile, "condition --> expression >= expression\n");if_flag=((yyvsp[(1) - (3)].intVal) >= (yyvsp[(3) - (3)].intVal));(yyval.intVal) = ((yyvsp[(1) - (3)].intVal) >= (yyvsp[(3) - (3)].intVal)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 263 "zzh.y"
    { fprintf(treeFile, "expression --> %d\n", (yyvsp[(1) - (1)].intVal)); (yyval.intVal) = (yyvsp[(1) - (1)].intVal); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 264 "zzh.y"
    { 
                fprintf(treeFile, "expression --> %s\n", (yyvsp[(1) - (1)].id)); 
                struct word *w = isExist((yyvsp[(1) - (1)].id));
                if(w != NULL){
                    if(w->word_type == 1){
                        (yyval.intVal) = w->value.int_value; 
                    }else{
                        printf("error: %s's type mismatch\n",(yyvsp[(1) - (1)].id));
                        fprintf(errorFile, "error: %s's type mismatch at line: %d\n",(yyvsp[(1) - (1)].id),linecount);
                    }
                }else{
                    printf("%s is not defined\n",(yyvsp[(1) - (1)].id));
                    fprintf(errorFile, "%s is not defined at line: %d\n",(yyvsp[(1) - (1)].id),linecount);
                }
            }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 279 "zzh.y"
    { fprintf(treeFile, "expression --> ( expression )\n"); (yyval.intVal) = (yyvsp[(2) - (3)].intVal); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 280 "zzh.y"
    { fprintf(treeFile, "expression --> expression + expression\n"); (yyval.intVal) = (yyvsp[(1) - (3)].intVal) + (yyvsp[(3) - (3)].intVal);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 281 "zzh.y"
    { fprintf(treeFile, "expression --> expression - expression\n"); (yyval.intVal) = (yyvsp[(1) - (3)].intVal) - (yyvsp[(3) - (3)].intVal); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 282 "zzh.y"
    { fprintf(treeFile, "expression --> expression * expression\n"); (yyval.intVal) = (yyvsp[(1) - (3)].intVal) * (yyvsp[(3) - (3)].intVal); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 283 "zzh.y"
    { fprintf(treeFile, "expression --> expression / expression\n"); (yyval.intVal) = (yyvsp[(1) - (3)].intVal) / (yyvsp[(3) - (3)].intVal); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 286 "zzh.y"
    { fprintf(treeFile, "expression2 --> %s\n", (yyvsp[(1) - (1)].strVal));  strcpy((yyval.strVal), (yyvsp[(1) - (1)].strVal)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 287 "zzh.y"
    { fprintf(treeFile, "expression2 --> ( expression2 )\n"); strcpy((yyval.strVal), (yyvsp[(2) - (3)].strVal)); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 288 "zzh.y"
    { fprintf(treeFile, "expression2 --> expression2 + expression2\n"); (yyval.strVal) = string_add((yyvsp[(1) - (3)].strVal), (yyvsp[(3) - (3)].strVal)); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 289 "zzh.y"
    { fprintf(treeFile, "expression2 --> expression2 - expression2\n"); (yyval.strVal) = string_subtract((yyvsp[(1) - (3)].strVal), (yyvsp[(3) - (3)].strVal)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 295 "zzh.y"
    {
        if(isif==0)
        printf("%s\n", (yyvsp[(3) - (4)].strVal));  // 打印字符串内容;

        else
        {   
            if(if_flag!=0&&isif==1){
            // printf("if语句中的输出:");
            printf("%s\n", (yyvsp[(3) - (4)].strVal));  // 打印字符串内容
            }
        }
        }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 308 "zzh.y"
    {
        
        if(isif==0)
        printf("%d\n", (yyvsp[(3) - (4)].intVal));  // 打印字符串内容;
            
         else
            {   if(if_flag!=0)   
                { printf("%d\n", (yyvsp[(3) - (4)].intVal));  // 打印表达式的值
                }
            }
    }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 320 "zzh.y"
    {
        {
        
        if(isif==0)
        printf("%s\n", (yyvsp[(3) - (4)].strVal));  // 打印字符串内容;
            
         else
            {              
                if(if_flag!=0&&isif==1){
                printf("%s\n", (yyvsp[(3) - (4)].strVal));  // 打印字符串内容
            }
            }
        }
    }
    break;



/* Line 1455 of yacc.c  */
#line 2025 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 336 "zzh.y"


char* string_add(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1);  // 分配内存
    strcpy(result, str1);  // 复制第一个字符串
    strcat(result, str2);  // 拼接第二个字符串
    return result;
}

// 字符串减法函数
char* string_subtract(const char* str1, const char* str2) {
    // 查找str2在str1中的位置
    char* pos = strstr(str1, str2);
    if (!pos) {
        // 如果没有找到匹配的部分，直接返回原字符串
        return strdup(str1);  // strdup会复制并返回一个新的字符串
    }

    // 计算删除str2后，剩余部分的长度
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t result_len = len1 - len2;

    // 为结果分配内存，包含终止符
    char* result = (char*)malloc(result_len + 1);
    if (!result) {
        // 内存分配失败时处理
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // 将str1中str2之前的部分复制到result
    size_t prefix_len = pos - str1;
    strncpy(result, str1, prefix_len);

    // 将str2之后的部分复制到result
    strcpy(result + prefix_len, pos + len2);

    return result;
}

void yyerror(char *msg) {
    //printf("msg = %s at line %d\n",msg,linecount);
    fprintf(stderr, "Error: %s at line %d\n", msg, linecount);
    fprintf(errorFile, "Error: %s at line %d\n", msg, linecount);
}

int yywrap() {
    return 1;
}

void pushType(int idNum,int type){
    if(isPushType == 1){
        struct word *current = word_list;
        for(int i=0;i<idNum;i++){
            if(current == NULL){
                printf("error: IDList is too large\n");
                fprintf(errorFile, "error: IDList is too large at line: %d\n",linecount);
                return;
            }
            current->word_type = type;
            switch(type){
                case 1:
                    current->value.int_value = 0;
                    break;
                case 2:
                    current->value.double_value = 0;
                    break;
                case 3:
                    current->value.string_value = NULL;
                    break;
                case 4:
                    current->value.int_value = 1;
                    break;
            }
            //printf("%d: id = %s , type = %d\n",linecount,current->word_name,current->word_type);
            current = current->next;
        }
    }else{
        isPushType = 1;
    }
}

void free_list(struct word *head) {
    struct word *current = head;
    struct word *next;

    while (current != NULL) {
        next = current->next; // 保存下一个节点的指针

        // 如果节点中有动态分配的字段（如字符串），先释放它
        if (current->word_name != NULL) {
            free(current->word_name);
        }

        // 释放当前节点
        free(current);

        // 移动到下一个节点
        current = next;
    }
}

struct word * isExist(char *word){
    struct word *wp = word_list;

    while(wp!=NULL){
        if(strcmp(wp->word_name, word) == 0){
            return wp;
        }
        wp = wp->next;
    }

    return NULL;
}

void outputIDS(){

	FILE* file = fopen("./output/IDFile.txt", "w");

    if (file == NULL) {
        fprintf(stderr, "failed to create IDFile.txt\n");
        printf("failed to create IDFile.txt\n");
        exit(1);
    }else{
        char *name = "name";
        char *type = "type";
        char *value = "value";
        fprintf(file, "%-15s %-15s %-15s\n", name, type, value);
        struct word *wp = word_list;
        while(wp!=NULL){
            int type = wp->word_type;
            switch(type){
                case 1:
                    fprintf(file, "%-15s %-15s %-15d\n", wp->word_name, "int", wp->value.int_value);
                    break;
                case 2:
                    fprintf(file, "%-15s %-15s %-15f\n", wp->word_name, "double", wp->value.double_value);
                    break;
                case 3:
                    if(wp->value.string_value == NULL){
                        fprintf(file, "%-15s %-15s %-15s\n", wp->word_name, "string", "NULL");
                    }else{
                        fprintf(file, "%-15s %-15s %-15s\n", wp->word_name, "string", wp->value.string_value);
                    }
                    break;
                case 4:
                    if(wp->value.int_value == 1){
                        fprintf(file, "%-15s %-15s %-15s\n", wp->word_name, "bool", "true");
                    }else{
                        fprintf(file, "%-15s %-15s %-15s\n", wp->word_name, "bool", "false");
                    }
                    break;
            }
            wp = wp->next;
        }

    }

    fclose(file);
} 

void createOutputFolder(){
    const char *folder = "output";

    // 检查文件夹是否存在
    if (ACCESS(folder, 0) != 0) {
        // 文件夹不存在，创建文件夹
        if (MKDIR(folder) != 0) {
            fprintf(stderr, "failed to create Folder output\n");
            printf("failed to create Folder output\n");
            exit(1);
        }
    } 
}

int main(int argc, char **argv) {

    createOutputFolder();
    
    treeFile = fopen("./output/tree.txt", "w");
    errorFile = fopen("./output/error.txt", "w");
    tokenFile = fopen("./output/tokenFile.txt", "w");

    fprintf(tokenFile , "%-15s%-15s%-15s\n", "line", "token", "name");

    if (!treeFile) {
        fprintf(stderr, "Could not open tree.txt\n");
        printf("Could not open tree.txt\n");
        return 1;
    }

    if (!errorFile) {
        fprintf(stderr, "Could not open error.txt\n");
        printf("Could not open error.txt\n");
        return 1;
    }

    if (!tokenFile) {
        fprintf(stderr, "Could not open tokenFile.txt\n");
        printf("Could not open tokenFile.txt\n");
        return 1;
    }
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            fclose(treeFile);
            fclose(errorFile);
            fclose(tokenFile);
            fclose(file);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    outputIDS();
    free_list(word_list);
    fclose(treeFile);
    fclose(errorFile);
    fclose(tokenFile);
    return 0;
}

