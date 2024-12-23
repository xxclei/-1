%{
#include "y.tab.h"
#include <string.h>

void yyerror(char *msg);

extern int linecount;

extern int isStatement;

extern int idNum;

int num = 0;

struct word {
    char *word_name;
    int word_type;
    struct word *next;
};

extern struct word *word_list;

int add_word(int type, char *word);

int lookup_word(char *word);

%}

%%
[\n]+               { linecount++; printf("-----------------------------------linecount = %d\n",linecount);}
[ \t\r]+              /* 忽略空白字符 */
"var"               { num = 0; isStatement = 1; return VAR; }
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
"=="                { printf("detectEQ");return EQ; }
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
[A-Za-z_][A-Za-z0-9_]*  {  
                            printf("-----------------------------------isStatement = %d\n",isStatement);
                            if(isStatement==1){
                                num++; 
                                idNum = num;
                                yylval.id = strdup(yytext); 
                                if(add_word(0, yytext) == 0){
                                    printf("error: %s is already declared\n", yytext);
                                }
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
    if (wp == NULL) {
        fprintf(stderr, "Error: malloc failed to allocate memory for word.\n");
        return 0;  // 内存分配失败，返回错误
    }

    wp->word_name = (char*)malloc(strlen(word) + 1);
    if (wp->word_name == NULL) {
        fprintf(stderr, "Error: malloc failed to allocate memory for word name.\n");
        free(wp);  // 释放已经分配的内存
        return 0;  // 内存分配失败，返回错误
    }

    /* 拷贝单词名称 */
    strcpy(wp->word_name, word);
    wp->word_type = type;

    wp->next = word_list;  // 插入到链表的头部
    word_list = wp;  // 更新链表头

    return 1;
}

/* 搜索变量名是否存在 ！！！若查找效率低，可以使用散列表代替链表 */
int lookup_word(char *word){
    struct word *wp = word_list;

    while (wp != NULL) {
        if (strcmp(wp->word_name, word) == 0) {
            return 1;  // 找到变量
        }
        wp = wp->next;
    }

    return 0;  // 没有找到变量
}
