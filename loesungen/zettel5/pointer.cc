#include <iostream>
using namespace std;

void absatz()
{
	cout << endl << "===============================================" << endl;

}

void swap1(double a, double b)		// Call by value --> a und b werden nur innerhalb von swap1() geändert.
{
	double tmp = a;
	a = b;
	b = tmp;

	cout << "In Swap 1. a: " << a << ", b: " << b <<endl;
}


void swap2(double& a, double& b)		// Call by Reference: Variablen werden global verändert (weil keine Kopie erstellt wird, sondern die Adressen der Variablen)
{
	double tmp = a;
	a = b;
	b = tmp;

	cout << "In Swap 2. a: " << a << ", b: " << b <<endl;
}


void swap3(double* a, double* b)		// Übergabe von Pointern auf a und b.
{
	double tmp = *a;
	*a = *b;
	*b = tmp;

	cout << "In Swap 3. a: " << *a << ", b: " << *b <<endl;
}

void swap3(char* a, char* b)		// Überladen der Funktion für (f)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}



double* maximum_value(double* a, int size)
{
	if (size == 0) return NULL;
	double* maxPtr = a;			// Start: 1. Element ist max.
	for (int i = 0; i < size; i++)
	{
		if (*(a+i) >= *maxPtr) maxPtr = a+i;
	}
	return maxPtr;
}


int length_string(const char* str)
{
	if (*str == 0) return 0;
	int len = 0;			// Laufvariable und Länge(return) zugleich
	do len++; while (*(str+len) != 0);

	return len;
}


void reverse_string(char* str)
{
	int len = length_string(str) - 1;

	for (int i = 0; i <= len/2; i++)	// Alternative wäre, eine Kopie von str zu erstellen und nicht zu swappen, sondern einfach iterativ die Werte aus der Kopie zu nehmen.
	{
		swap3(str+i, (str+len-i));		// Überladene Funktion swap3 nutzen.
	}
}

int main()
{
//	AUFGABENTEIL (a)
	double a = 42.0;
	double b;
	double* ptr_a = &a;
	*ptr_a = 42.42;

//	AUFGABENTEIL (b)
	int a1 = 15;
	int a2 = 20;
	int* p1 = &a1; 
	int* p2 = &a2;
	*p1 = *p2;			// a1 erhält den Wert von a2 --> a1 = a2 = 20. p1 zeigt auf a1, p2 zeigt auf a2.
	p1 = p2;			// p1 zeigt auf denselben Wert wie p2 --> p1 = p2 = &a2. Nach wie vor ist a1 = a2 = 20.


// 	AUFGABENTEIL (c)
	a = 7, b = 12;
	cout << "Vor Swap 1. a: " << a << ", b: " << b <<endl;
	swap1(a, b);
	cout << "Nach Swap 1. a: " << a << ", b: " << b <<endl;	
	
	absatz();

	a = 7, b = 12;
	cout << "Vor Swap 2. a: " << a << ", b: " << b <<endl;
	swap2(a, b);
	cout << "Nach Swap 2. a: " << a << ", b: " << b <<endl;	

	absatz();

	a = 7, b = 12;
	cout << "Vor Swap 3. a: " << a << ", b: " << b <<endl;
	swap3(&a, &b);
	cout << "Nach Swap 3. a: " << a << ", b: " << b <<endl;	

	absatz();

//	AUFGABENTEIL (d)

	double arr[5] = {1., 4., 12., 3., 5.};
	cout << "Die Adresse " << maximum_value(arr, 5) << " hat den Wert " << *maximum_value(arr, 5) << endl;

	absatz();

//	AUFGABENTEIL (e)
	char name[] = "Marvin und Erik";
	char* namePtr = name;
	cout << "\"" << name << "\" hat die Länge " << length_string(namePtr) << " (inkl. Leerzeichen)." << endl;

	absatz();


//	AUFGABENTEIL (f)
	cout << "\"" << name << "\" rückwärts ist \"";
	reverse_string(name);
	cout << name << "\"." << endl;

	return 0;


}