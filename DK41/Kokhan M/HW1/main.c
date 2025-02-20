#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.c"

int main() {
    int size;
    
    printf("Size of Arr: ");
    scanf("%d", &size);

    int* array = createArray(size);
    
    printArray(array, size);


    int* remixedArray = remixArray(array, size);
    
    printArray(remixedArray, size);
    free(array);
    free(remixedArray);

    return 0;
}
