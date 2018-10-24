#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>
using namespace std;
class BibPomSimpson
{
public:

	double *arrayWspolczynniki;  // tablica na wzor funkcji  [x^3, x^2, ...]
	Point *arrayOfPoints;
	int ktoryStopienWielomianu;
	int xMin;
	int xMax;
	int n;
	int sizeOfArrayOfPoints;

	double calculateMetodaProstokatow();
	void getWielomian();
	void getPoints();
	void test();


	BibPomSimpson();
	~BibPomSimpson();
};



inline double BibPomSimpson::calculateMetodaProstokatow()
{
	double wynik = 0.0;
	int dx = (xMax - xMin) / n;
	int index = dx;
	for (int i = 1; i <= n; i++)
	{
		wynik += arrayOfPoints[index].y;
		index += dx;   // bo dx to mo¿e byc np. 2 tez. dx to szerokosc prostokata
	}

	return (wynik * dx);
}

inline void BibPomSimpson::getWielomian()
{
	cout << "Ktorego stopnia wielomian?" << endl;
	cin >> ktoryStopienWielomianu;
	cout << "Podaj liczbe n, czyli ilosc aproksymujacych prostokatow (przedzialow) :" << endl;
	cin >> n;

	arrayWspolczynniki = new double[(ktoryStopienWielomianu + 1)];


	double wspolczynnik;
	int j = ktoryStopienWielomianu;

	for (int i = ktoryStopienWielomianu; i >= 0; i--)
	{
		cout << "Podaj wspolczynnik stojacy przy X do potegi " << i << ": " << endl;
		cin >> wspolczynnik;
		arrayWspolczynniki[j] = wspolczynnik;
		j--;
	}

}

inline void BibPomSimpson::getPoints()
{
	cout << "Podaj przedzial punktow X w postaci liczb calkowitych (najpierw najmniejszy X, potem najwiekszy X): ";
	cout << endl;
	cin >> xMin;
	cin >> xMax;

	sizeOfArrayOfPoints = 0;

	for (int i = xMin; i <= xMax; i++)
	{
		sizeOfArrayOfPoints++;
	}

	arrayOfPoints = new Point[sizeOfArrayOfPoints];
	int min = xMin;
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		arrayOfPoints[i].x = double(min);
		min++;
	}
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		arrayOfPoints[i].y = 0;
		for (int j = ktoryStopienWielomianu; j >= 0; j--)
		{
			arrayOfPoints[i].y += (arrayWspolczynniki[j] * pow(arrayOfPoints[i].x, j));
		}
	}


}

inline void BibPomSimpson::test()
{
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		cout << "Wartosc x: " << arrayOfPoints[i].x << "   Wartosc y: " << arrayOfPoints[i].y << endl;
	}
}

BibPomSimpson::BibPomSimpson()
{
}


BibPomSimpson::~BibPomSimpson()
{
}

