#pragma once

#include <string>
#include "Rasteriser.h"

class RasteriserDefaultCullingTest
{
public:
	RasteriserDefaultCullingTest();
	~RasteriserDefaultCullingTest();

	std::string test();

private:
	HRESULT initialise();
	HRESULT getDescription();

private:
	ID3D11Device* device;
	ID3D11DeviceContext* context;
	CD3D11_RASTERIZER_DESC description;
};
