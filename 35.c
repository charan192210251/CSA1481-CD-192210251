
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char *input;
char lookahead;

void next_char() {
    lookahead = *input++;
}

void match_id() {
    if (isalpha(lookahead)) {
        next_char();
    } else {
        printf("Syntax error: Expected identifier\n");
        exit(1);
    }
}

void F() {
    if (lookahead == '(') {
        next_char();
        void E();
        if (lookahead == ')') {
            next_char();
        } else {
            printf("Syntax error: Expected ')'\n");
            exit(1);
        }
    } else if (isalpha(lookahead)) {
        match_id();
    } else {
        printf("Syntax error: Expected id or '('\n");
        exit(1);
    }
}

void T_prime() {
    if (lookahead == '*') {
        next_char();
        F();
        T_prime();
    } else if (lookahead == '/') {
        next_char();
        F();
        T_prime();
    }
}

void T() {
    F();
    T_prime();
}

void E_prime() {
    if (lookahead == '+') {
        next_char();
        T();
        E_prime();
    } else if (lookahead == '-') {
        next_char();
        T();
        E_prime();
    }
}

void E() {
    T();
    E_prime();
}

void parse() {
    next_char();
    E();
    if (lookahead != '\0') {
        printf("Syntax error: Unexpected character '%c'\n", lookahead);
        exit(1);
    }
    printf("Parsing successful\n");
}

int main() {
    char buffer[256];
    printf("Enter an expression: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline character
    input = buffer;
    lookahead = ' '; // Initialize lookahead
    parse();
    return 0;
}
