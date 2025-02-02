//
//  main.c
//  lab1
//
//  Created by Slava Gubar on 09.02.2021.
//

#include <stdio.h>
#include "math.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");

	printf("2^2: %f\n", power(2, -2));
	printf("4!: %ld\n", factorial(4));
	printf("The result of calculation: %f\n", q(1, 1, 1));

	return 0;
}
