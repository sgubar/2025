#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data);
void append(Node** head, int data);
void insertAt(Node** head, int index, int data);
void removeAt(Node** head, int index);
void printList(Node* head);
void freeList(Node* head);
int listSize(Node* head);

#endif
