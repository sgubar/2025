#include <GL/freeglut.h>
#include <cmath>
#include <vector>

// Номер варіанту 7

const float PI = 3.14159265358979323846;
const float BASE_RADIUS = 1.0;
const float PRISM_HEIGHT = 2.0;

float rotationAngle = 0.0;

GLfloat baseVertices[6][3];
GLfloat topVertices[6][3];

void calculateVertices() {
    for (int i = 0; i < 6; ++i) {
        float angle = i * 2.0 * PI / 6.0;
        baseVertices[i][0] = BASE_RADIUS * cos(angle);
        baseVertices[i][1] = BASE_RADIUS * sin(angle);
        baseVertices[i][2] = 0.0;

        topVertices[i][0] = BASE_RADIUS * cos(angle);
        topVertices[i][1] = BASE_RADIUS * sin(angle);
        topVertices[i][2] = PRISM_HEIGHT;
    }
}

void drawPrism() {
    GLfloat colors[8][3] = {
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 1.0, 0.0},
        {1.0, 0.0, 1.0},
        {0.0, 1.0, 1.0},
        {1.0, 0.5, 0.0},
        {0.5, 0.0, 1.0}
    };

    glColor3fv(colors[6]);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        glVertex3fv(baseVertices[i]);
    }
    glEnd();

    glColor3fv(colors[7]);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i) {
        glVertex3fv(topVertices[i]);
    }
    glEnd();

    for (int i = 0; i < 6; ++i) {
        int next_i = (i + 1) % 6;
        glColor3fv(colors[i]);
        glBegin(GL_QUADS);
        glVertex3fv(baseVertices[i]);
        glVertex3fv(baseVertices[next_i]);
        glVertex3fv(topVertices[next_i]);
        glVertex3fv(topVertices[i]);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);

    glRotatef(rotationAngle, 1.0, 0.0, 0.0);

    drawPrism();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (double)w / (double)h, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idle() {
    rotationAngle += 0.1;

    if (rotationAngle > 360.0) {
        rotationAngle -= 360.0;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    calculateVertices();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Hexagonal Prism (Variant 5)");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}
