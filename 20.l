%{
#include <stdio.h>
#include <stdlib.h>  // For EXIT_FAILURE
%}

%%
\<[a-z]+[0-9]*\> { printf("Found tag: %s\n", yytext); }
\<\/[a-z]+[0-9]*\> { printf("Found tag: %s\n", yytext); }

.       { /* ignore other characters */ }
%%

int main(int argc, char **argv)
{
    FILE *file = stdin;  // Default to stdin
    if (argc > 1) {
        file = fopen(argv[1], "r");
        if (!file) {
            perror("File opening failed");
            return EXIT_FAILURE;
        }
    }
    
    yyin = file;  // Set yyin to the file pointer

    yylex();

    if (file != stdin) {  // Only close the file if it was opened
        fclose(file);
    }

    return 0;
}
int yywrap(){return 1;}
