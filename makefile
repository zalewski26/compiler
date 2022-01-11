all: main

.PHONY:main
main: app/lexer.l
	lex app/lexer.l && bison -d app/parser.ypp && g++ -o main parser.tab.cpp lex.yy.c ./src/*.cpp -I./inc

clean:
	rm lex.yy.c parser.tab* main 