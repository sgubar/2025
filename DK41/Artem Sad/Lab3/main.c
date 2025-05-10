#include "tree.h"
#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Vuzol* koreni = NULL;
    int vybir, znach;
    Vuzol* rezultat;
    
    printf("�������� ������ � ������� ������� (��� int, ����������� �����)\n");
    
    do {
        printf("\n����:\n");
        printf("1. ������ �������\n");
        printf("2. �������� �������\n");
        printf("3. ������ �������\n");
        printf("4. ������� ������ (����������� �����)\n");
        printf("5. �������� ��� ������\n");
        printf("0. �����\n");
        
        vybir = vvestyTsile("������� �����: ");
        
		switch (vybir) {
            case 1:
                znach = vvestyTsile("������ ���� ����� ��� ���������: ");
                koreni = dodaty(koreni, znach);
                printf("������� %d ������ �� ������.\n", znach);
                break;
                
            case 2:
                znach = vvestyTsile("������ ���� ����� ��� ���������: ");
                koreni = vydalytyVuzol(koreni, znach);
                printf("������� %d �������� � ������ (���� �� �������).\n", znach);
                break;
                
            case 3:
                znach = vvestyTsile("������ ���� ����� ��� ������: ");
                rezultat = poshuk(koreni, znach);
                if (rezultat != NULL) {
                    printf("������� %d �������� � �����.\n", znach);
                } else {
                    printf("������� %d �� �������� � �����.\n", znach);
                }
                break;
                
            case 4:
                printf("����������� ����� ������: ");
                symetrychnyyObhid(koreni);
                printf("\n");
                break;
                
            case 5:
                vydalytyDerevo(koreni);
                koreni = NULL;
                printf("������ ������� ��������.\n");
                break;
                
            case 0:
                printf("���������� ��������...\n");
                break;
                
            default:
                printf("������� ����! ��������� �� ���.\n");
        }
    } while (vybir != 0);
    
    vydalytyDerevo(koreni);
    return 0;
}
