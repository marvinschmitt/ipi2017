#include <iostream> //Bibliothek um Ein- und Ausgaben in der Konsole zu tätigen --> sehr mächtiges IO-Werkzeug
using namespace std; //Wir bewegen uns im namespace std (Standard-C++-Befehle), also müssen wir nicht immer std::cout etc. schreiben.

int main(int argc, char *argv[])
{
const int N = 10;


cout << "1 steht links oben:" << endl;
for (int i = 1; i<=N; i++)
{
	for (int j = 1; j<=N; j++)
	{
		cout.width(5);
		cout << i*j;
	}
cout << endl;
}


cout << endl << endl << endl << "1 steht jetzt links unten:" << endl;
for (int i = N; i>=1; i--)
{
	for (int j = 1; j<=N; j++)
	{
		cout.width(5);
		cout << i*j;
	}
cout << endl;
}


  return 0;
}

