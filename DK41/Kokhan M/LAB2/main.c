#include "list.h"
#include <stdio.h>

int main() {
    List* myList = createTwoSidedMallocList();

    if (myList == NULL) {
        fprintf(stderr, "Failed to create list. Exiting.\n");
        return 1;
    }

    append(myList, 1);
    append(myList, 2);
    append(myList, 3);
    append(myList, 2);
    append(myList, 9);
    append(myList, 2);
    append(myList, 5);

    printf("Started list:\n");
    printList(myList);

    int elementToDouble = 9;

    doubleElement(myList, elementToDouble);

    printf("\nList after doudle %d:\n", elementToDouble);
    printList(myList);

    freeList(myList);

    return 0;
}
