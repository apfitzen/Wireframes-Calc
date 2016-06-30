//
//  DihedralFace.h
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/24/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#ifndef __Wireframes_Calc_4__DihedralFace__
#define __Wireframes_Calc_4__DihedralFace__

#include "FramedFace.h"
#include "basicshapes.h"

class DihedralFace:public FramedFace
{
private:
    void addDihedral(double frameWidth,const VertexVector& vertices);
    virtual std::vector<Triangle> generateTriangles(double frameWidth,const VertexVector& vertices);
    virtual std::vector<std::pair<Triangle, int>> do_generateTriangleEdgePairs(double frameWidth,const VertexVector& vertices,const EdgeVector& edges);
    virtual DihedralFace* doClone();
    virtual double do_calculateMaxWidth(const VertexVector& vertices) const;
public:
    DihedralFace();
};


#endif /* defined(__Wireframes_Calc_4__DihedralFace__) */
