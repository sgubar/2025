#ifndef DK_TOOL_H
#define DK_TOOL_H

void allocateMatrix(int ***matrix, int rows, int columns);
void inputMatrix(int **matrix, int rows, int columns);
void printMatrix(int **matrix, int rows, int columns);
void transposeMatrix(int **matrix, int rows, int columns, int ***transposed);
void freeMatrix(int **matrix, int rows);

#endif
