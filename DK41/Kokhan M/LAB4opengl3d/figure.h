#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

#define PT_NUM 3

typedef struct {
    float R, G, B;
} Color_s;

typedef struct {
    Point* points[PT_NUM];
    Color_s* color;
} Figure_s;

typedef struct FigureListElement {
    Figure_s* figure;
    struct FigureListElement* next;
    struct FigureListElement* prev;
} FigureListElement_s;

typedef struct {
    FigureListElement_s* head;
    FigureListElement_s* tail;
} FigureList_s;

Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);

Figure_s* createFigure(Point** points, Color_s* color);
void deleteFigure(Figure_s* figure);
void drawFigure(Figure_s* figure);

FigureList_s* createFigList(void);
void deleteFigList(FigureList_s* list);
void drawFigList(FigureList_s* list);
int addFigToFigList(FigureList_s* list, Figure_s* figure);
int insertFigToFigListAtIndex(FigureList_s* list, int index, Figure_s* figure);
int removeFigFromFigListAtIndex(FigureList_s* list, int index);

#endif
