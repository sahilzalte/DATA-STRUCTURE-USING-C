#include <stdio.h>

// Recursive function to multiply two numbers
int multiply(int a, int b) {
    if (a == 0)  // Base case: if 'a' is 0, return 0
        return 0;
    return b + multiply(a - 1, b);  // Recursively add 'b' 'a' times
}

int main() {
    int a, b;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Call the recursive function and print the result
    printf("Multiplication of %d and %d is: %d\n", a, b, multiply(a, b));

    return 0;
}
