#include <GL/glut.h>

float zoom = -10.0f;

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(6.0, 5.0, 6.0, 0.0, 0.5, 0.0, 0.0, 1.0, 0.0);

    glTranslatef(0.0f, 0.0f, zoom);

    // Розміри паралелепіпеда
    float length = 4.0f;  // вздовж Z
    float width = 2.0f;   // вздовж X
    float height = 1.0f;  // вздовж Y

    float x = width / 2.0f;
    float y = height;
    float z = length / 2.0f;

    glBegin(GL_QUADS);

    // Верхня грань
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-x, y, -z);
    glVertex3f(x, y, -z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);

    // Нижня грань (центр у (0, 0, 0))
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-x, 0.0, -z);
    glVertex3f(x, 0.0, -z);
    glVertex3f(x, 0.0, z);
    glVertex3f(-x, 0.0, z);

    // Передня
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-x, 0.0, z);
    glVertex3f(x, 0.0, z);
    glVertex3f(x, y, z);
    glVertex3f(-x, y, z);

    // Задня
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-x, 0.0, -z);
    glVertex3f(x, 0.0, -z);
    glVertex3f(x, y, -z);
    glVertex3f(-x, y, -z);

    // Ліва
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-x, 0.0, -z);
    glVertex3f(-x, 0.0, z);
    glVertex3f(-x, y, z);
    glVertex3f(-x, y, -z);

    // Права
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(x, 0.0, -z);
    glVertex3f(x, 0.0, z);
    glVertex3f(x, y, z);
    glVertex3f(x, y, -z);

    glEnd();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, ratio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key, int x, int y) {
    if (key == GLUT_KEY_UP) zoom += 0.5f;
    if (key == GLUT_KEY_DOWN) zoom -= 0.5f;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Паралелепіпед — Варіант 8");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
