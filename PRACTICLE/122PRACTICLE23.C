#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void insert(int value)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1)
    {
        front = 0; // Initialize front if queue is empty
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}
void deleteElement()
{
    if (front == -1)
    {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear)
    { // Queue becomes empty after deletion
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
        {
            break;
        }
        i = (i + 1) % MAX;
    }
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
