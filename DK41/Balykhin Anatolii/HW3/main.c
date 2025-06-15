#include <stdio.h>
#include <stdlib.h>
#include "struc.h"

void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu() {
    printf("\n MENU \n");
    printf("1. Add a new rectangle\n");
    printf("2. Insert/replace rectangle by index\n");
    printf("3. Delete rectangle by index\n");
    printf("4. Display array\n");
    printf("0. Exit\n");
    printf("Selection: ");
}

int main() {
    int capacity;
    printf("Enter the desired array capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Incorrect capacity. Exit.\n");
        return 1;
    }
    clear_stdin();

    Array* rect_array = create_array(capacity);
    if (!rect_array) {
        printf("Failed to create array. Exit.\n");
        return 1;
    }
    printf("Array with capacity %d successfully created.\n", capacity);

    int choice;

    do {
        print_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number.\n");
            clear_stdin();
            choice = -1;
            continue;
        }
        clear_stdin();
        switch (choice) {
            case 1: {
                printf("\n Adding a new rectangle \n");
                Rectangle* new_rect = create_rectangle();
                if (new_rect) {
                    int index = add_element(rect_array, new_rect);
                    if (index != -1) {
                        printf("Rectangle added successfully at index %d.\n", index);
                    } else {
                        delete_rectangle(new_rect);
                    }
                }
                break;
            }
            case 2: {
                printf("\n Insert/replace by index \n");
                printf("Enter the index: ", capacity - 1);
                int index;
                scanf("%d", &index);
                clear_stdin();

                Rectangle* new_rect = create_rectangle();
                if (new_rect) {
                    if (insert_element_at(rect_array, new_rect, index) != -1) {
                        printf("Operation for index %d completed.\n", index);
                    } else {
                        delete_rectangle(new_rect);
                    }
                }
                break;
            }
            case 3: {
                printf("\nDelete by index\n");
                printf("Enter the index of the element to delete: ", capacity - 1);
                int index;
                scanf("%d", &index);
                clear_stdin();

                if (delete_element_at(rect_array, index) == 0) {
                    printf("The element with index %d has been deleted.\n", index);
                }
                break;
            }
            case 4: {
                print_array(rect_array);
                break;
            }
            case 0: {
                printf("Exit.\n");
                break;
            }
            default: {
                printf("Error: Unknown option ‘%d’.\n", choice);
                break;
            }
        }
    } while (choice != 0);

    delete_array(rect_array);
    printf("All memory cleared\n");
    return 0;
}
