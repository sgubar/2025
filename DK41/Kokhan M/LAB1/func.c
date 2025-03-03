#include "func.h"
#include <stdlib.h>

double factorial(int n) {
    if (n < 0) {
        printf("V tebe MM v dote < 0, geniy\n");
        exit(EXIT_FAILURE);
    }

    if (n == 0) {
        return 1.0; 
    }

    double result = 1.0;    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

double calculate_Q(double A, double B, double C) {
    if (B + C * C == 0) {
        printf("Ya zara tebe na 0 podily, zroz?\n");
        exit(EXIT_FAILURE);
    }

    double first_term = (A * B) / (B + C * C);

    double sum = 0.0;

    for (int D = 0; D <= (int)B; D++) {
        sum += factorial(D);
    }
    return first_term + sum;
}
