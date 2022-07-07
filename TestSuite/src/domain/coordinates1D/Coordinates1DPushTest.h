#pragma once

#include <string>
#include "Coordinates1D.h"

class Coordinates1DPushTest
{
public:
	Coordinates1DPushTest();
	~Coordinates1DPushTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates1D unit;
	int itterations;
};
