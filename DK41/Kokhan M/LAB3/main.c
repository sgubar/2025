#include "labtree.h"
#include <stdio.h>

int main() {
    TreeNode* root = NULL;

    printf("Inserting: 50.5, 30.3, 70.7, 20.2, 40.4, 60.6, 80.8, 40.4\n");
    root = insertNode(root, 50.5);
    root = insertNode(root, 30.3);
    root = insertNode(root, 70.7);
    root = insertNode(root, 20.2);
    root = insertNode(root, 40.4);
    root = insertNode(root, 60.6);
    root = insertNode(root, 80.8);
    root = insertNode(root, 40.4);

    printf("\nIn-order traversal (Symmetric): ");
    printInOrder(root);
    printf("\n");

    double val1 = 40.4;
    printf("\nSearching for %.2f: ", val1);
    if (searchNode(root, val1) != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    double val2 = 99.9;
    printf("Searching for %.2f: ", val2);
    if (searchNode(root, val2) != NULL) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    printf("\nTry to delete 20.2 (leaf node)\n");
    root = deleteNode(root, 20.2);
    printf("Order after deleting 20.2: ");
    printInOrder(root);
    printf("\n");

    printf("\nTry to delete 70.7 (node with one child)\n");
    root = deleteNode(root, 70.7);
    printf("Order after deleting 70.7: ");
    printInOrder(root);
    printf("\n");

    printf("\nTry to delete 50.5 (root node with two children)\n");
    root = deleteNode(root, 50.5);
    printf("In-order traversal after deleting 50.5: ");
    printInOrder(root);
    printf("\n");

    printf("\nTry to delete 99.9 (non-existent node)\n");
    root = deleteNode(root, 99.9);
    printf("Root after deleting 99.9: ");
    printInOrder(root);
    printf("\n");
    
    printf("\nDeleting 40.4 (one of the duplicates)\n");
    root = deleteNode(root, 40.4);
    printf("Root after deleting 40.4: ");
    printInOrder(root);
    printf("\n");

    printf("\nDeleting the entire tree...\n");
    deleteTree(root);
    root = NULL;

    printf("Deleted tree test.: ");
    printInOrder(root);
    printf("\n");
    return 0;
}
