#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main() {
    int rows, columns;

    printf("Enter the number of rows and columns (format: rows columns): ");
    while (scanf("%d %d", &rows, &columns) != 2 || rows <= 0 || columns <= 0) {
        printf("Invalid input! Enter two positive integers: ");
        while (getchar() != '\n'); // Очищення буфера
    }

    int **matrix;
    allocateMatrix(&matrix, rows, columns);
    inputMatrix(matrix, rows, columns);
    printMatrix(matrix, rows, columns);

    int **transposed;
    transposeMatrix(matrix, rows, columns, &transposed);
    
    printf("\nTransposed Matrix:\n");
    printMatrix(transposed, columns, rows);

    freeMatrix(matrix, rows);
    freeMatrix(transposed, columns);

    return 0;
}
