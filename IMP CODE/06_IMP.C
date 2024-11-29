// Queue (Enqueue and Dequeue using Linked List)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into the queue.\n", value);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }
    Node *temp = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    printf("%d dequeued from the queue.\n", temp->data);
    free(temp);
}

// Display queue
void displayQueue()
{
    Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
