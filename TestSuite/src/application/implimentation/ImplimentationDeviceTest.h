#pragma once

#include <string>
#include <d3d11.h>

#include "Facade.h"
#include "Implimentation.h"

class ImplimentationDeviceTest
{
public:
	ImplimentationDeviceTest();
	~ImplimentationDeviceTest();

	std::string test();

private:
	void cleanup();

private:
	D3D11Renderer::Facade* unit;
};
