#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the string follows the grammar
bool is_valid_grammar(const char *str, int start, int end) {
    if (start > end) {
        return true; // Empty string case
    }
    if (start == end) {
        return false; // Single character cannot be valid
    }
    if (str[start] == 'a' && str[end] == 'b') {
        return is_valid_grammar(str, start + 1, end - 1);
    }
    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    if (is_valid_grammar(input, 0, length - 1)) {
        printf("The string is valid according to the grammar.\n");
    } else {
        printf("The string is not valid according to the grammar.\n");
    }

    return 0;
}
