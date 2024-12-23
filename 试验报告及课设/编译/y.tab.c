/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "demo3.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *msg);
int yylex();

FILE *treeFile;

extern FILE *yyin;

int linecount = 1;

int isStatement = 0;

int idNum = 0;


struct word {
    char *word_name;
    int word_type;
    struct word *next;
};

// 语句结构体定义


struct word *word_list = NULL;

void pushType(int idNum,int type);

void free_list(struct word *head);


#line 107 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    NUMBER = 259,                  /* NUMBER  */
    STR = 260,                     /* STR  */
    VAR = 261,                     /* VAR  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    FOR = 264,                     /* FOR  */
    WHILE = 265,                   /* WHILE  */
    INT = 266,                     /* INT  */
    DOUBLE = 267,                  /* DOUBLE  */
    STRING = 268,                  /* STRING  */
    BOOL = 269,                    /* BOOL  */
    ASSIGN = 270,                  /* ASSIGN  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    LT = 273,                      /* LT  */
    GT = 274,                      /* GT  */
    LE = 275,                      /* LE  */
    GE = 276,                      /* GE  */
    COLON = 277,                   /* COLON  */
    COMMA = 278,                   /* COMMA  */
    LBRACKET = 279,                /* LBRACKET  */
    RBRACKET = 280,                /* RBRACKET  */
    LPAREN = 281,                  /* LPAREN  */
    RPAREN = 282,                  /* RPAREN  */
    LBRACE = 283,                  /* LBRACE  */
    RBRACE = 284,                  /* RBRACE  */
    PRINT = 285,                   /* PRINT  */
    PLUS = 286,                    /* PLUS  */
    MINUS = 287,                   /* MINUS  */
    MULT = 288,                    /* MULT  */
    DIV = 289                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define NUMBER 259
#define STR 260
#define VAR 261
#define IF 262
#define ELSE 263
#define FOR 264
#define WHILE 265
#define INT 266
#define DOUBLE 267
#define STRING 268
#define BOOL 269
#define ASSIGN 270
#define EQ 271
#define NE 272
#define LT 273
#define GT 274
#define LE 275
#define GE 276
#define COLON 277
#define COMMA 278
#define LBRACKET 279
#define RBRACKET 280
#define LPAREN 281
#define RPAREN 282
#define LBRACE 283
#define RBRACE 284
#define PRINT 285
#define PLUS 286
#define MINUS 287
#define MULT 288
#define DIV 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "demo3.y"

    int intVal;
    double doubleVal;
    char* strVal;
    char* id;

    struct Statement* stmt;  // 语句指针类型

