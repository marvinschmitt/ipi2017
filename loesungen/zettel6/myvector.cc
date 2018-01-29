// myvector.cc

#include <cmath>
#include <iostream>
#include "myvector.h"

#define MY_PI 3.14159265358979f
#define PRECISION 0.0000001f


MyVector::MyVector()
{
	x = 0;
	y = 0;
	z = 0;
}

MyVector::MyVector(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

MyVector::~MyVector(){}


void MyVector::print()
{

	std::cout << "(" << x << "|" << y << "|" << z << ")" << std::endl;

/*
	cout << "(";
//	cout.width(3);
	cout << x << "|";
//	cout.width(3);
	cout << y << "|";
//	cout.width(3);
	cout << z << ")" << endl;
*/
}

void MyVector::setValues(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

void MyVector::setX(float newX)
{
	x = newX;
}

void MyVector::setY(float newY)
{
	y = newY;
}

void MyVector::setZ(float newZ)
{
	z = newZ;
}

float MyVector::getX()
{
	return x;
}

float MyVector::getY()
{
	return y;
}

float MyVector::getZ()
{
	return z;
}

float MyVector::length() const
{
	return (float)sqrt(x*x + y*y + z*z);
}

MyVector MyVector::add(const MyVector& vec)
{
	MyVector erg;
	erg.x = x + vec.x;
	erg.y = y + vec.y;
	erg.z = z + vec.z;

	return erg;
}

MyVector MyVector::subtract(const MyVector& vec)
{
	MyVector erg;
	erg.x = x - vec.x;
	erg.y = y - vec.y;
	erg.z = z - vec.z;

	return erg;
}

MyVector MyVector::mult(float c)
{
	MyVector erg;
	erg.x = x * c;
	erg.y = y * c;
	erg.z = z * c;

	return erg;
}

float MyVector::dot(const MyVector& vec)
{
	return x*vec.x + y*vec.y + z*vec.z;
}

MyVector MyVector::cross(const MyVector& vec)
{
	MyVector erg;
	erg.x = (y * vec.z) - (z * vec.y);		// Klammern sind nicht nötig, aber übersichtlich.
	erg.y = (z * vec.x) - (x * vec.z);
	erg.z = (x * vec.y) - (y * vec.x);

	return erg;
}

float MyVector::angle(const MyVector& vec)
{
	float erg;
	erg = (float)acos ( (*this).dot(vec) / ( (*this).length() * vec.length() ) );
	return erg;
}

float MyVector::angle_deg(const MyVector& vec)
{
	return (*this).angle(vec) * 180.0f / MY_PI;		// Ergebnis von angle() in Grad
}


float MyVector::area(const MyVector& vec)
{
	return ( (*this).cross(vec) ).length();
}


bool MyVector::isParallel(const MyVector& vec)
{
	if ((fabs(x/vec.x - y/vec.y) < PRECISION) && (fabs(y/vec.y - z/vec.z) < PRECISION) && (fabs(x/vec.x - z/vec.z) < PRECISION)) return true;
	else return false;
}

bool MyVector::isOrthogonal(const MyVector& vec)
{
	if ((*this).dot(vec) < PRECISION) return true;
	else return false;
}

bool isEqual(float a, float b)
{
	return ((fabs(a - b) < PRECISION))? true : false;
}
