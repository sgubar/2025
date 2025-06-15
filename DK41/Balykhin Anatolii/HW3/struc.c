#include "struc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Rectangle* create_rectangle() {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    if (!rect) return NULL;

    printf("Enter the coordinates of 4 points (x y):\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        if (scanf("%lf %lf", &rect->points[i].x, &rect->points[i].y) != 2) {
            printf("Coordinate reading error.\n");
            while (getchar() != '\n');
            free(rect);
            return NULL;
        }
    }

    return rect;
}

void print_rectangle(Rectangle* rect) {
    if (!rect) return;
    printf("Rectangle with points:\n");
    for (int i = 0; i < 4; i++) {
        printf("  Point %d: (%.2f, %.2f)\n", i + 1, rect->points[i].x, rect->points[i].y);
    }
}

int check_if_rectangle(Rectangle* rect) {
    if (!rect) return 0;

    Point* p = rect->points;

    double d01 = distance(p[0], p[1]);
    double d12 = distance(p[1], p[2]);
    double d23 = distance(p[2], p[3]);
    double d30 = distance(p[3], p[0]);
    double d02 = distance(p[0], p[2]);
    double d13 = distance(p[1], p[3]);

    if (fabs(d01 - d23) < 0.001 &&
        fabs(d12 - d30) < 0.001 &&
        fabs(d02 - d13) < 0.001)
        return 1;

    return 0;
}

double rectangle_area(Rectangle* rect) {
    if (!check_if_rectangle(rect)) return 0;

    double side1 = distance(rect->points[0], rect->points[1]);
    double side2 = distance(rect->points[1], rect->points[2]);
    return side1 * side2;
}

void delete_rectangle(Rectangle* rect) {
    if (rect) free(rect);
}

Array* create_array(int capacity) {
    if (capacity <= 0) return NULL;

    Array* array = (Array*)malloc(sizeof(Array));
    if (!array) {
        perror("Unable allocate memory for array");
        return NULL;
    }

    array->data = (Rectangle**)malloc(capacity * sizeof(Rectangle*));
    if (!array->data) {
        perror("Unable allocate memory for array");
        free(array);
        return NULL;
    }
    for (int i = 0; i < capacity; i++) {
        array->data[i] = NULL;
    }
    array->capacity = capacity;
    array->size = 0;

    return array;
}

void delete_array(Array* array) {
    if (!array) return;

    for (int i = 0; i < array->capacity; i++) {
        if (array->data[i] != NULL) {
            delete_rectangle(array->data[i]);
        }
    }
    free(array->data);
    free(array);
}

int add_element(Array* array, Rectangle* rect) {
    if (!array || !rect) return -1;
    if (array->size >= array->capacity) {
        printf("Array is full.\n");
        return -1;
    }
    for (int i = 0; i < array->capacity; i++) {
        if (array->data[i] == NULL) {
            array->data[i] = rect;
            array->size++;
            return i;
        }
    }
    return -1;
}

int insert_element_at(Array* array, Rectangle* rect, int index) {
    if (!array || !rect) return -1;
    if (index < 0 || index >= array->capacity) {
        printf("Error: index out of array range.\n");
        return -1;
    }

    if (array->data[index] != NULL) {
        delete_rectangle(array->data[index]);
    } else {
        array->size++;
    }

    array->data[index] = rect;

    return index;
}
int delete_element_at(Array* array, int index) {
    if (!array || index < 0 || index >= array->capacity) {
        printf("Incorrect index or array does not exist.\n");
        return -1;
    }

    if (array->data[index] == NULL) {
        printf("There is no element to delete at index %d.\n", index);
        return -1;
    }
    delete_rectangle(array->data[index]);
    array->data[index] = NULL;
    array->size--;
    return 0;
}

void print_array(Array* array) {
    if (!array) {
        printf("The array is NULL.\n");
        return;
    }

    printf("\n Array contents (Size: %d, Capacity: %d)\n", array->size, array->capacity);
    if (array->size == 0) {
        printf("The array is empty.\n");
    } else {
        int printed_count = 0;
        for (int i = 0; i < array->capacity; i++) {
            if (array->data[i] != NULL) {
                printf("\n[Index %d]\n", i);
                print_rectangle(array->data[i]);
                if(check_if_rectangle(array->data[i])) {
                    printf("It's rectangular. Area: %.2f\n", rectangle_area(array->data[i]));
                } else {
                    printf("This is not a rectangle.\n");
                }
                printed_count++;
            }
        }
        if (printed_count == 0) {
             printf("The array is empty.\n");
        }
    }
    printf("End of array\n");
}
