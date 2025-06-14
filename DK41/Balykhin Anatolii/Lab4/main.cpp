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
const char* windowTitle = "Rectangles";
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

long getListCount(FigureList* list) {
    if (list == NULL) return 0;
    long count = 0;
    for (FigureListElement* current = list->head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

void removeFigureFromList(FigureList* list, int index) {
    if (list == NULL || list->head == NULL || index < 0 || index >= getListCount(list)) {
        return;
    }

    FigureListElement* toDelete = list->head;
    for (int i = 0; i < index; ++i) {
        toDelete = toDelete->next;
    }

    if (toDelete == list->head) list->head = toDelete->next;
    if (toDelete == list->tail) list->tail = toDelete->prev;
    if (toDelete->prev != NULL) toDelete->prev->next = toDelete->next;
    if (toDelete->next != NULL) toDelete->next->prev = toDelete->prev;

    deleteListElement(toDelete);
}

void insertFigureInList(FigureList* list, int index, Figure* fig) {
    long count = getListCount(list);
    if (list == NULL || index < 0 || index > count) return;

    if (index == count) {
        addFigureToList(list, fig);
        return;
    }

    FigureListElement* newElement = createListElement(fig);
    if (newElement == NULL) return;

    if (index == 0) {
        newElement->next = list->head;
        if (list->head != NULL) list->head->prev = newElement;
        list->head = newElement;
        if (list->tail == NULL) list->tail = newElement;
    } else {
        FigureListElement* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newElement->next = current;
        newElement->prev = current->prev;
        if (current->prev != NULL) current->prev->next = newElement;
        current->prev = newElement;
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

    Point* pts1[4], *pts2[4], *pts3[4], *pts4[4], *pts5[4];
    pts1[0] = createPoint(15, 20); pts1[1] = createPoint(30, 20); pts1[2] = createPoint(30, 60); pts1[3] = createPoint(15, 60);
    pts2[0] = createPoint(-60, -50); pts2[1] = createPoint(-20, -50); pts2[2] = createPoint(-20, -40); pts2[3] = createPoint(-60, -40);
    pts3[0] = createPoint(-55, 10); pts3[1] = createPoint(-25, 10); pts3[2] = createPoint(-25, 40); pts3[3] = createPoint(-55, 40);
    pts4[0] = createPoint(40, -30); pts4[1] = createPoint(65, -30); pts4[2] = createPoint(65, -15); pts4[3] = createPoint(40, -15);
    pts5[0] = createPoint(-60, -10); pts5[1] = createPoint(-40, -10); pts5[2] = createPoint(-40, 10); pts5[3] = createPoint(-60, 10);

    addFigureToList(mainFigureList, createFigure(pts1, createColor(1.0, 0.2, 0.2)));
    addFigureToList(mainFigureList, createFigure(pts2, createColor(0.2, 1.0, 0.2)));
    addFigureToList(mainFigureList, createFigure(pts3, createColor(0.2, 0.2, 1.0)));
    addFigureToList(mainFigureList, createFigure(pts4, createColor(1.0, 1.0, 0.2)));
    addFigureToList(mainFigureList, createFigure(pts5, createColor(1.0, 0.2, 1.0)));

    printf("1.Creating 5 rectangles.\n");
    printf("Number of elements: %ld\n\n", getListCount(mainFigureList));

    printf("2.Removing an element with an index 2.\n");
    removeFigureFromList(mainFigureList, 2);
    printf("Number of elements: %ld\n\n", getListCount(mainFigureList));

    Point* pts6[4];
    pts6[0] = createPoint(0, -50); pts6[1] = createPoint(30, -50); pts6[2] = createPoint(30, -30); pts6[3] = createPoint(0, -30);

    printf("3. Add a new (cyan) element to the position with index 1.\n");
    insertFigureInList(mainFigureList, 1, createFigure(pts6, createColor(0.2, 1.0, 1.0)));
    printf("Final number of elements: %ld\n\n", getListCount(mainFigureList));

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
