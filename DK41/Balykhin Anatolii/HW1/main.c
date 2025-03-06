#include "dk_tool.h"

int main() {
    int size;
    printf("Enter the size of square matrices: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Error! Enter a positive number: ");
        while (getchar() != '\n');
    }

    int** A = createMatrix(size);
    int** B = createMatrix(size);
    int** result = createMatrix(size);

    printf("\nEntering the first matrix:\n");
    inputMatrix(size, A);
    printf("\nEntering the second matrix:\n");
    inputMatrix(size, B);
    printf("\nFirst matrix:\n");
    printMatrix(size, A);
    printf("\nSecond matrix:\n");
    printMatrix(size, B);
    multiplyMatrices(size, A, B, result);
    printf("\nResult of multiplication:\n");
    printMatrix(size, result);

    return 0;
}
