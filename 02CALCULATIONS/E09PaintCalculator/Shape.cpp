#include "Shape.h"
#include <numbers>


void Rectangle::calcArea() 
{
    int area_MM2 = length * width;                      // area in mm^2
    area = static_cast<double>(area_MM2) / MM2_TO_M2;   // area in m^2
}


void Circle::calcArea()
{
    int areaMM2 = PI * diameter;                         // area in mm^2
    area = static_cast<double>(areaMM2) / MM2_TO_M2;     // area in m^2
}


