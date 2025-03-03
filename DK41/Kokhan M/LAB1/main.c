#include <stdio.h>
#include <stdlib.h>
#include "func.c"

int main() {
    double A, B, C;

    do {
        printf("Var A (a number): ");
    } while (scanf("%lf", &A) != 1 || (getchar() != '\n' && getchar() != EOF)); 
    

    do {
        printf("Var B (a non-negative number): ");
        if (scanf("%lf", &B) != 1 || getchar() != '\n') {
            printf("Ty invalid, chy sho?\n");
            B = -1; 
        } else if (B < 0) {
            printf("KAKOI NEGATIV TY CHYWURLA?\n");
        }
    } while (B < 0);
    
    do {
        printf("Var C (a number): ");
    } while (scanf("%lf", &C) != 1 || (getchar() != '\n' && getchar() != EOF));

    double Q = calculate_Q(A, B, C);
    printf("Var of Q is: %lf\n", Q);

    return 0;
}
