%{
#include <stdio.h>
%}

%%
[A-Z]+ {printf("Capital word: %s ", yytext); }
.  
%%

int main() {
    printf("Enter string:");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
