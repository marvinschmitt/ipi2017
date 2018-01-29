#include "sphere.h"

Sphere::Sphere() {this->radius = 0;}

Sphere::Sphere(double r) {this->radius = r;}

void Sphere::setRadius(double r) {this->radius = r;}

double Sphere::getRadius() const {return this->radius;}

double Sphere::getVolume() const {return pow(this->radius, 3)*(4/3)*my_pi;}

double Sphere::getSurfaceArea() const {return pow(this->radius, 2)*my_pi*4;}