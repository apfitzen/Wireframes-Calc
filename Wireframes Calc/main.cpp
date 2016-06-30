//
//  main.cpp
//  Wireframes Calc 5
//
//  Created by Aaron Pfitzenmaier on 6/22/16.
//  Copyright (c) 2016 Aaron Pfitzenmaier. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>

#include "Matrix3x3.h"

int main(int argc, const char * argv[]) {
    clock_t t;
    t = clock();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<std::string> colors1={"Blue","Green","Red","Yellow","Orange","Violet","Cyan","Magenta","Black","Brown","CadetBlue","Aquamarine","Gray","MediumVioletRed","BlueViolet","SeaGreen","SlateBlue","MediumSlateBlue","Tan","Light_Purple"};
    std::vector<std::string> colors2={"Yellow","Green","Blue","Red","Violet","MediumVioletRed","CadetBlue","Orange","CornflowerBlue","DarkGreen","Cyan","Magenta","Aquamarine","BlueViolet","Brown","MediumSlateBlue","Tan","Light_Purple","SlateBlue","SeaGreen"};
    std::vector<std::string> colors3={"Yellow","Green","Blue","Red","Violet","Cyan","Magenta","Aquamarine","BlueViolet","Brown","MediumVioletRed","Yellow","Cyan","Brown","Orange","Light_Purple","SeaGreen","MediumSlateBlue","SlateBlue","Tan"};
    
    Matrix3x3 m(9.3,10,-1,2,-5,2,0,-4,0);
    std::cout << m.toString() << "\n\n";
    Matrix3x3 inverse=m.inverse();
    Matrix3x3 identity=inverse*m;
    std::cout << identity.toString() << "\n";
    
    Vector v1(2,3,4);
    Vector v2=v1.getUnitVector();
    
    std::cout << v2.toString() << "\n";
    
    t = clock() - t;
    printf ("\nIt took me %lu clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    return 0;
}
