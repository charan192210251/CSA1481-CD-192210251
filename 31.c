#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function prototypes
void eliminateLeftRecursion(char *nonTerminal, char productions[][MAX], int numProductions);

int main() {
    // Define the non-terminal and its productions directly
    char nonTerminal[] = "A";
    int numProductions = 2;

    // Define the productions (example: A -> Aa | ß)
    char productions[2][MAX] = {
        "Aa",
        "ß"
    };

    eliminateLeftRecursion(nonTerminal, productions, numProductions);

    return 0;
}

// Function to eliminate left recursion
void eliminateLeftRecursion(char *nonTerminal, char productions[][MAX], int numProductions) {
    char newNonTerminal[MAX];
    snprintf(newNonTerminal, sizeof(newNonTerminal), "%s'", nonTerminal);

    printf("Eliminated Left Recursion:\n");

    // Print the first set of productions
    printf("%s -> ", nonTerminal);
    int hasNonLeftRecursive = 0;
    int i;
    for (i = 0; i < numProductions; i++) {
        if (productions[i][0] != nonTerminal[0]) {
            if (hasNonLeftRecursive) {
                printf(" | ");
            }
            hasNonLeftRecursive = 1;
            printf("%s%s", productions[i], newNonTerminal);
        }
    }
    if (!hasNonLeftRecursive) {
        printf("e");
    }
    printf("\n");

    // Print the new non-terminal productions
    printf("%s -> ", newNonTerminal);
    int hasRecursive = 0;
    for (i = 0; i < numProductions; i++) {
        if (productions[i][0] == nonTerminal[0]) {
            char temp[MAX];
            snprintf(temp, sizeof(temp), "%s", &productions[i][1]);
            if (hasRecursive) {
                printf(" | ");
            }
            hasRecursive = 1;
            printf("%s%s", temp, newNonTerminal);
        }
    }
    if (!hasRecursive) {
        printf("e");
    }
    printf("\n");
}
