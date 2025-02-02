//
//  main.c
//  d01_matrix
//
//  Created by Slava Gubar on 09.02.2024.
//

#include <stdio.h>
#include "matrixtool.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");

	int m[2][2] = { { 1, 1}, {1, 2} };

	int result = sum_elements_of_matrix((int *)m, 2, 2);

	printf("result - %d\n", result);

	//1. Create matrix
	//2. Print matrix

	int *matrix = create_matrix(3, 3);
	fill_matrix(matrix, 3, 3);
	print_matrix((int *)matrix, 3, 3);

	printf("result - %d\n", sum_elements_of_matrix(matrix, 3, 3));

	destroy_matrix(matrix);
	// !!!
	//1. int **matrix_alternative;
	//2. matrix as struct/object

	return 0;
}
