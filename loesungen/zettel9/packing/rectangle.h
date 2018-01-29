#include <iostream>
#include <string>
using namespace std;

class Point {
private:
  double x,y;

public:
  Point () : x(0.), y(0.) {}
  Point (double xNew, double yNew) : x(xNew), y(yNew) {}

  double getX () const { return x; }
  double getY () const { return y; }

  // teste, ob zwei Punkte gleich sind
  bool operator== (Point const& other) const {
    return getX() == other.getX() && getY() == other.getY();
  }

  // teste, ob zwei Punkte ungleich sind
  bool operator!= (Point const& other) const {
    return getX() != other.getX() || getY() != other.getY();
  }

  // erzeuge neuen Punkt mit vertauschten x- und y-Koordinaten
  Point transpose() const {
    Point res(getY(), getX());
    return res;
  }

  // erzeuge neuen Punkt, der um Vektor v verschoben ist
  Point translate (Point const& v) const {
    Point res(getX()+v.getX(), getY()+v.getY());
    return res;
  }
};

// wandle den Punkt in einen String der Form "[x, y]"
string to_string (Point const& p) {
  return "[" + std::to_string(p.getX()) + ", " + std::to_string(p.getY()) + "]";
}

class Rectangle {
private:
  Point p0; // linke untere Ecke
  Point p1; // rechte obere Ecke

public:
  Rectangle() {}
  Rectangle(Point const& p1New) : p1(p1New) {}
  Rectangle(Point const& p0New, Point const& p1New) :
    p0(p0New), p1(p1New) {}

  Point const& getP0 () const { return p0; }
  Point const& getP1 () const { return p1; }

  double getX0 () const { return p0.getX(); }
  double getX1 () const { return p1.getX(); }
  double getY0 () const { return p0.getY(); }
  double getY1 () const { return p1.getY(); }

  double width () const { return p1.getX()-p0.getX(); }
  double height () const { return p1.getY()-p0.getY(); }

  bool is_valid () const { return getX0() <= getX1() && getY0() <= getY1(); }

  double area() const {
    if (is_valid()) {
      return width()*height();
    }
    else {
      return -1;
    }
  }

  Rectangle transpose () const {
    Rectangle res(p0.transpose(), p1.transpose());
    return res;
  }

  Rectangle translate (Point const& v) const {
    Rectangle res(p0.translate(v), p1.translate(v));
    return res;
  }

  bool contains (Point const& p) const {
    return p.getX() >= getX0() && p.getX() <= getX1()
        && p.getY() >= getY0() && p.getY() <= getY1();
  }


  void print() const
  {
    cout << to_string(this->p0);
    cout << ", ";
    cout << to_string(this->p1);
    cout << endl;
  }
};

string to_string (Rectangle const& r) {
  return "[" + std::to_string(r.getX0()) + ":" + std::to_string(r.getY0()) + ", "
      + std::to_string(r.getX1()) + ":" + std::to_string(r.getY1()) + "]";
}

Rectangle rectangle_union (Rectangle const& r1, Rectangle const& r2) {
  Point lowerLeft (min(r1.getX0(), r2.getX0()), min(r1.getY0(), r1.getY0()));
  Point upperRight (max(r1.getX1(), r2.getX1()), max(r1.getY1(), r1.getY1()));
  return Rectangle(lowerLeft, upperRight);
}

Rectangle rectangle_intersection (Rectangle const& r1, Rectangle const& r2) {
  Point lowerLeft (max(r1.getX0(), r2.getX0()), max(r1.getY0(), r1.getY0()));
  Point upperRight (min(r1.getX1(), r2.getX1()), min(r1.getY1(), r1.getY1()));
  return Rectangle(lowerLeft, upperRight);
}
