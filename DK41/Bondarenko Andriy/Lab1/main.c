#include <stdio.h>
#include <math.h>
#include "math_utils.h"

// Функція для отримання коректного вводу числа
double getValidInput(const char* prompt) {
    double value;
    printf("%s", prompt);
    while (scanf("%lf", &value) != 1) {
        printf("Error! Enter number again: ");
        while (getchar() != '\n'); // Очищення буфера
    }
    return value;
}

int main() {
    double A, B, C, Q = 0;

    printf("Expression calculation: Q = A * (sqrt(B + C) / B) + sum((A + D)!)\n");

    // Ввід даних з перевіркою
    A = getValidInput("Enter A: ");

    do {
        B = getValidInput("Enter B (B > 0): ");
        if (B <= 0) {
            printf("Error! B must be greater than 0.\n");
        }
    } while (B <= 0);

    C = getValidInput("Enter C: ");

    // Обчислення виразу
    Q = A * (sqrt(B + C) / B);
    
    for (int D = 0; D <= C; D++) { 
        Q += factorial(A + D);
    }

    // Виведення результату
    printf("Result Q: %.4lf\n", Q);
    
    return 0;
}
