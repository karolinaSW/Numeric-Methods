#pragma once
#include <iostream>
#include "Point.h"
#include "BibPomSimpson.h"
#include <math.h>
using namespace std;

int xMin;
int xMax;



class MainSimpson
{
public:
	MainSimpson();
	~MainSimpson();
	void main();
};



MainSimpson::MainSimpson()
{
}


MainSimpson::~MainSimpson()
{
}

inline void MainSimpson::main()
{

	BibPomSimpson m;
	m.getWielomian();

	//-------------------------------------------------------------


	cout << "Podaj przedzial punktow X w postaci liczb calkowitych (najpierw najmniejszy X, potem najwiekszy X): ";
	cout << endl;
	cin >> xMin;
	cin >> xMax;

	int sizeOfArrayOfPoints;

	//double *arrayWspolczynniki;  // tablica na wzor funkcji  [x^3, x^2, ...]
	Point *arrayOfPoints;

	sizeOfArrayOfPoints = 0;

	for (int i = xMin; i <= xMax; i++)
	{
		sizeOfArrayOfPoints++;
	}
	double h = (xMax - xMin) / m.n;

	arrayOfPoints = new Point[sizeOfArrayOfPoints];
	int min = xMin;

	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		arrayOfPoints[i].x = double(min);
		min++;
	}

	for (int i = 1; i < m.n + 1; i++)
	{
		arrayOfPoints[i].x = arrayOfPoints[i - 1].x + h;
	}

	double wynik = 0;
	double calkaSkladowa = 0;

	

	for (int i = 0; i < sizeOfArrayOfPoints; i++)
	{
		arrayOfPoints[i].y = 0;
		for (int j = m.ktoryStopienWielomianu; j >= 0; j--)
		{
			arrayOfPoints[i].y += (m.arrayWspolczynniki[j] * pow(arrayOfPoints[i].x, j));
		}
	}



	for (int i = 0; i <= m.n - 1; i = i + 2)
	{
		calkaSkladowa = ((arrayOfPoints[i].y + 4 * arrayOfPoints[i + 1].y + arrayOfPoints[i + 2].y)*(h / 3));
		wynik = wynik + calkaSkladowa;
	}

	cout << "Wynik calki oznaczonej wynosi: " << wynik << endl;
}
