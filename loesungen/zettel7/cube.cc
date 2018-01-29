#include "cube.h"

Cube::Cube() : Cuboid() {}
Cube::Cube(double s) : Cuboid(s, s, s){};

double Cube::getVolume2() const
{
    return this->getArea() * this->side;
}

double Cube::getSurfaceArea2() const
{
    return this->getArea() * 6;
}