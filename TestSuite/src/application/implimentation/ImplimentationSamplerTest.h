#pragma once

#include <string>
#include <d3d11.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationSamplerTest
{
public:
	ImplimentationSamplerTest();
	~ImplimentationSamplerTest();

	std::string test();

private:
	bool success();

private:
	D3D11Renderer::Facade* unit;
	ID3D11SamplerState* state;
};
