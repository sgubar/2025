#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float scale = 1.0f;
float offsetX = 0.0f;
float offsetY = 0.0f;

void keyboard(unsigned char key, int x, int y);
void specialKeys(int key, int x, int y);

void display()
{
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f); // Білий колір
        glVertex2f(0.0, -1.0); // Вісь Y
        glVertex2f(0.0, 1.0);
        glVertex2f(-1.0, 0.0); // Вісь X
        glVertex2f(1.0, 0.0);
    glEnd();

    for(float i = -1.0; i <= 1.0; i += 0.1){
        glBegin(GL_LINES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex2f(i, -0.03); glVertex2f(i, 0.03);
            glVertex2f(-0.03, i); glVertex2f(0.03, i);
        glEnd();
    }

    glLoadIdentity();
    glTranslatef(offsetX, offsetY, 0.0f);
    glScalef(scale, scale, 1.0f);
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 1.0f);
        const float a = 0.6f;
        const float b = 0.3f;

        for (float t = -M_PI; t <= M_PI; t += 0.01) {
            float x = a * cos(t) * cos(t) - b * cos(t);
            float y = a * sin(t) * cos(t) - b * cos(t);
            glVertex2f(x, y);
        }
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            scale *= 1.1f;
            break;
        case '-':
            scale /= 1.1f;
            break;
        case 'r':
        case 'R':
            scale = 1.0f;
            offsetX = 0.0f;
            offsetY = 0.0f;
            break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    float moveSpeed = 0.1f / scale;

    switch (key) {
        case GLUT_KEY_UP:
            offsetY += moveSpeed;
            break;
        case GLUT_KEY_DOWN:
            offsetY -= moveSpeed;
            break;
        case GLUT_KEY_LEFT:
            offsetX -= moveSpeed;
            break;
        case GLUT_KEY_RIGHT:
            offsetX += moveSpeed;
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Graph");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
