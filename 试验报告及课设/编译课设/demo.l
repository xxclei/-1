%{
#include "y.tab.h"
#include <string.h>

void yyerror(char *msg);

extern int linecount;

extern int isStatement;
extern int isif;
extern int iselse;
extern int if_flag;
extern int idNum;

int num = 0;

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

extern struct word *word_list;

int add_word(int type, char *word);

int lookup_word(char *word);

%}

%%
[\n]+               { linecount++; }
[ \t\r]+            /* 忽略空白字符 */
"var"               { num = 0; isStatement = 1; return VAR; }
"if"                { isif=1;return IF; }
"else"              { if_flag=!if_flag;return ELSE; }
"for"               { return FOR; }
"while"             { return WHILE; }
"int"               { return INT; }
"double"            { return DOUBLE; }
"string"            { return STRING; }
"bool"              { return BOOL; }
"print"             { return PRINT; }
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
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MULT; }
"/"                 { return DIV; }
-?[0-9]+            { yylval.intVal = atoi(yytext); return NUMBER; }
-?[0-9]+\.[0-9]+    { yylval.doubleVal = atof(yytext); return NUMBER; }
\"([^\"\\\n]|\\.)*\"  {  // 匹配带引号的字符串
    int len = strlen(yytext);
    
    // 去掉两端的引号
    yytext[len - 1] = '\0';  // 去掉结尾的引号
    memmove(yytext, yytext + 1, len - 1);  // 移动字符以去掉开头的引号

    yylval.strVal = strdup(yytext);  // 去掉引号后的字符串传递给语法分析器
    return STR;
}
[A-Za-z_][A-Za-z0-9_]*  {  
                            if(isStatement==1){
                                num++; 
                                idNum = num;
                                yylval.id = strdup(yytext); 
                                if(add_word(0, yytext) == 0){
                                    printf("error: %s is already declared\n", yytext);
                                }
                            }else{
                                yylval.id = strdup(yytext); 
                            }
                            return ID; 
                        }
\/\/.*              { /* 忽略注释 */ }
.                   { printf("%s: lexical error\n", yytext); }

%%

extern void *malloc();

int add_word(int type, char *word){
    struct word *wp;

    if(lookup_word(word) != 0){
        /* 该变量已经声明 */
        return 0;
    }

    /* 添加变量 */
    wp = (struct word *)malloc(sizeof(struct word));

    wp->next = word_list;

    wp->word_name = (char*)malloc(strlen(word)+1);
    strcpy(wp->word_name,word);
    wp->word_type = type;
    word_list = wp; 
    return 1;
}

/* 搜索变量名是否存在 ！！！若查找效率低，可以使用散列表代替链表 */
int lookup_word(char *word){
    struct word *wp = word_list;

    while(wp!=NULL){
        if(strcmp(wp->word_name, word) == 0){
            return 1;
        }
        wp = wp->next;
    }

    return 0;
}