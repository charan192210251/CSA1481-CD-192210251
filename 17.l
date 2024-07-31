%{
#include <stdio.h>
#include <stdlib.h>

int num_chars = 0;
int num_lines = 0;
int num_words = 0;
%}

%%

[ \t]+                    /* Ignore spaces and tabs */
\n                        { num_lines++; }
[A-Za-z_][A-Za-z0-9_]*    { num_words++; }
"//".*               { /* Ignore single-line comments */ }
.                         { num_chars++; } /* Count any other characters */

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    yyin = file;
    yylex();
    
    fclose(file);
    
    printf("Number of characters: %d\n", num_chars);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    
    return 0;
}
int yywrap(){
return 1;
}
