#include <stdio.h>

void reverseString(char *str)
{
    if (*str == '\0')
    {
        return;
    }
    reverseString(str + 1);
    printf("%c", *str);
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    gets(str); // Use gets() to input string

    printf("Reversed string: ");
    reverseString(str); // Call the recursive function
    printf("\n");

    return 0;
}
