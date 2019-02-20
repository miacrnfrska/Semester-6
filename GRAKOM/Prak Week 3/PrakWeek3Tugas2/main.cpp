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

void lineBres(int x0, int y0, int xEnd, int yEnd) {
    int dx = fabs(xEnd - x0);
    int dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x;
    int y;

    if(x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }
    else {
        x = x0;
        y = y0;
    }
    setPixel(x, y);

    while(x < xEnd) {
        x++;
        if(p < 0) {
            p += twoDy;
        }
        else {
           y++;
           p += twoDyMinusDx;
        }
        setPixel(x, y);
    }
}

void display() {
    lineBres(80, 100, 80, 145);
    lineBres(120, 100, 120, 145);
    lineBres(60, 90, 140, 90);
    lineBres(60, 60, 140, 60);
    lineBres(80, 50, 80, 5);
    lineBres(120, 50, 120, 5);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(550, 200);
    glutInitWindowSize(400, 300);
    glutCreateWindow("OpenGL Practicum Week03 Program 02");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
