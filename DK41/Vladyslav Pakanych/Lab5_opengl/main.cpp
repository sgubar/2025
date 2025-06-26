#include <GL/freeglut.h>
#include <cmath>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Лабораторна робота 3D-призма з правильною трикутною основою
// Студент: Владислав Паканич
// Варіант 10

char title[] = "Призма з правильною трикутною основою (Варіант 10)";
float angleY = 0.0f; // кут обертання навколо осі Oy

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void drawTriangularPrism() {
    const float R = 1.0f;      // радіус описаного кола основи
    const float height = 2.0f; // висота призми
    const float angleStep = 2.0f * M_PI / 3.0f;

    GLfloat base[3][3];
    GLfloat top[3][3];
    for (int i = 0; i < 3; ++i) {
        float ang = i * angleStep;
        base[i][0] = R * cos(ang);
        base[i][1] = 0.0f;
        base[i][2] = R * sin(ang);
        top[i][0] = base[i][0];
        top[i][1] = height;
        top[i][2] = base[i][2];
    }

    // Нижня основа (трикутник)
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        for (int i = 0; i < 3; ++i) glVertex3fv(base[i]);
    glEnd();

    // Верхня основа (трикутник)
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        for (int i = 2; i >= 0; --i) glVertex3fv(top[i]);
    glEnd();

    // Бокові грані (3 квадрати)
    glBegin(GL_QUADS);
    for (int i = 0; i < 3; ++i) {
        int next = (i + 1) % 3;
        // кольори: червоний, зелений, синій
        glColor3f(i == 0, i == 1, i == 2);
        glVertex3fv(base[i]);
        glVertex3fv(base[next]);
        glVertex3fv(top[next]);
        glVertex3fv(top[i]);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, -1.0f, -6.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    drawTriangularPrism();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / (float)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void timer(int value) {
    angleY += 0.7f;
    if (angleY > 360.0f) angleY -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}
