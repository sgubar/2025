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
    int num;
    //num = rand() % a;

    switch (argc){
    case 1:
         while (1) {
                printf("Число:");
                if (scanf("%i", &num) == 0) {
                    while (getchar() != '\n');
                    printf("еєеєєееєееє так діло не буде, забагато хочешь або роби менше %d або я тобі зламаю ноги\n", a);
                    continue;
                }
                if (num >= a) {
                    printf("еєеєєееєееє так діло не буде, забагато хочешь або роби менше %d або я тобі зламаю ноги\n", a);
                    continue;
                }
                break;
            }
         break;
        
    case 2:
       num = atoi(argv[1]);
       if (num >= a) {
           while (1) {
               printf("Число:");
               if (scanf("%i", &num) == 0) {
                   while (getchar() != '\n');
                   printf("еєеєєееєееє так діло не буде, забагато хочешь або роби менше %d або я тобі зламаю ноги\n", a);
                   continue;
               }
               if (num >= a) {
                   printf("еєеєєееєееє так діло не буде, забагато хочешь або роби менше %d або я тобі зламаю ноги\n", a);
                   continue;
               }
               break;
           }
           break;
       }
       break;
    default:
        printf("ті дюрнії");
        return -1;
        break;
    
}
    int 卍解вацаонима = dtb(num, size);
    printf("%i", 卍解вацаонима);
    printf("\n");
    printf("%i", btd(卍解вацаонима, size));
    printf("\n");
    system("pause");
    return 0;
