#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення пам’яті!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createCircularList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = createNode(i);
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
    tail->next = head; // робимо список кільцевим
    return head;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    printf("Список: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

void deleteEachThird(Node** headRef) {
    if (!(*headRef)) return;
    Node* current = *headRef;
    Node* prev = NULL;
    int count = 0;

    int total = 0;
    Node* temp = *headRef;
    do {
        total++;
        temp = temp->next;
    } while (temp != *headRef);

    while (total >= 3) {
        count = 1;
        while (count < 3) {
            prev = current;
            current = current->next;
            count++;
        }
        printf("Видалення: %d\n", current->data);
        prev->next = current->next;
        if (current == *headRef) {
            *headRef = current->next;
        }
        free(current);
        current = prev->next;
        total--;

        printList(*headRef);
    }
}

void freeList(Node* head) {
    if (!head) return;
    Node* temp = head;
    Node* next;
    do {
        next = temp->next;
        free(temp);
        temp = next;
    } while (temp != head);
}
