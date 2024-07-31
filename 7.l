%{
#include<stdio.h>
%}

%%
[0-9]+ {printf("\n%s is a number",yytext);}
[a-zA-Z]+ {printf("\n%s is a word",yytext);}
%%

int main(){
printf("Enter:");
yylex();
return 0;
}

int yywrap(){
return 1;
}
