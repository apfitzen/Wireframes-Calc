//
//  PenultimateTriangle.h
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 1/4/15.
//  Copyright (c) 2015 Aaron Pfitzenmaier. All rights reserved.
//

#ifndef __Wireframes_Calc_4__PenultimateTriangle__
#define __Wireframes_Calc_4__PenultimateTriangle__

#include <vector>
#include "FaceGenerator.h"

class Vertex;
class Point;
class Triangle;
class PenultimateTriangle:public FaceGenerator
{ //use with equilateral triangles only
private:
    bool verifyFaceIsTriangle(const VertexVector& vertices,std::string message) const;
    
    virtual PenultimateTriangle* doClone();
    virtual std::vector<Triangle> generateTriangles(double frameWidth,const VertexVector& vertices);
    virtual std::vector<std::pair<Triangle, int>> do_generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges);
    virtual double do_calculateMaxWidth(const VertexVector& vertices) const;
    
    std::vector<Point> inners;
    void generateInnerPoints(double frameWidth,const VertexVector& vertices);
    std::vector<Triangle> connectInnerPoints(const VertexVector& vertices);
public:
    PenultimateTriangle();
};

#endif /* defined(__Wireframes_Calc_4__PenultimateTriangle__) */
