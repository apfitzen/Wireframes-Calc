//
//  IcosahedralCompound.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 6/11/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>
#include "IcosahedralCompound.h"
#include "Polyhedron.h"
#include "Icosahedron.h"
#include "Utilities.h"

IcosahedralCompound::IcosahedralCompound(const Polyhedron& polyhedron,double radius,double twist):Compound(polyhedron,20)
{
    Icosahedron icosa(0,0,0);
    int faceNumber=icosa.getFaceNum();
    for (int i=0;i<faceNumber;i++)
    {
        poly.at(i)->setTransformation(AffineTransformation::alignWithTriangle(icosa.getFaceVertices(i),twist,radius));
    }
}