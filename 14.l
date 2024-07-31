%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+(\.[0-9]+)?    { printf("NUMBER: %s\n", yytext); }
"+"                  { printf("PLUS\n"); }
"-"                  { printf("MINUS\n"); }
"*"                  { printf("MULTIPLY\n"); }
"/"                  { printf("DIVIDE\n"); }
"("                  { printf("LPAREN\n"); }
")"                  { printf("RPAREN\n"); }
[ \t\n]+             { /* Ignore whitespace */ }
.                    { printf("UNKNOWN: %s\n", yytext); }

%%

int main(int argc, char **argv) {
    yylex();
    return 0;
}
