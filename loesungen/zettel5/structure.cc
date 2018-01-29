#include <iostream>
#define num numerator				// Schreibarbeit sparen... Auf dem AB ist nur festgelegt, wie man die Fraction definieren soll, nicht, wie man sie danach aufruft.
#define den denominator

using namespace std;

struct Fraction
{
	double numerator, denominator;
};

int ggT(int a, int b)			// Kurzschreibweise des Euklid-Algorithmus
{
	return (b == 0)? a : ggT(b, a%b);
}

void check_den(Fraction a)		// PRüfen, ob Nenner = 0.
{
	if (a.den == 0) cerr << "FEHLER, NENNER IST NULL!!!" << endl;
}

void print(Fraction a)			// Print-Funktion
{
	check_den(a);
	cout << a.num << "/" << a.den << endl;
}

void reduce(Fraction& a)		// ggT finden, Zähler + Nenner durch ggT teilen.
{
	while (ggT(a.num, a.den) != 1)	
		{
			double teiler = (double)ggT(a.num, a.den);		
			a.num /= teiler;
			a.den /= teiler;
		}
}

Fraction sum(Fraction a, Fraction b)		// Brüche Nennergleich machen, Zähler addieren und dann kürzen.
{
	check_den(a);
	check_den(b);
	Fraction summe;
	summe.den = a.den * b.den;
	summe.num = a.num * b.den + b.num * a.den;
	reduce(summe);
	return summe;
}

Fraction mult(Fraction a, Fraction b)		// Jeweils Zähler und Nenner multiplizieren, dann kürzen.
{
	check_den(a);
	check_den(b);
	Fraction produkt;
	produkt.num = a.num * b.num;
	produkt.den = a.den * b.den;
	reduce(produkt);
	return produkt;
}

Fraction reciprocal(Fraction a)			// Zähler und Nenner tauschen (ginge auch manuell mit einer Variable tmp)
{
	check_den(a);
	swap(a.num, a.den);
	return a;
}


double decimal(Fraction a)			// Einfach ausrechnen und als double zurückgeben.
{
	check_den(a);
	return (a.num / a.den);
}


// Operatoren definieren, weil ich mir mit der Funktionsschreibweise unten viel zu unsicher war, ob ich nicht doch einen Fehler einbaue.

Fraction operator+(Fraction a, Fraction b)		
{
	return sum(a, b);
}

Fraction operator*(Fraction a, Fraction b)
{
	return mult(a, b);
}

Fraction operator/(Fraction a, Fraction b)
{
	return mult(a, reciprocal(b));
}

int main()
{
//	Die Brüche aus der Rechenaufgabe in Fractions definieren.
	Fraction u = {12, 53};
	Fraction v = {3, 4};
	Fraction w = {-1, 2};
	Fraction x = {1, 5};

//	Ohne Operatoren:
/*	Fraction e = mult(sum(u, mult(v, w)), reciprocal(x));
	cout << "Bruch: " << e.num << "/" << e.den << endl;
	cout << "Dezimal: " << decimal(e) << endl;
*/

//	Mit Operatoren:
	Fraction f = (u+(v*w))/x;
	cout << "Bruch: " << endl;
	print(f);
	cout << "Dezimal: " << decimal(f) << endl;


	return 0;
}