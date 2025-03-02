#include <stdio.h>
#include "dk_tool.h"

// Функція для введення матриці з терміналу
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Введіть елементи матриці %d x %d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Елемент [%d][%d]: ", i, j);
            while (scanf("%d", &matrix[i][j]) != 1) { // Перевірка правильності вводу
                printf("Некоректне значення! Введіть число: ");
                while (getchar() != '\n'); // Очищення буфера
            }
        }
    }
}

// Функція для виведення матриці в термінал
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Матриця %d x %d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функція для віднімання двох матриць
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}
