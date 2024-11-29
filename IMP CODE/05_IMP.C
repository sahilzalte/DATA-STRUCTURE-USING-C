//  Stack (Push and Pop using Linked List)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

// Push operation
void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", value);
}

// Pop operation
void pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    Node *temp = top;
    top = top->next;
    printf("%d popped from the stack.\n", temp->data);
    free(temp);
}

// Display stack
void displayStack()
{
    Node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();
    return 0;
}
