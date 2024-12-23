%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(char *msg);
int yylex();

FILE *treeFile;

extern FILE *yyin;

int linecount = 0;

int isStatement = 0;

int idNum = 0;

/*enum Type{
    INT = 1,
    FLOAT = 2,
    DOUBLE =3,
    STRING = 4,
    BOOLEAN = 5
};*/

struct word {
    char *word_name;
    int word_type;
    struct word *next;
};

struct word *word_list = NULL;

void pushType(int idNum,int type);

void free_list(struct word *head);

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
%token ASSIGN EQ NE LT GT LE GE COLON COMMA LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE

/* 优先级 */
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULT DIV

/* 非终结符 */
%type <intVal> expression
%type <id> id_list type array_dimensions
%type <intVal> condition
%%
program: statement_list{ fprintf(treeFile, "program --> statement_list\n");}
        ;

statement_list: statement statement_list{ fprintf(treeFile, "statement_list --> statement statement_list\n");}
              | /* 空 */{ fprintf(treeFile, "statement_list --> ε\n");}
              ;

statement: variable_declaration{ fprintf(treeFile, "statement --> variable_declaration\n");}
         | assignment{ printf("复制语句完成");fprintf(treeFile, "statement --> assignment\n");}
         | if_statement{ fprintf(treeFile, "statement --> if_statement\n");}
         | loop_statement{ fprintf(treeFile, "statement --> loop_statement\n");}
         ;

variable_declaration: VAR id_list type{ printf("变量声明开始");fprintf(treeFile, "variable_declaration --> var id_list type\n");}
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

assignment: ID ASSIGN expression {
    // 找到符号表中的变量
    struct word *current = word_list;
    while (current != NULL) {
        if (strcmp(current->word_name, $1) == 0) {
            // 假设 $3 是表达式的值，你可以根据类型进行赋值
            current->word_type = $3;  // 更新变量的值
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        fprintf(stderr, "Error: Variable %s not declared\n", $1);
        exit(1);  // 如果变量未声明，直接退出
    }

    // 输出调试信息
    printf("复制语句\n");
    fprintf(treeFile, "assignment --> %s = expression\n", $1);
}
if_statement: IF LPAREN condition RPAREN LBRACE statement_list RBRACE{ fprintf(treeFile, "if_statement --> if ( condition ) { statement_list }\n");}
            | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE{ fprintf(treeFile, "if_statement --> if ( condition ) { statement_list } else { statement_list }\n");}
            ;

loop_statement: FOR ID COLON ID LBRACE statement_list RBRACE /* 增强型 for 循环 */{ fprintf(treeFile, "loop_statement --> for %s : %s { statement_list }\n", $2, $4);}
              | WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE{ fprintf(treeFile, "loop_statement --> while ( condition ) { statement_list }\n");}
              ;

condition: expression EQ expression { fprintf(treeFile, "condition --> expression == expression\n");printf("相等");$$ = ($1 == $3);}
         | expression NE expression { fprintf(treeFile, "condition --> expression != expression\n");$$ = ($1 != $3); }
         | expression LT expression { fprintf(treeFile, "condition --> expression < expression\n");$$ = ($1 < $3); }
         | expression LE expression { fprintf(treeFile, "condition --> expression <= expression\n");$$ = ($1 <= $3);}
         | expression GT expression { fprintf(treeFile, "condition --> expression > expression\n"); $$ = ($1 > $3);}
         | expression GE expression { fprintf(treeFile, "condition --> expression >= expression\n");$$ = ($1 >= $3); }
         ;

expression: NUMBER {
    fprintf(treeFile, "expression --> %d\n", $1);
    $$ = $1;
}
| ID {
    printf("识别到ID");
    struct word *current = word_list;
    while (current != NULL) {
        if (strcmp(current->word_name, $1) == 0) {
            fprintf(treeFile, "expression --> %s (value = %d)\n", $1, current->word_type);
            $$ = current->word_type;  // 假设类型值是存储在 word_type 中的
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        fprintf(stderr, "Error: Variable %s not declared\n", $1);
        printf("错误");
        exit(1);
    }
}
          | LPAREN expression RPAREN { fprintf(treeFile, "expression --> ( expression )\n"); $$ = $2; }
          | expression PLUS expression { fprintf(treeFile, "expression --> expression + expression\n"); $$ = $1 + $3; }
          | expression MINUS expression { fprintf(treeFile, "expression --> expression - expression\n"); $$ = $1 - $3; }
          | expression MULT expression { fprintf(treeFile, "expression --> expression * expression\n"); $$ = $1 * $3; }
          | expression DIV expression { fprintf(treeFile, "expression --> expression / expression\n"); $$ = $1 / $3; }
          ;
          

%%
void yyerror(char *msg) {
    fprintf(stderr, "Error: %s at line %d\n", msg, linecount);
}

int yywrap() {
    return 1;
}

void pushType(int idNum, int type) {
    struct word *current = word_list;
    int i = 0;
    while (current != NULL && i < idNum) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        printf("error: idNum is too large\n");
        return;
    }
    current->word_type = type;
    printf("%d: id = %s , type = %d\n", linecount, current->word_name, current->word_type);
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