#line 237 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_STR = 5,                        /* STR  */
  YYSYMBOL_VAR = 6,                        /* VAR  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_FOR = 9,                        /* FOR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_BOOL = 14,                      /* BOOL  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NE = 17,                        /* NE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_LE = 20,                        /* LE  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_COLON = 22,                     /* COLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 29,                    /* RBRACE  */
  YYSYMBOL_PRINT = 30,                     /* PRINT  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_MULT = 33,                      /* MULT  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_statement_list = 37,            /* statement_list  */
  YYSYMBOL_statement = 38,                 /* statement  */
  YYSYMBOL_variable_declaration = 39,      /* variable_declaration  */
  YYSYMBOL_id_list = 40,                   /* id_list  */
  YYSYMBOL_type = 41,                      /* type  */
  YYSYMBOL_array_dimensions = 42,          /* array_dimensions  */
  YYSYMBOL_assignment = 43,                /* assignment  */
  YYSYMBOL_if_statement = 44,              /* if_statement  */
  YYSYMBOL_loop_statement = 45,            /* loop_statement  */
  YYSYMBOL_condition = 46,                 /* condition  */
  YYSYMBOL_expression = 47,                /* expression  */
  YYSYMBOL_print_statement = 48            /* print_statement  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   93

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  89

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    72,    73,    76,    77,    78,    79,    80,
      83,    84,    87,    88,    91,    95,    99,   103,   107,   108,
     111,   112,   115,   119,   128,   140,   144,   151,   152,   153,
     154,   155,   156,   159,   160,   161,   162,   163,   164,   165,
     167,   171
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMBER", "STR",
  "VAR", "IF", "ELSE", "FOR", "WHILE", "INT", "DOUBLE", "STRING", "BOOL",
  "ASSIGN", "EQ", "NE", "LT", "GT", "LE", "GE", "COLON", "COMMA",
  "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "PRINT",
  "PLUS", "MINUS", "MULT", "DIV", "$accept", "program", "statement_list",
  "statement", "variable_declaration", "id_list", "type",
  "array_dimensions", "assignment", "if_statement", "loop_statement",
  "condition", "expression", "print_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      14,    -4,     9,   -12,    12,   -10,    -8,    19,   -30,    14,
     -30,   -30,   -30,   -30,   -30,     6,    -1,    49,     6,     3,
       6,     0,   -30,   -30,   -30,   -30,     6,    51,     9,    10,
      10,   -30,   -30,    20,    38,    37,    24,    45,    46,    18,
      47,     6,     6,     6,     6,   -30,    29,   -30,   -30,     6,
      36,     6,     6,     6,     6,     6,     6,    48,    58,   -30,
     -30,   -30,   -27,   -27,   -30,   -30,    21,    51,    14,    51,
      51,    51,    51,    51,    51,    14,    14,    10,     8,    59,
      60,   -30,    39,   -30,   -30,    62,    14,    63,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     0,     0,     0,     0,     2,     4,
       5,     6,     7,     8,     9,     0,    12,     0,     0,     0,
       0,     0,     1,     3,    34,    33,     0,    22,     0,    14,
      15,    16,    17,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    40,
      41,    35,    36,    37,    38,    39,     0,    11,     4,    27,
      28,    29,    31,    30,    32,     4,     4,    20,     0,     0,
       0,    21,    23,    25,    26,     0,     4,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,    -9,   -30,   -30,    65,   -30,   -29,   -30,   -30,
     -30,    55,   -13,   -30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    17,    33,    47,    11,    12,
      13,    34,    35,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    48,    27,    24,    25,    38,    43,    44,    39,    24,
      25,    15,    16,    40,    18,    19,    20,     1,    21,    22,
       2,     3,    28,     4,     5,    36,    26,    57,    62,    63,
      64,    65,    26,    66,    46,    49,    67,    82,    69,    70,
      71,    72,    73,    74,     6,    60,    77,    85,    81,    41,
      42,    43,    44,    51,    52,    53,    54,    55,    56,    78,
      29,    30,    31,    32,    68,    50,    79,    80,    41,    42,
      43,    44,    58,    59,    61,    37,    75,    87,    41,    42,
      43,    44,    41,    42,    43,    44,    76,     0,    83,    84,
      86,     0,    88,    45
};

static const yytype_int8 yycheck[] =
{
       9,    30,    15,     3,     4,     5,    33,    34,    21,     3,
       4,    15,     3,    26,    26,     3,    26,     3,    26,     0,
       6,     7,    23,     9,    10,    22,    26,     3,    41,    42,
      43,    44,    26,     4,    24,    15,    49,    29,    51,    52,
      53,    54,    55,    56,    30,    27,    25,     8,    77,    31,
      32,    33,    34,    16,    17,    18,    19,    20,    21,    68,
      11,    12,    13,    14,    28,    27,    75,    76,    31,    32,
      33,    34,    27,    27,    27,    20,    28,    86,    31,    32,
      33,    34,    31,    32,    33,    34,    28,    -1,    29,    29,
      28,    -1,    29,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     7,     9,    10,    30,    36,    37,    38,
      39,    43,    44,    45,    48,    15,     3,    40,    26,     3,
      26,    26,     0,    37,     3,     4,    26,    47,    23,    11,
      12,    13,    14,    41,    46,    47,    22,    46,     5,    47,
      47,    31,    32,    33,    34,    40,    24,    42,    42,    15,
      27,    16,    17,    18,    19,    20,    21,     3,    27,    27,
      27,    27,    47,    47,    47,    47,     4,    47,    28,    47,
      47,    47,    47,    47,    47,    28,    28,    25,    37,    37,
      37,    42,    29,    29,    29,     8,    28,    37,    29
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      39,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      42,    42,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    47,    47,    47,    47,    47,    47,    47,
      48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     5,     1,     3,     1,     1,     1,     1,     2,     2,
       3,     4,     3,     7,    11,     7,     7,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       4,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 2: /* program: statement_list  */
