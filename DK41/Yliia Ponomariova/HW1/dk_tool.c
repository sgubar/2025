#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("Array el: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* createArray(int size) {
    //Code down create pointer of type int* and set adress of arr to it 
    int  *array = (int*)malloc(size * sizeof(int)); // (int*) converts malloc's void* to int*
                                                    // malloc allocates block of memory in bytes. malloc return void*
                                                    // sizeof(int) return size of one int in bytes (basic 4 bytes)
                                                    // size * sizeof(int) gives total bytes value that used for storing massive using size int numbers
    if (array == NULL) {
        printf("Error, array does not born in this world!");
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array; // return POINTER which holds ADRESS on array
}

int* remixArray(int arr[], int size) {
    if (size <= 0) {
        return NULL;
    }

    int* newArr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    //arr reversor
    for (int i = 0; i < size / 2; i++) {
        int temp = newArr[i];
        newArr[i] = newArr[size - 1 - i];
        newArr[size - 1 - i] = temp;
    }

    return newArr;
}
