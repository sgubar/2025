//#pragma warning(disable: 6011)
#include <stdio.h>  
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
	long long a = 1;
	for (int i = 0; i < y; i++) {
		a *= x;
	}
	return a;
}


int dtb(int a, int b) {
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

int btd(int a, int b) {
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
	}
	free(array);
	array = NULL;
	return z;
}

