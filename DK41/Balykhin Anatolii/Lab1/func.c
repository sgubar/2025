#include "func.h"

int stepin(int base, int exp) {
    if (exp < 0) return -1;
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int suma(int a) {
    int sum = 0;
    for (int D = 0; D <= a; D++) {
        sum += stepin(2, D);
    }
    return sum;
}

int absolute(int x) {
    return (x < 0) ? -x : x;
}

double Q(int A, int B, int C) {
     return ((double)absolute(A * C - B) / stepin(C, 3)) * suma(A);
}

void clear_variables(int* A, int* B, int* C) {
    *A = 0;
    *B = 0;
    *C = 0;
}

void get_input(int* A, int* B, int* C) {
    printf("Enter A, B, and C (C should not be zero):\n");

    printf("A: ");
    while (scanf("%d", A) != 1) {
        printf("Invalid input. Enter an integer for A: ");
        while (getchar() != '\n');
    }

    printf("B: ");
    while (scanf("%d", B) != 1) {
        printf("Invalid input. Enter an integer for B: ");
        while (getchar() != '\n');
    }

    printf("C: ");
    while (scanf("%d", C) != 1 || *C == 0) {
        printf("C must be a nonzero integer: ");
        while (getchar() != '\n');
    }
}
