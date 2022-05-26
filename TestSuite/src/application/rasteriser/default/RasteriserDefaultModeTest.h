#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserDefaultModeTest
{
public:
	RasteriserDefaultModeTest();
	~RasteriserDefaultModeTest();

	std::string test();

private:
	HRESULT initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
};
