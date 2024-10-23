#include<stdio.h>

int main() {
    int arr[100], num = 0, i, loc, choice, element;

    while (1) {
        // Menu-driven interface
        printf("\nArray Operations:\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                
                printf("How many elements do you want?\n");
                scanf("%d", &num);
                printf("Enter the %d elements:\n", num);
                for (i = 0; i < num; i++) {
                    scanf("%d", &arr[i]);  
                }
                break;

            case 2:
                
                if (num >= 100) {
                    printf("Array is full, cannot insert element.\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (1-based index) to insert: ");
                scanf("%d", &loc);
                loc--;  
                if (loc > num || loc < 0) {
                    printf("Invalid position!\n");
                } else {
                    for (i = num; i > loc; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[loc] = element;
                    num++;
                }
                break;

            case 3:
                
                printf("Enter the location where you want to delete (1-based index): ");
                scanf("%d", &loc);
                loc--;  
                if (loc >= num || loc < 0) {
                    printf("Delete not possible\n");
                } else {
                    for (i = loc; i < num - 1; i++) {
                        arr[i] = arr[i + 1];  
                    }
                    num--;  
                    printf("Element deleted successfully.\n");
                }
                break;

            case 4:
                
                printf("You entered these values: ");
                for (i = 0; i < num; i++) {
                    printf("%d ", arr[i]);  
                }
                printf("\n");
                break;

            case 5:
                
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
