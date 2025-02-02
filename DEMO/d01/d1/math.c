//
//  math.c
//  d1
//
//  Created by Slava Gubar on 01.02.2021.
//

#include "math.h"
#include <stdlib.h>

int sum(int a, int b) {
	return a + b;
}

int matrix_sum(int **matrix, int row, int col)
{
	int result = -1;

	if (matrix == NULL)
	{
		return result;
	}

	result = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result += *(*(matrix + i) + j); // result = result + matrix[i][j];
		}
	}

	return result;
}

int matrix_sum1(int *matrix, int row, int col) {
	int result = -1;

	if (matrix == NULL)
	{
		return result;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result += *(matrix + i*col + j); // result = result + matrix[i][j]; ???
		}
	}

	result = 0;
	return result;
}

int **create_matrix(int row, int col)
{
	int **matrix = (int **)malloc(sizeof(int *) * row); // int *array[];

	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int *)malloc(sizeof(int) * col); //void *
	}

	return matrix;
}

void delete_matrix(int **matrix, int row) {
	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < row; i++) {
		free (*(matrix + i));
	}

	free(matrix);
}

int *create_matrix1(int row, int col) {
	return (int *)malloc(sizeof(int) * row * col);
}

void delete_matrix1(int *matrix) {
	if (matrix != NULL) {
		free(matrix);
	}
}

int dk_strlen(char *string) {
	int result = 0;

	while(*string != '\0') {
		string ++;
		result ++;
	}

	return result;
}
