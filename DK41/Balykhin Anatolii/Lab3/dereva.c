#include <stdio.h>
#include <stdlib.h>
#include "dereva.h"

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Error memory selection.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return create_node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* search(Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

Node* find_min(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

Node* delete_node(Node* root, int value) {
    if (root == NULL) return NULL;

    if (value < root->data)
        root->left = delete_node(root->left, value);
    else if (value > root->data)
        root->right = delete_node(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void preorder_print(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_print(root->left);
        preorder_print(root->right);
    }
}

void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}
