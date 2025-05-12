#ifndef LABTREE_H
#define LABTREE_H

#include <stdlib.h>
#include <stdio.h>
typedef struct TreeNode {
    double data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(double data);
TreeNode* insertNode(TreeNode* root, double data);

TreeNode* deleteNode(TreeNode* root, double data);
TreeNode* searchNode(TreeNode* root, double data);
void deleteTree(TreeNode* root);
void printInOrder(TreeNode* root);

#endif
