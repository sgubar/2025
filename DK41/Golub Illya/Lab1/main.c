#include <stdio.h>
#include "mathfunc.h"

int main() {
    int A;
    double B;
    char buffer[100];

    // Введення значення A з валідацією
    while (1) {
        printf("Enter integer for A (0 <= A <= 20): ");
        if (check_input(&A, "%d") && A >= 0 && A <= 20) {
            break;
        } else {
            printf("Incorrect Value. Type from 0 to 20.\n");
        }
    }

    // Введення значення B з валідацією
    while (1) {
        printf("Enter a number for B: ");
        if (check_input(&B, "%lf")) {
            break;
        } else {
            printf("Invalid input. Please enter a number.\n");
        }
    }

    // Обчислення знаменника та перевірка на ділення на нуль
    double denominator = absolute(2 * A + B);
    if (denominator == 0) {
        printf("Error: division by zero.\n");
        return 1;
    }

    // Обчислення результату
    unsigned long long numerator = factorial(A);
    double Q = (double)numerator / denominator;

    // Виведення результату
    printf("The result Q is: %lf\n", Q);

    return 0;
}

