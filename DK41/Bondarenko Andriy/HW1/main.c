#include <stdio.h>
#include "dk_tool.h"
#include <stdlib.h>

int main() {
    int A[ROWS][COLS], B[ROWS][COLS], sum[ROWS][COLS];

    printf("Matrix A:\n");
    inputMatrix(A);
    
    printf("Matrix B:\n");
    inputMatrix(B);

    addMatrices(A, B, sum);

    printf("result:\n");
    printMatrix(sum);

    system("pause");
    return 0;
}
