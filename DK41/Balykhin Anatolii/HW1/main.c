#include "dk_tool.h"
#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of square matrices: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Wrong number: ");
        while (getchar() != '\n');
    }

    int A[size][size], B[size][size], result[size][size];
    printf("\nEntering the first matrix:\n");
    inputMatrix(size, A);
    printf("\nEntering the second matrix:\n");
    inputMatrix(size, B);
    printf("\nFirst matrix:\n");
    printMatrix(size, A);
    printf("\nSecond matrix:\n");
    printMatrix(size, B);
    multiply(size, A, B, result);
    printf("\nResult of multipy:\n");
    printMatrix(size, result);
    return 0;
}
