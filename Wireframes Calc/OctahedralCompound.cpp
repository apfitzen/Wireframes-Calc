//
//  OctahedralCompound.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 6/11/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>
#include "OctahedralCompound.h"
#include "Polyhedron.h"
#include "Octahedron.h"
#include "Utilities.h"

OctahedralCompound::OctahedralCompound(const Polyhedron& polyhedron,double radius,double twist):Compound(polyhedron,8)
{
    Octahedron octa(0,0,0);
    int faceNumber=octa.getFaceNum();
    for (int i=0;i<faceNumber;i++)
    {
        poly.at(i)->setTransformation(AffineTransformation::alignWithTriangle(octa.getFaceVertices(i),twist,radius));
    }
}