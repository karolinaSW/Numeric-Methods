#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class MetodaEulera
{
public:
	MetodaEulera();
	~MetodaEulera();
	void menu();
};



MetodaEulera::MetodaEulera()
{
}


MetodaEulera::~MetodaEulera()
{
}


void MetodaEulera::menu()
{

	int stopieny;

	int stopienx;
	cout << "Podaj stopien wielomianu(x) : " << endl;
	cin >> stopienx;
	cout << "Podaj stopien wielomianu(y) : " << endl;
	cin >> stopieny;

	double*tabwspolczynnikowx = new double[stopienx + 1];
	double* tabwspolczynnikowy = new double[stopieny + 1];

	for (int i = 0; i < stopienx + 1; i++)
	{
		//if (stopienx != 0)
		//{
		cout << "wspolczynnik(x) " << i << " potegi " << endl;
		cin >> tabwspolczynnikowx[i];
		//cout << tabwspolczynnikowx[i] << endl;
		//}
	}

	for (int i = 0; i < stopieny + 1; i++)
	{
		//if (stopieny != 0)
		//{
		cout << "wspolczynnik(y) " << i << " potegi " << endl;
		cin >> tabwspolczynnikowy[i];
		//cout << tabwspolczynnikowy[i] << endl;
		//}
	}

	double x0, y0, b, h, N, fy, fx, fxy;
	cout << "podaj poczatek przedzialu " << endl;
	cin >> x0;
	cout << "podaj koniec przedzialu " << endl;
	cin >> b;
	cout << "podaj punkt w y(0)" << endl;
	cin >> y0;
	cout << "podaj krok " << endl;
	cin >> h;
	N = (b - x0) / h;
	double* tabpunktowY = new double[N + 1];
	double* tabpunktowX = new double[N + 1];
	tabpunktowX[0] = x0;
	tabpunktowY[0] = y0;
	for (int i = 0; i < N; i++)
	{
		fy = 0;
		fx = 0; fxy = 0;
		for (int j = 0; j <stopieny + 1; j++)
		{
			fy += tabwspolczynnikowy[j] * pow(tabpunktowY[i], j);
		}
		for (int j = 0; j <stopienx + 1; j++)
		{
			fx += tabwspolczynnikowx[j] * pow(tabpunktowX[i], j);
		}
		fxy = fx + fy;

		tabpunktowY[i + 1] = tabpunktowY[i] + h * fxy;
		//cout << tabpunktowY[i+1]<<endl;
		tabpunktowX[i + 1] = tabpunktowX[i] + h;
		cout << tabpunktowX[i + 1] << "         " << tabpunktowY[i + 1] << endl;
	}
}
