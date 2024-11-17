#include <stdio.h>

// Recursive function for multiplication
int multiply(int a, int b) {
    if (b == 0)
        return 0;
    return a + multiply(a, b - 1);
}

int main() {
    int num1, num2, result;

    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &num1, &num2);

    // Call recursive function
    result = multiply(num1, num2);

    printf("Result: %d\n", result);
    return 0;
}
