#include "Shape.h"


void Rectangle::calcArea() 
{
    int area_MM2 = length * width;                                 // area in mm^2
    area = static_cast<double>(area_MM2) / PaintCalc::MM2_TO_M2;   // area in m^2
}


void Circle::calcArea()
{
    constexpr int MM_to_M{ 1000 };
    area = (diameter / MM_to_M) * std::numbers::pi; 
}


