#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "pentagon.h"
#include "List.h"

using namespace std;

const float ROTATION_SPEED = 0.05f;
float angle = 0.0f;
SquareList squares;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    squares.drawAll();
    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    angle += ROTATION_SPEED;
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void initOpenGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100.0f, 100.0f, -100.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    squares.addSquare({0, 0, 30});
    squares.addSquare({50, 50, 20});
    squares.addSquare({-50, -50, 25});
    squares.addSquare({30, -30, 15});
    squares.addSquare({-30, 30, 35});

    squares.sortBeforeMax();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Square List OpenGL");
    initOpenGL();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}
