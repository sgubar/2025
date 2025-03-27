#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    if (!head) {
        printf("The list is empty!\n");
        return;
    }
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node* findMax(Node* head) {
    if (!head) return NULL;
    Node* maxNode = head;
    while (head) {
        if (head->data > maxNode->data)
            maxNode = head;
        head = head->next;
    }
    return maxNode;
}

void sortBeforeMax(Node** head) {
    Node* maxNode = findMax(*head);
    if (!maxNode || maxNode == *head) return;

    Node* start = *head;
    Node* end = maxNode->prev;

    for (Node* i = start->next; i && i != maxNode; i = i->next) {
        int key = i->data;
        Node* j = i->prev;
        while (j && j->data > key && j != maxNode) {
            j->next->data = j->data;
            j = j->prev;
        }
        if (j)
            j->next->data = key;
        else
            start->data = key;
    }
}

int inputInt(const char* prompt) {
    int num;
    char buffer[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Input error! Try again.\n");
            continue;
        }
        if (sscanf(buffer, "%d", &num) == 1)
            return num;
        else
            printf("Invalid format! Please enter an integer.\n");
    }
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
