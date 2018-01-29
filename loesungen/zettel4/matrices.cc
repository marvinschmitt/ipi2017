#include <iostream>
using namespace std;

const int N = 20;

void abstand()
{
	cout << endl << endl << endl;
}

void matrix_print(int a[N][N], int c)	// c = columns (Anzahl Zeilen/Spalten der Matrix), die auch tatsächlich besetzt sind.
	{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout.width(3);
			cout << a[i][j];			
		}
		cout << endl;
	}
}



void matrix_zero(int a[N][N], int c)			// c = columns (Anzahl Zeilen/Spalten der Matrix), die auch tatsächlich besetzt sind.
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = 0;
		}
	}
}


void matrix_id(int a[N][N], int c)				// c = columns (Anzahl Zeilen/Spalten der Matrix), die auch tatsächlich besetzt sind.
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = 0;
			if (i == j) a[i][j] = 1;
		}
	}
}


void matrix_diagonal(int a[N][N], int c, int* werte)		// c = columns (Anzahl Zeilen/Spalten der Matrix), die auch tatsächlich besetzt sind.
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a[i][j] = 0;
			if (i == j) a[i][j] = werte[i];
		}
	}
}


void matrix_add(int summand1[N][N], int summand2[N][N], int summe[N][N], int c)		// Input: summand1/2, Output: summe
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			summe[i][j] = summand1[i][j] + summand2[i][j];
		}
	}	
}


void matrix_subtract(int minuent1[N][N], int minuent2[N][N], int differenz[N][N], int c)	// Input: minuent1/2, Output: differenz
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			differenz[i][j] = minuent1[i][j] - minuent2[i][j];
		}
	}	
}

void matrix_transpose(int a[N][N], int a_transposed[N][N], int c)		// Input: a, Output: a_transposed
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			a_transposed[i][j] = a[j][i];
		}
	}		
}

void matrix_multiply(int faktor1[N][N], int faktor2[N][N], int produkt[N][N], int c)		// Input: faktor1/2, Output: produkt
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int u = 0; u < c; u++)
			{
				produkt[i][j] += faktor1[i][u] * faktor2[u][j];
			}
		}
	}


}


int matrix_trace(int a[N][N], int c)
{
	int trace = 0;
	for (int i = 0; i < c; i++)
	{
			trace += a[i][i];
	}
	return trace;
}


int main()
{
	int nullmatrix[N][N];	
	int einheitsmatrix[N][N];
	int diagonalmatrix[N][N];
	int summe[N][N];
	int differenz[N][N];
	int A_transposed[N][N];
	int produkt[N][N];
	int A[N][N] = {{2, 5, 4}, {3, 2, 4}, {1, 1, 0}};
	int B[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


	int columns;
	cout << "Wie viele Zeilen/Spalten soll die quadratische Matrix haben? ";
	cin >> columns;
	cout << endl;

	// Nullmatrix
	cout << endl << "Nullmatrix: " << endl;
	matrix_zero(nullmatrix, columns);
	matrix_print(nullmatrix, columns);

	abstand();

	// Einheitsmatrix
	cout << endl << "Einheitsmatrix: " << endl;
	matrix_id(einheitsmatrix, columns);
	matrix_print(einheitsmatrix, columns);

	abstand();

	// Diagonalmatrix
	cout << "Initialisierung der Diagonalmatrix: " << endl;		// Idee: Zielwerte (durch Benutzerin eingegeben) werden in einem Array eingespeichert (Größe: n).
	int werte[columns];
	
	for (int i = 0; i < columns; i++)
	{
		cout << "Wert " << i+1 << ": ";
		cin >> werte[i];
	}
	cout << endl << "Diagnoalmatrix: " << endl;
	matrix_diagonal(diagonalmatrix, columns, werte);
	matrix_print(diagonalmatrix, columns);

	abstand();

	// Summe aus A und B
	cout << endl << "Summe aus A und B: " << endl;
	matrix_add(A, B, summe, 3);
	matrix_print(summe, 3);

	abstand();

	// Differenz aus A und B
	cout << endl << "Differenz aus A und B: " << endl;
	matrix_subtract(A, B, differenz, 3);
	matrix_print(differenz, 3);

	abstand();

	//Transpose
	cout << endl << "Transponierte von A: " << endl;
	matrix_transpose(A, A_transposed, 3);
	matrix_print(A_transposed, 3);

	abstand();

	// Spur von A
	cout << endl << "Spur von A: " << matrix_trace(A, 3) << endl;

	abstand();

	// Multiplikation
	cout << endl << "A x B: " << endl;
	matrix_multiply(A, B, produkt, 3);
	matrix_print(produkt, 3);

/* 	Um nicht-quadratische Matrizen zu multiplizieren:
	Überprüfen, ob die Anzahl der Zeilen/Spalten übereinstimmen (Zeilen1 = Spalten2)
	Außerdem müssen mehrere Zählervariablen (Obergrenzen) übergeben werden.
*/

}