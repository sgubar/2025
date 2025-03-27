#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int getIntInput(const char* prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            return value;
        } else {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear the buffer
        }
    }
}

int main() {
    List* myList = createTwoSidedMallocList();
    if (myList == NULL) {
        fprintf(stderr, "Failed to create list. Exiting.\n");
        return 1;
    }

    int numElements = getIntInput("Enter the number of elements you want to add to the list: ");

    // Додаємо елементи в список
    for (int i = 0; i < numElements; i++) {
        int data = getIntInput("Enter a number to append to the list: ");
        append(myList, data);
    }

    printf("Started list:\n");
    printList(myList);

    int elementToDouble = getIntInput("Enter the element to double: ");

    doubleElement(myList, elementToDouble);

    printf("\nList after doubling occurrences of %d:\n", elementToDouble);
    printList(myList);

    freeList(myList);

    return 0;
}
