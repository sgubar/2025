#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)calloc(size, sizeof(int));
    }
    return matrix;
}

void inputMatrix(int size, int** matrix) {
    printf("Enter matrix values (size %dx%d):\n", size, size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            while (1) {
                printf("Element [%d][%d]: ", i, j);
                if (scanf("%d", &matrix[i-1][j-1]) != 1) {
                    printf("Invalid input. Please enter an integer.\n");
                    while(getchar() != '\n');
                } else {
                    break;
                }
            }
        }
    }
}

void printMatrix(int size, int** matrix) {
    printf("Matrix (%dx%d):\n", size, size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            printf("%d ", matrix[i-1][j-1]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int size, int** A, int** B, int** result) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            result[i-1][j-1] = 0;
            for (int k = 1; k <= size; k++) {
                result[i-1][j-1] += A[i-1][k-1] * B[k-1][j-1];
            }
        }
    }
}
