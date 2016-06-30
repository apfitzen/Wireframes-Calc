//
//  Matrix3x3.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 5/24/15.
//  Copyright (c) 2015 Aaron Pfitzenmaier. All rights reserved.
//

#include "Matrix3x3.h"
#include <iostream>
#include <cmath>
#include "basicshapes.h"
#include "Utilities.h"

Matrix3x3::Matrix3x3(double aa,double bb,double cc,
                     double dd,double ee,double ff,
                     double gg,double hh,double ii)
{
    matrixArray[0][0]=aa;
    matrixArray[0][1]=bb;
    matrixArray[0][2]=cc;
    
    matrixArray[1][0]=dd;
    matrixArray[1][1]=ee;
    matrixArray[1][2]=ff;
    
    matrixArray[2][0]=gg;
    matrixArray[2][1]=hh;
    matrixArray[2][2]=ii;
}
Matrix3x3::Matrix3x3(const Vector& v1,const Vector& v2,const Vector& v3)
{
    matrixArray[0][0]=v1.getX();
    matrixArray[0][1]=v2.getX();
    matrixArray[0][2]=v3.getX();
    
    matrixArray[1][0]=v1.getY();
    matrixArray[1][1]=v2.getY();
    matrixArray[1][2]=v3.getY();
    
    matrixArray[2][0]=v1.getZ();
    matrixArray[2][1]=v2.getZ();
    matrixArray[2][2]=v3.getZ();
}
double Matrix3x3::getCofactor(int row,int col) const
{
    int row1=(row+1)%3;
    int row2=(row+2)%3;
    int col1=(col+1)%3;
    int col2=(col+2)%3;
    double a=getEntry(row1, col1);
    double b=getEntry(row1, col2);
    double c=getEntry(row2, col1);
    double d=getEntry(row2, col2);
    int sign=(row+col)%2*-2+1;
    if (row==1) {sign*=-1;}
    if (col==1) {sign*=-1;}
    return sign*(a*d-b*c);
}
double Matrix3x3::determinant() const
{
    double det=0;
    for (int i=0;i<3;i++)
    {
        det+=getEntry(0,i)*getCofactor(0, i);
    }
    return det;
}

Matrix3x3 Matrix3x3::inverse() const
{
    Matrix3x3 preInverse=Matrix3x3(getCofactor(0,0),getCofactor(1,0),getCofactor(2,0),
                                   getCofactor(0,1),getCofactor(1,1),getCofactor(2,1),
                                   getCofactor(0,2),getCofactor(1,2),getCofactor(2,2));
    return preInverse*(1.0/determinant());
}
double Matrix3x3::getEntry(int  i,int j) const
{
    return matrixArray[i][j];
}
Vector Matrix3x3::getColumnVector(int col) const
{
    if (col>2 || col<0)
    {
        std::cout << "Error Matrix3x3::getColumnVector: column value out of range [0-2]: " << col << "\n";
        return Vector(0,0,0);
    }
    
    double vx=matrixArray[0][col];
    double vy=matrixArray[1][col];
    double vz=matrixArray[2][col];
    
    return Vector(vx,vy,vz);
    
}
Vector Matrix3x3::getRowVector(int row) const
{
    if (row>2 || row<0)
    {
        std::cout << "Error Matrix3x3::getRowVector: row value out of range [0-2]: " << row << "\n";
        return Vector(0,0,0);
    }
    
    double vx=matrixArray[row][0];
    double vy=matrixArray[row][1];
    double vz=matrixArray[row][2];
    
    return Vector(vx,vy,vz);
}
void Matrix3x3::printInfo() const
{
    /*for (int i=0;i<3;i++)
     {
     for (int j=0;j<3;j++)
     {
     std::cout << matrixArray[i][j] << " ";
     }
     std::cout << "\n";
     }*/
    std::cout << toString();
}
std::string Matrix3x3::toString() const
{
    std::string matrixString="[";
    for (int i=0;i<3;i++)
    {
        matrixString+="[";
        for (int j=0;j<3;j++)
        {
            matrixString+=doubleToString(matrixArray[i][j]);
            if (j!=2) {matrixString+=",";}
        }
        matrixString+="]";
        if (i!=2){matrixString+=",\n";}
    }
    matrixString+="]";
    return matrixString;
}
Matrix3x3 Matrix3x3::operator*(const double& param) const
{
    double nma[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            nma[i][j]=matrixArray[i][j]*param;
        }
    }
    return Matrix3x3(nma[0][0],nma[0][1],nma[0][2],
                     nma[1][0],nma[1][1],nma[1][2],
                     nma[2][0],nma[2][1],nma[2][2]);
}
Vector Matrix3x3::operator*(const Vector& param) const
{
    return getColumnVector(0)*param.getX()+getColumnVector(1)*param.getY()+getColumnVector(2)*param.getZ();
}
Matrix3x3 Matrix3x3::operator*(const Matrix3x3& param) const
{
    double aa=Vector::dot(getRowVector(0),param.getColumnVector(0));
    double bb=Vector::dot(getRowVector(0),param.getColumnVector(1));
    double cc=Vector::dot(getRowVector(0),param.getColumnVector(2));
    
    double dd=Vector::dot(getRowVector(1),param.getColumnVector(0));
    double ee=Vector::dot(getRowVector(1),param.getColumnVector(1));
    double ff=Vector::dot(getRowVector(1),param.getColumnVector(2));
    
    double gg=Vector::dot(getRowVector(2),param.getColumnVector(0));
    double hh=Vector::dot(getRowVector(2),param.getColumnVector(1));
    double ii=Vector::dot(getRowVector(2),param.getColumnVector(2));
    
    return Matrix3x3(aa,bb,cc,dd,ee,ff,gg,hh,ii);
}
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& param) const
{
    double nma[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            nma[i][j]=matrixArray[i][j]+param.getEntry(i,j);
        }
    }
    
    return Matrix3x3(nma[0][0],nma[0][1],nma[0][2],
                     nma[1][0],nma[1][1],nma[1][2],
                     nma[2][0],nma[2][1],nma[2][2]);
}

Matrix3x3 Matrix3x3::zeroMatrix()
{
    return Matrix3x3(0,0,0,
                     0,0,0,
                     0,0,0);
}
Matrix3x3 Matrix3x3::identityMatrix()
{
    return Matrix3x3(1,0,0,
                     0,1,0,
                     0,0,1);
}
