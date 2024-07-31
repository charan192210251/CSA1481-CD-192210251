%{
	#include<stdio.h>
%}

%%
[ \t\n]+ ;
[0-9]+ {printf("\n%s is a digit",yytext);}
[^0-9]+ {printf("\n%s is not a digit",yytext);}
%%

int main(){
	printf("Enter : ");
	yylex();
	return 0;
}

int yywrap(){
return 1;
}
