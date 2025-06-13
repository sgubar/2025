#ifndef BINARY_H
#define BINARY_H

typedef struct Node {
    double value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(double value);
Node* insert(Node* root, double value);
Node* search(Node* root, double value);
Node* deleteNode(Node* root, double value);
void deleteTree(Node* root);
void reverseInOrder(Node* root);

#endif
