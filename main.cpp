#include <GL/glut.h>
#include <math.h>
#include <vector>

#include "Hermite.h"
#include "strukt.h"
#include "Matrix.h"
#include "Bezier.h"

GLsizei winWidth = 800, winHeight = 600;


int dragged = -1;
int dragged2 = -1;
int drag_i;
int drag_i2;


Hermite hermite;
Bezier bezier;

/*
typedef struct point2d
{
    GLdouble x, y;
} POINT2D;

typedef struct indexdrag
{
    int i, j;
} IndexDrag;

typedef struct vector
{
    GLdouble x, y;
} Vector;

Vector initVector(GLdouble x, GLdouble y)
{
    Vector P;
    P.x = x;
    P.y = y;
    return P;
}

IndexDrag initIndexDrag(int i, int j)
{
    IndexDrag P;
    P.i = i;
    P.j = j;
    return P;
}

POINT2D initPoint2D(GLdouble x, GLdouble y)
{
    POINT2D P;
    P.x = x;
    P.y = y;
    return P;
}*/








void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
    glShadeModel(GL_FLAT);
    glPointSize(10.0);

    
    POINT2D p1 = initPoint2D(100, 200);
    POINT2D p2 = initPoint2D(230, 300);
    POINT2D p3 = initPoint2D(400, 300);
    POINT2D p4 = initPoint2D(550, 100);

    std::vector<POINT2D> tmp;
    std::vector<POINT2D> tmp2;
    
    tmp.push_back(p1);
    tmp.push_back(p2);
    tmp.push_back(p3);
    tmp.push_back(p4);

    
    POINT2D q0 = initPoint2D(p3.x, p3.y);
    POINT2D q1 = initPoint2D(300, 550);
    POINT2D q2 = initPoint2D(100, 400);
    POINT2D q3 = initPoint2D(400, 400);
    POINT2D q4 = initPoint2D(500, 300);
    POINT2D q5 = initPoint2D(p1.x, p1.y);

    tmp2.push_back(q0);
    tmp2.push_back(q1);
    tmp2.push_back(q2);
    tmp2.push_back(q3);
    tmp2.push_back(q4);
    tmp2.push_back(q5);

    hermite.points = tmp;
    bezier.points = tmp2;

   // std::cout << tmp.size() << " " << tmp2.size() << std::endl;

    //std::cout << hermites.size() << std::endl;


}

void display()
{
    



    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

        hermite.draw();
        bezier.draw();

    glutSwapBuffers();
}

GLfloat dist2(POINT2D P1, POINT2D P2)
{
    GLfloat t1 = P1.x - P2.x;
    GLfloat t2 = P1.y - P2.y;
    return t1 * t1 + t2 * t2;
}

/*void update(int n)
{

    glutPostRedisplay();

    glutTimerFunc(5, update, 0);
}*/

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        break;
    }
}

int getActivePoint(Hermite hermite, GLint size, GLint sens, GLint x, GLint y)
{
    GLint s = sens * sens;
    POINT2D P = initPoint2D(x, y);
    POINT2D tmp, tmp2;

    for (int i = 0; i < hermite.points.size(); i++){
            tmp = initPoint2D(hermite.points[i].x, hermite.points[i].y);
            if ( dist2(tmp, P) < s){
                return i;
            }

    }

    return -1;
        
}
int getActivePoint2(Bezier bez, GLint size, GLint sens, GLint x, GLint y)
{
    GLint s = sens * sens;
    POINT2D P = initPoint2D(x, y);
    POINT2D tmp;

    for (int i = 0; i < bez.points.size(); i++){
            tmp = initPoint2D(bez.points[i].x, bez.points[i].y);
            if ( dist2(tmp, P) < s){
                return i;
            }

    }

    return -1;
        
}

void processMouse(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    int i;

    if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)
    {
        int res = getActivePoint(hermite, 4, 8, xMouse, winHeight - yMouse);
        int res2 = getActivePoint2(bezier, 4, 8, xMouse, winHeight - yMouse);
       // std::cout << res2 << std::endl;
        if (res > -1)
        {
            dragged = res;
            drag_i = res;
        }
        if(res2 > -1){
            dragged2 = res2;
            drag_i2 = res2;

        }
    }
    if (button == GLUT_LEFT_BUTTON && action == GLUT_UP){
        dragged = -1;
        dragged2 = -1;
    }
}

void processMouseActiveMotion(GLint xMouse, GLint yMouse)
{

    if (dragged >= 0)
    {
        
        hermite.points[drag_i].x = xMouse;
        hermite.points[drag_i].y = winHeight - yMouse;

        glutPostRedisplay();
    }
    if (dragged2 >= 0)
    {
        

        bezier.points[drag_i2].x = xMouse;
        bezier.points[drag_i2].y = winHeight - yMouse;
        
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(40, 40);
    glutCreateWindow("Hermite and Beziel - Szilvacsku Peter");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(processMouse);
    glutMotionFunc(processMouseActiveMotion);
    //glutTimerFunc(5, update, 0);
    glutMainLoop();
    return 0;
}
