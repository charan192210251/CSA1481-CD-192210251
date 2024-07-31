%{
#include <stdio.h>
#include <ctype.h>

int num_chars = 0;  // Counter for characters
int num_lines = 0;  // Counter for lines
int num_words = 0;  // Counter for words
int in_word = 0;    // Flag to check if we are inside a word
%}

%%

\n                  { num_lines++; }   // Count lines
[ \t]+               { /* Ignore whitespace */ }
[a-zA-Z0-9]+         { 
                        num_words++; 
                        in_word = 1; 
                    }
.                    { num_chars++; }   // Count all characters (including punctuation)

%%

int main(int argc, char **argv) {
    yylex();  // Start lexical analysis

    // Print the counts
    printf("Number of characters: %d\n", num_chars);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);

    return 0;
}
