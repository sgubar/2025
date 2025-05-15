#ifndef DEREVA_H
#define DEREVA_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value);
Node* insert(Node* root, int value);
Node* delete_node(Node* root, int value);
Node* search(Node* root, int value);
void preorder_print(Node* root);
void free_tree(Node* root);

#endif
