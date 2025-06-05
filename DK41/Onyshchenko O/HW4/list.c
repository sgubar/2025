#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initList(List* list) {
    list->head = NULL;
    list->size = 0;
}

void addElement(List* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

int removeElement(List* list, int value) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current) {
        if (current->data == value) {
            if (prev == NULL)
                list->head = current->next;
            else
                prev->next = current->next;
            free(current);
            list->size--;
            return 1; // успішно
        }
        prev = current;
        current = current->next;
    }
    return 0; // не знайдено
}

int insertElementAt(List* list, int index, int value) {
    if (index < 0 || index > list->size)
        return 0;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return 0;
    newNode->data = value;
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
    return 1;
}

int removeElementAt(List* list, int index) {
    if (index < 0 || index >= list->size)
        return 0;
    Node* current = list->head;
    Node* prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
        list->head = current->next;
    else
        prev->next = current->next;

    free(current);
    list->size--;
    return 1;
}

void printList(const List* list) {
    Node* current = list->head;
    printf("List: ");
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void clearList(List* list) {
    Node* current = list->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->size = 0;
}

int getListSize(const List* list) {
    return list->size;
}
