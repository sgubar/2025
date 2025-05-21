
#include <GL/glut.h>
#include <GL/glu.h>

static float angleZ = 0.0f;

void drawCube() {
    float h = 1.0f;     
    float z0 = 0.0f;    
    float z1 = 2.0f;    

    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
      glVertex3f(-h, -h, z0);
      glVertex3f( h, -h, z0);
      glVertex3f( h,  h, z0);
      glVertex3f(-h,  h, z0);

    glColor3f(1, 0, 0);
      glVertex3f(-h, -h, z1);
      glVertex3f(-h,  h, z1);
      glVertex3f( h,  h, z1);
      glVertex3f( h, -h, z1);

    glColor3f(1, 0, 1);
      glVertex3f( h, -h, z0);
      glVertex3f( h, -h, z1);
      glVertex3f( h,  h, z1);
      glVertex3f( h,  h, z0);

    glColor3f(0, 1, 1);
      glVertex3f(-h, -h, z1);
      glVertex3f(-h, -h, z0);
      glVertex3f(-h,  h, z0);
      glVertex3f(-h,  h, z1);

    glColor3f(1, 1, 0);
      glVertex3f(-h,  h, z0);
      glVertex3f( h,  h, z0);
      glVertex3f( h,  h, z1);
      glVertex3f(-h,  h, z1);

    glColor3f(0, 1, 0);
      glVertex3f(-h, -h, z1);
      glVertex3f( h, -h, z1);
      glVertex3f( h, -h, z0);
      glVertex3f(-h, -h, z0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
      5.0, 0.0, 3.0,   
      0.0, 0.0, 1.0,   
      0.0, 0.0, 1.0    
    );

  
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

    drawCube();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    float aspect = (float)w / h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'w' || key == 'W') {
        angleZ += 5.0f;
    } else if (key == 's' || key == 'S') {
        angleZ -= 5.0f;
    } else if (key == 27) {
        exit(0);
    }
    glutPostRedisplay();
}

void initGL() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Variant 5");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
