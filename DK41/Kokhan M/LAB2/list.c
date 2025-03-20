#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(Node** head) {
    *head = NULL;
}

void add_to_list(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
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

int reverse_between(Node** head, int target) {
    Node* first = NULL;
    Node* last = NULL;
    Node* current = *head;
    int first_index = -1;
    int last_index = -1;
    int index = 0;

    while (current != NULL) {
        if (current->data == target) {
            if (first == NULL) {
                first = current;
                first_index = index;
            }
            last = current;
            last_index = index;
        }
        current = current->next;
        index++;
    }

    if (first == NULL || first == last) { 
        return 0;
    }

    int count_between = last_index - first_index - 1;
    if (count_between <= 0) {
        return 1; // 
    }

    int* data_to_reverse = (int*)malloc(sizeof(int) * count_between);
    if (data_to_reverse == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    current = *head;
    int current_index = 0;
    int data_index = 0;
    while (current != NULL && current_index <= last_index) {
        if (current_index > first_index && current_index < last_index) {
            data_to_reverse[data_index++] = current->data;
        }
        current = current->next;
        current_index++;
    }

    for (int i = 0; i < count_between / 2; i++) {
        int temp = data_to_reverse[i];
        data_to_reverse[i] = data_to_reverse[count_between - 1 - i];
        data_to_reverse[count_between - 1 - i] = temp;
    }

    current = *head;
    current_index = 0;
    data_index = 0;
    while (current != NULL && current_index <= last_index) {
        if (current_index > first_index && current_index < last_index) {
            current->data = data_to_reverse[data_index++];
        }
        current = current->next;
        current_index++;
    }

    free(data_to_reverse);
    return 1;
}

void free_list(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
