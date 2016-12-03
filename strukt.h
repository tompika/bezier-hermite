
#ifndef STRUKT_H
#define STRUKT_H



typedef struct point2d
{
    GLdouble x, y;
} POINT2D;

typedef struct vector
{
    GLdouble x, y;
} Vector;

typedef struct indexdrag
{
    int i, j;
} IndexDrag;

Vector initVector(GLdouble x, GLdouble y)
{
    Vector P;
    P.x = x;
    P.y = y;
    return P;
}

POINT2D initPoint2D(GLdouble x, GLdouble y)
{
    POINT2D P;
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


#endif