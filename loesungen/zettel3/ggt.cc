#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
  int a = 123, b = 1968;  // die ganzen Zahlen, deren ggT berechnet werden soll
  int ggt = 0;   // Variable zum Speichern des ggT


  while (true)
  {
  	if (a==0)
  	{
  	  ggt = b;
  	  break;
  	}

  	if (b==0)
  	{
  	  ggt = a;
  	  break;
  	}

  	if (a>b)
  	{
  	  a = a-b;
  	}

  	else
  	{
  	  b = b-a;
  	}

  }

  
  cout << "Der groesste gemeinsame Teiler ist:  " << ggt << endl;
  
  return 0;
}
