#pragma once

#include <string>
#include "Resolution.h"

class ResolutionMinimumHeightTest
{
public:
	ResolutionMinimumHeightTest();
	~ResolutionMinimumHeightTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Resolution unit;
};
