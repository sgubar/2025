#ifndef MY_LIST_H
#define MY_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Оголошення структури вузла списку
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Прототипи функцій
Node* createNode(int data);
void append(Node** head, int data);
void printList(Node* head);
double calculateAverage(Node* head);
void removeFirstBelowAverage(Node** head, double average);
void freeList(Node* head); // Додане оголошення

#endif
