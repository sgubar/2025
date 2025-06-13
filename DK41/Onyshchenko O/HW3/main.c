#include <stdio.h>
#include "array.h"

int main() {
    Array *rects = createArray(5);
    if (!rects) {
        printf("Помилка створення масиву\n");
        return 1;
    }

    Rectangle r1 = {0, 0, 10, 5};
    Rectangle r2 = {1, 2, 3, 4};
    Rectangle r3 = {2, 2, 6, 2};

    addElement(rects, &r1);
    addElement(rects, &r2);
    insertElement(rects, &r3, 1); // заміщення

    printArray(rects);

    destroyArray(rects);
    return 0;
}
