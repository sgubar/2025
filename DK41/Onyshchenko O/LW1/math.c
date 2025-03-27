#include "math.h"
#include <math.h>
#include <stdio.h>
double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
double absolute(double x) {
    return x < 0 ? -x : x;
}
double square_root(double x) {
    return x < 0 ? -1 : sqrt(x);
}
