#include <stdio.h>
#include "list.h"

int getValidInt(const char* prompt, int min) {
    int value;
    char c;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1 || value < min) {
            printf("Помилка! Введіть ціле число ≥ %d.\n", min);
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    }
    return value;
}

int main() {
    printf("=== Робота з кільцевим списком ===\n");

    int n = getValidInt("Введіть кількість елементів у списку (≥ 3): ", 3);

    Node* head = createCircularList(n);
    printList(head);

    deleteEachThird(&head);

    freeList(head);

    printf("Залишилось менше трьох елементів. Програма завершена.\n");

    return 0;
}
