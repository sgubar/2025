#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"

int input_int(const char *prompt, int min, int max) {
    int v; char t;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &v, &t) != 2 || t != '\n') {
            printf("  >> Invalid input! Please enter an integer.\n");
            while (getchar() != '\n');
        } else if (v < min || v > max) {
            printf("  >> Value must be between [%d..%d].\n", min, max);
        } else {
            return v;
        }
    }
}

int main(void) {
    int A = input_int("Enter A (0 ≤ A ≤ 20): ", 0, 20);
    int B = input_int("Enter B (−100 ≤ B ≤ 100): ", -100, 100);
    int C = input_int("Enter C (−100 ≤ C ≤ 100): ", -100, 100);

    int denom = 100 - B - C;
    if (denom == 0) {
        fprintf(stderr, "Error: denominator is zero!\n");
        return EXIT_FAILURE;
    }

    double Q = (double)(A + B + C) / denom;
    for (int D = 0; D <= A; ++D) {
        Q += power(2, D + A);
    }

    // Лише результат Q
    printf("Result Q = %.2f\n", Q);

    return EXIT_SUCCESS;
}
