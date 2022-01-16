%option noyywrap
%option yylineno
%{
    #include "../parser.tab.hpp"
    #include <string.h> 
    #include <stdlib.h> 
    int yylex();
%}

%x COMMENT

pidentifier [_a-z]+
num         -?([0-9]|[1-9][0-9]*)   

%%
\(              {BEGIN(COMMENT);}
<COMMENT>\)     {BEGIN(INITIAL);}
<COMMENT>.      ;
VAR             {return (VAR); }
BEGIN           { return (_BEGIN); }
ENDDO           { return (ENDDO); }
ENDWHILE        { return (ENDWHILE); }
ENDFOR          { return (ENDFOR); }
END             { return (END); }
REPEAT          { return (REPEAT);}
UNTIL           { return (UNTIL);}
ASSIGN          { return (ASSIGN); }
IF              { return (IF); }
THEN            { return (THEN); }
ELSE            { return (ELSE); }
ENDIF           { return (ENDIF); }
WHILE           { return (WHILE); }
DO              { return (DO); }
FOR             { return (FOR); }
FROM            { return (FROM); }
READ            { return (READ); }
WRITE           { return (WRITE); }
PLUS            { return (PLUS); }
MINUS           { return (MINUS); }
TIMES           { return (TIMES); }
DIV             { return (DIV); }
MOD             { return (MOD); }
EQ              { return (EQ); }
NEQ             { return (NEQ); }
LE              { return (LE); }
GE              { return (GE); }
LEQ             { return (LEQ); }
GEQ             { return (GEQ); }
TO              {yylval.direction = false; return (direction); }
DOWNTO          {yylval.direction = true; return (direction); }
{pidentifier}   {yylval.pidentifier = (char*) strdup(yytext); return (pidentifier);}
{num}           {yylval.num = atoi(yytext); return(num);}
[ \t\n]+        ;
.               { return yytext[0]; }
%%