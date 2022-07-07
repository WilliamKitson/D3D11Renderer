#pragma once

#include <string>
#include "Coordinates2D.h"

class Coordinates2DIndexDefaultTest
{
public:
	Coordinates2DIndexDefaultTest();
	~Coordinates2DIndexDefaultTest();

	std::string test();

private:
	D3D11Renderer::Coordinates2D unit;
	float value[2];
};
