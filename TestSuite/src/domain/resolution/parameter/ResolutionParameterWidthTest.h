#pragma once

#include <string>
#include "Resolution.h"

class ResolutionParameterWidthTest
{
public:
	ResolutionParameterWidthTest();
	~ResolutionParameterWidthTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Resolution unit;
	int width;
};
