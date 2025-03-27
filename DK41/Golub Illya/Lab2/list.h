#pragma once

typedef struct listNodeTag {
    double number;
    struct listNodeTag *next;
} ListNode;

typedef struct listTag {
    ListNode *head;
    ListNode *tail;
    unsigned int count;
} List;

List *createList(void);
void destroyList(List *list);
List *getListFromUser(void);
void deleteDuplicates(List *list);
void appendNumberToList(List *list, double number);
void deleteNumberFromList(List *list, unsigned int index);
signed char numberInList(List *list, double number, unsigned int endIndex);
double numberAtIndex(List *list, unsigned int index);
void printList(List *list);