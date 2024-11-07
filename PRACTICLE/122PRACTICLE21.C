#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;

void insert(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete\n");
        return;
    }
    printf("Deleted %d\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value to insert: "); scanf("%d", &value); insert(value); break;
            case 2: deleteElement(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}
