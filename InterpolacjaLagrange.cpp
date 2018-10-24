#include "stdafx.h"
#include "InterpolacjaLagrange.h"


double InterpolacjaLagrange::calculate(Point arr[], int num, double x)
{
	double wynik = 0.0;
	double w1 = 1.0, w2 = 1.0;
	for (int i = 0; i<num; i++)
	{
		for (int j = 0; j<num; j++)
		{
			if (i != j)
			{
				w1 = w1 * (x - arr[j].x);
				w2 = w2 * (arr[i].x - arr[j].x);
			}
		}
		wynik += arr[i].y * w1 / w2;
		w1 = 1;
		w2 = 1;
	}

	cout << "Wynik interpolacji to: " << wynik << "\n";
	return wynik;
}

InterpolacjaLagrange::InterpolacjaLagrange()
{
}


InterpolacjaLagrange::~InterpolacjaLagrange()
{
}
