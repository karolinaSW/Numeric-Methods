#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>

using namespace std;

class BibPomBisekcja
{
public:
	BibPomBisekcja();
	~BibPomBisekcja();

	double *arrayWspolczynniki;  // tablica na wzor funkcji  [x^3, x^2, ...]
	Point *arrayOfPoints;
	int ktoryStopienWielomianu;
	int xMin;
	int xMax;
	int n;
	int sizeOfArrayOfPoints;


	double calculateMetodaProstokatow();
	void getWielomian();
	double getPoints(float zmiennaX);
	void test();
};



BibPomBisekcja::BibPomBisekcja()
{
}


BibPomBisekcja::~BibPomBisekcja()
{
}

inline double BibPomBisekcja::calculateMetodaProstokatow()
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

inline void BibPomBisekcja::getWielomian()
{
	cout << "Ktorego stopnia wielomian?" << endl;
	cin >> ktoryStopienWielomianu;
	//cout << "Podaj liczbe n, czyli ilosc aproksymujacych prostokatow (przedzialow) :" << endl;
	//cin >> n;

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

inline double BibPomBisekcja::getPoints(float zmiennaX)
{
	double wynik = 0.0;
	for (int j = ktoryStopienWielomianu; j >= 0; j--)
	{
		wynik += (arrayWspolczynniki[j] * pow(zmiennaX, j));
	}
	return wynik;
}

inline void BibPomBisekcja::test()
{

	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		cout << "Wartosc x: " << arrayOfPoints[i].x << "   Wartosc y: " << arrayOfPoints[i].y << endl;
	}
}
