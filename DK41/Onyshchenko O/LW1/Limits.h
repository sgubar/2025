#ifndef LIMITS_H
#define LIMITS_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void append(Node** head, int data);
void printList(Node* head);
Node* findMax(Node* head);
void sortBeforeMax(Node** head);
void freeList(Node* head);
int inputInt(const char* prompt);

#endif
