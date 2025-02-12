#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#include "dk_tool.h"

int counta(int number) {
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

int db(int a, int b) {
	char* array = malloc(b);
	_itoa(a, array, 2);
	a = atoi(array);
	free(array);
	return a;
}
int bd(int a, int b) {
	char* array = malloc(b);
	(int)_itoa(a, array, 10);
	int z = 0;
	int l = 0;
	for (int i = counta(a)-1; i >= 0; i--)
	{
		z += (array[i] -'0') * (st(2, l));
		l++;
	}
	return z;
}

int st(int x, int y) {
	return (int)pow(x, y);
};