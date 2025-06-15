#include "math_utils.h"

// Fast exponentiation (binary exponentiation)
long long power(int base, unsigned exp) {
    long long result = 1;
    long long b = base;
    while (exp) {
        if (exp & 1) result *= b;
        b *= b;
        exp >>= 1;
    }
    return result;
}

long long factorial(unsigned n) {
    long long result = 1;
    for (unsigned i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int abs_val(int x) {
    return x < 0 ? -x : x;
}
