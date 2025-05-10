#include "tree.h"
#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Vuzol* koreni = NULL;
    int vybir, znach;
    Vuzol* rezultat;
    
    printf("Програма роботи з бінарним деревом (тип int, симетричний обхід)\n");
    
    do {
        printf("\nМеню:\n");
        printf("1. Додати елемент\n");
        printf("2. Видалити елемент\n");
        printf("3. Знайти елемент\n");
        printf("4. Вивести дерево (симетричний обхід)\n");
        printf("5. Видалити все дерево\n");
        printf("0. Вийти\n");
        
        vybir = vvestyTsile("Виберіть опцію: ");
        
		switch (vybir) {
            case 1:
                znach = vvestyTsile("Введіть ціле число для додавання: ");
                koreni = dodaty(koreni, znach);
                printf("Елемент %d додано до дерева.\n", znach);
                break;
                
            case 2:
                znach = vvestyTsile("Введіть ціле число для видалення: ");
                koreni = vydalytyVuzol(koreni, znach);
                printf("Елемент %d видалено з дерева (якщо він існував).\n", znach);
                break;
                
            case 3:
                znach = vvestyTsile("Введіть ціле число для пошуку: ");
                rezultat = poshuk(koreni, znach);
                if (rezultat != NULL) {
                    printf("Елемент %d знайдено в дереві.\n", znach);
                } else {
                    printf("Елемент %d не знайдено в дереві.\n", znach);
                }
                break;
                
            case 4:
                printf("Симетричний обхід дерева: ");
                symetrychnyyObhid(koreni);
                printf("\n");
                break;
                
            case 5:
                vydalytyDerevo(koreni);
                koreni = NULL;
                printf("Дерево повністю видалено.\n");
                break;
                
            case 0:
                printf("Завершення програми...\n");
                break;
                
            default:
                printf("Невірний вибір! Спробуйте ще раз.\n");
        }
    } while (vybir != 0);
    
    vydalytyDerevo(koreni);
    return 0;
}
