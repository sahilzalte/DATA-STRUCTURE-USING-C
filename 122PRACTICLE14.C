#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term (node)
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new term into the polynomial (sorted by exponent)
void insertTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    if (*poly == NULL || (*poly)->exponent < exponent) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        struct Node* current = *poly;
        while (current->next != NULL && current->next->exponent >= exponent) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Inserting terms into the first polynomial
    insertTerm(&poly1, 5, 3);  // 5x^3
    insertTerm(&poly1, 4, 2);  // 4x^2
    insertTerm(&poly1, 2, 0);  // 2

    // Inserting terms into the second polynomial
    insertTerm(&poly2, 3, 4);  // 3x^4
    insertTerm(&poly2, 1, 3);  // 1x^3
    insertTerm(&poly2, 2, 2);  // 2x^2
    insertTerm(&poly2, 3, 1);  // 3x^1

    // Displaying the polynomials
    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    return 0;
}
