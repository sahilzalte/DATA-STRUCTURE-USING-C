#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    struct Node *next;
};

// Define the front and rear pointers for the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to insert an element into the queue
void insert(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed! Unable to insert %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, front and rear point to the new node
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        // Attach the new node at the end of the queue and move the rear pointer
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", value);
}

// Function to delete an element from the queue
void deleteElement()
{
    if (front == NULL)
    {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted %d\n", front->data);
    front = front->next;

    // If front becomes NULL, set rear to NULL as well (queue is now empty)
    if (front == NULL)
    {
        rear = NULL;
    }

    // Free the memory of the deleted node
    free(temp);
}

// Function to display the elements of the queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            deleteElement();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
