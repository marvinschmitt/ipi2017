#include <iostream>
using namespace std;
const float mein_pi = 3.1415927; // dürfen wir pi aus cmath nutzen?

int circumference_rectangle(int a, int b)
{
	return (2*a + 2*b);
}

int area_rectangle(int a, int b)
{
	return a*b;
}

int circumference_square(int a)
{
	return 4*a;
}

int area_square(int a)
{
	return a*a;
}

float circumference_circle(float r)
{
	return mein_pi*r*2;				
}

float area_circle(float r)
{
	return mein_pi*r*r;
}

int surface_area_cuboid(int a, int b, int c)
{
	return (2*a*b + 2*a*c + 2*b*c);
}

int volume_cuboid(int a, int b, int c)
{
	return a*b*c;
}

int surface_area_cube(int a)
{
	return 6*a*a;
}

int volume_cube(int a)
{
	return a*a*a;
}

float surface_area_sphere(float r)
{
	return mein_pi*r*r*4;
}

float volume_sphere(float r)
{
	return mein_pi*r*r*r*(4/3);
}

int main()
{
	int n, form, a, b, c;
	float r;


	cout << "Geben Sie die Dimensionen ein: ";
	cin >> n;
	if (n == 2)
	{
		cout << endl << "Welches Objekt möchten Sie betrachten?" << endl << "0 - Rechteck" << endl << "1 - Quadrat" << endl << "2 - Kreis" << endl;
		cin >> form;
		switch (form)
		{
			case 0:
				cout << endl << "Geben Sie die Seitenlängen des Rechtecks ein." << endl;
				cin >> a >> b;
				cout << "Das Rechteck hat einen Umfang von " << circumference_rectangle(a, b) << " und eine Fläche von " << area_rectangle(a, b) << endl;
				break;
			case 1:
				cout << endl << "Geben Sie die Seitenlänge des Quadrats ein." << endl;
				cin >> a;
				cout << "Das Quadrat hat einen Umfang von " << circumference_square(a) << " und eine Fläche von " << area_square(a) << endl;
				break;
			case 2:
				cout << endl << "Geben Sie den Radius des Kreises ein." << endl;
				cin >> r;
				cout << "Der Kreis hat einen Umfang von " << circumference_circle(r) << " und eine Fläche von " << area_circle(r) << endl;
				break;
			default:
				cout << endl << "Fehler! Sie müssen 0, 1 oder 2 eingeben. Das Programm wird nun beendet." << endl;
		}

	}

	else if (n == 3)
	{
		cout << endl << "Welches Objekt möchten Sie betrachten?" << endl << "0 - Quader" << endl << "1 - Würfel" << endl << "2 - Kugel" << endl;
		cin >> form;
		switch (form)
		{
			case 0:
				cout << endl << "Geben Sie die Seitenlängen des Quaders ein." << endl;
				cin >> a >> b >> c;
				cout << "Der Quader hat eine Oberfläche von " << surface_area_cuboid(a, b, c) << " und ein Volumen von " << volume_cuboid(a, b, c) << endl;
				break;
			case 1:
				cout << endl << "Geben Sie die Seitenlänge des Würfels ein." << endl;
				cin >> a;
				cout << "Der Würfel hat eine Oberfläche von " << surface_area_cube(a) << " und ein Volumen von " << volume_cube(a) << endl;
				break;
			case 2:
				cout << endl << "Geben Sie den Radius der Kugel ein." << endl;
				cin >> r;
				cout << "Der Kreis hat eine Oberfläche von " << surface_area_sphere(r) << " und ein Volumen von " << volume_sphere(r) << endl;
				break;
			default:
				cout << endl << "Fehler! Sie müssen 0, 1 oder 2 eingeben. Das Programm wird nun beendet." << endl;
		}
	}

	else cout << endl << "Fehler! Sie müssen 2 oder 3 eingeben. Das Programm wird nun beendet." << endl;


return 0;
}