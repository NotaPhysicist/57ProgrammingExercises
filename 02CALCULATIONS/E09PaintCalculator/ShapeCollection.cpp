#include "ShapeCollection.h"


void ShapeCollection::calcTotalArea()
{
    for (auto& shape : shapes)
    {
        shape->calcArea();
        totalArea += shape->getArea();
    }
}

void ShapeCollection::calcTotalLiters()
{
    /** 
     * Calculation from given coverage
     * 
     *  1 ~gallon~   3.7854 L      ~1 ft^2~      3.7854 L 
     *   -------- x -------- x    --------     = --------     = 1.16 L/m^2
     *   ~35 ft^2~  1 ~gallon~   0.092903 m^2   3.251605 m^2
     */
    double litersPerM2 = 1.16;    
    nLiters = static_cast<int>(std::ceil(totalArea * litersPerM2));
}