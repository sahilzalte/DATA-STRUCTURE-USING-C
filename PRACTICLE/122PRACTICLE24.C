#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    struct Node *next;
};

// Define the front and rear pointers for the circular queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to insert an element into the circular queue
void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed! Unable to insert %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL)
    { // Queue is empty
        front = rear = newNode;
        rear->next = front; // Link back to front to make it circular
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
    printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue
void deleteElement()
{
    if (front == NULL)
    { // Queue is empty
        printf("Queue Underflow! No elements to delete\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear)
    { // Only one element in the queue
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    printf("Deleted %d\n", temp->data);
    free(temp);
}

// Function to display the elements of the circular queue
void display()
{
    if (front == NULL)
    { // Queue is empty
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nCircular Queue Operations:\n");
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
