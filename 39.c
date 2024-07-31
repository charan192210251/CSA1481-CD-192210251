#include <stdio.h>

int main() {
    int a, b;
    int ab;  // Variable to store common subexpression
    int c;
    int d;
    
    // Input values for a and b
    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);
    
    // Compute common subexpression once
    ab = a * b;

    // Use precomputed value
    c = ab + ab;
    d = ab - ab;
    
    // Output results
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    
    return 0;
}
