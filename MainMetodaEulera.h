#pragma once
#include "MetodaEulera.h"

class MainMetodaEulera
{
public:
	MainMetodaEulera();
	~MainMetodaEulera();
	void main();
};



MainMetodaEulera::MainMetodaEulera()
{
}


MainMetodaEulera::~MainMetodaEulera()
{
}

inline void MainMetodaEulera::main()
{
	MetodaEulera e;
	e.menu();
}
