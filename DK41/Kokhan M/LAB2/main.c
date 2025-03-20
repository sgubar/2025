#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    Node* list;
    int choice, value, target;

    init_list(&list);

    do {
        printf("\nMenu:\n");
        printf("1. Add an element to the list\n");
        printf("2. Print the list\n");
        printf("3. Reverse elements between the first and last occurrence of a given element\n");
        printf("4. Exit\n");
        printf("Select an action (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(choice) {
            case 1:
                printf("Enter a number to add to the list: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid value! Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                add_to_list(&list, value);
                printf("Number %d added to the list.\n", value);
                break;

            case 2:
                printf("List: ");
                print_list(list);
                break;

            case 3:
                printf("Enter a number to reverse elements between its first and last occurrence: ");
                if (scanf("%d", &target) != 1) {
                    printf("Invalid value! Please enter an integer.\n");
                    while(getchar() != '\n');
                    break;
                }
                if (reverse_between(&list, target)) {
                    printf("Elements between the first and last occurrence of %d have been reversed.\n", target);
                } else {
                    printf("Number %d does not appear in the list or appears less than twice.\n", target);
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                free_list(list);
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while(choice != 4);

    return 0;
}
