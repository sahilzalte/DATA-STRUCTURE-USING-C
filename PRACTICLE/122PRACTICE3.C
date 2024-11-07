#include <stdio.h>
#include <string.h>

#define MAX 10
#define LENGTH 100

int main()
{
    char a[MAX][LENGTH];
    char key[LENGTH];
    int n, i, flag = 0;

    // Prompt user to enter the size of the array (maximum size is 10)
    printf("\nEnter size of array (max %d): ", MAX);
    scanf("%d", &n);
    getchar(); // To consume the newline character left by scanf

    // Prompt user to enter array elements (strings)
    printf("\nEnter array elements (strings): \n");
    for (i = 0; i < n; i++)
    {
        fgets(a[i], LENGTH, stdin);    // Read a string
        a[i][strcspn(a[i], "\n")] = 0; // Remove the trailing newline character
    }

    // Prompt user to enter the key string to be searched
    printf("\nEnter key element to be searched: ");
    fgets(key, LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Remove the trailing newline character

    // Perform linear search for the key string
    for (i = 0; i < n; i++)
    {
        if (strcmp(key, a[i]) == 0)
        { // Compare key with each array element
            flag = 1;
            break;
        }
    }

    // Print the result of the search
    if (flag == 1)
    {
        printf("\nElement is found at index %d\n", i);
    }
    else
    {
        printf("\nElement is not found\n");
    }
    return 0;
}
