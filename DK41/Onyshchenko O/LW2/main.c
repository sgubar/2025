#include <stdio.h>
#include "limits.h"

int main() {
    Node* head = NULL;
    int n = inputInt("Enter the number of list items: ");

    for (int i = 0; i < n; i++) {
        int value = inputInt("Enter the value of the item: ");
        append(&head, value);
    }

    printf("\nInitial ");
    printList(head);

    sortBeforeMax(&head);

    printf("\nList after sorting before max ");
    printList(head);

    freeList(head);
    return 0;
}
