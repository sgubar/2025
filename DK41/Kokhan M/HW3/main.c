#include <stdio.h>
#include "dztree.h"

int main() {
    TreeNode* root = NULL;

    printf("--- Creating and inserting elements ---\n");
    root = insertNode(root, 50.5);
    root = insertNode(root, 30.2);
    root = insertNode(root, 20.0);
    root = insertNode(root, 40.8);
    root = insertNode(root, 70.1);
    root = insertNode(root, 60.6);
    root = insertNode(root, 80.3);
    root = insertNode(root, 35.5);

    printf("Tree after insertion (in-order): ");
    printInOrder(root);
    printf("\n\n");

    printf("--- Searching for elements ---\n");
    double searchValue = 40.8;
    TreeNode* foundNode = searchNode(root, searchValue);
    if (foundNode != NULL) {
        printf("Element %.2f found in the tree.\n", searchValue);
    } else {
        printf("Element %.2f NOT found in the tree.\n", searchValue);
    }

    searchValue = 99.9;
    foundNode = searchNode(root, searchValue);
    if (foundNode != NULL) {
        printf("Element %.2f found in the tree.\n", searchValue);
    } else {
        printf("Element %.2f NOT found in the tree.\n", searchValue);
    }
    printf("\n");

    printf("--- Deleting elements ---\n");

    printf("Deleting leaf node 20.0\n");
    root = deleteNode(root, 20.0);
    printf("Tree after deleting 20.0: ");
    printInOrder(root);
    printf("\n");

    printf("Deleting node 30.2 (has one right child 40.8)\n");
    root = deleteNode(root, 30.2);
    printf("Tree after deleting 30.2: ");
    printInOrder(root);
    printf("\n");

    printf("Deleting root node 50.5 (has two children)\n");
    root = deleteNode(root, 50.5);
    printf("Tree after deleting 50.5: ");
    printInOrder(root);
    printf("\n\n");

    printf("--- Deleting the entire tree ---\n");
    deleteTree(root);
    root = NULL;
    printf("Tree deleted.\n");

    printf("Attempting to print empty tree: ");
    printInOrder(root);
    printf("[end of empty tree printout]\n");

    return 0;
}
