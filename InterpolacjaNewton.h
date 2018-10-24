#pragma once
#include "Point.h"
#include <iostream>
using namespace std;


class InterpolacjaNewton :public Point
{
	
public:
	

	static double calculate(Point arr[], int num, double x);
	static double iloczynRoznicowy(int n, int p, Point arr[], int k);
	static double roznicaIloczyn(int n, Point arr[], int num, double x);
	//static double licznik(int n, Point arr[]);
	
	~InterpolacjaNewton();
};

