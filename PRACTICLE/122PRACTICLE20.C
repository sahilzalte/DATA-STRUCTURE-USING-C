#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to traverse the linked list in reverse order using recursion
void traverseReverse(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    traverseReverse(head->next);
    printf("%d -> ", head->data);
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input values for the nodes
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    // Traverse the linked list in reverse order
    printf("Linked list in reverse order: ");
    traverseReverse(head);
    printf("NULL\n");

    return 0;
}
