#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DPushZTest
{
public:
	Coordinates3DPushZTest();
	~Coordinates3DPushZTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates3D unit;
	int itterations;
};
