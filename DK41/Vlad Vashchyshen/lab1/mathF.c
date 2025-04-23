#include "mathF.h"
#include <stdio.h>
#include <math.h>

// Функція для обчислення суми степенів 2^(D+A)
double calculateSum(int A) {
    double sum = 0;
    for (int D = 0; D <= A; D++) {
        sum += pow(2, D + A);
    }
    return sum;
}

// Функція для обчислення Q
double calculateQ(int A, int B, int C) {
    if (100 - B - C == 0) {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
    double firstPart = (double)(A + B + C) / (100 - B - C);
    double secondPart = calculateSum(A);
    return firstPart + secondPart;
}
