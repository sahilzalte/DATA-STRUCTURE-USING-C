#include <stdio.h>

int main()
{
    int arr[100], i, n, j, temp;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("Number of elements should not exceed 100.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // selection sort algorithm
    for (i = 0; i < n - 1; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted elements are: ");
    for (j = 0; j < n; ++j)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}
