%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 1000

// 语句类型枚举
typedef enum {
    ASSIGNMENT,  // 赋值语句
    PRINT        // 打印语句
} StatementType;

// 语句结构体定义
typedef struct Statement {
    StatementType type;  // 语句类型

    // 联合体，用于存储不同类型的语句
    union {
        struct { 
            char* var_name;
            int value;
        } assignment;  // 赋值语句

        struct { 
            int value;
        } print;  // 打印语句
    } stmt;

    void (*execute)(struct Statement* stmt);  // 执行语句的函数指针
    struct Statement* next;  // 链表指针，指向下一条语句
} Statement;

// StatementList 是 Statement 的别名
typedef Statement StatementList;

void yyerror(char *msg);
int add_symbol(char *id, char *type);
char* find_symbol_type(char *id);
void execute_statement_list(Statement* stmt_list);
int yylex();

// 符号表相关结构
typedef struct {
    char *id;      // 变量名
    char *type;    // 变量类型
    int value;     // 变量的值
} Symbol;

Symbol symbol_table[MAX_SYMBOLS];  // 符号表
int symbol_count = 0;  // 符号计数

int linecount = 1;
int idnum = 0;

// 单词结构体定义
struct word {
    char *word_name;
    int word_type;
    struct word *next;
};

// 单词表
struct word *word_list;

%}

// Union 必须在声明 `Statement` 和 `StatementList` 之后
%union {
    int intVal;
    double doubleVal;
    char* strVal;
    char* id;

    struct Statement* stmt;  // 语句指针类型
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

%type <stmt> statement
%type <stmt> statement_list



%%
program: statement_list
        ;

statement_list: statement statement_list
              | /* 空 */
              ;

statement: variable_declaration
         | assignment
         | if_statement
         | loop_statement
         ;

variable_declaration: VAR id_list type{
    printf("语句");
    char *type = $3;  // 获取变量类型

    // 检查并添加每个变量到符号表中
    for (int i = 1; i <= $2; i++) {
        // 检查变量是否已声明
        check_declaration($2[i], type);  // 这里我们假设 $2[i] 是变量名
    }}
|VAR id_list type ASSIGN expression{ 
    printf("复制语句");    
    char *type = $3;  // 获取变量类型

    // 检查并添加每个变量到符号表中
    for (int i = 1; i <= $2; i++) {
        // 检查变量是否已声明
        check_declaration($2[i], type);
    }

    // 处理赋值语句
    for (int i = 1; i <= $2; i++) {
        // 检查赋值表达式类型与变量声明类型是否匹配
        check_assignment($2[i], type);  // 确保类型匹配
    }}
                    ;

id_list: ID{printf("检测到ID]");        }
       | ID COMMA id_list{printf("检测到ID]");        }
       ;

type: INT
    | DOUBLE
    | STRING
    | BOOL
    | INT array_dimensions
    | DOUBLE array_dimensions
    ;

array_dimensions: LBRACKET NUMBER RBRACKET
                | LBRACKET NUMBER RBRACKET array_dimensions
                ;




assignment: ID ASSIGN expression
          ;




if_statement:
    IF LPAREN condition RPAREN LBRACE statement_list RBRACE
        {   
            if ($3) {  // 如果条件为真
                execute_statement_list($6);  // 执行 if 语句块
                printf("条件为镇");
            }
            
        }
  | IF LPAREN condition RPAREN LBRACE statement_list RBRACE ELSE LBRACE statement_list RBRACE
        {
            if ($3) {  // 如果条件为真
                execute_statement_list($6);  // 执行 if 语句块
            } else {
                execute_statement_list($10);  // 否则执行 else 语句块
            }
        }
  ;




loop_statement: FOR LPAREN condition RPAREN LBRACE statement_list RBRACE
              | FOR ID COLON ID LBRACE statement_list RBRACE /* 增强型 for 循环 */
              | WHILE LPAREN condition RPAREN LBRACE statement_list RBRACE
              ;



condition:
    expression EQ expression { $$ = ($1 == $3);printf("相等");}   // 等于
  | expression NE expression { $$ = ($1 != $3); }   // 不等于
  | expression LT expression { $$ = ($1 < $3); }    // 小于
  | expression LE expression { $$ = ($1 <= $3); }   // 小于等于
  | expression GT expression { $$ = ($1 > $3); }    // 大于
  | expression GE expression { $$ = ($1 >= $3); }   // 大于等于
;



expression:
    NUMBER { $$ = $1; }                                      // 处理数字
  | ID { $$ = get_variable_value($1); }                        // 获取变量的值
  | LPAREN expression RPAREN { $$ = $2; }                     // 处理括号表达式
  | expression PLUS expression { $$ = $1 + $3; }              // 加法
  | expression MINUS expression { $$ = $1 - $3; }             // 减法
  | expression MULT expression { $$ = $1 * $3; }              // 乘法
  | expression DIV expression { $$ = $1 / $3; }               // 除法
;


%%

void execute_statement_list(Statement* stmt_list) {
    Statement* current_stmt = stmt_list;

    while (current_stmt != NULL) {
        execute_statement(current_stmt);  // 执行当前语句
        current_stmt = current_stmt->next;  // 继续到下一个语句
    }
}



void execute_statement(Statement* stmt) {
   printf("执行语句");
   switch (stmt->type) {
        case ASSIGNMENT:
            // 正确地访问 union 内的字段
            set_variable_value(stmt->stmt.assignment.var_name, stmt->stmt.assignment.value);
            break;
        case PRINT:
            printf("%d\n", stmt->stmt.print.value);
            break;
        default:
            break;
    }
}

int get_variable_value(char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].id, name) == 0) {
            return symbol_table[i].value;
        }
    }
    printf("Error: Variable '%s' not declared\n", name);
    exit(1);
}

