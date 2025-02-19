#define _CRT_SECURE_NO_WARNINGS 
#include <time.h>
#include <math.h>               
#include <stdio.h>  
#include <stdlib.h>
//#include <iostream>             
#include <Windows.h>            
//#include <locale>  
#include "dk_tool.h"

//using namespace std;

int main(int argc, char* argv[]) {

    srand((int)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 8;
    const int popa = 2;
    int a = (int)st(popa, size);
    int num = -1;
    //num = rand() % a;

    if (argc == 1 || argc == 2) {
        if (argc == 2) {
            num = atoi(argv[1]);
        }
            while (num >= a || num <=- 1) {
                printf("Число в діапазоні 0 - %d:", a - 1);
                if (scanf("%i", &num) == 0) {
                    while (getchar() != '\n');
                    printf("еєеєєееєееє так діло не буде, забагато хочешь або роби в діапазоні 0 - %d або я тобі зламаю ноги\n", a-1);
                    continue;
                }
            }
        
            int 卍解вацаонима = dtb(num, size);
            printf("%i", 卍解вацаонима);
            printf("\n");
            printf("%i", btd(卍解вацаонима, size));
            printf("\n");
            system("pause");
            return 0;

        }
        else {
                printf("ті дюрнії");
                return -1;
            }
            }
