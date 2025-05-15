#include <stdio.h>
#include <stdlib.h>

// Structure of the tree node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// === Tree functions ===

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert an element
Node* insertNode(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value)
        root->right = insertNode(root->right, value);
    else
        printf("Element %d already exists in the tree.\n", value);

    return root;
}

// Search for an element
Node* search(Node* root, int value) {
    if (root == NULL || root->value == value)
        return root;
    if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Find minimum value node (for deletion)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete an element
Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Node with one or no children
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
        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

// Post-order traversal (left – right – root)
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

// Delete the whole tree
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// === User interaction ===

void printMenu() {
    printf("\nMenu:\n");
    printf("1 - Add element\n");
    printf("2 - Delete element\n");
    printf("3 - Search for element\n");
    printf("4 - Print tree (post-order traversal)\n");
    printf("5 - Clear tree\n");
    printf("0 - Exit\n");
}

int readInt(const char* prompt) {
    int x;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &x, &term) != 2 || term != '\n') {
            printf("Invalid input! Please enter an integer number.\n");
            while (getchar() != '\n'); // clear buffer
        } else {
            return x;
        }
    }
}

// === Main function ===
int main() {
    Node* root = NULL;
    int choice, val;

    printf("Binary tree (int), post-order traversal\n");

    do {
        printMenu();
        choice = readInt("Your choice: ");

        switch (choice) {
            case 1:
                val = readInt("Enter value to insert: ");
                root = insertNode(root, val);
                break;
            case 2:
                val = readInt("Enter value to delete: ");
                root = deleteNode(root, val);
                break;
            case 3:
                val = readInt("Enter value to search: ");
                if (search(root, val))
                    printf("Element %d found in the tree.\n", val);
                else
                    printf("Element %d not found.\n", val);
                break;
            case 4:
                printf("Post-order traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                root = NULL;
                printf("Tree cleared.\n");
                break;
            case 0:
                deleteTree(root);
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number from 0 to 5.\n");
        }
    } while (choice != 0);

    return 0;
}
