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

    if (argc == 1 || argc == 2) {
        if (argc == 1) {
        ddos:
            printf("Число:");
            if (scanf("%i", &num) == 0) {
                while (getchar() != '\n');
                goto ddos;
            }
            if(num>= a){ goto ddos; }
            //getchar();
        }
        else {
            num = atoi(argv[1]);
            if (num >= a) { goto ddos; }
        } 
        
        int 卍解вацаонима = db(num,size);
        printf("%i",卍解вацаонима);
        printf("\n");
        printf("%i",bd(卍解вацаонима,size));
        printf("\n");
        system("pause");
        return 0;
    }
    else
    {
        printf("ті дюрнії");
        return -1;
    }
}
