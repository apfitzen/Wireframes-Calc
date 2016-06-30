//
//  Face.h
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/21/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#ifndef __Wireframes_Calc_4__Face__
#define __Wireframes_Calc_4__Face__

#include <vector>
#include <map>

#include "basicshapes.h"

typedef std::vector<int> EdgeVector;
typedef std::vector<Point> VertexVector;

class FaceGenerator
{
private:
    virtual FaceGenerator* doClone()=0;
    virtual std::vector<Triangle> generateTriangles(double frameWidth,const VertexVector& vertices)=0;
    virtual std::vector<std::pair<Triangle, int>> do_generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges)=0;
    virtual double do_calculateMaxWidth(const VertexVector& vertices) const=0;
    
    bool areVerticesAndEdgesEqualLength(const VertexVector& vertices,const EdgeVector& edges,std::string message) const;
protected:
    std::map<std::string,double> attributes;
    
    FaceGenerator();
public:
    FaceGenerator* clone();
    
    void setAttribute(std::string name,double value);
    double getAttribute(std::string name);
    
    std::vector<Triangle> generateTrianglesList(double frameWidth,const VertexVector& vertices);
    std::vector<std::pair<Triangle, int>> generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges);
    double calculateMaxWidth(const VertexVector& vertices) const;
    virtual ~FaceGenerator();
};

#endif /* defined(__Wireframes_Calc_4__Face__) */
