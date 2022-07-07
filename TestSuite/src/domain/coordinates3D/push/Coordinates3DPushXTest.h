#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DPushXTest
{
public:
	Coordinates3DPushXTest();
	~Coordinates3DPushXTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates3D unit;
	int itterations;
};
