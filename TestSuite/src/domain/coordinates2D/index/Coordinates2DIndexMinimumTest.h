#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DIndexMinimumTest
{
public:
	Coordinates2DIndexMinimumTest();
	~Coordinates2DIndexMinimumTest();

	std::string test();

private:
	D3D11Renderer::Coordinates2D unit;
	float value[2];
};
