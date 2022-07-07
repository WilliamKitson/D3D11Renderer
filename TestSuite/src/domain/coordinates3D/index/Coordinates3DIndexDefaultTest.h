#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DIndexDefaultTest
{
public:
	Coordinates3DIndexDefaultTest();
	~Coordinates3DIndexDefaultTest();

	std::string test();

private:
	D3D11Renderer::Coordinates3D unit;
	float value[3];
};
