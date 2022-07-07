#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DPushYTest
{
public:
	Coordinates2DPushYTest();
	~Coordinates2DPushYTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates2D unit;
	int itterations;
};
