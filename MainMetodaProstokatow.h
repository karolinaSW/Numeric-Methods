#pragma once
#include "MetodaProstokatow.h"

class MainMetodaProstokatow
{
public:
	MainMetodaProstokatow();
	~MainMetodaProstokatow();
	void main();
};



MainMetodaProstokatow::MainMetodaProstokatow()
{
}


MainMetodaProstokatow::~MainMetodaProstokatow()
{
}

inline void MainMetodaProstokatow::main()
{
	BibliotekaPomocniczaSimpson m;

	m.getWielomian();
	m.getPoints();
	m.test();

	cout << "Wynik calkowania metoda prostokatow:  " << m.calculateMetodaProstokatow() << endl;
}
