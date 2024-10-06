#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data;
    struct node *next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct node **head, int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Element %d inserted at the end.\n", num);
}

// Function to insert a new node after a given element
void insertAfter(struct node *head, int target, int num)
{
    struct node *temp = head;
    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found in the list.\n", target);
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Element %d inserted after %d.\n", num, target);
    }
}

// Function to delete a node with a specific value
void deleteNode(struct node **head, int num)
{
    struct node *temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == num)
    {
        *head = temp->next;
        free(temp);
        printf("Element %d deleted from the list.\n", num);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != num)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the element was not found
    if (temp == NULL)
    {
        printf("Element %d not found in the list.\n", num);
        return;
    }

    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted from the list.\n", num);
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
    int choice, num, target;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert after a given element\n");
        printf("3. Delete an element\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to insert at the end: ");
            scanf("%d", &num);
            insertAtEnd(&head, num);
            break;

        case 2:
            printf("Enter the element to insert after: ");
            scanf("%d", &target);
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            insertAfter(head, target, num);
            break;

        case 3:
            printf("Enter the number to delete: ");
            scanf("%d", &num);
            deleteNode(&head, num);
            break;

        case 4:
            display(head);
            break;

        case 5:
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
