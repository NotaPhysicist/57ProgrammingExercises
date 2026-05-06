#pragma once

#include <numbers>

constexpr int MM2_TO_M2 { 1'000'000};
constexpr double PI{ std::numbers::pi };

class Shape
{
    public:
        Shape() : area(0) {}
        virtual ~Shape() = default;
        
        double Shape::getArea() const { return area; }
        
        virtual void calcArea() = 0;

    protected:
        double area;  // square meters
};

class Rectangle : virtual public Shape
{
    public:
        Rectangle(int length, int width) : Shape(), length(length), width(width) {}
        
        int Rectangle::getLength() const { return length; }
        int Rectangle::getWidth() const { return width; }
    
        void calcArea() override;

    private:
        int length;  // millimeters
        int width;   // millimeters
};

class Circle : virtual public Shape
{
    public:
        Circle(int diameter) : Shape(), diameter(diameter) {}
        
        int Circle::getDiameter() const { return diameter; }
        
        void calcArea() override;

    private:
        int diameter;  // millimeters
};

