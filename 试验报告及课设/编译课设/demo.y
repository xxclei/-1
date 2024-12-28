%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_NAME(x) _Generic((x), \
    int: 1, \
    double: 2, \
    char*: 3 )

void yyerror(char *msg);
int yylex();

FILE *treeFile;

extern FILE *yyin;

int linecount = 1;
int isif=0;
int iselse=0;
int isStatement = 0;

int idNum = 0;
int if_flag=1;


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

%}

%union {
    int intVal;
    double doubleVal;
    char* strVal;
    char* id;
}

/* 终结符 */
%token <id> ID
%token <intVal> NUMBER
%token <strVal> STR
%token VAR IF ELSE FOR WHILE INT DOUBLE STRING BOOL
%token PLUS MINUS MULT DIV
%token ASSIGN EQ NE LT GT LE GE COLON COMMA LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE PRINT
/* 优先级 */
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULT DIV

/* 非终结符 */
%type <intVal> expression
%type <strVal> expression2
%type <id> id_list type array_dimensions
%type <strVal> statement_list 
%type <intVal> condition
%type <strVal> if_statement 
%type <strVal> print_statement



%%
program: statement_list{ fprintf(treeFile, "program --> statement_list\n");}
        ;

statement_list: statement statement_list{ fprintf(treeFile, "statement_list --> statement statement_list\n");}
              | /* 空 */{ fprintf(treeFile, "statement_list --> ε\n");}
              ;

statement: variable_declaration{ fprintf(treeFile, "statement --> variable_declaration\n");}
         | assignment{ fprintf(treeFile, "statement --> assignment\n");}
         | if_statement{ fprintf(treeFile, "statement --> if_statement\n");}
         | loop_statement{ fprintf(treeFile, "statement --> loop_statement\n");}
         | print_statement{ fprintf(treeFile, "statement --> print_statement\n"); }
         ;

variable_declaration: VAR id_list type{ fprintf(treeFile, "variable_declaration --> var id_list type\n");}
                    | VAR id_list type ASSIGN expression{ fprintf(treeFile, "variable_declaration --> var id_list type = expression\n");}
                    ;

id_list: ID { isStatement = 0; fprintf(treeFile, "id_list --> %s\n",$1);}
       | ID COMMA id_list { fprintf(treeFile, "id_list --> %s , id_list\n",$1);}
       ;

type: INT{
            pushType(idNum,1);
            fprintf(treeFile, "type --> int\n");
         }
    | DOUBLE{
                pushType(idNum,2); 
                fprintf(treeFile, "type --> double\n");
            }
    | STRING{ 
                pushType(idNum,3); 
                fprintf(treeFile, "type --> string\n");
            }
    | BOOL  { 
                pushType(idNum,4); 
                fprintf(treeFile, "type --> bool\n");
            }
    | INT array_dimensions{ fprintf(treeFile, "type --> int array_dimensions\n");}
    | DOUBLE array_dimensions{ fprintf(treeFile, "type --> double array_dimensions\n");}
    ;

array_dimensions: LBRACKET NUMBER RBRACKET{ fprintf(treeFile, "array_dimensions --> [ %d ]\n",$2);}
                | LBRACKET NUMBER RBRACKET array_dimensions{ fprintf(treeFile, "array_dimensions --> [ %d ] array_dimensions\n",$2);}
                ;

