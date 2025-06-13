#include <stdio.h>
#include <stdlib.h>

// Структура вузла
typedef struct Node {
    double data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

// Створення нового вузла
Node* createNode(double data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Додавання елемента в кінець списку
void append(double data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next)
        current = current->next;
    current->next = newNode;
    newNode->prev = current;
}

// Вставка елемента за індексом
void insert(double data, int index) {
    if (index < 0) {
        printf("Invalid index!\n");
        return;
    }
    Node* newNode = createNode(data);
    if (index == 0) {
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
        return;
    }
    Node* current = head;
    int i = 0;
    while (current && i < index) {
        current = current->next;
        i++;
    }
    if (!current) {
        append(data); // Якщо індекс більший за розмір списку — додаємо в кінець
        return;
    }
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev)
        current->prev->next = newNode;
    current->prev = newNode;
}

// Видалення елемента за значенням
void delete(double data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;

            free(current);
            printf("Element %.2lf deleted.\n", data);
            return;
        }
        current = current->next;
    }
    printf("Element not found.\n");
}

// Видалення всього списку
void deleteList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("List cleared.\n");
}

// Розмір списку
int size() {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Вивід списку
void display() {
    Node* current = head;
    if (!current) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (current) {
        printf("%.2lf ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Меню користувача
void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Add element\n");
    printf("2. Insert element at index\n");
    printf("3. Delete element by value\n");
    printf("4. Display list\n");
    printf("5. List size\n");
    printf("6. Clear list\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

int main() {
    int choice, index;
    double value;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value (double): ");
                scanf("%lf", &value);
                append(value);
                break;
            case 2:
                printf("Enter value (double): ");
                scanf("%lf", &value);
                printf("Enter index: ");
                scanf("%d", &index);
                insert(value, index);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%lf", &value);
                delete(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("List size: %d\n", size());
                break;
            case 6:
                deleteList();
                break;
            case 0:
                deleteList();
                printf("Program exited.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
