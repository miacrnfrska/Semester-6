/*  PRAKTIKUM 3
    Nama : Mia Carina Friska Lingga
    NIM  : 11S16059
    Kelas: 13TI2
*/

#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

void lineDDA(int x0, int y0, int xEnd, int yEnd) {
    int dx = xEnd - x0;
    int dy = yEnd - y0;
    int steps;
    int k;
    int xIncrement;
    int yIncrement;
    int x = x0;
    int y = y0;

    if(fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    }
    else {
        steps = fabs(dy);
    }
    xIncrement = dx / steps;
    yIncrement = dy / steps;

    setPixel(x, y);
    for(k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel(x, y);
    }
}

void display() {
    lineDDA(80, 100, 80, 145);
    lineDDA(120, 100, 120, 145);
    lineDDA(60, 90, 140, 90);
    lineDDA(60, 60, 140, 60);
    lineDDA(80, 50, 80, 5);
    lineDDA(120, 50, 120, 5);


}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(550, 200);
    glutInitWindowSize(400, 300);
    glutCreateWindow("OpenGL Practicum Week03 Program 01");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
