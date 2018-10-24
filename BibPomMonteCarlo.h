#pragma once

#include "Point.h"
#include <math.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class BibPomMonteCarlo
{
public:
	BibPomMonteCarlo();
	~BibPomMonteCarlo();

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
};



BibPomMonteCarlo::BibPomMonteCarlo()
{
}


BibPomMonteCarlo::~BibPomMonteCarlo()
{
}

inline double BibPomMonteCarlo::calculateMetodaProstokatow()
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

inline void BibPomMonteCarlo::getWielomian()
{
	cout << "Ktorego stopnia wielomian?" << endl;
	cin >> ktoryStopienWielomianu;
	cout << "Podaj liczbe n, czyli ilosc punktow:" << endl;
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

inline void BibPomMonteCarlo::getPoints()
{
	cout << "Podaj przedzial punktow X w postaci liczb calkowitych (najpierw najmniejszy X, potem najwiekszy X): ";
	cout << endl;
	cin >> xMin;
	cin >> xMax;

	sizeOfArrayOfPoints = n;


	arrayOfPoints = new Point[sizeOfArrayOfPoints];
	int min = xMin * 100.0;
	int max = xMax * 100.0;
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		arrayOfPoints[i].x = ((rand() % (max + 1 - min)) + min) / 100.0;
		cout << "x " << i << " = " << arrayOfPoints[i].x << endl;
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

inline void BibPomMonteCarlo::test()
{
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		cout << "Wartosc x: " << arrayOfPoints[i].x << "   Wartosc y: " << arrayOfPoints[i].y << endl;
	}
}
