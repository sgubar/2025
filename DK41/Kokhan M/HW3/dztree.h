#ifndef DZTREE_H
#define DZTREE_H

#include <stdio.h>
#include <stdlib.h>

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
TreeNode* minValueNode(TreeNode* node);

#endif
