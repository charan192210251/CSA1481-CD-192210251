#include <stdio.h>
#include <ctype.h>

int main() {
    int ch;
    int lines = 0, words = 0, characters = 0;
    int in_word = 0;

    printf("Enter text (Press Ctrl+D or Ctrl+Z to end input):\n");

    while ((ch = getchar()) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch) || ch == '\n' || ch == '\t') {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }

    // If the last character was part of a word
    if (in_word) {
        words++;
    }

    printf("\nLines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    return 0;
}
