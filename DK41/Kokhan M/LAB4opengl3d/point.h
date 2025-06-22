#ifndef POINT_H
#define POINT_H

typedef struct {
    float x;
    float y;
} Point;

Point* createPoint(float x, float y);
void deletePoint(Point* p);

#endif
