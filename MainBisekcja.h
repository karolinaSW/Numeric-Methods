#pragma once

#include <iostream>
#include <cmath>
#include "Point.h"
#include "BibPomBisekcja.h"
using namespace std;


class MainBisekcja
{
public:
	MainBisekcja();
	~MainBisekcja();
	void main();
};



MainBisekcja::MainBisekcja()
{
}


MainBisekcja::~MainBisekcja()
{
}

inline void MainBisekcja::main()
{
	BibPomBisekcja m;
	m.getWielomian();



	// x^3 - 2x -4
	// miejsce zerowe y=0 x=2

	cout << "Podaj zakres (a, b)" << endl;
	float a, b;
	cin >> a >> b;

	float x, y, ya, yb;

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



	while (abs(a - b) > 0.01)
	{
		x = (a + b) / 2;
		y = m.getPoints(x);


		if (y == 0)
		{

			break;
		}
		else if (y*ya < 0)
		{
			b = x;
		}
		else
		{
			a = x;
		}

	}

	cout << "Znaleziono pierwiastek (miejsce zerowe) : x = " << ((a + b) / 2) << endl;


}
