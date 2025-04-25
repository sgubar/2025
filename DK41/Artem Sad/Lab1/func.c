#include "func.h"
#include <stdio.h>

double faktorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Помилка: Факторіал відємного числа\n");
        return -1;
    }
    double res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

double stepin(double osnova, int pokaznyk) {
    if (pokaznyk < 0) {
        fprintf(stderr, "Помилка: Негативний степінь\n");
        return -1;
    }
    double res = 1;
    while(pokaznyk--) res *= osnova;
    return res;
}

double modul(double x) {
    return x < 0 ? -x : x;
}


bool obchyslyty_Q(double A, double B, double C, double *result) {
    if (B < 0) {
        fprintf(stderr, "Помилка: B має бути невід'ємним\n");
        return false;
    }
    
    double znamenyk = B + stepin(C, 2);
    if (znamenyk == 0) {
        fprintf(stderr, "Помилка: Ділення на нуль\n");
        return false;
    }
    
    double suma = 0;
    for (int D = 0; D <= B; D++) {
        double fact = faktorial(D);
        if (fact == -1) return false;
        suma += fact;
    }
    
    *result = (A * B) / znamenyk + suma;
    return true;
}
