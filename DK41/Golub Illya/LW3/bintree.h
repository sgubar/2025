#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Оголошення структури для вузла бінарного дерева
typedef struct Node {
    float data;           // Дані, що зберігаються у вузлі (число з рухомою комою)
    struct Node* left;    // Вказівник на лівий дочірній вузол
    struct Node* right;   // Вказівник на правий дочірній вузол
} Node;

Node* createNode(float data);

// Вставляє новий елемент у бінарне дерево пошуку
Node* insert(Node* root, float data);

// Виконує зворотній обхід дерева (Right-Root-Left) та виводить значення вузлів
void reverseInorder(Node* root);

// Шукає вузол із заданим значенням у дереві
Node* search(Node* root, float data);

// Знаходить вузол з мінімальним значенням у піддереві (використовується при видаленні)
Node* minValueNode(Node* node);

// Видаляє вузол із заданим значенням з бінарного дерева пошуку
Node* deleteNode(Node* root, float data);

// Рекурсивно видаляє все дерево, звільняючи пам'ять
void deleteTree(Node* root);

// Допоміжна функція для безпечного зчитування числа з рухомою комою
bool getFloat(float* value);