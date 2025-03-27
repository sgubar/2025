#include <stdio.h>
#include <stdlib.h>
#include "math_operations.h"
#include "calculator.h"

double calculate_q(int A, int B, int C) {
    if (C == 0) {
        printf("Error: C cannot be zero (division by zero error).\n");
        exit(1);
    }
    int numerator = absolute(A * C - B);
    int denominator = power(C, 3);
    int sum_part = 0;
    for (int D = 0; D <= A; D++) {
        sum_part += power(2, D);
    }
    return (double)numerator / denominator * sum_part;
}

int main() {
    printf("This program calculates Q using the given formula.\n");
    int A = get_integer("Enter A (integer >= 0): ", 0, 0);
    int B = get_integer("Enter B (integer): ", -1, 0);
    int C = get_integer("Enter C (integer, nonzero): ", -1, 1);
    
    double Q = calculate_q(A, B, C);
    printf("Result: Q = %lf\n", Q);
    return 0;
}
