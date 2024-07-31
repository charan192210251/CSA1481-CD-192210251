%{
#include<stdio.h>
%}
%%
[a-z0-9]+@[g][m][a][i][l]\.[c][o][m] {printf("Valid");}
. {printf("invalid");}
%%
int main(){
printf("Enter: ");
yylex();
return 0;
}
int yywrap(){
return 1;
}
