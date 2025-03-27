#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

List *createList(void) {
    List *result = (List *) malloc(sizeof(List));
    if (result != NULL) {
        result->count = 0;
        result->head = NULL;
        result->tail = NULL;
    }
    return result;
}

void destroyList(List *list) {
    if (list == NULL) return;

    ListNode *node = list->head;
    while (node != NULL) {
        ListNode *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

List *getListFromUser(void) {
    List *result = createList();
    if (result != NULL) {
        char input[256];
        printf("Enter numbers separated by spaces and press enter to finish:\n");
        fgets(input, sizeof(input), stdin);
        char *token = strtok(input, " ");
        while (token != NULL) {
            double number;
            if (sscanf(token, "%lf", &number) == 1) {
                appendNumberToList(result, number);
            }
            token = strtok(NULL, " ");
        }
    }
    return result;
}

void deleteDuplicates(List *list) {
    if (list == NULL) return;

    for (unsigned int i = 0; i < list->count; i++) {
        if (numberInList(list, numberAtIndex(list, i), i)) {
            deleteNumberFromList(list, i);
            i--;
        }
    }
}

void appendNumberToList(List *list, double number) {
    if (list == NULL) return;

    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    if (node == NULL) return;

    node->number = number;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
}

void deleteNumberFromList(List *list, unsigned int index) {
    if (list == NULL) return;

    ListNode *previous = NULL, *current = list->head;
    for (unsigned int i = 0; current != NULL && i != index; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == list->tail) {
        list->tail = previous;
    }

    free(current);
    list->count--;
}

signed char numberInList(List *list, double number, unsigned int endIndex) {
    if (list == NULL) return -1;

    ListNode *node = list->head;
    for (unsigned int i = 0; node != NULL && i != endIndex; i++) {
        if (node->number == number) return 1;
        node = node->next;
    }
    return 0;
}

double numberAtIndex(List *list, unsigned int index) {
    if (list == NULL || index >= list->count) return 0;

    ListNode *node = list->head;
    for (unsigned int i = 0; node != NULL && i != index; i++) {
        node = node->next;
    }
    return node->number;
}

void printList(List *list) {
    if (list == NULL) {
        printf("ERROR");
        return;
    }

    if (list->head == NULL) {
        printf("(empty)");
        return;
    }

    ListNode *node = list->head;
    printf("%lf", node->number);
    node = node->next;

    while (node != NULL) {
        printf(" -> %lf", node->number);
        node = node->next;
    }
}
