#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 100

int main()
{
    char arr[MAX][MAX_LEN];
    int n, i, j;
    char temp[MAX_LEN];

    // Input the number of strings
    printf("Enter number of strings you want to sort: ");
    scanf("%d", &n);
    getchar(); // Clear newline character from input buffer

    // Input the strings
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
    {
        fgets(arr[i], MAX_LEN, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0'; // Remove newline character
    }

    // Bubble sort algorithm for strings
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                // Swap strings
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }

    // Display sorted strings
    printf("Sorted strings are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}
