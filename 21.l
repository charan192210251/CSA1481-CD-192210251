%{
#include <stdio.h>
#include <stdlib.h>

int line_number = 1;
%}

%%

\n          { 
                printf("%s  %d", yytext,line_number++); 
              }

%%
int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        FILE *file = fopen(argv[1], "r");
        if (!file)
        {
            perror("fopen");
            return 1;
        }
        yyin = file;
    }

    yylex();
       return 0;
}

int yywrap(){
return 1;}
