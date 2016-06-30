//
//  FifteenCompound.cpp
//  Wireframes Calc 4
//
//  Created by Aaron Pfitzenmaier on 12/30/14.
//  Copyright (c) 2014 Aaron Pfitzenmaier. All rights reserved.
//

#include "FifteenCompound.h"
#include "Polyhedron.h"
#include "basicshapes.h"

FifteenCompound::FifteenCompound(const Polyhedron& polyhedron):Compound(polyhedron,15)
{
    double sixtyNine=69.094842554;
    double twentyOne=20.905157447;
    double thirtyOne=31.717474411;
    double fiftyEight=58.282525589;
    
    poly.at(0)->setRotation(0,0,0);
    poly.at(1)->setRotation(sixtyNine,30,twentyOne);
    poly.at(2)->setRotation(-sixtyNine,30,-twentyOne);
    poly.at(3)->setRotation(-sixtyNine,-30,twentyOne);
    poly.at(4)->setRotation(sixtyNine,-30,-twentyOne);
    poly.at(5)->setRotation(90,90,0);
    poly.at(6)->setRotation(-thirtyOne,-18,-fiftyEight);
    poly.at(7)->setRotation(thirtyOne,-18,fiftyEight);
    poly.at(8)->setRotation(thirtyOne,18,-fiftyEight);
    poly.at(9)->setRotation(-thirtyOne,18,fiftyEight);
    poly.at(10)->setRotation(90,0,90);
    poly.at(11)->setRotation(-thirtyOne,-54,fiftyEight);
    poly.at(12)->setRotation(thirtyOne,-54,-fiftyEight);
    poly.at(13)->setRotation(thirtyOne,54,fiftyEight);
    poly.at(14)->setRotation(-thirtyOne,54,-fiftyEight);
}