#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void init_list(Node** head);
void add_to_list(Node** head, int value);
void print_list(Node* head);
int reverse_between(Node* head, int target);
void free_list(Node* head);

#endif
