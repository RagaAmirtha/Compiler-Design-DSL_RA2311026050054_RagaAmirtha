#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

/* Create generic node */
ASTNode* create_node(NodeType type) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->name[0] = '\0';
    node->value = 0;
    node->op[0] = '\0';
    node->left = node->right = node->third = node->next = NULL;
    return node;
}

/* Number node */
ASTNode* create_num_node(int value) {
    ASTNode *node = create_node(NUM_NODE);
    node->value = value;
    return node;
}

/* Identifier node */
ASTNode* create_id_node(char *name) {
    ASTNode *node = create_node(ID_NODE);
    strcpy(node->name, name);
    return node;
}

/* Binary operation */
ASTNode* create_binop_node(char *op, ASTNode *left, ASTNode *right) {
    ASTNode *node = create_node(BINOP_NODE);
    strcpy(node->op, op);
    node->left = left;
    node->right = right;
    return node;
}

/* Declaration */
ASTNode* create_decl_node(char *name, ASTNode *expr) {
    ASTNode *node = create_node(DECL_NODE);
    strcpy(node->name, name);
    node->left = expr;
    return node;
}

/* Assignment */
ASTNode* create_assign_node(char *name, ASTNode *expr) {
    ASTNode *node = create_node(ASSIGN_NODE);
    strcpy(node->name, name);
    node->left = expr;
    return node;
}

/* Print */
ASTNode* create_print_node(ASTNode *expr) {
    ASTNode *node = create_node(PRINT_NODE);
    node->left = expr;
    return node;
}

/* Condition */
ASTNode* create_cond_node(char *op, ASTNode *left, ASTNode *right) {
    ASTNode *node = create_node(COND_NODE);
    strcpy(node->op, op);
    node->left = left;
    node->right = right;
    return node;
}

/* If statement */
ASTNode* create_if_node(ASTNode *cond, ASTNode *body) {
    ASTNode *node = create_node(IF_NODE);
    node->left = cond;
    node->right = body;
    return node;
}

/* Print AST */
void print_ast(ASTNode *node, int level) {
    while (node != NULL) {

        for (int i = 0; i < level; i++)
            printf("  ");

        switch (node->type) {

            case DECL_NODE:
                printf("DECL: %s\n", node->name);
                print_ast(node->left, level + 1);
                break;

            case ASSIGN_NODE:
                printf("ASSIGN: %s\n", node->name);
                print_ast(node->left, level + 1);
                break;

            case PRINT_NODE:
                printf("PRINT\n");
                print_ast(node->left, level + 1);
                break;

            case IF_NODE:
                printf("IF\n");

                for (int i = 0; i < level + 1; i++)
                    printf("  ");
                printf("CONDITION:\n");
                print_ast(node->left, level + 2);

                for (int i = 0; i < level + 1; i++)
                    printf("  ");
                printf("BODY:\n");
                print_ast(node->right, level + 2);
                break;

            case BINOP_NODE:
                printf("BINOP: %s\n", node->op);
                print_ast(node->left, level + 1);
                print_ast(node->right, level + 1);
                break;

            case COND_NODE:
                printf("COND: %s\n", node->op);
                print_ast(node->left, level + 1);
                print_ast(node->right, level + 1);
                break;

            case NUM_NODE:
                printf("NUM: %d\n", node->value);
                break;

            case ID_NODE:
                printf("ID: %s\n", node->name);
                break;

            default:
                printf("UNKNOWN NODE\n");
        }

        node = node->next;
    }
}
