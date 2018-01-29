// myvector.h

#pragma once

class MyVector
{
private:
  float x,y,z;

public:
  // Konstruktoren und Dekonstruktor
  MyVector();
  MyVector(float newX, float newY, float newZ);
  ~MyVector();

  // Methoden der Klasse
  void print();

  void setValues(float newX, float newY, float newZ);
  void setX(float newX);
  void setY(float newY);
  void setZ(float newZ);

  float getX();
  float getY();
  float getZ();

  float length() const;

  MyVector add(const MyVector& vec);
  MyVector subtract(const MyVector& vec);

  MyVector mult(float scale);
  float dot(const MyVector& vec);
  MyVector cross(const MyVector& vec);


  float angle(const MyVector& vec);
  float angle_deg(const MyVector& vec);
  float area(const MyVector& vec);

  bool isOrthogonal(const MyVector& vec);
  bool isParallel(const MyVector& vec);
};


bool isEqual(float a, float b);
