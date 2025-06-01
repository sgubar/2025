// Варіант 13

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

void display()
{
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f); 
        for (float t = -M_PI; t <= M_PI; t += 0.01) {
            float x = cos(t);
            float y = sin(t);
            glVertex2f(x, y);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    for(float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for(float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Графік Функції");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
