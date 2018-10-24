#pragma once

#include "stdafx.h"
#include <iostream>

using namespace std;

class MainCramer
{
public:
	MainCramer();
	~MainCramer();
	void main();
};



MainCramer::MainCramer()
{
}


MainCramer::~MainCramer()
{
}

inline void MainCramer::main()
{
	float wyznacznikGlowny = 0;
	float wyznacznikX = 0;
	float wyznacznikY = 0;
	float wyznacznikZ = 0;

	//-----------------------------------------------------------------------------------------------------------
	//-------------------------------            wyznacznik macierzy 3x3 glowny
	//-----------------------------------------------------------------------------------------------------------



	int **macierz = new int *[3];	// tworze macierz 3w4k, czwarta kolumna to wyniki
	for (int i = 0; i < 4; i++)
	{
		macierz[i] = new int[3];
	}

	//-----------------------uzupelniam------------------------
	cout << "Uzupelnij macierz 3x3 (wierszami, od gory do dolu):" << endl;
	cin >> macierz[0][0];
	cin >> macierz[0][1];
	cin >> macierz[0][2];
	cin >> macierz[1][0];
	cin >> macierz[1][1];
	cin >> macierz[1][2];
	cin >> macierz[2][0];
	cin >> macierz[2][1];
	cin >> macierz[2][2];

	//wyniki
	cout << "Uzupelnij wyniki w macierzy (kolumna, od gory do dolu): " << endl;
	cin >> macierz[0][3];
	cin >> macierz[1][3];
	cin >> macierz[2][3];

	//macierz pomocnicza
	int *macierzTmp = new int[3];

	for (int i = 0; i < 3; i++)
	{
		macierzTmp[i] = 0;
	}


	//-----------------------uzupelnione------------------------


	int wyznacznik = 0; // w petli dodaje do niego od razu czesc dodawana wyznacznika
	int iloczyn = 1;
	int odjemna = 0; // czesc, ktora odejmuje przy liczeniu wyznacznika

	for (int i = 0; i < 3; i++) //prawoskosne (dodawanie)
	{

		for (int j = 0; j < 3; j++)
		{
			int a;
			a = i + j;

			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

		}
		wyznacznik += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc dodawana = " << wyznacznik << endl;


	for (int i = 0; i < 3; i++) 	 //lewoskosne (odejmowanie); trzy czynniki
	{
		int a = i;

		for (int j = 2; j >= 0; j--)
		{
			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

			a++;
		}
		odjemna += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc odejmowana = " << odjemna << endl;

	// ---------------------------------------------------liczenie wyznacznika (odejmowanie prawoskosy - lewoskosy)

	wyznacznik = wyznacznik - odjemna;

	cout << "Wyznacznik macierzy 3x3 wynosi: " << wyznacznik << endl << endl;
	wyznacznikGlowny = wyznacznik;


	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------END OF wyznacznik 3x3 glowny
	//-----------------------------------------------------------------------------------------------------------


	//###########################################################################################################

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------wyznacznik x (podmieniam kolumne wynikow z kolumna x)
	//-----------------------------------------------------------------------------------------------------------

	// resetuje wartosci
	wyznacznik = 0;
	iloczyn = 1;
	odjemna = 0;

	for (int i = 0; i < 3; i++)
	{
		macierzTmp[i] = macierz[i][0];  // przepisuje, zeby zapamietac kolumne x, bo zaraz ja podstawie
	}

	for (int i = 0; i < 3; i++)
	{
		macierz[i][0] = macierz[i][3];  // podstawione wyniki za x
	}

	for (int i = 0; i < 3; i++)		// drukowanie macierzy 
	{
		for (int j = 0; j < 3; j++)
		{
			cout << macierz[i][j] << "	";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) //prawoskosne (dodawanie)
	{

		for (int j = 0; j < 3; j++)
		{
			int a;
			a = i + j;

			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

		}
		wyznacznik += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc dodawana = " << wyznacznik << endl;


	for (int i = 0; i < 3; i++) 	 //lewoskosne (odejmowanie); trzy czynniki
	{
		int a = i;

		for (int j = 2; j >= 0; j--)
		{
			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

			a++;
		}
		odjemna += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc odejmowana = " << odjemna << endl;

	// ---------------------------------------------------liczenie wyznacznika (odejmowanie prawoskosy - lewoskosy)

	wyznacznik = wyznacznik - odjemna;

	cout << "Wyznacznik x macierzy wynosi: " << wyznacznik << endl << endl;


	//wracam z wartosciami do macierzy glownej
	for (int i = 0; i < 3; i++)
	{
		macierz[i][0] = macierzTmp[i];
	}

	wyznacznikX = wyznacznik;

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------END OF wyznacznik x
	//-----------------------------------------------------------------------------------------------------------



	//###########################################################################################################

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------wyznacznik y (podmieniam kolumne wynikow z kolumna y)
	//-----------------------------------------------------------------------------------------------------------

	// resetuje wartosci
	wyznacznik = 0;
	iloczyn = 1;
	odjemna = 0;

	for (int i = 0; i < 3; i++)
	{
		macierzTmp[i] = macierz[i][1];  // przepisuje, zeby zapamietac kolumne y, bo zaraz ja podstawie
	}

	for (int i = 0; i < 3; i++)
	{
		macierz[i][1] = macierz[i][3];  // podstawione wyniki za y
	}

	for (int i = 0; i < 3; i++)		// drukowanie macierzy 
	{
		for (int j = 0; j < 3; j++)
		{
			cout << macierz[i][j] << "	";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) //prawoskosne (dodawanie)
	{

		for (int j = 0; j < 3; j++)
		{
			int a;
			a = i + j;

			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

		}
		wyznacznik += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc dodawana = " << wyznacznik << endl;


	for (int i = 0; i < 3; i++) 	 //lewoskosne (odejmowanie); trzy czynniki
	{
		int a = i;

		for (int j = 2; j >= 0; j--)
		{
			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

			a++;
		}
		odjemna += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc odejmowana = " << odjemna << endl;

	// ---------------------------------------------------liczenie wyznacznika (odejmowanie prawoskosy - lewoskosy)

	wyznacznik = wyznacznik - odjemna;

	cout << "Wyznacznik y macierzy wynosi: " << wyznacznik << endl << endl;

	//wracam z wartosciami do macierzy glownej
	for (int i = 0; i < 3; i++)
	{
		macierz[i][1] = macierzTmp[i];
	}

	wyznacznikY = wyznacznik;

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------END OF wyznacznik y
	//-----------------------------------------------------------------------------------------------------------



	//###########################################################################################################

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------wyznacznik z (podmieniam kolumne wynikow z kolumna z)
	//-----------------------------------------------------------------------------------------------------------

	// resetuje wartosci
	wyznacznik = 0;
	iloczyn = 1;
	odjemna = 0;

	for (int i = 0; i < 3; i++)
	{
		macierzTmp[i] = macierz[i][2];  // przepisuje, zeby zapamietac kolumne z, bo zaraz ja podstawie
	}

	for (int i = 0; i < 3; i++)
	{
		macierz[i][2] = macierz[i][3];  // podstawione wyniki za y
	}

	for (int i = 0; i < 3; i++)		// drukowanie macierzy 
	{
		for (int j = 0; j < 3; j++)
		{
			cout << macierz[i][j] << "	";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) //prawoskosne (dodawanie)
	{

		for (int j = 0; j < 3; j++)
		{
			int a;
			a = i + j;

			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

		}
		wyznacznik += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc dodawana = " << wyznacznik << endl;


	for (int i = 0; i < 3; i++) 	 //lewoskosne (odejmowanie); trzy czynniki
	{
		int a = i;

		for (int j = 2; j >= 0; j--)
		{
			if (a >= 3)
			{
				if (a == 3)
				{
					iloczyn = iloczyn * macierz[0][j];
				}
				else if (a == 4)
				{
					iloczyn = iloczyn * macierz[1][j];
				}
			}
			else
			{
				iloczyn = iloczyn * macierz[a][j];
			}

			a++;
		}
		odjemna += iloczyn;
		iloczyn = 1;
	}
	cout << "Czesc odejmowana = " << odjemna << endl;

	// ---------------------------------------------------liczenie wyznacznika (odejmowanie prawoskosy - lewoskosy)

	wyznacznik = wyznacznik - odjemna;

	cout << "Wyznacznik z macierzy wynosi: " << wyznacznik << endl << endl;

	//wracam z wartosciami do macierzy glownej
	for (int i = 0; i < 3; i++)
	{
		macierz[i][2] = macierzTmp[i];
	}

	wyznacznikZ = wyznacznik;

	//-----------------------------------------------------------------------------------------------------------
	//----------------------------------END OF wyznacznik z
	//-----------------------------------------------------------------------------------------------------------



	// obliczanie x, y i z

	if (wyznacznikGlowny == 0 && (wyznacznikX != 0 || wyznacznikY != 0 || wyznacznikZ != 0))
	{
		cout << "Uklad sprzeczny." << endl << endl;
	}

	else if (wyznacznikGlowny == 0 && wyznacznikX == 0 && wyznacznikY == 0 && wyznacznikZ == 0)
	{
		cout << "Uklad nieoznaczony, nieskonczenie wiele rozwiazan." << endl << endl;
	}
	else
	{
		float x = float(wyznacznikX / wyznacznikGlowny);
		float y = float(wyznacznikY / wyznacznikGlowny);
		float z = float(wyznacznikZ / wyznacznikGlowny);

		cout << "Wyniki ukladu to: \nX = " << x << "\nY = " << y << "\nZ = " << z << endl << endl;
	}

}
