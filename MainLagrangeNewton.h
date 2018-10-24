#pragma once

#include "stdafx.h"
#include <iostream>
#include "Point.h"
#include <fstream>
#include <string>

#include "InterpolacjaLagrange.h"
#include "InterpolacjaNewton.h"

using namespace std;

Point *arrayOfPoints;
int amountOfPoints = 0;

void print(Point arr[], int num);

class MainLagrangeNewton
{
public:
	MainLagrangeNewton();
	~MainLagrangeNewton();

	void main();
};



MainLagrangeNewton::MainLagrangeNewton()
{
}


MainLagrangeNewton::~MainLagrangeNewton()
{
}

inline void MainLagrangeNewton::main()
{
	cout << "\n\n-----Program liczacy interpolacje zadanego punktu-----\n\n";

	cout << "\nWprowadzanie punktow reczne, czy z pliku? \n";
	cout << "Reczne - 1 \nZ pliku - 2 \n";
	char choice2;
	cin >> choice2;

	switch (choice2)
	{
	case '1':
	{
		double tempX, tempY;

		cout << "Ile punktow? \n";
		cin >> amountOfPoints;
		arrayOfPoints = new Point[amountOfPoints]; ///---------------------

		for (int i = 0; i < amountOfPoints; i++)
		{
			cout << "\nWprowadz " << i + 1 << " punkt x :\n";
			cin >> tempX;

			cout << "\nWprowadz " << i + 1 << " punkt y :\n";
			cin >> tempY;

			arrayOfPoints[i].x = tempX;
			arrayOfPoints[i].y = tempY;

		}

		print(arrayOfPoints, amountOfPoints);

		break;
	}
	case '2':
	{
		fstream file;
		cout << "\nWprowadz nazwe pliku z rozszerzeniem\n"; //plik ma byc tam, gdzie TEN plik cpp.
		string nameOfFile;
		cin >> nameOfFile;

		file.open(nameOfFile, ios::in);
		if (file.good() == true)
		{
			cout << "\nUdalo sie otworzyc plik :) \n";

			double tempX, tempY;

			amountOfPoints = 0;
			string testLine;

			while (!file.eof())
			{
				getline(file, testLine);
				++amountOfPoints;

			}

			file.clear();
			file.seekg(0, ios::beg); // ustawienie wskaŸnika odczytu pliku na pocz¹tek (bo po pêtli jest na koñcu)

			arrayOfPoints = new Point[amountOfPoints]; ///-----------------------

			for (int i = 0; i < amountOfPoints; i++)
			{
				file >> tempX >> tempY;

				arrayOfPoints[i].x = tempX;
				arrayOfPoints[i].y = tempY;

			}

			print(arrayOfPoints, amountOfPoints);

		}
		else cout << "\nERROR - nie mozna otworzyc pliku! :( \n";

		break;
	}
	}

	double valX;
	cout << "Podaj wartosc wspolrzednej x punktu, dla ktorego chcesz policzyc wartosc: \n";
	cin >> valX;
	cout << endl << endl;

	cout << "Interpolacja Lagrange'a - wybierz 1 \nInterpolacja Newtona - wybierz 2 \n\n";
	char choice;
	cin >> choice;



	switch (choice) {
	case '1':
	{
		cout << "lagrange\n";

		cout << "Wynik interpolacji Lagrange'a dla zadanego punktu to: " << InterpolacjaLagrange::calculate(arrayOfPoints, amountOfPoints, valX) << endl << endl;


		break;
	}
	case '2':
	{
		cout << "newton\n";
		cout << "Wynik interpolacji Newtona dla zadanego punktu to: " << InterpolacjaNewton::calculate(arrayOfPoints, amountOfPoints, valX) << endl << endl;
		break;
	}
	}

	delete[] arrayOfPoints;
}


void print(Point arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << endl;
		cout << "x: " << arr[i].x << "   y: " << arr[i].y << endl;

	}
}

