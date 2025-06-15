#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include <math.h>

// Definition of a binary tree node with float data
typedef struct Node {
    float data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with given data
Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inorder (symmetrical) traversal to print the tree
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%.2f ", root->data);
    inorderTraversal(root->right);
}

// Insert a value into the binary search tree
Node* insertNode(Node* root, float value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    } else {
        printf("Warning: Element %.2f already exists.\n", value);
    }
    return root;
}

// Find the node with minimum value in a tree
Node* findMinNode(Node* root) {
    Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node with given value
Node* deleteNode(Node* root, float value) {
    if (root == NULL) {
        printf("Warning: Element %.2f not found.\n", value);
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node found
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a value in the tree
Node* searchNode(Node* root, float value) {
    if (root == NULL || fabs(root->data - value) < 1e-6)
        return root;
    if (value < root->data)
        return searchNode(root->left, value);
    else
        return searchNode(root->right, value);
}

// Delete entire tree and free memory
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Helper: read a float with validation
int readFloat(const char* prompt, float* out) {
    char buffer[100];
    char* endptr;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            return 0;
        }
        errno = 0;
        *out = strtof(buffer, &endptr);
        if (errno != 0 || endptr == buffer || *endptr != '\n') {
            printf("Invalid input. Please enter a valid float number.\n");
            continue;
        }
        return 1;
    }
}

// Helper: read an integer choice with validation
int readInt(const char* prompt, int min, int max, int* out) {
    char buffer[100];
    char* endptr;
    long val;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            return 0;
        }
        errno = 0;
        val = strtol(buffer, &endptr, 10);
        if (errno != 0 || endptr == buffer || *endptr != '\n' || val < min || val > max) {
            printf("Invalid choice. Please enter an integer between %d and %d.\n", min, max);
            continue;
        }
        *out = (int)val;
        return 1;
    }
}

int main() {
    Node* root = NULL;
    int choice;
    float value;

    printf("Binary Search Tree (float elements, inorder traversal)\n");
    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Print tree (inorder)\n");
        printf("5. Delete entire tree\n");
        printf("6. Exit\n");
        if (!readInt("Enter your choice (1-6): ", 1, 6, &choice)) break;

        switch (choice) {
            case 1:
                if (readFloat("Enter float value to insert: ", &value)) {
                    root = insertNode(root, value);
                }
                break;
            case 2:
                if (readFloat("Enter float value to delete: ", &value)) {
                    root = deleteNode(root, value);
                }
                break;
            case 3:
                if (readFloat("Enter float value to search: ", &value)) {
                    Node* found = searchNode(root, value);
                    if (found)
                        printf("Element %.2f found in the tree.\n", value);
                    else
                        printf("Element %.2f not found.\n", value);
                }
                break;
            case 4:
                printf("Tree inorder: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                root = NULL;
                printf("Entire tree deleted.\n");
                break;
            case 6:
                deleteTree(root);
                printf("Exiting program.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
