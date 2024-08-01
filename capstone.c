#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack type
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// Stack Operations
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

// A utility function to check if the given character is operand
int isOperand(char ch) {
    return isalnum(ch);
}

// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

// The main function that converts given infix expression
// to postfix expression
int infixToPostfix(char* exp) {
    int i, k;

    // Create a stack of capacity equal to expression size
    Stack* stack = createStack(strlen(exp));
    if (!stack) // See if stack was created successfully
        return -1;

    for (i = 0, k = -1; exp[i]; ++i) {
        // If the scanned character is an operand, add it to output
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        // If the scanned character is an '(', push it to the stack
        else if (exp[i] == '(')
            push(stack, exp[i]);

        // If the scanned character is an ')', pop and output from the stack
        // until an '(' is encountered
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression
            else
                pop(stack);
        } else // an operator is encountered
        {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s", exp);
    return 0;
}

// Driver program to test above functions
int main() {
    char exp[] = "a*b-c+8";
    infixToPostfix(exp);
    return 0;
}
