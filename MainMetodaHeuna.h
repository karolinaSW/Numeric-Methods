#pragma once
#include "MetodaHeuna.h"
class MainMetodaHeuna
{
public:
	MainMetodaHeuna();
	~MainMetodaHeuna();
	void main();
};



MainMetodaHeuna::MainMetodaHeuna()
{
}


MainMetodaHeuna::~MainMetodaHeuna()
{
}

inline void MainMetodaHeuna::main()
{
	MetodaHeuna mh;
	mh.menu();
}
