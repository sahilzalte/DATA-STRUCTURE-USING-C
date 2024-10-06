#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_LEN 100
int main() {
    char arr[MAX][MAX_LEN];
    int n, i, j;
    char temp[MAX_LEN];
    printf("Enter the number of strings you want to sort (up to %d): ", MAX);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid input. Please enter a positive integer up to %d.\n", MAX);
        return 1;
    }
    getchar(); 
    // Input the strings
    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        fgets(arr[i], MAX_LEN, stdin);
        arr[i][strcspn(arr[i], "\n")] = '\0';  
    }

    
    for (i = 1; i < n; i++) {
        strcpy(temp, arr[i]);
        j = i - 1;

        
        while (j >= 0 && strcmp(arr[j], temp) > 0) {
            strcpy(arr[j + 1], arr[j]);
            --j;
        }
        strcpy(arr[j + 1], temp);
    }

    // Output sorted strings
    printf("Sorted strings are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}
