//
//  DihedralFace.cpp
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/24/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>

#include "DihedralFace.h"
#include "Utilities.h"

DihedralFace::DihedralFace():FramedFace()
{
    attributes["dihedral"]=0.0;
    attributes["uorl"]=1.0;
}
std::vector<Triangle> DihedralFace::generateTriangles(double frameWidth,const VertexVector& vertices)
{
    double dihedral=attributes.at("dihedral");
    generateInnerPoints(frameWidth*cos(dihedral*M_PI/180),vertices);
    addDihedral(frameWidth,vertices);
    return connectInnerPoints(vertices);
}
std::vector<std::pair<Triangle, int>> DihedralFace::do_generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges)
{
    double dihedral=attributes.at("dihedral");
    generateInnerPoints(frameWidth*cos(dihedral*M_PI/180),vertices);
    addDihedral(frameWidth,vertices);
    return makeTriangleEdgePairs(frameWidth,vertices,edges);
}
void DihedralFace::addDihedral(double frameWidth,const VertexVector& vertices)
{
    double dihedral=attributes.at("dihedral");
    double uorl=attributes.at("uorl");
    if (dihedral!=0) //raise/lower these inner points out of the plane of face based on dihedral
    {
        Point v1=vertices.at(0);
        Point v2=vertices.at(1);
        Point v3=vertices.at(2);
        Plane facePlane=Plane::planeThroughPoints(v1, v2, v3);
        Vector normal=facePlane.getNormalVector();
        
        double height=frameWidth*sin(dihedral*M_PI/180);
        
        Point opoint;
        int upperOrLower;
        if (uorl>=0.0)
        {
            upperOrLower=1;
        }
        else
        {
            upperOrLower=-1;
        }
        
        int faceSize=(int) vertices.size();
        for (int i=0;i<faceSize;i++)
        {
            opoint=inners.at(i)+normal;
            double dist=Point::distance(opoint, inners.at(i));
            double hfactor=height/dist;
            inners.at(i)=Point::extendLine(inners.at(i), opoint, hfactor*upperOrLower);
        }
    }
}
double DihedralFace::do_calculateMaxWidth(const VertexVector& vertices) const
{
    double dihedral=attributes.at("dihedral");
    double maxHeight=FramedFace::do_calculateMaxWidth(vertices);
    return maxHeight/cos(dihedral*M_PI/180);
}
DihedralFace* DihedralFace::doClone()
{
    return new DihedralFace(*this);
}