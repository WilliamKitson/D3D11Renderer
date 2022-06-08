#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserModeWireframeTest
{
public:
	RasteriserModeWireframeTest();
	~RasteriserModeWireframeTest();

	std::string test();

private:
	HRESULT initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	CD3D11_RASTERIZER_DESC description;
};
