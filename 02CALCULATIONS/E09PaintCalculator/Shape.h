#pragma once

#include <vector>
#include <memory>


class ShapeCollection
{
    public:
        ShapeCollection() : totalArea(0), n_Spaces(0), n_Liters(0) {}
        double getTotalArea() const; 
        int get_nSpaces() const;
        int getLiters() const;
        void calulateTotalArea();
        void calulateLiters();
        
        template<typename T, typename... Args>
        void add(Args&&... args);
        
    private:
        std::vector<std::unique_ptr<Shape>> shapes;
        double totalArea;  // square meters
        int n_Spaces;      // number of composite spaces
        int n_Liters;  // liters, rounded up to the next whole number
};

class Shape
{
    public:
        Shape() : area(0) {}
        virtual ~Shape() = default;
        virtual void calcArea() = 0;
        double getArea() const;

    protected:
        double area;  // square meters
};

class Rectangle : public Shape
{
    public:
        Rectangle(int length, int width) : Shape(), length(length), width(width) {}
        int getLength() const;
        int getWidth() const;
        void calcArea() override;

    private:
        int length;  // millimeters
        int width;   // millimeters
};

class Circle : public Shape
{
    public:
        Circle(int diameter) : Shape(), diameter(diameter) {}
        int getDiameter() const;
        void calcArea() override;

    private:
        int diameter;  // millimeters
};