#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define POINTS_PER_FIGURE 4

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    float r;
    float g;
    float b;
} Color;

typedef struct {
    Point* points[POINTS_PER_FIGURE];
    Color* color;
} Figure;

typedef struct FigureListElement {
    struct FigureListElement* prev;
    struct FigureListElement* next;
    Figure* figure;
} FigureListElement;

typedef struct {
    FigureListElement* head;
    FigureListElement* tail;
} FigureList;

FigureList* mainFigureList;
const char* windowTitle = "Rect";
const int windowWidth = 700;
const int windowHeight = 700;
float rotationAngle = 0.0f;


Point* createPoint(int x, int y) {
    Point* p = (Point*)malloc(sizeof(Point));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}


void deletePoint(Point* p) {
    if (p != NULL) {
        free(p);
    }
}


Color* createColor(float r, float g, float b) {
    Color* c = (Color*)malloc(sizeof(Color));
    if (c != NULL) {
        c->r = r;
        c->g = g;
        c->b = b;
    }
    return c;
}


void deleteColor(Color* c) {
    if (c != NULL) {
        free(c);
    }
}


Figure* createFigure(Point** points, Color* color) {
    Figure* fig = (Figure*)malloc(sizeof(Figure));
    if (fig != NULL) {
        for (int i = 0; i < POINTS_PER_FIGURE; i++) {
            fig->points[i] = points[i];
        }
        fig->color = color;
    }
    return fig;
}


void deleteFigure(Figure* fig) {
    if (fig != NULL) {
        for (int i = 0; i < POINTS_PER_FIGURE; i++) {
            deletePoint(fig->points[i]);
        }
        deleteColor(fig->color);
        free(fig);
    }
}


FigureListElement* createListElement(Figure* fig) {
    FigureListElement* elem = (FigureListElement*)malloc(sizeof(FigureListElement));
    if (elem != NULL) {
        elem->figure = fig;
        elem->next = NULL;
        elem->prev = NULL;
    }
    return elem;
}


void deleteListElement(FigureListElement* elem) {
    if (elem != NULL) {
        deleteFigure(elem->figure);
        free(elem);
    }
}


FigureList* createFigureList() {
    FigureList* list = (FigureList*)malloc(sizeof(FigureList));
    if (list != NULL) {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}


void addFigureToList(FigureList* list, Figure* fig) {
    if (list == NULL) return;
    FigureListElement* newElement = createListElement(fig);
    if (newElement == NULL) return;

    if (list->head == NULL) {
        list->head = newElement;
        list->tail = newElement;
    } else {
        list->tail->next = newElement;
        newElement->prev = list->tail;
        list->tail = newElement;
    }
}


void drawFigure(Figure* fig) {
    if (fig == NULL) return;

    glBegin(GL_QUADS);
    glColor3f(fig->color->r, fig->color->g, fig->color->b);
    for (int i = 0; i < POINTS_PER_FIGURE; i++) {
        glVertex2f(fig->points[i]->x / 100.0f, fig->points[i]->y / 100.0f);
    }
    glEnd();
}


void drawFigureList(FigureList* list) {
    if (list == NULL) return;
    for (FigureListElement* current = list->head; current != NULL; current = current->next) {
        drawFigure(current->figure);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
    drawFigureList(mainFigureList);
    glPopMatrix();

    glutSwapBuffers();
}

void timer(int value) {
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f) {
        rotationAngle -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    mainFigureList = createFigureList();


    Point* rect1_pts[POINTS_PER_FIGURE];
    rect1_pts[0] = createPoint(15, 20);
    rect1_pts[1] = createPoint(30, 20);
    rect1_pts[2] = createPoint(30, 60);
    rect1_pts[3] = createPoint(15, 60);
    addFigureToList(mainFigureList, createFigure(rect1_pts, createColor(1.0f, 0.2f, 0.2f)));

    Point* rect2_pts[POINTS_PER_FIGURE];
    rect2_pts[0] = createPoint(-60, -50);
    rect2_pts[1] = createPoint(-20, -50);
    rect2_pts[2] = createPoint(-20, -40);
    rect2_pts[3] = createPoint(-60, -40);
    addFigureToList(mainFigureList, createFigure(rect2_pts, createColor(0.2f, 1.0f, 0.2f)));

    Point* rect3_pts[POINTS_PER_FIGURE];
    rect3_pts[0] = createPoint(-55, 10);
    rect3_pts[1] = createPoint(-25, 10);
    rect3_pts[2] = createPoint(-25, 40);
    rect3_pts[3] = createPoint(-55, 40);
    addFigureToList(mainFigureList, createFigure(rect3_pts, createColor(0.2f, 0.2f, 1.0f)));

    Point* rect4_pts[POINTS_PER_FIGURE];
    rect4_pts[0] = createPoint(40, -30);
    rect4_pts[1] = createPoint(65, -30);
    rect4_pts[2] = createPoint(65, -15);
    rect4_pts[3] = createPoint(40, -15);
    addFigureToList(mainFigureList, createFigure(rect4_pts, createColor(1.0f, 1.0f, 0.2f)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(windowTitle);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
