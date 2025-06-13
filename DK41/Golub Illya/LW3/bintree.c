#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Функція для створення нового вузла дерева
Node* createNode(float data) {
    // Виділяємо пам'ять для нового вузла
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Помилка виділення пам'яті для нового вузла!\n");
        exit(EXIT_FAILURE);
    }
    // Ініціалізація даних нового вузла
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    // Повертаємо вказівник на створений вузол
    return newNode;
}

// Функція для вставки нового елемента в бінарне дерево пошуку
Node* insert(Node* root, float data) {
    // Якщо дерево порожнє, створюється новий вузол, який стає коренем
    if (root == NULL) {
        return createNode(data);
    }
    // Якщо значення, що вставляється, менше значення поточного вузла,
    // рекурсивно вставляємо його в ліве піддерево
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // Якщо значення, що вставляється, більше значення поточного вузла,
    // рекурсивно вставляємо його в праве піддерево
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // Якщо значення вже існує в дереві, нічого не робимо 
    // Повертаємо вказівник на корінь
    return root;
}

// Функція для зворотнього обходу дерева (Right-Root-Left) та виведення значень
void reverseInorder(Node* root) {
    if (root != NULL) {
        // Рекурсивно обходимо праве піддерево
        reverseInorder(root->right);
        // Виводимо значення поточного вузла (кореня піддерева)
        printf("%.2f ", root->data);
        // Рекурсивно обходимо ліве піддерево
        reverseInorder(root->left);
    }
}

// Функція для пошуку вузла із заданим значенням у дереві
Node* search(Node* root, float data) {
    // Якщо корінь порожній або значення знайдено в поточному вузлі
    if (root == NULL || root->data == data) {
        return root; // Повертаємо поточний вузол
    }
    // Якщо шукане значення менше значення поточного вузла,
    // рекурсивно шукаємо в лівому піддереві
    if (data < root->data) {
        return search(root->left, data);
    }
    // Інакше рекурсивно шукаємо в правому піддереві
    return search(root->right, data);
}

// Функція для знаходження вузла з мінімальним значенням у заданому піддереві
Node* minValueNode(Node* node) {
    Node* current = node;
    // Мінімальне значення завжди знаходиться в крайньому лівому вузлі
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Функція для видалення вузла із заданим значенням з бінарного дерева пошуку
Node* deleteNode(Node* root, float data) {
    if (root == NULL) {
        return root;
    }

    // Якщо значення, що видаляється, менше значення кореня,
    // рекурсивно видаляємо з лівого піддерева
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // Якщо значення, що видаляється, більше значення кореня,
    // рекурсивно видаляємо з правого піддерева
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Випадок 1: Вузол не має дочірніх елементів або має лише один
        if (root->left == NULL) { // Немає лівого дочірнього
            Node* temp = root->right; // Зберігаємо правий
            free(root);             // Звільняємо пам'ять поточного вузла
            return temp;            // Повертаємо правий дочірній як новий корінь цього піддерева
        } else if (root->right == NULL) { // Немає правого дочірнього
            Node* temp = root->left;  // Зберігаємо лівий
            free(root);               // Звільняємо пам'ять
            return temp;              // Повертаємо лівий дочірній
        }

        // Випадок 2: Вузол має два дочірні елементи
        // Знаходимо наступника (найменший елемент у правому піддереві)
        Node* temp = minValueNode(root->right);
        // Копіюємо дані наступника в поточний вузол
        root->data = temp->data;
        // Рекурсивно видаляємо наступника з правого піддерева
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Функція для рекурсивного видалення всього дерева та звільнення пам'яті
void deleteTree(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// Допоміжна функція для безпечного зчитування числа
bool getFloat(float* value) {
    char buffer[100]; // Буфер для зчитування рядка
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return false;
    }
    // Намагаємося конвертувати рядок у float.
    // sscanf повертає кількість успішно присвоєних елементів.
    if (sscanf(buffer, "%f", value) == 1) {
        // Перевіряємо, чи немає зайвих символів після числа
        char check;
        if (sscanf(buffer, "%f %c", value, &check) == 1) {
             return true;
        }
    }
    return false;
}
