#pragma once

#include <string>
#include <d3d11.h>

#include "Rasteriser.h"

class RasteriserModeSolidTest
{
public:
	RasteriserModeSolidTest();
	~RasteriserModeSolidTest();

	std::string test();

private:
	HRESULT initialise();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	CD3D11_RASTERIZER_DESC description;
};