#line 69 "demo3.y"
                       { fprintf(treeFile, "program --> statement_list\n");}
#line 1315 "y.tab.c"
    break;

  case 3: /* statement_list: statement statement_list  */
#line 72 "demo3.y"
                                        { fprintf(treeFile, "statement_list --> statement statement_list\n");}
#line 1321 "y.tab.c"
    break;

  case 4: /* statement_list: %empty  */
#line 73 "demo3.y"
                         { fprintf(treeFile, "statement_list --> ε\n");}
#line 1327 "y.tab.c"
    break;

  case 5: /* statement: variable_declaration  */
#line 76 "demo3.y"
                               { fprintf(treeFile, "statement --> variable_declaration\n");}
#line 1333 "y.tab.c"
    break;

  case 6: /* statement: assignment  */
#line 77 "demo3.y"
                     { fprintf(treeFile, "statement --> assignment\n");}
#line 1339 "y.tab.c"
    break;

  case 7: /* statement: if_statement  */
#line 78 "demo3.y"
                       { fprintf(treeFile, "statement --> if_statement\n");}
#line 1345 "y.tab.c"
    break;

  case 8: /* statement: loop_statement  */
#line 79 "demo3.y"
                         { fprintf(treeFile, "statement --> loop_statement\n");}
#line 1351 "y.tab.c"
    break;

  case 9: /* statement: print_statement  */
#line 80 "demo3.y"
                          { fprintf(treeFile, "statement --> print_statement\n"); }
#line 1357 "y.tab.c"
    break;

  case 10: /* variable_declaration: VAR id_list type  */
#line 83 "demo3.y"
                                      { fprintf(treeFile, "variable_declaration --> var id_list type\n");}
#line 1363 "y.tab.c"
    break;

  case 11: /* variable_declaration: VAR id_list type ASSIGN expression  */
#line 84 "demo3.y"
                                                        { fprintf(treeFile, "variable_declaration --> var id_list type = expression\n");}
#line 1369 "y.tab.c"
    break;

  case 12: /* id_list: ID  */
#line 87 "demo3.y"
            { isStatement = 0; fprintf(treeFile, "id_list --> %s\n",(yyvsp[0].id));}
#line 1375 "y.tab.c"
    break;

  case 13: /* id_list: ID COMMA id_list  */
#line 88 "demo3.y"
                          { fprintf(treeFile, "id_list --> %s , id_list\n",(yyvsp[-2].id));}
#line 1381 "y.tab.c"
    break;

  case 14: /* type: INT  */
#line 91 "demo3.y"
         {
            pushType(idNum,1);
            fprintf(treeFile, "type --> int\n");
         }
#line 1390 "y.tab.c"
    break;

  case 15: /* type: DOUBLE  */
#line 95 "demo3.y"
            {
                pushType(idNum,2); 
                fprintf(treeFile, "type --> double\n");
            }
#line 1399 "y.tab.c"
    break;

  case 16: /* type: STRING  */
#line 99 "demo3.y"
            { 
                pushType(idNum,3); 
                fprintf(treeFile, "type --> string\n");
            }
#line 1408 "y.tab.c"
    break;

  case 17: /* type: BOOL  */
#line 103 "demo3.y"
            { 
                pushType(idNum,4); 
                fprintf(treeFile, "type --> bool\n");
            }
