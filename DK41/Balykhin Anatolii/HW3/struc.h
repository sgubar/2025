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

typedef struct {
    Rectangle** data;
    int capacity;
    int size;
} Array;

Array* create_array(int capacity);
void delete_array(Array* array);
int add_element(Array* array, Rectangle* rect);
int insert_element_at(Array* array, Rectangle* rect, int index);
int delete_element_at(Array* array, int index);
void print_array(Array* array);

#endif
