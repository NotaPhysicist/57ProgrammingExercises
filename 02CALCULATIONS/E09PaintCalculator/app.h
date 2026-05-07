#pragma once        

#include <print>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#include "Console.h"
#include "ShapeCollection.h"

/*
NOTES: 

Convert this to meters? If I work in meters I need to use 
doubles. 

Break up the area(s) you wish to measure into a series or 
rectangles and circles. Then input them one-by-one to get
total area and the number of gallons of paint required. 

This program assumes a coverage of 350 square feet per gallon. 
Enter a custom coverage ratio, or press return to proceed: 

Is the space a rectangle or a circle? 
    [c] Enter the radius of the circle: 
    [r] Enter the length:
    [r] Enter the width:

Area of this space: 
Total area so far: 
Enter [t] to complete, or press return to enter another space

Total coverage: 
Number of gallons required:
*/

void run();
std::string makeTitle(); 
bool signal(std::string_view s, char flag);
bool signal_Exit(std::string_view s);
bool signal_Done(std::string_view s);
bool signal_Circle(std::string_view s);
bool signal_Rectangle(std::string_view s);

