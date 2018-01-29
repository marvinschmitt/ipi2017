// main_myvector.cc

#include <iostream>
#include "myvector.h"
using namespace std;

int main()
{
	MyVector a;
	a.setValues(5.0, 0.0, 2.0);
	cout << "a = ";
	a.print();

	MyVector b (3.0, 1.0, 4.0);
	cout << "b = ";
	b.print();

	MyVector c (5.0, 3.0, 5.0);
	cout << "c = ";
	c.print();

	MyVector AB = b.subtract(a);
	MyVector BA = AB.mult(-1);
	MyVector BC = c.subtract(b);
	MyVector CB = BC.mult(-1);
	MyVector CA = a.subtract(c);
	MyVector AC = CA.mult(-1);


	if (AB.isOrthogonal(AC) || BA.isOrthogonal(BC) || CA.isOrthogonal(CB))
		cout << "Das Dreieck ABC ist rechtwinklig." << endl;
	else cout << "Das Dreieck ABC ist nicht rechtwinklig." << endl;
	cout << "W(AB AC) = " << AB.angle_deg(AC) << "°, " <<
			"W(BC BA) = " << BC.angle_deg(BA) << "°, " <<
			"W(CA CB) = " << CA.angle_deg(CB) << "°. " << endl;


//	vermeiden, dass man zwei floats auf Gleichheit prüft:
	float ab_len = AB.length(), bc_len = BC.length(), ca_len = CA.length();
	if ( isEqual(ab_len, bc_len) || isEqual(bc_len, ca_len) || isEqual(ca_len, ab_len))
		cout << "Das Dreieck ABC ist gleichschenklig." << endl;
	else cout << "Das Dreieck ABC ist nicht gleichschenklig." << endl;
	cout << "|AB| = " << AB.length() << " ," <<
			"|BC| = " << BC.length() << " ," <<
			"|CA| = " << CA.length() << "." << endl;

	float area1 = AB.area(AC) / 2;

	cout << "Flächeninhalt des Dreiecks ABC: " << area1 << endl;


//	Ich verstehe die Aufgabe so, dass wir die Ortsvektoren mit 2 multiplizieren sollen?
//	Wenn wir die Seitenlängen multiplizieren sollen, wäre der Ausdruck (AB.mult(2).area(AC.mult(2))) / 2.


	MyVector a2 = a.mult(2);
	MyVector b2 = b.mult(2);
	MyVector c2 = c.mult(2);
	MyVector AB2 = b2.subtract(a2);
	MyVector AC2 = c2.subtract(a2);
	float area2 = AB2.area(AC2) / 2;
	cout << "Flächeninhalt des Dreiecks mit verdoppelten Ortsvektoren: " << area2 << endl;
	cout << "Der Flächeninhalt hat sich also um den Faktor " << area2/area1 << " erhöht." << endl;
	return 0;
}
