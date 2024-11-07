#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void PUSH()
{
    int val;
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &val);

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    temp->data = val;
    temp->next = top;
    top = temp;
    printf("Element %d pushed onto stack.\n", val);
}
void POP()
{
    if (top == NULL)
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        struct Node *temp = top;
        printf("\nDeleted Element: %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}
void DISPLAY()
{
    if (top == NULL)
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        struct Node *temp = top;
        printf("\n**** Elements in Stack ****\n");
        while (temp != NULL)
        {
            printf(" %d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choice;
    printf("\n *** STACK USING LINKED LIST ***\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. DISPLAY\n");
    printf("4. EXIT\n");

    while (1)
    {
        printf("\nEnter your choice (1-4): ");
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input! Please enter a number.\n");
            continue;
        }
        switch (choice)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
