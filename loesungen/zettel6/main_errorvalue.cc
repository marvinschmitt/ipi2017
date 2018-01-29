// main_errorvalue.cc

#include <iostream>
#include "errorvalue.h"

using namespace std;

int main()
{
	ErrorValue a(10.0, 2.0), b(5.0, 1.0);

	ErrorValue s = a + b;

	cout << "s = ";
//	cout << s.value() << " +- " << s.absolute() << " (" << s.relative() * 100 << " %)" << endl;
	s.print();
	cout << endl << endl;

	double A[] = {10.0, 10.2, 10.8, 10.1, 9.6, 10.2, 9.9, 10.3};
	int len_A = sizeof(A) / sizeof(A[0]);
	double B[] = {14.2, 15.0, 13.8, 14.5, 14.8, 14.5, 13.9, 14.1, 14.5, 14.2};
	int len_B = sizeof(B) / sizeof(B[0]);
	double C[] = {11.3, 10.8, 11.1, 11.0, 11.6, 10.8, 10.7, 11.8, 12.0};
	int len_C = sizeof(C) / sizeof(C[0]);

/*
//	OHNE friend-Funktion außerhalb der Klasse ErrorValue - man muss die Funktion auf einem "leeren" Objekt ausführen

	ErrorValue a_err;
	a_err = a_err.fromMeasurements(A, len_A);

	ErrorValue b_err;
	b_err = b_err.fromMeasurements(B, len_B);

	ErrorValue c_err;
	c_err = c_err.fromMeasurements(C, len_C);
*/


//	MIT friend-Funktion außerhalb der Klasse ErrorValue - man kann die Objekte direkt korrekt anlegen.

	ErrorValue a_err = fromMeasurements(A, len_A);

	ErrorValue b_err = fromMeasurements(B, len_B);

	ErrorValue c_err = fromMeasurements(C, len_C);

	cout << "a_err = ";
	a_err.print();
	cout << "b_err = ";
	b_err.print();
	cout << "c_err = ";
	c_err.print();

	ErrorValue d_err = a_err + b_err + c_err;
	cout << "d_err = a_err + b_err + c_err = ";
	d_err.print();

// 	--> Aggregation von Messwerten erhöht deren Genauigkeit.


}
