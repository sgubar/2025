#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;  
    double major_axis; 
    double minor_axis;
} Ellipse;

Ellipse* create_ellipse(Point center, double major_axis, double minor_axis);

void destroy_ellipse(Ellipse* ellipse);

double calculate_ellipse_area(const Ellipse* ellipse);

void print_ellipse(const Ellipse* ellipse);

bool is_point_inside_ellipse(const Ellipse* ellipse, const Point* point);

#endif