#line 1417 "y.tab.c"
    break;

  case 18: /* type: INT array_dimensions  */
#line 107 "demo3.y"
                          { fprintf(treeFile, "type --> int array_dimensions\n");}
#line 1423 "y.tab.c"
    break;

  case 19: /* type: DOUBLE array_dimensions  */
#line 108 "demo3.y"
                             { fprintf(treeFile, "type --> double array_dimensions\n");}
#line 1429 "y.tab.c"
    break;

  case 20: /* array_dimensions: LBRACKET NUMBER RBRACKET  */
#line 111 "demo3.y"
                                          { fprintf(treeFile, "array_dimensions --> [ %d ]\n",(yyvsp[-1].intVal));}
#line 1435 "y.tab.c"
    break;

  case 21: /* array_dimensions: LBRACKET NUMBER RBRACKET array_dimensions  */
#line 112 "demo3.y"
                                                           { fprintf(treeFile, "array_dimensions --> [ %d ] array_dimensions\n",(yyvsp[-2].intVal));}
#line 1441 "y.tab.c"
    break;

  case 22: /* assignment: ID ASSIGN expression  */
#line 115 "demo3.y"
                                { fprintf(treeFile, "assignment --> %s = expression\n",(yyvsp[-2].id));}
#line 1447 "y.tab.c"
    break;

  case 23: /* if_statement: IF LPAREN condition RPAREN LBRACE statement_list RBRACE  */
#line 120 "demo3.y"
        {   
            if ((yyvsp[-4].intVal)) {  // 如果条件为真
                printf("执行if\n");
                (yyval.strVal)=(yyvsp[-1].strVal);
            }
            else{printf("if_statement不执行\n");}
            
        }
#line 1460 "y.tab.c"
    break;

  case 24: /* if_statement: IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE  */
#line 129 "demo3.y"
        {
            if ((yyvsp[-8].intVal)) {  // 如果条件为真
                printf("执行if\n");
                (yyval.strVal)=(yyvsp[-5].strVal);
            } else {
                printf("执行else\n");
                (yyval.strVal)=(yyvsp[-1].strVal);
            }
        }
#line 1474 "y.tab.c"
    break;

  case 25: /* loop_statement: FOR ID COLON ID LBRACE statement_list RBRACE  */
#line 141 "demo3.y"
{ fprintf(treeFile, "loop_statement --> for %s : %s { statement_list }\n", (yyvsp[-5].id), (yyvsp[-3].id));

}
#line 1482 "y.tab.c"
    break;

  case 26: /* loop_statement: WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE  */
#line 144 "demo3.y"
                                                                          { fprintf(treeFile, "loop_statement --> while ( condition ) { statement_list }\n");
              while((yyvsp[-4].intVal)){printf("执行while循环");(yyvsp[-1].strVal);}
              }
#line 1490 "y.tab.c"
    break;

  case 27: /* condition: expression EQ expression  */
#line 151 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression == expression\n");(yyval.intVal) = ((yyvsp[-2].intVal) == (yyvsp[0].intVal));}
#line 1496 "y.tab.c"
    break;

  case 28: /* condition: expression NE expression  */
#line 152 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression != expression\n");(yyval.intVal) = ((yyvsp[-2].intVal) != (yyvsp[0].intVal)); }
#line 1502 "y.tab.c"
    break;

  case 29: /* condition: expression LT expression  */
#line 153 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression < expression\n");(yyval.intVal) = ((yyvsp[-2].intVal) < (yyvsp[0].intVal)); }
#line 1508 "y.tab.c"
    break;

  case 30: /* condition: expression LE expression  */
#line 154 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression <= expression\n");(yyval.intVal) = ((yyvsp[-2].intVal) <= (yyvsp[0].intVal));}
#line 1514 "y.tab.c"
    break;

  case 31: /* condition: expression GT expression  */
