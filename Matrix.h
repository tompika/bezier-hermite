/**
    
    Matrix.h
    Bevgraf - 3. hazi

    @author Péter Szilvácsku
    @version 1.0 2016.11.10. 
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>


class Matrix
{

  public:
    double **data;
    int m, n;

    Matrix()
    {
        this->n = 4;
        this->m = 4;

        data = new double *[n];
        for (int i = 0; i < n; i++)
            data[i] = new double[m];
    }

    Matrix(int n, int m)
    {
        this->n = n;
        this->m = m;

        data = new double *[n];
        for (int i = 0; i < n; i++)
            data[i] = new double[m];
    }

    Matrix(int n, int m, std::vector<std::vector<double>> data_)
    {
        this->n = n;
        this->m = m;
        data = new double *[n];
        for (int i = 0; i < n; i++)
            data[i] = new double[m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                data[i][j] = data_[i][j];
            }
        }
    }

    Matrix operator*(const Matrix Other)
    {

        Matrix ret;
        float sum;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < Other.m; j++)
            {
                sum = 0;
                for (int k = 0; k < m; k++)
                    sum = sum + this->data[i][k] * Other.data[k][j];
                ret.data[i][j] = sum;
            }

        return ret;
    }
/*
    Matrix operator*(const Matrix other)
    {
        // if row-column match is present
        if (colNum == other.getRowNum())
        {
            // create an appropriate sized matrix
            Matrix temp = Matrix(rowNum, other.getColNum());
            temp.zeroTheElements();
            for (int i = 0; i < rowNum; ++i)
            {
                for (int j = 0; j < other.getColNum(); ++j)
                {
                    for (int k = 0; k < colNum; ++k)
                    {
                        temp[i][j] = temp[i][j] + data[i][k] * other[k][j];
                    }
                }
            }
            return temp;
        }
    }*/

    void display()
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << data[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
};

#endif
