#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum { TRIANGLE, SQUARE } ShapeType;

typedef struct Figure {
    ShapeType type;
    float r, g, b;
    float size;
    float angle;
    float speed;
    struct Figure* next;
} Figure;

Figure* head = NULL;
int figureCount = 0;

// Створення нової фігури
Figure* createFigure(ShapeType type) {
    Figure* f = (Figure*)malloc(sizeof(Figure));
    if (!f) return NULL;
    f->type = type;
    f->r = (float)rand() / RAND_MAX;
    f->g = (float)rand() / RAND_MAX;
    f->b = (float)rand() / RAND_MAX;
    f->size = 0.2f + (float)rand() / RAND_MAX * 0.2f;
    f->angle = 0.0f;
    f->speed = 0.5f + (float)rand() / RAND_MAX * 1.5f;
    f->next = NULL;
    return f;
}

// Додавання фігури у кінець списку
void addFigureEnd(ShapeType type) {
    Figure* newFig = createFigure(type);
    if (!newFig) return;
    if (!head) {
        head = newFig;
    } else {
        Figure* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newFig;
    }
    figureCount++;
}

// Вставка фігури у позицію index (0-based)
void insertFigureAt(ShapeType type, int index) {
    if (index < 0 || index > figureCount) return;
    Figure* newFig = createFigure(type);
    if (!newFig) return;

    if (index == 0) {
        newFig->next = head;
        head = newFig;
    } else {
        Figure* curr = head;
        for (int i = 0; i < index -1; i++) {
            curr = curr->next;
        }
        newFig->next = curr->next;
        curr->next = newFig;
    }
    figureCount++;
}

// Видалення фігури за індексом
void removeFigureAt(int index) {
    if (index < 0 || index >= figureCount || !head) return;
    Figure* toDelete = NULL;
    if (index == 0) {
        toDelete = head;
        head = head->next;
    } else {
        Figure* curr = head;
        for (int i = 0; i < index -1; i++) {
            curr = curr->next;
        }
        toDelete = curr->next;
        curr->next = toDelete->next;
    }
    free(toDelete);
    figureCount--;
}

// Малювання фігури
void drawFigure(Figure* f) {
    glColor3f(f->r, f->g, f->b);
    glPushMatrix();
    glRotatef(f->angle, 0,0,1);
    switch(f->type) {
        case TRIANGLE:
            glBegin(GL_TRIANGLES);
            glVertex2f(0.0f, f->size);
            glVertex2f(-f->size, -f->size);
            glVertex2f(f->size, -f->size);
            glEnd();
            break;
        case SQUARE:
            glBegin(GL_QUADS);
            glVertex2f(-f->size, -f->size);
            glVertex2f(f->size, -f->size);
            glVertex2f(f->size, f->size);
            glVertex2f(-f->size, f->size);
            glEnd();
            break;
    }
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    Figure* curr = head;
    while (curr) {
        drawFigure(curr);
        curr = curr->next;
    }
    glutSwapBuffers();
}

void idle() {
    Figure* curr = head;
    while (curr) {
        curr->angle += curr->speed;
        if (curr->angle > 360.0f) curr->angle -= 360.0f;
        curr = curr->next;
    }
    glutPostRedisplay();
}

// Простий обробник клавіш:
// '1' — додати трикутник в кінець
// '2' — додати квадрат в кінець
// 'i' — вставити трикутник в позицію 0 (для прикладу)
// 'd' — видалити перший елемент (індекс 0)
// ESC — вихід
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case '1':
            addFigureEnd(TRIANGLE);
            break;
        case '2':
            addFigureEnd(SQUARE);
            break;
        case 'i':
            insertFigureAt(TRIANGLE, 0);
            break;
        case 'd':
            removeFigureAt(0);
            break;
        case 27:
            exit(0);
            break;
    }
}

void init() {
    glClearColor(0.2,0.2,0.2,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Список 2D фігур з обертанням");

    init();

    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
