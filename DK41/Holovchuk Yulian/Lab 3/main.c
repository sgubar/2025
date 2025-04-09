#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ----------- Data Structure -----------

typedef struct Node {
    float value;
    struct Node* left;
    struct Node* right;
} Node;

// ----------- Tree Operations -----------

Node* createNode(float value) {
    Node* node = malloc(sizeof(Node));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, float value) {
    if (!root)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

Node* search(Node* root, float value) {
    if (!root || root->value == value)
        return root;

    return (value < root->value)
        ? search(root->left, value)
        : search(root->right, value);
}

Node* findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, float value) {
    if (!root)
        return NULL;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left) {
            Node* rightChild = root->right;
            free(root);
            return rightChild;
        }
        if (!root->right) {
            Node* leftChild = root->left;
            free(root);
            return leftChild;
        }

        Node* minRight = findMin(root->right);
        root->value = minRight->value;
        root->right = deleteNode(root->right, minRight->value);
    }

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    printf("%.2f ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// ----------- Input Functions -----------

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getMenuChoice() {
    int choice;
    char term;

    while (1) {
        printf("\nChoose an option (0 - 5): ");
        if (scanf("%d%c", &choice, &term) != 2 || term != '\n') {
            printf("Invalid input. Please enter a number between 0 and 5.\n");
            clearInputBuffer();
        } else if (choice < 0 || choice > 5) {
            printf("Invalid choice. Option must be between 0 and 5.\n");
        } else {
            return choice;
        }
    }
}

float getFloatInput(const char* prompt) {
    float value;
    char term;

    while (1) {
        printf("%s (example: 3.14 or -2.0): ", prompt);
        if (scanf("%f%c", &value, &term) != 2 || term != '\n') {
            printf("Invalid input. Please enter a valid floating point number.\n");
            clearInputBuffer();
        } else {
            return value;
        }
    }
}

// ----------- User Interface -----------

void printMenu() {
    printf("\n========== Binary Tree ==========\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Search element\n");
    printf("4. Print tree (pre-order)\n");
    printf("5. Delete entire tree\n");
    printf("0. Exit\n");
}

int main() {
    Node* root = NULL;
    int option;
    float input;

    do {
        printMenu();
        option = getMenuChoice();

        switch (option) {
            case 1:
                input = getFloatInput("Enter a number to insert");
                root = insert(root, input);
                printf("Inserted %.2f into the tree.\n", input);
                break;

            case 2:
                if (!root) {
                    printf("Tree is empty. Nothing to delete.\n");
                    break;
                }
                input = getFloatInput("Enter a number to delete");
                root = deleteNode(root, input);
                printf("Deleted %.2f if it existed.\n", input);
                break;

            case 3:
                if (!root) {
                    printf("Tree is empty. Nothing to search.\n");
                    break;
                }
                input = getFloatInput("Enter a number to search");
                if (search(root, input))
                    printf("Element %.2f was found in the tree.\n", input);
                else
                    printf("Element %.2f was NOT found in the tree.\n", input);
                break;

            case 4:
                printf("Tree (pre-order): ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                deleteTree(root);
                root = NULL;
                printf("The tree has been deleted.\n");
                break;

            case 0:
                deleteTree(root);
                printf("Exiting program. Goodbye!\n");
                break;
        }

    } while (option != 0);

    return 0;
}
