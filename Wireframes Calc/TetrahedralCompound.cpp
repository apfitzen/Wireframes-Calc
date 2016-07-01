//
//  TetrahedralCompound.cpp
//  Wireframes Calc 4.5
//
//  Created by Aaron Pfitzenmaier on 5/29/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <cmath>
#include "TetrahedralCompound.h"
#include "Polyhedron.h"
#include "Tetrahedron.h"
#include "Utilities.h"

TetrahedralCompound::TetrahedralCompound(const Polyhedron& polyhedron,double radius,double twist):Compound(polyhedron,4)
{
    Tetrahedron refTet(0,0,0);
    int faceNumber=refTet.getFaceNum();
    for (int i=0;i<faceNumber;i++)
    {
        poly.at(i)->setTransformation(AffineTransformation::alignWithTriangle(refTet.getFaceVertices(i),twist,radius));
    }
}