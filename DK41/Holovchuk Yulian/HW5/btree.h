#ifndef BTREE_H
#define BTREE_H

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value);
Node* insert(Node* root, int value);
Node* search(Node* root, int value);
Node* deleteNode(Node* root, int value);
void deleteTree(Node* root);
void preorder(Node* root);

#endif
