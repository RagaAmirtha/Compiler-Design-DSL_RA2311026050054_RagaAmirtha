%{
#include "ast.h"
#include "parser.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%%

"let"           { return LET; }
"print"         { return PRINT; }
"if"            { return IF; }

"=="            { return EQ; }
">"             { return GT; }
"<"             { return LT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"="             { return ASSIGN; }

";"             { return SEMICOLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }

[0-9]+          {
                    yylval.num = atoi(yytext);
                    return NUMBER;
                }

[a-zA-Z_][a-zA-Z0-9_]* {
                    yylval.id = strdup(yytext);
                    return IDENTIFIER;
                }

[ \t\r\n]+      ;   /* ignore whitespace */

.               { printf("Unknown character: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
