#pragma once 

class Cuboid
{
protected:
    double width, height, length;

public:
    Cuboid();
    Cuboid(double w, double h, double l);

    void setWidth(double w);
    void setHeight(double h);
    void setLength(double l);

    double getWidth() const;
    double getHeight() const;
    double getLength() const;

    double getVolume() const;
    double getSurfaceArea() const;
};