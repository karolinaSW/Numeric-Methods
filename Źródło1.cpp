# include <iostream>
#include <cstdlib>
#include "stdafx.h"
#include "MainLagrangeNewton.h"
#include "InterpolacjaLagrange.h"
#include "InterpolacjaNewton.h"
#include "Point.h"
#include "MainCramer.h"
#include "MainMetodaProstokatow.h"
#include "MetodaProstokatow.h"
#include "MainMetodaTrapezow.h"
#include "MetodaTrapezow.h"
#include "MainSimpson.h"
#include "BibPomSimpson.h"
#include "BibPomMonteCarlo.h"
#include "MainCalkaMonteCarlo.h"
#include "MainBisekcja.h"
#include "BibPomBisekcja.h"
#include "BibPomNewtonRaphson.h"
#include "MainNewtonRaphson.h"
#include "MainRungyKutty.h"
#include "MetodaRungyKutty4.h"
#include "MainMetodaHeuna.h"
#include "MetodaHeuna.h"
#include "MetodaEulera.h"
#include "MainMetodaEulera.h"



using namespace std;

int main()
{
	char zapetloneMenu = 'y';

	while (zapetloneMenu == 'y' || zapetloneMenu == 'Y')
	{

		cout << "---------------Biblioteka metod numerycznych----------------" << endl << endl;
		cout << "Wybierz metode, ktorej chcesz uzyc:" << endl << endl;

		cout << "1.\t Interpolacja Lagrange'a lub Newtona" << endl;
		cout << "2.\t Interpolacja wielomianowa / uklad rownan Cramera" << endl;
		cout << "3.\t Calkowanie metoda prostokatow" << endl;
		cout << "4.\t Calkowanie metoda trapezow" << endl;
		cout << "5.\t Calkowanie metoda Simpsona" << endl;
		cout << "6.\t Calkowanie metoda Monte Carlo" << endl;
		cout << "7.\t Kwadratury Gaussa" << endl;
		cout << "8.\t Metoda bisekcji" << endl;
		cout << "9.\t Metoda Newtona - Raphsona" << endl;
		cout << "10.\t Metoda Eulera" << endl;
		cout << "11.\t Metoda Heuna" << endl;
		cout << "12.\t Metoda RK4" << endl;

		int wybor;

		cout << endl;
		cin >> wybor;

		switch (wybor)
		{
		case 1:
		{
			MainLagrangeNewton ln;
			ln.main();
			break;
		}
		case 2:
		{
			MainCramer c;
			c.main();
			break;
		}
		case 3:
		{
			MainMetodaProstokatow mp;
			mp.main();
			break;
		}
		case 4:
		{
			MainMetodaTrapezow mt;
			mt.main();
			break;
		}
		case 5:
		{
			MainSimpson s;
			s.main();
			break;
		}
		case 6:
		{
			MainCalkaMonteCarlo mc;
			mc.main();
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			MainBisekcja b;
			b.main();
			break;
		}
		case 9:
		{
			MainNewtonRaphson nr;
			nr.main();
			break;
		}
		case 10:
		{
			MainMetodaEulera e;
			e.main();
			break;
		}
		case 11:
		{
			MainMetodaHeuna mh;
			mh.main();

			break;
		}
		case 12:
		{
			MainRungyKutty rk;
			rk.main();
			break;
		}
		}

		cout << endl << endl << "Uzyc innej metody? 'y' - tak, 'n' - wyjscie:" << endl;
		cin >> zapetloneMenu;
	}


	system("pause");
	return 0;
}