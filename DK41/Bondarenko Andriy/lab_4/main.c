#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct Square {
    float size;
    float angle;
    float angleSpeed;
    float distance;
    struct Square* next;
    struct Square* prev;
} Square;

Square* head = NULL;
Square* tail = NULL;

void addSquare() {
    Square* sq = (Square*)malloc(sizeof(Square));
    sq->size = 30 + rand() % 40; // random size between 30 and 70
    sq->angle = 0;
    sq->angleSpeed = 0.01f + ((float)rand() / RAND_MAX) * 0.05f;
    sq->distance = 50 + rand() % 150;
    sq->next = NULL;
    sq->prev = tail;

    if (tail) {
        tail->next = sq;
    } else {
        head = sq;
    }
    tail = sq;
}

void removeLastSquare() {
    if (tail) {
        Square* toDelete = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL;
        free(toDelete);
    }
}

void drawSquare(float x, float y, float size, float angle) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle * 180.0f / 3.14159f, 0, 0, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-size/2, -size/2);
        glVertex2f(size/2, -size/2);
        glVertex2f(size/2, size/2);
        glVertex2f(-size/2, size/2);
    glEnd();
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Square* current = head;
    while (current) {
        current->angle += current->angleSpeed;
        float x = current->distance * cos(current->angle);
        float y = current->distance * sin(current->angle);
        drawSquare(x, y, current->size, current->angle);
        current = current->next;
    }

    glutSwapBuffers();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // roughly 60 FPS
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
        case 'A':
            addSquare();
            break;
        case 'd':
        case 'D':
            removeLastSquare();
            break;
        case 27: // ESC key
            exit(0);
            break;
    }
}

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WINDOW_WIDTH/2, WINDOW_WIDTH/2, -WINDOW_HEIGHT/2, WINDOW_HEIGHT/2);
    glMatrixMode(GL_MODELVIEW);
    srand(time(NULL));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Rotating Squares (OpenGL)");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
