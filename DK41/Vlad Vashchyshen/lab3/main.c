#include <stdio.h>
#include <stdlib.h>

// Структура вузла дерева
typedef struct Node {
    float data;
    struct Node* left;
    struct Node* right;
} Node;

// Створення нового вузла
Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Вставка елемента
Node* insert(Node* root, float value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Значення %.2f вже є в дереві.\n", value);
    return root;
}

// Симетричний (in-order) обхід дерева
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%.2f ", root->data);
        inOrder(root->right);
    }
}

// Пошук елемента
Node* search(Node* root, float value) {
    if (root == NULL || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Мінімальне значення в піддереві
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Видалення елемента
Node* deleteNode(Node* root, float value) {
    if (root == NULL)
        return NULL;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Один або жодного нащадка
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Два нащадки
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Видалення всього дерева
void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Безпечне введення числа типу float
float inputFloat() {
    float value;
    char buffer[100];
    while (1) {
        printf("Введіть число типу float: ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Помилка введення. Спробуйте ще раз.\n");
            continue;
        }
        if (sscanf(buffer, "%f", &value) == 1) {
            return value;
        } else {
            printf("Некоректне значення! Спробуйте знову.\n");
        }
    }
}

// Меню користувача
void menu() {
    printf("\nМеню:\n");
    printf("1. Додати елемент\n");
    printf("2. Видалити елемент\n");
    printf("3. Пошук елемента\n");
    printf("4. Симетричний обхід дерева\n");
    printf("5. Видалити все дерево\n");
    printf("0. Вихід\n");
    printf("Ваш вибір: ");
}

int main() {
    Node* root = NULL;
    int choice;
    float value;

    do {
        menu();
        scanf("%d", &choice);
        while(getchar() != '\n'); // Очистити буфер

        switch (choice) {
            case 1:
                value = inputFloat();
                root = insert(root, value);
                break;
            case 2:
                value = inputFloat();
                root = deleteNode(root, value);
                break;
            case 3:
                value = inputFloat();
                if (search(root, value))
                    printf("Значення %.2f знайдено в дереві.\n", value);
                else
                    printf("Значення %.2f не знайдено.\n", value);
                break;
            case 4:
                printf("Симетричний обхід: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                root = NULL;
                printf("Дерево успішно видалено.\n");
                break;
            case 0:
                deleteTree(root);
                printf("Завершення програми.\n");
                break;
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}

