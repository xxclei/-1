%{
#include "parser.h" // 包含由bison生成的头文件
%}

%%

if                 { return IF; }
repeat             { return REPEAT; }
read               { return READ; }
write              { return WRITE; }
if                 { return IF; }
else               { return ELSE; }
until              { return UNTIL; }
[0-9]+             { yylval = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval = strdup(yytext); return IDENTIFIER; }
"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MULTIPLY; }
"/"                { return DIVIDE; }
"="                { return EQUAL; }
"<"                { return LESS; }
">"                { return GREATER; }
"("                { return LPAREN; }
")"                { return RPAREN; }
";"                { return SEMICOLON; }
":"                { return COLON; }
"="                { return ASSIGN; }
[ \t\n]+           { /* 忽略空格、制表符和换行符 */ }
.                  { /* 其他字符报错 */ }

%%

int yywrap() {
    return 1;
}