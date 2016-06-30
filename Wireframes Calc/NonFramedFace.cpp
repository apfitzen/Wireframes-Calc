//
//  NonFramedFace.cpp
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/23/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#include "NonFramedFace.h"

NonFramedFace::NonFramedFace():FaceGenerator()
{
    
}
std::vector<Triangle> NonFramedFace::generateTriangles(double frameWidth,const VertexVector& vertices)
{
    return std::vector<Triangle>(0);
}
NonFramedFace* NonFramedFace::doClone()
{
    return new NonFramedFace(*this);
}
std::vector<std::pair<Triangle, int>> NonFramedFace::do_generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges)
{
    return std::vector<std::pair<Triangle, int>>(0);
}
double NonFramedFace::do_calculateMaxWidth(const VertexVector& vertices) const
{
    return 1000000.0;
}