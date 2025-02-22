#include <stdio.h>
#include <stdlib.h>

// Функція для виведення матриці
void printMatrix(int **matrix, int rows, int columns, const char *message) {
    printf("\n%s\n", message);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            printf("%5d ", matrix[row][col]);
        }
        printf("\n");
    }
}

// Функція для створення транспонованої матриці
int **transposeMatrix(int **matrix, int rows, int columns) {
    int **transposed = (int **)malloc(columns * sizeof(int *));
    for (int i = 0; i < columns; i++) {
        transposed[i] = (int *)malloc(rows * sizeof(int));
    }
    
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            transposed[col][row] = matrix[row][col];
        }
    }
    return transposed;
}

// Функція для звільнення пам'яті
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, columns;
    
    // Введення розмірності матриці
    printf("Enter the number of rows 'a' and columns 'b' in the format 'a b':\n");
    while (scanf("%d %d", &rows, &columns) != 2 || rows <= 0 || columns <= 0) {
        printf("Error! Please enter two positive integers.\n");
        while (getchar() != '\n'); // Очищення буфера вводу
    }

    // Виділення пам’яті під початкову матрицю
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    
    // Заповнення матриці користувачем
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            int input_status;
            do {
                printf("matrix[%d][%d]: ", row, col);
                input_status = scanf("%d", &matrix[row][col]);
                if (input_status != 1) {
                    printf("Error! Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n'); // Очищення буфера
                }
            } while (input_status != 1);
        }
    }
    
    // Виведення введеної матриці
    printMatrix(matrix, rows, columns, "Entered matrix:");
    
    // Створення транспонованої матриці
    int **transposed = transposeMatrix(matrix, rows, columns);
    
    // Виведення транспонованої матриці
    printMatrix(transposed, columns, rows, "Transposed matrix:");
    
    // Звільнення пам’яті
    freeMatrix(matrix, rows);
    freeMatrix(transposed, columns);
    
    return 0;
}
