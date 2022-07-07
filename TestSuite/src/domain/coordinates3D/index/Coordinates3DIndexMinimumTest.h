#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DIndexMinimumTest
{
public:
	Coordinates3DIndexMinimumTest();
	~Coordinates3DIndexMinimumTest();

	std::string test();

private:
	D3D11Renderer::Coordinates3D unit;
	float value[3];
};
