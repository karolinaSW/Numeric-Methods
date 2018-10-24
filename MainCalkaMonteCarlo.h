#pragma once
#include <iostream>
#include "Point.h"
#include "BibPomMonteCarlo.h"
class MainCalkaMonteCarlo
{
public:
	MainCalkaMonteCarlo();
	~MainCalkaMonteCarlo();
	void main();
};



MainCalkaMonteCarlo::MainCalkaMonteCarlo()
{
}


MainCalkaMonteCarlo::~MainCalkaMonteCarlo()
{
}

inline void MainCalkaMonteCarlo::main()
{
	srand(time(NULL));
	BibPomMonteCarlo m;
	m.getWielomian();
	m.getPoints();

	double wynik = 0;

	for (int i = 0; i < m.sizeOfArrayOfPoints; i++)
	{
		wynik += m.arrayOfPoints[i].y;
	}

	wynik /= m.n;

	cout << "Wynik calki Monte Carlo to:   " << wynik << endl;

}
