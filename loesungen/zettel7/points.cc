#include <iostream>
#include <cmath>
using namespace std;

class Point2D {
protected:
  double x, y;
  
public:
  Point2D();
  Point2D(double xNew, double yNew);

  void setX(double xNew);
  void setY(double yNew);
  double getX() const;
  double getY() const;

  double calcDistance(const Point2D& newPoint) const;
};

  Point2D::Point2D(): x(0), y(0){}
  Point2D::Point2D(double xNew, double yNew): x(xNew), y(yNew){}

  void Point2D::setX(double xNew)
  {
    x = xNew;
  }

  void Point2D::setY(double yNew)
  {
    y = yNew;  
  }

  double Point2D::getX() const
  {
    return this->x;
  }

  double Point2D::getY() const
  {
    return this->y;
  }



double Point2D::calcDistance(const Point2D& newPoint) const
  {
    return sqrt(pow(this->x - newPoint.x, 2) + pow(this->y - newPoint.y, 2));
  }


class Point3D : public Point2D {
private:
  double z;

public:
  Point3D();
  Point3D(double xNew, double yNew, double zNew);

  void setZ(double zNew);
  double getZ() const;
  double calcDistance(const Point3D& newPoint) const;

};

Point3D::Point3D(){
  x = 0;
  y = 0;
  z = 0;
}
Point3D::Point3D(double xNew, double yNew, double zNew)
{
  x = xNew;
  y = yNew;
  z = zNew;
} 

void Point3D::setZ(double zNew)
{
  z = zNew;
}

double Point3D::getZ() const
{
  return this->z;
}

double Point3D::calcDistance(const Point3D& newPoint) const
{
  return sqrt(pow(this->x - newPoint.x, 2) + pow(this->y - newPoint.y, 2) + pow(this->z - newPoint.z, 2));
}

// Die Access Settings für x,y (Point2D) müssen protected und nicht private sein - dann kann man von Point3D aus direkt darauf zugreifen.

int main() {
	Point2D P1 (2.0, 5.0);
  Point2D P2 (3.0, -3.0);
  cout << P1.calcDistance(P2) << endl
  Point3D P3 (2.0, 5.0, 4.0);
  P3.setX(2.0);
  P3.setY(5.0);
  P3.setZ(4.0);
  Point3D P4(3.0, -3.0, 0.0);
  cout << P3.calcDistance(P4) << endl;
  return 0;
}
