all: compiler

compiler: lex.yy.c parser.tab.c ast.o main.o
	gcc -o compiler lex.yy.c parser.tab.c ast.o main.o -lfl -I src 

lex.yy.c: src/lexer.l parser.tab.h
	flex -o lex.yy.c src/lexer.l

parser.tab.c parser.tab.h: src/parser.y
	bison -d -o parser.tab.c src/parser.y

ast.o: src/ast.c src/ast.h
	gcc -c src/ast.c -o ast.o -I src

main.o: src/main.c src/ast.h
	gcc -c src/main.c -o main.o -I src

clean:
	rm -f compiler lex.yy.c parser.tab.c parser.tab.h *.o	
