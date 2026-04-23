#ifndef AST_H
#define AST_H

typedef enum {
    PROGRAM_NODE,
    STMT_LIST_NODE,
    DECL_NODE,
    ASSIGN_NODE,
    PRINT_NODE,
    IF_NODE,
    BINOP_NODE,
    NUM_NODE,
    ID_NODE,
    COND_NODE
} NodeType;

typedef struct ASTNode {
    NodeType type;

    char name[50];   // variable name
    int value;       // for numbers
    char op[10];     // operator (+, -, *, etc.)

    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *third;
    struct ASTNode *next;

} ASTNode;

/* Function declarations */

ASTNode* create_node(NodeType type);
ASTNode* create_num_node(int value);
ASTNode* create_id_node(char *name);
ASTNode* create_binop_node(char *op, ASTNode *left, ASTNode *right);
ASTNode* create_decl_node(char *name, ASTNode *expr);
ASTNode* create_assign_node(char *name, ASTNode *expr);
ASTNode* create_print_node(ASTNode *expr);
ASTNode* create_cond_node(char *op, ASTNode *left, ASTNode *right);
ASTNode* create_if_node(ASTNode *cond, ASTNode *body);

void print_ast(ASTNode *node, int level);

#endif
