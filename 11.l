%{
#include<stdio.h>
%}
%%
[0-9]{2}\/[0-9]{2}\/[0-9]{4} {printf("Valid");}
. {printf("Invalid");}
%%
int main(){
printf("Enter ");
yylex();
return 0;
}
int yywrap(){
return 1;
}
