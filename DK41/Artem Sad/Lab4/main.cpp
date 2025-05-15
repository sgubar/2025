#include <GL/glut.h>
#include <list>
#include <cmath>

using namespace std;

struct Shape {
    float x, y;
    float width, height;
    float angle;
    float rotationSpeed;
    float r, g, b;
};

list<Shape> shapes;
float globalRotation = 0.0f;
bool rotating = false;
int lastY = 0;

void drawRectangle(const Shape& rect) {
    glPushMatrix();
    glTranslatef(rect.x, rect.y, 0.0f);
    glRotatef(rect.angle, 0.0f, 0.0f, 1.0f);
    
    glColor3f(rect.r, rect.g, rect.b);
    glBegin(GL_QUADS);
        glVertex2f(-rect.width/2, -rect.height/2);
        glVertex2f(rect.width/2, -rect.height/2);
        glVertex2f(rect.width/2, rect.height/2);
        glVertex2f(-rect.width/2, rect.height/2);
    glEnd();
    
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glRotatef(globalRotation, 0.0f, 1.0f, 0.0f);
    
    for (list<Shape>::const_iterator it = shapes.begin(); it != shapes.end(); ++it) {
        drawRectangle(*it);
    }
    
    glPopMatrix();
    glutSwapBuffers();
}

void update(int value) {
    for (list<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it) {
        it->angle += it->rotationSpeed;
        if (it->angle > 360.0f) it->angle -= 360.0f;
    }
    
    if (rotating) {
        globalRotation += 1.0f;
        if (globalRotation > 360.0f) globalRotation -= 360.0f;
    }
    
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void mouse(int button, int state, int x, int y) {
    if (button == 3 || button == 4) {
        if (button == 3) {
            globalRotation += 5.0f;
        } else {
            globalRotation -= 5.0f;
        }
        glutPostRedisplay();
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Shape newRect;
        newRect.x = (x - 250) / 250.0f;
        newRect.y = (250 - y) / 250.0f;
        newRect.width = 0.2f;
        newRect.height = 0.1f;
        newRect.angle = 0.0f;
        newRect.rotationSpeed = 1.0f + (rand() % 5);
        newRect.r = (rand() % 100) / 100.0f;
        newRect.g = (rand() % 100) / 100.0f;
        newRect.b = (rand() % 100) / 100.0f;
        
        shapes.push_back(newRect);
    } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        if (!shapes.empty()) {
            shapes.pop_back();
        }
    }
}

void motion(int x, int y) {
    int deltaY = y - lastY;
    globalRotation += deltaY * 0.5f;
    lastY = y;
    glutPostRedisplay();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    
    Shape rect1 = {0.0f, 0.0f, 0.4f, 0.2f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f};
    Shape rect2 = {-0.5f, 0.5f, 0.3f, 0.15f, 0.0f, 3.0f, 0.0f, 1.0f, 0.0f};
    Shape rect3 = {0.5f, -0.5f, 0.25f, 0.1f, 0.0f, 1.5f, 0.0f, 0.0f, 1.0f};
    
    shapes.push_back(rect1);
    shapes.push_back(rect2);
    shapes.push_back(rect3);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Graphics with OpenGL and Lists");
    
    init();
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(0, update, 0);
    
    glutMainLoop();
    return 0;
}
