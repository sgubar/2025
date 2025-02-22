#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

// Виділення пам’яті під матрицю
void allocateMatrix(int ***matrix, int rows, int columns) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(columns * sizeof(int));
    }
}

// Введення елементів матриці
void inputMatrix(int **matrix, int rows, int columns) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("matrix[%d][%d]: ", i, j);
            while (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input! Enter a number: ");
                while (getchar() != '\n'); // Очищення буфера
            }
        }
    }
}

// Вивід матриці
void printMatrix(int **matrix, int rows, int columns) {
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Транспонування матриці
void transposeMatrix(int **matrix, int rows, int columns, int ***transposed) {
    allocateMatrix(transposed, columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            (*transposed)[j][i] = matrix[i][j];
        }
    }
}

// Звільнення пам’яті
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
