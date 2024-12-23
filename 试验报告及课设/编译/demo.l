%{
#include "demo.tab.h"
#include <string.h>

void yyerror(char *msg);

extern int linecount;

%}

%%
[\n]+               { linecount++; }
[ \t]+              /* 忽略空白字符 */
"var"               { return VAR; }
"if"                { return IF; }
"else"              { return ELSE; }
"for"               { return FOR; }
"while"             { return WHILE; }
"int"               { return INT; }
"double"            { return DOUBLE; }
"string"            { return STRING; }
"bool"              { return BOOL; }
":"                 { return COLON; }
"="                 { return ASSIGN; }
"=="                { return EQ; }
"!="                { return NE; }
"<="                { return LE; }
">="                { return GE; }
"<"                 { return LT; }
">"                 { return GT; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
","                 { return COMMA; }
-?[0-9]+            { yylval.intVal = atoi(yytext); return NUMBER; }
-?[0-9]+\.[0-9]+    { yylval.doubleVal = atof(yytext); return NUMBER; }
\"[^"\n]*\"         { yylval.strVal = strdup(yytext); return STR; }
[A-Za-z_][A-Za-z0-9_]* { yylval.id = strdup(yytext); return ID; }
\/\/.*              { /* 忽略注释 */ }
.                   { printf("%s: lexical error\n", yytext); }

%%

