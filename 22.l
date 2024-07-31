%{
#include <stdio.h>
int cl = 0;  // Counter for comment lines
%}

%%

/\*([^*]|\*+[^*/])*\*+/ {  // Matches multi-line comments
    cl++;
}

/\/\*.*?\*\/[ \t]*\n?/ {  // Matches multi-line comments ending in newlines
    cl++;
}

\/\/[^\n]* {  // Matches single-line comments
    cl++;
}

[^\n]*\n {  // Matches all other lines and prints them
    fputs(yytext, stdout);
}

%%

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outfile = fopen(argv[2], "w");
    if (!outfile) {
        perror("Error opening output file");
        fclose(file);
        return 1;
    }

    yyin = file;
    yyout = outfile;
    yylex();

    fclose(file);
    fclose(outfile);

    printf("Total number of comment lines: %d\n", cl);
    return 0;
}

int yywrap() {
    return 1;
}
