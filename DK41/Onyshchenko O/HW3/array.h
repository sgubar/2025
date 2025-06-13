#ifndef ARRAY_H
#define ARRAY_H

typedef struct {
    double x, y;
    double width;
    double height;
} Rectangle;

typedef struct {
    Rectangle *data;
    int size;
    int capacity;
} Array;

Array* createArray(int capacity);
void destroyArray(Array *arr);
int addElement(Array *arr, Rectangle *rect);
int insertElement(Array *arr, Rectangle *rect, int index);
void printArray(const Array *arr);

#endif
