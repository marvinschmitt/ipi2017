#pragma once 
#include "sphere.h"

class Circle : public Sphere
{
    
public:
    Circle();
    Circle(double r);
    double getArea() const;
    double getCircumference() const;
};