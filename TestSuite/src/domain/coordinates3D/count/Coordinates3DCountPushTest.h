#pragma once

#include <string>
#include "Coordinates3D.h"

class Coordinates3DCountPushTest
{
public:
	Coordinates3DCountPushTest();
	~Coordinates3DCountPushTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Coordinates3D unit;
	int itterations;
};
