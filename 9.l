%{
#include<stdio.h>
#include<string.h>
int maxl=0;
char maxw[10];
%}

%%
[a-zA-Z]+ { if(yyleng>maxl){
maxl=yyleng;
strcpy(maxw,yytext);
}
}
%%

int main(){
printf("Enter: ");
yylex();
printf("Longest word: %s\n", maxw);
printf("Length of longest word: %d\n",maxl);
return 0;
}

int yywrap(){
return 1;
}

