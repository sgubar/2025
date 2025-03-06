#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main() {
    int size;
    while (1) {
        printf("Enter size of the matrix: ");
        if (scanf("%d", &size) != 1 || size <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while(getchar() != '\n');
        } else {
            break;
        }
    }
    int** A = createMatrix(size);
    int** B = createMatrix(size);
    int** result = createMatrix(size);

    inputMatrix(size, A);
    inputMatrix(size, B);
    printf("Matrix A:\n");
    printMatrix(size, A);
    printf("Matrix B:\n");
    printMatrix(size, B);
    multiplyMatrices(size, A, B, result);
    printf("Result of multiplication (A * B):\n");
    printMatrix(size, result);

    return 0;
}
