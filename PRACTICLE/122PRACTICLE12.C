#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of the list
void addtagbeg(struct node **head, int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = *head;
    *head = newnode;
}

// Function to search for a node with a given value
void search(struct node *head, int data)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (data == current->data)
        {
            printf("Element found: %d\n", data);
            return;
        }
        current = current->next;
    }
    printf("Element not found\n");
}

// Function to display all nodes in the list
void display(struct node *head)
{
    struct node *current = head;
    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to handle menu-driven operations
void menu()
{
    struct node *head = NULL; // Initialize the head of the list
    int choice, num;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Search for an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            addtagbeg(&head, num);
            printf("Element %d inserted at the beginning.\n", num);
            break;

        case 2:
            printf("Enter the number to search: ");
            scanf("%d", &num);
            search(head, num);
            break;

        case 3:
            display(head);
            break;
        case 4:
            printf("Exiting...\n");
            // Free the allocated memory
            while (head != NULL)
            {
                struct node *temp = head;
                head = head->next;
                free(temp);
            }
            return;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

int main()
{
    menu();
    return 0;
}