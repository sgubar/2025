#include <GL/glut.h>
#include <math.h>

const float a = 2.0f;

float zoom = 1.0f;
float panX = 0.0f;
float panY = 0.0f;

void drawAxes() {
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, 10.0f);
    glEnd();

    for (float x = -10.0f; x <= 10.0f; x += 1.0f) {
        glBegin(GL_LINES);
        glVertex2f(x, -0.1f);
        glVertex2f(x, 0.1f);
        glEnd();
    }

    for (float y = -10.0f; y <= 10.0f; y += 1.0f) {
        glBegin(GL_LINES);
        glVertex2f(-0.1f, y);
        glVertex2f(0.1f, y);
        glEnd();
    }
}

void drawCurve() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    for (float t = -M_PI + 0.01f; t <= M_PI; t += 0.01f) {
        float sin_t = sin(t);
        float cos_t = cos(t);
        float denom = 1.0f + sin_t * sin_t;

        if (fabs(denom) > 0.001f) {
            float factor = a * sqrt(2.0f);
            float x = factor * cos_t / denom;
            float y = factor * cos_t * sin_t / denom;

            if (fabs(x) < 10.0f && fabs(y) < 10.0f)
                glVertex2f(x, y);
        }
    }
    glEnd();
}

void display() {
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glScalef(zoom, zoom, 1.0f);
    glTranslatef(panX, panY, 0.0f);

    drawAxes();
    drawCurve();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)width / (float)height;
    if (width >= height) {
        glOrtho(-5.0 * aspect, 5.0 * aspect, -5.0, 5.0, -1.0, 1.0);
    } else {
        glOrtho(-5.0, 5.0, -5.0 / aspect, 5.0 / aspect, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
        case '=': zoom *= 1.1f; break;
        case '-':
        case '_': zoom *= 0.9f; break;
        case 'w': panY -= 0.1f / zoom; break;
        case 's': panY += 0.1f / zoom; break;
        case 'a': panX += 0.1f / zoom; break;
        case 'd': panX -= 0.1f / zoom; break;
        case 'r': zoom = 1.0f; panX = 0.0f; panY = 0.0f; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:    panY -= 0.1f / zoom; break;
        case GLUT_KEY_DOWN:  panY += 0.1f / zoom; break;
        case GLUT_KEY_LEFT:  panX += 0.1f / zoom; break;
        case GLUT_KEY_RIGHT: panX -= 0.1f / zoom; break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Параметричний графік (варіант 6)");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
