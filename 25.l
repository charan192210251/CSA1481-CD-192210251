%{
#include<stdio.h>
#include<string.h>

char word [] = "charan";
int count = 0;
%}

%%
[a-zA-Z]+ { if(strcmp(yytext, word)==0)
				count++; }
. ;		 
%%

int yywrap()
{
	return 1;
}

int main()
{
		yylex();
		printf("%d", count);
}
