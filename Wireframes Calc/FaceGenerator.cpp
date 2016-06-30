//
//  Face.cpp
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/21/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#include <vector>

#include "FaceGenerator.h"
#include "Utilities.h"

FaceGenerator::~FaceGenerator()
{
    
}
FaceGenerator::FaceGenerator()
{
    
}
bool FaceGenerator::areVerticesAndEdgesEqualLength(const VertexVector& vertices,const EdgeVector& edges,std::string message) const
{
    if (vertices.size()==edges.size())
    {
        return true;
    }
    else
    {
        std::cout << "Error: FaceGenerator::" << message << " called with vertices vector size != edge vector size" << "\n";
        return false;
    }
}
std::vector<Triangle> FaceGenerator::generateTrianglesList(double frameWidth,const VertexVector& vertices)
{
    return generateTriangles(frameWidth,vertices);
}
std::vector<std::pair<Triangle, int>> FaceGenerator::generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges)
{
    if (!areVerticesAndEdgesEqualLength(vertices,edges,"generateTriangleEdgePairs")) {return std::vector<std::pair<Triangle, int>>();}
    return do_generateTriangleEdgePairs(frameWidth,vertices,edges);
}
double FaceGenerator::calculateMaxWidth(const VertexVector& vertices) const
{
    return do_calculateMaxWidth(vertices);
}

void FaceGenerator::setAttribute(std::string name,double value)
{
    attributes.at(name)=value;
}
double FaceGenerator::getAttribute(std::string name)
{
    return attributes.at(name);
}

FaceGenerator* FaceGenerator::clone()
{
    FaceGenerator* newFace=doClone();
    return newFace;
}