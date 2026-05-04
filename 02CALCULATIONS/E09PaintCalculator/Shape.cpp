#include "Shape.h"


template<typename T, typename... Args>
void add(Args&&... args)
{
    static_assert(std::is_base_of<Shape, T>::value, "T must derive from Shape");
    shapes.push_back(std::make_unique<T>(std::forward<Args>(args)...));
}