#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} List;

void initList(List* list);
void addElement(List* list, int value);
int removeElement(List* list, int value);
int insertElementAt(List* list, int index, int value);
int removeElementAt(List* list, int index);
void printList(const List* list);
void clearList(List* list);
int getListSize(const List* list);

#endif
