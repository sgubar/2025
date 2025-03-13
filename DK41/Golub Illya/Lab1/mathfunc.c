#include "mathfunc.h"
#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) return 0;
    if (n <= 1) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double absolute(double value) {
    return (value < 0) ? -value : value;
}

int check_input(void *value, const char *format) {
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, format, value) == 1) {
            return 1;
        }
    }
    return 0;
}
