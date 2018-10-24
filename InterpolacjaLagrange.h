#pragma once
#include "Point.h"
#include <iostream>
using namespace std;

class InterpolacjaLagrange : public Point
{
public:
	static double calculate(Point arr[], int num, double x);

	InterpolacjaLagrange();
	~InterpolacjaLagrange();
};

