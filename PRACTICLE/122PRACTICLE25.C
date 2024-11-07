#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Define the front pointer for the priority queue
struct Node *front = NULL;

// Function to insert an element into the priority queue
void insert(int value, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed! Unable to insert %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;

    // If the queue is empty or the new node has higher priority than the front node
    if (front == NULL || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        // Locate the node after which the new node should be inserted
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d with priority %d\n", value, priority);
}

// Function to delete an element with the highest priority from the queue
void deleteElement()
{
    if (front == NULL)
    {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted %d with priority %d\n", temp->data, temp->priority);
    front = front->next;
    free(temp);
}

// Function to display the elements of the priority queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements:\n");
    while (temp != NULL)
    {
        printf("Value: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, priority;

    while (1)
    {
        printf("\nPriority Queue Operations:\n");
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
            printf("Enter priority of the element: ");
            scanf("%d", &priority);
            insert(value, priority);
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
