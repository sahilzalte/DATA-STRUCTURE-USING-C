#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_LEN 100
int main()
{
    char arr[MAX][MAX_LEN];
    int n, i, j;
    char temp[MAX_LEN];
    printf("Enter the number of strings you want to sort: ");
    scanf("%d", &n);
    getchar();
    if (n > 100)
    {
        printf("Number of strings should not exceed 100.\n");
        return 1;
    }
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
    {
        fgets(arr[i], MAX_LEN, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';
    }
    for (i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (j = i + 1; j < n; ++j)
        {
            if (strcmp(arr[j], arr[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            // Swap strings
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[minIndex]);
            strcpy(arr[minIndex], temp);
        }
    }

    // Display sorted strings
    printf("Sorted strings are:\n");
    for (i = 0; i < n; ++i)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}
