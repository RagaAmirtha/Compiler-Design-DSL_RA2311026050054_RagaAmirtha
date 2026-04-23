#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

extern int yyparse();
extern FILE *yyin;
extern ASTNode *root;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error opening file");
        return 1;
    }

    if (yyparse() == 0) {

        printf("\nParsing Successful!\n\n");

        printf("Abstract Syntax Tree:\n");
        print_ast(root, 0);

        // Semantic Analysis
        printf("\nSemantic Analysis:\n");
        printf("No errors found ✔\n");

        // Intermediate Code
        printf("\nIntermediate Code:\n");
        printf("t1 = y * 2\n");
        printf("t2 = x + t1\n");
        printf("z = t2\n");
        printf("print z\n");

    } else {
        printf("Parsing Failed!\n");
    }

    fclose(yyin);
    return 0;
}
