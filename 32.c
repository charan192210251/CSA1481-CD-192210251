#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function prototypes
void eliminateLeftFactoring(char *nonTerminal, char productions[][MAX], int numProductions);

int main() {
    // Hardcoded non-terminal and productions
    char nonTerminal[] = "A";
    int numProductions = 3;
    char productions[3][MAX] = {
        "aß1",
        "aß2",
        "aß3"
    };

    // Perform left factoring
    eliminateLeftFactoring(nonTerminal, productions, numProductions);

    return 0;
}

// Function to eliminate left factoring
void eliminateLeftFactoring(char *nonTerminal, char productions[][MAX], int numProductions) {
    char commonPrefix[MAX];
    int commonPrefixLength = 0;
    int i, j;

    // Initialize commonPrefix
    commonPrefix[0] = '\0';

    // Check for common prefix among productions
    for (i = 1; i < numProductions; i++) {
        j = 0;
        while (productions[0][j] != '\0' && productions[i][j] != '\0' && productions[0][j] == productions[i][j]) {
            j++;
        }
        if (j > commonPrefixLength) {
            commonPrefixLength = j;
            strncpy(commonPrefix, productions[0], j);
            commonPrefix[j] = '\0';
        }
    }

    // No common prefix found
    if (commonPrefixLength == 0) {
        printf("%s -> ", nonTerminal);
        for (i = 0; i < numProductions; i++) {
            if (i > 0) {
                printf(" | ");
            }
            printf("%s", productions[i]);
        }
        printf("\n");
        return;
    }

    // Printing the new non-terminal
    char newNonTerminal[MAX];
    snprintf(newNonTerminal, sizeof(newNonTerminal), "%s'", nonTerminal);

    // Print the original non-terminal with the common prefix factored out
    printf("%s -> %s%s\n", nonTerminal, commonPrefix, newNonTerminal);

    // Print the new non-terminal productions
    printf("%s -> ", newNonTerminal);
    int first = 1;
    for (i = 0; i < numProductions; i++) {
        if (strncmp(productions[i], commonPrefix, commonPrefixLength) == 0) {
            if (!first) {
                printf(" | ");
            }
            first = 0;
            printf("%s", &productions[i][commonPrefixLength]);
        }
    }
    if (first) {
        printf("e");
    }
    printf("\n");
}
