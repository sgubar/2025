#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int check_brackets(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    Node *stack = NULL;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '(' || ch == '{' || ch == '[') {
            Node *newNode = (Node*)malloc(sizeof(Node));
            if (newNode == NULL) {
                printf("Error memory selection\n");
                fclose(file);
                return 0;
            }
            newNode->bracket = ch;
            newNode->next = stack;
            stack = newNode;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack == NULL) {
                fclose(file);
                return 0; 
            }
            char last = stack->bracket;
            Node *temp = stack;
            stack = stack->next;
            free(temp);
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                fclose(file);
                return 0;
            }
        }
    }
    int balanced = (stack == NULL);
    fclose(file);
    while (stack != NULL) {
        Node *temp = stack;
        stack = stack->next;
        free(temp);
    }
    return balanced;
}
