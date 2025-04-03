#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stddef.h>


typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rectangle;

Rectangle* createRectangle(double x1, double y1, double x2, double y2);
void destroyRectangle(Rectangle* rect);
double calculateArea(const Rectangle* rect);
void printRectangle(const Rectangle* rect);
Rectangle* inputRectangle();

#endif
