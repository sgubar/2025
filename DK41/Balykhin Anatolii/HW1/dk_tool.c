#include "dk_tool.h"
#include <stdio.h>

void inputMatrix(int size, int matrix[size][size]) {
    printf("Enter elements of %dx%d matrix:\n", size, size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            printf("Element [%d][%d]: ", i, j);
            while (scanf("%d", &matrix[i][j]) != 1) {
                printf("Error! Enter a valid number: ");
                while (getchar() != '\n');
            }
        }
    }
}

void printMatrix(int size, int matrix[size][size]) {
    printf("Matrix %dx%d:\n", size, size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply(int size, int A[size][size], int B[size][size], int result[size][size]) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            result[i][j] = 0;
            for (int k = 1; k <= size; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
