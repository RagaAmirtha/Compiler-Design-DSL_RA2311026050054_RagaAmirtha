%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

void yyerror(const char *s);
int yylex(void);

ASTNode *root = NULL;
ASTNode *append_stmt(ASTNode *list, ASTNode *stmt);
%}

%union {
    int num;
    char *id;
    ASTNode *node;
}

%token LET PRINT IF
%token NUMBER IDENTIFIER
%token PLUS MINUS MUL DIV ASSIGN
%token GT LT EQ
%token SEMICOLON LPAREN RPAREN LBRACE RBRACE

%type <node> program stmt_list stmt decl_stmt assign_stmt print_stmt if_stmt expr term factor condition
%type <num> NUMBER
%type <id> IDENTIFIER

%%

program:
    stmt_list { root = $1; }
    ;

stmt_list:
    stmt_list stmt { $$ = append_stmt($1, $2); }
    | stmt         { $$ = $1; }
    ;

stmt:
    decl_stmt   { $$ = $1; }
    | assign_stmt { $$ = $1; }
    | print_stmt { $$ = $1; }
    | if_stmt    { $$ = $1; }
    ;

decl_stmt:
    LET IDENTIFIER ASSIGN expr SEMICOLON
    { $$ = create_decl_node($2, $4); }
    ;

assign_stmt:
    IDENTIFIER ASSIGN expr SEMICOLON
    { $$ = create_assign_node($1, $3); }
    ;

print_stmt:
    PRINT expr SEMICOLON
    { $$ = create_print_node($2); }
    ;

if_stmt:
    IF condition LBRACE stmt_list RBRACE
    { $$ = create_if_node($2, $4); }
    ;

condition:
    expr GT expr { $$ = create_cond_node(">", $1, $3); }
    | expr LT expr { $$ = create_cond_node("<", $1, $3); }
    | expr EQ expr { $$ = create_cond_node("==", $1, $3); }
    ;

expr:
    expr PLUS term { $$ = create_binop_node("+", $1, $3); }
    | expr MINUS term { $$ = create_binop_node("-", $1, $3); }
    | term { $$ = $1; }
    ;

term:
    term MUL factor { $$ = create_binop_node("*", $1, $3); }
    | term DIV factor { $$ = create_binop_node("/", $1, $3); }
    | factor { $$ = $1; }
    ;

factor:
    NUMBER { $$ = create_num_node($1); }
    | IDENTIFIER { $$ = create_id_node($1); }
    | LPAREN expr RPAREN { $$ = $2; }
    ;

%%

ASTNode *append_stmt(ASTNode *list, ASTNode *stmt) {
    if (list == NULL) return stmt;
    ASTNode *temp = list;
    while (temp->next != NULL) temp = temp->next;
    temp->next = stmt;
    return list;
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}
