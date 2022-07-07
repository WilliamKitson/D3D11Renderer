#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DIndexMaximumTest
{
public:
	Coordinates2DIndexMaximumTest();
	~Coordinates2DIndexMaximumTest();

	std::string test();

private:
	D3D11Renderer::Coordinates2D unit;
	float value[2];
};
