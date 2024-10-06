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

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* ptr1 = poly1;
    struct Node* ptr2 = poly2;

    // Traverse both polynomials and add corresponding terms
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exponent > ptr2->exponent) {
            insertTerm(&result, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        } else if (ptr1->exponent < ptr2->exponent) {
            insertTerm(&result, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        } else {
            // Exponents are the same, so add the coefficients
            int sum = ptr1->coefficient + ptr2->coefficient;
            if (sum != 0) {
                insertTerm(&result, sum, ptr1->exponent);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    // Add remaining terms of polynomial 1
    while (ptr1 != NULL) {
        insertTerm(&result, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }

    // Add remaining terms of polynomial 2
    while (ptr2 != NULL) {
        insertTerm(&result, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sumPoly = NULL;

    // Inserting terms into the first polynomial (e.g., 5x^3 + 4x^2 + 2)
    insertTerm(&poly1, 5, 3);  // 5x^3
    insertTerm(&poly1, 4, 2);  // 4x^2
    insertTerm(&poly1, 2, 0);  // 2

    // Inserting terms into the second polynomial (e.g., 3x^4 + 1x^3 + 2x^2 + 3x)
    insertTerm(&poly2, 3, 4);  // 3x^4
    insertTerm(&poly2, 1, 3);  // 1x^3
    insertTerm(&poly2, 2, 2);  // 2x^2
    insertTerm(&poly2, 3, 1);  // 3x

    // Display the input polynomials
    printf("First Polynomial: ");
    displayPolynomial(poly1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    sumPoly = addPolynomials(poly1, poly2);

    // Display the result of the addition
    printf("Sum of Polynomials: ");
    displayPolynomial(sumPoly);

    return 0;
}
