#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array* createArray(int capacity) {
    if (capacity <= 0) return NULL;

    Array *arr = (Array*)malloc(sizeof(Array));
    if (!arr) return NULL;

    arr->data = (Rectangle*)malloc(sizeof(Rectangle) * capacity);
    if (!arr->data) {
        free(arr);
        return NULL;
    }

    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void destroyArray(Array *arr) {
    if (!arr) return;
    free(arr->data);
    free(arr);
}

int addElement(Array *arr, Rectangle *rect) {
    if (!arr || !rect || arr->size >= arr->capacity) return -1;
    arr->data[arr->size] = *rect;
    return arr->size++;
}

int insertElement(Array *arr, Rectangle *rect, int index) {
    if (!arr || !rect || index < 0 || index >= arr->capacity) return -1;
    arr->data[index] = *rect;
    if (index >= arr->size) {
        arr->size = index + 1;
    }
    return index;
}

void printArray(const Array *arr) {
    if (!arr) return;
    for (int i = 0; i < arr->size; i++) {
        Rectangle r = arr->data[i];
        printf("Rectangle %d: x=%.2f, y=%.2f, width=%.2f, height=%.2f\n",
               i, r.x, r.y, r.width, r.height);
    }
}
