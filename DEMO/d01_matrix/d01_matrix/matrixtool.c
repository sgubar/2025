//
//  matrixtool.c
//  d01_matrix
//
//  Created by Slava Gubar on 09.02.2024.
//

#include "matrixtool.h"
#include <stdio.h>
#include <stdlib.h>

int sum_elements_of_matrix_3(int m[][3]){
	return 1;
}

int sum_elements_of_matrix(int *matrix, int nrow, int ncol) {
	int result = 0;

	if (NULL == matrix) {
		return __INT_MAX__;
	}

	for (int i = 0; i < nrow; i ++) {
		for (int j = 0; j < ncol; j ++) {
			result += *(matrix + nrow * i + j);
		}
	}

	return  result;
}

// create matrix
int *create_matrix(int nrow, int ncol) {
	int *result = (int *)malloc(nrow * ncol * sizeof(int));
	return result;
}

void destroy_matrix(int *matrix) {
	if (NULL == matrix) {
		return;
	}

	free(matrix);
}

// print matrix
void print_matrix(int *matrix, int nrow, int ncol) {

	if (NULL == matrix) {
		printf("Invalid matrix!\n");
		return ;
	}

	for (int i = 0; i < nrow; i ++) {
		for (int j = 0; j < ncol; j ++) {
			printf("%d ", *(matrix + nrow * i + j));
		}
		printf("\n");
	}
}

void fill_matrix(int *matrix, int nrow, int ncol) {
	if (NULL == matrix) {
		return ;
	}

	for (int i = 0; i < nrow; i ++) {
		for (int j = 0; j < ncol; j ++) {
			*(matrix + nrow * i + j) = i + j;
		}
		printf("\n");
	}
}


int my_strlen(char *str) {
	int result = 0;
	int i = 0;

	while(*(str + i) != '\0') {
		i ++;
		result ++;
	}

	return result;
}
