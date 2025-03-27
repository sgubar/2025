#include <stdio.h>
#include "list.h"

int main(void) {
    List *l = getListFromUser();
    printf("Before clear:\n");
    printList(l);
    printf("\nAfter clear:\n");

    deleteDuplicates(l);

    printList(l);
    printf("\n");

    destroyList(l);

    return 0;
}