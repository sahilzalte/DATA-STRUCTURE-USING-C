#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to perform pre-order traversal of the BST
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);      // Visit node
        preorderTraversal(root->left);  // Traverse left subtree
        preorderTraversal(root->right); // Traverse right subtree
    }
}

// Function to perform post-order traversal of the BST
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);  // Traverse left subtree
        postorderTraversal(root->right); // Traverse right subtree
        printf("%d ", root->data);       // Visit node
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. Post-Order Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Inserted %d\n", value);
            break;
        case 2:
            printf("Pre-Order Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Post-Order Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
