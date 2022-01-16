/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 2 "app/parser.ypp"

    #include "../inc/types.hpp"

#line 52 "parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    _BEGIN = 259,
    END = 260,
    ASSIGN = 261,
    IF = 262,
    THEN = 263,
    ELSE = 264,
    ENDIF = 265,
    WHILE = 266,
    DO = 267,
    ENDDO = 268,
    ENDWHILE = 269,
    FOR = 270,
    FROM = 271,
    TO = 272,
    DOWNTO = 273,
    ENDFOR = 274,
    REPEAT = 275,
    UNTIL = 276,
    READ = 277,
    WRITE = 278,
    PLUS = 279,
    MINUS = 280,
    TIMES = 281,
    DIV = 282,
    MOD = 283,
    EQ = 284,
    NEQ = 285,
    LE = 286,
    GE = 287,
    LEQ = 288,
    GEQ = 289,
    pidentifier = 290,
    num = 291,
    direction = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
#line 24 "app/parser.ypp"
union semrec
{
#line 25 "app/parser.ypp"

    int num; /* Integer values */
    char* pidentifier; /* Identifiers */
    bool direction;
    struct lbs* lbls; /* For backpatching */
    Identifier* id;
    Value* val;
    Condition* cond;
    Expression* exp;
    Command* cmd;
    CommandSet* cSet;

#line 115 "parser.tab.hpp"

};
#line 24 "app/parser.ypp"
typedef union semrec YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */
