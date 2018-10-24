#pragma once
#include "MetodaRungyKutty4.h"

class MainRungyKutty
{
public:
	MainRungyKutty();
	~MainRungyKutty();
	void main();
};



MainRungyKutty::MainRungyKutty()
{
}


MainRungyKutty::~MainRungyKutty()
{
}

inline void MainRungyKutty::main()
{
	MetodaRungyKutty4 rk;
	rk.menu();
}
