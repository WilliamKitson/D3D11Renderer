#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DIndexMaximumTest
{
public:
	Coordinates3DIndexMaximumTest();
	~Coordinates3DIndexMaximumTest();

	std::string test();

private:
	D3D11Renderer::Coordinates3D unit;
	float value[3];
};
