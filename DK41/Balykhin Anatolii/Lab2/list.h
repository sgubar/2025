#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node {
    char bracket;
    struct Node *next;
} Node;

int check_brackets(const char *filename);

#endif
