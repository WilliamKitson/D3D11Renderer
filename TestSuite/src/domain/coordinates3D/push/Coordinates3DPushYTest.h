#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DPushYTest
{
public:
	Coordinates3DPushYTest();
	~Coordinates3DPushYTest();

	std::string test();

private:
	void initialise();
	int successes();

private:
	D3D11Renderer::Coordinates3D unit;
	int itterations;
};
