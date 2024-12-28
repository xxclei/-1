%{
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
%token <doubleVal> DNUM
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

assignment:  ID ASSIGN expression2{
                                    if(!isif){
                                        char * name = $1;
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME($3);
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.string_value = (char*)malloc(strlen($3) + 1); // +1 是为了 '\0'
                                                if (w->value.string_value == NULL) {
                                                    printf("%s's Memory allocation failed\n",w->word_name);
                                                    fprintf(errorFile, "%s's Memory allocation failed at line: %d\n",w->word_name,linecount);
                                                }
                                                strcpy(w->value.string_value, $3); 
                                                //printf("%s:%s\n",$1,w->value.string_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                                fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",$1);
                                    }
                                    else if(if_flag!=0){
                                        char * name = $1;
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME($3);
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.string_value = (char*)malloc(strlen($3) + 1); // +1 是为了 '\0'
                                                if (w->value.string_value == NULL) {
                                                    printf("%s's Memory allocation failed\n",w->word_name);
                                                    fprintf(errorFile, "%s's Memory allocation failed at line: %d\n",w->word_name,linecount);
                                                }
                                                strcpy(w->value.string_value, $3); 
                                                //printf("%s:%s\n",$1,w->value.string_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",$1);
                                    }
                                 }
          |  ID ASSIGN expression{       
                                        if(!isif){
                                        char * name = $1;
                                        struct word *w = isExist(name);
                                        int type = TYPE_NAME($3);
                                        if(w != NULL){
                                            if(w->word_type == type){
                                                w->value.int_value = $3; 
                                                //printf("%s:%d\n",$1,w->value.int_value);
                                            }else{
                                                printf("error: %s's type mismatch\n",name);
                                                fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                            }
                                        }
                                        fprintf(treeFile, "assignment --> %s = expression\n",$1);
                                        }
                                        else if(if_flag!=0){
                                                //printf("if语句中的赋值:");
                                                char * name = $1;
                                                struct word *w = isExist(name);
                                                int type = TYPE_NAME($3);
                                                if(w != NULL){
                                                    if(w->word_type == type){
                                                        w->value.int_value = $3; 
                                                        //printf("%s:%d\n",$1,w->value.int_value);
                                                    }else{
                                                        printf("error: %s's type mismatch\n",name);
                                                        fprintf(errorFile, "error: %s's type mismatch at line: %d\n",name,linecount);
                                                    }
                                                }
                                                fprintf(treeFile, "assignment --> %s = expression\n",$1);
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
              | WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE{ fprintf(treeFile, "loop_statement --> while ( condition ) { statement_list }\n");}
              ;

condition: expression EQ expression { fprintf(treeFile, "condition --> expression == expression\n");if_flag=($1 == $3);$$ = ($1 == $3);}
         | expression NE expression { fprintf(treeFile, "condition --> expression != expression\n");if_flag=($1 != $3);$$ = ($1 != $3); }
         | expression LT expression { fprintf(treeFile, "condition --> expression < expression\n");if_flag=($1 < $3);$$ = ($1 < $3); }
         | expression LE expression { fprintf(treeFile, "condition --> expression <= expression\n");if_flag=($1 <= $3);$$ = ($1 <= $3);}
         | expression GT expression { fprintf(treeFile, "condition --> expression > expression\n"); if_flag=($1 > $3);$$ = ($1 > $3);}
         | expression GE expression { fprintf(treeFile, "condition --> expression >= expression\n");if_flag=($1 >= $3);$$ = ($1 >= $3); }
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
                        fprintf(errorFile, "error: %s's type mismatch at line: %d\n",$1,linecount);
                    }
                }else{
                    printf("%s is not defined\n",$1);
                    fprintf(errorFile, "%s is not defined at line: %d\n",$1,linecount);
                }
            }
          | LPAREN expression RPAREN { fprintf(treeFile, "expression --> ( expression )\n"); $$ = $2; }
          | expression PLUS expression { fprintf(treeFile, "expression --> expression + expression\n"); $$ = $1 + $3;}
          | expression MINUS expression { fprintf(treeFile, "expression --> expression - expression\n"); $$ = $1 - $3; }
          | expression MULT expression { fprintf(treeFile, "expression --> expression * expression\n"); $$ = $1 * $3; }
          | expression DIV expression { fprintf(treeFile, "expression --> expression / expression\n"); $$ = $1 / $3; }
          ;

expression2: STR { fprintf(treeFile, "expression2 --> %s\n", $1);  strcpy($$, $1); }
           | LPAREN expression2 RPAREN { fprintf(treeFile, "expression2 --> ( expression2 )\n"); strcpy($$, $2); }
           | expression2 PLUS expression2 { fprintf(treeFile, "expression2 --> expression2 + expression2\n"); $$ = string_add($1, $3); } // 拼接字符串
           | expression2 MINUS expression2 { fprintf(treeFile, "expression2 --> expression2 - expression2\n"); $$ = string_subtract($1, $3); } // 减去字符串
           ;

print_statement:PRINT LPAREN STR RPAREN
        //  printf("isif=%d  isflag=%d  ",isif,if_flag);

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
    | PRINT LPAREN expression RPAREN
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
        {
        
        if(isif==0)
        printf("%s\n", $3);  // 打印字符串内容;
            
         else
            {              
                if(if_flag!=0&&isif==1){
                printf("%s\n", $3);  // 打印字符串内容
            }
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
