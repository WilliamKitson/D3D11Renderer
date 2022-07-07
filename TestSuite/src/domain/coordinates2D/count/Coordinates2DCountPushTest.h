#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DCountPushTest
{
public:
	Coordinates2DCountPushTest();
	~Coordinates2DCountPushTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Coordinates2D unit;
	int itterations;
};
