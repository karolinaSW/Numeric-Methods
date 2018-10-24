#include "stdafx.h"
#include "InterpolacjaNewton.h"


InterpolacjaNewton::~InterpolacjaNewton()
{
}

double InterpolacjaNewton::calculate(Point arr[], int num, double x)
{
	cout << "Interpolacja Newtonowska: \n\n\n";
	cout << "Liczba punktow: " << num << endl;

	double valY = arr[0].y;

	if (num >= 2)
	{
		valY += ((arr[1].y - arr[0].y) / (arr[1].x - arr[0].x)*(x-arr[0].x));

		for (int i = 2; i < num; i++)
		{
			
			valY = valY + iloczynRoznicowy(i, 0, arr, i) * roznicaIloczyn(i,arr,num,x);
		}
	}
	else
	{
		cerr << "Za malo punktow!" << endl;
	}
	return valY;
	cout << endl << endl;
}

double InterpolacjaNewton::iloczynRoznicowy(int n, int p, Point arr[], int k) // num to wielkosc tablicy
{
	if (n == 1)
	{
		double wynik;
		wynik = ((((arr[k].y - arr[k-1].y) / (arr[k].x - arr[k-1].x))) );
		return wynik;
	}

	else if (n >= 2)
	{
		double wynik1;
		wynik1 = (((iloczynRoznicowy(n-1,p+1, arr, k))-(iloczynRoznicowy(n-1,p, arr, k-1)))/(arr[k].x - arr[p].x));

		return wynik1;
	}





	//ponizej desperacja - wpisane na sztywno, byle liczylo...

	/*
	if (n == 2)
	{
		
		{
			return ((arr[n - 1 + indexChange].y - arr[n - 2 + indexChange].y) / (arr[n - 1 + indexChange].x - arr[n - 2 + indexChange].x));
		}
		
	}
	


	if (n == 3)
	{

		{
			double wynik;

			wynik = (((((arr[n - 1 + indexChange].y - arr[n - 2 + indexChange].y) / (arr[n - 1 + indexChange].x - arr[n - 2 + indexChange].x)))-(((arr[n - 2 + indexChange].y - arr[n - 3 + indexChange].y) / (arr[n - 2 + indexChange].x - arr[n - 3 + indexChange].x))))/(arr[n-1].x - arr[n-3].x));
			return wynik;
		}

	}

	if (n == 4)
	{

		{	double wynik;
		wynik = (((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x)) - ((((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x)) - ((arr[1].y - arr[0].y) / (arr[1].x - arr[0].x))) / (arr[2].x - arr[0].x))) / (arr[3].x - arr[0].x);
		//wynik = ((((((((arr[n - 1 + indexChange].y - arr[n - 2 + indexChange].y) / (arr[n - 1 + indexChange].x - arr[n - 2 + indexChange].x))) - (((arr[n - 2 + indexChange].y - arr[n - 3 + indexChange].y) / (arr[n - 2 + indexChange].x - arr[n - 3 + indexChange].x)))) / (arr[n - 1].x - arr[n - 3].x)))-((((((arr[n - 2 + indexChange].y - arr[n - 3 + indexChange].y) / (arr[n - 2 + indexChange].x - arr[n - 3 + indexChange].x))) - (((arr[n - 3 + indexChange].y - arr[n - 4 + indexChange].y) / (arr[n - 3 + indexChange].x - arr[n - 4 + indexChange].x)))) / (arr[n - 3].x - arr[n - 4].x))))/(arr[n - 1].x - arr[n - 4].x));
			return wynik;
		}

	}

	if (n == 5)
	{

		{
			return ((((((((arr[4].y - arr[3].y) / (arr[4].x - arr[3].x)) - ((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x))) / (arr[4].x - arr[2].x)) - ((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x))) / (arr[4].x - arr[1].x))-((((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x)) - ((((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x)) - ((arr[1].y - arr[0].y) / (arr[1].x - arr[0].x))) / (arr[2].x - arr[0].x))) / (arr[3].x - arr[0].x)))/(arr[4].x-arr[0].x));
		}

	}

	if (n == 6)
	{

		{
			return (((((((((((arr[5].y - arr[4].y) / (arr[5].x - arr[4].x)) - ((arr[4].y - arr[3].y) / (arr[4].x - arr[3].x))) / (arr[5].x - arr[3].x)) - ((((arr[4].y - arr[3].y) / (arr[4].x - arr[3].x)) - ((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x))) / (arr[4].x - arr[2].x))) / (arr[5].x - arr[2].x)) - ((((((arr[4].y - arr[3].y) / (arr[4].x - arr[3].x)) - ((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x))) / (arr[4].x - arr[2].x)) - ((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x))) / (arr[4].x - arr[1].x))) / (arr[5].x - arr[1].x))) - (((((((((arr[4].y - arr[3].y) / (arr[4].x - arr[3].x)) - ((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x))) / (arr[4].x - arr[2].x)) - ((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x))) / (arr[4].x - arr[1].x)) - ((((((arr[3].y - arr[2].y) / (arr[3].x - arr[2].x)) - ((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x))) / (arr[3].x - arr[1].x)) - ((((arr[2].y - arr[1].y) / (arr[2].x - arr[1].x)) - ((arr[1].y - arr[0].y) / (arr[1].x - arr[0].x))) / (arr[2].x - arr[0].x))) / (arr[3].x - arr[0].x))) / (arr[4].x - arr[0].x)))) / (arr[5].x - arr[0].x));
		}

	}

	*/
	
}

double InterpolacjaNewton::roznicaIloczyn(int n, Point arr[], int num, double x)  // <- to jest we wzorze to (x-x0)(x-x1)...(x-x[n-1])
{
	

	if (n == 1)
	{
		double wynik;
		wynik =  (x - arr[0].x);
		return wynik;
		
	}
	else if (n > 1)
	{
		double wynik1;
		wynik1 =  ((x-arr[n-1].x)*roznicaIloczyn(n-1,arr,num,x));
		return wynik1;
	}
	
}



