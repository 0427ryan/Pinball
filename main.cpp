#include "Include/glut.h"
#include <iostream>
#include "Board.h"

using namespace std;

GLuint window;

float vertexs[][6] = {
    {-1.0,-1.0,-1.0, 0.0, 0.0, 0.0}, {1.0, -1.0, -1.0, 1, 0, 0}, {1.0, 1.0, -1.0, 1, 1, 0}, {-1.0, 1.0, -1.0, 0, 1, 0},
    {-1.0, -1.0, 1.0, 0.0, 0.0, 1.0}, {1.0, -1.0, 1.0, 1, 0, 1}, {1.0, 1.0, 1.0, 1, 1, 1}, {-1.0, 1.0, 1.0, 0, 1, 1}
};

void init(void);
void display(void);
void update(int);
void onKeyPressed(unsigned char, int, int);
void onKeyReleased(unsigned char, int, int);

Board* b = new Board();

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    init();
    glutMainLoop();
    return 0;
}
void init() {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(512, 512);

    glutCreateWindow("U10916026");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 1);

    glutKeyboardFunc(onKeyPressed);
    glutKeyboardUpFunc(onKeyReleased);

    glClearColor(0.2, 0.2, 0.2, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 512.0, 0.0, 512.0, 0.0, 512.0);

    glutPostRedisplay();
}

void display(void) {
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2, 0.2, 0.2, 1.0);

    glViewport(0, 0, 512, 512);
    glLoadIdentity();
    gluLookAt(
        0.0, 0.0, 1.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );

    drawBoard(b);
    drawBall(&b->ball);

    //printf("display\n");

    glutSwapBuffers();
    return;
}

void update(int a) {
    glutTimerFunc(25, update, 1);
    b->step();
    display();
}

void onKeyPressed(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        if (not b->left_panel.isActive) {
            b->left_panel.isActive = true;
            b->kickLeft();
        }
        break;
    case 'd':
    case 'D':
        if (not b->right_panel.isActive) {
            b->right_panel.isActive = true;
            b->kickRight();
        }
        break;
    };
}
void onKeyReleased(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        if(b->left_panel.isActive)
            b->left_panel.isActive = false;
        break;
    case 'd':
    case 'D':
        if (b->right_panel.isActive) 
            b->right_panel.isActive = false;
        break;
    };
}

