#include <stdio.h>
#define max 5
int queue[max];
int rear = -1;
void enqueue(int element)
{
    if (rear == max - 1)
    {
        printf("Queue is full !\n");
    }
    else
    {
        rear++;
        queue[rear] = element;
        printf("%d Element is inserted into queue.\n", element);
    }
}
int main()
{
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);

    return 0;
}