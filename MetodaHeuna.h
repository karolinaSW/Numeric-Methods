#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


class MetodaHeuna
{
public:
	MetodaHeuna();
	~MetodaHeuna();

	double funkcja(double x, double y);
	void dzialanie(double x0, double xk, double h, double y0);
	void menu();

};



MetodaHeuna::MetodaHeuna()
{
}


MetodaHeuna::~MetodaHeuna()
{
}


double MetodaHeuna::funkcja(double x, double y)
{
	return sin(x) - 3 * cos(y);
}



void MetodaHeuna::dzialanie(double x0, double xk, double h, double y0)
{

	double n = (xk - x0) / h;


	double* tabY = new double[n + 1];
	double* tabX = new double[n + 1];
	tabY[0] = y0;
	tabX[0] = x0;

	for (int i = 1; i <= n + 1; ++i)
	{
		tabX[i] = tabX[i - 1] + h;
	}

	for (int i = 1; i <= n + 1; ++i)
	{
		tabY[i] = (tabY[i - 1]) + (h / 2 * (funkcja(tabX[i - 1], tabY[i - 1]) + funkcja(tabX[i - 1] + h, tabY[i - 1] + h * funkcja(tabX[i - 1], tabY[i - 1]))));
	}

	for (int i = 0; i <= n + 1; ++i)
	{
		cout << "X " << i << ": " << tabX[i] << endl;
		cout << "Y " << i << ": " << tabY[i] << endl;
	}

}

void MetodaHeuna::menu()
{
	double x0, y0, xk, h;
	cout << "Podaj x poczatkowe: " << endl;
	cin >> x0;
	cout << "Podaj (x koncowe), czyli b:" << endl;
	cin >> xk;
	cout << "Podaj y poczatkowe: " << endl;
	cin >> y0;
	cout << "Podaj krok " << endl;
	cin >> h;

	dzialanie(x0, xk, h, y0);
}
