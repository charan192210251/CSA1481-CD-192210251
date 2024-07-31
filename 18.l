%{
#include <stdio.h>
%}

%%
[0-9]+(\.[0-9]+)? { printf("Found constant: %s\n", yytext); }
.                 { /* Ignore other characters */ }

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
