#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
Node* createCircularList(int n);
void printList(Node* head);
void deleteEachThird(Node** headRef);
void freeList(Node* head);

#endif
