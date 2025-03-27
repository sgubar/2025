#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int get_integer(const char *prompt, int min_value, int nonzero) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }
        if (min_value != -1 && value < min_value) {
            printf("Error: Value must be at least %d.\n", min_value);
            continue;
        }
        if (nonzero && value == 0) {
            printf("Error: Value cannot be zero.\n");
            continue;
        }
        return value;
    }
}
