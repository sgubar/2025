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
            printf("�������! ������ �������� �����.\n");
            continue;
        }
        ochystyty_vvid();
        
        if(n_min && *zmina < 0) {
            printf("�������! ����� �� ���� ��������.\n");
            continue;
        }
        
        return true;
    }
}

int main() {
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    
    printf("����������� ������ �1. ������ 1\n");
    printf("���������� Q = (A*B)/(B + C^2) + ���� ���������(D=0 �� B) D!\n\n");
    
    double A, B, C;
    zchytaty_chyslo("������ �������� A: ", &A, false);
    zchytaty_chyslo("������ ������� �������� B: ", &B, true);
    zchytaty_chyslo("������ �������� C: ", &C, false);
    
    double Q;
    if(obchyslyty_Q(A, B, C, &Q)) {
        printf("\n��������� ���������� Q: %.4lf\n", Q);
    } else {
        printf("\n�� ������� ��������� Q ����� ������� � ������� �����\n");
    }
    
    printf("\n�������� Enter ��� ������");
    getchar();
    
    return 0;
}
