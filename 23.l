%{
#include <stdio.h>
#include <stdlib.h>
%}

/* Define token types */
%token KEYWORD IDENTIFIER CONSTANT STRING_LITERAL OPERATOR SEPARATOR

/* Regular expressions for different token types */
%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|
"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|
"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|
"unsigned"|"void"|"volatile"|"while"        { printf("<KEYWORD, %s>\n", yytext); }

[A-Za-z_][A-Za-z0-9_]*                      { printf("<IDENTIFIER, %s>\n", yytext); }

[0-9]+                                      { printf("<CONSTANT, %s>\n", yytext); }

\"([^\\\n]|(\\.))*?\"                        { printf("<STRING_LITERAL, %s>\n", yytext); }

"+"|"-"|"*"|"/"|"%"|"++"|"--"|"=="|"!="|"<="|">="|"<"|">"|"="|"&&"|"||"|"!"|
"&"|"|"|"^"|"~"|"<<"|">>"                   { printf("<OPERATOR, %s>\n", yytext); }

"(" | ")" | "{" | "}" | "[" | "]" | "," | ";" | ":" | "."  { printf("<SEPARATOR, %s>\n", yytext); }

[ \t\n]+                                    /* Ignore whitespace */
.                                           { printf("<UNKNOWN, %s>\n", yytext); }
%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror("Failed to open file");
            return 1;
        }
        yyin = file;
    }
    yylex();
    return 0;
}
