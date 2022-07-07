#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DPushXTest
{
public:
	Coordinates2DPushXTest();
	~Coordinates2DPushXTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates2D unit;
	int itterations;
};
