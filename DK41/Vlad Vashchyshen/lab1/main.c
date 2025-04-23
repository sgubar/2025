#include <stdio.h>
#include "mathF.h"

// Функція для введення значень із перевіркою
void inputValues(int *A, int *B, int *C) {
    printf("Введіть A: ");
    while (scanf("%d", A) != 1) {
        printf("Помилка! Введіть ціле число для A: ");
        while (getchar() != '\n'); // Очищення буфера вводу
    }

    printf("Введіть B: ");
    while (scanf("%d", B) != 1) {
        printf("Помилка! Введіть ціле число для B: ");
        while (getchar() != '\n');
    }

    printf("Введіть C: ");
    while (scanf("%d", C) != 1) {
        printf("Помилка! Введіть ціле число для C: ");
        while (getchar() != '\n');
    }
}

// Основна функція
int main() {
    int A, B, C;
    
    inputValues(&A, &B, &C);
    
    if (100 - B - C == 0) {
        printf("Помилка: ділення на нуль! Програма завершена.\n");
        return 1;
    }

    double Q = calculateQ(A, B, C);
    printf("Результат Q: %.2lf\n", Q);

    return 0;
}
