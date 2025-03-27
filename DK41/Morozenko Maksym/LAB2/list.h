#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct List {
    Node* head;
    Node* tail;
} List;

List* createTwoSidedMallocList();
void append(List* list, int data);
void printList(List* list);
void freeList(List* list);
void doubleElement(List* list, int element);

#endif // LIST_H
