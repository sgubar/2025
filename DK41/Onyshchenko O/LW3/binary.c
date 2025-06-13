#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, double value) {
    if (root == NULL) return createNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

void reverseInOrder(Node* root) {
    if (root) {
        reverseInOrder(root->right);
        printf("%.2lf ", root->value);
        reverseInOrder(root->left);
    }
}

Node* search(Node* root, double value) {
    if (!root || root->value == value) return root;
    if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, double value) {
    if (!root) return root;
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
        } else {
            Node* temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    return root;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
