#include <stdio.h>
#include "math.h"

int main() {
    double A, B, C;
    printf("Input number A (real number): ");
    while (scanf("%lf", &A) != 1) {
        printf("Error pridyrok! Enter a valid number: ");
        while (getchar() != '\n');
    }
    printf("Enter B (real number, not 0): ");
    while (scanf("%lf", &B) != 1 || B == 0) {
        printf("Error! B cannot be 0. Please enter again: ");
        while (getchar() != '\n');
    }
    printf("Input number C (real number): ");
    while (scanf("%lf", &C) != 1 || C < 0) {
        printf("Error! C must be >= 0. Please enter again: ");
        while (getchar() != '\n');
    }
    double sqrt_part = square_root(B + C);
    if (sqrt_part == -1) {
        printf("Error! Cannot find the root of a negative number.\n");
        return 1;
    }
    double sum_factorial = 0;
    for (int D = 0; D <= (int)C; D++) {
        sum_factorial += factorial((int)A + D);
    }
    double Q = A * (sqrt_part / B) + sum_factorial;
    printf("Result Q: %.2lf\n", Q);
    return 0;
}
