#include <GL/glut.h>
#include <cmath>

float zoom = 1.0f;
float translateX = 0.0f;
float translateY = 0.0f;

const float a = 0.1f;
const float b = 0.25f;
const int segments = 1000;

void drawAxes() {
    glColor3f(0.5f, 0.5f, 0.5f); // Сірий
    glBegin(GL_LINES);
        glVertex2f(-10.0f, 0.0f);
        glVertex2f(10.0f, 0.0f);
        glVertex2f(0.0f, -10.0f);
        glVertex2f(0.0f, 10.0f);
    glEnd();

    // Поділки
    for (float i = -10.0f; i <= 10.0f; i += 1.0f) {
        glBegin(GL_LINES);
            glVertex2f(i, -0.1f);
            glVertex2f(i, 0.1f);
            glVertex2f(-0.1f, i);
            glVertex2f(0.1f, i);
        glEnd();
    }
}

void drawSpiral() {
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float t = (float)i / segments * 5.0f * M_PI;
        float r = a * exp(b * t);
        float x = r * cos(t);
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glScalef(zoom, zoom, 1.0f);
    glTranslatef(translateX, translateY, 0.0f);

    drawAxes();
    drawSpiral();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int, int) {
    if (key == '+') zoom *= 1.1f;
    if (key == '-') zoom /= 1.1f;
    glutPostRedisplay();
}

void specialKeys(int key, int, int) {
    if (key == GLUT_KEY_LEFT) translateX += 0.1f;
    if (key == GLUT_KEY_RIGHT) translateX -= 0.1f;
    if (key == GLUT_KEY_UP) translateY -= 0.1f;
    if (key == GLUT_KEY_DOWN) translateY += 0.1f;
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f); // Помаранчевий фон
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Logarithmic Spiral");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
