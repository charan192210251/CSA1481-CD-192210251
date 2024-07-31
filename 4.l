%{
#include <stdio.h>
int vc = 0;
int cc = 0;
%}

%%
[ \t\n]+ ;
[aeiouAEIOU] {vc++;}
[^aeiouAEIOU] {cc++;}
%%

int main() {
    printf("Enter a sentence:");
    yylex();
    printf("Number of vowels: %d\n", vc);
    printf("Number of consonants: %d\n", cc);
    return 0;
}

int yywrap() {
    return 1;
}
