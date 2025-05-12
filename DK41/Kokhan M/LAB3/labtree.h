#include "labtree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* createNode(double data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        perror("Error allocating memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, double data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

static TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode* deleteNode(TreeNode* root, double data) {

    if (root == NULL) {
        return root;
    }

    // Рекурсивно шукаємо вузол для видалення
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // Якщо дані == root->data, це вузол, який потрібно видалити
    else {
        // Випадок 1: Вузол без нащадків або з одним нащадком
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root); // Звільняємо пам'ять поточного вузла
            return temp; // Повертаємо правого нащадка (або NULL, якщо його немає)
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root); // Звільняємо пам'ять поточного вузла
            return temp; // Повертаємо лівого нащадка
        }

        // Випадок 2: Вузол з двома нащадками
        // Знаходимо найменший вузол у правому піддереві (inorder successor)
        TreeNode* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

TreeNode* searchNode(TreeNode* root, double data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    }

    return searchNode(root->right, data);
}

void deleteTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        // Вивід даних поточного вузла
        printf("%.2f ", root->data);
        printInOrder(root->right);
    }
}
