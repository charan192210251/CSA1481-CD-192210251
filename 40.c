#include <stdio.h>
#include <stdlib.h>

// Function to generate assembly code for addition
void generateAdditionAssembly(int operand1, int operand2, int result) {
    printf("MOV EAX, %d\n", operand1);  // Move operand1 into EAX register
    printf("ADD EAX, %d\n", operand2);  // Add operand2 to EAX register
    printf("MOV [%d], EAX\n", result);  // Store result from EAX into memory
}

// Function to generate assembly code for subtraction
void generateSubtractionAssembly(int operand1, int operand2, int result) {
    printf("MOV EAX, %d\n", operand1);  // Move operand1 into EAX register
    printf("SUB EAX, %d\n", operand2);  // Subtract operand2 from EAX register
    printf("MOV [%d], EAX\n", result);  // Store result from EAX into memory
}

// Main function simulating the backend of the compiler
int main() {
    int operand1, operand2, result;
    char operation;
    
    // Get input from the user
    printf("Enter the first operand: ");
    scanf("%d", &operand1);
    printf("Enter the second operand: ");
    scanf("%d", &operand2);
    printf("Enter the operation (+ or -): ");
    scanf(" %c", &operation);  // Note the space before %c to consume any newline character
    
    // Generate assembly code based on the operation
    if (operation == '+') {
        printf("Assembly code for addition:\n");
        result = operand1 + operand2;  // Compute result
        generateAdditionAssembly(operand1, operand2, result);
    } else if (operation == '-') {
        printf("Assembly code for subtraction:\n");
        result = operand1 - operand2;  // Compute result
        generateSubtractionAssembly(operand1, operand2, result);
    } else {
        printf("Unsupported operation.\n");
    }
    
    return 0;
}
