#include <iostream>

using namespace std;

int sum(int k)
{
	return (k > 1) ? k+sum(k-1) :  1;
}


void convert_decimal (int x, int p)		// Nomenklatur aus Algorithmus der Vorlesung vom 24.10.
{
	int y, z;
	if (x == 0) return;
	else
	{
		y = x / p;
		z = x % p;
		cout << z;
		convert_decimal(y, p);
	}
}


double square(double x)
{
	return x*x;
}

double power(double x, int n)
{
	if (n == 1) return x;
	else if (n % 2 == 0) return (square(power(x, n/2)));
	else if (n % 2 == 1) return (x*power(x, n-1));
	else {cerr << "FEHLER!" << endl; return -1;}
}


int main()
{
//	AUFGABE (a)
	cout << sum(12) << endl;
	
// 	AUFGABE (b)

	convert_decimal(1278, 2);	// gibt die Zahl in umgekehrter Reihenfolge aus.
	cout << endl;
	convert_decimal(1278, 8);	// gibt die Zahl in umgekehrter Reihenfolge aus.
	cout << endl;


//	AUFGABE (c)
	cout << power(12, 3) << endl;

/*	AUFGABE (c) TEXT:
	Es wäre eine schlechte Idee, weil es exponentiell mehr rekursive Funktionsaufrufe braucht. Pro Aufruf braucht es bei der nächsten "Stufe" ja wieder zwei Aufrufe der rekursiven Funktion.
	Wenn man square() nutzt, wird jedes Mal eine Hälfte des symmetrischen Baums gespart und durch eine Operation (Quadratur) ersetzt.
*/

	return 0;
}