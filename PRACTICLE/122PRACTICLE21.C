#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to insert an element into the queue
void insert(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to delete an element from the queue
void deleteElement()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
    if (front > rear)
    { // Reset queue if empty
        front = rear = -1;
    }
}

// Function to display the queue elements
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
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
