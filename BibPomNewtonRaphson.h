#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>

using namespace std;

class BibPomNewtonRaphson
{
public:
	BibPomNewtonRaphson();
	~BibPomNewtonRaphson();


	double *arrayWspolczynniki;  // tablica na wzor funkcji  [x^3, x^2, ...]
	Point *arrayOfPoints;
	int ktoryStopienWielomianu;
	int xMin;
	int xMax;
	int n;
	int sizeOfArrayOfPoints;
	int iloscNienaturalnychPoteg;

	float *tabNienaturalnePotegi = new float[iloscNienaturalnychPoteg];
	float *tabWspolczynnikowPrzyNienaturalnychPotegach = new float[iloscNienaturalnychPoteg];

	double calculateMetodaProstokatow();
	void getWielomian();
	double getPoints(float zmiennaX);
	void test();

};



BibPomNewtonRaphson::BibPomNewtonRaphson()
{
}


BibPomNewtonRaphson::~BibPomNewtonRaphson()
{
}

inline double BibPomNewtonRaphson::calculateMetodaProstokatow()
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

inline void BibPomNewtonRaphson::getWielomian()
{
	cout << "Ktorego stopnia wielomian?" << endl;
	cin >> ktoryStopienWielomianu;
	//cout << "Podaj liczbe n, czyli ilosc aproksymujacych prostokatow (przedzialow) :" << endl;
	//cin >> n;
	cout << "Czy wielomian posiada potegi ujemne i niecalkowite? Podaj ich liczbe: " << endl;
	cin >> iloscNienaturalnychPoteg;

	arrayWspolczynniki = new double[(ktoryStopienWielomianu + 1)];


	double wspolczynnik;
	int j = ktoryStopienWielomianu;

	cout << "Wspolczynniki przy potegach naturalnych..." << endl;
	for (int i = ktoryStopienWielomianu; i >= 0; i--)
	{
		cout << "Podaj wspolczynnik stojacy przy X do potegi " << i << ": " << endl;
		cin >> wspolczynnik;
		arrayWspolczynniki[j] = wspolczynnik;
		j--;
	}
	if (iloscNienaturalnychPoteg != 0)
	{
		float potega;
		float wsp;
		cout << endl << "Wspolczynniki przy potegach nienaturalnych" << endl;



		for (int i = 0; i < iloscNienaturalnychPoteg; i++)
		{
			cout << "Podaj potege:" << endl;
			cin >> potega;
			cout << "Podaj wspolczynnik stojacy przy X do potegi " << potega << ": " << endl;
			cin >> wsp;
			tabNienaturalnePotegi[i] = potega;
			tabWspolczynnikowPrzyNienaturalnychPotegach[i] = wsp;
		}

	}


}

inline double BibPomNewtonRaphson::getPoints(float zmiennaX)
{

	double wynik = 0.0;
	for (int j = ktoryStopienWielomianu; j >= 0; j--)
	{
		wynik += (arrayWspolczynniki[j] * pow(zmiennaX, j));
	}
	if (iloscNienaturalnychPoteg != 0)
	{
		for (int i = 0; i < iloscNienaturalnychPoteg; i++)
		{
			wynik += (tabWspolczynnikowPrzyNienaturalnychPotegach[i] * pow(zmiennaX, tabNienaturalnePotegi[i]));
		}
	}
	return wynik;
}

inline void BibPomNewtonRaphson::test()
{
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		cout << "Wartosc x: " << arrayOfPoints[i].x << "   Wartosc y: " << arrayOfPoints[i].y << endl;
	}
}
