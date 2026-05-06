#pragma once

#include "Shape.h"

#include <vector>
#include <memory>


class ShapeCollection
{
public:
    ShapeCollection() : totalArea(0), n_Spaces(0), n_Liters(0) {}
    
    double ShapeCollection::getTotalArea() const { return totalArea; }
    int ShapeCollection::get_nSpaces() const { return n_Spaces; }
    int ShapeCollection:: getLiters() const { return n_Liters; }
    
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
    int n_Spaces;      // number of composite spaces
    int n_Liters;      // liters, rounded up to the next whole number
};