#line 155 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression > expression\n"); (yyval.intVal) = ((yyvsp[-2].intVal) > (yyvsp[0].intVal));}
#line 1520 "y.tab.c"
    break;

  case 32: /* condition: expression GE expression  */
#line 156 "demo3.y"
                                    { fprintf(treeFile, "condition --> expression >= expression\n");(yyval.intVal) = ((yyvsp[-2].intVal) >= (yyvsp[0].intVal)); }
#line 1526 "y.tab.c"
    break;

  case 33: /* expression: NUMBER  */
#line 159 "demo3.y"
                   { fprintf(treeFile, "expression --> %d\n", (yyvsp[0].intVal)); (yyval.intVal) = (yyvsp[0].intVal); }
#line 1532 "y.tab.c"
    break;

  case 34: /* expression: ID  */
#line 160 "demo3.y"
               { fprintf(treeFile, "expression --> %s\n", (yyvsp[0].id)); }
#line 1538 "y.tab.c"
    break;

  case 35: /* expression: LPAREN expression RPAREN  */
#line 161 "demo3.y"
                                     { fprintf(treeFile, "expression --> ( expression )\n"); (yyval.intVal) = (yyvsp[-1].intVal); }
#line 1544 "y.tab.c"
    break;

  case 36: /* expression: expression PLUS expression  */
#line 162 "demo3.y"
                                       { fprintf(treeFile, "expression --> expression + expression\n"); (yyval.intVal) = (yyvsp[-2].intVal) + (yyvsp[0].intVal); }
#line 1550 "y.tab.c"
    break;

  case 37: /* expression: expression MINUS expression  */
#line 163 "demo3.y"
                                        { fprintf(treeFile, "expression --> expression - expression\n"); (yyval.intVal) = (yyvsp[-2].intVal) - (yyvsp[0].intVal); }
#line 1556 "y.tab.c"
    break;

  case 38: /* expression: expression MULT expression  */
#line 164 "demo3.y"
                                       { fprintf(treeFile, "expression --> expression * expression\n"); (yyval.intVal) = (yyvsp[-2].intVal) * (yyvsp[0].intVal); }
#line 1562 "y.tab.c"
    break;

  case 39: /* expression: expression DIV expression  */
#line 165 "demo3.y"
                                      { fprintf(treeFile, "expression --> expression / expression\n"); (yyval.intVal) = (yyvsp[-2].intVal) / (yyvsp[0].intVal); }
#line 1568 "y.tab.c"
    break;

  case 40: /* print_statement: PRINT LPAREN STR RPAREN  */
#line 168 "demo3.y"
        {
            printf("%s\n", (yyvsp[-1].strVal));  // 打印字符串内容
        }
#line 1576 "y.tab.c"
    break;

  case 41: /* print_statement: PRINT LPAREN expression RPAREN  */
#line 172 "demo3.y"
        {
            printf("%d\n", (yyvsp[-1].intVal));  // 打印表达式的值
        }
#line 1584 "y.tab.c"
    break;


#line 1588 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 177 "demo3.y"



void yyerror(char *msg) {
    printf("msg = %s at line %d\n",msg,linecount);
    fprintf(stderr, "Error: %s at line %d\n", msg, linecount);
}

int yywrap() {
    return 1;
}



void pushType(int idNum,int type){
    struct word *current = word_list;
    for(int i=0;i<idNum;i++){
        if(current == NULL){
            printf("error: idNum is too large\n");
            return;
        }
        current->word_type = type;
        printf("\n%d: id = %s , type = %d\n",linecount,current->word_name,current->word_type);
        current = current->next;
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



int main(int argc, char **argv) {
    treeFile = fopen("tree.txt", "w");
    if (!treeFile) {
        fprintf(stderr, "Could not open tree.txt\n");
        return 1;
    }
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            fclose(treeFile);
            return 1;
        }
        yyin = file;
    }
    yyparse();
    free_list(word_list);
    fclose(treeFile);
    return 0;
}
