#include <stdio.h>
#define MAX 5

int queue[MAX];
int rear = -1;

void enqueue(int element)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        rear++;
        queue[rear] = element;
        printf("%d added to the queue.\n", element);
    }
}
int main()
{
    enqueue(10); // Add elements
    enqueue(20);
    enqueue(30);

    return 0;
}
