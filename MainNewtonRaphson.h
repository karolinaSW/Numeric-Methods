#pragma once

#include "stdafx.h"
#include <iostream>
#include "BibPomNewtonRaphson.h"

using namespace std;

BibPomNewtonRaphson m;

class MainNewtonRaphson
{
public:
	MainNewtonRaphson();
	~MainNewtonRaphson();
	float pochodna(float);
	void main();
};



MainNewtonRaphson::MainNewtonRaphson()
{
}


MainNewtonRaphson::~MainNewtonRaphson()
{
}

inline float MainNewtonRaphson::pochodna(float zmiennaX)
{
	float wynik = 0;
	for (int i = m.ktoryStopienWielomianu; i > 0; i--) {
		wynik += m.arrayWspolczynniki[i] * pow(zmiennaX, i - 1) * i;
	}

	if (m.iloscNienaturalnychPoteg != 0)
	{
		for (int i = 0; i < m.iloscNienaturalnychPoteg; i++)
		{
			wynik += (m.tabWspolczynnikowPrzyNienaturalnychPotegach[i] * pow(zmiennaX, m.tabNienaturalnePotegi[i] - 1.0) * m.tabNienaturalnePotegi[i]);
		}
	}

	if (wynik == 0 || wynik == INFINITY)
	{
		cout << "Przyjmij inna wartosc 'a'. Powyzszy przypadek doprowadzil do dzielenia przez 0 :( " << endl;

		system("pause");
		exit(1);
	}
	else
	{
		return wynik;
	}
}

inline void MainNewtonRaphson::main()
{
	float dokladnosc = 0.0001;
	float a, b;
	float x1, x2, y, ya, yb;

	m.getWielomian();


	cout << "Podaj zakres (a, b)" << endl;
	cin >> a >> b;


	ya = m.getPoints(a);
	yb = m.getPoints(b);


	while (ya * yb >= 0)
	{
		cout << "Podaj inny przedzial (a, b)." << endl;
		cout << "f(a) i f(b) musza miec przeciwne znaki." << endl;

		cin >> a >> b;

		ya = m.getPoints(a);
		yb = m.getPoints(b);
	}

	x1 = a;
	y = m.getPoints(x1);
	if (abs(y) < dokladnosc)
	{
		x2 = x1;
	}
	else
	{
		while (abs(y) >= dokladnosc)
		{
			x2 = x1 - (m.getPoints(x1) / pochodna(x1));
			y = m.getPoints(x2);

			if (abs(y) < dokladnosc)
			{
				break;
			}
			x1 = x2;
		}

	}
	cout << "Pierwiastek (miejsce zerowe) funkcji wynosi: " << x2 << endl;

}
