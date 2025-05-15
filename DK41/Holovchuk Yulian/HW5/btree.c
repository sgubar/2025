#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int value) {
    if (!root) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

Node* search(Node* root, int value) {
    if (!root || root->value == value)
        return root;
    return value < root->value
        ? search(root->left, value)
        : search(root->right, value);
}

Node* findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int value) {
    if (!root) return NULL;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* minRight = findMin(root->right);
        root->value = minRight->value;
        root->right = deleteNode(root->right, minRight->value);
    }

    return root;
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
