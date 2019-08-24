/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

using namespace std;

GLfloat white[3] = {1.0,1.0,1.0};
#define NPOINTS 90

    float xArr[NPOINTS];
    float yArr[NPOINTS];

void init(void){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    GLfloat angulo, delta;
    GLfloat x, y;
    float r;

    delta = float(360) / float(NPOINTS);
    angulo = 0;
    glColor3fv(white);


    for(int i=0; i < NPOINTS; i++)
    {
      r = -3 + 4 * cos(angulo);
      x = r * sin(angulo);
      y = r * cos(angulo);

      xArr[i] = x;
      yArr[i] = y;
      glBegin(GL_POINTS);
        glVertex2f(x,y);
      glEnd();
      angulo += delta;

    }



    glFlush();
}

/* Program entry point*/
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400,400);
    glutInitWindowSize(400,400);
    glutCreateWindow("Actividad Escala");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    printf("%f",xArr[NPOINTS]);
    printf("NERIiiii");
    return 0;
}

//primero tratamos de guardar 90 puntos en un arreglo pero no pudimos, debido a que
