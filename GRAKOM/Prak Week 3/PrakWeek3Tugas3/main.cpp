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

class screenPt {
private:
    GLint x;
    GLint y;

public:
    screenPt() {
        x = 0;
        y = 0;
    }

    void setCoords(GLint xCoordValue, GLint yCoordValue) {
        x = xCoordValue;
        y = yCoordValue;
    }

    GLint getx() const {
        return x;
    }

    GLint gety() const {
        return y;
    }

    void incrementx() {
        x++;
    }

    void decrementy() {
        y--;
    }
};

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    glFlush();
}

void circleMidpoint(GLint xc, GLint yc, GLint radius) {
    screenPt circPt;

    GLint p = 1 - radius;

    circPt.setCoords(0, radius);

    void circlePlotPoints(GLint, GLint, screenPt);
    circlePlotPoints(xc, yc, circPt);
    while(circPt.getx() < circPt.gety()) {
        circPt.incrementx();
        if(p < 0) {
            p += 2 * circPt.getx() + 1;
        }
        else {
            circPt.decrementy();
            p += 2 * (circPt.getx() - circPt.gety()) + 1;
        }
        circlePlotPoints(xc, yc, circPt);
    }
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt) {
    setPixel(xc + circPt.getx(), yc + circPt.gety());
    setPixel(xc - circPt.getx(), yc + circPt.gety());
    setPixel(xc + circPt.getx(), yc - circPt.gety());
    setPixel(xc - circPt.getx(), yc - circPt.gety());
    setPixel(xc + circPt.getx(), yc + circPt.gety());
    setPixel(xc - circPt.getx(), yc + circPt.gety());
    setPixel(xc + circPt.getx(), yc - circPt.gety());
    setPixel(xc - circPt.getx(), yc - circPt.gety());
}

void display() {
    circleMidpoint(30, 100, 10);
    circleMidpoint(90, 100, 20);
    circleMidpoint(160, 100, 30);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(550, 200);
    glutInitWindowSize(400, 300);
    glutCreateWindow("OpenGL Practicum Week03 Program 03");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
