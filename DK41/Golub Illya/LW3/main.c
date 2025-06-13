#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

// Функція для перевірки, чи дерево порожнє
bool isTreeEmpty(Node* root) {
    if (root == NULL) { // Якщо корінь дерева NULL, то дерево порожнє
        printf("Дерево порожнє.\n");
        return true; 
    }
    return false;
}

// Функція для введення числа з рухомою комою від користувача
bool inputFloatValue(float* value, const char* prompt) {
    printf("%s", prompt);
    if (!getFloat(value)) { // Викликаємо функцію getFloat для зчитування та перевірки числа
        printf("Некоректне введення. Введіть дійсне число.\n");
        // Очищаємо буфер вводу, щоб уникнути проблем з наступними scanf
        char c;
        while ((c = getchar()) != '\n' && c != EOF);
        return false;
    }
    return true;
}

// Функція для очищення буфера вводу, треба після scanf
void clearInputBuffer() {
    int c;
    // Зчитуємо символи з буфера, поки не зустрінемо символ нового рядка або кінець файлу
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Node* root = NULL; // Вказівник на корінь бінарного дерева
    int choice;
    float value;

    do {
        printf("\n--- Операції з бінарним деревом ---\n");
        printf("1. Створити нове дерево (видаляє існуюче)\n");
        printf("2. Вставити елемент\n");
        printf("3. Видалити елемент\n");
        printf("4. Пошук елемента\n");
        printf("5. Вивести дерево (зворотній обхід: Праве-Корінь-Ліве)\n");
        printf("6. Видалити все дерево\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("Некоректне введення. Введіть число від 0 до 6.\n");
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: // Створити нове дерево
                deleteTree(root);
                root = NULL;
                printf("Нове порожнє дерево створено.\n");
                break; // Вихід з switch

            case 2: // Вставити елемент
                if (!inputFloatValue(&value, "Введіть число з плаваючою комою для вставки (наприклад, 3.14): ")) {
                    break;
                }
                root = insert(root, value); // Вставляємо значення в дерево
                printf("%.2f було додано до дерева.\n", value);
                break;

            case 3: // Видалити елемент
                if (isTreeEmpty(root)) { // Перевіряємо, чи дерево не порожнє
                    break; // Оскільки root == NULL, то нічого видаляти
                }
                if (!inputFloatValue(&value, "Введіть число для видалення: ")) {
                    break;
                }
                if (search(root, value) == NULL) {
                    printf("%.2f не знайдено в дереві.\n", value);
                } else {
                    root = deleteNode(root, value); // Видаляємо вузол
                    printf("%.2f видалено з дерева.\n", value);
                }
                break;

            case 4: // Пошук елемента
                if (isTreeEmpty(root)) { 
                    break;
                }
                if (!inputFloatValue(&value, "Введіть число для пошуку: ")) {
                    break;
                }
                // Шукаємо елемент і виводимо результат
                if (search(root, value) != NULL) {
                    printf("%.2f знайдено в дереві.\n", value);
                } else {
                    printf("%.2f не знайдено в дереві.\n", value);
                }
                break;

            case 5: // Вивести дерево (зворотній обхід)
                if (isTreeEmpty(root)) { // Перевіряємо, чи дерево не порожнє
                    break;
                }
                printf("Дерево (зворотній обхід R-Ro-L): ");
                reverseInorder(root); // Викликаємо функцію зворотнього обходу
                printf("\n");
                break;

            case 6: // Видалити все дерево
                if (root == NULL) { // Додаткова перевірка на пусте дерево
                    printf("Дерево вже порожнє.\n");
                } else {
                    deleteTree(root); // Видаляємо все дерево
                    root = NULL;
                    printf("Дерево видалено.\n");
                }
                break;

            case 0: // Вихід
                printf("Вихід з програми.\n");
                break;

            default: // Обробка некоректного вибору
                printf("Некоректний вибір. Будь ласка, введіть число від 0 до 6.\n");
        }
    } while (choice != 0);

    deleteTree(root);
    root = NULL;

    return 0;
}