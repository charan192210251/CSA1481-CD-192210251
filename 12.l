%{
#include<stdio.h>
%}
%%
[a-zA-Z]+ {printf("%s is a word\n",yytext);}
==|!=|<|>|<=|>= {printf("%s is a Relational operator\n",yytext);}
.
%%
int main(){
printf("Enter: ");
yylex();
return 0;
}
int yywrap(){
return 1;
}
