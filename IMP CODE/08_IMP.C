// Queue (Enqueue and Dequeue using Array)
#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0; // Set front to 0 if inserting the first element
    queue[++rear] = value;
    printf("%d enqueued into the queue.\n", value);
}

// Dequeue operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from the queue.\n", queue[front++]);
    if (front > rear)
        front = rear = -1; // Reset the queue when empty
}

// Display queue
void displayQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
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
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}
