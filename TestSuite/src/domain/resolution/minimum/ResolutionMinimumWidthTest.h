#pragma once

#include <string>
#include "Resolution.h"

class ResolutionMinimumWidthTest
{
public:
	ResolutionMinimumWidthTest();
	~ResolutionMinimumWidthTest();

	std::string test();

private:
	void initialise();

private:
	D3D11Renderer::Resolution unit;
};
