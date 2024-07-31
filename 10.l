%{
#include<stdio.h>
%}
%%
((http)s?:\/\/[a-zA-Z0-9]{2,}(\.[a-z]{2,})+(\/[a-zA-Z0-9+=?]*)*) {printf("\nURL Valid\n");} 
. {printf("\nURL Invalid\n");} 
%%

int main() 
{ 
    printf("\nEnter URL : "); 
    yylex(); 
    printf("\n"); 
    return 0; 
}
int yywrap(){return 1;}
