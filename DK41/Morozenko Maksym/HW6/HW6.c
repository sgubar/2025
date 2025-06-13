#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265359

void drawAxes() {
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений
    glBegin(GL_LINES);
    // Вісь X
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    // Вісь Y
    glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, 10.0f);
    glEnd();

    // Поділки
    glBegin(GL_LINES);
    for (int i = -10; i <= 10; ++i) {
        glVertex2f(i, -0.1f);
        glVertex2f(i, 0.1f);
        glVertex2f(-0.1f, i);
        glVertex2f(0.1f, i);
    }
    glEnd();
}

void drawGraph() {
    glColor3f(0.0f, 0.0f, 0.0f); // Чорний
    glBegin(GL_LINE_STRIP);
    for (float t = 0.01f; t <= 4 * PI; t += 0.01f) {
        float r = 2.0f + cos(2.5f * t); // 2 + cos(5/2 * t)
        float x = r * cos(t);
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxes();
    drawGraph();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Білий фон
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // Область виводу
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Графік функції (варіант 8)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
