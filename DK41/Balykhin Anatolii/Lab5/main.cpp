#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdbool.h>

char window_title[] = "Pyramid";
bool is_rotating = false;
int mouse_pos_x, mouse_pos_y;
float rotation_x = 20.0f;
float rotation_y = 0.0f;
float zoom_level = -8.0f;
float zoom_step = 0.15f;

void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void displayScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, zoom_level);
    glRotatef(rotation_x, 1.0f, 0.0f, 0.0f);
    glRotatef(rotation_y, 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.0f, 0.5f);
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f,  1.0f);
        glVertex3f( 1.0f, 0.0f,  1.0f);
        glVertex3f( 1.0f, 0.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, 0.0f, 1.0f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( 1.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, 0.0f, -1.0f);

        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f( 1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f, -1.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f( 0.0f, 1.5f, 0.0f);
        glVertex3f(-1.0f, 0.0f, -1.0f);
        glVertex3f(-1.0f, 0.0f, 1.0f);
    glEnd();
    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    if (height == 0) height = 1;
    float aspect_ratio = (float)width / (float)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect_ratio, 0.1f, 100.0f);
}

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            is_rotating = true;
            mouse_pos_x = x;
            mouse_pos_y = y;
        } else if (state == GLUT_UP) {
            is_rotating = false;
        }
    }
}

void handleMouseMove(int x, int y) {
    if (is_rotating) {
        float dx = (float)(x - mouse_pos_x);
        float dy = (float)(y - mouse_pos_y);
        rotation_y += dx * 0.25f;
        rotation_x += dy * 0.25f;
        mouse_pos_x = x;
        mouse_pos_y = y;
        glutPostRedisplay();
    }
}

void handleSpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            zoom_level += zoom_step;
            break;
        case GLUT_KEY_LEFT:
            zoom_level -= zoom_step;
            break;
    }
    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(window_title);
    glutDisplayFunc(displayScene);
    glutReshapeFunc(reshapeWindow);
    glutMouseFunc(handleMouseClick);
    glutMotionFunc(handleMouseMove);
    glutSpecialFunc(handleSpecialKeys);
    glutKeyboardFunc(handleKeyboard);
    initOpenGL();
    glutMainLoop();

    return 0;
}
