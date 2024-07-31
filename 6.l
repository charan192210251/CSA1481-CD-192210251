%{
#include <stdio.h>
int p = 0;
int n = 0;
%}

%%

[+]?[0-9]+ {p++;}
[-][0-9]+ {n++;}
. ; 
%%

int main() {
    printf("Enter:");
    yylex();
    printf("Total positive numbers: %d\n", p);
    printf("Total negative numbers: %d\n", n);
    return 0;
}

int yywrap() {
    return 1;
}
