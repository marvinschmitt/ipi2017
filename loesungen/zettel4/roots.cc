// Aufgabe 4.4 (a): f(x) = x² - c hat die positive Nullstelle Wurzel(c).

#include <iostream>
#include <cmath>			// Nils (Tutor) hat gesagt, wir dürfen in Aufgabenteil d) die sqrt-Funktion nutzen um die Genauigkeit zu bestimmen.

using namespace std;

const double accuracy = 1.0e-12;		// Globale Variable mit gewünschter Genauigkeit

double f(double x, double c)		// Gibt den Wert von f(x) = x² - c aus
{
	return (x*x - c);
}


double newton_method(double c, double nullstelle)		// Funktion zieht die Wurzel aus c, Startwert ist nullstelle
{
	int k = 1;
	do 
	{
		nullstelle = 0.5*(nullstelle + (c/nullstelle));
		cout << "Iteration #" << k << ", Wert: " << nullstelle << endl;
		k++;
	} while (abs(nullstelle - sqrt(c)) > accuracy);		// Genauigkeit wird als Betrag ausgewertet, weil man sich je nach Startwerten von links oder rechts nähern kann.
	return k-1;
}


double bisection_method(double c, double a, double b)		// Nomenklatur nach Aufgabenblatt.
{
	double m;
	int k = 1;
	do
	{
		if (f(a, c) < 0 && 0 < f(b, c))					//
		{
			m = (a+b) / 2;								// hier könnte man auch überall m durch (a+b)/2 ersetzen und bräuchte die Variable m nicht, das würde aber ziemlich unübersichtlich..
			if (f(m, c) > 0) b = m;
			else if (f(m, c ) < 0) a = m;
			else cout << "Maximale Genauigkeit erreicht." << endl;	// Wenn sich die Werte nicht mehr ändern, ist die maximale Auflösung mit double erreicht oder die Wurzel ist als double darstellbar und genau berechnet.
			cout << "Iteration #" << k << ", Wert: " << m << endl;	// m ist die aktuellste Intervallhalbierung und wird deshalb als Schätzer verwendet.
		}
		else cout << "Maximale Genauigkeit erreicht." << endl;  // Wenn sich die Werte nicht mehr ändern, ist die maximale Auflösung mit double erreicht oder die Wurzel ist als double darstellbar und genau berechnet.
	k++;
	} while (abs(m - sqrt(c)) > accuracy);				// Genauigkeit wird als Betrag ausgewertet, weil man sich je nach Startwerten von links oder rechts nähern kann.
	return k-1;				
}


int main()
{
	double c;
	cout << "Von welcher natürlichen Zahl soll die Quadratwurzel berechnet werden? ";
	cin >> c;
	cout << newton_method(c, 4) << " Iterationen bei Newtonverfahren nötig." << endl;
	cout << "---########################---------------------########################---" << endl << endl << endl;
	cout << bisection_method(c, 0, 4) << " Iterationen bei Intervallhalbierung nötig." << endl;
	
	return 0;
}