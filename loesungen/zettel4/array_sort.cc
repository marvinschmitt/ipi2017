#include <iostream>
using namespace std;

int main()
{
	int a[] = {12, 6, 10, 2, 1, 22, 4, 16, 12, 7};			// Definition & Initialisierung des Arrays
	int kleinstesElementSubgruppe;							// Kleinstes Element im aktuellen Zielbereich {a[i], ..., a[aLength - 1]}
	int kleinstesElementSubgruppeStelle;					// Für Dreieckstausch
	int aLength = sizeof(a) / sizeof(a[0]);					// Länge des Arrays entspricht Speicher des Arrays geteilt durch Speicher eines Elements

	for (int i = 0; i < aLength; i++)						// i gibt die Stelle an, an die sortiert wird (0 kleinstes, 1 zweitkleinstes etc.)
	{
		for (int j = i; j < aLength; j++)					// j gibt die Stelle an, die gerade geprüft wird
		{
			if (j == i) kleinstesElementSubgruppe = a[j];	// zunächst wird das erste Element als kleinstes angenommen
			if (a[j] < kleinstesElementSubgruppe)
			{
				kleinstesElementSubgruppe = a[j];			// falls ein Element kleiner als das aktuell kleinste ist, wird es das neue kleinste
				kleinstesElementSubgruppeStelle = j;		// Merke dir die Stelle, an der das kleinste Element ist - damit man das Element an Stelle i dorthin schieben kann
			}
		}
		a[kleinstesElementSubgruppeStelle] = a[i];			// DREIECKS-
		a[i] = kleinstesElementSubgruppe;					// TAUSCH


	}

	for (int p = 0; p < aLength; p++)						// Array ausgeben
	{
		cout << "Eintrag " << p+1 << ": " << a[p] << endl;
	}


return 0;
}