void set_variable_value(char* name, int value) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].id, name) == 0) {  // 使用 id 而不是 name
            symbol_table[i].value = value;
            return;
        }
    }
    // 如果没有找到对应的符号，则添加新符号
    strcpy(symbol_table[symbol_count].id, name);
    symbol_table[symbol_count].value = value;
    symbol_count++;
}

void check_declaration(char *id, char *type) {
    if (!add_symbol(id, type)) {
        char error_msg[100];
        sprintf(error_msg, "Variable '%s' already declared", id);
        semantic_error(error_msg);
    }
}  //检查是否已声明

void check_assignment(char *id, char *type) {
    char *declared_type = find_symbol_type(id);
    if (declared_type == NULL) {
        char error_msg[100];
        sprintf(error_msg, "Variable '%s' not declared", id);
        semantic_error(error_msg);
    }
    if (strcmp(declared_type, type) != 0) {
        char error_msg[100];
        sprintf(error_msg, "Type mismatch in assignment to '%s'", id);
        semantic_error(error_msg);
    }
}     //检查是否和已声明的Var类型相同

void semantic_error(char *msg) {
    fprintf(stderr, "Semantic Error: %s\n", msg);
    exit(1); // 出现语义错误后退出程序
}

int add_symbol(char *id, char *type) {
    // 检查符号是否已存在
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].id, id) == 0) {
            return 0;  // 符号已存在
        }
    }
    // 添加新符号
    symbol_table[symbol_count].id = strdup(id);
    symbol_table[symbol_count].type = strdup(type);
    symbol_count++;
    return 1;
}

// 查找符号
char* find_symbol_type(char *id) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].id, id) == 0) {
            return symbol_table[i].type;
        }
    }
    return NULL; // 符号未找到
}



void yyerror(char *msg) {
    fprintf(stderr, "Error: %s at line %d\n", msg, linecount);
}


int yywrap() {
    return 1;
}

extern FILE *yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Could not open %s\n", argv[1]);
            return 1;
        }
        yyin = file;
        printf("File opened successfully\n");  // Debugging line
    }

    yyparse();
    return 0;
}