assignment: ID ASSIGN expression{       
    // printf("isif=%d  isflag=%d",isif,if_flag);
                                        
                                        if(!isif)
                                        {
                                        char * name = $1;
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME($3);
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.int_value = $3; 
                                                printf("%s:%d\n",$1,w->value.int_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",$1);
                                        }

                                        else
                                            {if(if_flag!=0){
                                                // {printf("if语句中的赋值:");
                                                char * name = $1;
                                                struct word *w = isExist(name);
                                                int type = TYPE_NAME($3);
                                                if(w != NULL){
                                                    if(w->word_type == type){
                                                        w->value.int_value = $3; 
                                                        printf("%s:%d\n",$1,w->value.int_value);
                                                    }else{
                                                        printf("error: %s's type mismatch\n",name);
                                                    }
                                                }
                                                fprintf(treeFile, "assignment --> %s = expression\n",$1);
                                                }
                                        }
                                }
          ;

if_statement: IF LPAREN condition RPAREN LBRACE statement_list RBRACE{ 
    isif=0;
    fprintf(treeFile, "if_statement --> if ( condition ) { statement_list }\n");
            if ($3) {  // 如果条件为真
            if_flag=1;
                // printf("执行if\n");
                $$=$6;
            }
            else{
                // printf("if_statement不执行\n");
            $$="NULL";}
}
            | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
            {   isif=0;
                fprintf(treeFile, "if_statement --> if ( condition ) { statement_list } else { statement_list }\n");
                        if ($3) {  // 如果条件为真
                        if_flag=1;
                // printf("执行if\n");
                $$=$6;
            } else {
                if_flag=0;
                // printf("执行else\n");
                $$=$10;
            }
            }
            ;

loop_statement: FOR ID COLON ID LBRACE statement_list RBRACE /* 增强型 for 循环 */{ fprintf(treeFile, "loop_statement --> for %s : %s { statement_list }\n", $2, $4);}
              | WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE{ fprintf(treeFile, "loop_statement --> while ( condition ) { statement_list }\n");while($3){printf("执行while循环");$6;}}
              ;

condition: expression EQ expression { fprintf(treeFile, "condition --> expression == expression\n");if_flag=($1 == $3);$$ = ($1 == $3);}
         | expression NE expression { fprintf(treeFile, "condition --> expression != expression\n");if_flag=($1 != $3);$$ = ($1 != $3); }
         | expression LT expression { fprintf(treeFile, "condition --> expression < expression\n");if_flag=($1 < $3);$$ = ($1 < $3); }
         | expression LE expression { fprintf(treeFile, "condition --> expression <= expression\n");if_flag=($1 <= $3);$$ = ($1 <= $3);}
         | expression GT expression { fprintf(treeFile, "condition --> expression > expression\n"); if_flag=($1 > $3);$$ = ($1 > $3);}
         | expression GE expression { fprintf(treeFile, "condition --> expression >= expression\n");if_flag=($1 >= $3);$$ = ($1 >= $3); }
         | expression2 EQ expression2 { fprintf(treeFile, "condition --> expression >= expression\n");if_flag=(strcmp($1,$3));$$ = (strcmp($1,$3)); }
        ;

expression: NUMBER { fprintf(treeFile, "expression --> %d\n", $1); $$ = $1; }
          | ID { 
                fprintf(treeFile, "expression --> %s\n", $1); 
                struct word *w = isExist($1);
                if(w != NULL){
                    if(w->word_type == 1){
                        $$ = w->value.int_value; 
                    }else{
                    
                        printf("error: %s's type mismatch\n",$1);
                    }
                }else{
                    printf("%s is not defined\n",$1);
                }
            }




          | LPAREN expression RPAREN { fprintf(treeFile, "expression --> ( expression )\n"); $$ = $2; }
          | expression PLUS expression { fprintf(treeFile, "expression --> expression + expression\n"); $$ = $1 + $3;}
          | expression MINUS expression { fprintf(treeFile, "expression --> expression - expression\n"); $$ = $1 - $3; }
          | expression MULT expression { fprintf(treeFile, "expression --> expression * expression\n"); $$ = $1 * $3; }
          | expression DIV expression { fprintf(treeFile, "expression --> expression / expression\n"); $$ = $1 / $3; }
          ;

expression2:
    LPAREN expression2 RPAREN {
        fprintf(treeFile, "expression --> ( expression )\n");
        $$ = $2;
    }
    | expression2 PLUS expression2 {
        fprintf(treeFile, "expression --> expression + expression\n");
        $$ = string_add($1, $3);  // 拼接字符串
    }
    | expression2 MINUS expression2 {
        fprintf(treeFile, "expression --> expression - expression\n");
        $$ = string_subtract($1, $3);  // 减去字符串
    }
    | STR {
        
        fprintf(treeFile, "expression --> STRING: %s\n", $1);
        $$ = $1;  // 直接返回字符串
    }
;

        
print_statement:
     PRINT LPAREN expression RPAREN
    {
        
        if(isif==0)
        printf("%d\n", $3);  // 打印字符串内容;
            
         else
            {   if(if_flag!=0)   
                { printf("%d\n", $3);  // 打印表达式的值
                }
            }
    }
    | PRINT LPAREN expression2 RPAREN
    {
        
       if(isif==0)
        printf("%s\n", $3);  // 打印字符串内容;

        else
        {   
            if(if_flag!=0&&isif==1){
            // printf("if语句中的输出:");
            printf("%s\n", $3);  // 打印字符串内容
            }
        }
    }
        
    ;

%%

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
        printf("%d: id = %s , type = %d\n",linecount,current->word_name,current->word_type);
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
