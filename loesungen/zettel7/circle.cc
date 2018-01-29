#include "circle.h"

Circle::Circle() : Sphere() {}
Circle::Circle(double r) : Sphere(r) {}

double Circle::getArea() const {return my_pi * pow(this->radius, 2);}
double Circle::getCircumference() const {return 2 * my_pi * this->radius;}