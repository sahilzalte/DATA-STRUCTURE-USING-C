#include <stdio.h>

int main() {
    int i, lower, upper, mid, n, search, arr[50];
    
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    
    printf("\nEnter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter element you want to search: ");
    scanf("%d", &search);

    lower = 0;
    upper = n - 1;
    mid = (lower + upper) / 2;

    while (lower <= upper) {
        if (arr[mid] < search) {
            lower = mid + 1;
        } else if (arr[mid] == search) {
            printf("\n%d found at location: %d", search, mid + 1);
            break;
        } else {
            upper = mid - 1;
        }
        mid = (lower + upper) / 2;
    }

    if (lower > upper) {
        printf("\n%d not found in the list", search);
    }

    return 0;
}
