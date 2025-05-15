#include <stdio.h>
#include <stdlib.h>

// Структура вузла двозв’язного списку
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Функція для створення нового вузла
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Функція для додавання елемента у кінець списку
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Функція для виведення списку у прямому порядку
void printForward(Node* head) {
    Node* temp = head;
    printf("Список у прямому порядку: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Функція для виведення списку у зворотному порядку
void printBackward(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Список у зворотному порядку: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Функція для перевірки коректного введення числа
int inputNumber() {
    int num;
    while (1) {
        printf("Введіть ціле число: ");
        if (scanf("%d", &num) == 1) {
            return num;
        } else {
            printf("Помилка! Введіть коректне число.\n");
            while (getchar() != '\n'); // Очищення буфера введення
        }
    }
}

// Основна функція програми
int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\nМеню:\n");
        printf("1 - Додати елемент\n");
        printf("2 - Вивести список у прямому та зворотному порядку\n");
        printf("3 - Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                value = inputNumber();
                append(&head, value);
                break;
            case 2:
                printForward(head);
                printForward(head);
                printBackward(head);
                printBackward(head);
                break;
            case 3:
                printf("Вихід з програми.\n");
                return 0;
            default:
                printf("Некоректний вибір! Спробуйте ще раз.\n");
        }
    }

    return 0;
}
