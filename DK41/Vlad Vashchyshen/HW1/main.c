#include <stdio.h>
#include "dk_tool.h"

int main() { //write chcp 65001 (UTF8)
    int rows, cols;
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    // Введення розміру матриці з перевіркою
    printf("Введіть кількість рядків (1-%d): ", MAX_SIZE);
    while (scanf("%d", &rows) != 1 || rows <= 0 || rows > MAX_SIZE) {
        printf("Некоректне значення! Введіть кількість рядків ще раз: ");
        while (getchar() != '\n');
    }

    printf("Введіть кількість стовпців (1-%d): ", MAX_SIZE);
    while (scanf("%d", &cols) != 1 || cols <= 0 || cols > MAX_SIZE) {
        printf("Некоректне значення! Введіть кількість стовпців ще раз: ");
        while (getchar() != '\n');
    }

    // Введення двох матриць через термінал
    printf("Введення першої матриці:\n");
    inputMatrix(A, rows, cols);
    printf("Введення другої матриці:\n");
    inputMatrix(B, rows, cols);

    // Віднімання матриць
    subtractMatrices(A, B, result, rows, cols);

    // Вивід результату
    printf("Результат віднімання:\n");
    printMatrix(result, rows, cols);

    return 0;
}
