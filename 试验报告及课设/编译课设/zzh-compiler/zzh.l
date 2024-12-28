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
extern FILE *errorFile;
extern FILE *tokenFile;
extern int isPushType;

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
"var"               { num = 0; isStatement = 1; fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return VAR; }
"if"                { isif=1; fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return IF; }
"else"              { if_flag=!if_flag; fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return ELSE; }
"for"               { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return FOR; }
"while"             { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return WHILE; }
"int"               { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return INT; }
"double"            { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return DOUBLE; }
"string"            { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return STRING; }
"bool"              { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return BOOL; }
"print"             { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Key Word",yytext); return PRINT; }
":"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return COLON; }
"="                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return ASSIGN; }
"=="                { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return EQ; }
"!="                { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return NE; }
"<="                { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return LE; }
">="                { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return GE; }
"<"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return LT; }
">"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return GT; }
"["                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return LBRACKET; }
"]"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return RBRACKET; }
"("                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return LPAREN; }
")"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return RPAREN; }
"{"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return LBRACE; }
"}"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return RBRACE; }
","                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Specail Word",yytext); return COMMA; }
"+"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return PLUS; }
"-"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return MINUS; }
"*"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return MULT; }
"/"                 { fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"Operator",yytext); return DIV; }
-?[0-9]+            { yylval.intVal = atoi(yytext); fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"NUM",yytext); return NUMBER; }
-?[0-9]+\.[0-9]+    { yylval.doubleVal = atof(yytext); fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"NUM",yytext); return DNUM; }
\"([^\"\\\n]|\\.)*\"  {  // 匹配带引号的字符串
    int len = strlen(yytext);
    
    // 去掉两端的引号
    yytext[len - 1] = '\0';  // 去掉结尾的引号
    memmove(yytext, yytext + 1, len - 1);  // 移动字符以去掉开头的引号

    yylval.strVal = strdup(yytext);  // 去掉引号后的字符串传递给语法分析器
    fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"STR",yytext);
    return STR;
}
[A-Za-z_][A-Za-z0-9_]*  {  
                            if(isStatement==1){
                                num++; 
                                idNum = num;
                                yylval.id = strdup(yytext); 
                                if(add_word(0, yytext) == 0){
                                    //printf("error: %s is already declared\n", yytext);
                                    fprintf(errorFile, "error: %s is already declared at line: %d\n", yytext,linecount);
                                    isPushType = 0;
                                }
                            }else{
                                yylval.id = strdup(yytext); 
                            }
                            fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"ID",yytext);
                            return ID; 
                        }
\/\/[^\n]*          { /* 忽略注释 */ fprintf(tokenFile, "%-15d%-15s%-15s\n",linecount,"no meaning",yytext); }
.                   {   
                        //printf("%s: lexical error\n", yytext); 
                        fprintf(errorFile, "%s: lexical error at line: %d\n", yytext,linecount); 
                    }

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