// main.c
#include <GL/freeglut.h>
#include <stdlib.h>

// Вузол двозв’язного списку
typedef struct Node {
    float size, angle;
    struct Node *prev, *next;
} Node;

static Node *head = NULL, *tail = NULL;

Node* create_node(float s) {
    Node *n = malloc(sizeof(Node));
    if (!n) exit(EXIT_FAILURE);
    n->size  = s;
    n->angle = 0.0f;
    n->prev = n->next = NULL;
    return n;
}

void append_node(Node *n) {
    if (!head) head = tail = n;
    else {
        tail->next = n;
        n->prev    = tail;
        tail       = n;
    }
}

void delete_node(Node *n) {
    if (!n) return;
    if (n->prev) n->prev->next = n->next;
    else         head          = n->next;
    if (n->next) n->next->prev = n->prev;
    else         tail          = n->prev;
    free(n);
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
      glVertex2f(0.0f, 0.0f);
      glVertex2f(1.0f, 0.0f);
      glVertex2f(0.0f, 1.0f);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (Node *cur = head; cur; cur = cur->next) {
        glPushMatrix();
          glRotatef(cur->angle, 0.0f, 0.0f, 1.0f);
          glScalef(cur->size, cur->size, 1.0f);
          drawTriangle();
        glPopMatrix();
    }
    glutSwapBuffers();
}

void timerFunc(int) {
    for (Node *cur = head; cur; cur = cur->next) {
        cur->angle += 1.0f;
        if (cur->angle >= 360.0f) cur->angle -= 360.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timerFunc, 0);
}

int main(int argc, char **argv) {
    append_node(create_node(0.3f));
    append_node(create_node(0.5f));
    append_node(create_node(0.7f));
    delete_node(head->next);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D OpenGL + List");

    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutTimerFunc(0, timerFunc, 0);
    glutMainLoop();
    return 0;
}
