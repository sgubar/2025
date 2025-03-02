#include "MathFX.h"

// Факторіал
int factorial(int n) {
    if (n < 0) return 0;
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// Піднесення до степеня
float power(float base, int exponent) {
    float result = 1.0;
    int exp = exponent < 0 ? -exponent : exponent;
    for (int i = 0; i < exp; i++)
        result *= base;
    return (exponent < 0) ? 1.0 / result : result;
}
