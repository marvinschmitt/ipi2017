#include "rectangle.h"

Rectangle::Rectangle() : width(0), height(0) {};
Rectangle::Rectangle(double w, double h) : width(w), height(h) {};

void Rectangle::setWidth(double w) { this->width = w; }
void Rectangle::setHeight(double h) { this->height = h; }
double Rectangle::getWidth() const {return this->width;}
double Rectangle::getHeight() const {return this->height;}

double Rectangle::getArea() const {return this->width * this->height;}
double Rectangle::getCircumference() const {return ( this->width + this->height ) * 2; 

}