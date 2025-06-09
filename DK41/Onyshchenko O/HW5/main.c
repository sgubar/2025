#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert element\n");
    printf("2. Search for element\n");
    printf("3. Delete element\n");
    printf("4. Print tree\n");
    printf("5. Exit\n");
    printf("Your choice: ");
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted into the tree.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Deletion attempt for %d completed.\n", value);
                break;

            case 4:
                printf("In-order traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                deleteTree(root);
                printf("Memory freed. Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
