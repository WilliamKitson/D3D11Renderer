#pragma once

#include <string>
#include "Coordinates1D.h"

class Coordinates1DCountPushTest
{
public:
	Coordinates1DCountPushTest();
	~Coordinates1DCountPushTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Coordinates1D unit;
	int itterations;
};
