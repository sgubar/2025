//
//  main.c
//  d1
//
//  Created by Slava Gubar on 01.02.2021.
//

#include <stdio.h>
#include "math.h"
//#include <string.h>
//#include <memory.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
	int y = 0;
	int a = 5;
	int *b = &a;
	int *k = NULL;

	if (k != NULL) {
		int bk = *k;
	}

	int c = *b;
	int d[9];

	int size = sizeof(d);
	int count = sizeof(d)/sizeof(d[0]);

	int *array = d;
	int *g = array + 1;
	int z = *(array + 1);
	int z1 = *g;

	int z2 = g[1]; // == d[2]
	int z3 = d[1];

	char ax = 'a';
	char ax_str[] = "test";
	char *ax_str2 = "test";

	int *arr_int = (int *)malloc(sizeof(int) * 10);

	if (arr_int != NULL) {
		int zx = *(arr_int + 1);
		char *arr_char = (char *)arr_int;
		char zc = *(arr_char + 1);

		free(arr_int);
		arr_int = NULL;
	}

	int sizeOfArray = sizeof(array); // sizeof int *array
	int x2[5][6];

	int **y2 = create_matrix(5, 6);

	int sum = matrix_sum(y2, 5, 6);

	if (sum == -1)
	{
		printf ("Fail\n");
	}

	delete_matrix(y2, 5);
	y2 = NULL;

	a = 6;

	// insert code here...
	printf("Hello, World! len: %d\n", dk_strlen("test of len"));

	return 0;
}
