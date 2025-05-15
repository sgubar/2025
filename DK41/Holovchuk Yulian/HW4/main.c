#include "my_list.h"

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    insertAt(&head, 1, 15);  // [10, 15, 20, 30]
    printList(head);

    removeAt(&head, 2);      // [10, 15, 30]
    printList(head);

    printf("Size: %d\n", listSize(head));

    freeList(head);
    return 0;
}
