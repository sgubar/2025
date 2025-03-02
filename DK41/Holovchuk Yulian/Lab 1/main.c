#include <stdio.h>
#include <stdlib.h>
#include "MathFX.h"

/** 
 * @brief Зчитує число від користувача з перевіркою правильності введення.
 * 
 * @param name Назва змінної у формулі (символ для підказки користувачу).
 * @param type Тип очікуваного значення: 0 - раціональні числа, 1 - цілі числа.
 * @return float Введене значення (для цілих чисел повертається як float, але без десяткової частини).
 */
float input(char name, int type) {
    float val;
    char c;

    if (type == 0) {
        printf("Enter rational number %c: ", name);
        while (scanf("%f", &val) != 1) {
            printf("Invalid input! Enter rational number %c: ", name);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        while ((c = getchar()) != '\n' && c != EOF);
    } else if (type == 1) {
        printf("Enter integer number %c: ", name);
        while (1) {
            if (scanf("%f", &val) == 1 && val == (int)val) {
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
            printf("Invalid input! Enter integer number %c: ", name);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } else {
        printf("Error: Invalid type!\n");
        exit(1);
    }
    return val;
}

int main() {
    printf("The code is designed to calculate Q using the formula: Q = (A^2 + B^2) / (B + 5^C) + B!\n");
    float A = input('A', 0);
    float B = input('B', 0);
    int C = (int)input('C', 1);

    // Перевірка ділення на 0
    if (B + power(5, C) == 0) {
        printf("Error: Division by zero is not allowed!\n");
        return 1;
    }

    // Обчислення виразу Q ← (A² + B²) / (B + 5^C) + B!
    float Q = (power(A, 2) + power(B, 2)) / (B + power(5, C)) + factorial((int)B);

    printf("Q = %f\n", Q);

    printf("Press Enter to exit...");
    getchar();  // Чекає на натискання клавіші

    return 0;
}
