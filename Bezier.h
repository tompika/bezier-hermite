/**
    
    Bezier.h
    Bevgraf - 4. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.12.01. 
*/

#ifndef BEZIER_H
#define BEZIER_H

#include <vector>
#include <iostream>
#include "strukt.h"

class Bezier
{

  public:
    std::vector<POINT2D> points;
    std::vector<POINT2D> points_tmp;

    Bezier(){

    }
    Bezier(std::vector<POINT2D> allP)
    {

        this->points = allP;
    }

    void draw()
    {
        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_POINTS);
        for(int i=0; i < points.size(); i++){
            glVertex2d(points[i].x, points[i].y);
        }
        glEnd();


        points_tmp = points;
        glBegin(GL_LINE_STRIP);
        for (double t = 0; t <= 1; t += 0.01)
        {
            
            for (int r = 0; r < 5; r++)
            {
                for (int i = 0; i < 5 - r; i++)
                {
                    points_tmp[i].x = (1 - t) * points_tmp[i].x + t * points_tmp[i + 1].x;
                    points_tmp[i].y = (1 - t) * points_tmp[i].y + t * points_tmp[i + 1].y;
                }
            }
            glVertex2d(points_tmp[0].x, points_tmp[0].y);
           // std::cout << points_tmp[0].x << " " <<  points_tmp[0].y << std::endl;
            
            points_tmp = points;
        }
        glEnd();

    }
};
#endif