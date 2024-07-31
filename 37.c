#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int tempCount = 1;

void generateThreeAddressCode(char* expr) {
    char temp[10];
    char opStack[100];
    int opTop = -1;
    char output[100];
    int outIndex = 0;
    
    // Tokenize the expression
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            // If token is a number, push to the output
            output[outIndex++] = token[0];
        } else if (token[0] == '*' || token[0] == '/') {
            // Handle * and / operators
            while (opTop >= 0 && (opStack[opTop] == '*' || opStack[opTop] == '/')) {
                output[outIndex++] = opStack[opTop--];
            }
            opStack[++opTop] = token[0];
        } else if (token[0] == '+' || token[0] == '-') {
            // Handle + and - operators
            while (opTop >= 0) {
                output[outIndex++] = opStack[opTop--];
            }
            opStack[++opTop] = token[0];
        }
        token = strtok(NULL, " ");
    }

    while (opTop >= 0) {
        output[outIndex++] = opStack[opTop--];
    }
    output[outIndex] = '\0';

    // Generate the three-address code
    int j = 0;
    while (output[j] != '\0') {
        if (isdigit(output[j])) {
            printf("t%d = %c\n", tempCount++, output[j]);
        } else if (output[j] == '*' || output[j] == '/') {
            printf("t%d = t%d %c t%d\n", tempCount, tempCount-2, output[j], tempCount-1);
            tempCount++;
        } else if (output[j] == '+' || output[j] == '-') {
            printf("t%d = t%d %c t%d\n", tempCount, tempCount-2, output[j], tempCount-1);
            tempCount++;
        }
        j++;
    }
}

int main() {
    char expr[100];
    printf("Enter the expression (with spaces between tokens, e.g., 2 + 3 * 5):\n");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';  // Remove newline character

    printf("Intermediate Code for expression %s:\n", expr);
    generateThreeAddressCode(expr);
    return 0;
}
