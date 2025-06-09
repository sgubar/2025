#ifndef BINARY_H
#define BINARY_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
Node* search(Node* root, int value);
Node* deleteNode(Node* root, int value);
void inorder(Node* root);
void deleteTree(Node* root);

#endif
