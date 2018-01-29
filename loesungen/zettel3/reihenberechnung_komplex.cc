#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  double summeTeilA = 0;
  double summeTeilB = 0; // Variablen zum Speichern
  double summand = 0;
  double k; //damit k auch außerhalb der for-Schleife verfügbar ist
  int k_int;
  double summeAltA = 1;
  double genauigkeitsZugewinn = 1; //wird als 1 initialisiert, damit das Abbruchkriterium nicht sofort erreicht ist (z.B. bei Initialisierung: SummeTeilA = 0 und Genauigkeitszugewinn = 0)

  for(k = 1; genauigkeitsZugewinn > 0.0000000001; k++) //Abbruchkriterium: wenig Genauigkeitszugewinn
  {
  	summeAltA = summeTeilA;
  	summand = 1/(k*k);
  	summeTeilA += summand;

  	k_int = k; // die %-Funktion erlaubt nur Variablen vom Typ int. Leider dürfen wir die fmod()-Funktion nicht benutzen.
  	if (k_int%2 == 0) 
  	{
  	  summeTeilB += summand;
  	}

  	else 
  	{
  	  summeTeilB -= summand;
  	}

  	genauigkeitsZugewinn = ((summeAltA - summeTeilA) * (summeAltA - summeTeilA)); //leider darf man hier ja kein abs() benutzen.
  }
  
  cout << "Die Summe aus Teil a ergibt:  " << summeTeilA << endl;  
  cout << "Die Summe aus Teil b ergibt:  " << summeTeilB << endl;
  cout << "Es wurden " << k << " Iterationen berechnet." << endl;
  
  return 0;
}

