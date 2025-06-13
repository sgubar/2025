#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

// Safe input for double
int safeDoubleInput(double* outValue) {
    char buffer[100];
    char* end;
    if (!fgets(buffer, sizeof(buffer), stdin)) return 0;
    *outValue = strtod(buffer, &end);
    if (end == buffer || (*end != '\n' && *end != '\0')) {
        return 0;
    }
    return 1;
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Insert element\n");
    printf("2. Delete element\n");
    printf("3. Search element\n");
    printf("4. Print tree\n");
    printf("5. Delete entire tree\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Node* root = NULL;
    int choice;
    double value;

    do {
        menu();
        if (scanf("%d", &choice) != 1) {
            printf("Input error! Please enter an integer.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // remove newline character

        switch (choice) {
            case 1:
                printf("Enter a double value to insert: ");
                if (safeDoubleInput(&value))
                    root = insert(root, value);
                else
                    printf("Invalid number format!\n");
                break;

            case 2:
                printf("Enter a double value to delete: ");
                if (safeDoubleInput(&value))
                    root = deleteNode(root, value);
                else
                    printf("Invalid number format!\n");
                break;

            case 3:
                printf("Enter a double value to search: ");
                if (safeDoubleInput(&value)) {
                    Node* found = search(root, value);
                    if (found)
                        printf("Value %.2lf found in the tree.\n", value);
                    else
                        printf("Value %.2lf not found in the tree.\n", value);
                } else {
                    printf("Invalid number format!\n");
                }
                break;

            case 4:
                printf("Reverse in-order traversal:\n");
                reverseInOrder(root);
                printf("\n");
                break;

            case 5:
                deleteTree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;

            case 0:
                deleteTree(root);
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
