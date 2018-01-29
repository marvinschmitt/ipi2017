// errorvalue.h

#pragma once

class ErrorValue
{
	double v, sd;		// v: Value, sd: Standard deviation

public:
	ErrorValue();
	ErrorValue(double new_v, double new_sd);
	~ErrorValue();

//	Aufgabenteil (a)
	double value();
	double absolute();
	double relative();

	ErrorValue operator+(const ErrorValue& errval);

	void print();


//	Aufgabenteil (b)
//	in-class Funktion
	ErrorValue fromMeasurements(const double* werte_array, const int N);

//	schöner: out-class friend Funktion. Man könnte es auch ohne friend machen, bräuchte dann allerdings Setter.
	friend ErrorValue fromMeasurements(const double* werte_array, const int N);

};

//	out-class Funktion
ErrorValue fromMeasurements(const double* werte_array, const int N);
