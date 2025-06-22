#include "figure.h"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

Color_s* createColor(float R, float G, float B) {
    Color_s* color = (Color_s*)malloc(sizeof(Color_s));
    if (color != NULL) {
        color->R = R;
        color->G = G;
        color->B = B;
    }
    return color;
}

void deleteColor(Color_s* color) {
    if (NULL != color) {
        free(color);
    }
}

Figure_s* createFigure(Point** points, Color_s* color) {
    Figure_s* figure = (Figure_s*)malloc(sizeof(Figure_s));
    if (figure != NULL) {
        for (int i = 0; i < PT_NUM; i++) {
            figure->points[i] = points[i];
        }
        figure->color = color;
    }
    return figure;
}

void deleteFigure(Figure_s* figure) {
    if (NULL != figure) {
        for (int i = 0; i < PT_NUM; i++) {
            deletePoint(figure->points[i]);
        }
        deleteColor(figure->color);
        free(figure);
    }
}

void drawFigure(Figure_s* figure) {
    if (NULL == figure) return;

    glBegin(GL_TRIANGLES);
    glColor3f(figure->color->R, figure->color->G, figure->color->B);
    for (int i = 0; i < PT_NUM; i++) {
        glVertex2f(figure->points[i]->x / 100.0f, figure->points[i]->y / 100.0f);
    }
    glEnd();
}

FigureListElement_s* createListElement(Figure_s* figure) {
    FigureListElement_s* result = (FigureListElement_s*)malloc(sizeof(FigureListElement_s));
    if (NULL != result) {
        result->figure = figure;
        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void deleteListElement(FigureListElement_s* listElement) {
    if (NULL != listElement) {
        deleteFigure(listElement->figure);
        free(listElement);
    }
}

FigureList_s* createFigList(void) {
    FigureList_s* result = (FigureList_s*)malloc(sizeof(FigureList_s));
    if (NULL != result) {
        result->head = NULL;
        result->tail = NULL;
    }
    return result;
}

void deleteFigList(FigureList_s* list) {
    if (NULL == list) {
        return;
    }

    FigureListElement_s* element = list->head;
    while (NULL != element) {
        FigureListElement_s* tmp = element->next;
        deleteListElement(element);
        element = tmp;
    }
    free(list);
}

void drawFigList(FigureList_s* list) {
    if (NULL == list) {
        printf("Помилка: недійсний вказівник на список\n");
        return;
    }

    for (FigureListElement_s* element = list->head; element != NULL; element = element->next) {
        drawFigure(element->figure);
    }
}

long countOfFigList(FigureList_s* list) {
    if (NULL == list) {
        return 0;
    }
    long count = 0;
    for (FigureListElement_s* element = list->head; element != NULL; element = element->next, count++);
    return count;
}

int addFigToFigList(FigureList_s* list, Figure_s* figure) {
    if (NULL == list) return 0;

    FigureListElement_s* element = createListElement(figure);
    if (NULL == element) return 0;

    if (NULL == list->head) {
        list->head = element;
        list->tail = element;
    }
    else {
        list->tail->next = element;
        element->prev = list->tail;
        list->tail = element;
    }
    return 1;
}

void removeLastElementFromFigList(FigureList_s* list) {
    if (NULL == list || NULL == list->tail) return;

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    FigureListElement_s* toDelete = list->tail;
    list->tail = toDelete->prev;
    list->tail->next = NULL;
    deleteListElement(toDelete);
}

void removeFirstElementFromFigList(FigureList_s* list) {
    if (NULL == list || NULL == list->head) return;

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    FigureListElement_s* toDelete = list->head;
    list->head = toDelete->next;
    list->head->prev = NULL;
    deleteListElement(toDelete);
}

int removeFigFromFigListAtIndex(FigureList_s* list, int index) {
    if (NULL == list) return 0;
    long count = countOfFigList(list);
    if (index < 0 || index >= count) return 0;

    if (index == 0) {
        removeFirstElementFromFigList(list);
        return 1;
    }
    if (index == count - 1) {
        removeLastElementFromFigList(list);
        return 1;
    }

    int current = 0;
    FigureListElement_s* element = list->head;
    while (current != index) {
        element = element->next;
        current++;
    }

    element->prev->next = element->next;
    element->next->prev = element->prev;
    deleteListElement(element);
    return 1;
}

int insertFigToFigListAtIndex(FigureList_s* list, int index, Figure_s* figure) {
    if (NULL == list) return 0;
    long count = countOfFigList(list);
    if (index < 0 || index > count) return 0;

    if (index == count) {
        return addFigToFigList(list, figure);
    }

    FigureListElement_s* newElement = createListElement(figure);
    if (NULL == newElement) return 0;

    if (index == 0) {
        newElement->next = list->head;
        list->head->prev = newElement;
        list->head = newElement;
    }
    else {
        int current = 0;
        FigureListElement_s* element = list->head;
        while (current != index) {
            element = element->next;
            current++;
        }
        newElement->next = element;
        newElement->prev = element->prev;
        element->prev->next = newElement;
        element->prev = newElement;
    }
    return 1;
}
