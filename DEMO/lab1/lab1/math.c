//
//  math.c
//  lab1
//
//  Created by Slava Gubar on 09.02.2021.
//

#include "math.h"

#define MOD(n) (n < 0 ? -n : n) // (condition) ? <> : <>

double power(int base, int pow) {

	double result = 1;
	int pw = MOD(pow);
	for (int i = 0; i < pw; i ++) {
		result *= base;
	}

	return (pow < 0) ? 1.0 / result : result;
}

//3! = 1 * 2 * 3

long factorial(int number) {
	long result = 1;

	if (number < 0) {
		return -1;
	}

	for (int i = 1; i <= number; i ++) {
		result *= i;
	}

	return result;
}

long sum_factor(int start, int finish) {
	long result = 0;

	for (int i = start; i < finish; i ++) {
		result += factorial(i + finish);
	}

	return result;
}


double q(int A, int B, int C) {
	return power((A - B), C) / (double)(B + power(C, 6)) + (double)sum_factor(0, B);
}
