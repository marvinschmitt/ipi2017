#include "cuboid.h"

Cuboid::Cuboid() : width(0), height(0), length(0) {};
Cuboid::Cuboid(double w, double h, double l) : width(w), height(h), length(l) {};

void Cuboid::setWidth(double w) {this->width = w;}
void Cuboid::setHeight(double h) {this->height = h;}
void Cuboid::setLength(double l) {this->length = l;}

double Cuboid::getWidth() const {return this->width;}
double Cuboid::getHeight() const {return this->height;}
double Cuboid::getLength() const {return this->length;}

double Cuboid::getVolume() const {return this->width * this->height * this->length;}
double Cuboid::getSurfaceArea() const {return 2 * (this->width * this->height + this->height * this->length + this->length * this->width);}