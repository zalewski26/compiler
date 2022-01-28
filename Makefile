.PHONY = all clean cleanAll

all: compiler.tab.cpp compiler.l.c
	g++ -std=c++17 -o kompilator app/parser.tab.cpp app/lexer.l.c src/*.cpp

compiler.tab.cpp: app/parser.ypp
	bison -d -o app/parser.tab.cpp app/parser.ypp

compiler.l.c: app/lexer.l
	flex -o app/lexer.l.c app/lexer.l

clean:
	rm -f */*.tab.h* */*.tab.c* */*.l.c*
cleanAll:
	rm -f */*.tab.h* */*.tab.c* */*.l.c* kompilator