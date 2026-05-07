#pragma once

#include "Shape.h"

#include <vector>
#include <memory>
#include <cmath>


class ShapeCollection
{
public:
    ShapeCollection() : totalArea(0), nSpaces(0), nLiters(0) {}
    
    double getTotalArea() const { return totalArea; }
    int getNSpaces() const { return nSpaces; }
    int getLiters() const { return nLiters; }
    
    void calcTotalArea();
    void calcTotalLiters();
    
    template<typename T, typename... Args>
    void add(Args&&... args)
    {
        static_assert(std::is_base_of<Shape, T>::value, "T must derive from Shape");
        
        shapes.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

private:
    std::vector<std::unique_ptr<Shape>> shapes;
    double totalArea;  // square meters
    int nSpaces;       // number of composite spaces
    int nLiters;       // liters, rounded up to the next whole number
};