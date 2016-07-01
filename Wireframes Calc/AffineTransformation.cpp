//
//  AffineTransformation.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 5/28/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>
#include "AffineTransformation.h"
#include "Matrix3x3.h"
#include "basicshapes.h"
#include "Utilities.h"

AffineTransformation::AffineTransformation():matrix(Matrix3x3::identityMatrix()),translation(Vector(0,0,0))
{
    
}
AffineTransformation::AffineTransformation(const Matrix3x3& m,const Vector& v):matrix(m),translation(v)
{
    
}
AffineTransformation::AffineTransformation(const Matrix3x3& m):matrix(m),translation(Vector(0,0,0))
{
    
}
AffineTransformation::AffineTransformation(const Vector& v):matrix(Matrix3x3::identityMatrix()),translation(v)
{
    
}

Matrix3x3 AffineTransformation::getMatrix() const
{
    return matrix;
}
Vector AffineTransformation::getTranslation() const
{
    return translation;
}

Vector AffineTransformation::transform(const Vector& v) const
{
    return matrix*v+translation;
}

Point AffineTransformation::transform(const Point& p) const
{
    return transform(p.toVector()).toPoint();
}
void AffineTransformation::compose(AffineTransformation a)
{
    //composes current affine transformation inside the new one passed as a parameter, [a(this)]
    
    //a=Ax+b2, this=Tx+b1
    //Ax+b2
    //A(Tx+b1)+b2
    //ATx+Ab1+b2=(AT)x+(Ab1+b2)
    
    Matrix3x3 newMatrix=a.getMatrix()*matrix;
    Vector newTranslation=a.getMatrix()*translation+a.getTranslation();
    
    matrix=newMatrix;
    translation=newTranslation;
}

AffineTransformation AffineTransformation::makeRotation(double xrot,double yrot,double zrot)
{
    Vector xaxis(1,0,0);
    Vector yaxis(0,1,0);
    Vector zaxis(0,0,1);
    
    xaxis.rotate(xrot, yrot, zrot);
    yaxis.rotate(xrot, yrot, zrot);
    zaxis.rotate(xrot, yrot, zrot);
    
    return AffineTransformation(Matrix3x3(xaxis,yaxis,zaxis));
}
AffineTransformation AffineTransformation::rotationAroundVector(const Vector& vec,double degrees)
{
    //https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
    Vector k=vec.getUnitVector();
    Matrix3x3 kMatrix(0,-k.getZ(),k.getY(),
                      k.getZ(),0,-k.getX(),
                      -k.getY(),k.getX(),0);
    Matrix3x3 twistMatrix=Matrix3x3::identityMatrix()+kMatrix*sin(radians(degrees))+kMatrix*kMatrix*(1-cos(radians(degrees)));
    return twistMatrix;
}
AffineTransformation AffineTransformation::alignWithEdge(const Line& l1,double rotation,double originDist)
{
    Point midpoint=l1.getMidpoint();
    Vector midpointVector=midpoint.toVector();
    Vector zaxis=midpointVector*-1;
    zaxis.normalize();
    Vector xaxis=l1.getVector();
    xaxis.normalize();
    Vector yaxis=Vector::cross(zaxis, xaxis);
    Matrix3x3 positioning=Matrix3x3(xaxis,yaxis,zaxis);
    Vector translation=midpointVector.getUnitVector()*originDist;
    AffineTransformation edgeAlignment(positioning,translation);
    AffineTransformation twist=rotationAroundVector(zaxis, rotation);
    edgeAlignment.compose(twist);
    return edgeAlignment;
}
AffineTransformation AffineTransformation::alignWithTriangle(const Triangle& t1,double rotation,double originDist)
{
    Point centroid=t1.getCentroid();
    Vector xaxis=centroid.toVector();
    Vector zaxis(t1.getPointA(),centroid);
    Vector yaxis=Vector::cross(zaxis, xaxis); //in this order since k cross i = j for a right handed coordinate system
    xaxis.normalize();
    yaxis.normalize();
    zaxis.normalize();
    Matrix3x3 positioning=Matrix3x3(xaxis,yaxis,zaxis);
    Vector translation=xaxis.getUnitVector()*originDist;
    AffineTransformation triangleAlignment(positioning,translation);
    AffineTransformation twist=rotationAroundVector(xaxis, rotation);
    triangleAlignment.compose(twist);
    return triangleAlignment;
}

void AffineTransformation::printMatrix() const
{
    matrix.printInfo();
}