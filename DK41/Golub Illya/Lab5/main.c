#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

char title[] = "Pyramid";
int perspective = 1; /* true */
int moveScene = 0; /* false */
int mouse_x, mouse_y;
float a_x = 0, a_y = 0;
float zoom_param = -7.0;
float zoom_delta = 0.1;

void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param);
    glRotatef(a_x, 1, 0, 0);
    glRotatef(a_y, 0, 1, 0);
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f( 1.0f, -0.5f, 1.0f);
    glVertex3f(-1.0f, -0.5f, 1.0f);
    glVertex3f(-1.0f, -0.5f, -1.0f);
    glVertex3f( 1.0f, -0.5f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -0.5f, 1.0f);
    glVertex3f( 1.0f, -0.5f, 1.0f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -0.5f, 1.0f);
    glVertex3f( 1.0f, -0.5f, -1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -0.5f, -1.0f);
    glVertex3f(-1.0f, -0.5f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -0.5f, -1.0f);
    glVertex3f(-1.0f, -0.5f, 1.0f);
    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    GLfloat aspect;
    
    if (height == 0) height = 1;
    aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'a':
        case 'A':
            zoom_param += zoom_delta;
            glutPostRedisplay();
            break;
        case 'd':
        case 'D':
            zoom_param -= zoom_delta;
            glutPostRedisplay();
            break;
    }
}

void mouseClick(int button, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN) {
        moveScene = 1; /* true */
        mouse_x = x;
        mouse_y = y;
    }

    if (GLUT_LEFT_BUTTON == button && state == GLUT_UP) {
        moveScene = 0; /* false */
    }
}

void specKeyHandler(int sk, int x, int y)
{
    if (sk == GLUT_KEY_UP) {
        zoom_param += zoom_delta;
    }
    else if (sk == GLUT_KEY_DOWN) {
        zoom_param -= zoom_delta;
    }
}

void mouseMove(int x, int y)
{
    int dx, dy;
    
    dx = mouse_x - x;
    dy = mouse_y - y;
    a_x -= 0.250f * dy;
    a_y -= 0.250f * dx;
    mouse_x = x;
    mouse_y = y;
}

void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMove);
    glutSpecialFunc(specKeyHandler);
    glutTimerFunc(0, Timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}