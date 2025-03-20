#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* createTwoSidedMallocList() {
    List* newList = (List*)malloc(sizeof(List));
    if (newList == NULL) {
        fprintf(stderr, "Malloc error!\n");
        return NULL;
    }

    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void append(List* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Append error\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(List* list) {
    if (list->head == NULL) {
        printf("Empty list.\n");
        return;
    }

    Node* current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(List* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list);
}

void doubleElement(List* list, int element) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == element) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                fprintf(stderr, "Double el error\n");
                return;
            }
            
            newNode->data = element;
            newNode->next = current->next;
            newNode->prev = current;

            if (current->next != NULL) {
                current->next->prev = newNode;
            } else {
                list->tail = newNode;
            }
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
    }
}
