//
//  IcosahedralEdgeCompound.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 6/19/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>
#include <vector>
#include "IcosahedralEdgeCompound.h"
#include "Polyhedron.h"
#include "Icosahedron.h"
#include "Utilities.h"

IcosahedralEdgeCompound::IcosahedralEdgeCompound(const Polyhedron& polyhedron,double radius,double twist):Compound(polyhedron,30)
{
    Icosahedron icosahedron(0,0,0);
    int edgeNum=icosahedron.getEdgeNum();
    
    for (int i=0;i<edgeNum;i++)
    {
        poly.at(i)->setTransformation(AffineTransformation::alignWithEdge(icosahedron.getEdgeLine(i),twist,radius));
    }
}