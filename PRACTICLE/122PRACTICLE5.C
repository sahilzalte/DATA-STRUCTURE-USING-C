#include <stdio.h>
#include <string.h>

#define MAX 50
#define MAX_LEN 100

int main() {
    char arr[MAX][MAX_LEN];
    int n;
    char search[MAX_LEN];
    char temp[MAX_LEN];

    // Input the number of strings
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();  // Clear newline character from input buffer

    // Input the strings
    printf("Enter %d strings: \n", n);
    for (int i = 0; i < n; i++) {
        fgets(arr[i], MAX_LEN, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  // Remove newline character
    }

    // Sort the array of strings using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                // Swap strings
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    // Input the search string
    printf("Enter the string you want to search: ");
    fgets(search, MAX_LEN, stdin);
    search[strcspn(search, "\n")] = '\0';  // Remove newline character

    // Binary search
    int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(arr[mid], search);

        if (cmp < 0) {
            low = mid + 1;
        } else if (cmp == 0) {
            printf("String '%s' found at location: %d\n", search, mid + 1);
            found = 1;
            break;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("String '%s' not found in the array.\n", search);
    }

    return 0;
}
