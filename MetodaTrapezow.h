#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>

using namespace std;

class MetodaTrapezow
{
public:
	MetodaTrapezow();
	virtual ~MetodaTrapezow();

	double *arrayWspolczynniki;  // tablica na wzor funkcji  [x^3, x^2, ...]
	Point *arrayOfPoints;
	int ktoryStopienWielomianu;
	int xMin;
	int xMax;
	int n;
	int sizeOfArrayOfPoints;



	double calculateMetodaTrapezow();
	void getWielomian();
	void getPoints();
	void test();
};



MetodaTrapezow::MetodaTrapezow()
{
}


MetodaTrapezow::~MetodaTrapezow()
{
}



inline double MetodaTrapezow::calculateMetodaTrapezow()
{
	double wynik = 0.0;
	int dx = (xMax - xMin) / n;  // n to ilosc trapezow
	int index = dx;
	for (int i = 0; i <= n-1; i += index)
	{
		wynik += ((arrayOfPoints[i].y + arrayOfPoints[i+ index].y)/2);
	}

	return (wynik * dx);
}

inline void MetodaTrapezow::getWielomian()
{
	cout << "Ktorego stopnia wielomian?" << endl;
	cin >> ktoryStopienWielomianu;
	cout << "Podaj liczbe n, czyli ilosc aproksymujacych prostokatow:" << endl;
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

inline void MetodaTrapezow::getPoints()
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

inline void MetodaTrapezow::test()
{
	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		cout << "Wartosc x: " << arrayOfPoints[i].x << "   Wartosc y: " << arrayOfPoints[i].y << endl;
	}
}

