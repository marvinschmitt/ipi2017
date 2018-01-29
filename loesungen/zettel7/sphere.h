#pragma once 
#include <cmath>
const double my_pi = 3.1415927;

class Sphere
{
protected:
    double radius;

public:
    Sphere();
    Sphere(double r);

    void setRadius(double r);
    double getRadius() const;
    double getVolume() const;
    double getSurfaceArea() const;
};