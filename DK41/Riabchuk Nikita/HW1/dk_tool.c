//#pragma warning(disable: 6011)
#include <stdio.h> 
//#include <math.h> 
#include <stdlib.h>
#include "dk_tool.h"

int counta(double number) {
	int count = 0;
	if (number == 0) {
		count = 1;
	}
	else {
		while (number != 0) {
			number /= 10;
			count++;
		}
	}
	return count;
}

long long st(int x, int y) {
	//return (int)pow(x, y);//short
	long long a = 1;
	for (int i = 0; i < y; i++) {
		a *= x;
	}
	return a;
}


int db(int a, int b) {
	//char* array = malloc(st(2,b));//short
	//_itoa(a, array, 2);
	//a = atoi(array);
	//free(array);
	//return a;
	int *aray = calloc(st(2, b), sizeof(int));
	if (aray == NULL) {
		return -1;
	}
	for (int i = b-1; i >= 0; i--)
	{
		aray[i] = a % 2;
		a /= 2;
	}
	int result = 0;
	for (int i = 0; i < b; i++)
	{
		result = result * 10 + aray[i];
	}
	free(aray);
	aray = NULL;
	return result;
}

int bd(int a, int b) {
	/*char* array = malloc(b);
	(int)_itoa(a, array, 10);
	int z = 0;
	int l = 0;
	for (int i = counta(a) - 1; i >= 0; i--)
	{
		z += (array[i] - '0') * (st(2, l));
		l++;
	}
	free(array);
	return z;*/
	int* array = calloc(st(2, b), sizeof(int));
	if (array == NULL) {
		return -1;
	}
	for (int i = b - 1; i >= 0; i--)
	{
		array[i] = a % 10;
		a /= 10;
	}
	int z = 0;
	int l = 0;
	for (int i = b-1; i >= 0; i--) 
	{
		z += (int)(array[i] * (st(2, l)));
		l++;
		//printf("%i\t%i\n", array[i],z);
	}
	free(array);
	array = NULL;
	return z;
}

