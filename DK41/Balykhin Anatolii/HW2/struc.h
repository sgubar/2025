#ifndef STRUC_H
#define STRUC_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point points[4];
} Rectangle;

Rectangle* create_rectangle();
void print_rectangle(Rectangle* rect);
int check_if_rectangle(Rectangle* rect);
double rectangle_area(Rectangle* rect);
void delete_rectangle(Rectangle* rect);

#endif
