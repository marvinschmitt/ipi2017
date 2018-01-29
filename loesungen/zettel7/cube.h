#pragma once
#include "cuboid.h"
#include "square.h"
//#include "rectangle.h"

class Cube : public Cuboid, public Square       // Was soll uns die Klasse Square hier bringen? 
                                                // Cuboid ist hier sinnvoller - ein Würfel ist ein Quader mit gleichen Seitenlängen,
{                                               // Berechnungen für Quader kann man für den Würfel übernehmen.
private:                                        // Die Berechnungen mit den Methoden aus Square sind getVolume2() und getSurfaceArea2().
    double side;

public:
    Cube();
    Cube(double s);

    double getVolume2() const;
    double getSurfaceArea2() const;
};