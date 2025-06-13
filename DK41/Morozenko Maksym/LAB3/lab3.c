#include <stdio.h> 
#include <stdlib.h>

// Структура вузла дерева
typedef struct Node {
    double data;
    struct Node* left;
    struct Node* right;
} Node;

// Створення нового вузла
Node* createNode(double data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Додавання вузла
Node* insert(Node* root, double data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Пошук вузла
Node* search(Node* root, double data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Пошук вузла з мінімальним значенням
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Видалення вузла
Node* deleteNode(Node* root, double data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
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

// Прямий обхід дерева (Вузол -> Ліво -> Право)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%.2lf ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Видалення всього дерева
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Меню користувача
void menu() {
    printf("\n1. Add element\n");
    printf("2. Delete element\n");
    printf("3. Search for element\n");
    printf("4. Print tree (preorder traversal)\n");
    printf("5. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice;
    double value;

    printf("Binary tree with double data type.\n");

    do {
        menu();
        printf("Your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'); // очищення буфера вводу
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter value (double): ");
                if (scanf("%lf", &value) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                if (scanf("%lf", &value) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                if (scanf("%lf", &value) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (search(root, value))
                    printf("Value %.2lf found.\n", value);
                else
                    printf("Value %.2lf not found.\n", value);
                break;
            case 4:
                printf("Tree (preorder traversal): ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                printf("Exiting.\n");
                break;
            default:
                printf("Unknown choice.\n");
        }
    } while (choice != 5);

    return 0;
}
