#include <iostream>
#include <cmath> 						// in der Mitternachtsformel muss sqrt benutzt werden, deshalb wird an dieser Stelle cmath eingebunden.
using namespace std;

double number_of_solutions(double a, double b, double c)	// Determinante auswerten (Quelle: Wikipedia)
{
	double D = b*b - (4*a*c);
	if (D > 0) return 2;
	if (D == 0) return 1;
	else return 0;
}


float calc_one_solution(double a, double b, double c)
{
	return ((-b + sqrt(b*b - 4*a*c))/(2*a));		// Mitternachtsformel
}

float calc_two_solutions_plus(double a, double b, double c)
{
	return ((-b + sqrt(b*b - 4*a*c))/(2*a));		// Mitternachtsformel
}

float calc_two_solutions_minus(double a, double b, double c)	// Mitternachtsformel
{
	return ((-b - sqrt(b*b - 4*a*c))/(2*a));
}



int main()
{
	double a, b, c;			// Parameter der quadratischen Gleichung laut Zettel


	cout << "Bitte geben Sie a, b und c nach der folgenden Form ein: ax² + bx + c = 0." << endl;
	cout << "a: ";
	cin >> a;
	if (a == 0)		// wenn a = 0, ist die Gleichung keine quadratische Gleichung!
	{
		cout << "a darf nicht gleich Null sein! Programm wird nun beendet." << endl;
		return 1;
	}
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << endl;
	cout << "Die Gleichung " << a << "x² + " << b << "x + " << c << " = 0 hat ";
	if (number_of_solutions(a, b, c) == 0) 
		cout << "keine reele Lösung." << endl;
	else if (number_of_solutions(a, b, c) == 1)
		cout << "eine reele Lösung, nämlich " << calc_one_solution(a, b, c) << "." << endl;
	else if (number_of_solutions(a, b, c) == 2)
		cout << "zwei reele Lösungen, nämlich " << calc_two_solutions_plus(a, b, c) << " und " << calc_two_solutions_minus(a, b, c) << "." << endl;
	else 
	{
		cout << "Fehler! Programm wird nun beendet." << endl;
		return 1;
	}

	return 0;

}