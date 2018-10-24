#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class MetodaRungyKutty4
{
public:
	MetodaRungyKutty4();
	~MetodaRungyKutty4();

	double funkcja(double x, double y);
	void dzialanie(double x0, double xk, double h, double y0);
	void menu();
};



MetodaRungyKutty4::MetodaRungyKutty4()
{
}


MetodaRungyKutty4::~MetodaRungyKutty4()
{
}

double MetodaRungyKutty4::funkcja(double x, double y)
{
	return sin(x) - 3 * cos(y);
}


void MetodaRungyKutty4::dzialanie(double x0, double xk, double h, double y0)
{
	double n = (xk - x0) / h;
	double* tablica_Y = new double[n + 1];
	double* tablica_X = new double[n + 1];
	tablica_Y[0] = y0;
	tablica_X[0] = x0;

	for (int i = 1; i <= n; ++i)
	{
		tablica_X[i] = tablica_X[i - 1] + h;
	}
	for (int i = 1; i <= n; ++i)
	{

		double k1 = h * funkcja(tablica_X[i - 1], tablica_Y[i - 1]);
		double k2 = h * funkcja((tablica_X[i - 1] + h / 2), (tablica_Y[i - 1] + (0.5 * k1)));
		double k3 = h * funkcja((tablica_X[i - 1] + h / 2), (tablica_Y[i - 1] + (0.5 * k2)));
		double k4 = h * funkcja((tablica_X[i - 1] + h), (tablica_Y[i - 1] + k3));

		tablica_Y[i] = (tablica_Y[i - 1] + ((k1 + (2 * k2) + (2 * k3) + k4) / 6));
	}



	for (int i = 0; i <= n; ++i)
	{
		cout << "y" << i << " " << tablica_Y[i] << endl;
		cout << "x" << i << " " << tablica_X[i] << endl;
	}

}

void MetodaRungyKutty4::menu()
{
	double x0, y0, xk, h;
	cout << "Podaj x poczatkowe: " << endl;
	cin >> x0;
	cout << "Podaj b (x koncowe)" << endl;
	cin >> xk;
	cout << "Podaj y poczatkowe: " << endl;
	cin >> y0;
	cout << "Podaj krok " << endl;
	cin >> h;

	dzialanie(x0, xk, h, y0);
}


