#include <stdio.h>
#include <stdlib.h>
#include "dereva.h"

int get_int_input(const char* prompt) {
    int value;
    char term;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &term) != 2 || term != '\n') {
            printf("Enter an integer number\n");
            while (getchar() != '\n');
        } else {
            return value;
        }
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Find element\n");
        printf("4. Display tree\n");
        printf("5. Clear tree\n");
        printf("6. Exit\n");

        choice = get_int_input("Select options: ");

        switch (choice) {
            case 1:
                value = get_int_input("Enter an integer for add: ");
                root = insert(root, value);
                break;
            case 2:
                value = get_int_input("Enter an integer for delete: ");
                root = delete_node(root, value);
                break;
            case 3:
                value = get_int_input("Enter an integer for search: ");
                if (search(root, value))
                    printf("Element %d is found.\n", value);
                else
                    printf("Element %d is not found.\n", value);
                break;
            case 4:
                printf("Straight bypass: ");
                preorder_print(root);
                printf("\n");
                break;
            case 5:
                free_tree(root);
                root = NULL;
                printf("Tree is clear.\n");
                break;
            case 6:
                free_tree(root);
                printf("\n");
                return 0;
            default:
                printf("Incorrect number. Try again.\n");
        }
    }
    return 0;
}
