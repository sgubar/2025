#include "mathfunc.h"

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double absolute(double value) {
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
}

