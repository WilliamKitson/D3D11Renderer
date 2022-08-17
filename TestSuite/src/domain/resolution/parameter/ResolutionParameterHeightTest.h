#pragma once

#include <string>
#include "Resolution.h"

class ResolutionParameterHeightTest
{
public:
	ResolutionParameterHeightTest();
	~ResolutionParameterHeightTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Resolution unit;
	int height;
};
