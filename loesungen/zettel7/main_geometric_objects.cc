#include <iostream>
#include "rectangle.h"
#include "sphere.h"
#include "circle.h"
#include "cuboid.h"
#include "cube.h"
#include "square.h"

using namespace std;


void printClass(std::string s, const double x, const double y)
{
    cout.width(12);
    cout << s;
    cout.width(12);
    cout << x;
    cout.width(12);
    cout << y << endl;
}

int main()
{
    Rectangle rect1 (1.0, 2.0);
    Square square1(1.0);
    Circle circle1(3.0);
    Sphere sphere1(2.0);
    Cube cube1(2.0);
    Cuboid cuboid1(3.0, 2.0, 2.0);

    cout.width(12);
    cout << "Type";
    cout.width(12);
    cout << "Circum";
    cout.width(12);
    cout << "Area" << endl;

    printClass("Rectangle", rect1.getCircumference(), rect1.getArea());
    printClass("Square", square1.getCircumference(), square1.getArea());
    printClass("Circle", circle1.getCircumference(), circle1.getArea());
    cout << endl;
    
    cout.width(12);
    cout << "Type";
    cout.width(12);
    cout << "Surface";
    cout.width(12);
    cout << "Volume" << endl;

    printClass("Cuboid", cuboid1.getSurfaceArea(), cuboid1.getVolume());
    printClass("Cube", cube1.getSurfaceArea(), cube1.getVolume());  
    printClass("Sphere", sphere1.getSurfaceArea(), sphere1.getVolume());

    cout << endl;
    return 0;
}