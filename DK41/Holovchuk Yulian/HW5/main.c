#include <stdio.h>
#include "btree.h"

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Print (pre-order)\n5. Delete tree\n0. Exit\n> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                printf(search(root, value) ? "Found.\n" : "Not found.\n");
                break;
            case 4:
                printf("Pre-order: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;
            case 0:
                deleteTree(root);
                printf("Bye.\n");
                break;
            default:
                printf("Invalid.\n");
        }
    } while (choice != 0);

    return 0;
}
