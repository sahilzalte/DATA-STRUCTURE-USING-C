#include <stdio.h>

int main()
{
    int arr[100] = {30, 48, 67, 43, 56};
    int n = 5, pos, elem;

    printf("Enter the element to insert: ");
    scanf("%d", &elem);

    printf("Enter the position: ");
    scanf("%d", &pos);

    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = elem;
    n++;

    if (pos < 0)
    {
        printf("Negative Position !");
    }
    else
    {
        printf("%d Element stored at position :%d the array", elem, pos);
    }

    return 0;
}
