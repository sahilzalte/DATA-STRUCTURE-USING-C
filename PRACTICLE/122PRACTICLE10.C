#include <stdio.h>

int main()
{
    int arr[100], n, temp, i, j;

    // Input the number of elements
    printf("Enter number of elements you want to sort: ");
    scanf("%d", &n);

    if (n > 100)
    {
        printf("Number of elements should not exceed 100.\n");
        return 1;
    }

    // Input the elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Use &arr[i] to store input in the array
    }

    // Insertion sort algorithm
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }

    // Output sorted elements
    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
