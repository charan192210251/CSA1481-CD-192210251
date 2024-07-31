%{
#include<stdio.h>
%}
%%
ar {printf("AR");}
%%
int main(){
printf("Enter: ");
yylex();
return 0;
}
int yywrap(){
return 1;
}
