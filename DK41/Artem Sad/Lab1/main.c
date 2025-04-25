#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"
#include <windows.h>

void ochystyty_vvid() {
    while(getchar() != '\n');
}

bool zchytaty_chyslo(const char *zapros, double *zmina, bool n_min) {
    while(1) {
        printf("%s", zapros);
        if(scanf("%lf", zmina) != 1) {
            ochystyty_vvid();
            printf("Помилка! Введіть коректне число.\n");
            continue;
        }
        ochystyty_vvid();
        
        if(n_min && *zmina < 0) {
            printf("Помилка! Число має бути невідємним.\n");
            continue;
        }
        
        return true;
    }
}

int main() {
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    
    printf("Лабораторна робота №1. Варіант 1\n");
    printf("Обчислення Q = (A*B)/(B + C^2) + Сума факторіалів(D=0 до B) D!\n\n");
    
    double A, B, C;
    zchytaty_chyslo("Введіть значення A: ", &A, false);
    zchytaty_chyslo("Введіть невідємне значення B: ", &B, true);
    zchytaty_chyslo("Введіть значення C: ", &C, false);
    
    double Q;
    if(obchyslyty_Q(A, B, C, &Q)) {
        printf("\nРезультат обчислення Q: %.4lf\n", Q);
    } else {
        printf("\nНе вдалося обчислити Q через помилку у вхідних даних\n");
    }
    
    printf("\nНатисніть Enter для виходу");
    getchar();
    
    return 0;
}
