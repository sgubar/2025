#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, char data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int search(Node* root, char data) {
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;
    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

void printMenu() {
    printf("\nChoose an action:\n");
    printf("1 - Insert element\n");
    printf("2 - Delete element\n");
    printf("3 - Search for element\n");
    printf("4 - Print tree (preorder)\n");
    printf("5 - Exit\n");
    printf("Your choice: ");
}

int main() {
    Node* root = NULL;
    int choice;
    char ch;

    while (1) {
        printMenu();
        scanf(" %d", &choice);  // пробіл перед %d — щоб очистити буфер

        switch (choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                root = insert(root, ch);
                printf("Inserted '%c'.\n", ch);
                break;
            case 2:
                printf("Enter character to delete: ");
                scanf(" %c", &ch);
                root = deleteNode(root, ch);
                printf("Deleted '%c' (if it existed).\n", ch);
                break;
            case 3:
                printf("Enter character to search for: ");
                scanf(" %c", &ch);
                if (search(root, ch))
                    printf("Element '%c' found in the tree.\n", ch);
                else
                    printf("Element '%c' not found in the tree.\n", ch);
                break;
            case 4:
                printf("Tree (preorder): ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                deleteTree(root);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
