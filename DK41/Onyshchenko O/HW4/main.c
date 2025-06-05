#include <stdio.h>
#include "list.h"

int main() {
    List myList;
    initList(&myList);
    addElement(&myList, 10);
    addElement(&myList, 20);
    addElement(&myList, 30);
    printList(&myList);
    insertElementAt(&myList, 1, 15);
    printList(&myList);
    removeElement(&myList, 20);
    printList(&myList);
    removeElementAt(&myList, 0);
    printList(&myList);
    printf("List size: %d\n", getListSize(&myList));
    clearList(&myList);
    return 0;
}
