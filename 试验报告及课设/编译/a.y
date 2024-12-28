%{
#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构
typedef struct TreeNode {
    int type;
    YYSTYPE value;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* parse() {
    return statement_list();
}

void parseTree(TreeNode* node) {
    if (node == NULL) return;
    // 根据节点类型输出信息
    switch (node->type) {
        case IDENTIFIER:
            printf("Identifier: %s\n", node->value.string);
            break;
        case NUMBER:
            printf("Number: %d\n", node->value.number);
            break;
        // 其他情况...
    }
    // 递归遍历子节点
    parseTree(node->left);
    parseTree(node->right);
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
%}

%union {
    int number;
    char *string;
    // 可以根据需要添加其他类型
}

%token <number> NUMBER
%token <string> IDENTIFIER
%token IF REPEAT READ WRITE UNTIL ELSE LPAREN RPAREN SEMICOLON ASSIGN PLUS MINUS MULTIPLY DIVIDE EQUAL LESS GREATER

%type <node> statement statement_list statement_list' if_statement repeat_statement read_statement write_statement assignment_statement boolean_expression arithmetic_expression arithmetic_expression' arithmetic_term arithmetic_term'

%%
program:
    statement_list { parseTree($1); }
    ;

statement_list:
    statement statement_list'
    ;

statement_list':
    ';' statement statement_list' { $$ = $1; }
    | ε { $$ = NULL; }
    ;

statement:
    if_statement
    | repeat_statement
    | read_statement
    | write_statement
    | assignment_statement
    ;

if_statement:
    IF LPAREN boolean_expression RPAREN statement ELSE statement { $$ = ...; }
    ;

repeat_statement:
    REPEAT statement_list UNTIL LPAREN boolean_expression RPAREN { $$ = ...; }
    ;

read_statement:
    READ LPAREN IDENTIFIER RPAREN { $$ = ...; }
    ;

write_statement:
    WRITE LPAREN arithmetic_expression RPAREN { $$ = ...; }
    ;

assignment_statement:
    IDENTIFIER ASSIGN arithmetic_expression { $$ = ...; }
    ;

boolean_expression:
    arithmetic_expression relop arithmetic_expression { $$ = ...; }
    ;

arithmetic_expression:
    arithmetic_term arithmetic_expression' { $$ = ...; }
    ;

arithmetic_expression':
    '+' arithmetic_term arithmetic_expression' { $$ = ...; }
    | ε { $$ = NULL; }
    ;

arithmetic_term:
    factor arithmetic_term' { $$ = ...; }
    ;

arithmetic_term':
    '*' factor arithmetic_term' { $$ = ...; }
    | ε { $$ = NULL; }
    ;

factor:
    NUMBER { $$ = ...; }
    | IDENTIFIER { $$ = ...; }
    | LPAREN arithmetic_expression RPAREN { $$ = ...; }
    ;

%%