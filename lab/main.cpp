
#include <iostream>



#include <GLUT/glut.h>



#include <math.h>
void setPixel(GLint xCoordinate, GLint yCoordinate) {
glBegin(GL_POINTS);
glVertex2i(xCoordinate, yCoordinate);
glEnd();
glFlush(); }
void circleMidPoint(GLint xc, GLint yc, GLint radius)
{
int x=0,y=radius;
int p = 1-radius;
//function prototype
void circlePlotPoints(GLint, GLint, GLint,GLint); circlePlotPoints(xc, yc,x,y);
while(x < y)
{ x++;
if(p<0) p += 2 * x + 1;
else
{ y--; p += 2 * (x-y) + 1; }
circlePlotPoints(xc, yc, x, y);
}}
void circlePlotPoints(GLint xc, GLint yc, GLint x, GLint y) {
setPixel(xc + x , yc + y);
setPixel(xc - x , yc + y);
setPixel(xc + x , yc - y); setPixel(xc - x , yc - y); setPixel(xc + y , yc + x); setPixel(xc - y , yc + x); setPixel(xc + y , yc - x); setPixel(xc - y , yc - x); }
void init(void) {glClearColor(1.0,1.0,1.0,1.0); glMatrixMode(GL_PROJECTION); gluOrtho2D(0.0,300.0,0.0,300.0);
}
void drawMyCircle(void)
{
// outer circle glClear(GL_COLOR_BUFFER_BIT); glColor3f(0.9,0.5,0.0);
glPointSize(3.0);
GLint xCenter=150;
GLint yCenter=150;
GLint radius=75; circleMidPoint(xCenter, yCenter, radius); // middle circle
glColor3f(0.8,0.8,0.1);
glPointSize(3.0);
GLint xC=150;
GLint yC=150;
GLint r=50;
circleMidPoint(xC, yC, r);
//inner circle
glColor3f(0.8,0.8,0.8);
glPointSize(3.0);
GLint x=150;
GLint y=150;
GLint rr=25;
circleMidPoint(x, y, rr);
}

int main(int argc, char**argv)
{
glutInit(&argc, argv);
glutInitWindowPosition(10,10); glutInitWindowSize(500,500); glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutCreateWindow("Circle Mid Point Algorithm | Sara"); init();
glutDisplayFunc(drawMyCircle); glutMainLoop();
return 0;
}
