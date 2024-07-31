%{
#include<stdio.h>
%}
%%
bad {printf("good");}
%%
int main(){
printf("Enter: ");
yylex();
return 0;
}
int yywrap(){
return 1;
}
