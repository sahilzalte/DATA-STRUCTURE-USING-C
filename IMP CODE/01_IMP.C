// Implement a 'C' program to search a particular data from the given array using Linear Search.
#include <stdio.h>

int main()
{
    int n, i, key, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element not found.\n");
    }

    return 0;
}
