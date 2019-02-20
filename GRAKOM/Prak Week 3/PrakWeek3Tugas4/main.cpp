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
#include <stdarg.h>a

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
    lineDDA(50, 100, 150, 100);
    lineDDA(50, 50, 150, 50);
    lineDDA(50, 100, 50, 50);
    lineDDA(150, 100, 150, 50);
    circleMidpoint(75,85,5);
    circleMidpoint(125,85,5);
    lineBres(90, 65, 110, 70);
    lineDDA(125, 35, 160, 35);
    lineDDA(125, 30, 160, 30);
    lineDDA(75, 30, 40, 30);
    lineDDA(75, 35, 40, 35);
    lineDDA(75, 50, 75, 2);
    lineDDA(125, 50, 125, 2);
    circleMidpoint(165,33,6);
    circleMidpoint(35,33,6);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(550, 200);
    glutInitWindowSize(400, 300);
    glutCreateWindow("OpenGL Practicum Week03 Program 04");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
