#pragma once
#include "Point.h"
#include <math.h>
#include <iostream>
#include "MetodaTrapezow.h"


class MainMetodaTrapezow
{
public:
	MainMetodaTrapezow();
	~MainMetodaTrapezow();
	void main();
};



MainMetodaTrapezow::MainMetodaTrapezow()
{
}


MainMetodaTrapezow::~MainMetodaTrapezow()
{
}

inline void MainMetodaTrapezow::main()
{
	MetodaTrapezow m;

	m.getWielomian();
	m.getPoints();
	m.test();

	cout << "Wynik calkowania metoda prostokatow:  " << m.calculateMetodaTrapezow() << endl;
}
