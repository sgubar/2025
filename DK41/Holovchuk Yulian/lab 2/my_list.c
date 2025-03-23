#include "my_list.h"
#include <stdlib.h>
#include <stdio.h>

// Функція для створення нового вузла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Функція для додавання нового вузла в кінець списку
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Функція для обчислення середнього арифметичного елементів списку
double calculateAverage(Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return 0;
    }
    int sum = 0, count = 0;
    Node* temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return (double)sum / count;
}

// Функція для видалення першого елемента, меншого за середнє арифметичне
void removeFirstBelowAverage(Node** head, double average) {
    if (*head == NULL) {
        printf("The list is empty!\n");
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data < average) {
            printf("Removed first element below average: %d\n", temp->data);
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("No element found below the average!\n");
}

// Функція для виводу списку
void printList(Node* head) {
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Функція для звільнення пам'яті списку
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
