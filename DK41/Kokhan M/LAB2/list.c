#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(Node** head) {
    *head = NULL;
}

void add_to_list(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int reverse_between(Node* head, int target) {
    Node* first = NULL;
    Node* last = NULL;
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (current->data == target) {
            if (first == NULL) {
                first = current;
            }
            last = current;
            count++;
        }
        current = current->next;
    }

    if (count < 2) {
        return 0;
    }
    Node* prev = NULL;
    Node* next = NULL;
    current = first->next;
    while (current != last) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    first->next = last;
    if (prev != NULL) {
        first->next = prev;
    }

    return 1;
}

// Function to free the memory used by the list
void free_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
