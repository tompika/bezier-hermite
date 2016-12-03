/**
    
    Hermite.h
    Bevgraf - 4. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.11.27. 
*/

#ifndef HERMITE_H
#define HERMITE_H

#include <vector>
#include <iostream>
#include "strukt.h"
#include "Matrix.h"


class Hermite
{

  public:
    std::vector<POINT2D> points;
    Vector erinto;

    Matrix G;
    Matrix M;

    

    std::vector<std::vector<double>> CC={   {-0.0354925, 0.117125, -0.111801, 0.0239574},
                            {0.301932, -0.301932, -1.13225, 1.3587},
                            {-0.26644, 0.184807,  1.24405, -0.382653},
                            {0.238095, 0.047619, -0.75, 0.214286} 
                            };

    Matrix C = Matrix(4,4, CC);

    //std::vector<std::vector<double>> T;

    //  Hermite(POINT2D& p1_, POINT2D& p2_, POINT2D p3_,  POINT2D p4_){
    Hermite(){
        
    }
    

    Hermite(std::vector<POINT2D> ps)
    {

        this->points = ps;

        std::vector<std::vector<double>> G = {{ps[0].x, ps[1].x, ps[2].x, ps[3].x - ps[2].x},
                                              {ps[0].y, ps[1].y, ps[2].y, ps[3].y - ps[2].y}};

        Matrix G_M = Matrix(2, 4, G);
        this->G = G_M;

       // calculate();
    }

    void calculate()
    {
        //t1 = -2, t2 = 0.3 és t3 = 1.5
        double t1 = -2;
        double t2 = 0.3;
        double t3 = 1.5;

       /* std::vector<std::vector<double>> T_ = {{t1 * t1 * t1, t2 * t2 * t2, t3 * t3 * t3, 3 * (t3 * t3)},
                                               {t1 * t1, t2 * t2, t3 * t3, 2 * t3},
                                               {t1, t2, t3, 1},
                                               {1, 1, 1, 0}};*/


        double T[4][4] ={t1 * t1 * t1, t2 * t2 * t2, t3 * t3 * t3, 3 * (t3 * t3),
                                               t1 * t1, t2 * t2, t3 * t3, 2 * t3,
                                               t1, t2, t3, 1,
                                               1, 1, 1, 0};


        
        
       // C = C_;
        
      //  Matrix C = G * M;

    

        /*
        int i,j ,k;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 4; j++)
            {
                result.data[i][j] = 0;
                for (k = 0; k < 4; k++)
                {
                    result.data[i][j] = result.data[i][j] + (a.data[i][k] * b.data[k][j]);
                }
            }
        }

*/
    }

 

    void draw()
    {

        glBegin(GL_POINTS);
        for (int i = 0; i < points.size(); i++)
            glVertex2i(points[i].x, points[i].y);

        glEnd();

        glBegin(GL_LINES);
        glVertex2i(points[2].x, points[2].y);
        glVertex2i(points[3].x, points[3].y);

        glEnd();

                std::vector<std::vector<double>> G_ = {{points[0].x, points[1].x, points[2].x, points[3].x - points[2].x},
                                              {points[0].y, points[1].y,points[2].y, points[3].y - points[2].y}};
    G = Matrix(2,4, G_);

        // double t[4] = {t*t*t, t*t, t, 1};

        glBegin(GL_LINE_STRIP);
        for (double t = -2; t < 1.5; t += 0.01)
        {

            double tt[4] = {t * t * t, t * t, t, 1};

            double x = G.data[0][0] * (C.data[0][0] * tt[0] + C.data[0][1] * tt[1] + C.data[0][2] * tt[2] + C.data[0][3] * tt[3]) +
                       G.data[0][1] * (C.data[1][0] * tt[0] + C.data[1][1] * tt[1] + C.data[1][2] * tt[2] + C.data[1][3] * tt[3]) +
                       G.data[0][2] * (C.data[2][0] * tt[0] + C.data[2][1] * tt[1] + C.data[2][2] * tt[2] + C.data[2][3] * tt[3]) +
                       G.data[0][3] * (C.data[3][0] * tt[0] + C.data[3][1] * tt[1] + C.data[3][2] * tt[2] + C.data[3][3] * tt[3]);

            double y = G.data[1][0] * (C.data[0][0] * tt[0] + C.data[0][1] * tt[1] + C.data[0][2] * tt[2] + C.data[0][3] * tt[3]) +
                       G.data[1][1] * (C.data[1][0] * tt[0] + C.data[1][1] * tt[1] + C.data[1][2] * tt[2] + C.data[1][3] * tt[3]) +
                       G.data[1][2] * (C.data[2][0] * tt[0] + C.data[2][1] * tt[1] + C.data[2][2] * tt[2] + C.data[2][3] * tt[3]) +
                       G.data[1][3] * (C.data[3][0] * tt[0] + C.data[3][1] * tt[1] + C.data[3][2] * tt[2] + C.data[3][3] * tt[3]);

            glVertex2d(x, y);

            // std::cout << x << " " << y << std::endl;
        }
        glEnd();
    }
};

#endif
