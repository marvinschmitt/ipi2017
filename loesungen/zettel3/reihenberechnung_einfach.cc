// Diese Version ist intuitiv und leichter lesbar.
// In der Version "komplex" wird der Hinweis umgesetzt, Teil B in Teil A zu berechnen. Außerdem ist das Abbruchkriterium zielorientierter umgesetzt.


#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  double summeTeilA, summeTeilB; // Variablen zum Speichern
  int i=1,sign=1;                       // i Laufvariable, sign Vorzeichenvariable für B



	for (i; i <=1000; i++) {

		summeTeilA += 1.0/(i*i);

	}	
  
  cout << "Die Summe aus Teil a ergibt:  " << summeTeilA << endl;
  
	for (i=1; i <=1000; i++){

		sign *= -1;
		summeTeilB += sign* 1.0/(i*i);

	}  		
  
  cout << "Die Summe aus Teil b ergibt:  " << summeTeilB << endl;
  
  return 0;
}

