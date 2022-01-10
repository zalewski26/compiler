 
main: lexer.l parser.ypp components/*
	lex lexer.l && bison -d parser.ypp && g++ -o main parser.tab.hpp parser.tab.cpp lex.yy.c && make clean

clean:
	rm lex.yy.c *.tab*