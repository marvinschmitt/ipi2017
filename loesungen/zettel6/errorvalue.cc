// errorvalue.cc

#include <iostream>
#include <cmath>
#include "errorvalue.h"

using namespace std;


ErrorValue::ErrorValue(){
	v = 0;
	sd = 0;
}

ErrorValue::ErrorValue(double new_v, double new_sd){
	v = new_v;
	sd = new_sd;
}

ErrorValue::~ErrorValue(){}

double ErrorValue::value()
{
	return v;
}

double ErrorValue::absolute()
{
	return sd;
}

double ErrorValue::relative()
{
	return sd/v;
}

ErrorValue ErrorValue::operator+(const ErrorValue& errval)
{
	ErrorValue erg;
	erg.v = v + errval.v;
	erg.sd = sqrt(pow(sd, 2)+pow(errval.sd, 2));
	return erg;
}

void ErrorValue::print()
{
	cout << (*this).value() << " +- " << (*this).absolute() << " (" << (*this).relative() * 100 << " %)" << endl;
}

ErrorValue ErrorValue::fromMeasurements(const double* werte_array, const int N)
	{
		ErrorValue erg;		// Wird standardmäßig mit (0, 0) angelegt.
		double mean = 0, std_dev_num = 0;

		for (int i = 0; i < N; i++)
		{
			mean += werte_array[i];
		}
		mean /= N;
		erg.v = mean;

		for (int i = 0; i < N; i++)
		{
			std_dev_num += pow((mean - werte_array[i]), 2);
		}
		erg.sd = sqrt(std_dev_num / (N - 1));

		return erg;
	}


ErrorValue fromMeasurements(const double* werte_array, const int N)
	{
		ErrorValue erg;		// Wird standardmäßig mit (0, 0) angelegt.
		double mean = 0, std_dev_num = 0;

		for (int i = 0; i < N; i++)
		{
			mean += werte_array[i];
		}
		mean /= N;
		erg.v = mean;

		for (int i = 0; i < N; i++)
		{
			std_dev_num += pow((mean - werte_array[i]), 2);
		}
		erg.sd = sqrt(std_dev_num / (N - 1));

		return erg;
	}
