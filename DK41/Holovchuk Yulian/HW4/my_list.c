#include "my_list.h"

// Створення нового вузла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Додавання в кінець
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (!*head) {
        *head = newNode;
        return;
    }
    Node* tail = *head;
    while (tail->next)
        tail = tail->next;

    tail->next = newNode;
    newNode->prev = tail;
}

// Вставка за індексом (0 — початок)
void insertAt(Node** head, int index, int data) {
    if (index < 0) return;

    Node* newNode = createNode(data);
    if (index == 0) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; temp && i < index - 1; i++)
        temp = temp->next;

    if (!temp) return;

    newNode->next = temp->next;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// Видалення за індексом
void removeAt(Node** head, int index) {
    if (!*head || index < 0) return;

    Node* temp = *head;
    for (int i = 0; temp && i < index; i++)
        temp = temp->next;

    if (!temp) return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

// Розмір списку
int listSize(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Вивід списку
void printList(Node* head) {
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Звільнення памʼяті
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
