#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
double expression();
double term();
double factor();
double exponent();
double number();
void match(char expected);

// Global variable to hold the input expression and its current index
const char *input;
int index = 0;

// Function to evaluate expressions according to PEMDAS
double expression() {
    double result = term();
    while (input[index] == '+' || input[index] == '-') {
        char op = input[index];
        match(op);
        double nextTerm = term();
        if (op == '+') {
            result += nextTerm;
        } else {
            result -= nextTerm;
        }
    }
    return result;
}

double term() {
    double result = factor();
    while (input[index] == '*' || input[index] == '/') {
        char op = input[index];
        match(op);
        double nextFactor = factor();
        if (op == '*') {
            result *= nextFactor;
        } else {
            result /= nextFactor;
        }
    }
    return result;
}

double factor() {
    double result = exponent();
    return result;
}

double exponent() {
    double result = number();
    while (input[index] == '^') {
        match('^');
        double exponentValue = number();
        result = pow(result, exponentValue);
    }
    return result;
}

double number() {
    double result;
    if (input[index] == '(') {
        match('(');
        result = expression();
        match(')');
    } else if (isdigit(input[index]) || input[index] == '.') {
        char num[50];
        int numIndex = 0;
        while (isdigit(input[index]) || input[index] == '.') {
            num[numIndex++] = input[index++];
        }
        num[numIndex] = '\0';
        result = atof(num);
    } else {
        printf("Invalid character: %c\n", input[index]);
        exit(1);
    }
    return result;
}

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        printf("Expected %c but found %c\n", expected, input[index]);
        exit(1);
    }
}

int main() {
    char inputString[100];
    
    printf("Enter the expression: ");
    scanf("%s", inputString);
    input = inputString;
    
    double result = expression();
    
    if (input[index] == '\0') {
        printf("The result of the expression is: %lf\n", result);
    } else {
        printf("Invalid expression\n");
    }
    
    return 0;
}
