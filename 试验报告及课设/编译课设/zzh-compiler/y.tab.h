
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 72 "zzh.y"

    int intVal;
    double doubleVal;
    char* strVal;
    char* id;



/* Line 1676 of yacc.c  */
#line 131 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


