#include <GL/glut.h>
#include <iostream>
#include "figure.h"

char title[] = "Lab 2: OpenGL 2D Graphics with Lists";
int window_width = 600;
int window_height = 600;

float theta = 0.0f;
float theta_speed = 0.5f;
int timer_interval = 16;

FigureList_s* figlist;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);
    drawFigList(figlist);
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int value) {
    theta += theta_speed;
    if (theta > 360.0f) {
        theta -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(timer_interval, timer, 0);
}

void initGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void setupScene() {
    figlist = createFigList();
    std::cout << "Створено порожній список фігур." << std::endl;

    Point* points1[PT_NUM] = { createPoint(0, 50), createPoint(-43.3, -25), createPoint(43.3, -25) };
    Figure_s* figure1 = createFigure(points1, createColor(1.0, 0.0, 0.0));
    addFigToFigList(figlist, figure1);

    Point* points2[PT_NUM] = { createPoint(0, -30), createPoint(26, -75), createPoint(-26, -75) };
    Figure_s* figure2 = createFigure(points2, createColor(0.0, 1.0, 0.0));
    addFigToFigList(figlist, figure2);

    Point* points3[PT_NUM] = { createPoint(60, 60), createPoint(80, 40), createPoint(40, 40) };
    Figure_s* figure3 = createFigure(points3, createColor(1.0, 1.0, 0.0));
    addFigToFigList(figlist, figure3);
    std::cout << "Додано 3 трикутники до списку." << std::endl;

    std::cout << "Видаляємо другий елемент (з індексом 1)." << std::endl;
    removeFigFromFigListAtIndex(figlist, 1);

    Point* points4[PT_NUM] = { createPoint(-50, 0), createPoint(-30, 34.6), createPoint(-70, 34.6) };
    Figure_s* figure4 = createFigure(points4, createColor(0.0, 0.0, 1.0));

    std::cout << "Вставляємо новий (синій) трикутник на місце видаленого (індекс 1)." << std::endl;
    insertFigToFigListAtIndex(figlist, 1, figure4);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(title);

    setupScene();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    initGL();

    glutMainLoop();

    deleteFigList(figlist);

    return 0;
}
